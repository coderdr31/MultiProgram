// yjsssl0.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "yjsssl0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cyjsssl0 dialog



	
Cyjsssl0::Cyjsssl0(CWnd* pParent /*=NULL*/)
  : CDialog(Cyjsssl0::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cyjsssl0)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cyjsssl0::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cyjsssl0)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cyjsssl0, CDialog)
	//{{AFX_MSG_MAP(Cyjsssl0)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cyjsssl0 message handlers

void Cyjsssl0::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void Cyjsssl0::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
