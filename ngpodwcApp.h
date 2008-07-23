/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcApp.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2008-4-21
// RCS-ID:
// Copyright:   (c) 2008 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifndef NGPODWCAPP_H
#define NGPODWCAPP_H

#include <wx/app.h>

#include "common_config.h"

class ngpodwcApp : public wxApp
{
public:
    virtual bool OnInit();

    //ngpodwcConfig config;

    //ngpodwcConfig configRunning;//保存运行中的配置
    //ngpodwcConfig configStarting;//保持配置文件中的配置
    //ngpodinfo pictureInfo;
protected:
    wxLocale m_locale; // locale we'll be using
private:

};

#endif // NGPODWCAPP_H
