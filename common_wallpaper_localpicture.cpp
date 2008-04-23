/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_localpicture.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-04
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/string.h>
#include <wx/dir.h>
#include <wx/arrstr.h>

#include "common_globals.h"
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
    wxString pictureFileName;

    wxDir pictureDir(configRunning.LocalPicturePath);
    wxArrayString PictureArray;

    srand((int)time(0));
    pictureDir.GetAllFiles(configRunning.LocalPicturePath, &PictureArray,
                           wxT("*.jpg"), wxDIR_DEFAULT);

    pictureFileName = PictureArray[(int)(PictureArray.GetCount()*rand()/(RAND_MAX +1))];

    //获取原始图片
    if (!Image.LoadFile(pictureFileName,
                        wxBITMAP_TYPE_JPEG))
    {
        //wxSafeShowMessage(wxT("Local Picture Loading ERROR!"), pictureFileName);
        wxLogError(_("ERROR! Can't read Local Picture(%s)!"), pictureFileName.c_str());
        return false;
    }

    return true;
}

bool WallpaperLocalPicture::DrawText()
{
    return true;
}
