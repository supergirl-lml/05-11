
// MFC-05-11-3.h : MFC-05-11-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC05113App:
// �йش����ʵ�֣������ MFC-05-11-3.cpp
//

class CMFC05113App : public CWinApp
{
public:
	CMFC05113App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC05113App theApp;
