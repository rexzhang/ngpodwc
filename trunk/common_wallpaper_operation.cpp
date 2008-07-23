/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_operation.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-02-28
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

#include <wx/msw/registry.h>

#include "common_globals.h"

#include "common_wallpaper_operation.h"
/////
#include "common_wallpaper_ngpod.h"
#include "common_wallpaper_localpicture.h"
#include "common_wallpaper_ngpod_online.h"

bool updateWallpaper()
{
    WallpaperBase *pWallpaper;

    //获取POD 图片
    switch (configRunning.PictureSource)
    {
        case PICTURESOURCE_LOCALFILE:
        //pWallpaper = new WallpaperLocalPicture(config);
        pWallpaper = new WallpaperLocalPicture();
        break;
        case PICTURESOURCE_NGPOD:
        //pWallpaper = new WallpaperNGPOD(config);
        pWallpaper = new WallpaperNGPOD();
        break;
        case PICTURESOURCE_NGPOD_ONLINE:
        //pWallpaper = new WallpaperNGPODOnline(config);
        pWallpaper = new WallpaperNGPODOnline();
        break;
        default:
        wxLogError(_("Lost config info with PictureSource"));
        return false;
    }

    if(!pWallpaper->ImageOk())
    {
        wxSafeShowMessage(wxT("Image Op Error#1"), wxT("Image Op Error#1"));
        return false;
    }

    //调整图片尺寸
    pWallpaper->ImageReSize();

    //加注文字
    pWallpaper->DrawText();

    if(!pWallpaper->ImageOk())
    {
        wxSafeShowMessage(wxT("Image Op Error#2"), wxT("Image Op Error#2"));
        return false;
    }

    //将处理完毕的图片输出至指定目录
    pWallpaper->SaveWallpaper();

    //设定图片至桌布
    setWallpaperRegInfo(configRunning.ScreenPicturePath + wxT("\\") + configRunning.ScreenPictureName);

    /*
    //移动到需要的派生类如WallpaperNGPOD
    //保存变化后（当前背景图片）的日期信息至配置文件
    config.WriteConfig();
    */
    //释放内存
    delete pWallpaper;

    return true;
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
    wxString regKeyString = wxT("HKEY_CURRENT_USER\\Control Panel\\Desktop");
    wxRegKey *pRegKey = new wxRegKey(regKeyString);
    if( !pRegKey->Exists() )
    {
        wxLogError(_("_WIN32_Reg(%s)Error!"), regKeyString.c_str());
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

    return true;
}

