// C8.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C8.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC8 dialog


CC8::CC8(CWnd* pParent /*=NULL*/)
	: CDialog(CC8::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC8)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC8::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC8)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC8, CDialog)
	//{{AFX_MSG_MAP(CC8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC8 message handlers

void CC8::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC8::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
