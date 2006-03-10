#ifndef COMMON_WALLPAPER_BASE_H
#define COMMON_WALLPAPER_BASE_H

#include "ngpodwc_common_config.h"

class WallpaperBase
{
    public:
        WallpaperBase(ngpodwcConfig programConfig);
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
        ngpodwcConfig config;
    private:
};

#endif // COMMON_WALLPAPER_BASE_H
