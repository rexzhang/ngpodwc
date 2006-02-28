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

bool updateWallpaper(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo)
//bool updateWallpaper()
{
    //获取POD 图片描述信息以及图片文件名称
    //PodPictrueInfo pictureInfo;
    if(!pPodPictureInfo->GetInfo(pConfig->PodBasePath + wxT("\\") + pConfig->PodDatabaseName, pConfig->PodDate))
    {
        wxString msgTitle("获取POD 图片描述信息以及图片文件名称错误！",*wxConvCurrent);
        wxString msgContext("获取POD 图片描述信息以及图片文件名称错误！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    /*
    //Debug Info
    wxSafeShowMessage(pConfig->PodBasePath + wxT("\\")
                      + pConfig->PodPicturePath + wxT("\\")
                      + pPodPictureInfo->PhotoName,
                      pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName);
                      */

    //获取原始图片
    wxImage PodImage, ScreenImage;

    if (!PodImage.LoadFile(pConfig->PodBasePath + wxT("\\") + pConfig->PodPicturePath
                           + wxT("\\") + pPodPictureInfo->PhotoName, wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Can't load JPG image"), pPodPictureInfo->PhotoName);
        return 0;
    }

    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_8BPP_GREY);
    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_24BPP);
    if(!PodImage.Ok())
    {
        wxSafeShowMessage(wxT("Pod Image Op Error"), wxT("Pod Image Op Error"));
        return 1;
    }

    //调整图片尺寸
    if( (PodImage.GetWidth() != pConfig->ScreenWidth)
            && (PodImage.GetHeight() != pConfig->ScreenHeight) )
    {
        //如果原图片尺寸与屏幕尺寸不符〉〉调整大小
        /*
        //Debug Info
        wxString msg;
        msg.Printf(wxT("From : %i x %i\nTo   : %i x %i"),
                   PodImage.GetWidth(), PodImage.GetHeight(), pConfig->ScreenWidth, pConfig->ScreenHeight);
        wxSafeShowMessage(wxT("change size"), msg);
        */
        //wxSize ScreenSize(pConfig->ScreenWidth, pConfig->ScreenHeight);
        PodImage.Rescale(pConfig->ScreenWidth, pConfig->ScreenHeight);
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
    if(pConfig->ShowDisc)
    {
        pictureOpretionDrawText(&ScreenImage, pPodPictureInfo);
    }
    //ConvertToImage

    if(!ScreenImage.Ok())
    {
        wxSafeShowMessage(wxT("Image Op Error#2"), wxT("Image Op Error#2"));
        return 1;
    }

    //将处理完毕的图片输出至指定目录
    //if(!outputScreenPicture(&config, &pictureInfo))
    if(!outputScreenPicture(pConfig, &ScreenImage))
    {
        wxString msgTitle("图片Create Error错误！",*wxConvCurrent);
        wxString msgContext("图片Create Error错误！\n请....XXXX.......操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

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
    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    ScreenImageDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

    //
    wxString podInfoDisc(pPodPictureInfo->Disc);
    podInfoDisc.Replace(wxT("<BR>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<I>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</I>"), wxT(""), true);

    podInfoDisc.Replace(wxT("\n"), wxT(""), true);
    podInfoDisc.Replace(wxT(".\n"), wxT("."), true);
    podInfoDisc.Replace(wxT(". "), wxT(". \n "), true);

    /*
    podInfoDisc.Replace(wxT("\n"), wxT(" \n "), true);
    podInfoDisc.Replace(wxT(".\n"), wxT(". \n "), true);
    //podInfoDisc.Replace(wxT("."), wxT(".\n"), true);
    */

    //if(podInfoDisc.Find(wxT("#")))
    {
        podInfoDisc.Replace(wxT("#034"), wxT("\""), true);

        podInfoDisc.Replace(wxT("#145"), wxT("\'"), true);//‘
        podInfoDisc.Replace(wxT("#146"), wxT("\'"), true);//’

        podInfoDisc.Replace(wxT("#147"), wxT("\""), true);//“
        podInfoDisc.Replace(wxT("#148"), wxT("\""), true);//”

        podInfoDisc.Replace(wxT("#151"), wxT("\'"), true);//＇
    }


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
    wxRect podInfoRect(400,500,600,200);
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
    ScreenImageDC.SetBackgroundMode(wxSOLID);
    ScreenImageDC.DrawLabel(podInfoString, podInfoRect, wxALIGN_RIGHT | wxALIGN_BOTTOM);

    *pScreenImage = ScreenBitmap.ConvertToImage();

    return;
}

// ----------------------------------------------------------------------------
// FUNCTION USED FOR xxxxxxx wxImage<wxWidgets>
// ----------------------------------------------------------------------------
// return 1 = true/Finish
bool outputScreenPicture(ngpodwcConfig *pConfig, wxImage *pScreenImage)
//bool outputScreenPicture()
{

    if(!pScreenImage->SaveFile(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName,
                               wxBITMAP_TYPE_BMP))
    {
        wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));
        return 0;
    };

    return 1;
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
