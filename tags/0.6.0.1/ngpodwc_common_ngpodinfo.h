#ifndef COMMON_NGPODINFO_H
#define COMMON_NGPODINFO_H

#include <wx/db.h>
#include <wx/datetime.h>
#include "ngpodwc_common_datetime.h"

class ngpodinfo
{
    public:
        ngpodinfo();
        virtual ~ngpodinfo();

    wxChar Title[100];
    wxChar PodDate[20];
    wxChar Where[80];
    wxChar When[80];
    wxChar Who[80];
    wxChar Disc[254];
    wxChar Related[254];
    wxChar PhotoName[80];


    bool ngpodinfo::GetInfo(wxString PodDBName, wxDateTime PodDateSelected);

    protected:
    private:
    //int HandleError(wxString errmsg, wxDb *pDb=NULL);
    int HandleError(wxString errmsg);
    int HandleError(wxString errmsg, wxDb *pDb);
};

#endif // COMMON_NGPODINFO_H
/*
struct PodPictrueInfo
{

};
*/
