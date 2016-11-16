#if !defined(AFX_C8_H__A1BB2F3B_F88E_432B_9C1F_B10868FC66AA__INCLUDED_)
#define AFX_C8_H__A1BB2F3B_F88E_432B_9C1F_B10868FC66AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C8.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC8 dialog

class CC8 : public CDialog
{
// Construction
public:
	CC8(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC8)
	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC8)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC8)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C8_H__A1BB2F3B_F88E_432B_9C1F_B10868FC66AA__INCLUDED_)
