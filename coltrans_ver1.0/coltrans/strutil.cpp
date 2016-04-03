#include <string.h>
#include "strutil.h"
#include "stdafx.h"
int str2intdex(char *str,int *out,int min,int max)
{
	int len=strlen(str),i;
	int tmp;
	if(len == 0) return -1;
	for(i=0;i<len;i++)
		if(str[i] <'0' || str[i]>'9')
		return -1;
	sscanf(str,"%d",&tmp);
	if(tmp > max || tmp < min) return -1;
	*out=tmp;
	return 0;
}
int str2inthex(char *str,unsigned int *out,unsigned int min,unsigned int max)
{
	int len=strlen(str),i;
	int tmp=max+1;
	if(len == 0) return -1;
	for(i=0;i<len;i++)
		if(!(str[i] >= '0' &&  str[i]<='9' 
			|| str[i] >='a' && str[i]<='f'
			|| str[i] >='A' && str[i]<='F'))
		return -1;
	sscanf(str,"%lx",&tmp);
	if(tmp > max || tmp < min) return -1;
	*out=tmp;
	return 0;
}
int str2double(char *str,double *out,double min,double max)
{
	int len=strlen(str),i;
	double tmp=max+1;
	if(len == 0) return -1;
	for(i=0;i<len;i++)
		if(!(str[i] >= '0' &&  str[i]<='9' || str[i]=='.'))
		return -1;
	sscanf(str,"%lf",&tmp);
	if(tmp > max || tmp < min) return -1;
	*out=tmp;
	return 0;
}
bool CopyToClipboard(char *data)
{
	bool res;
	if(res=OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;//内存区
		char *buffer;//内存区缓冲区
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, strlen(data)+1);//分配内存
		buffer = (char*)GlobalLock(clipbuffer);
		strcpy(buffer, LPCSTR(data));
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT,clipbuffer);
		CloseClipboard();
	}
	return res;
}