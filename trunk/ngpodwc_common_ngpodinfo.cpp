#include "ngpodwc_common_ngpodinfo.h"

ngpodinfo::ngpodinfo()
{
    //ctor
}

ngpodinfo::~ngpodinfo()
{
    //dtor
}

// ----------------------------------------------------------------------------
// FUNCTION USED FOR HANDLING/DISPLAYING ERRORS
// ----------------------------------------------------------------------------
// Very generic error handling function.
// If a connection to the database is passed in, then we retrieve all the
// database errors for the connection and add them to the displayed message
int ngpodinfo::HandleError(wxString errmsg)
{
    // Retrieve all the error message for the errors that occurred
    wxString allErrors;
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

int ngpodinfo::HandleError(wxString errmsg, wxDb *pDb)
{
    // Retrieve all the error message for the errors that occurred
    wxString allErrors;
    // Get the database errors and append them to the error message
    allErrors = wxDbLogExtendedErrorMsg(errmsg.c_str(), pDb, 0, 0);

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
// FUNCTION USED FOR xxxxxxx
// ----------------------------------------------------------------------------
// return 1 = true/Finish
//bool ngpodinfo::getPodInfo(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo)
bool ngpodinfo::GetInfo(wxString PodDBName, wxDateTime PodDateSelected)
{
    wxDbConnectInf  *DbConnectInf    = NULL;    // DB connection information

    wxDb            *PodDB              = NULL;    // Database connection

    wxDbTable       *table           = NULL;    // Data table to access
    //const wxChar tableName[] = wxT("POD"); // Name of database table

    DbConnectInf = new wxDbConnectInf(0, wxT(""), wxT(""), wxT(""));//这里定义的内容基本没用

    //定义数据库连接
    //PodDB = new wxDb;//!!必须的一步
    PodDB = new wxDb(DbConnectInf->GetHenv());//!!必须的一步

    bool DBfailOnDataTypeUnsupported=!true;//!!目的？用处？

    //透过Driver的方式打开ODBC(正式的打开ODBC操作)
    if(!PodDB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=") + PodDBName + wxT(";UID=admin;"),
                    DBfailOnDataTypeUnsupported))
    {
        if (PodDB->IsOpen())
        {
            // Connection is open, but the initialization of
            // datatypes and parameter settings failed
            wxSafeShowMessage(PodDBName,
                              wxT("Connection is open, but the initialization of datatypes and parameter settings failed"));
            return 0;
        }
        else
        {
            // Error opening datasource
            HandleError(wxT("DB ENV ERROR: Cannot allocate ODBC env handle"), NULL);
            wxSafeShowMessage(PodDBName,
                              wxT("Error opening datasource"));
            return 0;
        }
    }


    //const wxString tableName = wxT("POD");
    const UWORD numTableColumns = 8;       // Number table columns
    //定义表部分
    //table = new wxDbTable(PodDB, wxT("POD"), numTableColumns, wxT(""), wxDB_QUERY_ONLY, wxT(""));
    table = new wxDbTable(PodDB, wxT("POD"), numTableColumns, wxT(""), wxDB_QUERY_ONLY, wxT(""));

    //清空数据
    wxStrcpy(Title, wxT(""));
    wxStrcpy(PodDate, wxT(""));//变量结构变了
    wxStrcpy(Where, wxT(""));
    wxStrcpy(When, wxT(""));
    wxStrcpy(Who, wxT(""));
    wxStrcpy(Disc, wxT(""));
    wxStrcpy(Related, wxT(""));
    wxStrcpy(PhotoName, wxT(""));

    //time_t PodTime_TT=0;

    table->SetColDefs(0, wxT("Pod_Title"), DB_DATA_TYPE_VARCHAR, Title, SQL_C_WXCHAR, sizeof(Title), true, true);
    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, PodDate, SQL_C_WXCHAR, sizeof(PodDate), true, true);
    //    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, &PodTime_TT, SQL_C_DATE, sizeof(PodTime_TT), true, true);
    table->SetColDefs(2, wxT("Pod_Where"), DB_DATA_TYPE_VARCHAR, Where, SQL_C_WXCHAR, sizeof(Where), true, true);
    table->SetColDefs(3, wxT("Pod_When"), DB_DATA_TYPE_VARCHAR, When, SQL_C_WXCHAR, sizeof(When), true, true);
    table->SetColDefs(4, wxT("Pod_Who"), DB_DATA_TYPE_VARCHAR, Who, SQL_C_WXCHAR, sizeof(Who), true, true);
    table->SetColDefs(5, wxT("Pod_Disc"), DB_DATA_TYPE_VARCHAR, Disc, SQL_C_WXCHAR, sizeof(Disc), true, true);
    table->SetColDefs(6, wxT("Pod_Related"), DB_DATA_TYPE_VARCHAR, Related, SQL_C_WXCHAR, sizeof(Related), true, true);
    table->SetColDefs(7, wxT("Pod_Photo"), DB_DATA_TYPE_VARCHAR, PhotoName, SQL_C_WXCHAR, sizeof(PhotoName), true, true);

    //打开表
    if (!table->Open())
    {
        wxSafeShowMessage(PodDBName,
                          wxT("An error occurred opening (setting up) the table"));
    }

    //table->SetWhereClause(wxT("Pod_When = '1982'"));//!OK

    //生成ODBC-Access的Date数字格式
    wxString msg;
    //msg.Printf(wxT("Pod_Date = %u"),wxDateTicks(pConfig->PodYear, pConfig->PodMonth, pConfig->PodDays));
    msg.Printf(wxT("Pod_Date = %u"),wxDateTicks(PodDateSelected));
    table->SetWhereClause(msg);
    //table->SetWhereClause(wxT("Pod_Date = '2005-08-23 00:00:00'"));

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
        HandleError(wxT("QUERY ERROR: "), table->GetDb());
        return 0;
    }

    while (table->GetNext())
    {
        wxString         msg;                       // Used for display messages
        msg.Printf(wxT("Row #% lu --\nTitle : %s\nPodDate : %s\nWhere : %s\nWhen : %s\nWho : %s\nDisc : %s\nRelated : %s\nPhotoName :%s"),
                   table->GetRowNum(),
                   Title,
                   PodDate,
                   Where,
                   When,
                   Who,
                   Disc,
                   Related,
                   PhotoName
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
                       Title,
                       PodDate,
                       Where,
                       When,
                       Who,
                       Disc,
                       Related,
                       PhotoName
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
    //wxDELETE(table);

    // Free the cached connection
    // (meaning release it back in to the cache of datasource
    // connections) for the next time a call to wxDbGetConnection()
    // is made.
    //wxDbFreeConnection(PodDB);
    //PodDB = NULL;

    // -----------------------------------------------------------------------
    // CLEANUP BEFORE EXITING APP
    // -----------------------------------------------------------------------
    // The program is now ending, so we need to close
    // any cached connections that are still being
    // maintained.
    //wxDbCloseConnections();

    // Release the environment handle that was created
    // for use with the ODBC datasource connections
    //wxDELETE(DbConnectInf);

    return 1;//获取成功
}

