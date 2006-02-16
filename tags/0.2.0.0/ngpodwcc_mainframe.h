/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_mainframe.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     07/02/2006 17:00:41
// RCS-ID:
// Copyright:   cooooooooooooopy
// Licence:
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 07/02/2006 17:00:41

#ifndef _NGPODWCC_MAINFRAME_H_
#define _NGPODWCC_MAINFRAME_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwcc_mainframe.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/notebook.h"
#include "wx/datectrl.h"
#include "wx/statline.h"
////@end includes

#include "ngpodwc_common_config.h"

#include "wx/dateevt.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxDatePickerCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_FRAME_MAIN 10000
#define SYMBOL_NGPODWCC_MAINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_NGPODWCC_MAINFRAME_TITLE _("Dialog")
#define SYMBOL_NGPODWCC_MAINFRAME_IDNAME ID_FRAME_MAIN
#define SYMBOL_NGPODWCC_MAINFRAME_SIZE wxSize(600, 480)
#define SYMBOL_NGPODWCC_MAINFRAME_POSITION wxDefaultPosition
#define ID_PANEL 10001
#define ID_NOTEBOOK 10002
#define ID_PANEL1 10003
#define ID_TEXTCTRL 10010
#define ID_BUTTON_PodBasePath 10011
#define ID_TEXTCTRL1 10012
#define ID_TEXTCTRL2 10029
#define ID_DATECTRL 10016
#define ID_PANEL2 10004
#define ID_PANEL3 10005
#define ID_CHOICE1 10027
#define ID_BUTTON1 10028
#define ID_TEXTCTRL4 10018
#define ID_TEXTCTRL5 10019
#define ID_TEXTCTRL6 10020
#define ID_BUTTON 10021
#define ID_TEXTCTRL3 10022
#define ID_BUTTON_RELOAD_CONFIG 10006
#define ID_BUTTON_RESTORE_DEFAULT 10007
#define ID_BUTTON_SAVE_CONFIG 10017
#define ID_BUTTON_ABOUT 10008
#define ID_BUTTON_QUIT 10009
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * ngpodwcc_MainFrame class declaration
 */

class ngpodwcc_MainFrame: public wxFrame
{
    DECLARE_CLASS( ngpodwcc_MainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ngpodwcc_MainFrame( );
    ngpodwcc_MainFrame( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWCC_MAINFRAME_IDNAME, const wxString& caption = SYMBOL_NGPODWCC_MAINFRAME_TITLE, const wxPoint& pos = SYMBOL_NGPODWCC_MAINFRAME_POSITION, const wxSize& size = SYMBOL_NGPODWCC_MAINFRAME_SIZE, long style = SYMBOL_NGPODWCC_MAINFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_NGPODWCC_MAINFRAME_IDNAME, const wxString& caption = SYMBOL_NGPODWCC_MAINFRAME_TITLE, const wxPoint& pos = SYMBOL_NGPODWCC_MAINFRAME_POSITION, const wxSize& size = SYMBOL_NGPODWCC_MAINFRAME_SIZE, long style = SYMBOL_NGPODWCC_MAINFRAME_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin ngpodwcc_MainFrame event handler declarations

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
    void OnTextctrlUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PodBasePath
    void OnButtonPodbasepathClick( wxCommandEvent& event );

    /// wxEVT_DATE_CHANGED event handler for ID_DATECTRL
    void OnDatectrlDateChanged( wxDateEvent& event );

    /// wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE1
    void OnChoice1Selected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
    void OnButton1Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL6
    void OnTextctrl6Updated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RELOAD_CONFIG
    void OnButtonReloadConfigClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RESTORE_DEFAULT
    void OnButtonRestoreDefaultClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SAVE_CONFIG
    void OnButtonSaveConfigClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ABOUT
    void OnButtonAboutClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_QUIT
    void OnButtonQuitClick( wxCommandEvent& event );

////@end ngpodwcc_MainFrame event handler declarations

////@begin ngpodwcc_MainFrame member function declarations

    ngpodwcConfig GetConfig() const { return config ; }
    void SetConfig(ngpodwcConfig value) { config = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ngpodwcc_MainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ngpodwcc_MainFrame member variables
    wxTextCtrl* PodBasePath;
    wxTextCtrl* PodDatabaseName;
    wxTextCtrl* PodPicturePath;
    wxDatePickerCtrl* NextPODDay;
    wxChoice* ScreenWidthHeight;
    wxTextCtrl* ScreenWidth;
    wxTextCtrl* ScreenHeight;
    wxTextCtrl* ScreenPicturePath;
    wxTextCtrl* ScreenPictureName;
    wxButton* ButtonSaveConfig;
    ngpodwcConfig config;
////@end ngpodwcc_MainFrame member variables

    void InitConfig(void);
    void ReadConfig(void);
    void WriteConfig(void);
    void SetDefault(void);
    void AutoDetectScreenWH(void);
    wxString AutoDetectSystemPath(void);
};

#endif
    // _NGPODWCC_MAINFRAME_H_
