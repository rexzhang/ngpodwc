//
//
//
#include <wx/string.h>

class ngpodwcConfig
{
public:
    wxString PodBasePath;
    wxString PodDatabaseName;

    wxString PodPictureMode;
    wxString PodPicturePath;

    int PodYear;
    int PodMonth;
    int PodDays;

    //////////
    wxString ScreenPicturePath;
    wxString ScreenPictureName;

    int ScreenWidth;
    int ScreenHeight;

    //////////
    //wxFileConfig *pFileConfig;

    ngpodwcConfig();
    void Init();

    bool ReadConfig();
    bool WriteConfig();

    /*    wxChar PodBasePath[254];//=wxT("");
        wxChar PodDatabaseName[254];//=wxT("");
        wxChar PodPictureMode[254];//=wxT("");
        wxChar PodPicturePath[254];//=wxT("");
        wxChar ScreenPicturePath[254];//=wxT("");
        wxChar ScreenPictureName[254];//=wxT("");
    */
    /*    wxChar* PodBasePath;//[254];//=wxT("");
        wxChar* PodDatabaseName;//[254];//=wxT("");
        wxChar* PodPictureMode;//[254];//=wxT("");
        wxChar* PodPicturePath;//[254];//=wxT("");
        wxChar* ScreenPicturePath;//[254];//=wxT("");
        wxChar* ScreenPictureName;//[254];//=wxT("");
    */

    //    wxSize ScreenSize;
};

//ngpodwcReadConfig(ngpodwcConfig *config);
