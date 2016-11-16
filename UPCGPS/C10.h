#if !defined(AFX_C10_H__5A3B2171_F847_483B_8B73_1F194D7B6F2A__INCLUDED_)
#define AFX_C10_H__5A3B2171_F847_483B_8B73_1F194D7B6F2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C10.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC10 dialog

class CC10 : public CDialog
{
// Construction
public:
	CC10(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC10)
	enum { IDD = IDD_DIALOG10 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC10)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC10)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C10_H__5A3B2171_F847_483B_8B73_1F194D7B6F2A__INCLUDED_)
