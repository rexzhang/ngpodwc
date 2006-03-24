#include "common_wallpaper_localpicture.h"

#include <wx/dir.h>

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
    wxString pictureFileName;

    wxDir pictureDir(config.LocalPicturePath);
    wxArrayString PictureArray;

    srand((int)time(0));
    pictureDir.GetAllFiles(config.LocalPicturePath, &PictureArray,
                           wxT("*.jpg"), wxDIR_DEFAULT);

    pictureFileName = PictureArray[(int)(PictureArray.GetCount()*rand()/(RAND_MAX +1))];

    //获取原始图片
    if (!Image.LoadFile(pictureFileName,
                        wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Local Picture Loading ERROR!"), pictureFileName);
        return false;
    }

    return true;
}

bool WallpaperLocalPicture::DrawText()
{
    return true;
}
