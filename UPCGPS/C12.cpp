// C12.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C12.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC12 dialog


CC12::CC12(CWnd* pParent /*=NULL*/)
	: CDialog(CC12::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC12)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC12::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC12)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC12, CDialog)
	//{{AFX_MSG_MAP(CC12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC12 message handlers

void CC12::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CC12::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
