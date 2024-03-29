/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_ngpod.cpp
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

#include "common_globals.h"
#include "common_wallpaper_ngpod.h"

//WallpaperNGPOD::WallpaperNGPOD(ngpodwcConfig programConfig):WallpaperBase(programConfig)
WallpaperNGPOD::WallpaperNGPOD():WallpaperBase()
{
    Init();
    //ctor
}

WallpaperNGPOD::~WallpaperNGPOD()
{
    //dtor
}

bool WallpaperNGPOD::Init()
{
    //获取POD 图片描述信息以及图片文件名称
    if(!podPictureInfo.GetInfo(configRunning.PodBasePath + wxT("\\") + configRunning.PodDatabaseName, configRunning.PodDate))
    {
        wxString msgTitle("获取POD 图片描述信息以及图片文件名称错误！",*wxConvCurrent);
        wxString msgContext("获取POD 图片描述信息以及图片文件名称错误！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return false;
    }
    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_8BPP_GREY);
    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_24BPP);
    /*
    //Debug Info
    wxSafeShowMessage(pConfig->PodBasePath + wxT("\\")
                      + pConfig->PodPicturePath + wxT("\\")
                      + podPictureInfo.PhotoName,
                      pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName);
                      */

    //获取原始图片
    wxString NGPODPictureName = configRunning.PodBasePath + wxT("\\") + configRunning.PodPicturePath
                                + wxT("\\") + podPictureInfo.PhotoName;
    if (!Image.LoadFile(NGPODPictureName, wxBITMAP_TYPE_JPEG))
    {
        //wxSafeShowMessage(wxT("Can't load JPG image"), podPictureInfo.PhotoName);
        wxLogError(_("ERROR! Can't read NGPOD 1.x Local Picture(%s)!"), NGPODPictureName.c_str());
        return false;
    }
    if(!Image.Ok())
    {
        wxSafeShowMessage(wxT("Image Loading Op Error"), wxT("Image Loading Op Error"));
        return false;
    }
    return true;
}

bool WallpaperNGPOD::SaveWallpaper()
{
    //将处理完毕的图片输出至指定目录
    /*
    wxString wallpaper = config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName;
    if(!Image.SaveFile(wallpaper, wxBITMAP_TYPE_BMP))
    {
        wxLogError(_("ERROR! Can't create(save) wallpaper file(%s)!"), wallpaper.c_str());
        return false;
    }
    */
    if(!WallpaperBase::SaveWallpaper())
    {
        return false;
    }

    //保存变化后（当前背景图片）的日期信息至配置文件
    configRunning.WriteConfig();
    return true;
}

wxString WallpaperNGPOD::GetText()
{
    wxString podInfoDisc(podPictureInfo.Disc);
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

    wxString podInfoString;//
    podInfoString.Printf(wxT(" Title : %s \n Date: %s \n When : %s \n Who : %s \n\n "),
                         podPictureInfo.Title,
                         podPictureInfo.PodDate,
                         podPictureInfo.When,
                         podPictureInfo.Who);
    podInfoString = podInfoString + podInfoDisc + wxT(" ");

    podInfoString.Replace(wxT("National Geographic Photo of the Day: "), wxT(""), true);
    podInfoString.Replace(wxT(" 00:00:00"), wxT(""), true);

    return podInfoString;
}
