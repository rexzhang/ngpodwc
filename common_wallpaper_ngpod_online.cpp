#include "common_wallpaper_ngpod_online.h"

#include "ngpodwc_common_datetime.h"
#include <wx/url.h>
#include <wx/stream.h>
#include <wx/txtstrm.h>

WallpaperNGPODOnline::WallpaperNGPODOnline(ngpodwcConfig programConfig):WallpaperBase(programConfig)
{
    Init();
    //ctor
}

WallpaperNGPODOnline::~WallpaperNGPODOnline()
{
    //dtor
}

bool WallpaperNGPODOnline::Init()
{
    //wxFileSystem::AddHandler(new wxInternetFSHandler );
    wxString NGPODOnineURLString = wxEmptyString;
    int Year, Month, Mday;

    toDate(config.PodDate, &Year, &Month, &Mday);

    NGPODOnineURLString.Printf(wxT("http://lava.nationalgeographic.com/cgi-bin/pod/PhotoOfTheDay.cgi?month=%u&day=%u&year=&%u"),
                               Month, Mday, (Year - 2000));

    wxURL NGPODOnlineURL(NGPODOnineURLString);

    /*
        if(NGPODOnlineHTTP.GetResponse() != 200)
        {
            //!report Error!!
            return false;
        }
        */
    if (NGPODOnlineURL.GetError() != wxURL_NOERR)
    {
        //!report Error!!
        return false;
    }
    wxInputStream *PhotoOfTheDay_in_stream;
    // Then, you can use all IO calls of in_stream (See wxStream)

    PhotoOfTheDay_in_stream = NGPODOnlineURL.GetInputStream();

    wxTextInputStream PhotoOfTheDayStream(*PhotoOfTheDay_in_stream,
                                          wxT("\t"), wxConvISO8859_1);

    wxString HtmlLine;
    while(PhotoOfTheDay_in_stream->Eof() == false)
    {
        HtmlLine = PhotoOfTheDayStream.ReadLine();
        wxSafeShowMessage(wxT("DEBUG Info"), HtmlLine);
    }

    //wxImage(wxInputStream& stream, long type = wxBITMAP_TYPE_ANY, int index = -1)

    return true;
}
