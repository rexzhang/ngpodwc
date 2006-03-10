#ifndef COMOON_NGPOD_BASE_H
#define COMOON_NGPOD_BASE_H

class NGPODBase
{
    public:
        NGPODBase();
        virtual ~NGPODBase();

        //��Ա����
        wxString NGPODBase::RemoveSpace(wxString inString);
        void NGPODBase::FixNGPODDisc();
        //��Ա����
        wxString NGPODTitle;
        wxDateTime NGPODDate;//���ڴ洢ָ��������
        int Year, Month, Mday;//���ڴ洢ָ�������ڵķָ��ʽ

        wxString NGPODWhere;
        wxString NGPODWhen;
        wxString NGPODWho;
        wxString NGPODDisc;
        wxString NGPODRelated;

        wxString NGPODPictureName;//���ڴ洢��ȡ��ָ�����ڵ�ͼƬ�ļ���
    protected:
    private:
};

#endif // COMOON_NGPOD_BASE_H
