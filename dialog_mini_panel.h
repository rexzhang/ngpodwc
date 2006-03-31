/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_mini_panel.h
// Purpose:
// Author:      rex zhang
// Modified by:
// Created:     23/02/2006 12:18:32
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifndef _DIALOG_MINI_PANEL_H_
#define _DIALOG_MINI_PANEL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dialog_mini_panel.h"
#endif

/*!
 * Includes
 */

////@begin includes
////@end includes

#include "common_wallpaper_operation.h"
#include "common_config.h"
#include "ngpodwc_common_ngpodinfo.h"
/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define SYMBOL_DIALOG_MINI_PANEL_STYLE wxDEFAULT_DIALOG_STYLE
#define SYMBOL_DIALOG_MINI_PANEL_TITLE _("National Geographic Photo Of the Day Wallpaper Changer")
#define SYMBOL_DIALOG_MINI_PANEL_IDNAME ID_DIALOG
#define SYMBOL_DIALOG_MINI_PANEL_SIZE wxSize(400, 300)
#define SYMBOL_DIALOG_MINI_PANEL_POSITION wxDefaultPosition
#define ID_BITMAPBUTTON 10001
#define ID_BITMAPBUTTON_PRE 10002
#define ID_BITMAPBUTTON_NEXT 10004
#define ID_BUTTON_QUIT 10003
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * dialog_mini_panel class declaration
 */

class dialog_mini_panel: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( dialog_mini_panel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dialog_mini_panel( );
    dialog_mini_panel( wxWindow* parent, wxWindowID id = SYMBOL_DIALOG_MINI_PANEL_IDNAME, const wxString& caption = SYMBOL_DIALOG_MINI_PANEL_TITLE, const wxPoint& pos = SYMBOL_DIALOG_MINI_PANEL_POSITION, const wxSize& size = SYMBOL_DIALOG_MINI_PANEL_SIZE, long style = SYMBOL_DIALOG_MINI_PANEL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DIALOG_MINI_PANEL_IDNAME, const wxString& caption = SYMBOL_DIALOG_MINI_PANEL_TITLE, const wxPoint& pos = SYMBOL_DIALOG_MINI_PANEL_POSITION, const wxSize& size = SYMBOL_DIALOG_MINI_PANEL_SIZE, long style = SYMBOL_DIALOG_MINI_PANEL_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin dialog_mini_panel event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON
    void OnBitmapbuttonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PRE
    void OnBitmapbuttonPreClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_NEXT
    void OnBitmapbuttonNextClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT
    void OnButtonQuitClick( wxCommandEvent& event );

////@end dialog_mini_panel event handler declarations

////@begin dialog_mini_panel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dialog_mini_panel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

    void InitConfig();
    void ShowConfig();
    void SwapPauseChangeWallpaperStat();
    void DisableUpdateButton();
    void EnableUpdateButton();

////@begin dialog_mini_panel member variables
    wxBitmapButton* PauseChangeWallpaper;
    wxBitmapButton* ShowPrePicture;
    wxBitmapButton* ShowNextPicture;
////@end dialog_mini_panel member variables

    ngpodwcConfig config;
    //ngpodinfo pictureInfo;
};

#endif
    // _DIALOG_MINI_PANEL_H_
