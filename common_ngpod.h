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


        //��Ա����
        bool DrawText();
        bool NGPOD::SaveWallpaper();

        //��Ա����
        wxImage Image;

    protected:
    private:
        ngpodinfo podPictureInfo;
        ngpodwcConfig config;
};

#endif // COMMON_NGPOD_H
