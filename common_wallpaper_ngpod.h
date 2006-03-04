#ifndef COMMON_WALLPAPER_NGPOD_H
#define COMMON_WALLPAPER_NGPOD_H

#include <common_wallpaper_base.h>

#include "ngpodwc_common_ngpodinfo.h"

class WallpaperNGPOD : public WallpaperBase
{
    public:
        WallpaperNGPOD(ngpodwcConfig programConfig);
        //WallpaperNGPOD(ngpodwcConfig programConfig):WallpaperBase(ngpodwcConfig programConfig);
        virtual ~WallpaperNGPOD();

        //��Ա����
        bool Init();
        bool DrawText();
        bool SaveWallpaper();

        //��Ա����

    protected:
    private:
        ngpodinfo podPictureInfo;
};

#endif // COMMON_WALLPAPER_NGPOD_H
