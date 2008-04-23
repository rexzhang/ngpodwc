/////////////////////////////////////////////////////////////////////////////
// Name:        common_globals.cpp
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-17
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////


#include "common_globals.h"
#include "version.h"


const wxString g_AppVendor              = wxT("Rex Zhang");
const wxString g_AppName			    = wxT("NGPODWC");
const wxString g_AppVersion             = (wxString(AutoVersion::FULLVERSION_STRING ,wxConvUTF8)
                                            + wxT(" ") + wxString(AutoVersion::STATUS ,wxConvUTF8)
                                            + wxT(" Bulid ") + wxString::Format(wxT("%d") ,AutoVersion::BUILDS_COUNT));
//const wxString g_AppActualVersionVerb	= wxT("1.0 revision " SVN_REVISION);
//const wxString g_AppActualVersion		= wxT("1.0-r" SVN_REVISION);
const wxString g_AppUrl 				= wxT("https://sourceforge.net/project/ngpodwc");
const wxString g_AppUrl2				= wxT("http://swik.net/ngpodwc");
const wxString g_AppUrl3				= wxT("http://flord.net");

//const wxString g_AppContactEmail		= wxT("rex.zhang@gmail.com");

const wxString g_AppProjectLeader		= wxT("Rex Zhang");
const wxString g_AppProjectLeaderEmail	= wxT("rex.zhang@gmail.com");

#if defined(__WXMSW__)

const wxString g_AppPlatform = wxT("Windows");
#elif defined(__WXOS2__)

const wxString g_AppPlatform = wxT("OS/2");
#elif defined(__WXMAC__)

const wxString g_AppPlatform = wxT("Mac OS X");
#elif defined(__FreeBSD__)

const wxString g_AppPlatform = wxT("FreeBSD");
#elif defined(__UNIX__)

const wxString g_AppPlatform = wxT("Linux");
#else

const wxString g_AppPlatform = _T("Unknown");
#endif

#if wxUSE_UNICODE

const wxString g_AppWXAnsiUnicode = _T("unicode");
#else

const wxString g_AppWXAnsiUnicode = _T("ANSI");
#endif

const wxString g_AppBuildTimestamp = (wxString(wxT(__DATE__)) + wxT(", ") + wxT(__TIME__) + wxT(" - wx") + wxString(wxT(wxVERSION_NUM_DOT_STRING)) + wxT(" (") + g_AppPlatform + wxT(", ") + g_AppWXAnsiUnicode + wxT(")") );

//const wxString g_DefaultBatchBuildArgs = wxT("-na -nd -ns --batch-build-notify");

operating_system_t __cb_get_os()
{
#if defined(__FreeBSD__)
    return osFreeBSD;
#elif defined(__UNIX__)

    return osLinux;
#elif defined(__WXMAC__)

    return osOSX;
#elif defined(__WXOS2__)

    return osOS2;
#elif defined(__WXMSW__)

    int Major = 0;
    int family = wxGetOsVersion(&Major, NULL);
    if(family == wxWIN95)
        return osWindows9598ME;
    if(family == wxWINDOWS_NT)
    {
        if(Major > 4)
            return osWindowsXP;
        else
            return osWindowsNT2000;
    }
    else
        return osUnknownWindows;
#else
#error Unable to determine OS
#endif
};

operating_system_t OS()
{
    static operating_system_t theOS = __cb_get_os();
    return theOS;
}

const wxString g_AppLanguageNames[LANGUAGES_SIZE] =
    {
        wxT("(System default)")   // Do *not* translate. If you do, people may be unable to switch back if they accidentially change the language
        ,_("Chinese (Simplified)")
        //        ,wxT("English (U.S.)")
        ,_("English")
        //        ,_("German")
        //        ,_("Russian")
    };

// Must have the same order than the above
const int g_AppLanguageCodes[LANGUAGES_SIZE] =
    {
        wxLANGUAGE_DEFAULT
        ,wxLANGUAGE_CHINESE_SIMPLIFIED
        //        ,wxLANGUAGE_ENGLISH_US
        ,wxLANGUAGE_ENGLISH
        //        ,wxLANGUAGE_GERMAN
        //        ,wxLANGUAGE_RUSSIAN
    };

ngpodwcConfig configStarting;
ngpodwcConfig configRunning;
