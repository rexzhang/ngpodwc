/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc.cpp
// Purpose:
// Author:      rex zhang
// Modified by:
// Created:     23/02/2006 12:18:54
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwc.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "ngpodwc.h"

////@begin XPM images
////@end XPM images

/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( NgpodwcApp )
////@end implement app

/*!
 * NgpodwcApp type definition
 */

IMPLEMENT_CLASS( NgpodwcApp, wxApp )

/*!
 * NgpodwcApp event table definition
 */

BEGIN_EVENT_TABLE( NgpodwcApp, wxApp )

////@begin NgpodwcApp event table entries
////@end NgpodwcApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for NgpodwcApp
 */

NgpodwcApp::NgpodwcApp()
{
    ////@begin NgpodwcApp member initialisation
    ////@end NgpodwcApp member initialisation
}

/*!
 * Initialisation for NgpodwcApp
 */

bool NgpodwcApp::OnInit()
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

    dialog_mini_panel *mainWindow = NULL;

    //读取配置文件
    config.ReadConfig();
    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //本地化
    m_locale.Init(config.UILanguage);
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
    if(config.ShowSplash)
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

    if (argc >= 2)
    {
        //判断是否需要忽略墙纸切换动作
        if(config.PauseChangeWallpaper)
        {
            wxBell();
            wxBell();
            //!return true;
            return false;//Test can not auto close at pauseChange mode
        }//!程序结束

        //有参数，
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
        //有参数，直接切换到下个日期
        //日期信息++
        seekDays(1, &(config.PodDate));
        //updateWallpaper(&config);
        updateWallpaper(config);
        wxBell();
        return true;
    }//!程序结束

    //无参数，表示需要显示小面板
    mainWindow = new dialog_mini_panel(NULL, ID_DIALOG, _("National Geographic Photo Of the Day Wallpaper Changer"));
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

/*!
 * Cleanup for NgpodwcApp
 */
int NgpodwcApp::OnExit()
{
    ////@begin NgpodwcApp cleanup
    return wxApp::OnExit();
    ////@end NgpodwcApp cleanup
}

