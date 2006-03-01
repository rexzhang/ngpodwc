/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc_common_config.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     09/02/2006
// RCS-ID:
// Copyright:   cooooooooooooopy
// Licence:
/////////////////////////////////////////////////////////////////////////////
#include "ngpodwc_common_config.h"
#include "ngpodwc_common_datetime.h"

//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
ngpodwcConfig::ngpodwcConfig()
{
    Init();
}

ngpodwcConfig::~ngpodwcConfig()
{
    //dtor
}

//---------------------------------------------------------------------------
//!config���ʼ��
//---------------------------------------------------------------------------
void ngpodwcConfig::Init()
{
    ConfigFileName = wxT("ngpodwc.ini");
    SetConfigFilePath(wxEmptyString);//ConfigFile = wxEmptyString + ConfigFileName;

    //������configΪĬ��ֵ,��Ϊ���䣨����������������Ϣ���ӵ������
    SetDefault();

    //config��iniֻ��ʼ��ΪĬ�ϲ������������ļ�
}

//---------------------------------------------------------------------------
//!config�������ļ��洢·������
//---------------------------------------------------------------------------
void ngpodwcConfig::SetConfigFilePath(wxString configFullPath)
{
    if (configFullPath == wxEmptyString)
        ConfigFile = ConfigFileName;
    else
        ConfigFile = configFullPath + wxT("\\") +ConfigFileName;
}

//---------------------------------------------------------------------------
//!config�������ļ��洢�ļ�����ȫ·������ȡ
//---------------------------------------------------------------------------
wxString ngpodwcConfig::GetConfigFile()
{
    return ConfigFile;
}

//---------------------------------------------------------------------------
//!����configΪĬ��ֵ
//---------------------------------------------------------------------------
void ngpodwcConfig::SetDefault()
{
    ///////////////////
    PodBasePath = wxEmptyString;
    PodDatabaseName = wxT("pod.mdb");//wxEmptyString;

    PodPictureMode = wxEmptyString;
    PodPicturePath = wxT("POD\\pictures\\lg_wallpaper");

    //2001-1-14���жϵ�������ֱ�Ӵ�2001-4-21��ʼ
    toWxDateTime(2001, 4, 21, &PodDate);

    //////////////
    LocalPicturePath = wxEmptyString;

    ////////////////
    ScreenWidth = 1024;
    ScreenHeight = 768;

    ScreenPicturePath = wxEmptyString;
    ScreenPictureName = wxT("POD_Wallpaper.bmp");

    ////////////////
    //Locked = false;
    PauseChangeWallpaper = false;//old-----bool Locked;
    ShowSplash = true;

    ShowDisc = true;

    return;
}


//---------------------------------------------------------------------------
//!��ȡ������Ϣ���ڴ�
//---------------------------------------------------------------------------
bool ngpodwcConfig::ReadConfig()
{
    //�������ļ�
    wxFileInputStream ConfigInputStream(ConfigFile);
    if(!ConfigInputStream.Ok())//��������ļ��Ƿ����
    {
        //�澯
        //wxString msgTitle("�����ļ������ڣ�",*wxConvCurrent);
        wxString msgTitle(wxT("lost .INI file"));
        wxString msgContext = wxT("can't found : ") + ConfigFile;
        //wxString msgContext("�Ҳ�����������ļ� ngpodwc.ini��\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
        //wxString msgContext;
        //msgContext.Printf(wxT("�Ҳ�����������ļ�:\n%s\n������ ngpodcc.exe ���г�ʼ��������"),ConfigFile);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));
        return 0;
    }

    //�����������ļ�������
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInputStream, wxConvUTF8);

    //��ȡ�����ļ�->�ڴ�
    PodBasePath = pFileConfig->Read(wxT("PodBasePath"));

    PodDatabaseName = pFileConfig->Read(wxT("PodDatabaseName"));
    PodPicturePath = pFileConfig->Read(wxT("PodPicturePath"));

    int year,month,mday;
    pFileConfig->Read(wxT("PodYear"), &(year));
    pFileConfig->Read(wxT("PodMonth"), &(month));
    pFileConfig->Read(wxT("PodDays"), &(mday));
    toWxDateTime(year, month, mday, &PodDate);

    ///////////////
    LocalPicturePath = pFileConfig->Read(wxT("LocalPicturePath"));

    /////////////
    ScreenPicturePath = pFileConfig->Read(wxT("ScreenPicturePath"));
    ScreenPictureName = pFileConfig->Read(wxT("ScreenPictureName"));
    pFileConfig->Read(wxT("ScreenWidth"), &(ScreenWidth));
    pFileConfig->Read(wxT("ScreenHeight"), &(ScreenHeight));

    /////////////////
    pFileConfig->Read(wxT("ShowDisc"), &(ShowDisc));

    pFileConfig->Read(wxT("PauseChangeWallpaper"), &(PauseChangeWallpaper));
    pFileConfig->Read(wxT("ShowSplash"), &(ShowSplash));

    //!ConfigInputStream.Close();
    //!ngpodwc.cpp:64: error: 'class wxFileInputStream' has no member named 'Close'

    return 1;
}

//---------------------------------------------------------------------------
//!���ڴ��е�������Ϣд�������ļ�
//---------------------------------------------------------------------------
bool ngpodwcConfig::WriteConfig()
{


    //�������ļ�
    wxFileOutputStream ConfigOutputStream(ConfigFile);
    if(!ConfigOutputStream.Ok())//��������ļ��Ƿ����
    {
        wxString msgTitle("�����ļ������ڣ�",*wxConvCurrent);
        wxString msgContext("�Ҳ�����������ļ� ngpodwc.ini��\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));
        return 0;
    }

    //wxFileConfig *pFileConfig = new wxFileConfig(ConfigOutputStream, wxConvUTF8);
    wxFileConfig *pFileConfig = new wxFileConfig();
    /////////////////
    pFileConfig->Write(wxT("PodBasePath"), PodBasePath);

    pFileConfig->Write(wxT("PodDatabaseName"), PodDatabaseName);
    pFileConfig->Write(wxT("PodPicturePath"), PodPicturePath);

    int year,month,mday;
    toDate(PodDate, &year, &month, &mday);
    pFileConfig->Write(wxT("PodYear"), year);
    pFileConfig->Write(wxT("PodMonth"), month);
    pFileConfig->Write(wxT("PodDays"), mday);

    ////////////////////
    pFileConfig->Write(wxT("LocalPicturePath"), LocalPicturePath);

    /////////////////////
    pFileConfig->Write(wxT("ScreenPicturePath"), ScreenPicturePath);
    pFileConfig->Write(wxT("ScreenPictureName"), ScreenPictureName);
    pFileConfig->Write(wxT("ScreenWidth"), ScreenWidth);
    pFileConfig->Write(wxT("ScreenHeight"), ScreenHeight);

    //////////////////////
    pFileConfig->Write(wxT("ShowDisc"), ShowDisc);

    pFileConfig->Write(wxT("PauseChangeWallpaper"), PauseChangeWallpaper);
    pFileConfig->Write(wxT("ShowSplash"), ShowSplash);

    //���浽�ļ�
    pFileConfig->Save(ConfigOutputStream, wxConvUTF8);
    ConfigOutputStream.Close();

    return 1;
}


