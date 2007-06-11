/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_localpicture.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-04
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_WALLPAPER_LOCALPICTURE_H
#define COMMON_WALLPAPER_LOCALPICTURE_H

#include <common_wallpaper_base.h>

class WallpaperLocalPicture : public WallpaperBase
{
    public:
        WallpaperLocalPicture(ngpodwcConfig programConfig);
        virtual ~WallpaperLocalPicture();

        //³ÉÔ±º¯Êý
        bool Init();
        bool DrawText();

    protected:
    private:
};

#endif // COMMON_WALLPAPER_LOCALPICTURE_H
