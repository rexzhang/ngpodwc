/////////////////////////////////////////////////////////////////////////////
// Name:        %SOURCE-FILENAME%
// Purpose:
// Author:      %AUTHOR%
// Modified by:
// Created:     2006-02-13
// RCS-ID:
// Copyright:   %COPYRIGHT%
// Licence:
/////////////////////////////////////////////////////////////////////////////
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "ngpodwc_common_datetime.h"

// ----------------------------------------------------------------------------
//!在给定的tm日期结构中移动（+向后移动 / -向前移动）指定的一个日期
// ----------------------------------------------------------------------------
//
bool tmSeekDays(int seek, tm *pTmIn)
{
    tm *pTmTemp;
    time_t time_tTemp;


    //转换到time_t格式
    time_tTemp = mktime(pTmIn);

    //加上seek天的秒数
    time_tTemp += seek*(24*60*60);

    //转换到tm结构
    pTmTemp = localtime(&time_tTemp);

    pTmIn->tm_year = pTmTemp->tm_year;
    pTmIn->tm_mon = pTmTemp->tm_mon;
    pTmIn->tm_mday = pTmTemp->tm_mday;

    return true;
}

// ----------------------------------------------------------------------------
//!在给定的日期基础上移动一个指定的日期
// ----------------------------------------------------------------------------
//
bool seekDays(int seek, int *year, int *month, int *day)
{
    //转换年月日至tm格式
    tm tmIn;
    tmIn.tm_sec = 0;
    tmIn.tm_min = 0;
    tmIn.tm_hour = 0;
    tmIn.tm_mday = *day;
    tmIn.tm_mon = *month;
    tmIn.tm_year = *year - 1900;
    tmIn.tm_wday = 0;
    tmIn.tm_yday = 0;
    tmIn.tm_isdst = 0;

    //
    tm *pTmTemp;
    time_t time_tTemp;

    //转换tm到time_t格式
    time_tTemp = mktime(&tmIn);

    //加上seek天的秒数
    time_tTemp += seek*(24*60*60);

    //转换time_t到tm结构
    pTmTemp = localtime(&time_tTemp);

    //无用步骤，范例用
    /*
    tmIn.tm_year = pTmTemp->tm_year;
    tmIn.tm_mon = pTmTemp->tm_mon;
    tmIn.tm_mday = pTmTemp->tm_mday;
    */

    *year = pTmTemp->tm_year + 1900;
    *month = pTmTemp->tm_mon;
    *day = pTmTemp->tm_mday;

    return true;
}

// ----------------------------------------------------------------------------
//!在给定的日期wxDateTime基础上移动一个指定的日期
// ----------------------------------------------------------------------------
//
bool seekDays(int seek, wxDateTime *inDate)
{
    int year, month, mday;

    toDate(*inDate, &year, &month, &mday);

    seekDays(seek, &year, &month, &mday);

    toWxDateTime(year, month, mday, inDate);

    return true;
}

// ----------------------------------------------------------------------------
//!将给定的日期转换成wxWidget ODBC-Access的Date数字格式
// ----------------------------------------------------------------------------
//
time_t wxDateTicks(int year, int month, int mday)
{
    //生成ODBC-Access的Date数字格式
    //用tm格式生成wxDateTime格式，然后使用GetTicks转换成time_t格式
    //再除以(24*60*60) 加上25539值,25539=(1970-1900)*date ticks
    //time_t use 1900 base year
    //wxWidget use 1970 base year

    tm TmTemp;
    //wxDateTime PodDateTime;
    //time_t time_tTemp;

    TmTemp.tm_sec = 0;
    TmTemp.tm_min = 0;
    TmTemp.tm_hour = 0;
    TmTemp.tm_mday = mday;
    TmTemp.tm_mon = month;
    //TmTemp.tm_year = 2004-1900;
    TmTemp.tm_year = year - 1900;
    TmTemp.tm_wday = 0;
    TmTemp.tm_yday = 0;
    TmTemp.tm_isdst = 0;

    /*
    //PodDateTime = wxDateTime::wxDateTime(TmTemp);
    //time_tTemp = PodDateTime.GetTicks();

    time_tTemp = mktime(&TmTemp); //等价上面的程序

    time_tTemp = time_tTemp/(24*60*60) + 25539;

    //table->SetWhereClause(wxT("Pod_Date <= 40000 AND Pod_Date >= 37999"));

    */
    return mktime(&TmTemp)/(24*60*60) + 25539;
}
// ----------------------------------------------------------------------------
//!将给定的wxDateTime转换成wxWidget ODBC-Access的Date数字格式
// ----------------------------------------------------------------------------
//
time_t wxDateTicks(wxDateTime InDate)
{
    //生成ODBC-Access的Date数字格式
    //用tm格式生成wxDateTime格式，然后使用GetTicks转换成time_t格式
    //再除以(24*60*60) 加上25539值,25539=(1970-1900)*date ticks
    //time_t use 1900 base year
    //wxWidget use 1970 base year


    //wxDateTime PodDateTime;
    time_t time_tTemp;

    time_tTemp = InDate.GetTicks();

    time_tTemp = time_tTemp/(24*60*60) + 25539;

    //table->SetWhereClause(wxT("Pod_Date <= 40000 AND Pod_Date >= 37999"));


    return time_tTemp;
}
// ----------------------------------------------------------------------------
//!将给定的日期转换成wxWidget wxDateTime格式
// ----------------------------------------------------------------------------
void toWxDateTime(int year, int month, int mday, wxDateTime *date)
{
    tm TmTemp;
    //wxDateTime PodDateTime;
    //time_t time_tTemp;

    TmTemp.tm_sec = 0;
    TmTemp.tm_min = 0;
    TmTemp.tm_hour = 0;
    TmTemp.tm_mday = mday;
    TmTemp.tm_mon = month;
    //TmTemp.tm_year = 2004-1900;
    TmTemp.tm_year = year - 1900;
    TmTemp.tm_wday = 0;
    TmTemp.tm_yday = 0;
    TmTemp.tm_isdst = 0;

    //wxDateTime& wxDateTime(const struct tm& tm)

    date->Set(TmTemp);

    return;
}

// ----------------------------------------------------------------------------
//!将wxWidget wxDateTime日期格式 转换成格年月日
// ----------------------------------------------------------------------------
void toDate(wxDateTime inDate, int *year, int *month, int *mday)
{
    tm *pTmTemp;
    time_t time_tTemp;

    time_tTemp = inDate.GetTicks();//GetTicks Returns the number of seconds since Jan 1, 1970.
    pTmTemp = localtime(&time_tTemp);

    *year = pTmTemp->tm_year + 1900;
    *month = pTmTemp->tm_mon;
    *mday = pTmTemp->tm_mday;

    return;
}
