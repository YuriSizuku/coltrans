/*
	color module's declearation
*/
#ifndef _COLTYPE_H
#define _COLTYPE_H
typedef double COL1;
typedef unsigned char COL255;
typedef struct _COLRGB
{
	COL255 r;
	COL255 g;
	COL255 b;
}COLRGB,*PCOLRGB;
typedef struct _COLYUV
{
	COL255 y;
	COL255 u;
	COL255 v;
}COLYUV,*PCOLYUV;
typedef struct _COLCMY
{
	COL255 c;
	COL255 m;
	COL255 y;
}COLCMY,*PCOLCMY;
typedef struct _COLHSV
{
	COL1 h;
	COL1 s;
	COL1 v;
}COLHSV,*PCOLHSV;
typedef struct _COLHSL
{
	COL1 h;
	COL1 s;
	COL1 l;
}COLHSL,*PCOLHSL;
#endif