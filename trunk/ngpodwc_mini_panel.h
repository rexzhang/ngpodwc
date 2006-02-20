/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc_mini_panel.h
// Purpose:     
// Author:      rex zhang
// Modified by: 
// Created:     19/02/2006 22:20:56
// RCS-ID:      
// Copyright:   coooooooooopy
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _NGPODWC_MINI_PANEL_H_
#define _NGPODWC_MINI_PANEL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwc_mini_panel.h"
#endif

/*!
 * Includes
 */

////@begin includes
////@end includes

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
#define SYMBOL_NGPODWC_MINI_PANEL_STYLE 0
#define SYMBOL_NGPODWC_MINI_PANEL_TITLE _("Dialog")
#define SYMBOL_NGPODWC_MINI_PANEL_IDNAME ID_DIALOG
#define SYMBOL_NGPODWC_MINI_PANEL_SIZE wxSize(400, 300)
#define SYMBOL_NGPODWC_MINI_PANEL_POSITION wxDefaultPosition
#define ID_BITMAPBUTTON 10001
#define ID_BITMAPBUTTON1 10002
#define ID_BITMAPBUTTON3 10004
#define ID_BUTTON_QUIT 10003
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * ngpodwc_mini_panel class declaration
 */

class ngpodwc_mini_panel: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( ngpodwc_mini_panel )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ngpodwc_mini_panel( );
    ngpodwc_mini_panel( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWC_MINI_PANEL_IDNAME, const wxPoint& pos = SYMBOL_NGPODWC_MINI_PANEL_POSITION, const wxSize& size = SYMBOL_NGPODWC_MINI_PANEL_SIZE, long style = SYMBOL_NGPODWC_MINI_PANEL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWC_MINI_PANEL_IDNAME, const wxPoint& pos = SYMBOL_NGPODWC_MINI_PANEL_POSITION, const wxSize& size = SYMBOL_NGPODWC_MINI_PANEL_SIZE, long style = SYMBOL_NGPODWC_MINI_PANEL_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin ngpodwc_mini_panel event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT
    void OnButtonQuitClick( wxCommandEvent& event );

////@end ngpodwc_mini_panel event handler declarations

////@begin ngpodwc_mini_panel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ngpodwc_mini_panel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ngpodwc_mini_panel member variables
////@end ngpodwc_mini_panel member variables
};

#endif
    // _NGPODWC_MINI_PANEL_H_
