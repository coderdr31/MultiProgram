#if !defined(AFX_EGRAPH_H__4ABA6FF6_8D71_45F2_98A1_7F199E917747__INCLUDED_)
#define AFX_EGRAPH_H__4ABA6FF6_8D71_45F2_98A1_7F199E917747__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EGraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEGraph dialog

class CEGraph : public CDialog
{
// Construction
public:
	CEGraph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEGraph)
	enum { IDD = IDD_DIALOG51 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEGraph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEGraph)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRest();
	afx_msg void OnStudy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EGRAPH_H__4ABA6FF6_8D71_45F2_98A1_7F199E917747__INCLUDED_)
