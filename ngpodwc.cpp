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

    //wxBitmap bitmap(wxBITMAP(logo));

    wxBitmap bitmap;
    wxSplashScreen *splash = NULL;
    if (bitmap.LoadFile(wxT("art/splash.png"), wxBITMAP_TYPE_PNG))
    {
        //��ʾSplashͼƬ
        splash= new wxSplashScreen(bitmap,
                                   wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
                                   6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
                                   wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP);
    }
    //wxApp::
    wxYield();

    //��ȡ�����ļ�
    ngpodwcConfig config;
    config.ReadConfig();

    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ�����
    PodPictrueInfo pictureInfo;
    if(!getPodInfo(&config, &pictureInfo))
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
bool outputScreenPicture(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo)
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

// ----------------------------------------------------------------------------
// FUNCTION USED FOR xxxxxxx
// ----------------------------------------------------------------------------
// return 1 = true/Finish
bool getPodInfo(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo)
{
    wxDbConnectInf  *DbConnectInf    = NULL;    // DB connection information

    wxDb            *PodDB              = NULL;    // Database connection

    wxDbTable       *table           = NULL;    // Data table to access
    //const wxChar tableName[] = wxT("POD"); // Name of database table

    DbConnectInf = new wxDbConnectInf(0, wxT(""), wxT(""), wxT(""));//���ﶨ������ݻ���û��

    //�������ݿ�����
    //PodDB = new wxDb;//!!�����һ��
    PodDB = new wxDb(DbConnectInf->GetHenv());//!!�����һ��

    bool DBfailOnDataTypeUnsupported=!true;//!!Ŀ�ģ��ô���

    //͸��Driver�ķ�ʽ��ODBC(��ʽ�Ĵ�ODBC����)
    if(!PodDB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=") + pConfig->PodBasePath + wxT("\\") + pConfig->PodDatabaseName + wxT(";UID=admin;"),
                    DBfailOnDataTypeUnsupported))
    {
        if (PodDB->IsOpen())
        {
            // Connection is open, but the initialization of
            // datatypes and parameter settings failed
            wxSafeShowMessage(pConfig->PodBasePath + pConfig->PodDatabaseName,
                              wxT("Connection is open, but the initialization of datatypes and parameter settings failed"));
            return 0;
        }
        else
        {
            // Error opening datasource
            //return HandleError(wxT("DB ENV ERROR: Cannot allocate ODBC env handle"));
            wxSafeShowMessage(pConfig->PodBasePath + pConfig->PodDatabaseName,
                              wxT("Error opening datasource"));
            return 0;
        }
    }


    //const wxString tableName = wxT("POD");
    const UWORD numTableColumns = 8;       // Number table columns
    //�������
    table = new wxDbTable(PodDB, wxT("POD"), numTableColumns, wxT(""), wxDB_QUERY_ONLY, wxT(""));

    //�������
    wxStrcpy(pPodPictureInfo->Title, wxT(""));
    wxStrcpy(pPodPictureInfo->PodDate, wxT(""));
    wxStrcpy(pPodPictureInfo->Where, wxT(""));
    wxStrcpy(pPodPictureInfo->When, wxT(""));
    wxStrcpy(pPodPictureInfo->Who, wxT(""));
    wxStrcpy(pPodPictureInfo->Disc, wxT(""));
    wxStrcpy(pPodPictureInfo->Related, wxT(""));
    wxStrcpy(pPodPictureInfo->PhotoName, wxT(""));

    //time_t PodTime_TT=0;

    table->SetColDefs(0, wxT("Pod_Title"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Title, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Title), true, true);
    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, pPodPictureInfo->PodDate, SQL_C_WXCHAR, sizeof(pPodPictureInfo->PodDate), true, true);
    //    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, &PodTime_TT, SQL_C_DATE, sizeof(PodTime_TT), true, true);
    table->SetColDefs(2, wxT("Pod_Where"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Where, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Where), true, true);
    table->SetColDefs(3, wxT("Pod_When"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->When, SQL_C_WXCHAR, sizeof(pPodPictureInfo->When), true, true);
    table->SetColDefs(4, wxT("Pod_Who"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Who, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Who), true, true);
    table->SetColDefs(5, wxT("Pod_Disc"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Disc, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Disc), true, true);
    table->SetColDefs(6, wxT("Pod_Related"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Related, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Related), true, true);
    table->SetColDefs(7, wxT("Pod_Photo"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->PhotoName, SQL_C_WXCHAR, sizeof(pPodPictureInfo->PhotoName), true, true);

    //�򿪱�
    if (!table->Open())
    {
        wxSafeShowMessage(pConfig->PodBasePath + pConfig->PodDatabaseName,
                          wxT("An error occurred opening (setting up) the table"));
    }

    //table->SetWhereClause(wxT("Pod_When = '1982'"));//!OK

    //����ODBC-Access��Date���ָ�ʽ
    wxString msg;
    //msg.Printf(wxT("Pod_Date = %u"),wxDateTicks(pConfig->PodYear, pConfig->PodMonth, pConfig->PodDays));
    msg.Printf(wxT("Pod_Date = %u"),wxDateTicks(pConfig->PodDate));
    table->SetWhereClause(msg);
    //table->SetWhereClause(wxT("Pod_Date = '2005-08-23 00:00:00'"));

    //����PodDate�ֶ�����
    table->SetOrderByClause(wxT("Pod_Date"));

    /*
    int PodDBTotalNumber = table->Count();
    wxString msg;
    msg.Printf(wxT(" table-Count() = %i"), PodDBTotalNumber);
    wxSafeShowMessage(msg,msg);
    */

    //����������޶���Ϣִ�в�ѯ����
    if (!table->Query())
    {
        return HandleError(wxT("QUERY ERROR: "), table->GetDb());
        //return 0;
    }

    while (table->GetNext())
    {
        wxString         msg;                       // Used for display messages
        msg.Printf(wxT("Row #% lu --\nTitle : %s\nPodDate : %s\nWhere : %s\nWhen : %s\nWho : %s\nDisc : %s\nRelated : %s\nPhotoName :%s"),
                   table->GetRowNum(),
                   pPodPictureInfo->Title,
                   pPodPictureInfo->PodDate,
                   pPodPictureInfo->Where,
                   pPodPictureInfo->When,
                   pPodPictureInfo->Who,
                   pPodPictureInfo->Disc,
                   pPodPictureInfo->Related,
                   pPodPictureInfo->PhotoName
                  );
        //�������/��ʵ��ȡ��POD��Ϣ
        //wxSafeShowMessage(wxT("Pod_wxDbTable Test"),msg);
    }

    /*
        if(!table->GetNext())
        {
            wxString         msg;                       // Used for display messages
            msg.Printf(wxT("Row #% lu --\nTitle : %s\nPodDate : %s\nWhere : %s\nWhen : %s\nWho : %s\nDisc : %s\nRelated : %s\nPhotoName :%s"),
                       table->GetRowNum(),
                       pPodPictureInfo->Title,
                       pPodPictureInfo->PodDate,
                       pPodPictureInfo->Where,
                       pPodPictureInfo->When,
                       pPodPictureInfo->Who,
                       pPodPictureInfo->Disc,
                       pPodPictureInfo->Related,
                       pPodPictureInfo->PhotoName
                      );
            // Code to display 'msg' here
            wxSafeShowMessage(wxT("table->GetNext Error!"),msg);
            return 0;
        }
    */
    // -----------------------------------------------------------------------
    // TAKE CARE OF THE ODBC CLASS INSTANCES THAT WERE BEING USED
    // -----------------------------------------------------------------------
    // If the wxDbTable instance was successfully created
    // then delete it as we are done with it now.
    wxDELETE(table);

    // Free the cached connection
    // (meaning release it back in to the cache of datasource
    // connections) for the next time a call to wxDbGetConnection()
    // is made.
    wxDbFreeConnection(PodDB);
    PodDB = NULL;


    // -----------------------------------------------------------------------
    // CLEANUP BEFORE EXITING APP
    // -----------------------------------------------------------------------
    // The program is now ending, so we need to close
    // any cached connections that are still being
    // maintained.
    wxDbCloseConnections();

    // Release the environment handle that was created
    // for use with the ODBC datasource connections
    wxDELETE(DbConnectInf);



    return 1;//��ȡ�ɹ�
}


