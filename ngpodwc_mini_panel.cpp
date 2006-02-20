/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc_mini_panel.cpp
// Purpose:     
// Author:      rex zhang
// Modified by: 
// Created:     19/02/2006 22:20:56
// RCS-ID:      
// Copyright:   coooooooooopy
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwc_mini_panel.h"
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

#include "ngpodwc_mini_panel.h"

////@begin XPM images
#include "art/unlock_picture.xpm"
#include "art/previous_pictrue.xpm"
#include "art/next_pictrue.xpm"
////@end XPM images

/*!
 * ngpodwc_mini_panel type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ngpodwc_mini_panel, wxPanel )

/*!
 * ngpodwc_mini_panel event table definition
 */

BEGIN_EVENT_TABLE( ngpodwc_mini_panel, wxPanel )

////@begin ngpodwc_mini_panel event table entries
    EVT_BUTTON( ID_BUTTON_QUIT, ngpodwc_mini_panel::OnButtonQuitClick )

////@end ngpodwc_mini_panel event table entries

END_EVENT_TABLE()

/*!
 * ngpodwc_mini_panel constructors
 */

ngpodwc_mini_panel::ngpodwc_mini_panel( )
{
}

ngpodwc_mini_panel::ngpodwc_mini_panel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, pos, size, style);
}

/*!
 * ngpodwc_mini_panel creator
 */

bool ngpodwc_mini_panel::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ngpodwc_mini_panel member initialisation
////@end ngpodwc_mini_panel member initialisation

////@begin ngpodwc_mini_panel creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end ngpodwc_mini_panel creation
    return true;
}

/*!
 * Control creation for ngpodwc_mini_panel
 */

void ngpodwc_mini_panel::CreateControls()
{    
////@begin ngpodwc_mini_panel content construction
    ngpodwc_mini_panel* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    itemBoxSizer2->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemPanel1, wxID_STATIC, _("NGPODWC"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText4->SetFont(wxFont(15, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer2->Add(itemStaticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    itemBoxSizer2->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap itemBitmapButton9Bitmap(itemPanel1->GetBitmapResource(wxT("art/unlock_picture.xpm")));
    wxBitmapButton* itemBitmapButton9 = new wxBitmapButton( itemPanel1, ID_BITMAPBUTTON, itemBitmapButton9Bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    itemBoxSizer6->Add(itemBitmapButton9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap itemBitmapButton11Bitmap(itemPanel1->GetBitmapResource(wxT("art/previous_pictrue.xpm")));
    wxBitmapButton* itemBitmapButton11 = new wxBitmapButton( itemPanel1, ID_BITMAPBUTTON1, itemBitmapButton11Bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    itemBoxSizer6->Add(itemBitmapButton11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap itemBitmapButton12Bitmap(itemPanel1->GetBitmapResource(wxT("art/next_pictrue.xpm")));
    wxBitmapButton* itemBitmapButton12 = new wxBitmapButton( itemPanel1, ID_BITMAPBUTTON3, itemBitmapButton12Bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    itemBoxSizer6->Add(itemBitmapButton12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer6->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer2->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton16 = new wxButton( itemPanel1, ID_BUTTON_QUIT, _("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton16->SetDefault();
    itemBoxSizer2->Add(itemButton16, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end ngpodwc_mini_panel content construction
}

/*!
 * Should we show tooltips?
 */

bool ngpodwc_mini_panel::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ngpodwc_mini_panel::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ngpodwc_mini_panel bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("art/unlock_picture.xpm"))
    {
        wxBitmap bitmap( unlock_picture_xpm);
        return bitmap;
    }
    else if (name == _T("art/previous_pictrue.xpm"))
    {
        wxBitmap bitmap( previous_pictrue_xpm);
        return bitmap;
    }
    else if (name == _T("art/next_pictrue.xpm"))
    {
        wxBitmap bitmap( next_pictrue_xpm);
        return bitmap;
    }
    return wxNullBitmap;
////@end ngpodwc_mini_panel bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ngpodwc_mini_panel::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ngpodwc_mini_panel icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ngpodwc_mini_panel icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT
 */

void ngpodwc_mini_panel::OnButtonQuitClick( wxCommandEvent& event )
{
    Destroy();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT in ngpodwc_mini_panel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT in ngpodwc_mini_panel. 
}


