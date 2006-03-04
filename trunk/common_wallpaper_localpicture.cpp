#include "common_wallpaper_localpicture.h"

WallpaperLocalPicture::WallpaperLocalPicture(ngpodwcConfig programConfig):WallpaperBase(programConfig)
{
    Init();
    //ctor
}

WallpaperLocalPicture::~WallpaperLocalPicture()
{
    //dtor
}

bool WallpaperLocalPicture::Init()
{
    //config.LocalPicturePath
    return true;
}

bool WallpaperLocalPicture::DrawText()
{
    return true;
}

bool WallpaperLocalPicture::SaveWallpaper()
{
    return true;
}
