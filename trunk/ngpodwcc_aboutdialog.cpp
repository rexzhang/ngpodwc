/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_aboutdialog.cpp
// Purpose:     
// Author:      Rex Zhang
// Modified by: 
// Created:     07/02/2006 18:03:07
// RCS-ID:      
// Copyright:   cooooooooooooopy
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwcc_aboutdialog.h"
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

#include "ngpodwcc_aboutdialog.h"

////@begin XPM images
////@end XPM images

/*!
 * ngpodwcc_aboutdialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ngpodwcc_aboutdialog, wxDialog )

/*!
 * ngpodwcc_aboutdialog event table definition
 */

BEGIN_EVENT_TABLE( ngpodwcc_aboutdialog, wxDialog )

////@begin ngpodwcc_aboutdialog event table entries
    EVT_BUTTON( ID_BUTTON8, ngpodwcc_aboutdialog::OnButton8Click )

////@end ngpodwcc_aboutdialog event table entries

END_EVENT_TABLE()

/*!
 * ngpodwcc_aboutdialog constructors
 */

ngpodwcc_aboutdialog::ngpodwcc_aboutdialog( )
{
}

ngpodwcc_aboutdialog::ngpodwcc_aboutdialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * ngpodwcc_aboutdialog creator
 */

bool ngpodwcc_aboutdialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ngpodwcc_aboutdialog member initialisation
////@end ngpodwcc_aboutdialog member initialisation

////@begin ngpodwcc_aboutdialog creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end ngpodwcc_aboutdialog creation
    return true;
}

/*!
 * Control creation for ngpodwcc_aboutdialog
 */

void ngpodwcc_aboutdialog::CreateControls()
{    
////@begin ngpodwcc_aboutdialog content construction
    ngpodwcc_aboutdialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxPanel* itemPanel3 = new wxPanel( itemDialog1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
    itemPanel3->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer2->Add(itemPanel3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemPanel3->SetSizer(itemBoxSizer4);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemPanel3, wxID_STATIC, _("NGPODWCC"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText6->SetFont(wxFont(16, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemPanel3, wxID_STATIC, _("National Geographic Photo Of the Day Wallpaper Conterl Center"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( itemPanel3, wxID_STATIC, _("Version : x.x.x.x(build xxxx)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticLine* itemStaticLine9 = new wxStaticLine( itemPanel3, wxID_STATIC, wxDefaultPosition, wxSize(300, -1), wxLI_VERTICAL );
    itemBoxSizer4->Add(itemStaticLine9, 0, wxGROW|wxALL, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemPanel3, wxID_STATIC, _("Developey by:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemPanel3, wxID_STATIC, _("Rex Zhang(rex.zhang@gmail.com)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText14 = new wxStaticText( itemPanel3, wxID_STATIC, _("Homepage"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText14, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemPanel3, wxID_STATIC, _("Http://www.flord.net"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(itemStaticText15, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton17 = new wxButton( itemDialog1, ID_BUTTON8, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton17, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end ngpodwcc_aboutdialog content construction
}

/*!
 * Should we show tooltips?
 */

bool ngpodwcc_aboutdialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ngpodwcc_aboutdialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ngpodwcc_aboutdialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ngpodwcc_aboutdialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ngpodwcc_aboutdialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ngpodwcc_aboutdialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ngpodwcc_aboutdialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8
 */

void ngpodwcc_aboutdialog::OnButton8Click( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8 in ngpodwcc_aboutdialog.
    // Before editing this code, remove the block markers.
    Destroy();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8 in ngpodwcc_aboutdialog. 
}


