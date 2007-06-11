/////////////////////////////////////////////////////////////////////////////
// Name:        common_config.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     09/02/2006
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

#include <wx/wfstream.h>
#include <wx/fileconf.h>
#include <wx/intl.h>
//#include

#include "common_config.h"
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
    PictureSource = PICTURESOURCE_LOCALFILE;

    UILanguage = wxLANGUAGE_DEFAULT;

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
    //��������ļ��Ƿ����
    if ( !wxFileExists(ConfigFile) )
    {
        //û�������ļ�
        wxLogWarning(_("Can't found .INI(%s) file. Skip read config."), ConfigFile.c_str());
        return false;
    }
    //�������ļ�
    wxFileInputStream ConfigInputStream(ConfigFile);
    if(!ConfigInputStream.Ok())//��������ļ��Ƿ�򿪳ɹ�
    {
        //�澯
        wxLogWarning(_("Can't open .INI(%s) file with READ mode. Skip read config."), ConfigFile.c_str());
        return false;
    }

    //�����������ļ�������
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInputStream, wxConvUTF8);

    //��ȡ�����ļ�->�ڴ�
    pFileConfig->Read(wxT("PictureSource"), &(PictureSource));

    ///////////////////////
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

    //��UICanonicalName(ISO����xx_XX)ת��ΪUILanguage(����)
    wxString UICanonicalName;
    if(pFileConfig->Read(wxT("UILanguage"), &(UICanonicalName)))
    {
        //wxLocale UIwxLocale;
        const wxLanguageInfo* UILanguageInfo = wxLocale::FindLanguageInfo(UICanonicalName);
        UILanguage = UILanguageInfo->Language;
    }

    //!ConfigInputStream.Close();
    //!ngpodwc.cpp:64: error: 'class wxFileInputStream' has no member named 'Close'

    return true;
}

//---------------------------------------------------------------------------
//!���ڴ��е�������Ϣд�������ļ�
//---------------------------------------------------------------------------
bool ngpodwcConfig::WriteConfig()
{
    //�������ļ�
    wxFileOutputStream ConfigOutputStream(ConfigFile);
    if(!ConfigOutputStream.Ok())//��������ļ��Ƿ�򿪳ɹ�
    {
        wxLogWarning(_("Can't open .INI(%s) file with WRITE mode. Skip write config."), ConfigFile.c_str());
        return false;
    }

    //wxFileConfig *pFileConfig = new wxFileConfig(ConfigOutputStream, wxConvUTF8);
    wxFileConfig *pFileConfig = new wxFileConfig();
    /////////////////
    pFileConfig->Write(wxT("PictureSource"), PictureSource);

    /////////////////////
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

    //��UILanguage(����)ת��ΪUICanonicalName(ISO����xx_XX)
    wxString UICanonicalName;
    const wxLanguageInfo* UILanguageInfo = wxLocale::GetLanguageInfo(UILanguage);
    UICanonicalName = UILanguageInfo->CanonicalName;
    pFileConfig->Write(wxT("UILanguage"), UICanonicalName);

    //���浽�ļ�
    pFileConfig->Save(ConfigOutputStream, wxConvUTF8);
    ConfigOutputStream.Close();

    return true;
}


