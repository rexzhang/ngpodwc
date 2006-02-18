#include <wx/datetime.h>

#include "ngpodwc_common_config.h"
#include "ngpodwc_common_datetime.h"
#include "ngpodwc_common_screen.h"
#include "ngpodwc_common_ngpodinfo.h"


#ifndef _NGPODWC_H_
#define _NGPODWC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwc.h"
#endif

/*!
 * Includes
 */


/*!
 * Forward declarations
 */


/*!
 * Control identifiers
 */


/*!
 * NgpodwcApp class declaration
 */

class NgpodwcApp: public wxApp
{
    DECLARE_CLASS( NgpodwcApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    NgpodwcApp();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin NgpodwccApp event handler declarations

////@end NgpodwccApp event handler declarations

////@begin NgpodwccApp member function declarations

////@end NgpodwccApp member function declarations
//bool getPodInfo(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo);
bool outputScreenPicture(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo);


////@begin NgpodwccApp member variables
////@end NgpodwccApp member variables

    ngpodwcConfig config;
    ngpodinfo pictureInfo;
};

/*!
 * Application instance declaration
 */


DECLARE_APP(NgpodwcApp)

#endif
    // _NGPODWC_H_

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
