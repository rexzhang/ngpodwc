///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIdialog_minipanel
///////////////////////////////////////////////////////////////////////////////
class GUIdialog_minipanel : public wxDialog 
{
	private:
	
	protected:
		
		wxStaticBitmap* m_bitmap4;
		wxStaticText* m_staticText24;
		wxBitmapButton* ID_BITMAPBUTTON;
		
		wxBitmapButton* ID_BITMAPBUTTON_PRE;
		wxBitmapButton* ID_BITMAPBUTTON_NEXT;
		
		wxBitmapButton* ID_BITMAPBUTTON_CC;
		
		wxBitmapButton* ID_BITMAPBUTTON_ABOUT;
		
		wxBitmapButton* ID_BITMAPBUTTON_QUIT;
		
	
	public:
		GUIdialog_minipanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("National Geographic Photo Of the Day Wallpaper Changer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 581,268 ), long style = wxDEFAULT_DIALOG_STYLE );
		~GUIdialog_minipanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUIdialog_configpanel
///////////////////////////////////////////////////////////////////////////////
class GUIdialog_configpanel : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel8;
		wxStaticBitmap* m_bitmap5;
		wxStaticText* m_staticText25;
		wxNotebook* m_notebook2;
		wxPanel* ID_PANEL1;
		
		
		wxStaticText* m_staticText26;
		wxChoice* PictureSource;
		
		wxCheckBox* PauseChangeWallpaper;
		
		wxCheckBox* ShowSplash;
		wxStaticText* m_staticText27;
		wxChoice* UILanguage;
		
		wxButton* ID_BUTTON3;
		wxPanel* ID_PANEL2;
		
		wxCheckBox* ShowDisc;
		wxPanel* ID_PANEL3;
		
		
		
		wxStaticText* m_staticText28;
		wxChoice* ScreenWidthHeight;
		wxButton* ID_BUTTON1;
		wxStaticText* m_staticText29;
		wxTextCtrl* ScreenWidth;
		
		wxStaticText* m_staticText30;
		wxTextCtrl* ScreenHeight;
		
		wxStaticText* m_staticText31;
		wxTextCtrl* ScreenPicturePath;
		wxButton* ID_BUTTON;
		wxStaticText* m_staticText32;
		wxTextCtrl* ScreenPictureName;
		
		
		wxButton* ID_BUTTON2;
		
		
		
		wxPanel* ID_PANEL5;
		
		
		
		wxStaticText* m_staticText33;
		wxTextCtrl* LocalPicturePath;
		wxButton* ID_BUTTON4;
		wxPanel* ID_PANEL6;
		
		
		
		wxStaticText* m_staticText35;
		wxTextCtrl* PodBasePath;
		wxButton* ID_BUTTON5;
		wxStaticText* m_staticText34;
		wxTextCtrl* PodDatabaseName;
		
		wxStaticText* m_staticText36;
		wxTextCtrl* PodPicturePath;
		
		wxStaticText* m_staticText37;
		wxDatePickerCtrl* NextPODDay;
		
		
		
		
		wxButton* ID_BUTTON6;
		wxButton* ID_BUTTON7;
		wxButton* ID_BUTTON9;
		wxButton* ID_BUTTON10;
		wxButton* ID_BUTTON11;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonAboutClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonQuitClick( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUIdialog_configpanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("National Geographic Photo Of the Day Wallpaper Control Center"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,493 ), long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX );
		~GUIdialog_configpanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUIdialog_about
///////////////////////////////////////////////////////////////////////////////
class GUIdialog_about : public wxDialog 
{
	private:
	
	protected:
		wxPanel* ID_PANEL4;
		
		wxStaticBitmap* wxID_STATIC;
		wxStaticText* m_staticText38;
		wxStaticText* m_staticText39;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText40;
		
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText42;
		
		wxStaticText* m_staticText43;
		wxStaticText* m_staticText44;
		wxStaticText* m_staticText45;
		wxStaticText* m_staticText46;
		
		wxButton* ID_BUTTON8;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonOKClick( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUIdialog_about( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 484,491 ), long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX );
		~GUIdialog_about();
	
};

#endif //__GUIFrame__
