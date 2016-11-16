// UPCGPS.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "UPCGPSDlg.h"
#include "Register.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSApp

BEGIN_MESSAGE_MAP(CUPCGPSApp, CWinApp)
	//{{AFX_MSG_MAP(CUPCGPSApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSApp construction

CUPCGPSApp::CUPCGPSApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CUPCGPSApp object

CUPCGPSApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSApp initialization

BOOL CUPCGPSApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CRegister dlg_r;
	if (dlg_r.DoModal() == IDOK)
	{
		
		CUPCGPSDlg dlg;
		//m_pMainWnd = &dlg;
		dlg.DoModal();

		return FALSE;

	}
    return FALSE;
}

void CUPCGPSApp::SetDialogBkColor(COLORREF clrCtlBk, COLORREF clrCtlTest)
{
	CWinApp::SetDialogBkColor(clrCtlBk,clrCtlTest);
   
}
