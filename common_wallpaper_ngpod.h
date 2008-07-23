/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_ngpod.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-04
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_WALLPAPER_NGPOD_H
#define COMMON_WALLPAPER_NGPOD_H

#include "common_wallpaper_base.h"

#include "ngpodwc_common_ngpodinfo.h"

class WallpaperNGPOD : public WallpaperBase
{
    public:
        //WallpaperNGPOD(ngpodwcConfig programConfig);
        WallpaperNGPOD(void);
        virtual ~WallpaperNGPOD();
        bool Init();

        //��Ա����
        //bool DrawText();
        bool SaveWallpaper();

        //��Ա����

    protected:
    private:
        //��Ա����
        wxString GetText();
        //��Ա����
        ngpodinfo podPictureInfo;
};

#endif // COMMON_WALLPAPER_NGPOD_H
