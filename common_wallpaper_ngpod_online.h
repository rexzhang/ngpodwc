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

        //��Ա����
        bool Init();
        //bool DrawText();
        wxString GetText();
        bool SaveWallpaper();

        //��Ա����

    protected:
    private:
        //��Ա����
        bool GetPictureFromInternet();
        //��Ա����
        //int Year, Month, Mday;//���ڴ洢ָ��������
        //wxString PODPictureName;//���ڴ洢��ȡ��ָ�����ڵ�ͼƬ�ļ���
};

#endif // COMMON_WALLPAPER_NGPOD_ONLINE_H
