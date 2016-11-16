#if !defined(AFX_C5_H__2BC0F109_2DC8_4532_A9DE_EC74AEA9191D__INCLUDED_)
#define AFX_C5_H__2BC0F109_2DC8_4532_A9DE_EC74AEA9191D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C5.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC5 dialog

class CC5 : public CDialog
{
// Construction
public:
	CC5(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC5)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC5)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C5_H__2BC0F109_2DC8_4532_A9DE_EC74AEA9191D__INCLUDED_)
