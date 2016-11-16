// C9.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C9.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC9 dialog


CC9::CC9(CWnd* pParent /*=NULL*/)
	: CDialog(CC9::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC9)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC9::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC9)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC9, CDialog)
	//{{AFX_MSG_MAP(CC9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC9 message handlers

void CC9::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC9::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
