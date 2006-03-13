#ifndef COMMON_WALLPAPER_LOCALPICTURE_H
#define COMMON_WALLPAPER_LOCALPICTURE_H

#include <common_wallpaper_base.h>

class WallpaperLocalPicture : public WallpaperBase
{
    public:
        WallpaperLocalPicture(ngpodwcConfig programConfig);
        virtual ~WallpaperLocalPicture();

        //³ÉÔ±º¯Êý
        bool Init();
        bool DrawText();

    protected:
    private:
};

#endif // COMMON_WALLPAPER_LOCALPICTURE_H
