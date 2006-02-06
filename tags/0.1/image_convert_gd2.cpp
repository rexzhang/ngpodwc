//GD2 Lib Support
#include "gd.h"


bool outputScreenPictureGD2(ngpodwcConfig *pConfig, PodPictrueInfo *pPodPictureInfo)
//return 1 = true/Finish
{
    gdImagePtr im;

    FILE *in;
    in = fopen("MM6664_421.jpg", "rb");
    im = gdImageCreateFromJpeg(in);
    fclose(in);

    int black, white;
    FILE *out;
    /* Allocate background */
    white = gdImageColorAllocate(im, 255, 255, 255);
    /* Allocate drawing color */
    black = gdImageColorAllocate(im, 0, 0, 0);
    /* Draw rectangle */
    gdImageRectangle(im, 0, 0, 99, 99, black);
    /* Open output file in binary mode */
    out = fopen("screen.bmp", "wb");
    /* Write WBMP, with black as foreground */
    gdImageWBMP(im, black, out);
    /* Close file */
    fclose(out);
    /* Destroy image */
    gdImageDestroy(im);
};
