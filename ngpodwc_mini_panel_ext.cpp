/////////////////////////////////////////////////////////////////////////////
// Name:        %SOURCE-FILENAME%
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     %DATE%
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include "ngpodwc_mini_panel.h"


#include "art/unlock_picture.xpm"
#include "art/lock_picture.xpm"

void ngpodwc_mini_panel::InitConfig()
{
    config.ReadConfig();

    ShowConfig();

    return;
}

void ngpodwc_mini_panel::ShowConfig()
{
    if(config.PauseChangeWallpaper)
    {
        //pause
        wxBitmap bitmap( lock_picture_xpm);
        PauseChangeWallpaper->SetBitmapLabel(bitmap);
    }
    else
    {
        //unpause
        wxBitmap bitmap( unlock_picture_xpm);
        PauseChangeWallpaper->SetBitmapLabel(bitmap);
    }
    return;
}

void ngpodwc_mini_panel::SwapPauseChangeWallpaperStat()
{
    config.PauseChangeWallpaper = !config.PauseChangeWallpaper;
    config.WriteConfig();
    ShowConfig();

    return;
}

void ngpodwc_mini_panel::DisableUpdateButton()
{
    PauseChangeWallpaper->Disable();
    ShowPrePicture->Disable();
    ShowNextPicture->Disable();
}

void ngpodwc_mini_panel::EnableUpdateButton()
{
    PauseChangeWallpaper->Enable();
    ShowPrePicture->Enable();
    ShowNextPicture->Enable();
}
