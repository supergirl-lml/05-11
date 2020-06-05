
// MFC-05-11View.h : CMFC0511View ��Ľӿ�
//

#pragma once

class CMFC0511Set;

class CMFC0511View : public CRecordView
{
protected: // �������л�����
	CMFC0511View();
	DECLARE_DYNCREATE(CMFC0511View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC0511_FORM };
#endif
	CMFC0511Set* m_pSet;

// ����
public:
	CMFC0511Doc* GetDocument() const;

// ����
public:
	CString path;
	CString filename, s;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC0511View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	long number;
	CString sex;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnBnClickedButtonShowPicture();
};

#ifndef _DEBUG  // MFC-05-11View.cpp �еĵ��԰汾
inline CMFC0511Doc* CMFC0511View::GetDocument() const
   { return reinterpret_cast<CMFC0511Doc*>(m_pDocument); }
#endif

