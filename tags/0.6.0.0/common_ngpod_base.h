#ifndef COMOON_NGPOD_BASE_H
#define COMOON_NGPOD_BASE_H

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

#endif // COMOON_NGPOD_BASE_H
