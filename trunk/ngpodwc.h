#include <wx/datetime.h>

struct ngpodwcConfig
{
    wxString DatabasePath;
    wxString DatabaseName;
};

struct PodPictrueInfo
{
    //wxString Title;
    wxChar Title[100];// = wxEmptyString;
    wxChar PodDate[20];
    wxChar Where[80];
    wxChar When[80];
    wxChar Who[80];
    wxChar Disc[254];
    wxChar Related[254];
    wxChar PhotoName[80];
};


bool getPodInfo(const wxString DatabasePath, const wxString DatabaseName, PodPictrueInfo *pPictureInfo);

// ----------------------------------------------------------------------------
// FUNCTION USED FOR HANDLING/DISPLAYING ERRORS
// ----------------------------------------------------------------------------
// Very generic error handling function.
// If a connection to the database is passed in, then we retrieve all the
// database errors for the connection and add them to the displayed message
int HandleError(wxString errmsg, wxDb *pDb=NULL)
{
    // Retrieve all the error message for the errors that occurred
    wxString allErrors;
    if (!pDb == NULL)
        // Get the database errors and append them to the error message
        allErrors = wxDbLogExtendedErrorMsg(errmsg.c_str(), pDb, 0, 0);
    else
        allErrors = errmsg;

    // Do whatever you wish with the error message here
    // wxLogDebug() is called inside wxDbLogExtendedErrorMsg() so this
    // console program will show the errors in the console window,
    // but these lines will show the errors in RELEASE builds also
    //wxFprintf(stderr, wxT("\n%s\n"), allErrors.c_str());
    //fflush(stderr);

    wxSafeShowMessage(errmsg,allErrors);

    return 1;
};
