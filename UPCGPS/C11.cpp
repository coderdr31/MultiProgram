// C11.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC11 dialog


CC11::CC11(CWnd* pParent /*=NULL*/)
	: CDialog(CC11::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC11)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC11::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC11)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC11, CDialog)
	//{{AFX_MSG_MAP(CC11)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC11 message handlers

void CC11::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC11::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
