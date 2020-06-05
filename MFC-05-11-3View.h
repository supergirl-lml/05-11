
// MFC-05-11-3View.h : CMFC05113View 类的接口
//

#pragma once

class CMFC05113Set;

class CMFC05113View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC05113View();
	DECLARE_DYNCREATE(CMFC05113View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC05113_FORM };
#endif
	CMFC05113Set* m_pSet;

// 特性
public:
	CMFC05113Doc* GetDocument() const;

// 操作
public:
	CString path;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC05113View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC-05-11-3View.cpp 中的调试版本
inline CMFC05113Doc* CMFC05113View::GetDocument() const
   { return reinterpret_cast<CMFC05113Doc*>(m_pDocument); }
#endif

