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
    //�������Ŀո��Ϊ1���ո�
    while(inString.Contains(wxT("  ")))
    {
        inString.Replace(wxT("  "), wxT(" "), true);
    }

    //����ͷ�Ŀո�ȥ��
    wxString outString;
    if (inString.StartsWith(wxT(" "), &outString))
    {
        //�ո�ͷ
    }
    else
    {
        //�ǿո�ͷ
        outString = inString;
    }

    return outString;
}

void NGPODBase::FixNGPODDisc()
//����汾��ӦNGPOD�����Disc��Ϣ
{
    if(NGPODDisc.Contains(wxT("#")))
    {
        NGPODDisc.Replace(wxT("#034"), wxT("\""), true);
        NGPODDisc.Replace(wxT("#039"), wxT("\'"), true);

        NGPODDisc.Replace(wxT("#133"), wxT("..."), true);//...

        NGPODDisc.Replace(wxT("#145"), wxT("\'"), true);//��
        NGPODDisc.Replace(wxT("#146"), wxT("\'"), true);//��

        NGPODDisc.Replace(wxT("#147"), wxT("\""), true);//��
        NGPODDisc.Replace(wxT("#148"), wxT("\""), true);//��

        NGPODDisc.Replace(wxT("#151"), wxT("\'"), true);//��
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
