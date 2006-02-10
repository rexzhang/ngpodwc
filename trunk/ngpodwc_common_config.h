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
    bool ReadConfig();
    bool WriteConfig();

    //类成员
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    int PodYear;
    int PodMonth;
    int PodDays;

    //////////
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;
};
