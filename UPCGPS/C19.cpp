// C19.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C19.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC19 dialog


CC19::CC19(CWnd* pParent /*=NULL*/)
	: CDialog(CC19::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC19)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC19::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC19)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC19, CDialog)
	//{{AFX_MSG_MAP(CC19)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC19 message handlers

void CC19::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC19::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
