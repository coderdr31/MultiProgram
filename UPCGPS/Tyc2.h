#if !defined(AFX_TYC2_H__9B0E5EB8_F23C_49E2_AA05_5E134CD9855E__INCLUDED_)
#define AFX_TYC2_H__9B0E5EB8_F23C_49E2_AA05_5E134CD9855E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tyc2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTyc2 dialog

class CTyc2 : public CDialog
{
// Construction
public:
	CTyc2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTyc2)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTyc2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTyc2)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TYC2_H__9B0E5EB8_F23C_49E2_AA05_5E134CD9855E__INCLUDED_)
