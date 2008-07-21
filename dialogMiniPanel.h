#ifndef DIALOGMINIPANEL_H
#define DIALOGMINIPANEL_H

#include <GUIFrame.h>


class dialogMiniPanel : public GUI_dialogMiniPanel
{
public:
    dialogMiniPanel(wxDialog *frame);
    virtual ~dialogMiniPanel();

protected:

private:
    void OnButtonClickPauseChangeWallpaper( wxCommandEvent& event );
    void OnButtonClickShowPrePicture( wxCommandEvent& event );
    void OnButtonClickShowNextPicture( wxCommandEvent& event );
    void OnButtonClickControlCenter( wxCommandEvent& event );
    void OnButtonClickAbout( wxCommandEvent& event );
    void OnButtonClickQuit( wxCommandEvent& event );

    //void InitConfig();
    void ShowConfig();
    void SwapPauseChangeWallpaperStat();
    void DisableUpdateButton();
    void EnableUpdateButton();


};

#endif // DIALOGMINIPANEL_H
