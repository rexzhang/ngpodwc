/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_ngpod_online.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-06
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_WALLPAPER_NGPOD_ONLINE_H
#define COMMON_WALLPAPER_NGPOD_ONLINE_H

#include "common_wallpaper_base.h"
#include "common_ngpod_base.h"

class WallpaperNGPODOnline : public WallpaperBase, private NGPODBase
{
    public:
        //WallpaperNGPODOnline(ngpodwcConfig programConfig);
        WallpaperNGPODOnline(void);
        virtual ~WallpaperNGPODOnline();

        //成员函数
        bool Init();
        //bool DrawText();
        wxString GetText();
        bool SaveWallpaper();

        //成员变量

    protected:
    private:
        //成员函数
        bool GetPictureFromInternet();
        //成员变量
        //int Year, Month, Mday;//用于存储指定的日期
        //wxString PODPictureName;//用于存储获取的指定日期的图片文件名
};

#endif // COMMON_WALLPAPER_NGPOD_ONLINE_H
