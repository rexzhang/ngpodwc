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

bool WallpaperBase::DrawText()
{
    return true;
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

bool WallpaperBase::SaveWallpaper()
{
    //��������ϵ�ͼƬ�����ָ��Ŀ¼
    if(!Image.SaveFile(config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName,
                               wxBITMAP_TYPE_BMP))
    {
        wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));

        wxString msgTitle("ͼƬCreate Error����",*wxConvCurrent);
        wxString msgContext("ͼƬCreate Error����\n��....XXXX.......������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return false;
    }
    return true;
}
