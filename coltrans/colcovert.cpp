#include "stdafx.h"
#include "colcovert.h"
#define ERR 0.000001f
void _findmm(COL1 *max,COL1 *min,...)//the last is -1
{
	va_list argptr;
	va_start(argptr,min);
	COL1 num;
	num=va_arg(argptr,COL1);
	*max=*min=num;
	while(num -(-1) >=ERR)
	{
		if(num>*max) *max=num;
		if(num<*min) *min=num;
		num=va_arg(argptr,COL1);
	}
	va_end(argptr);
}
int rgb2yuv(COLRGB *rgb,COLYUV *yuv)
{
	/* yuv -128~127
	Y = kr R + (1-kb-kr)G + kb B
	Cb = 0.5/(1-kb) * (B-Y)
	Cr = 0.5/(1-kr) * (R-Y)
	R = Y + (1-kr)/0.5 * Cr
	G = Y - 2kb(1-kb)/(1-kb-kr) * Cb - 2kr(1-kr)/(1-kb-kr) * Cr
	B = Y + (1-kb)/0.5 * Cb
	*/
	yuv->y=(COL255)(0.299*(double)rgb->r+0.587*(double)rgb->g+0.114*(double)rgb->b);
	yuv->u=(COL255)(0.564*(double)(rgb->b-yuv->y))+128;
	yuv->v=(COL255)(0.713*(double)(rgb->r-yuv->y))+128;
	//COLRGB rgb2;
	//yuv2rgb(yuv,&rgb2);
	return 0;
}
int rgb2cmy(COLRGB *rgb,COLCMY *cmy)
{
	cmy->c=255-rgb->r;
	cmy->m=255-rgb->g;
	cmy->y=255-rgb->b;
	return 0;
}
int rgb2hsv(COLRGB *rgb,COLHSV *hsv)
{
	//initial
	COL1 r1,g1,b1;
	COL1 max,min;
	r1=(double)rgb->r/255;
	g1=(double)rgb->g/255;
	b1=(double)rgb->b/255;
	double c=ERR;
	_findmm(&max,&min,r1,g1,b1,-1.0);
	//H
	if(max-min <= ERR)
		hsv->h=0;
	else if(max-r1<=ERR && g1>=b1)
		hsv->h=60*(g1-b1)/(max-min)+0;
	else if(max-r1<=ERR && g1<b1)
		hsv->h=60*(g1-b1)/(max-min)+360;
	else if(max-g1<=ERR)
		hsv->h=60*(b1-r1)/(max-min)+120;
	else if(max-b1<=ERR)
		hsv->h=60*(r1-g1)/(max-min)+240;
	//S
	if(max-0 <= ERR)
		hsv->s=0;
	else
		hsv->s=1-min/max;
	//V
	hsv->v=max;
	//COLRGB rgb2;
	//hsv2rgb(hsv,&rgb2);
	return 0;
}
int rgb2hsl(COLRGB *rgb,COLHSL *hsl)
{
	//initial
	COL1 r1,g1,b1;
	COL1 max,min;
	r1=(double)rgb->r/255;
	g1=(double)rgb->g/255;
	b1=(double)rgb->b/255;
	double c=ERR;
	_findmm(&max,&min,r1,g1,b1,-1.0);
	//H
	if(max-min <= ERR)
		hsl->h=0;
	else if(max-r1<=ERR && g1>=b1)
		hsl->h=60*(g1-b1)/(max-min)+0;
	else if(max-r1<=ERR && g1<b1)
		hsl->h=60*(g1-b1)/(max-min)+360;
	else if(max-g1<=ERR)
		hsl->h=60*(b1-r1)/(max-min)+120;
	else if(max-b1<=ERR)
		hsl->h=60*(r1-g1)/(max-min)+240;
	//L
	hsl->l=(max+min)/2;
	//S
	if(hsl->l -0 <= ERR || max-min <= ERR)
		hsl->s=0;
	else if(hsl->l >0 && hsl->l <=0.5)
		hsl->s=(max-min)/(max+min);
	else
		hsl->s=(max-min)/(2-(max+min));

	//COLRGB rgb2;
	//hsl2rgb(hsl,&rgb2);
	return 0;
}
int hsl2rgb(COLHSL *hsl,COLRGB *rgb)
{
	COL1 col[3];//rgb
	COL1 p,q,hk,tcol[3];
	int i;
	if(hsl->s - 0 <= ERR)
	{
		col[0]=col[1]=col[2]=hsl->l;
	}
	else
	{
		if(hsl->l < 0.5)
			q=hsl->l * (hsl->l + hsl->s);
		else
			q=hsl->l + hsl->s - (hsl->l * hsl->s);
		p=2*hsl->l - q;
		hk=hsl->h /360;
		tcol[0]=hk+ 1.0/3.0;
		tcol[1]=hk;
		tcol[2]=hk-1.0/3.0;
		for(i=0;i<3;i++)
		{
			if(tcol[i]<0) tcol[i]+=1.0;
			else if(tcol[i]>1) tcol[i]-=1.0;
		}
		for(i=0;i<3;i++)
		{
			if(tcol[i]<1.0/6.0)
				col[i]=p+((q-p)*6*tcol[i]);
			else if(tcol[i]>=1.0/6.0 && tcol[i]<1.0/2.0)
				col[i]=q;
			else if(tcol[i]>=1.0/2.0 && tcol[i]<2.0/3.0)
				col[i]=p+((q-p)*6*(2.0/3.0-tcol[i]));
			else
				col[i]=p;
		}
	}
	rgb->r=(COL255)(col[0]*255);
	rgb->g=(COL255)(col[1]*255);
	rgb->b=(COL255)(col[2]*255);
	return 0;
}
int hsv2rgb(COLHSV *hsv,COLRGB *rgb)
{
	int hi;
	COL1 r1,g1,b1;
	COL1 f,p,q,t;
	hi=(int )floor(hsv->h/60)%6;
	f=hsv->h/60 -hi;
	p=hsv->v * (1-hsv->s);
	q=hsv->v * (1-f*hsv->s);
	t=hsv->v * (1-(1-f)*hsv->s);
	switch(hi)
	{
		case 0:
			r1=hsv->v;g1=t;b1=p;
			break;
		case 1:
			r1=q;g1=hsv->v;b1=p;
			break;
		case 2:
			r1=p;g1=hsv->v;b1=t;
			break;
		case 3:
			r1=p;g1=q;b1=hsv->v;
			break;
		case 4:
			r1=t;g1=p;b1=hsv->v;
			break;
		case 5:
			r1=hsv->v;g1=p;b1=q;
			break;
	}
	rgb->r=(COL255)(r1*255);
	rgb->g=(COL255)(g1*255);
	rgb->b=(COL255)(b1*255);
	return 0;
}
int cmy2rgb(COLCMY *cmy,COLRGB *rgb)
{
	rgb->r=255-cmy->c;
	rgb->g=255-cmy->m;
	rgb->b=255-cmy->y;
	return 0;
}
int yuv2rgb(COLYUV *yuv,COLRGB *rgb)
{
	rgb->r=(COL255)((double)yuv->y+1.402*(double)(yuv->v-128));
	rgb->g=(COL255)((double)yuv->y-0.344*(double)(yuv->u-128)-0.714*(double)(yuv->v-128));
	rgb->b=(COL255)((double)yuv->y+1.772*(double)(yuv->u-128));
	return 0;
}