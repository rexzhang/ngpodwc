/////////////////////////////////////////////////////////////////////////////
// Name:        %SOURCE-FILENAME%
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     %DATE%
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include "ngpodwc_common_wallpaper_operation.h"

bool updateWallpaper(ngpodwcConfig config)
//bool updateWallpaper()
{
    ngpodwcConfig *pConfig = &config;

    //获取POD 图片
    WallpaperNGPOD ngpodImage(config);

    wxImage PodImage, ScreenImage;
    PodImage = ngpodImage.Image;
    if(!PodImage.Ok())
    {
        wxSafeShowMessage(wxT("Pod Image Op Error"), wxT("Pod Image Op Error"));
        return 1;
    }

    //调整图片尺寸
    if( (PodImage.GetWidth() != pConfig->ScreenWidth)
            || (PodImage.GetHeight() != pConfig->ScreenHeight) )
    {
        //如果原图片尺寸与屏幕尺寸不符〉〉调整大小
        /*
        //Debug Info
        wxString msg;
        msg.Printf(wxT("From : %i x %i\nTo   : %i x %i"),
                   PodImage.GetWidth(), PodImage.GetHeight(), pConfig->ScreenWidth, pConfig->ScreenHeight);
        wxSafeShowMessage(wxT("change size"), msg);
        */
        ScreenImage = PodImage.Rescale(pConfig->ScreenWidth, pConfig->ScreenHeight);
    }
    else
    {
        ScreenImage = PodImage;
    }

    if(!ScreenImage.Ok())
    {
        wxSafeShowMessage(wxT("Image Op Error#1"), wxT("Image Op Error#1"));
        return 1;
    }

    //加注文字
    ngpodImage.Image = ScreenImage;
    ngpodImage.DrawText();
    ScreenImage = ngpodImage.Image;

    if(!ScreenImage.Ok())
    {
        wxSafeShowMessage(wxT("Image Op Error#2"), wxT("Image Op Error#2"));
        return 1;
    }

    //将处理完毕的图片输出至指定目录
    ngpodImage.SaveWallpaper();

    //设定图片至桌布
    setWallpaperRegInfo(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName);

    //保存变化后（当前背景图片）的日期信息至配置文件
    pConfig->WriteConfig();

    return true;
}

