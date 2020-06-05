
// MFC-05-11-3View.h : CMFC05113View ��Ľӿ�
//

#pragma once

class CMFC05113Set;

class CMFC05113View : public CRecordView
{
protected: // �������л�����
	CMFC05113View();
	DECLARE_DYNCREATE(CMFC05113View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC05113_FORM };
#endif
	CMFC05113Set* m_pSet;

// ����
public:
	CMFC05113Doc* GetDocument() const;

// ����
public:
	CString path;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC05113View();
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
	CString photo;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFC-05-11-3View.cpp �еĵ��԰汾
inline CMFC05113Doc* CMFC05113View::GetDocument() const
   { return reinterpret_cast<CMFC05113Doc*>(m_pDocument); }
#endif

