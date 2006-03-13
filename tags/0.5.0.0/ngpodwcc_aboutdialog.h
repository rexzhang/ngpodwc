/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_aboutdialog.h
// Purpose:     
// Author:      Rex Zhang
// Modified by: 
// Created:     07/02/2006 18:03:07
// RCS-ID:      
// Copyright:   cooooooooooooopy
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _NGPODWCC_ABOUTDIALOG_H_
#define _NGPODWCC_ABOUTDIALOG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwcc_aboutdialog.h"
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
#define SYMBOL_NGPODWCC_ABOUTDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_NGPODWCC_ABOUTDIALOG_TITLE _("Dialog")
#define SYMBOL_NGPODWCC_ABOUTDIALOG_IDNAME ID_DIALOG_ABOUT
#define SYMBOL_NGPODWCC_ABOUTDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_NGPODWCC_ABOUTDIALOG_POSITION wxDefaultPosition
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
 * ngpodwcc_aboutdialog class declaration
 */

class ngpodwcc_aboutdialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( ngpodwcc_aboutdialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ngpodwcc_aboutdialog( );
    ngpodwcc_aboutdialog( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWCC_ABOUTDIALOG_IDNAME, const wxString& caption = SYMBOL_NGPODWCC_ABOUTDIALOG_TITLE, const wxPoint& pos = SYMBOL_NGPODWCC_ABOUTDIALOG_POSITION, const wxSize& size = SYMBOL_NGPODWCC_ABOUTDIALOG_SIZE, long style = SYMBOL_NGPODWCC_ABOUTDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWCC_ABOUTDIALOG_IDNAME, const wxString& caption = SYMBOL_NGPODWCC_ABOUTDIALOG_TITLE, const wxPoint& pos = SYMBOL_NGPODWCC_ABOUTDIALOG_POSITION, const wxSize& size = SYMBOL_NGPODWCC_ABOUTDIALOG_SIZE, long style = SYMBOL_NGPODWCC_ABOUTDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin ngpodwcc_aboutdialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON8
    void OnButton8Click( wxCommandEvent& event );

////@end ngpodwcc_aboutdialog event handler declarations

////@begin ngpodwcc_aboutdialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ngpodwcc_aboutdialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ngpodwcc_aboutdialog member variables
////@end ngpodwcc_aboutdialog member variables
};

#endif
    // _NGPODWCC_ABOUTDIALOG_H_
