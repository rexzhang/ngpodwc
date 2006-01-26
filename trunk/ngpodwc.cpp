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

    wxDbConnectInf DbConnectInf;
    //正式的打开ODBC操作
    wxDb DB(DbConnectInf.GetHenv());

    bool DBfailOnDataTypeUnsupported=TRUE;

    //透过Driver的方式打开ODBC
    //if(DB.Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=pod.mdb;UID=admin;"),DBfailOnDataTypeUnsupported))
    if(DB.Open(wxT("DRIVER=Microsoft Access Driver (*.mdb);DBQ=") + DatabasePath + DatabaseName + wxT(";UID=admin;"),
               DBfailOnDataTypeUnsupported))
    {
        if (DB.IsOpen())
        {
            // Connection is open, but the initialization of
            // datatypes and parameter settings failed
            wxSafeShowMessage(DatabasePath,DatabaseName);
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

    //wxString tableName = wxT("POD");
    const wxChar tableName[] = wxT("POD"); // Name of database table
    const UWORD numTableColumns = 8;       // Number table columns
    wxDbTable       *table           = NULL;    // Data table to access

    table = new wxDbTable(&DB, tableName, numTableColumns, wxT(""), !wxDB_QUERY_ONLY, wxT(""));
    //wxDbTable table;
    if (!table->Open())
    {
        // An error occurred opening (setting up) the table
    }

    //按照PodDate字段排序
    table->SetOrderByClause(wxT("PodDate"));

    table->GetFirst();





    return;
}
