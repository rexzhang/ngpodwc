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

    toDate(config.PodDate, &Year, &Month, &Mday);

    NGPODOnineURLString.Printf(wxT("http://lava.nationalgeographic.com/cgi-bin/pod/PhotoOfTheDay.cgi?month=%u&day=%u&year=&%u"),
                               Month, Mday, (Year - 2000));

    wxURL NGPODOnlineURL(NGPODOnineURLString);

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
        if(HtmlLine.Contains(wxT("/pod/pictures/sm_wallpaper/")))
        {
            // <a href="/pod/pictures/sm_wallpaper/06130_50036.jpg"><img src="/pod/pictures/normal/06130_50036.jpg" class="gray-border" width="470" border="0"></a></div>
            HtmlLine.Replace(wxT("/pod/pictures/sm_wallpaper/"), wxT("\n"));
            HtmlLine = HtmlLine.AfterFirst(wxChar('\n'));
            PODPictureName = HtmlLine.BeforeFirst(wxChar('\"'));
            //wxSafeShowMessage(wxT("DEBUG Info"), PODPictureName);
            break;
        }
    }

    GetPictureFromInternet();

    return true;
}

bool WallpaperNGPODOnline::GetPictureFromInternet()
{
    //get picture file---------------------------
    wxString NGPODOnineURLString(wxT("http://lava.nationalgeographic.com/pod/pictures/lg_wallpaper/"));
    NGPODOnineURLString << PODPictureName;

    wxSafeShowMessage(wxT("DEBUG Info"), NGPODOnineURLString);

    wxURL NGPODOnlineURL(NGPODOnineURLString);
    if (NGPODOnlineURL.GetError() != wxURL_NOERR)
    {
        //!report Error!!
        return false;
    }
    wxInputStream *PhotoOfTheDay_in_stream;
    PhotoOfTheDay_in_stream = NGPODOnlineURL.GetInputStream();

    //wxImage(wxInputStream& stream, long type = wxBITMAP_TYPE_ANY, int index = -1)
    if(!Image.LoadFile(*PhotoOfTheDay_in_stream, wxBITMAP_TYPE_JPEG))
    {
        //report error
        wxSafeShowMessage(wxT("Can't load JPG image"), wxT("from internet"));
        return false;
    }

    return true;
}

bool WallpaperNGPODOnline::SaveWallpaper()
{


    //将处理完毕的图片输出至指定目录
    if(!Image.SaveFile(config.ScreenPicturePath + wxT("\\") + config.ScreenPictureName,
                       wxBITMAP_TYPE_BMP))
    {
        wxSafeShowMessage(wxT("Can't save BMP image"),wxT("Can't save BMP image"));

        wxString msgTitle("图片Create Error错误！",*wxConvCurrent);
        wxString msgContext("图片Create Error错误！\n请....XXXX.......操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return false;
    }
    //保存变化后（当前背景图片）的日期信息至配置文件
    config.WriteConfig();

    return true;
}


