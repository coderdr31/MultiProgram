// 4.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C4 dialog


C4::C4(CWnd* pParent /*=NULL*/)
	: CDialog(C4::IDD, pParent)
{
	//{{AFX_DATA_INIT(C4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void C4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C4, CDialog)
	//{{AFX_MSG_MAP(C4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C4 message handlers

void C4::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void C4::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
