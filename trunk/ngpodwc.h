struct ngpodwcConfig
{
    wxString DatabasePath;
    wxString DatabaseName;
};

struct PodPictrueInfo
{
    wxString Title;
    wxString PodDate;
    wxString Where;
    wxString When;
    wxString Who;
    wxString Disc;
    wxString Related;
    wxString PhotoName;
};


void getPodInfo(wxString DatabasePath, wxString DatabaseName, PodPictrueInfo *pPictureInfo);
