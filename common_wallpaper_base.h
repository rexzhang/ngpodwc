/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_base.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-04
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_WALLPAPER_BASE_H
#define COMMON_WALLPAPER_BASE_H

#include <wx/string.h>
#include <wx/image.h>

#include "common_config.h"

class WallpaperBase
{
    public:
        //WallpaperBase(ngpodwcConfig programConfig);
        WallpaperBase(void);
        virtual bool Init();
        virtual ~WallpaperBase();

        //!��Ա����
        //ͼƬ���ã���ȡ�����棬�������
        bool SetImage(wxImage inImage);//!-->SetWallpaperImage()
        wxImage GetImage();//!-->GetWallpaperImage()
        virtual bool SaveWallpaper();//!-->SaveWallpaper()

        bool ImageOk();
        bool ImageReSize();
        //���ֱ�ע���
        virtual wxString GetText();
        bool DrawText();//�����أ������ñ������˵�GetText()ʵ�ֶԲ�ͬԴ�Ĳ���

        //!��Ա����
    protected:
        wxImage Image;
        //ngpodwcConfig config;
    private:
};

enum WallpaperStyle
{
    Tiled=1, Centered=2, Stretched=3
};

#endif // COMMON_WALLPAPER_BASE_H
