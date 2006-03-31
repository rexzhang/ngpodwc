/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_mini_panel.cpp
// Purpose:
// Author:      rex zhang
// Modified by:
// Created:     23/02/2006 12:18:32
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dialog_mini_panel.h"
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

#include "dialog_mini_panel.h"

////@begin XPM images
#include "art/logo32x32.xpm"
#include "art/unlock_picture.xpm"
#include "art/lock_picture.xpm"
#include "art/previous_pictrue.xpm"
#include "art/next_pictrue.xpm"
////@end XPM images

/*!
 * dialog_mini_panel type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dialog_mini_panel, wxDialog )

/*!
 * dialog_mini_panel event table definition
 */

BEGIN_EVENT_TABLE( dialog_mini_panel, wxDialog )

////@begin dialog_mini_panel event table entries
    EVT_BUTTON( ID_BITMAPBUTTON, dialog_mini_panel::OnBitmapbuttonClick )

    EVT_BUTTON( ID_BITMAPBUTTON_PRE, dialog_mini_panel::OnBitmapbuttonPreClick )

    EVT_BUTTON( ID_BITMAPBUTTON_NEXT, dialog_mini_panel::OnBitmapbuttonNextClick )

    EVT_BUTTON( ID_BUTTON_QUIT, dialog_mini_panel::OnButtonQuitClick )

////@end dialog_mini_panel event table entries

END_EVENT_TABLE()

/*!
 * dialog_mini_panel constructors
 */

dialog_mini_panel::dialog_mini_panel( )
{
}

dialog_mini_panel::dialog_mini_panel( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * ngpodwc_mini_panel creator
 */

bool dialog_mini_panel::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dialog_mini_panel member initialisation
    PauseChangeWallpaper = NULL;
    ShowPrePicture = NULL;
    ShowNextPicture = NULL;
////@end dialog_mini_panel member initialisation

////@begin dialog_mini_panel creation
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end dialog_mini_panel creation
    InitConfig();
    return true;
}

/*!
 * Control creation for ngpodwc_mini_panel
 */

void dialog_mini_panel::CreateControls()
{
////@begin dialog_mini_panel content construction
    dialog_mini_panel* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    itemBoxSizer2->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmap itemStaticBitmap5Bitmap(itemDialog1->GetBitmapResource(wxT("art/logo32x32.xpm")));
    wxStaticBitmap* itemStaticBitmap5 = new wxStaticBitmap( itemDialog1, wxID_STATIC, itemStaticBitmap5Bitmap, wxDefaultPosition, wxSize(32, 32), 0 );
    itemBoxSizer4->Add(itemStaticBitmap5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemDialog1, wxID_STATIC, _("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText6->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText6, 0, wxALIGN_BOTTOM|wxALL|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmap PauseChangeWallpaperBitmap(itemDialog1->GetBitmapResource(wxT("art/unlock_picture.xpm")));
    PauseChangeWallpaper = new wxBitmapButton( itemDialog1, ID_BITMAPBUTTON, PauseChangeWallpaperBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    wxBitmap PauseChangeWallpaperBitmapSel(itemDialog1->GetBitmapResource(wxT("art/lock_picture.xpm")));
    PauseChangeWallpaper->SetBitmapSelected(PauseChangeWallpaperBitmapSel);
    itemBoxSizer7->Add(PauseChangeWallpaper, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemBoxSizer7->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap ShowPrePictureBitmap(itemDialog1->GetBitmapResource(wxT("art/previous_pictrue.xpm")));
    ShowPrePicture = new wxBitmapButton( itemDialog1, ID_BITMAPBUTTON_PRE, ShowPrePictureBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    itemBoxSizer7->Add(ShowPrePicture, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap ShowNextPictureBitmap(itemDialog1->GetBitmapResource(wxT("art/next_pictrue.xpm")));
    ShowNextPicture = new wxBitmapButton( itemDialog1, ID_BITMAPBUTTON_NEXT, ShowNextPictureBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );
    itemBoxSizer7->Add(ShowNextPicture, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton12 = new wxButton( itemDialog1, ID_BUTTON_QUIT, _("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton12->SetDefault();
    itemBoxSizer2->Add(itemButton12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end dialog_mini_panel content construction
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PRE
 */

void dialog_mini_panel::OnBitmapbuttonPreClick( wxCommandEvent& event )
{
    DisableUpdateButton();
    seekDays(-1, &(config.PodDate));
    //updateWallpaper(&config);//, &pictureInfo);
    updateWallpaper(config);
    EnableUpdateButton();
    wxBell();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PRE in ngpodwc_mini_panel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PRE in ngpodwc_mini_panel.
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_NEXT
 */

void dialog_mini_panel::OnBitmapbuttonNextClick( wxCommandEvent& event )
{
    DisableUpdateButton();
    seekDays(1, &(config.PodDate));
    updateWallpaper(config);//, &pictureInfo);
    EnableUpdateButton();
    wxBell();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_NEXT in ngpodwc_mini_panel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_NEXT in ngpodwc_mini_panel.
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT
 */

void dialog_mini_panel::OnButtonQuitClick( wxCommandEvent& event )
{
    Destroy();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT in ngpodwc_mini_panel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT in ngpodwc_mini_panel.
}

/*!
 * Should we show tooltips?
 */

bool dialog_mini_panel::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap dialog_mini_panel::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dialog_mini_panel bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("art/logo32x32.xpm"))
    {
        wxBitmap bitmap( logo32x32_xpm);
        return bitmap;
    }
    else if (name == _T("art/unlock_picture.xpm"))
    {
        wxBitmap bitmap( unlock_picture_xpm);
        return bitmap;
    }
    else if (name == _T("art/lock_picture.xpm"))
    {
        wxBitmap bitmap( lock_picture_xpm);
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
////@end dialog_mini_panel bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon dialog_mini_panel::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dialog_mini_panel icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dialog_mini_panel icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON
 */

void dialog_mini_panel::OnBitmapbuttonClick( wxCommandEvent& event )
{
    SwapPauseChangeWallpaperStat();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON in ngpodwc_mini_panel.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON in ngpodwc_mini_panel.
}


