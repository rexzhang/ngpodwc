#ifndef COMMON_WALLPAPER_BASE_H
#define COMMON_WALLPAPER_BASE_H

#include "ngpodwc_common_config.h"

class WallpaperBase
{
    public:
        WallpaperBase(ngpodwcConfig programConfig);
        virtual bool Init();
        virtual ~WallpaperBase();

        //!成员函数
        //图片设置，获取，保存，操作相关
        bool SetImage(wxImage inImage);//!-->SetWallpaperImage()
        wxImage GetImage();//!-->GetWallpaperImage()
        virtual bool SaveWallpaper();//!-->SaveWallpaper()

        bool ImageOk();
        bool ImageReSize();
        //文字标注相关
        virtual wxString GetText();
        bool DrawText();//不重载，靠调用被重载了的GetText()实现对不同源的操作

        //!成员变量
    protected:
        wxImage Image;
        ngpodwcConfig config;
    private:
};

#endif // COMMON_WALLPAPER_BASE_H
