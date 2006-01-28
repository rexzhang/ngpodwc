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
    getPodInfo(config.DatabasePath, config.DatabaseName, &pPictureInfo);





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
    const wxString tableName = wxT("POD");
    const UWORD numTableColumns = 8;       // Number table columns

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


    //定义表部分
    //!!!!Debug
    table = new wxDbTable(PodDB, tableName, numTableColumns, wxT(""), !wxDB_QUERY_ONLY, wxT(""));

    PodPictrueInfo tempPictureInfo;

    table->SetColDefs(0, wxT("Pod_Title"), DB_DATA_TYPE_VARCHAR, tempPictureInfo.Title,
                      SQL_C_WXCHAR, sizeof(tempPictureInfo.Title), true, false, true, false);
    //table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_DATE, tempPictureInfo.PodDate,
    //                SQL_C_DATE, sizeof(tempPictureInfo.PodDate), true, true);
    table->SetColDefs(1, wxT("Pod_Date"), DB_DATA_TYPE_VARCHAR, tempPictureInfo.PodDate,
                      SQL_C_DATE, sizeof(tempPictureInfo.PodDate), true, true);
    //    table->SetColDefs(2, wxT("Pod_Where"), DB_DATA_TYPE_VARCHAR, tempPictureInfo.Where,
    //                    SQL_C_WXCHAR, sizeof(pPictureInfo->Where), false, true, true, false);

    //打开表
    if (!table->Open())
    {
        wxSafeShowMessage(DatabasePath + DatabaseName,
                          wxT("An error occurred opening (setting up) the table"));
        // An error occurred opening (setting up) the table
    }

    //按照PodDate字段排序
    table->SetOrderByClause(wxT("PodDate"));

    int PodDBTotalNumber = table->Count();
    /*
    wxString msg;
    msg.Printf(wxT(" table-Count() = %i"), PodDBTotalNumber);
    wxSafeShowMessage(msg,msg);
    */
    if (!table->Query())
    {
        //wxSafeShowMessage(wxT("QUERY ERROR: "), table->GetDb())

        return HandleError(wxT("QUERY ERROR: "), table->GetDb());
        //return 0;
    }

    //table->GetNext();
    table->GetFirst();
    wxSafeShowMessage(tempPictureInfo.Title,tempPictureInfo.PodDate);

    //wxString         msg;                       // Used for display messages
    while (table->GetNext())
    {
        //        msg.Printf(wxT("Row #%lu -- First Name : %s  Last Name is %s"),
        //                 table->GetRowNum(), FirstName, LastName);
        // Code to display 'msg' here
        //wxLogMessage(wxT("\n%s\n"), msg.c_str());
        wxSafeShowMessage(wxT("Pod_Title"),tempPictureInfo.Title);
    }


    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return 0;

    return 1;
}
