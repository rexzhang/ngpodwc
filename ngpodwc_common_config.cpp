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

//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
ngpodwcConfig::ngpodwcConfig()
{
    Init();
}

//---------------------------------------------------------------------------
//!config���ʼ��
//---------------------------------------------------------------------------
void ngpodwcConfig::Init()
{
    //������configΪĬ��ֵ
    SetDefault();

    //�ٶ�ȡ�����ļ���config����Ϊ���䣨����������������Ϣ���ӵ������
    ReadConfig();
}

//---------------------------------------------------------------------------
//!����configΪĬ��ֵ
//---------------------------------------------------------------------------
void ngpodwcConfig::SetDefault()
{
    PodBasePath = wxEmptyString;
    PodDatabaseName = wxT("pod.mdb");//wxEmptyString;

    PodPictureMode = wxEmptyString;
    PodPicturePath = wxT("POD\\pictures\\lg_wallpaper");

    //2001-1-14���жϵ�������ֱ�Ӵ�2001-4-21��ʼ
    PodYear = 2001;
    PodMonth = 4;
    PodDays = 21;

    ScreenWidth = 1024;
    ScreenHeight = 768;

    ScreenPicturePath = wxEmptyString;
    ScreenPictureName = wxT("POD_Wallpaper.bmp");
}


//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
bool ngpodwcConfig::ReadConfig()
{
    //�������ļ�
    wxFileInputStream ConfigInputStream(wxT("ngpodwc.ini"));
    if(!ConfigInputStream.Ok())//��������ļ��Ƿ����
    {
        //�澯
        wxString msgTitle("�����ļ������ڣ�",*wxConvCurrent);
        wxString msgContext("�Ҳ�����������ļ� ngpodwc.ini��\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
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

    pFileConfig->Read(wxT("PodYear"), &(PodYear));
    pFileConfig->Read(wxT("PodMonth"), &(PodMonth));
    pFileConfig->Read(wxT("PodDays"), &(PodDays));

    ScreenPicturePath = pFileConfig->Read(wxT("ScreenPicturePath"));
    ScreenPictureName = pFileConfig->Read(wxT("ScreenPictureName"));
    pFileConfig->Read(wxT("ScreenWidth"), &(ScreenWidth));
    pFileConfig->Read(wxT("ScreenHeight"), &(ScreenHeight));

    //!ConfigInputStream.Close();
    //!ngpodwc.cpp:64: error: 'class wxFileInputStream' has no member named 'Close'

    return 1;
}

//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
bool ngpodwcConfig::WriteConfig()
{


    //�������ļ�
    wxFileOutputStream ConfigOutputStream(wxT("ngpodwc.ini"));
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

    pFileConfig->Write(wxT("PodBasePath"), PodBasePath);

    pFileConfig->Write(wxT("PodDatabaseName"), PodDatabaseName);
    pFileConfig->Write(wxT("PodPicturePath"), PodPicturePath);

    pFileConfig->Write(wxT("PodYear"), PodYear);
    pFileConfig->Write(wxT("PodMonth"), PodMonth);
    pFileConfig->Write(wxT("PodDays"), PodDays);

    pFileConfig->Write(wxT("ScreenPicturePath"), ScreenPicturePath);
    pFileConfig->Write(wxT("ScreenPictureName"), ScreenPictureName);
    pFileConfig->Write(wxT("ScreenWidth"), ScreenWidth);
    pFileConfig->Write(wxT("ScreenHeight"), ScreenHeight);

    //���浽�ļ�
    pFileConfig->Save(ConfigOutputStream, wxConvUTF8);
    ConfigOutputStream.Close();

    return 1;
}


