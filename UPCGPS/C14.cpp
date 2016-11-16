// C14.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C14.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC14 dialog


CC14::CC14(CWnd* pParent /*=NULL*/)
	: CDialog(CC14::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC14)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC14::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC14)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC14, CDialog)
	//{{AFX_MSG_MAP(CC14)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC14 message handlers

void CC14::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC14::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
