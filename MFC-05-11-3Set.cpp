
// MFC-05-11-3Set.cpp : CMFC05113Set ���ʵ��
//

#include "stdafx.h"
#include "MFC-05-11-3.h"
#include "MFC-05-11-3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC05113Set ʵ��

// ���������� 2020��6��5��, 23:32

IMPLEMENT_DYNAMIC(CMFC05113Set, CRecordset)

CMFC05113Set::CMFC05113Set(CDatabase* pdb)
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
CString CMFC05113Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\MyProject.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC05113Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��1]");
}

void CMFC05113Set::DoFieldExchange(CFieldExchange* pFX)
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
// CMFC05113Set ���

#ifdef _DEBUG
void CMFC05113Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC05113Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

