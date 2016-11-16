// C16.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C16.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC16 dialog


CC16::CC16(CWnd* pParent /*=NULL*/)
	: CDialog(CC16::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC16)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC16::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC16)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC16, CDialog)
	//{{AFX_MSG_MAP(CC16)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC16 message handlers

void CC16::OnOK() 
{
	
//	CDialog::OnOK();
}

void CC16::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
