// C13.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C13.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC13 dialog


CC13::CC13(CWnd* pParent /*=NULL*/)
	: CDialog(CC13::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC13)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC13::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC13)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC13, CDialog)
	//{{AFX_MSG_MAP(CC13)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC13 message handlers

void CC13::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC13::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
