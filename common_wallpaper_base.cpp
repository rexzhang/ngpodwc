/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_base.cpp
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

#include <wx/bitmap.h>
#include <wx/dcmemory.h>
#include <wx/gdicmn.h>
#include <wx/font.h>

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

wxString WallpaperBase::GetText()
{
    return wxEmptyString;
}

bool WallpaperBase::DrawText()
{
    wxString TextString(GetText());//��ȡ��Ҫ��ע�ĸ�ʽ������ı�
    if(TextString == wxEmptyString)
    {
        //û�м�ע��Ϣ��ֱ������
        return false;
    }
    wxBitmap ScreenBitmap(Image);
    // Create a memory DC
    wxMemoryDC ScreenImageDC;
    ScreenImageDC.SelectObject(ScreenBitmap);
    wxColourDatabase ColourDB;
    //ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    //ScreenImageDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

    //
    int InfoBoxW = 600, InfoBoxH = 200;
    int InfoBoxXY = 20, infoBoxYSeek = 30;//��Ϊ����ʱ��Ϊ��������Ļ���½ǵ��������

    wxRect podInfoRect(Image.GetWidth() - InfoBoxXY - InfoBoxW,
                       Image.GetHeight() - InfoBoxXY - InfoBoxH - infoBoxYSeek,
                       InfoBoxW, InfoBoxH);
    /*
        //--------------------------------
        wxBitmap InfoBoxBitmap(600,150, 16);
        InfoBoxBitmap.LoadFile(wxT("share/art/logo.xpm"), wxBITMAP_TYPE_XPM);
        wxMemoryDC InfoBoxDC;

        InfoBoxDC.SelectObject(InfoBoxBitmap);
        InfoBoxDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
        InfoBoxDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

        //InfoBoxDC.Clear();
        //InfoBoxDC.DrawRoundedRectangle(0,0,600,150,20);
        InfoBoxDC.DrawRectangle(1,1,550,140);

        ScreenImageDC.DrawBitmap(InfoBoxBitmap, 400, 600, true);
        //--------------------------------
    */
    //ScreenImageDC.DrawRectangle(400,600,600,150);
    wxFont ScreenImageFont = ScreenImageDC.GetFont();
    ScreenImageFont.SetFamily(wxFONTFAMILY_ROMAN);
    ScreenImageDC.SetFont(ScreenImageFont);
    //ScreenImageDC.SetBackgroundMode(wxSOLID);//ǿ��ָ����ʾ���屳��ɫ��Ĭ��Ϊ͸��

    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    ScreenImageDC.DrawLabel(TextString, podInfoRect, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);

    //
    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("LIGHT GREY")));

    int InfoBoxW2 = 600, InfoBoxH2 = 200;
    int InfoBoxXY2 = 20, infoBoxYSeek2 = 30;//��Ϊ����ʱ��Ϊ��������Ļ���½ǵ��������
    wxRect podInfoRect2(Image.GetWidth() - InfoBoxXY2 - InfoBoxW2 - 1,
                        Image.GetHeight() - InfoBoxXY2 - InfoBoxH2 - infoBoxYSeek2 - 1,
                        InfoBoxW2, InfoBoxH2);
    ScreenImageDC.DrawLabel(TextString, podInfoRect2, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);
    //

    ScreenImageDC.SelectObject( wxNullBitmap );
    Image = ScreenBitmap.ConvertToImage();

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
    wxString wallpaper = config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName;
    if(!Image.SaveFile(wallpaper, wxBITMAP_TYPE_BMP))
    {
        //wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));
        wxLogError(_("ERROR! Can't create(save) wallpaper file(%s)!"), wallpaper.c_str());
        return false;
    }
    return true;
}
