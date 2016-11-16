#if !defined(AFX_C16_H__08A3271B_8A79_4F73_8C18_28E4FA81095E__INCLUDED_)
#define AFX_C16_H__08A3271B_8A79_4F73_8C18_28E4FA81095E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C16.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC16 dialog

class CC16 : public CDialog
{
// Construction
public:
	CC16(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC16)
	enum { IDD = IDD_DIALOG16 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC16)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC16)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C16_H__08A3271B_8A79_4F73_8C18_28E4FA81095E__INCLUDED_)
