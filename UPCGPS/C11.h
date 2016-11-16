#if !defined(AFX_C11_H__9151616F_1CD9_4172_9C58_B4988B915500__INCLUDED_)
#define AFX_C11_H__9151616F_1CD9_4172_9C58_B4988B915500__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C11.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC11 dialog

class CC11 : public CDialog
{
// Construction
public:
	CC11(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC11)
	enum { IDD = IDD_DIALOG11 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC11)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC11)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C11_H__9151616F_1CD9_4172_9C58_B4988B915500__INCLUDED_)
