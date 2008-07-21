///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUIFrame.h"

#include "share/art/icon_info.xpm"
#include "share/art/icon_quit.xpm"
#include "share/art/icon_settings.xpm"
#include "share/art/lock_picture.xpm"
#include "share/art/logo60x80.xpm"
#include "share/art/next_pictrue.xpm"
#include "share/art/previous_pictrue.xpm"
#include "share/art/unlock_picture.xpm"

///////////////////////////////////////////////////////////////////////////

GUI_dialogMiniPanel::GUI_dialogMiniPanel( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( logo60x80_xpm ), wxDefaultPosition, wxSize( 60,80 ), 0 );
	bSizer5->Add( m_bitmap4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, _("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	m_staticText24->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer5->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5 );
	
	bSizer4->Add( bSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	mPauseChangeWallpaper = new wxBitmapButton( this, wxID_ANY, wxBitmap( unlock_picture_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	
	mPauseChangeWallpaper->SetBitmapSelected( wxBitmap( lock_picture_xpm ) );
	mPauseChangeWallpaper->SetDefault(); 
	mPauseChangeWallpaper->SetToolTip( _("Pause/Unpause change wallpaper") );
	
	mPauseChangeWallpaper->SetToolTip( _("Pause/Unpause change wallpaper") );
	
	bSizer6->Add( mPauseChangeWallpaper, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mShowPrePicture = new wxBitmapButton( this, wxID_ANY, wxBitmap( previous_pictrue_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	mShowPrePicture->SetDefault(); 
	mShowPrePicture->SetToolTip( _("Show previous pictrue") );
	
	mShowPrePicture->SetToolTip( _("Show previous pictrue") );
	
	bSizer6->Add( mShowPrePicture, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mShowNextPicture = new wxBitmapButton( this, wxID_ANY, wxBitmap( next_pictrue_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	mShowNextPicture->SetDefault(); 
	mShowNextPicture->SetToolTip( _("Show next pictrue") );
	
	mShowNextPicture->SetToolTip( _("Show next pictrue") );
	
	bSizer6->Add( mShowNextPicture, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mControlCenter = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_settings_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	mControlCenter->SetDefault(); 
	mControlCenter->SetToolTip( _("Control Center") );
	
	mControlCenter->SetToolTip( _("Control Center") );
	
	bSizer6->Add( mControlCenter, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mAbout = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_info_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	mAbout->SetDefault(); 
	mAbout->SetToolTip( _("About") );
	
	mAbout->SetToolTip( _("About") );
	
	bSizer6->Add( mAbout, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mQuit = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_quit_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	mQuit->SetDefault(); 
	mQuit->SetToolTip( _("Quit") );
	
	mQuit->SetToolTip( _("Quit") );
	
	bSizer6->Add( mQuit, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer4->Add( bSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	mPauseChangeWallpaper->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickPauseChangeWallpaper ), NULL, this );
	mShowPrePicture->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickShowPrePicture ), NULL, this );
	mShowNextPicture->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickShowNextPicture ), NULL, this );
	mControlCenter->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickControlCenter ), NULL, this );
	mAbout->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickAbout ), NULL, this );
	mQuit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickQuit ), NULL, this );
}

GUI_dialogMiniPanel::~GUI_dialogMiniPanel()
{
	// Disconnect Events
	mPauseChangeWallpaper->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickPauseChangeWallpaper ), NULL, this );
	mShowPrePicture->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickShowPrePicture ), NULL, this );
	mShowNextPicture->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickShowNextPicture ), NULL, this );
	mControlCenter->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickControlCenter ), NULL, this );
	mAbout->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickAbout ), NULL, this );
	mQuit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogMiniPanel::OnButtonClickQuit ), NULL, this );
}

