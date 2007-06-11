/////////////////////////////////////////////////////////////////////////////
// Name:        dialog_config_panel.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     07/02/2006 17:00:41
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 07/02/2006 17:00:41

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dialog_config_panel.h"
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
#include "dialog_about.h"
////@end includes

#include "common_globals.h"

#include "dialog_config_panel.h"
//#include "ngpodwc_common_screen.h"

////@begin XPM images
#include "share/art/logo32x32.xpm"
#include "share/art/logo60x80.xpm"
////@end XPM images

/*!
 * dialog_config_panel type definition
 */

IMPLEMENT_CLASS( dialog_config_panel, wxFrame )

/*!
 * dialog_config_panel event table definition
 */

BEGIN_EVENT_TABLE( dialog_config_panel, wxFrame )

////@begin dialog_config_panel event table entries
    EVT_CHOICE( ID_CHOICE, dialog_config_panel::OnChoiceSelected )

    EVT_CHECKBOX( ID_CHECKBOX, dialog_config_panel::OnCheckboxClick )

    EVT_CHECKBOX( ID_CHECKBOX1, dialog_config_panel::OnCheckbox1Click )

    EVT_CHOICE( ID_CHOICE2, dialog_config_panel::OnChoice2Selected )

    EVT_BUTTON( ID_BUTTON3, dialog_config_panel::OnButton3Click )

    EVT_CHECKBOX( ID_CHECKBOX2, dialog_config_panel::OnCheckbox2Click )

    EVT_CHOICE( ID_CHOICE1, dialog_config_panel::OnChoice1Selected )

    EVT_BUTTON( ID_BUTTON1, dialog_config_panel::OnButton1Click )

    EVT_TEXT( ID_TEXTCTRL6, dialog_config_panel::OnTextctrl6Updated )

    EVT_BUTTON( ID_BUTTON, dialog_config_panel::OnButtonClick )

    EVT_TEXT( ID_TEXTCTRL7, dialog_config_panel::OnTextctrl7Updated )

    EVT_BUTTON( ID_BUTTON4, dialog_config_panel::OnButtonLocalpicturepathClick )

    EVT_TEXT( ID_TEXTCTRL, dialog_config_panel::OnTextctrlUpdated )

    EVT_BUTTON( ID_BUTTON5, dialog_config_panel::OnButtonPodbasepathClick )

    EVT_DATE_CHANGED( ID_DATEPICKERCTRL, dialog_config_panel::OnDatectrlDateChanged )

    EVT_BUTTON( ID_BUTTON6, dialog_config_panel::OnButtonReloadConfigClick )

    EVT_BUTTON( ID_BUTTON7, dialog_config_panel::OnButtonRestoreDefaultClick )

    EVT_BUTTON( ID_BUTTON9, dialog_config_panel::OnButtonSaveConfigClick )

    EVT_BUTTON( ID_BUTTON10, dialog_config_panel::OnButtonAboutClick )

    EVT_BUTTON( ID_BUTTON11, dialog_config_panel::OnButtonQuitClick )

////@end dialog_config_panel event table entries

END_EVENT_TABLE()

/*!
 * dialog_config_panel constructors
 */

dialog_config_panel::dialog_config_panel( )
{}

dialog_config_panel::dialog_config_panel( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create( parent, id, caption, pos, size, style );

    /////////add by rex humen
    InitConfig();
}

/*!
 * ngpodwcc_MainFrame creator
 */

bool dialog_config_panel::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    ////@begin dialog_config_panel member initialisation
    PictureSource = NULL;
    PauseChangeWallpaper = NULL;
    ShowSplash = NULL;
    UILanguage = NULL;
    ShowDisc = NULL;
    ScreenWidthHeight = NULL;
    ScreenWidth = NULL;
    ScreenHeight = NULL;
    ScreenPicturePath = NULL;
    ScreenPictureName = NULL;
    LocalPicturePath = NULL;
    PodBasePath = NULL;
    PodDatabaseName = NULL;
    PodPicturePath = NULL;
    NextPODDay = NULL;
    ButtonSaveConfig = NULL;
    ////@end dialog_config_panel member initialisation


    ////@begin dialog_config_panel creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("share/art/logo32x32.xpm")));
    Centre();
    ////@end dialog_config_panel creation

    return true;
}

/*!
 * Control creation for ngpodwcc_MainFrame
 */

