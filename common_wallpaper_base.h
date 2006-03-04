#ifndef COMMON_WALLPAPER_BASE_H
#define COMMON_WALLPAPER_BASE_H

#include "ngpodwc_common_config.h"

class WallpaperBase
{
    public:
        WallpaperBase(ngpodwcConfig programConfig);
        bool Init();
        virtual ~WallpaperBase();

        //��Ա����
        wxImage GetImage();
        bool SetImage(wxImage inImage);
        bool ImageOk();
        bool ImageReSize();

        bool SaveWallpaper();

        //��Ա����
    protected:
        wxImage Image;
        ngpodwcConfig config;
    private:

};

#endif // COMMON_WALLPAPER_BASE_H
