
// coltrans.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcoltransApp:
// �йش����ʵ�֣������ coltrans.cpp
//

class CcoltransApp : public CWinApp
{
public:
	CcoltransApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcoltransApp theApp;