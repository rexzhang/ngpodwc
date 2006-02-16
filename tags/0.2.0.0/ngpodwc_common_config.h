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
    //�๹�캯��
    ngpodwcConfig();
    //���ʼ������
    void Init();

    //���Ա����
    bool ReadConfig();
    bool WriteConfig();
    void SetDefault();

    //���Ա����
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    wxDateTime PodDate;
    int PodYear;
    int PodMonth;
    int PodDays;

    int ScreenWidth;
    int ScreenHeight;
    //    wxSize ScreenSize;

    //////////
    wxString ScreenPicturePath;
    wxString ScreenPictureName;
};
