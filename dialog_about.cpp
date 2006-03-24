/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_about.cpp
// Purpose:
// Author:      Rex Zhang(rex.zhang@gmail.com)
// Modified by:
// Created:     07/02/2006 80:03:07
// RCS-ID:
// Copyright:   (c) 2006, Rex Zhang
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dialog_about.h"
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

#include "dialog_about.h"

#include "common_globals.h"

////@begin XPM images
#include "art/logo60x80.xpm"
////@end XPM images

/*!
 * DialogAbout type definition
 */

IMPLEMENT_DYNAMIC_CLASS( DialogAbout, wxDialog )

/*!
 * DialogAbout event table definition
 */

BEGIN_EVENT_TABLE( DialogAbout, wxDialog )

////@begin DialogAbout event table entries
    EVT_BUTTON( ID_BUTTON8, DialogAbout::OnButton8Click )

////@end DialogAbout event table entries

END_EVENT_TABLE()

/*!
 * DialogAbout constructors
 */

DialogAbout::DialogAbout( )
{
}

DialogAbout::DialogAbout( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);

    UpdateAboutInfo();
}

/*!
 * ngpodwcc_aboutdialog creator
 */

bool DialogAbout::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin DialogAbout member initialisation
////@end DialogAbout member initialisation

////@begin DialogAbout creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end DialogAbout creation
    return true;
}

/*!
 * Control creation for ngpodwcc_aboutdialog
 */

void DialogAbout::CreateControls()
{
////@begin DialogAbout content construction
    DialogAbout* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxPanel* itemPanel3 = new wxPanel( itemDialog1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
    itemPanel3->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer2->Add(itemPanel3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemPanel3->SetSizer(itemBoxSizer4);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer4->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmap itemStaticBitmap7Bitmap(itemDialog1->GetBitmapResource(wxT("art/logo60x80.xpm")));
    wxStaticBitmap* itemStaticBitmap7 = new wxStaticBitmap( itemPanel3, wxID_STATIC, itemStaticBitmap7Bitmap, wxDefaultPosition, wxSize(60, 80), 0 );
    itemBoxSizer6->Add(itemStaticBitmap7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( itemPanel3, wxID_STATIC, _("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText8->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer6->Add(itemStaticText8, 0, wxALIGN_BOTTOM|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemPanel3, wxID_STATIC, wxT("Version: ") + g_AppVersion, wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText9->SetForegroundColour(wxColour(128, 128, 128));
    itemBoxSizer4->Add(itemStaticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticLine* itemStaticLine10 = new wxStaticLine( itemPanel3, wxID_STATIC, wxDefaultPosition, wxSize(300, -1), wxLI_VERTICAL );
    itemBoxSizer4->Add(itemStaticLine10, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemPanel3, wxID_STATIC, wxT("Bulid: ") + g_AppBuildTimestamp, wxDefaultPosition, wxDefaultSize, 0
 );
    itemStaticText11->SetForegroundColour(wxColour(128, 128, 128));
    itemBoxSizer4->Add(itemStaticText11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemPanel3, wxID_STATIC, _("Developey by"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText13->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText13, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText14 = new wxStaticText( itemPanel3, wxID_STATIC, g_AppProjectLeader + wxT("(") + g_AppProjectLeaderEmail + wxT(")"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText14, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemPanel3, wxID_STATIC, _("Homepage"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText16->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText16, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText17 = new wxStaticText( itemPanel3, wxID_STATIC, g_AppUrl, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText17, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel3, wxID_STATIC, g_AppUrl2, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText18, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText19 = new wxStaticText( itemPanel3, wxID_STATIC, g_AppUrl3, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText19, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton21 = new wxButton( itemDialog1, ID_BUTTON8, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton21->SetDefault();
    itemBoxSizer2->Add(itemButton21, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end DialogAbout content construction
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8
 */

void DialogAbout::OnButton8Click( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8 in ngpodwcc_aboutdialog.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8 in ngpodwcc_aboutdialog.
}

/*!
 * Should we show tooltips?
 */

bool DialogAbout::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap DialogAbout::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin DialogAbout bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("art/logo60x80.xpm"))
    {
        wxBitmap bitmap( logo60x80_xpm);
        return bitmap;
    }
    return wxNullBitmap;
////@end DialogAbout bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon DialogAbout::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin DialogAbout icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end DialogAbout icon retrieval
}