// ----------------------------------------------------------------------------
//!FUNCTION USED FOR xxxxxxx wxMemoryDC<wxWidgets>
// ----------------------------------------------------------------------------
void pictureOpretionDrawText(wxImage *pScreenImage, ngpodinfo *pPodPictureInfo)
{
    wxBitmap ScreenBitmap(pScreenImage);
    // Create a memory DC
    wxMemoryDC ScreenImageDC;
    ScreenImageDC.SelectObject(ScreenBitmap);
    //ScreenImageDC.SelectObject(*pScreenImage);
    wxColourDatabase ColourDB;
    //ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    //ScreenImageDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

    wxString podInfoDisc(pPodPictureInfo->Disc);
    if(podInfoDisc.Contains(wxT("#")))
    {
        podInfoDisc.Replace(wxT("#034"), wxT("\""), true);
        podInfoDisc.Replace(wxT("#039"), wxT("\'"), true);

        podInfoDisc.Replace(wxT("#133"), wxT("..."), true);//...

        podInfoDisc.Replace(wxT("#145"), wxT("\'"), true);//‘
        podInfoDisc.Replace(wxT("#146"), wxT("\'"), true);//’

        podInfoDisc.Replace(wxT("#147"), wxT("\""), true);//“
        podInfoDisc.Replace(wxT("#148"), wxT("\""), true);//”

        podInfoDisc.Replace(wxT("#151"), wxT("\'"), true);//＇
    }
    //
    podInfoDisc.Replace(wxT("<BR>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<I>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</I>"), wxT(""), true);

    podInfoDisc.Replace(wxT("\n"), wxT(""), true);
    podInfoDisc.Replace(wxT(".\n"), wxT("."), true);
    podInfoDisc.Replace(wxT(". "), wxT(". \n "), true);
    podInfoDisc.Replace(wxT(" \n \n"), wxT(" \n"), true);

    podInfoDisc.Replace(wxT(".\'\" "), wxT(".\'\" \n "), true);

    /*
    podInfoDisc.Replace(wxT("\n"), wxT(" \n "), true);
    podInfoDisc.Replace(wxT(".\n"), wxT(". \n "), true);
    //podInfoDisc.Replace(wxT("."), wxT(".\n"), true);
    */

    //
    wxString podInfoString;//
    podInfoString.Printf(wxT(" Title : %s \n Date: %s \n When : %s \n Who : %s \n\n "),
                         pPodPictureInfo->Title,
                         pPodPictureInfo->PodDate,
                         pPodPictureInfo->When,
                         pPodPictureInfo->Who);
    podInfoString = podInfoString + podInfoDisc + wxT(" ");

    podInfoString.Replace(wxT("National Geographic Photo of the Day: "), wxT(""), true);
    podInfoString.Replace(wxT(" 00:00:00"), wxT(""), true);
    //
    int InfoBoxW = 600, InfoBoxH = 200;
    int InfoBoxXY = 20, infoBoxYSeek = 30;//当为右下时，为右下与屏幕右下角的相对坐标

    wxRect podInfoRect(pScreenImage->GetWidth() - InfoBoxXY - InfoBoxW,
                       pScreenImage->GetHeight() - InfoBoxXY - InfoBoxH - infoBoxYSeek,
                       InfoBoxW, InfoBoxH);
    /*
        //--------------------------------
        wxBitmap InfoBoxBitmap(600,150, 16);
        InfoBoxBitmap.LoadFile(wxT("art/logo.xpm"), wxBITMAP_TYPE_XPM);
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
    //ScreenImageDC.SetBackgroundMode(wxSOLID);//强制指定显示字体背景色，默认为透明

    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    ScreenImageDC.DrawLabel(podInfoString, podInfoRect, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);
    ///////-------------
    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("LIGHT GREY")));

    int InfoBoxW2 = 600, InfoBoxH2 = 200;
    int InfoBoxXY2 = 20, infoBoxYSeek2 = 30;//当为右下时，为右下与屏幕右下角的相对坐标
    wxRect podInfoRect2(pScreenImage->GetWidth() - InfoBoxXY2 - InfoBoxW2 - 1,
                        pScreenImage->GetHeight() - InfoBoxXY2 - InfoBoxH2 - infoBoxYSeek2 - 1,
                        InfoBoxW2, InfoBoxH2);
    ScreenImageDC.DrawLabel(podInfoString, podInfoRect2, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);

    ///////-------------

    ScreenImageDC.SelectObject( wxNullBitmap );

    *pScreenImage = ScreenBitmap.ConvertToImage();

    return;
}

// ----------------------------------------------------------------------------
//!在注册表中指定背景图片位置，图片显示方式
//!并提示系统刷屏幕以便显示新设定的背景图片
//!MSW版本
// ----------------------------------------------------------------------------
//
bool setWallpaperRegInfo(wxString WallpaperPathAndName)
{
    //打开相关注册表
    wxRegKey *pRegKey = new wxRegKey(wxT("HKEY_CURRENT_USER\\Control Panel\\Desktop"));
    if( !pRegKey->Exists() )
    {
        wxSafeShowMessage(wxT("Reg ERROR!"), wxT("Reg ERROR!"));
    }

    /*
    //Debug Info
    wxString msg;
    pRegKey->QueryValue(wxT("Wallpaper"),msg);
    wxSafeShowMessage(msg,msg);
    */

    //设置图片显示方式
    WallpaperStyle style;
    style = Centered;
    switch( style )
    {
        case Stretched ://拉伸
        pRegKey->SetValue(wxT("WallpaperStyle"), 2);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Centered ://居中
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Tiled ://平铺
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 1);
        break;
    }

    //设置图片位置
    pRegKey->SetValue(wxT("Wallpaper"), WallpaperPathAndName);

    //关闭注册表
    pRegKey->Close();

    //提示系统刷新屏幕
    /*
    //函数使用范例
    //!http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/systemparametersinfo.asp
    //SPI_GETDESKWALLPAPER == get
    //SPI_SETDESKWALLPAPER
    char path[254]="c:\\winnt\\pod_wallpaper.bmp";//!
    //char path[254]="";
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    //转换成当前编码ASCII格式
    char path[254]="";
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

    /*
    //Unicode 版本 ，还有问题
    wxChar wxpath = wxt("");
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));

    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    return 1;
}
