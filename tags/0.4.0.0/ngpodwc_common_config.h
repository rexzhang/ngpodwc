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

//使用宏变量定义图片来源
//按wxChoice的编号原则
#define PICTURESOURCE_LOCALFILE 0
#define PICTURESOURCE_NGPOD 1


//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
class ngpodwcConfig
{
public:
    //类构造函数
    ngpodwcConfig();
    virtual ~ngpodwcConfig();
    //类初始化函数
    void Init();

    //类成员函数
    void SetConfigFilePath(wxString configFullPath);
    void SetDefault();

    wxString GetConfigFile();

    bool ReadConfig();
    bool WriteConfig();

    //类成员变量--------------
    int PictureSource;

    //NGPOD相关
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    wxDateTime PodDate;

    //本地图片资源信息
    wxString LocalPicturePath;

    //本地显示器/桌面相关
    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    //图片处理相关
    bool ShowDisc;

    //程序控制相关
    bool PauseChangeWallpaper;//old-----bool Locked;
    bool ShowSplash;

protected:

private:
    //config配置文件路径，文件名等信息
    wxString ConfigFile;//Full Path + FileName
    wxString ConfigFileName;
};

#endif // COMMON_CONFIG_H