GUI_dialogConfigPanel::GUI_dialogConfigPanel( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_panel8 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap5 = new wxStaticBitmap( m_panel8, wxID_ANY, wxBitmap( logo60x80_xpm ), wxDefaultPosition, wxSize( 60,80 ), 0 );
	bSizer6->Add( m_bitmap5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText25 = new wxStaticText( m_panel8, wxID_ANY, _("National Geographic Photo Of the Day\nWallpaper Control Center"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	m_staticText25->SetFont( wxFont( 11, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer6->Add( m_staticText25, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	bSizer5->Add( bSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_notebook2 = new wxNotebook( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_DEFAULT|wxNB_TOP|wxNB_MULTILINE );
	ID_PANEL1 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText26 = new wxStaticText( ID_PANEL1, wxID_ANY, _("Input Source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer1->Add( m_staticText26, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString mPictureSourceChoices[] = { _("Local Picture"), _("NGPOD"), _("NGPOD Online") };
	int mPictureSourceNChoices = sizeof( mPictureSourceChoices ) / sizeof( wxString );
	mPictureSource = new wxChoice( ID_PANEL1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mPictureSourceNChoices, mPictureSourceChoices, 0 );
	mPictureSource->SetSelection( 0 );
	fgSizer1->Add( mPictureSource, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mPauseChangeWallpaper = new wxCheckBox( ID_PANEL1, wxID_ANY, _("Pause Change Wallpaper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	fgSizer1->Add( mPauseChangeWallpaper, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mShowSplash = new wxCheckBox( ID_PANEL1, wxID_ANY, _("Show Splash"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	fgSizer1->Add( mShowSplash, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText27 = new wxStaticText( ID_PANEL1, wxID_ANY, _("UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer1->Add( m_staticText27, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString mUILanguageChoices;
	mUILanguage = new wxChoice( ID_PANEL1, wxID_ANY, wxDefaultPosition, wxDefaultSize, mUILanguageChoices, 0 );
	mUILanguage->SetSelection( 0 );
	fgSizer1->Add( mUILanguage, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mChangeUILanguage = new wxButton( ID_PANEL1, wxID_ANY, _("Change UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
	mChangeUILanguage->SetDefault(); 
	fgSizer1->Add( mChangeUILanguage, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL1->SetSizer( fgSizer1 );
	ID_PANEL1->Layout();
	fgSizer1->Fit( ID_PANEL1 );
	m_notebook2->AddPage( ID_PANEL1, _("Common Setting"), true );
	ID_PANEL2 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer7->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	mShowDisc = new wxCheckBox( ID_PANEL2, wxID_ANY, _("Show Disc"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	bSizer7->Add( mShowDisc, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_PANEL2->SetSizer( bSizer7 );
	ID_PANEL2->Layout();
	bSizer7->Fit( ID_PANEL2 );
	m_notebook2->AddPage( ID_PANEL2, _("Image Convert Setting"), false );
	ID_PANEL3 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText28 = new wxStaticText( ID_PANEL3, wxID_ANY, _("Screen Width x Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer2->Add( m_staticText28, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString mScreenWidthHeightChoices[] = { _("640x480"), _("800x600"), _("1024x768"), _("Auto Detect") };
	int mScreenWidthHeightNChoices = sizeof( mScreenWidthHeightChoices ) / sizeof( wxString );
	mScreenWidthHeight = new wxChoice( ID_PANEL3, wxID_ANY, wxDefaultPosition, wxDefaultSize, mScreenWidthHeightNChoices, mScreenWidthHeightChoices, 0 );
	mScreenWidthHeight->SetSelection( 0 );
	fgSizer2->Add( mScreenWidthHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	ID_BUTTON1 = new wxButton( ID_PANEL3, wxID_ANY, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON1->SetDefault(); 
	fgSizer2->Add( ID_BUTTON1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText29 = new wxStaticText( ID_PANEL3, wxID_ANY, _("Screen Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer2->Add( m_staticText29, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mScreenWidth = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	mScreenWidth->Enable( false );
	
	fgSizer2->Add( mScreenWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText30 = new wxStaticText( ID_PANEL3, wxID_ANY, _("Screen Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer2->Add( m_staticText30, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mScreenHeight = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	mScreenHeight->Enable( false );
	
	fgSizer2->Add( mScreenHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText31 = new wxStaticText( ID_PANEL3, wxID_ANY, _("ScreenPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer2->Add( m_staticText31, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mScreenPicturePath = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer2->Add( mScreenPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON = new wxButton( ID_PANEL3, wxID_ANY, _("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON->SetDefault(); 
	fgSizer2->Add( ID_BUTTON, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText32 = new wxStaticText( ID_PANEL3, wxID_ANY, _("ScreenPictureName"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer2->Add( m_staticText32, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mScreenPictureName = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	mScreenPictureName->Enable( false );
	
	fgSizer2->Add( mScreenPictureName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON2 = new wxButton( ID_PANEL3, wxID_ANY, _("Install NGPOD to Startup"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON2->SetDefault(); 
	ID_BUTTON2->Enable( false );
	
	fgSizer2->Add( ID_BUTTON2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL3->SetSizer( fgSizer2 );
	ID_PANEL3->Layout();
	fgSizer2->Fit( ID_PANEL3 );
	m_notebook2->AddPage( ID_PANEL3, _("Environment Setting"), false );
	ID_PANEL5 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText33 = new wxStaticText( ID_PANEL5, wxID_ANY, _("LocalPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer3->Add( m_staticText33, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mLocalPicturePath = new wxTextCtrl( ID_PANEL5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer3->Add( mLocalPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON4 = new wxButton( ID_PANEL5, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON4->SetDefault(); 
	fgSizer3->Add( ID_BUTTON4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL5->SetSizer( fgSizer3 );
	ID_PANEL5->Layout();
	fgSizer3->Fit( ID_PANEL5 );
	m_notebook2->AddPage( ID_PANEL5, _("Local Picture Source"), false );
	ID_PANEL6 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText35 = new wxStaticText( ID_PANEL6, wxID_ANY, _("PodBasePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer4->Add( m_staticText35, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mPodBasePath = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer4->Add( mPodBasePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON5 = new wxButton( ID_PANEL6, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON5->SetDefault(); 
	fgSizer4->Add( ID_BUTTON5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText34 = new wxStaticText( ID_PANEL6, wxID_ANY, _("PodDatabaseName"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	fgSizer4->Add( m_staticText34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mPodDatabaseName = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	mPodDatabaseName->Enable( false );
	
	fgSizer4->Add( mPodDatabaseName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText36 = new wxStaticText( ID_PANEL6, wxID_ANY, _("PodPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	fgSizer4->Add( m_staticText36, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mPodPicturePath = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	mPodPicturePath->Enable( false );
	
	fgSizer4->Add( mPodPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText37 = new wxStaticText( ID_PANEL6, wxID_ANY, _("Now POD Day"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	fgSizer4->Add( m_staticText37, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mNextPODDay = new wxDatePickerCtrl( ID_PANEL6, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN|wxDP_DEFAULT );
	fgSizer4->Add( mNextPODDay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL6->SetSizer( fgSizer4 );
	ID_PANEL6->Layout();
	fgSizer4->Fit( ID_PANEL6 );
	m_notebook2->AddPage( ID_PANEL6, _("NGPOD Source"), false );
	
	bSizer5->Add( m_notebook2, 0, wxEXPAND|wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 0 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	ID_BUTTON6 = new wxButton( m_panel8, wxID_ANY, _("Reload Config"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON6->SetDefault(); 
	bSizer8->Add( ID_BUTTON6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON7 = new wxButton( m_panel8, wxID_ANY, _("Restore Default"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON7->SetDefault(); 
	bSizer8->Add( ID_BUTTON7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mButtonSaveConfig = new wxButton( m_panel8, wxID_ANY, _("Save Config"), wxDefaultPosition, wxDefaultSize, 0 );
	mButtonSaveConfig->SetDefault(); 
	mButtonSaveConfig->Enable( false );
	
	bSizer8->Add( mButtonSaveConfig, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gSizer1->Add( bSizer8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	ID_BUTTON10 = new wxButton( m_panel8, wxID_ANY, _("About"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON10->SetDefault(); 
	bSizer9->Add( ID_BUTTON10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON11 = new wxButton( m_panel8, wxID_ANY, _("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON11->SetDefault(); 
	bSizer9->Add( ID_BUTTON11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gSizer1->Add( bSizer9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer5->Add( gSizer1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxSHAPED, 5 );
	
	m_panel8->SetSizer( bSizer5 );
	m_panel8->Layout();
	bSizer5->Fit( m_panel8 );
	bSizer4->Add( m_panel8, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	// Connect Events
	mPictureSource->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChoicePictureSource ), NULL, this );
	mPauseChangeWallpaper->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxPauseChangeWallpaperClick ), NULL, this );
	mShowSplash->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxShowSplashClick ), NULL, this );
	mUILanguage->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChioceUILanguage ), NULL, this );
	mChangeUILanguage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonClickChangeUILanguage ), NULL, this );
	mShowDisc->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxShowDiscClick ), NULL, this );
	mScreenWidthHeight->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChoiceScreenWHSelected ), NULL, this );
	ID_BUTTON1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAutoDetectScreenWHClick ), NULL, this );
	mScreenPicturePath->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextScreenPicturePathEnter ), NULL, this );
	ID_BUTTON->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAutoDetectSystemPathClick ), NULL, this );
	mLocalPicturePath->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextLocalPicturePathEnter ), NULL, this );
	ID_BUTTON4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonLocalPicturePathClick ), NULL, this );
	mPodBasePath->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextPodBasePathEnter ), NULL, this );
	ID_BUTTON5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonPodBasePathClick ), NULL, this );
	mNextPODDay->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( GUI_dialogConfigPanel::OnDateNowPODDayChanged ), NULL, this );
	ID_BUTTON6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonReloadConfigClick ), NULL, this );
	ID_BUTTON7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonRestoreDefaultClick ), NULL, this );
	mButtonSaveConfig->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonSaveConfigClick ), NULL, this );
	ID_BUTTON10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAboutClick ), NULL, this );
	ID_BUTTON11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonQuitClick ), NULL, this );
}

GUI_dialogConfigPanel::~GUI_dialogConfigPanel()
{
	// Disconnect Events
	mPictureSource->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChoicePictureSource ), NULL, this );
	mPauseChangeWallpaper->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxPauseChangeWallpaperClick ), NULL, this );
	mShowSplash->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxShowSplashClick ), NULL, this );
	mUILanguage->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChioceUILanguage ), NULL, this );
	mChangeUILanguage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonClickChangeUILanguage ), NULL, this );
	mShowDisc->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnCheckBoxShowDiscClick ), NULL, this );
	mScreenWidthHeight->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUI_dialogConfigPanel::OnChoiceScreenWHSelected ), NULL, this );
	ID_BUTTON1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAutoDetectScreenWHClick ), NULL, this );
	mScreenPicturePath->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextScreenPicturePathEnter ), NULL, this );
	ID_BUTTON->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAutoDetectSystemPathClick ), NULL, this );
	mLocalPicturePath->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextLocalPicturePathEnter ), NULL, this );
	ID_BUTTON4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonLocalPicturePathClick ), NULL, this );
	mPodBasePath->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI_dialogConfigPanel::OnTextPodBasePathEnter ), NULL, this );
	ID_BUTTON5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonPodBasePathClick ), NULL, this );
	mNextPODDay->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( GUI_dialogConfigPanel::OnDateNowPODDayChanged ), NULL, this );
	ID_BUTTON6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonReloadConfigClick ), NULL, this );
	ID_BUTTON7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonRestoreDefaultClick ), NULL, this );
	mButtonSaveConfig->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonSaveConfigClick ), NULL, this );
	ID_BUTTON10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonAboutClick ), NULL, this );
	ID_BUTTON11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogConfigPanel::OnButtonQuitClick ), NULL, this );
}

