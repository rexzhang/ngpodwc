#ifndef COMMON_WALLPAPER_NGPOD_ONLINE_H
#define COMMON_WALLPAPER_NGPOD_ONLINE_H

#include "common_wallpaper_base.h"
#include "common_ngpod_base.h"

class WallpaperNGPODOnline : public WallpaperBase, private NGPODBase
{
    public:
        WallpaperNGPODOnline(ngpodwcConfig programConfig);
        virtual ~WallpaperNGPODOnline();

        //��Ա����
        bool Init();
        //bool DrawText();
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
