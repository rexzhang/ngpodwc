/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_mainframe.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     07/02/2006 17:00:41
// RCS-ID:
// Copyright:   cooooooooooooopy
// Licence:
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 07/02/2006 17:00:41

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwcc_mainframe.h"
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
#include "ngpodwcc_aboutdialog.h"
////@end includes

#include "ngpodwcc_mainframe.h"
#include "ngpodwc_common_screen.h"

////@begin XPM images
#include "art/logo32x32.xpm"
#include "art/logo60x80.xpm"
////@end XPM images

/*!
 * ngpodwcc_MainFrame type definition
 */

IMPLEMENT_CLASS( ngpodwcc_MainFrame, wxFrame )

/*!
 * ngpodwcc_MainFrame event table definition
 */

BEGIN_EVENT_TABLE( ngpodwcc_MainFrame, wxFrame )

////@begin ngpodwcc_MainFrame event table entries
    EVT_TEXT( ID_TEXTCTRL, ngpodwcc_MainFrame::OnTextctrlUpdated )

    EVT_BUTTON( ID_BUTTON_PodBasePath, ngpodwcc_MainFrame::OnButtonPodbasepathClick )

    EVT_DATE_CHANGED( ID_DATECTRL, ngpodwcc_MainFrame::OnDatectrlDateChanged )

    EVT_CHOICE( ID_CHOICE1, ngpodwcc_MainFrame::OnChoice1Selected )

    EVT_BUTTON( ID_BUTTON1, ngpodwcc_MainFrame::OnButton1Click )

    EVT_TEXT( ID_TEXTCTRL6, ngpodwcc_MainFrame::OnTextctrl6Updated )

    EVT_BUTTON( ID_BUTTON, ngpodwcc_MainFrame::OnButtonClick )

    EVT_BUTTON( ID_BUTTON_RELOAD_CONFIG, ngpodwcc_MainFrame::OnButtonReloadConfigClick )

    EVT_BUTTON( ID_BUTTON_RESTORE_DEFAULT, ngpodwcc_MainFrame::OnButtonRestoreDefaultClick )

    EVT_BUTTON( ID_BUTTON_SAVE_CONFIG, ngpodwcc_MainFrame::OnButtonSaveConfigClick )

    EVT_BUTTON( ID_BUTTON_ABOUT, ngpodwcc_MainFrame::OnButtonAboutClick )

    EVT_BUTTON( ID_BUTTON_QUIT, ngpodwcc_MainFrame::OnButtonQuitClick )

////@end ngpodwcc_MainFrame event table entries

END_EVENT_TABLE()

/*!
 * ngpodwcc_MainFrame constructors
 */

ngpodwcc_MainFrame::ngpodwcc_MainFrame( )
{}

ngpodwcc_MainFrame::ngpodwcc_MainFrame( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create( parent, id, caption, pos, size, style );

    /////////add by rex humen
    InitConfig();
}

/*!
 * ngpodwcc_MainFrame creator
 */

bool ngpodwcc_MainFrame::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    ////@begin ngpodwcc_MainFrame member initialisation
    PodBasePath = NULL;
    PodDatabaseName = NULL;
    PodPicturePath = NULL;
    NextPODDay = NULL;
    ScreenWidthHeight = NULL;
    ScreenWidth = NULL;
    ScreenHeight = NULL;
    ScreenPicturePath = NULL;
    ScreenPictureName = NULL;
    ButtonSaveConfig = NULL;
    ////@end ngpodwcc_MainFrame member initialisation

    config.ReadConfig();

    ////@begin ngpodwcc_MainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("art/logo32x32.xpm")));
    Centre();
    ////@end ngpodwcc_MainFrame creation

    return true;
}

/*!
 * Control creation for ngpodwcc_MainFrame
 */

