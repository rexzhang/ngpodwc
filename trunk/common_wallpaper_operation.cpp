/////////////////////////////////////////////////////////////////////////////
// Name:        common_wallpaper_operation.cpp
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     %DATE%
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/msw/registry.h>

#include "common_wallpaper_operation.h"
/////
#include "common_wallpaper_ngpod.h"
#include "common_wallpaper_localpicture.h"
#include "common_wallpaper_ngpod_online.h"

bool updateWallpaper(ngpodwcConfig config)
{
    WallpaperBase *pWallpaper;

    //��ȡPOD ͼƬ
    switch (config.PictureSource)
    {
        case PICTURESOURCE_LOCALFILE:
        pWallpaper = new WallpaperLocalPicture(config);
        break;
        case PICTURESOURCE_NGPOD:
        pWallpaper = new WallpaperNGPOD(config);
        break;
        case PICTURESOURCE_NGPOD_ONLINE:
        pWallpaper = new WallpaperNGPODOnline(config);
        break;
        //default:
    }

    if(!pWallpaper->ImageOk())
    {
        wxSafeShowMessage(wxT("Image Op Error#1"), wxT("Image Op Error#1"));
        return false;
    }

    //����ͼƬ�ߴ�
    pWallpaper->ImageReSize();

    //��ע����
    pWallpaper->DrawText();

    if(!pWallpaper->ImageOk())
    {
        wxSafeShowMessage(wxT("Image Op Error#2"), wxT("Image Op Error#2"));
        return false;
    }

    //��������ϵ�ͼƬ�����ָ��Ŀ¼
    pWallpaper->SaveWallpaper();

    //�趨ͼƬ������
    setWallpaperRegInfo(config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName);

    /*
    //�ƶ�����Ҫ����������WallpaperNGPOD
    //����仯�󣨵�ǰ����ͼƬ����������Ϣ�������ļ�
    config.WriteConfig();
    */

    return true;
}

// ----------------------------------------------------------------------------
//!��ע�����ָ������ͼƬλ�ã�ͼƬ��ʾ��ʽ
//!����ʾϵͳˢ��Ļ�Ա���ʾ���趨�ı���ͼƬ
//!MSW�汾
// ----------------------------------------------------------------------------
//
bool setWallpaperRegInfo(wxString WallpaperPathAndName)
{
    //�����ע���
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

    //����ͼƬ��ʾ��ʽ
    WallpaperStyle style;
    style = Centered;
    switch( style )
    {
        case Stretched ://����
        pRegKey->SetValue(wxT("WallpaperStyle"), 2);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Centered ://����
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Tiled ://ƽ��
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 1);
        break;
    }

    //����ͼƬλ��
    pRegKey->SetValue(wxT("Wallpaper"), WallpaperPathAndName);

    //�ر�ע���
    pRegKey->Close();

    //��ʾϵͳˢ����Ļ
    /*
    //����ʹ�÷���
    //!http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/systemparametersinfo.asp
    //SPI_GETDESKWALLPAPER == get
    //SPI_SETDESKWALLPAPER
    char path[254]="c:\\winnt\\pod_wallpaper.bmp";//!
    //char path[254]="";
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    //ת���ɵ�ǰ����ASCII��ʽ
    char path[254]="";
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

    /*
    //Unicode �汾 ����������
    wxChar wxpath = wxt("");
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));

    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    return true;
}

