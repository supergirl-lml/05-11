
// MFC-05-11-3View.cpp : CMFC05113View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-05-11-3.h"
#endif

#include "MFC-05-11-3Set.h"
#include "MFC-05-11-3Doc.h"
#include "MFC-05-11-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC05113View

IMPLEMENT_DYNCREATE(CMFC05113View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC05113View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFC05113View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC05113View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC05113View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC05113View::OnRecordLast)
END_MESSAGE_MAP()

// CMFC05113View 构造/析构

CMFC05113View::CMFC05113View()
	: CRecordView(IDD_MFC05113_FORM)
	, name(_T(""))
	, number(0)
	, sex(_T(""))
	, photo(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\vc实验题\\11 差实验\\图片\\");

}

CMFC05113View::~CMFC05113View()
{
}

void CMFC05113View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}

BOOL CMFC05113View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC05113View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC05113Set;
	CRecordView::OnInitialUpdate();

}


// CMFC05113View 诊断

#ifdef _DEBUG
void CMFC05113View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC05113View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC05113Doc* CMFC05113View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC05113Doc)));
	return (CMFC05113Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC05113View 数据库支持
CRecordset* CMFC05113View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC05113View 消息处理程序


void CMFC05113View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = path + s;
	CImage img;
	img.Load(filename);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;//图片左上角点的位置和宽高
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);

	float cr_ratio = 1.0 * cr.Width() / cr.Height();
	float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{//客户区宽高比大于图像
		h = cr.Height();//图片高度
		w = img_ratio * h;//图片宽度
		sx = (cr.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CMFC05113View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}
