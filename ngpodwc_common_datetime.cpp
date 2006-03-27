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
//!�ڸ�����tm���ڽṹ���ƶ���+����ƶ� / -��ǰ�ƶ���ָ����һ������
// ----------------------------------------------------------------------------
//
bool tmSeekDays(int seek, tm *pTmIn)
{
    tm *pTmTemp;
    time_t time_tTemp;


    //ת����time_t��ʽ
    time_tTemp = mktime(pTmIn);

    //����seek�������
    time_tTemp += seek*(24*60*60);

    //ת����tm�ṹ
    pTmTemp = localtime(&time_tTemp);

    pTmIn->tm_year = pTmTemp->tm_year;
    pTmIn->tm_mon = pTmTemp->tm_mon;
    pTmIn->tm_mday = pTmTemp->tm_mday;

    return true;
}

// ----------------------------------------------------------------------------
//!�ڸ��������ڻ������ƶ�һ��ָ��������
// ----------------------------------------------------------------------------
//
bool seekDays(int seek, int *year, int *month, int *day)
{
    //ת����������tm��ʽ
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

    //ת��tm��time_t��ʽ
    time_tTemp = mktime(&tmIn);

    //����seek�������
    time_tTemp += seek*(24*60*60);

    //ת��time_t��tm�ṹ
    pTmTemp = localtime(&time_tTemp);

    //���ò��裬������
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
//!�ڸ���������wxDateTime�������ƶ�һ��ָ��������
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
//!������������ת����wxWidget ODBC-Access��Date���ָ�ʽ
// ----------------------------------------------------------------------------
//
time_t wxDateTicks(int year, int month, int mday)
{
    //����ODBC-Access��Date���ָ�ʽ
    //��tm��ʽ����wxDateTime��ʽ��Ȼ��ʹ��GetTicksת����time_t��ʽ
    //�ٳ���(24*60*60) ����25539ֵ,25539=(1970-1900)*date ticks
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

    time_tTemp = mktime(&TmTemp); //�ȼ�����ĳ���

    time_tTemp = time_tTemp/(24*60*60) + 25539;

    //table->SetWhereClause(wxT("Pod_Date <= 40000 AND Pod_Date >= 37999"));

    */
    return mktime(&TmTemp)/(24*60*60) + 25539;
}
// ----------------------------------------------------------------------------
//!��������wxDateTimeת����wxWidget ODBC-Access��Date���ָ�ʽ
// ----------------------------------------------------------------------------
//
time_t wxDateTicks(wxDateTime InDate)
{
    //����ODBC-Access��Date���ָ�ʽ
    //��tm��ʽ����wxDateTime��ʽ��Ȼ��ʹ��GetTicksת����time_t��ʽ
    //�ٳ���(24*60*60) ����25539ֵ,25539=(1970-1900)*date ticks
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
//!������������ת����wxWidget wxDateTime��ʽ
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
//!��wxWidget wxDateTime���ڸ�ʽ ת���ɸ�������
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
