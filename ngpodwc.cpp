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
    PodPictrueInfo pictureInfo;
    getPodInfo(config.DatabasePath, config.DatabaseName, &pictureInfo);





    return 0;
}

void getPodInfo(wxString DatabasePath, wxString DatabaseName, PodPictrueInfo *pPictureInfo)
{
    //DatabasePath = DatabasePath + DatabaseName;
    //wxSafeShowMessage(DatabasePath,DatabaseName);

    wxDbConnectInf  *DbConnectInf    = NULL;    // DB connection information

    wxDb            *PodDB              = NULL;    // Database connection

    wxDbTable       *table           = NULL;    // Data table to access
    const wxChar tableName[] = wxT("POD"); // Name of database table
    const UWORD numTableColumns = 8;       // Number table columns


    //wxDbConnectInf DbConnectInf;
    //DbConnectInf = new wxDbConnectInf(0, wxT(""), wxT(""), wxT(""));//这里定义的内容基本没用
    DbConnectInf = new wxDbConnectInf;

    //正式的打开ODBC操作
    //wxDb PodDB(DbConnectInf.GetHenv());
    //PodDB = new wxDb;//!!必须的一步
    PodDB = new wxDb(DbConnectInf->GetHenv());//!!必须的一步


    bool DBfailOnDataTypeUnsupported=TRUE;

    //透过Driver的方式打开ODBC
    //if(DB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=D:\\pod.mdb;UID=admin;"),DBfailOnDataTypeUnsupported))
    if(PodDB->Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=") + DatabasePath + DatabaseName + wxT(";UID=admin;"),
                   DBfailOnDataTypeUnsupported))//!!!!Debug
    {
        if (PodDB->IsOpen())
        {
            // Connection is open, but the initialization of
            // datatypes and parameter settings failed
            wxSafeShowMessage(DatabasePath +DatabaseName,
                              wxT("Connection is open, but the initialization of datatypes and parameter settings failed"));
            return;
        }
        else
        {
            // Error opening datasource
            //return HandleError(wxT("DB ENV ERROR: Cannot allocate ODBC env handle"));
            wxSafeShowMessage(DatabasePath,DatabaseName);
            return;
        }
    }

    //!!!TEST END
    wxSafeShowMessage(wxT("TEST END"),wxT("TEST END"));
    return;

    /*
    table = new wxDbTable(PodDB, tableName, numTableColumns, wxT(""), !wxDB_QUERY_ONLY, wxT(""));
    //table = new wxDbTable(&PodDB, wxT("TTT"), numTableColumns, wxT(""), !wxDB_QUERY_ONLY, wxT(""));
    //wxDbTable table;
    if (!table->Open())
    {
        // An error occurred opening (setting up) the table
    }

    //按照PodDate字段排序
    table->SetOrderByClause(wxT("PodDate"));

    table->GetFirst();
*/




    return;
}
