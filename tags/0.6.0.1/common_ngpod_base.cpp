#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "common_ngpod_base.h"

NGPODBase::NGPODBase()
{
    //ctor
}

NGPODBase::~NGPODBase()
{
    //dtor
}

wxString NGPODBase::RemoveSpace(wxString inString)
{
    //将连续的空格变为1个空格
    while(inString.Contains(wxT("  ")))
    {
        inString.Replace(wxT("  "), wxT(" "), true);
    }

    //将开头的空格去掉
    wxString outString;
    if (inString.StartsWith(wxT(" "), &outString))
    {
        //空格开头
    }
    else
    {
        //非空格开头
        outString = inString;
    }

    return outString;
}

void NGPODBase::FixNGPODDisc()
//这个版本对应NGPOD保存的Disc信息
{
    if(NGPODDisc.Contains(wxT("#")))
    {
        NGPODDisc.Replace(wxT("#034"), wxT("\""), true);
        NGPODDisc.Replace(wxT("#039"), wxT("\'"), true);

        NGPODDisc.Replace(wxT("#133"), wxT("..."), true);//...

        NGPODDisc.Replace(wxT("#145"), wxT("\'"), true);//‘
        NGPODDisc.Replace(wxT("#146"), wxT("\'"), true);//’

        NGPODDisc.Replace(wxT("#147"), wxT("\""), true);//“
        NGPODDisc.Replace(wxT("#148"), wxT("\""), true);//”

        NGPODDisc.Replace(wxT("#151"), wxT("\'"), true);//＇
    }
    return;
    //
    NGPODDisc.Replace(wxT("<BR>"), wxT(""), true);
    NGPODDisc.Replace(wxT("<P>"), wxT(""), true);
    NGPODDisc.Replace(wxT("</P>"), wxT(""), true);
    NGPODDisc.Replace(wxT("<I>"), wxT(""), true);
    NGPODDisc.Replace(wxT("</I>"), wxT(""), true);

    NGPODDisc.Replace(wxT("\n"), wxT(""), true);
    NGPODDisc.Replace(wxT(".\n"), wxT("."), true);
    NGPODDisc.Replace(wxT(". "), wxT(". \n "), true);
    NGPODDisc.Replace(wxT(" \n \n"), wxT(" \n"), true);

    NGPODDisc.Replace(wxT(".\'\" "), wxT(".\'\" \n "), true);
}
