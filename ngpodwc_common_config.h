/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_common_config.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     09/02/2006
// RCS-ID:
// Copyright:   cooooooooooooopy
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H


#include <wx/string.h>

//ʹ�ú��������ͼƬ��Դ
//��wxChoice�ı��ԭ��
#define PICTURESOURCE_LOCALFILE 0
#define PICTURESOURCE_NGPOD 1


//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
class ngpodwcConfig
{
public:
    //�๹�캯��
    ngpodwcConfig();
    virtual ~ngpodwcConfig();
    //���ʼ������
    void Init();

    //���Ա����
    void SetConfigFilePath(wxString configFullPath);
    void SetDefault();

    wxString GetConfigFile();

    bool ReadConfig();
    bool WriteConfig();

    //���Ա����--------------
    int PictureSource;

    //NGPOD���
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    wxDateTime PodDate;

    //����ͼƬ��Դ��Ϣ
    wxString LocalPicturePath;

    //������ʾ��/�������
    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    //ͼƬ�������
    bool ShowDisc;

    //����������
    bool PauseChangeWallpaper;//old-----bool Locked;
    bool ShowSplash;

protected:

private:
    //config�����ļ�·�����ļ�������Ϣ
    wxString ConfigFile;//Full Path + FileName
    wxString ConfigFileName;
};

#endif // COMMON_CONFIG_H
