#if !defined(AFX_C19_H__EE3081F5_B512_414C_9856_798557EF3135__INCLUDED_)
#define AFX_C19_H__EE3081F5_B512_414C_9856_798557EF3135__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C19.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC19 dialog

class CC19 : public CDialog
{
// Construction
public:
	CC19(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC19)
	enum { IDD = IDD_DIALOG19 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC19)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC19)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C19_H__EE3081F5_B512_414C_9856_798557EF3135__INCLUDED_)
