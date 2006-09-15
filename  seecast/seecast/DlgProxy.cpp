// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "seecast.h"
#include "DlgProxy.h"
#include "seecastDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CseecastDlgAutoProxy

IMPLEMENT_DYNCREATE(CseecastDlgAutoProxy, CCmdTarget)

CseecastDlgAutoProxy::CseecastDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CseecastDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CseecastDlg)))
		{
			m_pDialog = reinterpret_cast<CseecastDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CseecastDlgAutoProxy::~CseecastDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CseecastDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CseecastDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CseecastDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_Iseecast to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {36A5C608-B12E-4BB6-869C-29CBD814BB0D}
static const IID IID_Iseecast =
{ 0x36A5C608, 0xB12E, 0x4BB6, { 0x86, 0x9C, 0x29, 0xCB, 0xD8, 0x14, 0xBB, 0xD } };

BEGIN_INTERFACE_MAP(CseecastDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CseecastDlgAutoProxy, IID_Iseecast, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {08023F3F-99EB-4079-B223-F8AFD381D9E2}
IMPLEMENT_OLECREATE2(CseecastDlgAutoProxy, "seecast.Application", 0x8023f3f, 0x99eb, 0x4079, 0xb2, 0x23, 0xf8, 0xaf, 0xd3, 0x81, 0xd9, 0xe2)


// CseecastDlgAutoProxy message handlers
