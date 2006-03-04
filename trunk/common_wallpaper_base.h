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

        //��Ա����
        wxImage Image;

    protected:
        ngpodwcConfig config;
    private:
};

#endif // COMMON_WALLPAPER_BASE_H
