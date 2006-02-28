#include "ngpodwcc_mainframe.h"
#include "ngpodwc_common_screen.h"
#include "ngpodwcc.h"

#include <wx/stdpaths.h>
#include <wx/filename.h>

void ngpodwcc_MainFrame::InitConfig(void)
//��ʼ���������
{
    //Check config file
    if ( !wxFileExists(config.GetConfigFile()) )
    {
        //û�������ļ�
        wxSafeShowMessage(wxT("can not found .ini"),
                          wxT("systen will restore config to defaule\nplease click SAVE_CONFIG save config"));
        ButtonSaveConfig->Enable();
    }
    else
    {
        //�ҵ������ļ�
        config.ReadConfig();
        ButtonSaveConfig->Disable();
    }

    ShowConfig();
}

void ngpodwcc_MainFrame::ReadConfig(void)
//��ȡ�����ļ�������ؼ�
{
    config.ReadConfig();
    ShowConfig();
}

void ngpodwcc_MainFrame::WriteConfig(void)
//�������ؼ���ֵ�������ļ�
{
    config.WriteConfig();
}

void ngpodwcc_MainFrame::SetDefault(void)
{
    config.SetDefault();
    ShowConfig();
}

void ngpodwcc_MainFrame::ShowConfig(void)
//��config�еĲ���д������ؼ����Ա���ʾ����
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

	PauseChangeWallpaper->SetValue(config.PauseChangeWallpaper);
	ShowSplash->SetValue(config.ShowSplash);

	return;
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

