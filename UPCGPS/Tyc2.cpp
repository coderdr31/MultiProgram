// Tyc2.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "Tyc2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTyc2 dialog


CTyc2::CTyc2(CWnd* pParent /*=NULL*/)
	: CDialog(CTyc2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTyc2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTyc2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTyc2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTyc2, CDialog)
	//{{AFX_MSG_MAP(CTyc2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTyc2 message handlers

void CTyc2::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CTyc2::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}
