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

        //成员函数
        //bool DrawText();
        bool SaveWallpaper();

        //成员变量

    protected:
    private:
        //成员函数
        wxString GetText();
        //成员变量
        ngpodinfo podPictureInfo;
};

#endif // COMMON_WALLPAPER_NGPOD_H
