#if !defined(AFX_3_H__F6FA7F6C_7623_4E24_AD5D_620593086CAC__INCLUDED_)
#define AFX_3_H__F6FA7F6C_7623_4E24_AD5D_620593086CAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// 3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// C3 dialog

class C3 : public CDialog
{
// Construction
public:
	C3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(C3)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(C3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(C3)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_3_H__F6FA7F6C_7623_4E24_AD5D_620593086CAC__INCLUDED_)
