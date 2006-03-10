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

wxString WallpaperNGPODOnline::GetText()
{
    wxString NGPODText = wxEmptyString;
    if(NGPODTitle != wxEmptyString)
    {
        NGPODText << wxT("Title : ") << NGPODTitle << wxT("\n");
    }
    //!Date
    NGPODText << wxT("POD Date : ") << Year << wxT("-") << Month << wxT("-") << Mday << wxT("\n");

    if(NGPODWhen != wxEmptyString)
    {
        NGPODText << wxT("When : ") << NGPODWhen << wxT("\n");
    }

    NGPODText << wxT("Where : ") << NGPODWhere << wxT("\n");
    NGPODText << wxT("Who : ") << NGPODWho << wxT("\n");

    NGPODText << wxT("\n") << NGPODDisc;

    wxSafeShowMessage(wxT("DEBUG Info"), NGPODText);

    return NGPODText;
}

bool WallpaperNGPODOnline::Init()
{
    wxString NGPODOnineURLString = wxEmptyString;

    toDate(config.PodDate, &Year, &Month, &Mday);

    NGPODOnineURLString.Printf(wxT("http://lava.nationalgeographic.com/cgi-bin/pod/PhotoOfTheDay.cgi?month=%u&day=%u&year=%u"),
                               Month, Mday, (Year - 2000));
    //wxSafeShowMessage(wxT("DEBUG Info"), NGPODOnineURLString);

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
    int Finish = 0;
    while(!PhotoOfTheDay_in_stream->Eof() && Finish <= 6)
    {
        HtmlLine = PhotoOfTheDayStream.ReadLine();
        if(HtmlLine.Contains(wxT("<title>")))
            //<title>National Geographic Photo of the Day: Route 1</title>
        {
            HtmlLine.Replace(wxT("<title>National Geographic Photo of the Day: "), wxT("\n"));
            HtmlLine = HtmlLine.AfterFirst(wxChar('\n'));
            NGPODTitle = HtmlLine.BeforeFirst(wxChar('<'));
            //wxSafeShowMessage(wxT("DEBUG Info"), NGPODTitle);
            //break;
            Finish++;
            continue;
        }
        if(HtmlLine.Contains(wxT("/pod/pictures/sm_wallpaper/")))
            // <a href="/pod/pictures/sm_wallpaper/06130_50036.jpg"><img src="/pod/pictures/normal/06130_50036.jpg" class="gray-border" width="470" border="0"></a></div>
        {
            HtmlLine.Replace(wxT("/pod/pictures/sm_wallpaper/"), wxT("\n"));
            HtmlLine = HtmlLine.AfterFirst(wxChar('\n'));
            NGPODPictureName = HtmlLine.BeforeFirst(wxChar('\"'));
            //wxSafeShowMessage(wxT("DEBUG Info"), NGPODPictureName);
            //break;
            Finish++;
            continue;
        }
        //<div class="place-photographer" style="margin-top:10px;margin-left:10px;">
        if(HtmlLine.Contains(wxT("<div class=\"place-photographer\"")))
            //Photograph by  Bruce   Dale</div>
        {
            wxString WhereAndWhen = wxEmptyString;

            //NGPODWhere = wxEmptyString;
            //HtmlLine = PhotoOfTheDayStream.ReadLine();
            do
                //</div><div class="place-photographer-sub"
            {
                HtmlLine = PhotoOfTheDayStream.ReadLine();
                WhereAndWhen << HtmlLine;
            }
            while(!HtmlLine.Contains(wxT("</div>")));
            //1998</div><div class="place-photographer-sub"
            WhereAndWhen = WhereAndWhen.BeforeFirst(wxChar('<'));
            //WhereAndWhen = WhereAndWhen(WhereAndWhen);
            WhereAndWhen = WhereAndWhen.BeforeFirst(wxChar('<'));

            NGPODWhere = WhereAndWhen.BeforeLast(wxChar(','));
            NGPODWhere = RemoveSpace(NGPODWhere);

            NGPODWhen =  WhereAndWhen.AfterLast(wxChar(','));
            NGPODWhen = RemoveSpace(NGPODWhen);

            Finish++;
            //wxSafeShowMessage(wxT("DEBUG Info"), NGPODWho);
            continue;
        }
        if(HtmlLine.Contains(wxT("Photograph by")))
            //Photograph by  Bruce   Dale</div>
        {
            HtmlLine.Replace(wxT("Photograph by "), wxT("\n"));
            HtmlLine = HtmlLine.AfterFirst(wxChar('\n'));
            NGPODWho = HtmlLine.BeforeFirst(wxChar('<'));
            //wxSafeShowMessage(wxT("DEBUG Info"), NGPODWho);
            //break;
            NGPODWho = RemoveSpace(NGPODWho);
            Finish++;
            continue;
        }
        if(HtmlLine.Contains(wxT("<div class=\"pod-caption\"")))
            //<!--- start caption --->
            //<div class="pod-caption" style="margin-top:10px;margin-left:10px;">
        {
            NGPODDisc = wxEmptyString;
            HtmlLine = PhotoOfTheDayStream.ReadLine();

            while(!HtmlLine.Contains(wxT("</div>")))
                //</div></td>
            {
                NGPODDisc << HtmlLine;
                HtmlLine = PhotoOfTheDayStream.ReadLine();
            }
            //wxSafeShowMessage(wxT("DEBUG Info"), NGPODDisc);
            //break;
            //!内容整理
            NGPODDisc = RemoveSpace(NGPODDisc);
            //FixNGPODDisc();//在线版不需要多重处理.只有在<p>是是换行
            NGPODDisc.Replace(wxT("<p>"), wxT("\n"));
            NGPODDisc.Replace(wxT("<P>"), wxT("\n"));

            NGPODDisc.Replace(wxT("<BR>"), wxT("\n"));
            NGPODDisc.Replace(wxT("<br>"), wxT("\n"));

            NGPODDisc.Replace(wxT("<I>"), wxT(""));
            NGPODDisc.Replace(wxT("</I>"), wxT(""));
            NGPODDisc.Replace(wxT("<i>"), wxT(""));
            NGPODDisc.Replace(wxT("</i>"), wxT(""));

            NGPODDisc.Replace(wxT("\n\n"), wxT("\n"));
            Finish++;
            continue;
        }
        if(HtmlLine.Contains(wxT("<REPEAT_LINKS>")))
        {
            //<REPEAT_LINKS>
            //<li><a href="http://news.nationalgeographic.com/news/2002/12/1202_021202_AfricaPhotoGallery.html">News story & photo gallery: A Day in the Life of Africa</a></li>
            //</REPEAT_LINKS>
            NGPODRelated = PhotoOfTheDayStream.ReadLine();
            Finish++;
            continue;
        }
    }

/*
    wxString NGPOD = wxEmptyString;
    NGPOD << wxT("title : ") << NGPODTitle << wxT("\nwhere : ") << NGPODWhere;
    NGPOD << wxT("\nwhen : ") << NGPODWhen;
    NGPOD << wxT("\nwho : ") << NGPODWho << wxT("\ndisc : ") << NGPODDisc;
    NGPOD << wxT("\npicturename : ") << NGPODPictureName;
    wxSafeShowMessage(wxT("DEBUG Info"), NGPOD);
*/
    GetPictureFromInternet();

    return true;
}

bool WallpaperNGPODOnline::GetPictureFromInternet()
{
    //get picture file---------------------------
    wxString NGPODOnineURLString(wxT("http://lava.nationalgeographic.com/pod/pictures/lg_wallpaper/"));
    NGPODOnineURLString << NGPODPictureName;
    //wxSafeShowMessage(wxT("DEBUG Info"), NGPODOnineURLString);

    wxURL NGPODOnlineURL(NGPODOnineURLString);
    if (NGPODOnlineURL.GetError() != wxURL_NOERR)
    {
        //!report Error!!
        wxSafeShowMessage(wxT("NGPODOnlineURL GetError"), wxT("from internet"));
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


