#include "dialogConfigPanel.h"

#include "dialogAbout.h"

dialogConfigPanel::dialogConfigPanel(wxDialog *frame)
        :GUI_dialogConfigPanel(frame)
{
    //ctor
    /*
    #if wxUSE_STATUSBAR
        statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
        statusBar->SetStatusText(wxbuildinfo(short_f), 1);
    #endif
    */
    ReadConfig();
    ShowConfig();
}

dialogConfigPanel::~dialogConfigPanel()
{
    //dtor
}


/////////////////////////
void dialogConfigPanel::OnButtonAboutClick( wxCommandEvent& event )
{
    dialogAbout* window = new dialogAbout(this);//, ID_DIALOG_ABOUT, _("About"));
    window->Show(true);
    wxLogWarning( configRunning.PodBasePath );
    event.Skip();
}

void dialogConfigPanel::ShowConfig(void)
//将config中的参数写到界面控件，以便显示出来
{
    //////////////////
    mPictureSource->SetSelection(configRunning.PictureSource);

    //////////////////
    mPodBasePath->SetValue(configRunning.PodBasePath);
    mPodDatabaseName->SetValue(configRunning.PodDatabaseName);
    mPodPicturePath->SetValue(configRunning.PodPicturePath);
    //Next POD Day
    mNextPODDay->SetValue(configRunning.PodDate);

    ///////////////////
    mLocalPicturePath->SetValue(configRunning.LocalPicturePath);

    ///////////////////////
    if ((configRunning.ScreenWidth == 640) && (configRunning.ScreenHeight == 480))
    {
        mScreenWidthHeight->SetSelection(SCREENWH640x480);
        mScreenWidth->SetValue(wxT("640"));
        mScreenHeight->SetValue(wxT("480"));
    }
    else
    {
        if ((configRunning.ScreenWidth == 800) && (configRunning.ScreenHeight == 600))
        {
            mScreenWidthHeight->SetSelection(SCREENWH800x600);
            mScreenWidth->SetValue(wxT("800"));
            mScreenHeight->SetValue(wxT("600"));
        }
        else
        {
            if ((configRunning.ScreenWidth == 1024) && (configRunning.ScreenHeight == 768))
            {
                mScreenWidthHeight->SetSelection(SCREENWH1024x768);
                mScreenWidth->SetValue(wxT("1024"));
                mScreenHeight->SetValue(wxT("768"));
            }
            else
            {
                //SCREENWHAutoDetect
                mScreenWidthHeight->SetSelection(SCREENWHAutoDetect);
            }
        }
    }
    mScreenPicturePath->SetValue(configRunning.ScreenPicturePath);
    mScreenPictureName->SetValue(configRunning.ScreenPictureName);

    ////////////////////////////////
    mShowDisc->SetValue(configRunning.ShowDisc);

    mPauseChangeWallpaper->SetValue(configRunning.PauseChangeWallpaper);
    mShowSplash->SetValue(configRunning.ShowSplash);

    //UILanguage->SetSelection(g_AppLanguageID

    return;
}

void dialogConfigPanel::ReadConfig( void )//读取配置文件到界面控件
{
    configRunning.ReadConfig();
}

void dialogConfigPanel::WriteConfig( void )// 写内存中（界面控件）的配置到配置文件
{
    configRunning.WriteConfig();
}

void dialogConfigPanel::AutoDetectScreenWH(void)
{
    wxString screenWH;

    //get system X,Y
    configRunning.ScreenWidth = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    configRunning.ScreenHeight = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

    //update display info
    screenWH.Printf(wxT("%u"), configRunning.ScreenWidth);
    mScreenWidth->SetValue(screenWH);

    screenWH.Printf(wxT("%u"), configRunning.ScreenHeight);
    mScreenHeight->SetValue(screenWH);

    mScreenWidthHeight->SetSelection(SCREENWHAutoDetect);
}

wxString dialogConfigPanel::AutoDetectSystemPath(void)
{
    wxString path;
    wxGetEnv(wxT("windir"), &path);

    mScreenPicturePath->SetValue(path);
    return path;
}
