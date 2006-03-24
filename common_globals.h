/////////////////////////////////////////////////////////////////////////////
// Name:        common_globals.h
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     %DATE%
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_GLOBALS_H
#define COMMON_GLOBALS_H

#include <wx/string.h>

extern const wxString g_AppVendor;
extern const wxString g_AppName;
extern const wxString g_AppVersion;
//extern const wxString g_AppActualVersionVerb;
//extern const wxString g_AppActualVersion;
extern const wxString g_AppUrl;
extern const wxString g_AppUrl2;
extern const wxString g_AppUrl3;
//extern const wxString g_AppContactEmail;
extern const wxString g_AppProjectLeader;
extern const wxString g_AppProjectLeaderEmail;
extern const wxString g_AppPlatform;
extern const wxString g_AppWXAnsiUnicode;
extern const wxString g_AppBuildTimestamp;

//extern const wxString g_DefaultBatchBuildArgs;

#define LOCALIZE    true
#define LANGUAGES_SIZE  3

extern const wxString g_AppLanguageNames[LANGUAGES_SIZE];
extern const int g_AppLanguageCodes[LANGUAGES_SIZE];

typedef enum
{
osUnknownWindows,
osWindows9598ME,
osWindowsNT2000,
osWindowsXP,
osFreeBSD,
osLinux,
osOS2,
osOSX
}operating_system_t;

operating_system_t OS();

#endif // COMMON_GLOBALS_H
