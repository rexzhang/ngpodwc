
/*
#include <wx/msgdlg.h>
#include <wx/log.h>

#include <wx/datetime.h>

#include <wx/file.h>

//#include <ctime>
#include <time.h>

//#include "ngpodwc.h"
*/
#include <wx/splash.h>
//-------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ngpodwc.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "ngpodwc.h"

////@begin XPM images
////@end XPM images

/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( NgpodwcApp )
////@end implement app

/*!
 * NgpodwcApp type definition
 */

IMPLEMENT_CLASS( NgpodwcApp, wxApp )

/*!
 * NgpodwcApp event table definition
 */

BEGIN_EVENT_TABLE( NgpodwcApp, wxApp )

////@begin NgpodwccApp event table entries
////@end NgpodwccApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for NgpodwcApp
 */

NgpodwcApp::NgpodwcApp()
{}

/*!
 * Initialisation for NgpodwccApp
 */

bool NgpodwcApp::OnInit()
{

    wxImage::AddHandler(new wxBMPHandler);
    wxImage::AddHandler(new wxJPEGHandler);
    wxImage::AddHandler(new wxPNGHandler);
    //wxImage::AddHandler(new wxXPMHandler);

    //ngpodwcc_MainFrame* mainWindow = new ngpodwcc_MainFrame( NULL, ID_FRAME_MAIN );
    //mainWindow->Show(true);

    //wxApp::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE, "program");

    wxBitmap bitmap;
    wxSplashScreen *splash = NULL;
    if (bitmap.LoadFile(wxT("art/splash.png"), wxBITMAP_TYPE_PNG))
    {
        //��ʾSplashͼƬ
        splash= new wxSplashScreen(bitmap,
                                   wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                   6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
                                   wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR);//|wxSTAY_ON_TOP);
    }
    //wxApp::
    wxYield();

    //��ȡ�����ļ�

    config.ReadConfig();

    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ�����
    //PodPictrueInfo pictureInfo;
    //if(!getPodInfo(&config, &pictureInfo))
    if(!pictureInfo.GetInfo(config.PodBasePath + wxT("\\") + config.PodDatabaseName, config.PodDate))
    {
        wxString msgTitle("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���",*wxConvCurrent);
        wxString msgContext("��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ����ƴ���\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    /*
    //Debug Info
    wxSafeShowMessage(config.PodBasePath + wxT("\\")
                      + config.PodPicturePath + wxT("\\")
                      + pictureInfo.PhotoName,
                      config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName);
    */

    //����ͼƬ�������ָ��Ŀ¼
    if(!outputScreenPicture(&config, &pictureInfo))
    {
        wxString msgTitle("ͼƬCreate Error����",*wxConvCurrent);
        wxString msgContext("ͼƬCreate Error����\n��....XXXX.......������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    //�趨ͼƬ������
    setWallpaperRegInfo(config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName);

    //������Ϣ++
    seekDays(1, &(config.PodDate));
    //����++���������Ϣ�������ļ�
    config.WriteConfig();

    /*
    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return 0;
    */

    wxBell();

    return true;
}

/*!
 * Cleanup for NgpodwcApp
 */
int NgpodwcApp::OnExit()
{
    ////@begin NgpodwccApp cleanup
    return wxApp::OnExit();
    ////@end NgpodwccApp cleanup
}

// ----------------------------------------------------------------------------
// FUNCTION USED FOR MAIN <input point>
// ----------------------------------------------------------------------------
// return ?? = true/Finish
/*
main()
{

}
*/

// ----------------------------------------------------------------------------
// FUNCTION USED FOR xxxxxxx wxImage<wxWidgets>
// ----------------------------------------------------------------------------
// return 1 = true/Finish
bool NgpodwcApp::outputScreenPicture(ngpodwcConfig *pConfig, ngpodinfo *pPodPictureInfo)
{
    wxImage PodImage, ScreenImage;

    if (!PodImage.LoadFile(pConfig->PodBasePath + wxT("\\") + pConfig->PodPicturePath
                           + wxT("\\") + pPodPictureInfo->PhotoName, wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Can't load JPG image"), pPodPictureInfo->PhotoName);
        return 0;
    }

    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_8BPP_GREY);
    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_24BPP);


    if( (PodImage.GetWidth() != pConfig->ScreenWidth)
            && (PodImage.GetHeight() != pConfig->ScreenHeight) )
        //���ԭͼƬ�ߴ�����Ļ�ߴ粻������������С
    {
        wxString msg;
        /*
        //Debug Info
        msg.Printf(wxT("From : %i x %i\nTo   : %i x %i"),
                   PodImage.GetWidth(), PodImage.GetHeight(), pConfig->ScreenWidth, pConfig->ScreenHeight);
        wxSafeShowMessage(wxT("change size"), msg);
        */
        //wxSize ScreenSize(pConfig->ScreenWidth, pConfig->ScreenHeight);
        //PodImage.Resize(ScreenSize, xxx,
        PodImage.Rescale(pConfig->ScreenWidth, pConfig->ScreenHeight);
    }
    else
    {
        ScreenImage = PodImage;
    }

    if(!PodImage.SaveFile(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName,
                          wxBITMAP_TYPE_BMP))
    {
        wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));
        return 0;
    };

    return 1;
}




