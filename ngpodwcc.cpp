/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     07/02/2006 16:58:25
// RCS-ID:
// Copyright:   cooooooooooooopy
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwcc.h"
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

#include "ngpodwcc.h"

#include <wx/filename.h>


////@begin XPM images
////@end XPM images

/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( NgpodwccApp )
////@end implement app

/*!
 * NgpodwccApp type definition
 */

IMPLEMENT_CLASS( NgpodwccApp, wxApp )

/*!
 * NgpodwccApp event table definition
 */

BEGIN_EVENT_TABLE( NgpodwccApp, wxApp )

////@begin NgpodwccApp event table entries
////@end NgpodwccApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for NgpodwccApp
 */

NgpodwccApp::NgpodwccApp()
{
////@begin NgpodwccApp member initialisation
////@end NgpodwccApp member initialisation
}

/*!
 * Initialisation for NgpodwccApp
 */

bool NgpodwccApp::OnInit()
{
////@begin NgpodwccApp initialisation
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
    ngpodwcc_MainFrame* mainWindow = new ngpodwcc_MainFrame( NULL, ID_FRAME_MAIN );
    mainWindow->Show(true);
////@end NgpodwccApp initialisation

    //解决不在安装目录运行控制台找不到配置文件的问题
    wxFileName *filename;
    wxString path = argv[0];
    filename = new wxFileName(path, wxPATH_WIN);
    path = filename->GetPath(wxPATH_GET_VOLUME, wxPATH_WIN);
    (mainWindow->config).SetConfigFilePath(path);
    //config.SetConfigFilePath(path);
    //wxSafeShowMessage(wxT(""), (mainWindow->config).ConfigFile);

    return true;
}

/*!
 * Cleanup for NgpodwccApp
 */
int NgpodwccApp::OnExit()
{
////@begin NgpodwccApp cleanup
    return wxApp::OnExit();
////@end NgpodwccApp cleanup
}

