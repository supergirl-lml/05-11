
// MFC-05-11Set.cpp : CMFC0511Set ���ʵ��
//

#include "stdafx.h"
#include "MFC-05-11.h"
#include "MFC-05-11Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC0511Set ʵ��

// ���������� 2020��6��5��, 21:51

IMPLEMENT_DYNAMIC(CMFC0511Set, CRecordset)

CMFC0511Set::CMFC0511Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = 0;
	column3 = L"";
	column4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC0511Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\MyProject.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC0511Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��1]");
}

void CMFC0511Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Long(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[�Ա�]"), column3);
	RFX_Text(pFX, _T("[��Ƭ]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC0511Set ���

#ifdef _DEBUG
void CMFC0511Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC0511Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

