
// MFC-05-11Doc.h : CMFC0511Doc ��Ľӿ�
//


#pragma once
#include "MFC-05-11Set.h"


class CMFC0511Doc : public CDocument
{
protected: // �������л�����
	CMFC0511Doc();
	DECLARE_DYNCREATE(CMFC0511Doc)

// ����
public:
	CMFC0511Set m_MFC0511Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC0511Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
