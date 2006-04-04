/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc.cpp
// Purpose:
// Author:      rex zhang
// Modified by:
// Created:     23/02/2006 12:18:54
// RCS-ID:
// Copyright:   coooooooooopy
// Licence:
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

    //wxApp::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE, "program");
    wxBitmap splashBitmap;
    wxSplashScreen *splash = NULL;
    bool splashEnable = true;//will read from config

    ngpodwc_mini_panel *mainWindow = NULL;

    //��ȡ�����ļ�
    config.ReadConfig();
    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //ȷ���Ƿ���ʾSplash
    if(config.ShowSplash)
    {
        if(splashBitmap.LoadFile(wxT("art/splash.png"), wxBITMAP_TYPE_PNG))
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
        //�ж��Ƿ���Ҫ����ǽֽ�л�����
        if(config.PauseChangeWallpaper)
        {
            wxBell();
            wxBell();
            //!return true;
            return false;//Test can not auto close at pauseChange mode
        }//!�������

        //�в�����
        if(splashEnable)
        {
            //��ʾSplashͼƬ
            splash= new wxSplashScreen(splashBitmap,
                                       wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                       6000, NULL, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                       wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR);//|wxSTAY_ON_TOP);
            wxYield();
        }
        //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);
        //�в�����ֱ���л����¸�����
        //������Ϣ++
        seekDays(1, &(config.PodDate));
        //updateWallpaper(&config);
        updateWallpaper(config);
        wxBell();
        return true;
    }//!�������

    //�޲�������ʾ��Ҫ��ʾС���
    mainWindow = new ngpodwc_mini_panel(NULL, ID_DIALOG, _("Dialog"));
    if(splashEnable)
    {
        //��ʾSplashͼƬ
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
    return 0;
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
