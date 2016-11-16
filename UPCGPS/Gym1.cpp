// Gym1.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "Gym1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGym1 dialog


CGym1::CGym1(CWnd* pParent /*=NULL*/)
	: CDialog(CGym1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGym1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGym1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGym1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGym1, CDialog)
	//{{AFX_MSG_MAP(CGym1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGym1 message handlers

void CGym1::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CGym1::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
