/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_about.h
// Purpose:
// Author:      Rex Zhang(rex.zhang@gmail.com)
// Modified by:
// Created:     07/02/2006 80:03:07
// RCS-ID:
// Copyright:   (c) 2006, Rex Zhang
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _DIALOG_ABOUT_H_
#define _DIALOG_ABOUT_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "dialog_about.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/statline.h"
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
#define ID_DIALOG_ABOUT 10023
#define SYMBOL_DIALOGABOUT_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_DIALOGABOUT_TITLE _("About")
#define SYMBOL_DIALOGABOUT_IDNAME ID_DIALOG_ABOUT
#define SYMBOL_DIALOGABOUT_SIZE wxSize(400, 300)
#define SYMBOL_DIALOGABOUT_POSITION wxDefaultPosition
#define ID_PANEL4 10024
#define ID_BUTTON8 10025
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * DialogAbout class declaration
 */

class DialogAbout: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( DialogAbout )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    DialogAbout( );
    DialogAbout( wxWindow* parent, wxWindowID id = SYMBOL_DIALOGABOUT_IDNAME, const wxString& caption = SYMBOL_DIALOGABOUT_TITLE, const wxPoint& pos = SYMBOL_DIALOGABOUT_POSITION, const wxSize& size = SYMBOL_DIALOGABOUT_SIZE, long style = SYMBOL_DIALOGABOUT_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DIALOGABOUT_IDNAME, const wxString& caption = SYMBOL_DIALOGABOUT_TITLE, const wxPoint& pos = SYMBOL_DIALOGABOUT_POSITION, const wxSize& size = SYMBOL_DIALOGABOUT_SIZE, long style = SYMBOL_DIALOGABOUT_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin DialogAbout event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8
    void OnButton8Click( wxCommandEvent& event );

////@end DialogAbout event handler declarations

////@begin DialogAbout member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end DialogAbout member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin DialogAbout member variables
////@end DialogAbout member variables
};

#endif
    // _DIALOG_ABOUT_H_
