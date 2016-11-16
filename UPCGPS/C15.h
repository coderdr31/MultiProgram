#if !defined(AFX_C15_H__3BE8A560_32A1_4F8A_88A3_8AAA2720B8B0__INCLUDED_)
#define AFX_C15_H__3BE8A560_32A1_4F8A_88A3_8AAA2720B8B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C15.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC15 dialog

class CC15 : public CDialog
{
// Construction
public:
	CC15(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC15)
	enum { IDD = IDD_DIALOG15 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC15)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC15)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C15_H__3BE8A560_32A1_4F8A_88A3_8AAA2720B8B0__INCLUDED_)
