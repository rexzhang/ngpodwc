///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/intl.h>

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
/// Class GUI_dialogMiniPanel
///////////////////////////////////////////////////////////////////////////////
class GUI_dialogMiniPanel : public wxDialog 
{
	private:
	
	protected:
		
		wxStaticBitmap* m_bitmap4;
		wxStaticText* m_staticText24;
		wxBitmapButton* mPauseChangeWallpaper;
		
		wxBitmapButton* mShowPrePicture;
		wxBitmapButton* mShowNextPicture;
		
		wxBitmapButton* mControlCenter;
		
		wxBitmapButton* mAbout;
		
		wxBitmapButton* mQuit;
		
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnButtonClickPauseChangeWallpaper( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickShowPrePicture( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickShowNextPicture( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickControlCenter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickQuit( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_dialogMiniPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("National Geographic Photo Of the Day Wallpaper Changer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 581,268 ), long style = wxDEFAULT_DIALOG_STYLE );
		~GUI_dialogMiniPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_dialogConfigPanel
///////////////////////////////////////////////////////////////////////////////
class GUI_dialogConfigPanel : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel8;
		wxStaticBitmap* m_bitmap5;
		wxStaticText* m_staticText25;
		wxNotebook* m_notebook2;
		wxPanel* ID_PANEL1;
		
		
		wxStaticText* m_staticText26;
		wxChoice* mPictureSource;
		
		wxCheckBox* mPauseChangeWallpaper;
		
		wxCheckBox* mShowSplash;
		wxStaticText* m_staticText27;
		wxChoice* mUILanguage;
		
		wxButton* mChangeUILanguage;
		wxPanel* ID_PANEL2;
		
		wxCheckBox* mShowDisc;
		wxPanel* ID_PANEL3;
		
		
		
		wxStaticText* m_staticText28;
		wxChoice* mScreenWidthHeight;
		wxButton* ID_BUTTON1;
		wxStaticText* m_staticText29;
		wxTextCtrl* mScreenWidth;
		
		wxStaticText* m_staticText30;
		wxTextCtrl* mScreenHeight;
		
		wxStaticText* m_staticText31;
		wxTextCtrl* mScreenPicturePath;
		wxButton* ID_BUTTON;
		wxStaticText* m_staticText32;
		wxTextCtrl* mScreenPictureName;
		
		
		wxButton* ID_BUTTON2;
		
		
		
		wxPanel* ID_PANEL5;
		
		
		
		wxStaticText* m_staticText33;
		wxTextCtrl* mLocalPicturePath;
		wxButton* ID_BUTTON4;
		wxPanel* ID_PANEL6;
		
		
		
		wxStaticText* m_staticText35;
		wxTextCtrl* mPodBasePath;
		wxButton* ID_BUTTON5;
		wxStaticText* m_staticText34;
		wxTextCtrl* mPodDatabaseName;
		
		wxStaticText* m_staticText36;
		wxTextCtrl* mPodPicturePath;
		
		wxStaticText* m_staticText37;
		wxDatePickerCtrl* mNextPODDay;
		
		
		
		
		wxButton* ID_BUTTON6;
		wxButton* ID_BUTTON7;
		wxButton* mButtonSaveConfig;
		wxButton* ID_BUTTON10;
		wxButton* ID_BUTTON11;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnChoicePictureSource( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckBoxPauseChangeWallpaperClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckBoxShowSplashClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChioceUILanguage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonClickChangeUILanguage( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckBoxShowDiscClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnChoiceScreenWHSelected( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonAutoDetectScreenWHClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTextScreenPicturePathEnter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonAutoDetectSystemPathClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTextLocalPicturePathEnter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonLocalPicturePathClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnTextPodBasePathEnter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonPodBasePathClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDateNowPODDayChanged( wxDateEvent& event ){ event.Skip(); }
		virtual void OnButtonReloadConfigClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonRestoreDefaultClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonSaveConfigClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonAboutClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnButtonQuitClick( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		GUI_dialogConfigPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("National Geographic Photo Of the Day Wallpaper Control Center"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 640,493 ), long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX );
		~GUI_dialogConfigPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GUI_dialogAbout
///////////////////////////////////////////////////////////////////////////////
class GUI_dialogAbout : public wxDialog 
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
		GUI_dialogAbout( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 484,491 ), long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX );
		~GUI_dialogAbout();
	
};

#endif //__GUIFrame__
