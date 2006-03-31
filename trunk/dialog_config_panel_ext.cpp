#include "dialog_config_panel.h"
//#include "ngpodwc_common_screen.h"
#include "ngpodwcc.h"

#include "common_globals.h"

#include <wx/stdpaths.h>
#include <wx/filename.h>

void dialog_config_panel::InitConfig(void)
//��ʼ���������
{
    //Check config file
    //��������ļ��Ƿ����
    if ( !wxFileExists(config.GetConfigFile()) )
    {
        //û�������ļ�
        wxLogWarning(_("Can't found .INI(%s) file. Systen will restore config to defaule. Please click SAVE_CONFIG save config."), config.GetConfigFile().c_str());
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

void dialog_config_panel::ReadConfig(void)
//��ȡ�����ļ�������ؼ�
{
    config.ReadConfig();
    ShowConfig();
}

void dialog_config_panel::WriteConfig(void)
//�������ؼ���ֵ�������ļ�
{
    config.WriteConfig();
}

void dialog_config_panel::SetDefault(void)
{
    config.SetDefault();
    ShowConfig();
}

void dialog_config_panel::ShowConfig(void)
//��config�еĲ���д������ؼ����Ա���ʾ����
{
    //////////////////
    PictureSource->SetSelection(config.PictureSource);

    //////////////////
    PodBasePath->SetValue(config.PodBasePath);
    PodDatabaseName->SetValue(config.PodDatabaseName);
    PodPicturePath->SetValue(config.PodPicturePath);
    //Next POD Day
    NextPODDay->SetValue(config.PodDate);

    ///////////////////
    LocalPicturePath->SetValue(config.LocalPicturePath);

    ///////////////////////
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

	////////////////////////////////
	ShowDisc->SetValue(config.ShowDisc);

	PauseChangeWallpaper->SetValue(config.PauseChangeWallpaper);
	ShowSplash->SetValue(config.ShowSplash);

    //UILanguage->SetSelection(g_AppLanguageIDs[

	return;
}

void dialog_config_panel::AutoDetectScreenWH(void)
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

wxString dialog_config_panel::AutoDetectSystemPath(void)
{
    wxString path;
    wxGetEnv(wxT("windir"), &path);

    ScreenPicturePath->SetValue(path);
    return path;
}

