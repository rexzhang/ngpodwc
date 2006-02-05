#include <wx/datetime.h>

struct ngpodwcConfig
{
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
    wxSize ScreenSize;
};

struct PodPictrueInfo
{
    wxChar Title[100];
    wxChar PodDate[20];
    wxChar Where[80];
    wxChar When[80];
    wxChar Who[80];
    wxChar Disc[254];
    wxChar Related[254];
    wxChar PhotoName[80];
};

enum WallpaperStyle
{
    Tiled=1, Centered=2, Stretched=3
};


bool getPodInfo(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo);
bool outputScreenPicture(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo);



// ----------------------------------------------------------------------------
// FUNCTION USED FOR HANDLING/DISPLAYING ERRORS
// ----------------------------------------------------------------------------
// Very generic error handling function.
// If a connection to the database is passed in, then we retrieve all the
// database errors for the connection and add them to the displayed message
int HandleError(wxString errmsg, wxDb *pDb=NULL)
{
    // Retrieve all the error message for the errors that occurred
    wxString allErrors;
    if (!pDb == NULL)
        // Get the database errors and append them to the error message
        allErrors = wxDbLogExtendedErrorMsg(errmsg.c_str(), pDb, 0, 0);
    else
        allErrors = errmsg;

    // Do whatever you wish with the error message here
    // wxLogDebug() is called inside wxDbLogExtendedErrorMsg() so this
    // console program will show the errors in the console window,
    // but these lines will show the errors in RELEASE builds also
    //wxFprintf(stderr, wxT("\n%s\n"), allErrors.c_str());
    //fflush(stderr);

    wxSafeShowMessage(errmsg,allErrors);

    return 1;
}

// ----------------------------------------------------------------------------
//!�ڸ�����tm���ڽṹ���ƶ���+����ƶ� / -��ǰ�ƶ���ָ����һ������
// ----------------------------------------------------------------------------
//
bool tmSeekDays(int seek, tm *pTmIn)
{
    tm *pTmTemp;
    time_t time_tTemp;


    //ת����time_t��ʽ
    time_tTemp = mktime(pTmIn);

    //����seek�������
    time_tTemp += seek*(24*60*60);

    //ת����tm�ṹ
    pTmTemp = localtime(&time_tTemp);

    pTmIn->tm_year = pTmTemp->tm_year;
    pTmIn->tm_mon = pTmTemp->tm_mon;
    pTmIn->tm_mday = pTmTemp->tm_mday;

    return 1;
}

// ----------------------------------------------------------------------------
//!�ڸ��������ڻ������ƶ�һ��ָ��������
// ----------------------------------------------------------------------------
//
bool seekDays(int seek, int *year, int *month, int *day)
{
    //ת����������tm��ʽ
    tm tmIn;
    tmIn.tm_sec = 0;
    tmIn.tm_min = 0;
    tmIn.tm_hour = 0;
    tmIn.tm_mday = *day;
    tmIn.tm_mon = *month;
    tmIn.tm_year = *year - 1900;
    tmIn.tm_wday = 0;
    tmIn.tm_yday = 0;
    tmIn.tm_isdst = 0;

    //
    tm *pTmTemp;
    time_t time_tTemp;

    //ת��tm��time_t��ʽ
    time_tTemp = mktime(&tmIn);

    //����seek�������
    time_tTemp += seek*(24*60*60);

    //ת��time_t��tm�ṹ
    pTmTemp = localtime(&time_tTemp);

    //���ò��裬������
    /*
    tmIn.tm_year = pTmTemp->tm_year;
    tmIn.tm_mon = pTmTemp->tm_mon;
    tmIn.tm_mday = pTmTemp->tm_mday;
    */

    *year = pTmTemp->tm_year + 1900;
    *month = pTmTemp->tm_mon;
    *day = pTmTemp->tm_mday;

    return 1;
}

// ----------------------------------------------------------------------------
//!��ע�����ָ������ͼƬλ�ã�ͼƬ��ʾ��ʽ
//!����ʾϵͳˢ��Ļ�Ա���ʾ���趨�ı���ͼƬ
//!MSW�汾
// ----------------------------------------------------------------------------
//
bool setWallpaperRegInfo(wxString WallpaperPathAndName)
{
    //�����ע���
    wxRegKey *pRegKey = new wxRegKey(wxT("HKEY_CURRENT_USER\\Control Panel\\Desktop"));
    if( !pRegKey->Exists() )
    {
        wxSafeShowMessage(wxT("Reg ERROR!"), wxT("Reg ERROR!"));
    }

    /*
    //Debug Info
    wxString msg;
    pRegKey->QueryValue(wxT("Wallpaper"),msg);
    wxSafeShowMessage(msg,msg);
    */

    //����ͼƬ��ʾ��ʽ
    WallpaperStyle style;
    style = Centered;
    switch( style )
    {
        case Stretched ://����
        pRegKey->SetValue(wxT("WallpaperStyle"), 2);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Centered ://����
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Tiled ://ƽ��
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 1);
        break;
    }

    //����ͼƬλ��
    pRegKey->SetValue(wxT("Wallpaper"), WallpaperPathAndName);

    //�ر�ע���
    pRegKey->Close();

    //��ʾϵͳˢ����Ļ

    /*
    //����ʹ�÷���
    //!http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/systemparametersinfo.asp
    //SPI_GETDESKWALLPAPER == get
    //SPI_SETDESKWALLPAPER
    char path[254]="c:\\winnt\\pod_wallpaper.bmp";//!
    //char path[254]="";
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    //ת���ɵ�ǰ����ASCII��ʽ
    char path[254]="";
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

    /*
    //Unicode �汾 ����������
    wxChar wxpath = wxt("");
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));

    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    return 1;
}
