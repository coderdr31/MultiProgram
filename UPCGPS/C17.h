#if !defined(AFX_C17_H__5D6101C8_0F34_40CA_B949_B8B165E74C5B__INCLUDED_)
#define AFX_C17_H__5D6101C8_0F34_40CA_B949_B8B165E74C5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// C17.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CC17 dialog

class CC17 : public CDialog
{
// Construction
public:
	CC17(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CC17)
	enum { IDD = IDD_DIALOG17 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC17)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CC17)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C17_H__5D6101C8_0F34_40CA_B949_B8B165E74C5B__INCLUDED_)
