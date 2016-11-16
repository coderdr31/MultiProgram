// UPCGPS.h : main header file for the UPCGPS application
//

#if !defined(AFX_UPCGPS_H__1EB16AFC_5809_425A_BF81_95995EEDAE92__INCLUDED_)
#define AFX_UPCGPS_H__1EB16AFC_5809_425A_BF81_95995EEDAE92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSApp:
// See UPCGPS.cpp for the implementation of this class
//

class CUPCGPSApp : public CWinApp
{
public:
	void SetDialogBkColor(COLORREF clrCtlBk,COLORREF clrCtlTest);
	CUPCGPSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUPCGPSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUPCGPSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPCGPS_H__1EB16AFC_5809_425A_BF81_95995EEDAE92__INCLUDED_)
