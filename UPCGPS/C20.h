#if !defined(AFX_C20_H__CBBED073_031A_43E0_863C_33924BE0C120__INCLUDED_)
#define AFX_C20_H__CBBED073_031A_43E0_863C_33924BE0C120__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C20.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC20 dialog

class CC20 : public CDialog
{
// Construction
public:
	CC20(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC20)
	enum { IDD = IDD_DIALOG20 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC20)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC20)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C20_H__CBBED073_031A_43E0_863C_33924BE0C120__INCLUDED_)
