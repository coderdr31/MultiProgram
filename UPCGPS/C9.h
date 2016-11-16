#if !defined(AFX_C9_H__5000BEF1_13F7_4FB5_91A9_21DC42C2C9AD__INCLUDED_)
#define AFX_C9_H__5000BEF1_13F7_4FB5_91A9_21DC42C2C9AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C9.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC9 dialog

class CC9 : public CDialog
{
// Construction
public:
	CC9(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC9)
	enum { IDD = IDD_DIALOG9 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC9)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC9)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C9_H__5000BEF1_13F7_4FB5_91A9_21DC42C2C9AD__INCLUDED_)
