#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <GUIFrame.h>


class dialogAbout : public GUI_dialogAbout
{
public:
    dialogAbout(wxDialog *frame);//    ngpodwcAbout(wxFrame *frame);
    virtual ~dialogAbout();
protected:
private:
    void OnButtonOKClick( wxCommandEvent& event )
    {
        Destroy();
    }

};

#endif // DIALOGABOUT_H