void dialog_config_panel::CreateControls()
{
    ////@begin dialog_config_panel content construction
    dialog_config_panel* itemFrame1 = this;

    wxPanel* itemPanel2 = new wxPanel( itemFrame1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBitmap itemStaticBitmap5Bitmap(itemFrame1->GetBitmapResource(wxT("share/art/logo60x80.xpm")));
    wxStaticBitmap* itemStaticBitmap5 = new wxStaticBitmap( itemPanel2, wxID_STATIC, itemStaticBitmap5Bitmap, wxDefaultPosition, wxSize(60, 80), 0 );
    itemBoxSizer4->Add(itemStaticBitmap5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemPanel2, wxID_STATIC, _("National Geographic Photo Of the Day\nWallpaper Control Center"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText6->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxBOLD, false, _T("Tahoma")));
    itemBoxSizer4->Add(itemStaticText6, 0, wxALIGN_BOTTOM|wxALL, 5);

    wxNotebook* itemNotebook7 = new wxNotebook( itemPanel2, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_TOP|wxNB_MULTILINE );

    wxPanel* itemPanel8 = new wxPanel( itemNotebook7, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer9 = new wxFlexGridSizer(2, 2, 0, 0);
    itemPanel8->SetSizer(itemFlexGridSizer9);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemPanel8, wxID_STATIC, _("Input Source"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString PictureSourceStrings[] = {
        _("Local Picture"),
        _("NGPOD"),
        _("NGPOD Online")
    };
    PictureSource = new wxChoice( itemPanel8, ID_CHOICE, wxDefaultPosition, wxDefaultSize, 3, PictureSourceStrings, 0 );
    itemFlexGridSizer9->Add(PictureSource, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PauseChangeWallpaper = new wxCheckBox( itemPanel8, ID_CHECKBOX, _("Pause Change Wallpaper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    PauseChangeWallpaper->SetValue(false);
    itemFlexGridSizer9->Add(PauseChangeWallpaper, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ShowSplash = new wxCheckBox( itemPanel8, ID_CHECKBOX1, _("Show Splash"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    ShowSplash->SetValue(false);
    itemFlexGridSizer9->Add(ShowSplash, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel8, wxID_STATIC, _("UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemStaticText18, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString UILanguageStrings[] = {
        _("g_AppLanguageNames")
    };
    UILanguage = new wxChoice( itemPanel8, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, LANGUAGES_SIZE, g_AppLanguageNames, 0 );
    itemFlexGridSizer9->Add(UILanguage, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5);

    itemFlexGridSizer9->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton21 = new wxButton( itemPanel8, ID_BUTTON3, _("Change UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer9->Add(itemButton21, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel8, _("Common Setting"));

    wxPanel* itemPanel22 = new wxPanel( itemNotebook7, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer23 = new wxBoxSizer(wxVERTICAL);
    itemPanel22->SetSizer(itemBoxSizer23);

    itemBoxSizer23->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    ShowDisc = new wxCheckBox( itemPanel22, ID_CHECKBOX2, _("Show Disc"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    ShowDisc->SetValue(false);
    itemBoxSizer23->Add(ShowDisc, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel22, _("Image Convert Setting"));

    wxPanel* itemPanel26 = new wxPanel( itemNotebook7, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer27 = new wxFlexGridSizer(2, 3, 0, 0);
    itemPanel26->SetSizer(itemFlexGridSizer27);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText31 = new wxStaticText( itemPanel26, wxID_STATIC, _("Screen Width x Height"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemStaticText31, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxString ScreenWidthHeightStrings[] = {
        _("640x480"),
        _("800x600"),
        _("1024x768"),
        _("Auto Detect")
    };
    ScreenWidthHeight = new wxChoice( itemPanel26, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 4, ScreenWidthHeightStrings, 0 );
    itemFlexGridSizer27->Add(ScreenWidthHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5);

    wxButton* itemButton33 = new wxButton( itemPanel26, ID_BUTTON1, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemButton33, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText34 = new wxStaticText( itemPanel26, wxID_STATIC, _("Screen Width"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemStaticText34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenWidth = new wxTextCtrl( itemPanel26, ID_TEXTCTRL4, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    ScreenWidth->Enable(false);
    itemFlexGridSizer27->Add(ScreenWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText37 = new wxStaticText( itemPanel26, wxID_STATIC, _("Screen Height"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemStaticText37, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenHeight = new wxTextCtrl( itemPanel26, ID_TEXTCTRL5, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    ScreenHeight->Enable(false);
    itemFlexGridSizer27->Add(ScreenHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText40 = new wxStaticText( itemPanel26, wxID_STATIC, _("ScreenPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemStaticText40, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenPicturePath = new wxTextCtrl( itemPanel26, ID_TEXTCTRL6, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer27->Add(ScreenPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton42 = new wxButton( itemPanel26, ID_BUTTON, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemButton42, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText43 = new wxStaticText( itemPanel26, wxID_STATIC, _("ScreenPictureName"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer27->Add(itemStaticText43, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ScreenPictureName = new wxTextCtrl( itemPanel26, ID_TEXTCTRL3, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    ScreenPictureName->Enable(false);
    itemFlexGridSizer27->Add(ScreenPictureName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton47 = new wxButton( itemPanel26, ID_BUTTON2, _("Install NGPOD to Startup"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton47->Enable(false);
    itemFlexGridSizer27->Add(itemButton47, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer27->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel26, _("Environment Setting"));

    wxPanel* itemPanel51 = new wxPanel( itemNotebook7, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer52 = new wxFlexGridSizer(2, 3, 0, 0);
    itemPanel51->SetSizer(itemFlexGridSizer52);

    itemFlexGridSizer52->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer52->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer52->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText56 = new wxStaticText( itemPanel51, wxID_STATIC, _("LocalPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer52->Add(itemStaticText56, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    LocalPicturePath = new wxTextCtrl( itemPanel51, ID_TEXTCTRL7, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer52->Add(LocalPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton58 = new wxButton( itemPanel51, ID_BUTTON4, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer52->Add(itemButton58, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel51, _("Local Picture Source"));

    wxPanel* itemPanel59 = new wxPanel( itemNotebook7, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
    wxFlexGridSizer* itemFlexGridSizer60 = new wxFlexGridSizer(2, 3, 0, 0);
    itemPanel59->SetSizer(itemFlexGridSizer60);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText64 = new wxStaticText( itemPanel59, wxID_STATIC, _("PodBasePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer60->Add(itemStaticText64, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodBasePath = new wxTextCtrl( itemPanel59, ID_TEXTCTRL, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer60->Add(PodBasePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton66 = new wxButton( itemPanel59, ID_BUTTON5, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer60->Add(itemButton66, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText67 = new wxStaticText( itemPanel59, wxID_STATIC, _("PodDatabaseName"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer60->Add(itemStaticText67, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodDatabaseName = new wxTextCtrl( itemPanel59, ID_TEXTCTRL1, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    PodDatabaseName->Enable(false);
    itemFlexGridSizer60->Add(PodDatabaseName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText70 = new wxStaticText( itemPanel59, wxID_STATIC, _("PodPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer60->Add(itemStaticText70, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    PodPicturePath = new wxTextCtrl( itemPanel59, ID_TEXTCTRL2, _T(""), wxDefaultPosition, wxSize(200, -1), 0 );
    PodPicturePath->Enable(false);
    itemFlexGridSizer60->Add(PodPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText73 = new wxStaticText( itemPanel59, wxID_STATIC, _("Now POD Day"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer60->Add(itemStaticText73, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    NextPODDay = new wxDatePickerCtrl( itemPanel59, ID_DATEPICKERCTRL, wxDateTime(), wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN|wxDP_DEFAULT );
    wxDateTime minDateNextPODDay(1, (wxDateTime::Month) 2, 2001);
    wxDateTime maxDateNextPODDay;
    NextPODDay->SetRange(minDateNextPODDay, maxDateNextPODDay);
    itemFlexGridSizer60->Add(NextPODDay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer60->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook7->AddPage(itemPanel59, _("NGPOD Source"));

    itemBoxSizer3->Add(itemNotebook7, 0, wxGROW|wxALL, 5);

    wxGridSizer* itemGridSizer79 = new wxGridSizer(1, 2, 0, 0);
    itemBoxSizer3->Add(itemGridSizer79, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxSHAPED, 5);

    wxBoxSizer* itemBoxSizer80 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer79->Add(itemBoxSizer80, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton81 = new wxButton( itemPanel2, ID_BUTTON6, _("Reload Config"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer80->Add(itemButton81, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton82 = new wxButton( itemPanel2, ID_BUTTON7, _("Restore Default"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer80->Add(itemButton82, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ButtonSaveConfig = new wxButton( itemPanel2, ID_BUTTON9, _("Save Config"), wxDefaultPosition, wxDefaultSize, 0 );
    ButtonSaveConfig->Enable(false);
    itemBoxSizer80->Add(ButtonSaveConfig, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer84 = new wxBoxSizer(wxHORIZONTAL);
    itemGridSizer79->Add(itemBoxSizer84, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton85 = new wxButton( itemPanel2, ID_BUTTON10, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer84->Add(itemButton85, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton86 = new wxButton( itemPanel2, ID_BUTTON11, _("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer84->Add(itemButton86, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    ////@end dialog_config_panel content construction
}

/*!
 * Should we show tooltips?
 */

bool dialog_config_panel::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap dialog_config_panel::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
    ////@begin dialog_config_panel bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("share/art/logo60x80.xpm"))
    {
        wxBitmap bitmap( logo60x80_xpm);
        return bitmap;
    }
    return wxNullBitmap;
    ////@end dialog_config_panel bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon dialog_config_panel::GetIconResource( const wxString& name )
{
    // Icon retrieval
    ////@begin dialog_config_panel icon retrieval
    wxUnusedVar(name);
    if (name == _T("share/art/logo32x32.xpm"))
    {
        wxIcon icon( logo32x32_xpm);
        return icon;
    }
    return wxNullIcon;
    ////@end dialog_config_panel icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2
 */

void dialog_config_panel::OnButtonAboutClick( wxCommandEvent& event )
{
    DialogAbout* window = new DialogAbout(this, ID_DIALOG_ABOUT, _("About"));
    window->Show(true);
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3
 */

void dialog_config_panel::OnButtonQuitClick( wxCommandEvent& event )
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

void dialog_config_panel::OnButtonPodbasepathClick( wxCommandEvent& event )
{
    const wxString& dir = wxDirSelector(wxT("Please choice NGPOD\'s path"), config.PodBasePath, 0, wxDefaultPosition, this);
    if ( !dir.empty() )
    {
        config.PodBasePath = dir;
        PodBasePath->SetValue(config.PodBasePath);
    }
    PodBasePath->SetValue(config.PodBasePath);
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON4 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    //wxString defaultPath = config.PodBasePath;
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON4 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RELOAD_CONFIG
 */

void dialog_config_panel::OnButtonReloadConfigClick( wxCommandEvent& event )
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

void dialog_config_panel::OnButtonSaveConfigClick( wxCommandEvent& event )
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

void dialog_config_panel::OnChoice1Selected( wxCommandEvent& event )
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

void dialog_config_panel::OnButtonClick( wxCommandEvent& event )
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

void dialog_config_panel::OnButton1Click( wxCommandEvent& event )
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

void dialog_config_panel::OnButtonRestoreDefaultClick( wxCommandEvent& event )
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

void dialog_config_panel::OnTextctrlUpdated( wxCommandEvent& event )
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

void dialog_config_panel::OnTextctrl6Updated( wxCommandEvent& event )
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

void dialog_config_panel::OnDatectrlDateChanged( wxDateEvent& event )
{
    config.PodDate = NextPODDay->GetValue();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_DATE_CHANGED event handler for ID_DATECTRL in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_DATE_CHANGED event handler for ID_DATECTRL in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX
 */

void dialog_config_panel::OnCheckboxClick( wxCommandEvent& event )
{
    config.PauseChangeWallpaper = PauseChangeWallpaper->GetValue();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX1
 */

void dialog_config_panel::OnCheckbox1Click( wxCommandEvent& event )
{
    config.ShowSplash = ShowSplash->GetValue();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX1 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX1 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX2
 */

void dialog_config_panel::OnCheckbox2Click( wxCommandEvent& event )
{
    config.ShowDisc = ShowDisc->GetValue();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX2 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX2 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LocalPicturePath
 */

void dialog_config_panel::OnButtonLocalpicturepathClick( wxCommandEvent& event )
{
    const wxString& dir = wxDirSelector(wxT("Please choice Local File\'s path"), config.LocalPicturePath, 0, wxDefaultPosition, this);
    if ( !dir.empty() )
    {
        config.LocalPicturePath = dir;
        PodBasePath->SetValue(config.LocalPicturePath);
    }
    LocalPicturePath->SetValue(config.LocalPicturePath);
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LocalPicturePath in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LocalPicturePath in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL7
 */

void dialog_config_panel::OnTextctrl7Updated( wxCommandEvent& event )
{
    config.LocalPicturePath = LocalPicturePath->GetValue();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL7 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL7 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE
 */

void dialog_config_panel::OnChoiceSelected( wxCommandEvent& event )
{
    config.PictureSource = PictureSource->GetCurrentSelection();
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE2
 */

void dialog_config_panel::OnChoice2Selected( wxCommandEvent& event )
{
    config.UILanguage = g_AppLanguageCodes[UILanguage->GetCurrentSelection()];
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE2 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_CHOICE2 in ngpodwcc_MainFrame.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3
 */

void dialog_config_panel::OnButton3Click( wxCommandEvent& event )
{
    wxArrayString arr;
    for (int i=0; i<LANGUAGES_SIZE; i++)
    {
        arr.Add(g_AppLanguageNames[i]);
    }
    //wxSafeShowMessage(wxT("DEBUG"),wxT("3"));

    int choice = wxGetSingleChoiceIndex(
                     _("Select your prefered language"),
                     _("Language selection"),
                     arr);

    if (choice == -1)
    {
        //return wxLANGUAGE_UNKNOWN;
        //UILanguage = wxLANGUAGE_UNKNOWN;
    }
    else
    {
        config.UILanguage = g_AppLanguageCodes[choice];
        wxMessageBox(_("You must save config and restart NGPODWCC for this change to take effect."),
                     wxT("NGPODWCC"),
                     wxOK | wxCENTRE | wxICON_INFORMATION);
    }
    ButtonSaveConfig->Enable();
    ////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3 in ngpodwcc_MainFrame.
    // Before editing this code, remove the block markers.
    event.Skip();
    ////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON3 in ngpodwcc_MainFrame.
}


