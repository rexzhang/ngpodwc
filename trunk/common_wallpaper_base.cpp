#include "common_wallpaper_base.h"

WallpaperBase::WallpaperBase(ngpodwcConfig programConfig)
{
    //ctor
    config = programConfig;
    Init();
}

WallpaperBase::~WallpaperBase()
{
    //dtor
}

bool WallpaperBase::Init()
{
    return true;
}

wxImage WallpaperBase::GetImage()
{
    return Image;
}

bool WallpaperBase::SetImage(wxImage inImage)
{
    Image = inImage;
    return true;
}

bool WallpaperBase::ImageOk()
{
    return Image.Ok();
}

bool WallpaperBase::ImageReSize()
{
    //����ͼƬ�ߴ�
    if( (Image.GetWidth() != config.ScreenWidth)
            || (Image.GetHeight() != config.ScreenHeight) )
    {
        //���ԭͼƬ�ߴ�����Ļ�ߴ粻������������С
        /*
        //Debug Info
        wxString msg;
        msg.Printf(wxT("From : %i x %i\nTo   : %i x %i"),
                   PodImage.GetWidth(), PodImage.GetHeight(), pConfig->ScreenWidth, pConfig->ScreenHeight);
        wxSafeShowMessage(wxT("change size"), msg);
        */
        Image = Image.Rescale(config.ScreenWidth, config.ScreenHeight);
    }
    else
    {
        //Image = Image;
    }
}
