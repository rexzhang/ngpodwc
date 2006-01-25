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
    //打开配置文件
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    if(!ConfigInStream.Ok())//检查配置文件是否存在
    {
        //wxString msg = "检查配置文件是否存在";
        //wxString msgg =
        wxString msgTitle("配置文件不存在",*wxConvCurrent);
        wxString msgContext("找不到检查配置文件 ngpodwc.ini\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        //wxT("ngpodwc.ini can NOT found!,please RUN ngpodcc.exe"));

        return 1;
    }

    //读取配置文件-〉内存
    wxFileConfig *config = new wxFileConfig(ConfigInStream, wxConvUTF8);

    //config->Write(wxT("DatabasePath"),wxT("d:\\"));

    wxSafeShowMessage(config->Read(wxT("DatabasePath")),config->Read(wxT("DatabaseName")));

    return 0;
}

