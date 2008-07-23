/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_operation.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-02-28
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_WALLPAPER_OPERATION_H
#define COMMON_WALLPAPER_OPERATION_H

#include "common_config.h"
//#include "ngpodwc_common_ngpodinfo.h"
//#include "ngpodwc_common_screen.h"

//#include "common_ngpod.h"

//bool getPodInfo(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo);
//bool updateWallpaper(ngpodwcConfig *pConfig);//, ngpodinfo *pPodPictureInfo);
//bool updateWallpaper(ngpodwcConfig config);
bool updateWallpaper(void);
//void pictureOpretionDrawText(wxImage *pScreenImage, ngpodinfo *pPodPictureInfo);

bool setWallpaperRegInfo(wxString WallpaperPathAndName);

#endif // COMMON_WALLPAPER_OPERATION_H
