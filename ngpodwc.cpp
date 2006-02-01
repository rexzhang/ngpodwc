#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/msgdlg.h>
#include <wx/log.h>

#include <wx/datetime.h>

//#include <ctime>
#include <time.h>

//#include <wx/rawbmp.h>

#include "ngpodwc.h"



// ----------------------------------------------------------------------------
// FUNCTION USED FOR MAIN <input point>
// ----------------------------------------------------------------------------
// return ?? = true/Finish
main()
{

    //打开配置文件
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    if(!ConfigInStream.Ok())//检查配置文件是否存在
    {
        wxString msgTitle("配置文件不存在！",*wxConvCurrent);
        wxString msgContext("找不到检查配置文件 ngpodwc.ini！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));

        return 1;
    }

    //建立到配置文件的连接
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInStream, wxConvUTF8);

    //读取配置文件->内存
    ngpodwcConfig config;
    config.PodBasePath = pFileConfig->Read(wxT("PodBasePath"));

    config.PodDatabaseName = pFileConfig->Read(wxT("PodDatabaseName"));
    config.PodPicturePath = pFileConfig->Read(wxT("PodPicturePath"));

    pFileConfig->Read(wxT("PodYear"), &(config.PodYear));
    pFileConfig->Read(wxT("PodMonth"), &(config.PodMonth));
    pFileConfig->Read(wxT("PodDays"), &(config.PodDays));

    config.ScreenPicturePath = pFileConfig->Read(wxT("ScreenPicturePath"));
    config.ScreenPictureName = pFileConfig->Read(wxT("ScreenPictureName"));
    pFileConfig->Read(wxT("ScreenWidth"), &(config.ScreenWidth));
    pFileConfig->Read(wxT("ScreenHeight"), &(config.ScreenHeight));

    //wxSafeShowMessage(config.PodBasePath,config.PodDatabaseName);

    //获取POD 图片描述信息以及图片文件名称
    PodPictrueInfo pictureInfo;
    if(!getPodInfo(&config, &pictureInfo))
    {
        wxString msgTitle("获取POD 图片描述信息以及图片文件名称错误！",*wxConvCurrent);
        wxString msgContext("获取POD 图片描述信息以及图片文件名称错误！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    wxSafeShowMessage(config.PodBasePath + wxT("\\")
                      + config.PodPicturePath + wxT("\\")
                      + pictureInfo.PhotoName,
                      config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName);

    if(!outputScreenPicture(&config, &pictureInfo))
    {
        wxString msgTitle("图片Create Error错误！",*wxConvCurrent);
        wxString msgContext("图片Create Error错误！\n请....XXXX.......操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return 1;
    }

    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return 0;

    return 0;
}


// ----------------------------------------------------------------------------
// FUNCTION USED FOR xxxxxxx wxImage<wxWidgets>
// ----------------------------------------------------------------------------
// return 1 = true/Finish
bool outputScreenPicture(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo)
{
    wxImage PodImage;
    //wxInitAllImageHandlers();
    wxImage::AddHandler(new wxBMPHandler);
    wxImage::AddHandler(new wxJPEGHandler);
    wxImage::AddHandler(new wxPNGHandler);

    //wxImage PodImage(wxT("MM6664_421.png"), wxBITMAP_TYPE_PNG);
    if (!PodImage.LoadFile(pConfig->PodBasePath + wxT("\\") + pConfig->PodPicturePath
                           + wxT("\\") + pPodPictureInfo->PhotoName, wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Can't load JPG image"), pPodPictureInfo->PhotoName);
        return 0;
    }

    //wxBitmap PictureBitmap;//(&PodImage);

    //wxImage ScreenImage = PictureBitmap.ConvertToImage();

    /*
        if(!PictureBitmap.LoadFile(pConfig->ScreenPicturePath + wxT("\\")
                                   + wxT("MM6664_421.bmp"), wxBITMAP_TYPE_BMP))
        {
            wxSafeShowMessage(wxT("Can't load BMP image"),wxT("Can't load BMP image"));
            return 0;
        }
    */
    /*
        // Make a palette
        unsigned char* red = new unsigned char[256];
        unsigned char* green = new unsigned char[256];
        unsigned char* blue = new unsigned char[256];
        for (size_t i = 0; i < 256; i ++)
        {
            red[i] = green[i] = blue[i] = i;
        }
        wxPalette palette(256, red, green, blue);
        // Set the palette and the BMP depth
        PodImage.SetPalette(palette);

        PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT, wxBMP_8BPP_PALETTE);
    */
    //PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_8BPP_GREY);
    PodImage.SetOption(wxIMAGE_OPTION_BMP_FORMAT,wxBMP_24BPP);
    //if(!PodImage.SaveFile(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName,
    //                      wxBITMAP_TYPE_BMP))
    if(!PodImage.SaveFile(pConfig->ScreenPicturePath + wxT("\\") + pConfig->ScreenPictureName,
                          wxBITMAP_TYPE_BMP))
        //    if(!PodImage.SaveFile(config.ScreenPicturePath + wxT("\\") + wxT("screen.jpg"),
        //                        wxBITMAP_TYPE_JPEG))
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

    //wxDbConnectInf DbConnectInf;
    DbConnectInf = new wxDbConnectInf(0, wxT(""), wxT(""), wxT(""));//这里定义的内容基本没用
    //DbConnectInf = new wxDbConnectInf;

    //定义数据库连接
    //PodDB = new wxDb;//!!必须的一步
    PodDB = new wxDb(DbConnectInf->GetHenv());//!!必须的一步

    bool DBfailOnDataTypeUnsupported=!true;//!!目的？用处？

    //透过Driver的方式打开ODBC(正式的打开ODBC操作)
    //if(DB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=D:\\pod.mdb;UID=admin;"),DBfailOnDataTypeUnsupported))
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
    //定义表部分
    table = new wxDbTable(PodDB, wxT("POD"), numTableColumns, wxT(""), wxDB_QUERY_ONLY, wxT(""));

    //清空数据
    wxStrcpy(pPodPictureInfo->Title, wxT(""));
    wxStrcpy(pPodPictureInfo->PodDate, wxT(""));
    wxStrcpy(pPodPictureInfo->Where, wxT(""));
    wxStrcpy(pPodPictureInfo->When, wxT(""));
    wxStrcpy(pPodPictureInfo->Who, wxT(""));
    wxStrcpy(pPodPictureInfo->Disc, wxT(""));
    wxStrcpy(pPodPictureInfo->Related, wxT(""));
    wxStrcpy(pPodPictureInfo->PhotoName, wxT(""));

    time_t PodTime_TT=0;

    table->SetColDefs(0, wxT("Pod_Title"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Title, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Title), true, true);
    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, pPodPictureInfo->PodDate, SQL_C_WXCHAR, sizeof(pPodPictureInfo->PodDate), true, true);
    //    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, &PodTime_TT, SQL_C_DATE, sizeof(PodTime_TT), true, true);
    table->SetColDefs(2, wxT("Pod_Where"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Where, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Where), true, true);
    table->SetColDefs(3, wxT("Pod_When"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->When, SQL_C_WXCHAR, sizeof(pPodPictureInfo->When), true, true);
    table->SetColDefs(4, wxT("Pod_Who"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Who, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Who), true, true);
    table->SetColDefs(5, wxT("Pod_Disc"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Disc, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Disc), true, true);
    table->SetColDefs(6, wxT("Pod_Related"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->Related, SQL_C_WXCHAR, sizeof(pPodPictureInfo->Related), true, true);
    table->SetColDefs(7, wxT("Pod_Photo"), DB_DATA_TYPE_VARCHAR, pPodPictureInfo->PhotoName, SQL_C_WXCHAR, sizeof(pPodPictureInfo->PhotoName), true, true);

    //打开表
    if (!table->Open())
    {
        wxSafeShowMessage(pConfig->PodBasePath + pConfig->PodDatabaseName,
                          wxT("An error occurred opening (setting up) the table"));
    }

    //table->SetWhereClause(wxT("Pod_When = '1982'"));//!OK

    //生成ODBC-Access的Date数字格式
    //用tm格式生成wxDateTime格式，然后使用GetTicks转换成time_t格式
    //再除以(24*60*60) 加上25539值
    tm PodTm;
    wxDateTime PodDateTime;
    time_t PodTime_t;
    PodTm.tm_sec = 0;
    PodTm.tm_min = 0;
    PodTm.tm_hour = 0;
    PodTm.tm_mday = pConfig->PodDays;
    PodTm.tm_mon = pConfig->PodMonth;
    //PodTm.tm_year = 2004-1900;
    PodTm.tm_year = pConfig->PodYear - 1900;
    PodTm.tm_wday = 0;
    PodTm.tm_yday = 0;
    PodTm.tm_isdst = 0;
    PodDateTime = wxDateTime::wxDateTime(PodTm);
    PodTime_t = PodDateTime.GetTicks();
    PodTime_t = PodTime_t/(24*60*60) + 25539;

    //table->SetWhereClause(wxT("Pod_Date <= 40000 AND Pod_Date >= 37999"));
    wxString msg;
    msg.Printf(wxT("Pod_Date = %u"),PodTime_t);
    table->SetWhereClause(msg);
    //table->SetWhereClause(wxT("Pod_Date = 2001/03/13"));

    //按照PodDate字段排序
    table->SetOrderByClause(wxT("Pod_Date"));

    /*
    int PodDBTotalNumber = table->Count();
    wxString msg;
    msg.Printf(wxT(" table-Count() = %i"), PodDBTotalNumber);
    wxSafeShowMessage(msg,msg);
    */

    //根据上面的限定信息执行查询操作
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
        //检查表操作/现实获取的POD信息
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



    return 1;//获取成功
}


