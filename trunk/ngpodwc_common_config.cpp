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
//!config类初始化
//---------------------------------------------------------------------------
void ngpodwcConfig::Init()
{
    ConfigFileName = wxT("ngpodwc.ini");
    SetConfigFilePath(wxEmptyString);//ConfigFile = wxEmptyString + ConfigFileName;

    //先重置config为默认值,作为补充（兼容升级后配置信息增加的情况）
    SetDefault();

    //config。ini只初始化为默认参数，不读入文件
}

//---------------------------------------------------------------------------
//!config类配置文件存储路径设置
//---------------------------------------------------------------------------
void ngpodwcConfig::SetConfigFilePath(wxString configFullPath)
{
    if (configFullPath == wxEmptyString)
        ConfigFile = ConfigFileName;
    else
        ConfigFile = configFullPath + wxT("\\") +ConfigFileName;
}

//---------------------------------------------------------------------------
//!config类配置文件存储文件名（全路径）获取
//---------------------------------------------------------------------------
wxString ngpodwcConfig::GetConfigFile()
{
    return ConfigFile;
}

//---------------------------------------------------------------------------
//!重置config为默认值
//---------------------------------------------------------------------------
void ngpodwcConfig::SetDefault()
{
    ///////////////////
    PodBasePath = wxEmptyString;
    PodDatabaseName = wxT("pod.mdb");//wxEmptyString;

    PodPictureMode = wxEmptyString;
    PodPicturePath = wxT("POD\\pictures\\lg_wallpaper");

    //2001-1-14后有断档，所以直接从2001-4-21开始
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
//!读取配置信息到内存
//---------------------------------------------------------------------------
bool ngpodwcConfig::ReadConfig()
{
    //打开配置文件
    wxFileInputStream ConfigInputStream(ConfigFile);
    if(!ConfigInputStream.Ok())//检查配置文件是否存在
    {
        //告警
        //wxString msgTitle("配置文件不存在！",*wxConvCurrent);
        wxString msgTitle(wxT("lost .INI file"));
        wxString msgContext = wxT("can't found : ") + ConfigFile;
        //wxString msgContext("找不到检查配置文件 ngpodwc.ini！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        //wxString msgContext;
        //msgContext.Printf(wxT("找不到检查配置文件:\n%s\n请运行 ngpodcc.exe 进行初始化操作！"),ConfigFile);
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
//!将内存中的配置信息写回配置文件
//---------------------------------------------------------------------------
bool ngpodwcConfig::WriteConfig()
{


    //打开配置文件
    wxFileOutputStream ConfigOutputStream(ConfigFile);
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

    //保存到文件
    pFileConfig->Save(ConfigOutputStream, wxConvUTF8);
    ConfigOutputStream.Close();

    return 1;
}


