#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/msgdlg.h>
#include <wx/log.h>

main()
{
    // TODO (Rex##): todo list test
    //�������ļ�
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    if(!ConfigInStream.Ok())//��������ļ��Ƿ����
    {
        //wxString msg = "��������ļ��Ƿ����";
        //wxString msgg =
        wxString msgTitle("�����ļ�������",*wxConvCurrent);
        wxString msgContext("�Ҳ�����������ļ� ngpodwc.ini\n������ ngpodcc.exe ���г�ʼ��������",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));

        return 1;
    }

    //��ȡ�����ļ�-���ڴ�
    wxFileConfig *config = new wxFileConfig(ConfigInStream, wxConvUTF8);

    //config->Write(wxT("DatabasePath"),wxT("d:\\"));

    wxSafeShowMessage(config->Read(wxT("DatabasePath")),config->Read(wxT("DatabaseName")));

    return 0;
}

