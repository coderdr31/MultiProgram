// C6.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC6 dialog


CC6::CC6(CWnd* pParent /*=NULL*/)
	: CDialog(CC6::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC6)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC6)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC6, CDialog)
	//{{AFX_MSG_MAP(CC6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC6 message handlers

void CC6::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC6::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
