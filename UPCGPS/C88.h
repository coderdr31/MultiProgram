#if !defined(AFX_C88_H__D9F11BB9_0DA8_40F8_92B7_15C05282FA36__INCLUDED_)
#define AFX_C88_H__D9F11BB9_0DA8_40F8_92B7_15C05282FA36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C88.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC88 dialog

class CC88 : public CDialog
{
// Construction
public:
	CC88(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC88)
	enum { IDD = IDD_DIALOG8 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC88)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC88)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C88_H__D9F11BB9_0DA8_40F8_92B7_15C05282FA36__INCLUDED_)
