// C10.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "C10.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC10 dialog


CC10::CC10(CWnd* pParent /*=NULL*/)
	: CDialog(CC10::IDD, pParent)
{
	//{{AFX_DATA_INIT(CC10)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CC10::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CC10)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CC10, CDialog)
	//{{AFX_MSG_MAP(CC10)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC10 message handlers

void CC10::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CC10::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
