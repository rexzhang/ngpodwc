/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc.h
// Purpose:
// Author:      rex zhang
// Modified by:
// Created:     23/02/2006 12:18:54
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifndef _NGPODWC_H_
#define _NGPODWC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwc.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
////@end includes
#include "wx/splash.h"


#include "dialog_mini_panel.h"

#include "common_wallpaper_operation.h"
#include "common_config.h"
#include "ngpodwc_common_ngpodinfo.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * NgpodwcApp class declaration
 */

class NgpodwcApp: public wxApp
{
    DECLARE_CLASS( NgpodwcApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    NgpodwcApp();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin NgpodwcApp event handler declarations

////@end NgpodwcApp event handler declarations

////@begin NgpodwcApp member function declarations

////@end NgpodwcApp member function declarations

////@begin NgpodwcApp member variables
////@end NgpodwcApp member variables
    ngpodwcConfig config;
    //ngpodinfo pictureInfo;
protected:
    wxLocale m_locale; // locale we'll be using
};

/*!
 * Application instance declaration
 */

////@begin declare app
DECLARE_APP(NgpodwcApp)
////@end declare app

#endif
    // _NGPODWC_H_
