// C88.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C88.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC88 dialog


CC88::CC88(CWnd* pParent /*=NULL*/)
	: CDialog(CC88::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC88)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC88::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC88)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC88, CDialog)
	//{{AFX_MSG_MAP(CC88)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC88 message handlers

void CC88::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC88::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
