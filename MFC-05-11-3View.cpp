
// MFC-05-11-3View.cpp : CMFC05113View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC05113View ����/����

CMFC05113View::CMFC05113View()
	: CRecordView(IDD_MFC05113_FORM)
	, name(_T(""))
	, number(0)
	, sex(_T(""))
	, photo(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\vcʵ����\\11 ��ʵ��\\ͼƬ\\");

}

CMFC05113View::~CMFC05113View()
{
}

void CMFC05113View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}

BOOL CMFC05113View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC05113View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC05113Set;
	CRecordView::OnInitialUpdate();

}


// CMFC05113View ���

#ifdef _DEBUG
void CMFC05113View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC05113View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC05113Doc* CMFC05113View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC05113Doc)));
	return (CMFC05113Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC05113View ���ݿ�֧��
CRecordset* CMFC05113View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC05113View ��Ϣ�������


void CMFC05113View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = path + s;
	CImage img;
	img.Load(filename);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;//ͼƬ���Ͻǵ��λ�úͿ��
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);

	float cr_ratio = 1.0 * cr.Width() / cr.Height();
	float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{//�ͻ�����߱ȴ���ͼ��
		h = cr.Height();//ͼƬ�߶�
		w = img_ratio * h;//ͼƬ���
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
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC05113View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}
