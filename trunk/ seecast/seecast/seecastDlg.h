// seecastDlg.h : header file
//

#pragma once

class CseecastDlgAutoProxy;


// CseecastDlg dialog
class CseecastDlg : public CDialog
{
	DECLARE_DYNAMIC(CseecastDlg);
	friend class CseecastDlgAutoProxy;

// Construction
public:
	CseecastDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CseecastDlg();

// Dialog Data
	enum { IDD = IDD_SEECAST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CseecastDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
