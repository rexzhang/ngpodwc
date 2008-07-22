#include "dialogMiniPanel.h"

#include "common_globals.h"
#include "common_config.h"

#include "dialogAbout.h"
#include "dialogConfigPanel.h"

#include "ngpodwc_common_datetime.h"
#include "common_wallpaper_operation.h"

#include "share/art/unlock_picture.xpm"
#include "share/art/lock_picture.xpm"

dialogMiniPanel::dialogMiniPanel(wxDialog *frame)
        :GUI_dialogMiniPanel(frame)
{
    //ctor
    configRunning.ReadConfig();

    ShowConfig();
}

dialogMiniPanel::~dialogMiniPanel()
{
    //dtor
}


/*
void dialogMiniPanel::InitConfig()
{
    //config.ReadConfig();
    configRunning.ReadConfig();

    ShowConfig();

    return;
}
*/
void dialogMiniPanel::ShowConfig()
{
    if (configRunning.PauseChangeWallpaper)
    {
        //pause
        wxBitmap bitmap( lock_picture_xpm);
        mPauseChangeWallpaper->SetBitmapLabel(bitmap);
    }
    else
    {
        //unpause
        wxBitmap bitmap( unlock_picture_xpm);
        mPauseChangeWallpaper->SetBitmapLabel(bitmap);
    }
    return;
}

void dialogMiniPanel::SwapPauseChangeWallpaperStat()
{
    configRunning.PauseChangeWallpaper = !configRunning.PauseChangeWallpaper;
    configRunning.WriteConfig();
    ShowConfig();

    return;
}

void dialogMiniPanel::DisableUpdateButton()
{
    mPauseChangeWallpaper->Disable();
    mShowPrePicture->Disable();
    mShowNextPicture->Disable();
    mControlCenter->Disable();
    mAbout->Disable();
    mQuit->Disable();
}

void dialogMiniPanel::EnableUpdateButton()
{
    mPauseChangeWallpaper->Enable();
    mShowPrePicture->Enable();
    mShowNextPicture->Enable();
    mControlCenter->Enable();
    mAbout->Enable();
    mQuit->Enable();
}

void dialogMiniPanel::OnButtonClickPauseChangeWallpaper( wxCommandEvent& event )
{
    SwapPauseChangeWallpaperStat();
    event.Skip();
}

void dialogMiniPanel::OnButtonClickShowPrePicture( wxCommandEvent& event )
{
    DisableUpdateButton();
    seekDays(-1, &(configRunning.PodDate));
    //updateWallpaper(&config);//, &pictureInfo);
    updateWallpaper(configRunning);
    EnableUpdateButton();
    wxBell();
    event.Skip();
}
void dialogMiniPanel::OnButtonClickShowNextPicture( wxCommandEvent& event )
{
    DisableUpdateButton();
    seekDays(1, &(configRunning.PodDate));
    updateWallpaper(configRunning);//, &pictureInfo);
    EnableUpdateButton();
    wxBell();
    event.Skip();
}
void dialogMiniPanel::OnButtonClickControlCenter( wxCommandEvent& event )
{
    dialogConfigPanel* window = new dialogConfigPanel(this);//, ID_DIALOG_CONFIG_PANEL);

    //(window->config).SetConfigFilePath(path);
    //configRunning.ReadConfig();?????????????????应该不需要了-----！！！

    window->Show(true);
    event.Skip();
}
void dialogMiniPanel::OnButtonClickAbout( wxCommandEvent& event )
{
    dialogAbout* window = new dialogAbout(this);//, ID_DIALOG_ABOUT, _("About"));
    window->Show(true);
    event.Skip();
}
void dialogMiniPanel::OnButtonClickQuit( wxCommandEvent& event )
{
    Destroy();
    event.Skip();
}
