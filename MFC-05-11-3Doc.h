
// MFC-05-11-3Doc.h : CMFC05113Doc ��Ľӿ�
//


#pragma once
#include "MFC-05-11-3Set.h"


class CMFC05113Doc : public CDocument
{
protected: // �������л�����
	CMFC05113Doc();
	DECLARE_DYNCREATE(CMFC05113Doc)

// ����
public:
	CMFC05113Set m_MFC05113Set;

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
	virtual ~CMFC05113Doc();
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
