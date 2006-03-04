#include "common_wallpaper_ngpod.h"

WallpaperNGPOD::WallpaperNGPOD(ngpodwcConfig programConfig):WallpaperBase(programConfig)
{
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

    return true;
}
