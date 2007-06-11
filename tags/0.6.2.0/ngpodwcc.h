/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwcc.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     07/02/2006 16:58:25
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////

#ifndef _NGPODWCC_H_
#define _NGPODWCC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ngpodwcc.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "dialog_config_panel.h"
////@end includes

#include "common_config.h"

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
 * NgpodwccApp class declaration
 */

class NgpodwccApp: public wxApp
{
    DECLARE_CLASS( NgpodwccApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    NgpodwccApp();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin NgpodwccApp event handler declarations

////@end NgpodwccApp event handler declarations

////@begin NgpodwccApp member function declarations

////@end NgpodwccApp member function declarations

////@begin NgpodwccApp member variables
////@end NgpodwccApp member variables
    ngpodwcConfig config;
protected:
    wxLocale m_locale; // locale we'll be using
};

/*!
 * Application instance declaration
 */

////@begin declare app
DECLARE_APP(NgpodwccApp)
////@end declare app

#endif
    // _NGPODWCC_H_
