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

    //�������ļ�
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    if(!ConfigInStream.Ok())//��������ļ��Ƿ����
    {
        wxString msgTitle("�����ļ�������",*wxConvCurrent);
        wxString msgContext("�Ҳ�����������ļ� ngpodwc.ini\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));

        return 1;
    }

    //�����������ļ�������
    wxFileConfig *pFileConfig = new wxFileConfig(ConfigInStream, wxConvUTF8);

    //config->Write(wxT("DatabasePath"),wxT("d:\\"));

    //��ȡ�����ļ�-���ڴ�
    ngpodwcConfig config;
    config.DatabasePath = pFileConfig->Read(wxT("DatabasePath"));
    config.DatabaseName = pFileConfig->Read(wxT("DatabaseName"));
    //wxSafeShowMessage(config.DatabasePath,config.DatabaseName);

    //��ȡPOD ͼƬ������Ϣ�Լ�ͼƬ�ļ�����
    PodPictrueInfo pictureInfo;
    getPodInfo(config.DatabasePath, config.DatabaseName, &pictureInfo);





    return 0;
}

void getPodInfo(wxString DatabasePath, wxString DatabaseName, PodPictrueInfo *pPictureInfo)
{
    //DatabasePath = DatabasePath + DatabaseName;
    //wxSafeShowMessage(DatabasePath,DatabaseName);

    wxDbConnectInf DbConnectInf;
    //��ʽ�Ĵ�ODBC����
    wxDb DB(DbConnectInf.GetHenv());

    bool DBfailOnDataTypeUnsupported=TRUE;

    //͸��Driver�ķ�ʽ��ODBC
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

    //����PodDate�ֶ�����
    table->SetOrderByClause(wxT("PodDate"));

    table->GetFirst();





    return;
}