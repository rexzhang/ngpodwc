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
//!在给定的tm日期结构中移动（+向后移动 / -向前移动）指定的一个日期
// ----------------------------------------------------------------------------
//
bool tmSeekDays(int seek, tm *pTmIn)
{
    tm *pTmTemp;
    time_t time_tTemp;


    //转换到time_t格式
    time_tTemp = mktime(pTmIn);

    //加上seek天的秒数
    time_tTemp += seek*(24*60*60);

    //转换到tm结构
    pTmTemp = localtime(&time_tTemp);

    pTmIn->tm_year = pTmTemp->tm_year;
    pTmIn->tm_mon = pTmTemp->tm_mon;
    pTmIn->tm_mday = pTmTemp->tm_mday;

    return 1;
}

// ----------------------------------------------------------------------------
//!在给定的日期基础上移动一个指定的日期
// ----------------------------------------------------------------------------
//
bool seekDays(int seek, int *year, int *month, int *day)
{
    //转换年月日至tm格式
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

    //转换tm到time_t格式
    time_tTemp = mktime(&tmIn);

    //加上seek天的秒数
    time_tTemp += seek*(24*60*60);

    //转换time_t到tm结构
    pTmTemp = localtime(&time_tTemp);

    //无用步骤，范例用
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
//!在注册表中指定背景图片位置，图片显示方式
//!并提示系统刷屏幕以便显示新设定的背景图片
//!MSW版本
// ----------------------------------------------------------------------------
//
bool setWallpaperRegInfo(wxString WallpaperPathAndName)
{
    //打开相关注册表
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

    //设置图片显示方式
    WallpaperStyle style;
    style = Centered;
    switch( style )
    {
        case Stretched ://拉伸
        pRegKey->SetValue(wxT("WallpaperStyle"), 2);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Centered ://居中
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 0);
        break;
        case Tiled ://平铺
        pRegKey->SetValue(wxT("WallpaperStyle"), 0);
        pRegKey->SetValue(wxT("TileWallpaper"), 1);
        break;
    }

    //设置图片位置
    pRegKey->SetValue(wxT("Wallpaper"), WallpaperPathAndName);

    //关闭注册表
    pRegKey->Close();

    //提示系统刷新屏幕

    /*
    //函数使用范例
    //!http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/systemparametersinfo.asp
    //SPI_GETDESKWALLPAPER == get
    //SPI_SETDESKWALLPAPER
    char path[254]="c:\\winnt\\pod_wallpaper.bmp";//!
    //char path[254]="";
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    //转换成当前编码ASCII格式
    char path[254]="";
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

    /*
    //Unicode 版本 ，还有问题
    wxChar wxpath = wxt("");
    strcpy(path,WallpaperPathAndName.mb_str(*wxConvCurrent));

    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);
    */

    return 1;
}
