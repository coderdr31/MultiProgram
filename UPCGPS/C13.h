#if !defined(AFX_C13_H__036BBBD7_D8F4_4E84_969D_B61001F51517__INCLUDED_)
#define AFX_C13_H__036BBBD7_D8F4_4E84_969D_B61001F51517__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C13.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC13 dialog

class CC13 : public CDialog
{
// Construction
public:
	CC13(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC13)
	enum { IDD = IDD_DIALOG13 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC13)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC13)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C13_H__036BBBD7_D8F4_4E84_969D_B61001F51517__INCLUDED_)
