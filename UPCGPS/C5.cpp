// C5.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC5 dialog


CC5::CC5(CWnd* pParent /*=NULL*/)
	: CDialog(CC5::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC5, CDialog)
	//{{AFX_MSG_MAP(CC5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC5 message handlers

void CC5::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CC5::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
