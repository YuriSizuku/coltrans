#include <math.h>
#include <stdarg.h>
#include "coltype.h"
int rgb2yuv(COLRGB *rgb,COLYUV *yuv);//0 success,-1 fail,now ignore the return
int rgb2cmy(COLRGB *rgb,COLCMY *cmy);
int rgb2hsv(COLRGB *rgb,COLHSV *hsv);
int rgb2hsl(COLRGB *rgb,COLHSL *hsl);//may be 1 scale error, or use round, floor will be inacurate
int hsl2rgb(COLHSL *hsl,COLRGB *rgb);
int hsv2rgb(COLHSV *hsv,COLRGB *rgb);
int cmy2rgb(COLCMY *cmy,COLRGB *rgb);
int yuv2rgb(COLYUV *yuv,COLRGB *rgb);