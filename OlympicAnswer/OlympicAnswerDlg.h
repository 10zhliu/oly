// OlympicAnswerDlg.h : header file
//

#if !defined(AFX_OLYMPICANSWERDLG_H__93DA8824_A964_4C0E_8093_031B2F52E37B__INCLUDED_)
#define AFX_OLYMPICANSWERDLG_H__93DA8824_A964_4C0E_8093_031B2F52E37B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COlympicAnswerDlg dialog

class COlympicAnswerDlg : public CDialog
{
// Construction
public:
	bool GetTime();
	bool GetIp();
	COlympicAnswerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COlympicAnswerDlg)
	enum { IDD = IDD_OLYMPICANSWER_DIALOG };
	CString	m_outputdata;
	CString	m_data;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COlympicAnswerDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COlympicAnswerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLYMPICANSWERDLG_H__93DA8824_A964_4C0E_8093_031B2F52E37B__INCLUDED_)
