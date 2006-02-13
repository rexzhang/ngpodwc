#include "ngpodwcc_mainframe.h"

void ngpodwcc_MainFrame::InitConfig(void)
//��config�еĲ���д������ؼ�
{
    PodBasePath->SetValue(config.PodBasePath);
    PodDatabaseName->SetValue(config.PodDatabaseName);
    PodPicturePath->SetValue(config.PodPicturePath);

	//Next POD Day

	//ScreenWidthHeight
	//ScreenWidth
	//ScreenHeight

	ScreenPicturePath->SetValue(config.ScreenPicturePath);
	ScreenPictureName->SetValue(config.ScreenPictureName);
}

void ngpodwcc_MainFrame::ReadConfig(void)
//��ȡ�����ļ�������ؼ�
{
	config.ReadConfig();
	InitConfig();
}

void ngpodwcc_MainFrame::WriteConfig(void)
//�������ؼ���ֵ�������ļ�
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
