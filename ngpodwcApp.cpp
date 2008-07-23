/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcApp.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2008-4-21
// RCS-ID:
// Copyright:   (c) 2008 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include <wx/splash.h>
#include <wx/cmdline.h>
#include <wx/filename.h>

#include "ngpodwcApp.h"
#include "ngpodwcMain.h"

//#include "dialog_mini_panel.h"
//#include "dialog_config_panel.h"

#include "common_wallpaper_operation.h"
#include "common_config.h"
#include "ngpodwc_common_ngpodinfo.h"
#include "common_globals.h"

#include "GUIFrame.h"
#include "dialogMiniPanel.h"

IMPLEMENT_APP(ngpodwcApp);

bool ngpodwcApp::OnInit()
{

    wxImage::AddHandler(new wxBMPHandler);

    ////@begin NgpodwcApp initialisation
    // Remove the comment markers above and below this block
    // to make permanent changes to the code.

#if wxUSE_XPM

    wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG

    wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG

    wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF

    wxImage::AddHandler(new wxGIFHandler);
#endif
    ////@end NgpodwcApp initialisation

    wxBitmap splashBitmap;
    wxSplashScreen *splash = NULL;
    bool splashEnable = true;//will read from config

    //dialog_mini_panel *mainWindow = NULL;

    //读取配置文件
    //configRunning.ReadConfig();
    //configStarting = new ngpodwcConfig;
    configRunning.ReadConfig();
    //config.ReadConfig();
    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //本地化
    m_locale.Init(configRunning.UILanguage);
    // normally this wouldn't be necessary as the catalog files would be found
    // in the default locations, but under Windows then the program is not
    // installed the catalogs are in the parent directory (because the binary
    // is in a subdirectory of samples/internat) where we wouldn't find them by
    // default
    wxLocale::AddCatalogLookupPathPrefix(wxT("share\\locale\\."));
    // Initialize the catalogs we'll be using
    m_locale.AddCatalog(wxT("wxstd"));
    m_locale.AddCatalog(wxT("ngpodwcc"));

    //确定是否显示Splash
    if(configRunning.ShowSplash)
    {
        if(splashBitmap.LoadFile(wxT("share/art/splash.png"), wxBITMAP_TYPE_PNG))
        {
            splashEnable = true;
        }
        else
        {
            splashEnable = false;
        }
    }

    //解析命令行
    static const wxCmdLineEntryDesc cmdLineDesc[] =
        {
            {
                wxCMD_LINE_SWITCH, wxT("h"), wxT("help"), wxT("show this help message"),
                wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP
            },
            {
                wxCMD_LINE_SWITCH, wxT("v"), wxT("verbose"), wxT("be verbose")
            },
            {
                wxCMD_LINE_SWITCH, wxT("q"), wxT("quiet"),   wxT("be quiet")
            },

            {
                wxCMD_LINE_SWITCH, wxT("s"), wxT("silent"),   wxT("just show next picture")
            },
            {
                wxCMD_LINE_SWITCH, wxT("i"), wxT("install"),   wxT("auto create config file if it can't found")
            },
            {
                wxCMD_LINE_SWITCH, wxT("c"), wxT("config"),   wxT("config")
            },

            //{ wxCMD_LINE_OPTION, wxT("o"), wxT("output"),  wxT("output file") },
            //{ wxCMD_LINE_OPTION, wxT("i"), wxT("input"),   wxT("input dir") },
            //{ wxCMD_LINE_OPTION, wxT("d"), wxT("date"),    wxT("output file date"),
            //    wxCMD_LINE_VAL_DATE },

            {
                wxCMD_LINE_NONE
            }
        };

    wxCmdLineParser parser(cmdLineDesc, argc, argv);

    //统一使用 - 作为开关标示
    parser.SetSwitchChars(wxT("-"));

    switch ( parser.Parse() )
    {
    case -1:
        //命令行中有 -h 或 --help
        wxLogMessage(wxT("Help was given, terminating."));
        return false;
        break;

    case 0:
        //解析成功
        //ShowCmdLine(parser);
        break;

    default:
        //命令行输入有误
        wxLogMessage(wxT("Syntax error detected, aborting."));
        return false;
        break;
    }

    //!安静模式
    if (parser.Found(wxT("silent")))
    {
        //判断是否需要忽略墙纸切换动作
        if(configRunning.PauseChangeWallpaper)
        {
            wxBell();
            wxBell();
            //!return true;
            return false;//Test can not auto close at pauseChange mode
        }//!程序结束

        if(splashEnable)
        {
            //显示Splash图片
            splash= new wxSplashScreen(splashBitmap,
                                       wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                       6000, NULL, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                       wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR);//|wxSTAY_ON_TOP);
            wxYield();
        }
        //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);
        //直接切换到下个日期
        //日期信息++
        seekDays(1, &(configRunning.PodDate));
        //updateWallpaper(&config);
        updateWallpaper(configRunning);
        wxBell();
        return true;
    }//!程序结束

    //!安装调用
    if (parser.Found(wxT("install")))
    {
        wxFileName *filename;
        wxString path = argv[0];
        filename = new wxFileName(path, wxPATH_WIN);
        path = filename->GetPath(wxPATH_GET_VOLUME, wxPATH_WIN);
        configRunning.SetConfigFilePath(path);

        if(!configRunning.ReadConfig())//尝试读取，如果读取不成功
        {
            configRunning.WriteConfig();//创建一个配置文件
        }

        dialogConfigPanel* mainWindow = new dialogConfigPanel( 0L );//, ID_DIALOG_CONFIG_PANEL );

        configRunning.SetConfigFilePath(path);
        //wxSafeShowMessage(wxT(""), (mainWindow->config).ConfigFile);
        configRunning.ReadConfig();

        mainWindow->Show(true);

        return true;
    }

    //!直接进入配置面板
    if (parser.Found(wxT("config")))
    {
        dialogConfigPanel* mainWindow = new dialogConfigPanel( 0L );//, ID_DIALOG_CONFIG_PANEL );

        //(mainWindow->config).SetConfigFilePath(path);
        //wxSafeShowMessage(wxT(""), (mainWindow->config).ConfigFile);
        configRunning.ReadConfig();

        mainWindow->Show(true);

        return true;
    }

    //!无参数，表示需要显示小面板
    //ngpodwcMiniPanel* mainWindow = new ngpodwcMiniPanel(NULL, ID_DIALOG, _("National Geographic Photo Of the Day Wallpaper Changer"));
    dialogMiniPanel* mainWindow = new dialogMiniPanel(0L);//, _("National Geographic Photo Of the Day Wallpaper Changer"));
    //mainWindow = new dialog_mini_panel(NULL, ID_DIALOG, _("National Geographic Photo Of the Day Wallpaper Changer"));
    if(splashEnable)
    {
        //显示Splash图片
        splash= new wxSplashScreen(splashBitmap,
                                   wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                   6000, mainWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                   wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR);//|wxSTAY_ON_TOP);
        wxYield();
    }
    mainWindow->Show(true);

    /*
    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return false;
    */

    return true;
}