void ngpodwcc_MainFrame::CreateControls()
{
    ////@begin ngpodwcc_MainFrame content construction
    ngpodwcc_MainFrame* itemFrame1 = this;

    wxPanel* itemPanel2 = new wxPanel( itemFrame1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmap itemStaticBitmap5Bitmap(itemFrame1->GetBitmapResource(wxT("art/logo60x80.xpm")));
    wxStaticBitmap* itemStaticBitmap5 = new wxStaticBitmap( itemPanel2, wxID_STATIC, itemStaticBitmap5Bitmap, wxDefaultPosition, wxSize(60, 80), 0 );
    itemBoxSizer4->Add(itemStaticBitmap5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemPanel2, wxID_STATIC, _("National Geographic Photo Of the Day\nWallpaper Control Center"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText6->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText6, 0, wxALIGN_BOTTOM|wxALL, 5);

    wxNotebook* itemNotebook7 = new wxNotebook( itemPanel2, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_TOP );

    wxPanel* itemPanel8 = new wxPanel( itemNotebook7, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer9 = new wxFlexGridSizer(2, 3, 0, 0);
    itemPanel8->SetSizer(itemFlexGridSizer9);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText13 = new wxStaticText( itemPanel8, wxID_STATIC, _("PodBasePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText13, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodBasePath = new wxTextCtrl( itemPanel8, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer9->Add(PodBasePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton15 = new wxButton( itemPanel8, ID_BUTTON_PodBasePath, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemButton15, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemPanel8, wxID_STATIC, _("PodDatabaseName"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText16, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodDatabaseName = new wxTextCtrl( itemPanel8, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    PodDatabaseName->Enable(false);
    itemFlexGridSizer9->Add(PodDatabaseName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText19 = new wxStaticText( itemPanel8, wxID_STATIC, _("PodPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText19, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodPicturePath = new wxTextCtrl( itemPanel8, ID_TEXTCTRL2, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    PodPicturePath->Enable(false);
    itemFlexGridSizer9->Add(PodPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText22 = new wxStaticText( itemPanel8, wxID_STATIC, _("Next POD Day"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText22, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    NextPODDay = new wxDatePickerCtrl( itemPanel8, ID_DATECTRL, wxDateTime(), wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN|wxDP_DEFAULT );
    wxDateTime minDateNextPODDay(1, (wxDateTime::Month) 2, 2001);
    wxDateTime maxDateNextPODDay;
    NextPODDay->SetRange(minDateNextPODDay, maxDateNextPODDay);
    itemFlexGridSizer9->Add(NextPODDay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel8, _("NGPOD Source Setting"));

    wxPanel* itemPanel25 = new wxPanel( itemNotebook7, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxStaticText* itemStaticText26 = new wxStaticText( itemPanel25, wxID_STATIC, _("Comming soon..."), wxDefaultPosition, wxDefaultSize, 0 );

    itemNotebook7->AddPage(itemPanel25, _("Image Convert Setting"));

    wxPanel* itemPanel27 = new wxPanel( itemNotebook7, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer28 = new wxFlexGridSizer(2, 3, 0, 0);
    itemPanel27->SetSizer(itemFlexGridSizer28);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText32 = new wxStaticText( itemPanel27, wxID_STATIC, _("Screen Width x Height"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemStaticText32, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString ScreenWidthHeightStrings[] = {
        _("640x480"),
        _("800x600"),
        _("1024x768"),
        _("Auto Detect")
    };
    ScreenWidthHeight = new wxChoice( itemPanel27, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 4, ScreenWidthHeightStrings, 0 );
    itemFlexGridSizer28->Add(ScreenWidthHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton34 = new wxButton( itemPanel27, ID_BUTTON1, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemButton34, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText35 = new wxStaticText( itemPanel27, wxID_STATIC, _("Screen Width"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemStaticText35, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenWidth = new wxTextCtrl( itemPanel27, ID_TEXTCTRL4, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    ScreenWidth->Enable(false);
    itemFlexGridSizer28->Add(ScreenWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText38 = new wxStaticText( itemPanel27, wxID_STATIC, _("Screen Height"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemStaticText38, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenHeight = new wxTextCtrl( itemPanel27, ID_TEXTCTRL5, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    ScreenHeight->Enable(false);
    itemFlexGridSizer28->Add(ScreenHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText41 = new wxStaticText( itemPanel27, wxID_STATIC, _("ScreenPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemStaticText41, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenPicturePath = new wxTextCtrl( itemPanel27, ID_TEXTCTRL6, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer28->Add(ScreenPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton43 = new wxButton( itemPanel27, ID_BUTTON, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemButton43, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText44 = new wxStaticText( itemPanel27, wxID_STATIC, _("ScreenPictureName"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(itemStaticText44, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenPictureName = new wxTextCtrl( itemPanel27, ID_TEXTCTRL3, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    ScreenPictureName->Enable(false);
    itemFlexGridSizer28->Add(ScreenPictureName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer28->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel27, _("Screen Info Setting"));

    itemBoxSizer3->Add(itemNotebook7, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer49 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer49, 0, wxALIGN_LEFT|wxALL, 5);

    wxButton* itemButton50 = new wxButton( itemPanel2, ID_BUTTON_RELOAD_CONFIG, _("Reload Config"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer49->Add(itemButton50, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton51 = new wxButton( itemPanel2, ID_BUTTON_RESTORE_DEFAULT, _("Restore Default"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer49->Add(itemButton51, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ButtonSaveConfig = new wxButton( itemPanel2, ID_BUTTON_SAVE_CONFIG, _("Save Config"), wxDefaultPosition, wxDefaultSize, 0 );
    ButtonSaveConfig->Enable(false);
    itemBoxSizer49->Add(ButtonSaveConfig, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticLine* itemStaticLine53 = new wxStaticLine( itemPanel2, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer3->Add(itemStaticLine53, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer54 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer54, 0, wxALIGN_RIGHT|wxALL, 5);

    wxButton* itemButton55 = new wxButton( itemPanel2, ID_BUTTON_ABOUT, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer54->Add(itemButton55, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton56 = new wxButton( itemPanel2, ID_BUTTON_QUIT, _("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer54->Add(itemButton56, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ////@end ngpodwcc_MainFrame content construction
}

/*!
 * Should we show tooltips?
 */

bool ngpodwcc_MainFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ngpodwcc_MainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
    ////@begin ngpodwcc_MainFrame bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("art/logo60x80.xpm"))
    {
        wxBitmap bitmap( logo60x80_xpm);
        return bitmap;
    }
    return wxNullBitmap;
    ////@end ngpodwcc_MainFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ngpodwcc_MainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
    ////@begin ngpodwcc_MainFrame icon retrieval
    wxUnusedVar(name);
    if (name == _T("art/logo32x32.xpm"))
    {
        wxIcon icon( logo32x32_xpm);
        return icon;
    }
    return wxNullIcon;
    ////@end ngpodwcc_MainFrame icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2
 */

void ngpodwcc_MainFrame::OnButtonAboutClick( wxCommandEvent& event )
{
    ngpodwcc_aboutdialog* window = new ngpodwcc_aboutdialog(NULL, ID_DIALOG_ABOUT, _("Dialog"));
    window->Show(true);
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3
 */

void ngpodwcc_MainFrame::OnButtonQuitClick( wxCommandEvent& event )
{
    Destroy();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON4
 */

void ngpodwcc_MainFrame::OnButtonPodbasepathClick( wxCommandEvent& event )
{
    wxDirDialog dialog(NULL,wxT("Please choice NGPOD\'s path"),config.PodBasePath);
    if (dialog.ShowModal() == wxID_OK)
    {
        config.PodBasePath = dialog.GetPath();
        PodBasePath->SetValue(config.PodBasePath);

        wxMessageBox(config.PodBasePath);
    }
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON4 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    //wxString defaultPath = config.PodBasePath;
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON4 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RELOAD_CONFIG
 */

void ngpodwcc_MainFrame::OnButtonReloadConfigClick( wxCommandEvent& event )
{
    ReadConfig();

    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RELOAD_CONFIG in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RELOAD_CONFIG in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SAVE_CONFIG
 */

void ngpodwcc_MainFrame::OnButtonSaveConfigClick( wxCommandEvent& event )
{
    WriteConfig();

    ButtonSaveConfig->Disable();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SAVE_CONFIG in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SAVE_CONFIG in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE1
 */

void ngpodwcc_MainFrame::OnChoice1Selected( wxCommandEvent& event )
{
    //ScreenWidthHeight->GetCurrentSelection();
    switch (ScreenWidthHeight->GetCurrentSelection())
    {
        case SCREENWH640x480:
        config.ScreenWidth = 640;
        config.ScreenHeight = 480;
        ScreenWidth->SetValue(wxT("640"));
        ScreenHeight->SetValue(wxT("480"));
        break;
        case SCREENWH800x600:
        config.ScreenWidth = 800;
        config.ScreenHeight = 600;
        ScreenWidth->SetValue(wxT("800"));
        ScreenHeight->SetValue(wxT("600"));
        break;
        case SCREENWH1024x768:
        config.ScreenWidth = 1024;
        config.ScreenHeight = 768;
        ScreenWidth->SetValue(wxT("1024"));
        ScreenHeight->SetValue(wxT("768"));
        break;
        //case 3:
        default:
        //SCREENWHAutoDetect
        AutoDetectScreenWH();
    }

    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE1 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE1 in ngpodwcc_MainFrame.
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void ngpodwcc_MainFrame::OnButtonClick( wxCommandEvent& event )
{
    config.ScreenPicturePath = AutoDetectSystemPath();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

void ngpodwcc_MainFrame::OnButton1Click( wxCommandEvent& event )
{
    AutoDetectScreenWH();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1 in ngpodwcc_MainFrame.
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RESTORE_DEFAULT
 */

void ngpodwcc_MainFrame::OnButtonRestoreDefaultClick( wxCommandEvent& event )
{
    SetDefault();
    ButtonSaveConfig->Enable();
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RESTORE_DEFAULT in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RESTORE_DEFAULT in ngpodwcc_MainFrame.
}

/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL
 */

void ngpodwcc_MainFrame::OnTextctrlUpdated( wxCommandEvent& event )
{
    config.PodBasePath = PodBasePath->GetValue();
    ButtonSaveConfig->Enable();
////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL in ngpodwcc_MainFrame.
}

/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL6
 */

void ngpodwcc_MainFrame::OnTextctrl6Updated( wxCommandEvent& event )
{
    config.ScreenPicturePath = ScreenPicturePath->GetValue();
    ButtonSaveConfig->Enable();
////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL6 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL6 in ngpodwcc_MainFrame.
}
/*!
 * wxEVT_DATE_CHANGED event handler for ID_DATECTRL
 */

void ngpodwcc_MainFrame::OnDatectrlDateChanged( wxDateEvent& event )
{
    config.PodDate = NextPODDay->GetValue();
    ButtonSaveConfig->Enable();
////@begin wxEVT_DATE_CHANGED event handler for ID_DATECTRL in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_DATE_CHANGED event handler for ID_DATECTRL in ngpodwcc_MainFrame.
}


