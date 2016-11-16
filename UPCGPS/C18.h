#if !defined(AFX_C18_H__BE2053A9_C84B_4104_9110_115863A56168__INCLUDED_)
#define AFX_C18_H__BE2053A9_C84B_4104_9110_115863A56168__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C18.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC18 dialog

class CC18 : public CDialog
{
// Construction
public:
	CC18(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC18)
	enum { IDD = IDD_DIALOG18 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC18)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC18)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C18_H__BE2053A9_C84B_4104_9110_115863A56168__INCLUDED_)
