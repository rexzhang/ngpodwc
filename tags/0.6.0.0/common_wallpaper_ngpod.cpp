#include "common_wallpaper_ngpod.h"

WallpaperNGPOD::WallpaperNGPOD(ngpodwcConfig programConfig):WallpaperBase(programConfig)
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
    //��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ�����
    if(!podPictureInfo.GetInfo(config.PodBasePath + wxT("\\") + config.PodDatabaseName, config.PodDate))
    {
        wxString msgTitle("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���",*wxConvCurrent);
        wxString msgContext("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
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

    //��ȡԭʼͼƬ
    if (!Image.LoadFile(config.PodBasePath + wxT("\\") + config.PodPicturePath
                           + wxT("\\") + podPictureInfo.PhotoName, wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Can't load JPG image"), podPictureInfo.PhotoName);
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
    //��������ϵ�ͼƬ�����ָ��Ŀ¼
    if(!Image.SaveFile(config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName,
                               wxBITMAP_TYPE_BMP))
    {
        wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));

        wxString msgTitle("ͼƬCreate Error����",*wxConvCurrent);
        wxString msgContext("ͼƬCreate Error����\n��....XXXX.......������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return false;
    }
    //����仯�󣨵�ǰ����ͼƬ����������Ϣ�������ļ�
    config.WriteConfig();
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

        podInfoDisc.Replace(wxT("#145"), wxT("\'"), true);//��
        podInfoDisc.Replace(wxT("#146"), wxT("\'"), true);//��

        podInfoDisc.Replace(wxT("#147"), wxT("\""), true);//��
        podInfoDisc.Replace(wxT("#148"), wxT("\""), true);//��

        podInfoDisc.Replace(wxT("#151"), wxT("\'"), true);//��
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
