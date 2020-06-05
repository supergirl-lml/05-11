
// MFC-05-11View.cpp : CMFC0511View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-05-11.h"
#endif

#include "MFC-05-11Set.h"
#include "MFC-05-11Doc.h"
#include "MFC-05-11View.h"
#include"ShowDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC0511View

IMPLEMENT_DYNCREATE(CMFC0511View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC0511View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC0511View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CMFC0511View::OnRecordLast)
	ON_COMMAND(ID_RECORD_PREV, &CMFC0511View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC0511View::OnRecordNext)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC0511View::OnBnClickedButtonShowPicture)
END_MESSAGE_MAP()

// CMFC0511View 构造/析构

CMFC0511View::CMFC0511View()
	: CRecordView(IDD_MFC0511_FORM)
	, name(_T(""))
	, number(0)
	, sex(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\vc实验题\\11 差实验\\图片\\");
}

CMFC0511View::~CMFC0511View()
{
}

void CMFC0511View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
}

BOOL CMFC0511View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC0511View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC0511Set;
	CRecordView::OnInitialUpdate();

}


// CMFC0511View 诊断

#ifdef _DEBUG
void CMFC0511View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC0511View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC0511Doc* CMFC0511View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC0511Doc)));
	return (CMFC0511Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC0511View 数据库支持
CRecordset* CMFC0511View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC0511View 消息处理程序


void CMFC0511View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnBnClickedButtonShowPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowDlg  dlg;
	m_pSet->GetFieldValue(short(4),s);
	filename = path + s;

	UpdateData(true);
	dlg.file = filename;
	UpdateData(false);
	int r = dlg.DoModal();
	if (r == IDOK) {

	}
}

