#if !defined(AFX_C14_H__3ADC059F_0369_46A0_968E_AAE629CE2111__INCLUDED_)
#define AFX_C14_H__3ADC059F_0369_46A0_968E_AAE629CE2111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C14.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC14 dialog

class CC14 : public CDialog
{
// Construction
public:
	CC14(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC14)
	enum { IDD = IDD_DIALOG14 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC14)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC14)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C14_H__3ADC059F_0369_46A0_968E_AAE629CE2111__INCLUDED_)
