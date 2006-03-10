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
