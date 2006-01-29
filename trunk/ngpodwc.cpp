#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/msgdlg.h>
#include <wx/log.h>

#include "ngpodwc.h"

main()
{

    //打开配置文件
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    if(!ConfigInStream.Ok())//检查配置文件是否存在
    {
        wxString msgTitle("配置文件不存在",*wxConvCurrent);
        wxString msgContext("找不到检查配置文件 ngpodwc.ini\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));

        return 1;
    }

    //建立到配置文件的连接
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInStream, wxConvUTF8);

    //config->Write(wxT("DatabasePath"),wxT("d:\\"));

    //读取配置文件-〉内存
    ngpodwcConfig config;
    config.DatabasePath = pFileConfig->Read(wxT("DatabasePath"));
    config.DatabaseName = pFileConfig->Read(wxT("DatabaseName"));
    //wxSafeShowMessage(config.DatabasePath,config.DatabaseName);

    //获取POD 图片描述信息以及图片文件名称
    PodPictrueInfo pPictureInfo;
    if(!getPodInfo(config.DatabasePath, config.DatabaseName, &pPictureInfo))
    {
        wxSafeShowMessage(wxT("Error"),wxT("Error"));
    }




    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return 0;

    return 0;
}

bool getPodInfo(const wxString DatabasePath, const wxString DatabaseName, PodPictrueInfo *pPictureInfo)
//return 1 = true
{
    //wxSafeShowMessage(wxT("aaa"),DatabasePath + DatabaseName);

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
    if(!PodDB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=") + DatabasePath + DatabaseName + wxT(";UID=admin;"),
                    DBfailOnDataTypeUnsupported))
    {
        if (PodDB->IsOpen())
        {
            // Connection is open, but the initialization of
            // datatypes and parameter settings failed
            wxSafeShowMessage(DatabasePath +DatabaseName,
                              wxT("Connection is open, but the initialization of datatypes and parameter settings failed"));
            return 0;
        }
        else
        {
            // Error opening datasource
            //return HandleError(wxT("DB ENV ERROR: Cannot allocate ODBC env handle"));
            wxSafeShowMessage(DatabasePath + DatabaseName,
                              wxT("Error opening datasource"));
            return 0;
        }
    }


    //const wxString tableName = wxT("POD");
    const UWORD numTableColumns = 8;       // Number table columns
    //定义表部分
    table = new wxDbTable(PodDB, wxT("POD"), numTableColumns, wxT(""), wxDB_QUERY_ONLY, wxT(""));

    //清空数据
    wxStrcpy(pPictureInfo->Title, wxT(""));
    wxStrcpy(pPictureInfo->PodDate, wxT(""));
    wxStrcpy(pPictureInfo->Where, wxT(""));
    wxStrcpy(pPictureInfo->When, wxT(""));
    wxStrcpy(pPictureInfo->Who, wxT(""));
    wxStrcpy(pPictureInfo->Disc, wxT(""));
    wxStrcpy(pPictureInfo->Related, wxT(""));
    wxStrcpy(pPictureInfo->PhotoName, wxT(""));

    table->SetColDefs(0, wxT("Pod_Title"), DB_DATA_TYPE_VARCHAR, pPictureInfo->Title, SQL_C_WXCHAR, sizeof(pPictureInfo->Title), true, true);
    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, pPictureInfo->PodDate, SQL_C_WXCHAR, sizeof(pPictureInfo->PodDate), true, true);
    table->SetColDefs(2, wxT("Pod_Where"), DB_DATA_TYPE_VARCHAR, pPictureInfo->Where, SQL_C_WXCHAR, sizeof(pPictureInfo->Where), true, true);
    table->SetColDefs(3, wxT("Pod_When"), DB_DATA_TYPE_VARCHAR, pPictureInfo->When, SQL_C_WXCHAR, sizeof(pPictureInfo->When), true, true);
    table->SetColDefs(4, wxT("Pod_Who"), DB_DATA_TYPE_VARCHAR, pPictureInfo->Who, SQL_C_WXCHAR, sizeof(pPictureInfo->Who), true, true);
    table->SetColDefs(5, wxT("Pod_Disc"), DB_DATA_TYPE_VARCHAR, pPictureInfo->Disc, SQL_C_WXCHAR, sizeof(pPictureInfo->Disc), true, true);
    table->SetColDefs(6, wxT("Pod_Related"), DB_DATA_TYPE_VARCHAR, pPictureInfo->Related, SQL_C_WXCHAR, sizeof(pPictureInfo->Related), true, true);
    table->SetColDefs(7, wxT("Pod_Photo"), DB_DATA_TYPE_VARCHAR, pPictureInfo->PhotoName, SQL_C_WXCHAR, sizeof(pPictureInfo->PhotoName), true, true);

    //打开表
    if (!table->Open())
    {
        wxSafeShowMessage(DatabasePath + DatabaseName,
                          wxT("An error occurred opening (setting up) the table"));
    }

    //table->SetWhereClause(wxT("Pod_When = '1982'"));

    wxDateTime PodDate;// = "2005-3-3";
    PodDate.SetYear(2005);
    PodDate.SetMonth(3);
    PodDate.SetDay(3);


    table->SetWhereClause(wxT("Pod_Date = 2005-3-3"));

    //按照PodDate字段排序
    table->SetOrderByClause(wxT("Pod_Title"));

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

    //wxSafeShowMessage(wxT("Pod_Title"),pPictureInfo->Title);
    //table->GetNext();
    //table->GetFirst();


    while (table->GetNext())
    {
        wxString         msg;                       // Used for display messages
        msg.Printf(wxT("Row #% lu --\nTitle : %s\nPodDate : %s\nWhere : %s\nWhen : %s\nWho : %s\nDisc : %s\nRelated : %s\nPhotoName :%s"),
                   table->GetRowNum(),
                   pPictureInfo->Title,
                   pPictureInfo->PodDate,
                   pPictureInfo->Where,
                   pPictureInfo->When,
                   pPictureInfo->Who,
                   pPictureInfo->Disc,
                   pPictureInfo->Related,
                   pPictureInfo->PhotoName
                  );
        // Code to display 'msg' here
        wxSafeShowMessage(wxT("Pod_wxDbTable Test"),msg);
    }

/*
    if(!table->GetNext())
    {
        wxString         msg;                       // Used for display messages
        msg.Printf(wxT("Row #% lu --\nTitle : %s\nPodDate : %s\nWhere : %s\nWhen : %s\nWho : %s\nDisc : %s\nRelated : %s\nPhotoName :%s"),
                   table->GetRowNum(),
                   pPictureInfo->Title,
                   pPictureInfo->PodDate,
                   pPictureInfo->Where,
                   pPictureInfo->When,
                   pPictureInfo->Who,
                   pPictureInfo->Disc,
                   pPictureInfo->Related,
                   pPictureInfo->PhotoName
                  );
        // Code to display 'msg' here
        wxSafeShowMessage(wxT("table->GetNext Error!"),msg);
        return 0;
    }
*/
    return 1;
}
