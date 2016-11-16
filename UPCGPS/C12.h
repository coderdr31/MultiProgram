#if !defined(AFX_C12_H__5697E781_F916_4AEF_91BC_BC738559874E__INCLUDED_)
#define AFX_C12_H__5697E781_F916_4AEF_91BC_BC738559874E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C12.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC12 dialog

class CC12 : public CDialog
{
// Construction
public:
	CC12(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC12)
	enum { IDD = IDD_DIALOG12 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC12)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC12)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C12_H__5697E781_F916_4AEF_91BC_BC738559874E__INCLUDED_)
