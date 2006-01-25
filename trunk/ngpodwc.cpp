#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

main()
{
    wxFileInputStream ConfigInStream(wxT("ngpodwc.ini"));
    //wxFileOutputStream ConfigOutStream(wxT("ngpodwc.ini"));

    //wxConfig *config = new wxConfig(wxT("ngpodwc"), wxT("flord.net"));
    wxFileConfig *fileConfig = new wxFileConfig(ConfigInStream, wxConvUTF8);

    fileConfig->Write(wxT("DatabasePath"),wxT("d:\\"));

    wxFileOutputStream ConfigOutStream(wxT("ngpodwc-out.ini"));
    fileConfig->Save(ConfigOutStream, wxConvUTF8);

    return 0;
}
