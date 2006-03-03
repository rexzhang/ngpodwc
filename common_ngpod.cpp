#include "common_ngpod.h"

NGPOD::NGPOD(ngpodwcConfig programConfig)
{
    //ctor
    config = programConfig;
    Init();
}

NGPOD::~NGPOD()
{
    //dtor
}

bool NGPOD::Init()
{
    //获取POD 图片描述信息以及图片文件名称
    if(!podPictureInfo.GetInfo(config.PodBasePath + wxT("\\") + config.PodDatabaseName, config.PodDate))
    {
        wxString msgTitle("获取POD 图片描述信息以及图片文件名称错误！",*wxConvCurrent);
        wxString msgContext("获取POD 图片描述信息以及图片文件名称错误！\n请运行 ngpodcc.exe 进行初始化操作！",*wxConvCurrent);
        wxSafeShowMessage(msgTitle, msgContext);
        return false;
    }

    //获取原始图片
    //wxImage PodImage, ScreenImage;
    if (!Image.LoadFile(config.PodBasePath + wxT("\\") + config.PodPicturePath
                           + wxT("\\") + podPictureInfo.PhotoName, wxBITMAP_TYPE_JPEG))
    {
        wxSafeShowMessage(wxT("Can't load JPG image"), podPictureInfo.PhotoName);
        return false;
    }

    return true;
}

bool NGPOD::DrawText()
{

    wxBitmap ScreenBitmap(Image);
    // Create a memory DC
    wxMemoryDC ScreenImageDC;
    ScreenImageDC.SelectObject(ScreenBitmap);
    //ScreenImageDC.SelectObject(*pScreenImage);
    wxColourDatabase ColourDB;
    //ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    //ScreenImageDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

    wxString podInfoDisc(podPictureInfo.Disc);
    if(podInfoDisc.Contains(wxT("#")))
    {
        podInfoDisc.Replace(wxT("#034"), wxT("\""), true);
        podInfoDisc.Replace(wxT("#039"), wxT("\'"), true);

        podInfoDisc.Replace(wxT("#133"), wxT("..."), true);//...

        podInfoDisc.Replace(wxT("#145"), wxT("\'"), true);//‘
        podInfoDisc.Replace(wxT("#146"), wxT("\'"), true);//’

        podInfoDisc.Replace(wxT("#147"), wxT("\""), true);//“
        podInfoDisc.Replace(wxT("#148"), wxT("\""), true);//”

        podInfoDisc.Replace(wxT("#151"), wxT("\'"), true);//＇
    }
    //
    podInfoDisc.Replace(wxT("<BR>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</P>"), wxT(""), true);
    podInfoDisc.Replace(wxT("<I>"), wxT(""), true);
    podInfoDisc.Replace(wxT("</I>"), wxT(""), true);

    podInfoDisc.Replace(wxT("\n"), wxT(""), true);
    podInfoDisc.Replace(wxT(".\n"), wxT("."), true);
    podInfoDisc.Replace(wxT(". "), wxT(". \n "), true);
    podInfoDisc.Replace(wxT(" \n \n"), wxT(" \n"), true);

    podInfoDisc.Replace(wxT(".\'\" "), wxT(".\'\" \n "), true);

    /*
    podInfoDisc.Replace(wxT("\n"), wxT(" \n "), true);
    podInfoDisc.Replace(wxT(".\n"), wxT(". \n "), true);
    //podInfoDisc.Replace(wxT("."), wxT(".\n"), true);
    */

    //
    wxString podInfoString;//
    podInfoString.Printf(wxT(" Title : %s \n Date: %s \n When : %s \n Who : %s \n\n "),
                         podPictureInfo.Title,
                         podPictureInfo.PodDate,
                         podPictureInfo.When,
                         podPictureInfo.Who);
    podInfoString = podInfoString + podInfoDisc + wxT(" ");

    podInfoString.Replace(wxT("National Geographic Photo of the Day: "), wxT(""), true);
    podInfoString.Replace(wxT(" 00:00:00"), wxT(""), true);
    //
    int InfoBoxW = 600, InfoBoxH = 200;
    int InfoBoxXY = 20, infoBoxYSeek = 30;//当为右下时，为右下与屏幕右下角的相对坐标

    wxRect podInfoRect(Image.GetWidth() - InfoBoxXY - InfoBoxW,
                       Image.GetHeight() - InfoBoxXY - InfoBoxH - infoBoxYSeek,
                       InfoBoxW, InfoBoxH);
    /*
        //--------------------------------
        wxBitmap InfoBoxBitmap(600,150, 16);
        InfoBoxBitmap.LoadFile(wxT("art/logo.xpm"), wxBITMAP_TYPE_XPM);
        wxMemoryDC InfoBoxDC;

        InfoBoxDC.SelectObject(InfoBoxBitmap);
        InfoBoxDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
        InfoBoxDC.SetTextBackground(ColourDB.Find(wxT("LIGHT GREY")));

        //InfoBoxDC.Clear();
        //InfoBoxDC.DrawRoundedRectangle(0,0,600,150,20);
        InfoBoxDC.DrawRectangle(1,1,550,140);

        ScreenImageDC.DrawBitmap(InfoBoxBitmap, 400, 600, true);
        //--------------------------------
    */
    //ScreenImageDC.DrawRectangle(400,600,600,150);

    wxFont ScreenImageFont = ScreenImageDC.GetFont();
    ScreenImageFont.SetFamily(wxFONTFAMILY_ROMAN);
    ScreenImageDC.SetFont(ScreenImageFont);
    //ScreenImageDC.SetBackgroundMode(wxSOLID);//强制指定显示字体背景色，默认为透明

    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("DARK GREY")));
    ScreenImageDC.DrawLabel(podInfoString, podInfoRect, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);
    ///////-------------
    ScreenImageDC.SetTextForeground(ColourDB.Find(wxT("LIGHT GREY")));

    int InfoBoxW2 = 600, InfoBoxH2 = 200;
    int InfoBoxXY2 = 20, infoBoxYSeek2 = 30;//当为右下时，为右下与屏幕右下角的相对坐标
    wxRect podInfoRect2(Image.GetWidth() - InfoBoxXY2 - InfoBoxW2 - 1,
                        Image.GetHeight() - InfoBoxXY2 - InfoBoxH2 - infoBoxYSeek2 - 1,
                        InfoBoxW2, InfoBoxH2);
    ScreenImageDC.DrawLabel(podInfoString, podInfoRect2, wxALIGN_RIGHT | wxALIGN_BOTTOM, -1);

    ///////-------------

    ScreenImageDC.SelectObject( wxNullBitmap );

    Image = ScreenBitmap.ConvertToImage();

    return true;
}
