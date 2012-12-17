// OlympicAnswer.h : main header file for the OLYMPICANSWER application
//

#if !defined(AFX_OLYMPICANSWER_H__904BAD79_A979_41E3_BA5F_A4CFC7D5A7BE__INCLUDED_)
#define AFX_OLYMPICANSWER_H__904BAD79_A979_41E3_BA5F_A4CFC7D5A7BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COlympicAnswerApp:
// See OlympicAnswer.cpp for the implementation of this class
//

class COlympicAnswerApp : public CWinApp
{
public:
	COlympicAnswerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COlympicAnswerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COlympicAnswerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLYMPICANSWER_H__904BAD79_A979_41E3_BA5F_A4CFC7D5A7BE__INCLUDED_)
