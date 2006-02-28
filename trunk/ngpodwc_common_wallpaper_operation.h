/////////////////////////////////////////////////////////////////////////////
// Name:        %HEADER-FILENAME%
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     %DATE%
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include "ngpodwc_common_config.h"
#include "ngpodwc_common_ngpodinfo.h"
#include "ngpodwc_common_screen.h"

//bool getPodInfo(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo);
bool updateWallpaper(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo);
bool outputScreenPicture(ngpodwcConfig *pConfig, wxImage *pScreenImage);
void pictureOpretionDrawText(wxImage *pScreenImage, ngpodinfo *pPodPictureInfo);

bool setWallpaperRegInfo(wxString WallpaperPathAndName);
