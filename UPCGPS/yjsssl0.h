#if !defined(AFX_YJSSSL0_H__E34E711D_C2BF_47DB_AFEB_4FDA404E2A0D__INCLUDED_)
#define AFX_YJSSSL0_H__E34E711D_C2BF_47DB_AFEB_4FDA404E2A0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// yjsssl0.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cyjsssl0 dialog

class Cyjsssl0 : public CDialog
{
// Construction
public:
	Cyjsssl0(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cyjsssl0)
	enum { IDD = IDD_DIALOG0 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cyjsssl0)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cyjsssl0)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YJSSSL0_H__E34E711D_C2BF_47DB_AFEB_4FDA404E2A0D__INCLUDED_)
