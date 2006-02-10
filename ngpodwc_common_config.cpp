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
//!
//---------------------------------------------------------------------------
void ngpodwcConfig::Init()
{
    PodBasePath=wxEmptyString;
    PodDatabaseName=wxEmptyString;

    PodPictureMode=wxEmptyString;
    PodPicturePath=wxEmptyString;

    PodYear = 2003;//?????
    PodMonth = 1;
    PodDays = 14;

    ScreenPicturePath=wxEmptyString;
    //ScreenPictureName = wxEmptyString;
    ScreenPictureName = wxT("POD_Wallpaper.bmp");

    ScreenWidth = 1024;
    ScreenHeight = 768;
}

//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
bool ngpodwcConfig::ReadConfig()
{
    //打开配置文件
    wxFileInputStream ConfigInputStream(wxT("ngpodwc.ini"));
    if(!ConfigInputStream.Ok())//检查配置文件是否存在
    {
        wxString msgTitle("配置文件不存在！",*wxConvCurrent);
        wxString msgContext("找不到检查配置文件 ngpodwc.ini！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));
        return 0;
    }

    //建立到配置文件的连接
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInputStream, wxConvUTF8);

    //读取配置文件->内存
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


    //打开配置文件
    wxFileOutputStream ConfigOutputStream(wxT("ngpodwc.ini"));
    if(!ConfigOutputStream.Ok())//检查配置文件是否存在
    {
        wxString msgTitle("配置文件不存在！",*wxConvCurrent);
        wxString msgContext("找不到检查配置文件 ngpodwc.ini！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
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

    //保存到文件
    pFileConfig->Save(ConfigOutputStream, wxConvUTF8);
    ConfigOutputStream.Close();

    return 1;
}
