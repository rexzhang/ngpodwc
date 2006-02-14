#include "ngpodwcc_mainframe.h"
#include "ngpodwc_common_screen.h"


void ngpodwcc_MainFrame::InitConfig(void)
//将config中的参数写到界面控件
{
    PodBasePath->SetValue(config.PodBasePath);
    PodDatabaseName->SetValue(config.PodDatabaseName);
    PodPicturePath->SetValue(config.PodPicturePath);

    //Next POD Day
	NextPODDay->SetValue(config.PodDate);

    if((config.ScreenWidth == 640) && (config.ScreenHeight == 480))
    {
        ScreenWidthHeight->SetSelection(SCREENWH640x480);
        ScreenWidth->SetValue(wxT("640"));
        ScreenHeight->SetValue(wxT("480"));
    }
    else
    {
        if((config.ScreenWidth == 800) && (config.ScreenHeight == 600))
        {
            ScreenWidthHeight->SetSelection(SCREENWH800x600);
            ScreenWidth->SetValue(wxT("800"));
            ScreenHeight->SetValue(wxT("600"));
        }
        else
        {
            if((config.ScreenWidth == 1024) && (config.ScreenHeight == 768))
            {
                ScreenWidthHeight->SetSelection(SCREENWH1024x768);
                ScreenWidth->SetValue(wxT("1024"));
                ScreenHeight->SetValue(wxT("768"));
            }
            else
            {
                //SCREENWHAutoDetect
                ScreenWidthHeight->SetSelection(SCREENWHAutoDetect);
            }
        }
    }

    ScreenPicturePath->SetValue(config.ScreenPicturePath);
    ScreenPictureName->SetValue(config.ScreenPictureName);
}

void ngpodwcc_MainFrame::ReadConfig(void)
//读取配置文件到界面控件
{
    config.ReadConfig();
    InitConfig();
}

void ngpodwcc_MainFrame::WriteConfig(void)
//保存界面控件的值到配置文件
{
    config.WriteConfig();
}

void ngpodwcc_MainFrame::SetDefault(void)
{
    config.SetDefault();
    InitConfig();
}

void ngpodwcc_MainFrame::AutoDetectScreenWH(void)
{
    wxString screenWH;

    //get system X,Y
    config.ScreenWidth = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
    config.ScreenHeight = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);

    //update display info
    screenWH.Printf(wxT("%u"), config.ScreenWidth);
    ScreenWidth->SetValue(screenWH);

    screenWH.Printf(wxT("%u"), config.ScreenHeight);
    ScreenHeight->SetValue(screenWH);

    ScreenWidthHeight->SetSelection(3);
}

wxString ngpodwcc_MainFrame::AutoDetectSystemPath(void)
{
    wxString path;
    wxGetEnv(wxT("windir"), &path);

    ScreenPicturePath->SetValue(path);
    return path;
}

