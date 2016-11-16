// C17.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C17.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC17 dialog


CC17::CC17(CWnd* pParent /*=NULL*/)
	: CDialog(CC17::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC17)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC17::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC17)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC17, CDialog)
	//{{AFX_MSG_MAP(CC17)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC17 message handlers

void CC17::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC17::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
