
// MFC-05-11.h : MFC-05-11 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC0511App:
// �йش����ʵ�֣������ MFC-05-11.cpp
//

class CMFC0511App : public CWinApp
{
public:
	CMFC0511App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC0511App theApp;
