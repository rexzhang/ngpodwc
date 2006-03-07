#ifndef COMMON_WALLPAPER_NGPOD_ONLINE_H
#define COMMON_WALLPAPER_NGPOD_ONLINE_H

#include <common_wallpaper_base.h>

class WallpaperNGPODOnline : public WallpaperBase
{
    public:
        WallpaperNGPODOnline(ngpodwcConfig programConfig);
        virtual ~WallpaperNGPODOnline();

        //成员函数
        bool Init();
        //bool DrawText();
        //bool SaveWallpaper();

        //成员变量

    protected:
    private:
};

#endif // COMMON_WALLPAPER_NGPOD_ONLINE_H
