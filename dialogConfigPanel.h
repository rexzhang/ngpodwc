#ifndef DIALOGCONFIGPANEL_H
#define DIALOGCONFIGPANEL_H

#include <GUIFrame.h>

#include "common_globals.h"
#include "common_config.h"

class dialogConfigPanel : public GUI_dialogConfigPanel
{
public:
    dialogConfigPanel(wxFrame *frame);
    virtual ~dialogConfigPanel();

    ngpodwcConfig config;

protected:

private:
    //事件响应
    void OnButtonAboutClick( wxCommandEvent& event );
    void OnButtonQuitClick( wxCommandEvent& event )
    {
        Destroy();
    }
    void OnButtonReloadConfigClick( wxCommandEvent& event )
    {
        ReadConfig();
        ShowConfig();
        event.Skip();
    }
    void OnButtonAutoDetectScreenWHClick( wxCommandEvent& event )
    {
        AutoDetectScreenWH();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnButtonAutoDetectSystemPathClick( wxCommandEvent& event )
    {
        AutoDetectSystemPath();
        event.Skip();
    }
    void OnButtonRestoreDefaultClick( wxCommandEvent& event )
    {
        configRunning.SetDefault();
        ShowConfig();
        event.Skip();
    }
    void OnButtonPodBasePathClick( wxCommandEvent& event )
    {
        const wxString& dir = wxDirSelector(wxT("Please choice NGPOD\'s path"), configRunning.PodBasePath, 0, wxDefaultPosition, this);
        if ( !dir.empty() )
        {
            configRunning.PodBasePath = dir;
            mPodBasePath->SetValue(configRunning.PodBasePath);
        }
        mPodBasePath->SetValue(configRunning.PodBasePath);
        event.Skip();
    }
    void OnButtonSaveConfigClick( wxCommandEvent& event )
    {
        WriteConfig();
        mButtonSaveConfig->Disable();
        event.Skip();
    }
    void OnChoiceScreenWHSelected( wxCommandEvent& event )
    {
        switch (mScreenWidthHeight->GetCurrentSelection())
        {
        case SCREENWH640x480:
            configRunning.ScreenWidth = 640;
            configRunning.ScreenHeight = 480;
            mScreenWidth->SetValue(wxT("640"));
            mScreenHeight->SetValue(wxT("480"));
            break;
        case SCREENWH800x600:
            configRunning.ScreenWidth = 800;
            configRunning.ScreenHeight = 600;
            mScreenWidth->SetValue(wxT("800"));
            mScreenHeight->SetValue(wxT("600"));
            break;
        case SCREENWH1024x768:
            configRunning.ScreenWidth = 1024;
            configRunning.ScreenHeight = 768;
            mScreenWidth->SetValue(wxT("1024"));
            mScreenHeight->SetValue(wxT("768"));
            break;
            //case 3:
        default:
            //SCREENWHAutoDetect
            AutoDetectScreenWH();
        }

        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnTextPodBasePathEnter( wxCommandEvent& event )
    {
        configRunning.PodBasePath = mPodBasePath->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnTextScreenPicturePathEnter( wxCommandEvent& event )
    {
        configRunning.ScreenPicturePath = mScreenPicturePath->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnDateNowPODDayChanged( wxDateEvent& event )
    {
        configRunning.PodDate = mNextPODDay->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnCheckBoxPauseChangeWallpaperClick( wxCommandEvent& event )
    {
        configRunning.PauseChangeWallpaper = mPauseChangeWallpaper->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnCheckBoxShowSplashClick( wxCommandEvent& event )
    {
        configRunning.ShowSplash = mShowSplash->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnCheckBoxShowDiscClick( wxCommandEvent& event )
    {
        configRunning.ShowDisc = mShowDisc->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnButtonLocalPicturePathClick( wxCommandEvent& event )
    {
        const wxString& dir = wxDirSelector(wxT("Please choice Local File\'s path"), config.LocalPicturePath, 0, wxDefaultPosition, this);
        if ( !dir.empty() )
        {
            configRunning.LocalPicturePath = dir;
            mPodBasePath->SetValue(configRunning.LocalPicturePath);
        }
        mLocalPicturePath->SetValue(configRunning.LocalPicturePath);
        event.Skip();
    }
    void OnTextLocalPicturePathEnter( wxCommandEvent& event )
    {
        configRunning.LocalPicturePath = mLocalPicturePath->GetValue();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnChoicePictureSource( wxCommandEvent& event )
    {
        configRunning.PictureSource = mPictureSource->GetCurrentSelection();
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnChioceUILanguage( wxCommandEvent& event )
    {
        configRunning.UILanguage = g_AppLanguageCodes[mUILanguage->GetCurrentSelection()];
        mButtonSaveConfig->Enable();
        event.Skip();
    }
    void OnButtonClickChangeUILanguage( wxCommandEvent& event )
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
            configRunning.UILanguage = g_AppLanguageCodes[choice];
            wxMessageBox(_("You must save config and restart NGPODWCC for this change to take effect."),
                         wxT("NGPODWCC"),
                         wxOK | wxCENTRE | wxICON_INFORMATION);
        }
        mButtonSaveConfig->Enable();
        event.Skip();
    }

    //内部通用函数
    void ReadConfig();
    void WriteConfig();
    void ShowConfig();
    void AutoDetectScreenWH(void);
    wxString AutoDetectSystemPath(void);

};

#endif // DIALOGCONFIGPANEL_H
