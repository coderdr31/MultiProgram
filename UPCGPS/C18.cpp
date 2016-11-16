// C18.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C18.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC18 dialog


CC18::CC18(CWnd* pParent /*=NULL*/)
	: CDialog(CC18::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC18)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC18::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC18)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC18, CDialog)
	//{{AFX_MSG_MAP(CC18)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC18 message handlers

void CC18::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC18::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
