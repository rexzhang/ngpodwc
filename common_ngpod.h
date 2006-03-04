#ifndef COMMON_NGPOD_H
#define COMMON_NGPOD_H

#include "ngpodwc_common_config.h"

#include "ngpodwc_common_ngpodinfo.h"

class NGPOD
{
    public:
        NGPOD(ngpodwcConfig programConfig);
        bool Init();
        virtual ~NGPOD();


        //成员函数
        bool DrawText();
        bool NGPOD::SaveWallpaper();

        //成员变量
        wxImage Image;

    protected:
    private:
        ngpodinfo podPictureInfo;
        ngpodwcConfig config;
};

#endif // COMMON_NGPOD_H
