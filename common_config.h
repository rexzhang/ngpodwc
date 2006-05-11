/////////////////////////////////////////////////////////////////////////////
// Name:        common_config.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     09/02/2006
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <wx/string.h>
#include <wx/datetime.h>

//ʹ�ú��������ͼƬ��Դ
//��wxChoice�ı��ԭ��
#define PICTURESOURCE_LOCALFILE 0
#define PICTURESOURCE_NGPOD 1
#define PICTURESOURCE_NGPOD_ONLINE 2

//ʹ�ú����������Ļ�ֱ���
//��wxChoice�ı��ԭ��
#define SCREENWH640x480 0
#define SCREENWH800x600 1
#define SCREENWH1024x768 2
#define SCREENWHAutoDetect 3

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

    //���Ա����
    //!��������
    int PictureSource;

    //����������
    bool PauseChangeWallpaper;
    bool ShowSplash;
    int UILanguage;

    //!ͼƬ����
    bool ShowDisc;

    //!��������
    //������ʾ��/�������
    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    //!Դ-����ͼƬ��Դ��Ϣ
    wxString LocalPicturePath;

    //!Դ-NGPOD-ͨ��
    wxDateTime PodDate;

    //!Դ-NGPOD-1.x
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;
protected:

private:
    //config�����ļ�·�����ļ�������Ϣ
    wxString ConfigFile;// = Full Path + FileName
    wxString ConfigFileName;
};

#endif // COMMON_CONFIG_H