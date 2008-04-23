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
    ;

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
    wxLogWarning( configStarting.PodBasePath );
    event.Skip();
}
