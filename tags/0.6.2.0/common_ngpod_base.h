/////////////////////////////////////////////////////////////////////////////
// Name:        common_ngpod_base.h
// Purpose:
// Author:      Rex Zhang
// Modified by:
// Created:     2006-03-08
// RCS-ID:
// Copyright:   (c) 2006 Rex Zhang
// Licence:     GNU General Public License (GPL) version 2
/////////////////////////////////////////////////////////////////////////////
#ifndef COMMON_NGPOD_BASE_H
#define COMMON_NGPOD_BASE_H

#include <wx/string.h>
#include <wx/datetime.h>

class NGPODBase
{
    public:
        NGPODBase();
        virtual ~NGPODBase();

        //成员函数
        wxString NGPODBase::RemoveSpace(wxString inString);
        void NGPODBase::FixNGPODDisc();
        //成员变量
        wxString NGPODTitle;
        wxDateTime NGPODDate;//用于存储指定的日期
        int Year, Month, Mday;//用于存储指定的日期的分割格式

        wxString NGPODWhere;
        wxString NGPODWhen;
        wxString NGPODWho;
        wxString NGPODDisc;
        wxString NGPODRelated;

        wxString NGPODPictureName;//用于存储获取的指定日期的图片文件名
    protected:
    private:
};

#endif // COMMON_NGPOD_BASE_H
