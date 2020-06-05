
// MFC-05-11View.cpp : CMFC0511View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC0511View ����/����

CMFC0511View::CMFC0511View()
	: CRecordView(IDD_MFC0511_FORM)
	, name(_T(""))
	, number(0)
	, sex(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\vcʵ����\\11 ��ʵ��\\ͼƬ\\");
}

CMFC0511View::~CMFC0511View()
{
}

void CMFC0511View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
}

BOOL CMFC0511View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC0511View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC0511Set;
	CRecordView::OnInitialUpdate();

}


// CMFC0511View ���

#ifdef _DEBUG
void CMFC0511View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC0511View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC0511Doc* CMFC0511View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC0511Doc)));
	return (CMFC0511Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC0511View ���ݿ�֧��
CRecordset* CMFC0511View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC0511View ��Ϣ�������


void CMFC0511View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC0511View::OnBnClickedButtonShowPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

