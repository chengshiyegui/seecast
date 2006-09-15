// DlgProxy.h: header file
//

#pragma once

class CseecastDlg;


// CseecastDlgAutoProxy command target

class CseecastDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CseecastDlgAutoProxy)

	CseecastDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CseecastDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CseecastDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CseecastDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

