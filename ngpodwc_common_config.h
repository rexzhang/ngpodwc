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
#include <wx/string.h>


//---------------------------------------------------------------------------
//!
//---------------------------------------------------------------------------
class ngpodwcConfig
{
public:
    //类构造函数
    ngpodwcConfig();
    //类初始化函数
    void Init();

    //类成员函数
    void SetConfigFilePath(wxString configFullPath);
    void SetDefault();

    wxString GetConfigFile();

    bool ReadConfig();
    bool WriteConfig();

    //类成员变量
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    wxDateTime PodDate;
    /*
    int PodYear;
    int PodMonth;
    int PodDays;
    */

    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;

    //////////
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    bool Locked;
    ///////////
private:
    wxString ConfigFile;//Full Path + FileName
    wxString ConfigFileName;
};
