#ifndef COMOON_NGPOD_BASE_H
#define COMOON_NGPOD_BASE_H

class NGPODBase
{
    public:
        NGPODBase();
        virtual ~NGPODBase();

        //成员函数

        //成员变量
        wxString Title;
        wxDateTime Date;
        wxString Where;
        wxString When;
        wxString Who;
        wxString Disc;
        wxString Related;
        wxString PictureName;
    protected:
    private:
};

#endif // COMOON_NGPOD_BASE_H
