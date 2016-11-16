#if !defined(AFX_GYM1_H__03A9123F_33DE_4B78_A0DD_DDC91262C2B0__INCLUDED_)
#define AFX_GYM1_H__03A9123F_33DE_4B78_A0DD_DDC91262C2B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Gym1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGym1 dialog

class CGym1 : public CDialog
{
// Construction
public:
	CGym1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGym1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGym1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGym1)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GYM1_H__03A9123F_33DE_4B78_A0DD_DDC91262C2B0__INCLUDED_)
