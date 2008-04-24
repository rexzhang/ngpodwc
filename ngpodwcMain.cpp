/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcMain.cpp
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

#include "ngpodwcMain.h"
#include "ngpodwcApp.h"

#include "common_globals.h"

#include <wx/msgdlg.h>
#include <wx/listbox.h>
#include <wx/bitmap.h>
#include <wx/dcmemory.h>
#include <wx/gdicmn.h>
#include <wx/image.h>
#include <wx/dc.h>
#include <wx/dcscreen.h>

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

ngpodwcMiniPanel::ngpodwcMiniPanel(wxDialog *frame)
        : GUIdialog_minipanel(frame)
{
    /*
    #if wxUSE_STATUSBAR
        statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
        statusBar->SetStatusText(wxbuildinfo(short_f), 1);
    #endif
    */
    ;

}

ngpodwcMiniPanel::~ngpodwcMiniPanel()
{

}

ngpodwcConfigPanel::ngpodwcConfigPanel(wxFrame *frame)
        : GUIdialog_configpanel(frame)
{
    /*
    #if wxUSE_STATUSBAR
        statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
        statusBar->SetStatusText(wxbuildinfo(short_f), 1);
    #endif
    */
    ReadConfig();
    ShowConfig();

}

ngpodwcConfigPanel::~ngpodwcConfigPanel()
{


}


ngpodwcAbout::ngpodwcAbout(wxFrame *frame)
        : GUIdialog_about(frame)
{
    /*
    #if wxUSE_STATUSBAR
        statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
        statusBar->SetStatusText(wxbuildinfo(short_f), 1);
    #endif
    */
    ;

}

ngpodwcAbout::~ngpodwcAbout()
{

}

/////////////////////////
void ngpodwcConfigPanel::OnButtonAboutClick( wxCommandEvent& event )
{
    ngpodwcAbout* window = new ngpodwcAbout(this);//, ID_DIALOG_ABOUT, _("About"));
    window->Show(true);
    wxLogWarning( configRunning.PodBasePath );
    event.Skip();
}

void ngpodwcConfigPanel::ShowConfig(void)
//将config中的参数写到界面控件，以便显示出来
{
    //////////////////
    mPictureSource->SetSelection(configRunning.PictureSource);

    //////////////////
    mPodBasePath->SetValue(configRunning.PodBasePath);
    mPodDatabaseName->SetValue(configRunning.PodDatabaseName);
    mPodPicturePath->SetValue(configRunning.PodPicturePath);
    //Next POD Day
    mNextPODDay->SetValue(configRunning.PodDate);

    ///////////////////
    mLocalPicturePath->SetValue(configRunning.LocalPicturePath);

    ///////////////////////
    if((configRunning.ScreenWidth == 640) && (configRunning.ScreenHeight == 480))
    {
        mScreenWidthHeight->SetSelection(SCREENWH640x480);
        mScreenWidth->SetValue(wxT("640"));
        mScreenHeight->SetValue(wxT("480"));
    }
    else
    {
        if((configRunning.ScreenWidth == 800) && (configRunning.ScreenHeight == 600))
        {
            mScreenWidthHeight->SetSelection(SCREENWH800x600);
            mScreenWidth->SetValue(wxT("800"));
            mScreenHeight->SetValue(wxT("600"));
        }
        else
        {
            if((configRunning.ScreenWidth == 1024) && (configRunning.ScreenHeight == 768))
            {
                mScreenWidthHeight->SetSelection(SCREENWH1024x768);
                mScreenWidth->SetValue(wxT("1024"));
                mScreenHeight->SetValue(wxT("768"));
            }
            else
            {
                //SCREENWHAutoDetect
                mScreenWidthHeight->SetSelection(SCREENWHAutoDetect);
            }
        }
    }
    mScreenPicturePath->SetValue(configRunning.ScreenPicturePath);
    mScreenPictureName->SetValue(configRunning.ScreenPictureName);

	////////////////////////////////
	mShowDisc->SetValue(configRunning.ShowDisc);

	mPauseChangeWallpaper->SetValue(configRunning.PauseChangeWallpaper);
	mShowSplash->SetValue(configRunning.ShowSplash);

    //UILanguage->SetSelection(g_AppLanguageID

	return;
}

void ngpodwcConfigPanel::ReadConfig( void )//读取配置文件到界面控件
{
    configRunning.ReadConfig();
}

void ngpodwcConfigPanel::WriteConfig( void )// 写内存中（界面控件）的配置到配置文件
{
    configRunning.WriteConfig();
}

void ngpodwcConfigPanel::AutoDetectScreenWH(void)
{
    wxString screenWH;

    //get system X,Y
    configRunning.ScreenWidth = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    configRunning.ScreenHeight = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

    //update display info
    screenWH.Printf(wxT("%u"), configRunning.ScreenWidth);
    mScreenWidth->SetValue(screenWH);

    screenWH.Printf(wxT("%u"), configRunning.ScreenHeight);
    mScreenHeight->SetValue(screenWH);

    mScreenWidthHeight->SetSelection(SCREENWHAutoDetect);
}

wxString ngpodwcConfigPanel::AutoDetectSystemPath(void)
{
    wxString path;
    wxGetEnv(wxT("windir"), &path);

    mScreenPicturePath->SetValue(path);
    return path;
}
