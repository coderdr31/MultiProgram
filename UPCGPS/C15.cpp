// C15.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C15.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC15 dialog


CC15::CC15(CWnd* pParent /*=NULL*/)
	: CDialog(CC15::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC15)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC15::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC15)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC15, CDialog)
	//{{AFX_MSG_MAP(CC15)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC15 message handlers

void CC15::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC15::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