GUI_dialogAbout::GUI_dialogAbout( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	ID_PANEL4 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
	ID_PANEL4->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	wxID_STATIC = new wxStaticBitmap( ID_PANEL4, wxID_ANY, wxBitmap( logo60x80_xpm ), wxDefaultPosition, wxSize( 60,80 ), 0 );
	bSizer12->Add( wxID_STATIC, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText38 = new wxStaticText( ID_PANEL4, wxID_ANY, _("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	m_staticText38->SetFont( wxFont( 11, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer12->Add( m_staticText38, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	bSizer11->Add( bSizer12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText39 = new wxStaticText( ID_PANEL4, wxID_ANY, _("wxT(\"Version: \") + g_AppVersion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	m_staticText39->SetForegroundColour( wxColour( 128, 128, 128 ) );
	
	bSizer11->Add( m_staticText39, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( ID_PANEL4, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxLI_VERTICAL );
	bSizer11->Add( m_staticline2, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText40 = new wxStaticText( ID_PANEL4, wxID_ANY, _("wxT(\"Bulid: \") + g_AppBuildTimestamp"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	m_staticText40->SetForegroundColour( wxColour( 128, 128, 128 ) );
	
	bSizer11->Add( m_staticText40, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText41 = new wxStaticText( ID_PANEL4, wxID_ANY, _("Developer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer11->Add( m_staticText41, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText42 = new wxStaticText( ID_PANEL4, wxID_ANY, _("g_AppProjectLeader + wxT(\"(\") + g_AppProjectLeaderEmail + wxT(\")\")"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer11->Add( m_staticText42, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText43 = new wxStaticText( ID_PANEL4, wxID_ANY, _("Homepage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer11->Add( m_staticText43, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText44 = new wxStaticText( ID_PANEL4, wxID_ANY, _("g_AppUrl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	bSizer11->Add( m_staticText44, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText45 = new wxStaticText( ID_PANEL4, wxID_ANY, _("g_AppUrl2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	bSizer11->Add( m_staticText45, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText46 = new wxStaticText( ID_PANEL4, wxID_ANY, _("g_AppUrl3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer11->Add( m_staticText46, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_PANEL4->SetSizer( bSizer11 );
	ID_PANEL4->Layout();
	bSizer11->Fit( ID_PANEL4 );
	bSizer10->Add( ID_PANEL4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_BUTTON8 = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON8->SetDefault(); 
	bSizer10->Add( ID_BUTTON8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	ID_BUTTON8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogAbout::OnButtonOKClick ), NULL, this );
}

GUI_dialogAbout::~GUI_dialogAbout()
{
	// Disconnect Events
	ID_BUTTON8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUI_dialogAbout::OnButtonOKClick ), NULL, this );
}
