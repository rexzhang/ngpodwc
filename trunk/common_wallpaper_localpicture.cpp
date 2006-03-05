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

    pictureDir.GetFirst(&pictureFileName, wxT("*.jpg"), wxDIR_DEFAULT);

    //获取原始图片
    if (!Image.LoadFile(config.LocalPicturePath + wxT("\\") + pictureFileName,
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
