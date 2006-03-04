#ifndef COMMON_WALLPAPER_BASE_H
#define COMMON_WALLPAPER_BASE_H

#include "ngpodwc_common_config.h"

class WallpaperBase
{
    public:
        WallpaperBase(ngpodwcConfig programConfig);
        bool Init();
        virtual ~WallpaperBase();

        //成员函数
        wxImage GetImage();
        bool SetImage(wxImage inImage);
        bool ImageOk();
        bool ImageReSize();

        bool SaveWallpaper();

        //成员变量
    protected:
        wxImage Image;
        ngpodwcConfig config;
    private:

};

#endif // COMMON_WALLPAPER_BASE_H
