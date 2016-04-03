/*
  string and num change functions
*/
#ifndef _STRUTIL_H
#define _STRUTIL_H
int str2intdex(char *str,int *out,int min,int max);//0 valid,-1 error tbe functions down the same
int str2inthex(char *str,unsigned int *out,unsigned int min,unsigned int max);
int str2double(char *str,double *out,double min,double max);
bool CopyToClipboard(char *data);
#endif