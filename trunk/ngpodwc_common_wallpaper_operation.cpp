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
    //��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ�����
    //PodPictrueInfo pictureInfo;
    if(!pPodPictureInfo->GetInfo(pConfig->PodBasePath + wxT("\\") + pConfig->PodDatabaseName, pConfig->PodDate))
    {
        wxString msgTitle("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���",*wxConvCurrent);
        wxString msgContext("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
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

    //��ȡԭʼͼƬ
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

    //����ͼƬ�ߴ�
    if( (PodImage.GetWidth() != pConfig->ScreenWidth)
            && (PodImage.GetHeight() != pConfig->ScreenHeight) )
    {
        //���ԭͼƬ�ߴ�����Ļ�ߴ粻������������С
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

    //��ע����
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

    //��������ϵ�ͼƬ�����ָ��Ŀ¼
    //if(!outputScreenPicture(&config, &pictureInfo))
    if(!outputScreenPicture(pConfig, &ScreenImage))
    {
        wxString msgTitle("ͼƬCreate Error����",*wxConvCurrent);
        wxString msgContext("ͼƬCreate Error����\n��....XXXX.......������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    //�趨ͼƬ������
    setWallpaperRegInfo(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName);

    //����仯�󣨵�ǰ����ͼƬ����������Ϣ�������ļ�
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

        podInfoDisc.Replace(wxT("#145"), wxT("\'"), true);//��
        podInfoDisc.Replace(wxT("#146"), wxT("\'"), true);//��

        podInfoDisc.Replace(wxT("#147"), wxT("\""), true);//��
        podInfoDisc.Replace(wxT("#148"), wxT("\""), true);//��

        podInfoDisc.Replace(wxT("#151"), wxT("\'"), true);//��
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
