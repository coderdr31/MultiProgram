// 3.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// C3 dialog


C3::C3(CWnd* pParent /*=NULL*/)
	: CDialog(C3::IDD, pParent)
{
	//{{AFX_DATA_INIT(C3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void C3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(C3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(C3, CDialog)
	//{{AFX_MSG_MAP(C3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C3 message handlers

void C3::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void C3::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
