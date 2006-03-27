/////////////////////////////////////////////////////////////////////////////
// Name:        ngpodwc_common_datetime.h
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     2006-02-13
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////

#include <wx/datetime.h>

bool tmSeekDays(int seek, tm *pTmIn);
bool seekDays(int seek, int *year, int *month, int *day);
bool seekDays(int seek, wxDateTime *inDate);

time_t wxDateTicks(int year, int month, int mday);
time_t wxDateTicks(wxDateTime InDate);

void toWxDateTime(int year, int month, int mday, wxDateTime *date);
void toDate(wxDateTime inDate, int *year, int *month, int *mday);

