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

    //����仯�󣨵�ǰ����ͼƬ����������Ϣ�������ļ�
    config.WriteConfig();

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

    return 1;
}

