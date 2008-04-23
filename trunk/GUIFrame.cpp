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

GUIdialog_minipanel::GUIdialog_minipanel( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( logo60x80_xpm ), wxDefaultPosition, wxSize( 60,80 ), 0 );
	bSizer5->Add( m_bitmap4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	m_staticText24->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer5->Add( m_staticText24, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5 );
	
	bSizer4->Add( bSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	ID_BITMAPBUTTON = new wxBitmapButton( this, wxID_ANY, wxBitmap( unlock_picture_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	
	ID_BITMAPBUTTON->SetBitmapSelected( wxBitmap( lock_picture_xpm ) );
	ID_BITMAPBUTTON->SetDefault(); 
	ID_BITMAPBUTTON->SetToolTip( wxT("Pause/Unpause change wallpaper") );
	
	ID_BITMAPBUTTON->SetToolTip( wxT("Pause/Unpause change wallpaper") );
	
	bSizer6->Add( ID_BITMAPBUTTON, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BITMAPBUTTON_PRE = new wxBitmapButton( this, wxID_ANY, wxBitmap( previous_pictrue_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	ID_BITMAPBUTTON_PRE->SetDefault(); 
	ID_BITMAPBUTTON_PRE->SetToolTip( wxT("Show previous pictrue") );
	
	ID_BITMAPBUTTON_PRE->SetToolTip( wxT("Show previous pictrue") );
	
	bSizer6->Add( ID_BITMAPBUTTON_PRE, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BITMAPBUTTON_NEXT = new wxBitmapButton( this, wxID_ANY, wxBitmap( next_pictrue_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	ID_BITMAPBUTTON_NEXT->SetDefault(); 
	ID_BITMAPBUTTON_NEXT->SetToolTip( wxT("Show next pictrue") );
	
	ID_BITMAPBUTTON_NEXT->SetToolTip( wxT("Show next pictrue") );
	
	bSizer6->Add( ID_BITMAPBUTTON_NEXT, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BITMAPBUTTON_CC = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_settings_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	ID_BITMAPBUTTON_CC->SetDefault(); 
	ID_BITMAPBUTTON_CC->SetToolTip( wxT("Control Center") );
	
	ID_BITMAPBUTTON_CC->SetToolTip( wxT("Control Center") );
	
	bSizer6->Add( ID_BITMAPBUTTON_CC, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BITMAPBUTTON_ABOUT = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_info_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	ID_BITMAPBUTTON_ABOUT->SetDefault(); 
	ID_BITMAPBUTTON_ABOUT->SetToolTip( wxT("About") );
	
	ID_BITMAPBUTTON_ABOUT->SetToolTip( wxT("About") );
	
	bSizer6->Add( ID_BITMAPBUTTON_ABOUT, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer6->Add( 5, 5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BITMAPBUTTON_QUIT = new wxBitmapButton( this, wxID_ANY, wxBitmap( icon_quit_xpm ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	ID_BITMAPBUTTON_QUIT->SetDefault(); 
	ID_BITMAPBUTTON_QUIT->SetToolTip( wxT("Quit") );
	
	ID_BITMAPBUTTON_QUIT->SetToolTip( wxT("Quit") );
	
	bSizer6->Add( ID_BITMAPBUTTON_QUIT, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer4->Add( bSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

GUIdialog_minipanel::~GUIdialog_minipanel()
{
}

GUIdialog_configpanel::GUIdialog_configpanel( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
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
	
	m_staticText25 = new wxStaticText( m_panel8, wxID_ANY, wxT("National Geographic Photo Of the Day\nWallpaper Control Center"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	m_staticText26 = new wxStaticText( ID_PANEL1, wxID_ANY, wxT("Input Source"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	fgSizer1->Add( m_staticText26, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString PictureSourceChoices[] = { wxT("Local Picture"), wxT("NGPOD"), wxT("NGPOD Online") };
	int PictureSourceNChoices = sizeof( PictureSourceChoices ) / sizeof( wxString );
	PictureSource = new wxChoice( ID_PANEL1, wxID_ANY, wxDefaultPosition, wxDefaultSize, PictureSourceNChoices, PictureSourceChoices, 0 );
	PictureSource->SetSelection( 0 );
	fgSizer1->Add( PictureSource, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	PauseChangeWallpaper = new wxCheckBox( ID_PANEL1, wxID_ANY, wxT("Pause Change Wallpaper"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	fgSizer1->Add( PauseChangeWallpaper, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ShowSplash = new wxCheckBox( ID_PANEL1, wxID_ANY, wxT("Show Splash"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	fgSizer1->Add( ShowSplash, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText27 = new wxStaticText( ID_PANEL1, wxID_ANY, wxT("UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer1->Add( m_staticText27, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString UILanguageChoices;
	UILanguage = new wxChoice( ID_PANEL1, wxID_ANY, wxDefaultPosition, wxDefaultSize, UILanguageChoices, 0 );
	UILanguage->SetSelection( 0 );
	fgSizer1->Add( UILanguage, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	
	fgSizer1->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON3 = new wxButton( ID_PANEL1, wxID_ANY, wxT("Change UI Language"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON3->SetDefault(); 
	fgSizer1->Add( ID_BUTTON3, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL1->SetSizer( fgSizer1 );
	ID_PANEL1->Layout();
	fgSizer1->Fit( ID_PANEL1 );
	m_notebook2->AddPage( ID_PANEL1, wxT("Common Setting"), false );
	ID_PANEL2 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer7->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ShowDisc = new wxCheckBox( ID_PANEL2, wxID_ANY, wxT("Show Disc"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	
	bSizer7->Add( ShowDisc, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_PANEL2->SetSizer( bSizer7 );
	ID_PANEL2->Layout();
	bSizer7->Fit( ID_PANEL2 );
	m_notebook2->AddPage( ID_PANEL2, wxT("Image Convert Setting"), false );
	ID_PANEL3 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText28 = new wxStaticText( ID_PANEL3, wxID_ANY, wxT("Screen Width x Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer2->Add( m_staticText28, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString ScreenWidthHeightChoices[] = {  };
	int ScreenWidthHeightNChoices = sizeof( ScreenWidthHeightChoices ) / sizeof( wxString );
	ScreenWidthHeight = new wxChoice( ID_PANEL3, wxID_ANY, wxDefaultPosition, wxDefaultSize, ScreenWidthHeightNChoices, ScreenWidthHeightChoices, 0 );
	ScreenWidthHeight->SetSelection( 0 );
	fgSizer2->Add( ScreenWidthHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL|wxSHAPED, 5 );
	
	ID_BUTTON1 = new wxButton( ID_PANEL3, wxID_ANY, wxT("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON1->SetDefault(); 
	fgSizer2->Add( ID_BUTTON1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText29 = new wxStaticText( ID_PANEL3, wxID_ANY, wxT("Screen Width"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer2->Add( m_staticText29, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ScreenWidth = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ScreenWidth->Enable( false );
	
	fgSizer2->Add( ScreenWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText30 = new wxStaticText( ID_PANEL3, wxID_ANY, wxT("Screen Height"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	fgSizer2->Add( m_staticText30, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ScreenHeight = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ScreenHeight->Enable( false );
	
	fgSizer2->Add( ScreenHeight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText31 = new wxStaticText( ID_PANEL3, wxID_ANY, wxT("ScreenPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer2->Add( m_staticText31, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ScreenPicturePath = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer2->Add( ScreenPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON = new wxButton( ID_PANEL3, wxID_ANY, wxT("Auto Detect"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON->SetDefault(); 
	fgSizer2->Add( ID_BUTTON, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText32 = new wxStaticText( ID_PANEL3, wxID_ANY, wxT("ScreenPictureName"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	fgSizer2->Add( m_staticText32, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ScreenPictureName = new wxTextCtrl( ID_PANEL3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	ScreenPictureName->Enable( false );
	
	fgSizer2->Add( ScreenPictureName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON2 = new wxButton( ID_PANEL3, wxID_ANY, wxT("Install NGPOD to Startup"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON2->SetDefault(); 
	ID_BUTTON2->Enable( false );
	
	fgSizer2->Add( ID_BUTTON2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer2->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL3->SetSizer( fgSizer2 );
	ID_PANEL3->Layout();
	fgSizer2->Fit( ID_PANEL3 );
	m_notebook2->AddPage( ID_PANEL3, wxT("Environment Setting"), false );
	ID_PANEL5 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer3->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText33 = new wxStaticText( ID_PANEL5, wxID_ANY, wxT("LocalPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer3->Add( m_staticText33, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	LocalPicturePath = new wxTextCtrl( ID_PANEL5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer3->Add( LocalPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON4 = new wxButton( ID_PANEL5, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON4->SetDefault(); 
	fgSizer3->Add( ID_BUTTON4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL5->SetSizer( fgSizer3 );
	ID_PANEL5->Layout();
	fgSizer3->Fit( ID_PANEL5 );
	m_notebook2->AddPage( ID_PANEL5, wxT("Local Picture Source"), false );
	ID_PANEL6 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText35 = new wxStaticText( ID_PANEL6, wxID_ANY, wxT("PodBasePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer4->Add( m_staticText35, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	PodBasePath = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer4->Add( PodBasePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON5 = new wxButton( ID_PANEL6, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON5->SetDefault(); 
	fgSizer4->Add( ID_BUTTON5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText34 = new wxStaticText( ID_PANEL6, wxID_ANY, wxT("PodDatabaseName"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	fgSizer4->Add( m_staticText34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	PodDatabaseName = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	PodDatabaseName->Enable( false );
	
	fgSizer4->Add( PodDatabaseName, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText36 = new wxStaticText( ID_PANEL6, wxID_ANY, wxT("PodPicturePath"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	fgSizer4->Add( m_staticText36, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	PodPicturePath = new wxTextCtrl( ID_PANEL6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	PodPicturePath->Enable( false );
	
	fgSizer4->Add( PodPicturePath, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText37 = new wxStaticText( ID_PANEL6, wxID_ANY, wxT("Now POD Day"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	fgSizer4->Add( m_staticText37, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	NextPODDay = new wxDatePickerCtrl( ID_PANEL6, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN|wxDP_DEFAULT );
	fgSizer4->Add( NextPODDay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer4->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_PANEL6->SetSizer( fgSizer4 );
	ID_PANEL6->Layout();
	fgSizer4->Fit( ID_PANEL6 );
	m_notebook2->AddPage( ID_PANEL6, wxT("NGPOD Source"), true );
	
	bSizer5->Add( m_notebook2, 0, wxEXPAND|wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 2, 0, 0 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	ID_BUTTON6 = new wxButton( m_panel8, wxID_ANY, wxT("Reload Config"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON6->SetDefault(); 
	bSizer8->Add( ID_BUTTON6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON7 = new wxButton( m_panel8, wxID_ANY, wxT("Restore Default"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON7->SetDefault(); 
	bSizer8->Add( ID_BUTTON7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON9 = new wxButton( m_panel8, wxID_ANY, wxT("Save Config"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON9->SetDefault(); 
	ID_BUTTON9->Enable( false );
	
	bSizer8->Add( ID_BUTTON9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	gSizer1->Add( bSizer8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	ID_BUTTON10 = new wxButton( m_panel8, wxID_ANY, wxT("About"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON10->SetDefault(); 
	bSizer9->Add( ID_BUTTON10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ID_BUTTON11 = new wxButton( m_panel8, wxID_ANY, wxT("Quit"), wxDefaultPosition, wxDefaultSize, 0 );
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
	ID_BUTTON10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_configpanel::OnButtonAboutClick ), NULL, this );
	ID_BUTTON11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_configpanel::OnButtonQuitClick ), NULL, this );
}

GUIdialog_configpanel::~GUIdialog_configpanel()
{
	// Disconnect Events
	ID_BUTTON10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_configpanel::OnButtonAboutClick ), NULL, this );
	ID_BUTTON11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_configpanel::OnButtonQuitClick ), NULL, this );
}

GUIdialog_about::GUIdialog_about( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
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
	
	m_staticText38 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("National Geographic Photo Of the Day\nWallpaper Changer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	m_staticText38->SetFont( wxFont( 11, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer12->Add( m_staticText38, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	bSizer11->Add( bSizer12, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText39 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("wxT(\"Version: \") + g_AppVersion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	m_staticText39->SetForegroundColour( wxColour( 128, 128, 128 ) );
	
	bSizer11->Add( m_staticText39, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( ID_PANEL4, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxLI_VERTICAL );
	bSizer11->Add( m_staticline2, 0, wxEXPAND|wxALL, 5 );
	
	m_staticText40 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("wxT(\"Bulid: \") + g_AppBuildTimestamp"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	m_staticText40->SetForegroundColour( wxColour( 128, 128, 128 ) );
	
	bSizer11->Add( m_staticText40, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText41 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("Developer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	m_staticText41->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer11->Add( m_staticText41, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText42 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("g_AppProjectLeader + wxT(\"(\") + g_AppProjectLeaderEmail + wxT(\")\")"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer11->Add( m_staticText42, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText43 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("Homepage"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	m_staticText43->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer11->Add( m_staticText43, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText44 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("g_AppUrl"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	bSizer11->Add( m_staticText44, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText45 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("g_AppUrl2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	bSizer11->Add( m_staticText45, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText46 = new wxStaticText( ID_PANEL4, wxID_ANY, wxT("g_AppUrl3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer11->Add( m_staticText46, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer11->Add( 5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_PANEL4->SetSizer( bSizer11 );
	ID_PANEL4->Layout();
	bSizer11->Fit( ID_PANEL4 );
	bSizer10->Add( ID_PANEL4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	ID_BUTTON8 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	ID_BUTTON8->SetDefault(); 
	bSizer10->Add( ID_BUTTON8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	this->SetSizer( bSizer10 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	ID_BUTTON8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_about::OnButtonOKClick ), NULL, this );
}

GUIdialog_about::~GUIdialog_about()
{
	// Disconnect Events
	ID_BUTTON8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIdialog_about::OnButtonOKClick ), NULL, this );
}
