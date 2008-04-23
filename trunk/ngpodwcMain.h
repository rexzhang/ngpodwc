/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcMain.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2008-4-21
// RCS-ID:
// Copyright:   (c) 2008 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////


#ifndef NGPODWCMAIN_H_INCLUDED
#define NGPODWCMAIN_H_INCLUDED

#include "GUIFrame.h"

#include "common_config.h"

class ngpodwcMiniPanel: public GUIdialog_minipanel
{

public:
    ngpodwcMiniPanel(wxDialog *frame);
    ~ngpodwcMiniPanel();

    ngpodwcConfig config;

private:
    ;

};

class ngpodwcConfigPanel: public GUIdialog_configpanel
{

public:
    ngpodwcConfigPanel(wxFrame *frame);
    ~ngpodwcConfigPanel();

    ngpodwcConfig config;

private:
    void OnButtonAboutClick( wxCommandEvent& event );
    void OnButtonQuitClick( wxCommandEvent& event )
    {
        Destroy();
    }

};

class ngpodwcAbout: public GUIdialog_about
{

public:
    ngpodwcAbout(wxFrame *frame);
    ~ngpodwcAbout();

private:
    void OnButtonOKClick( wxCommandEvent& event )
    {
        Destroy();
    }

};

#endif // NGPODWCMAIN_H_INCLUDED
