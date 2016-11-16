#if !defined(AFX_C6_H__BDC220FD_19B1_403F_B442_D256EE4BC9E1__INCLUDED_)
#define AFX_C6_H__BDC220FD_19B1_403F_B442_D256EE4BC9E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC6 dialog

class CC6 : public CDialog
{
// Construction
public:
	CC6(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC6)
	enum { IDD = IDD_DIALOG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC6)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C6_H__BDC220FD_19B1_403F_B442_D256EE4BC9E1__INCLUDED_)
