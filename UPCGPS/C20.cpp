// C20.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C20.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC20 dialog


CC20::CC20(CWnd* pParent /*=NULL*/)
	: CDialog(CC20::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC20)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC20::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC20)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC20, CDialog)
	//{{AFX_MSG_MAP(CC20)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC20 message handlers

void CC20::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC20::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
