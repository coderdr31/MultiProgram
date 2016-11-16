// Register.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "Register.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CUPCGPSApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CRegister dialog


CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
{

}


void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegister)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	//{{AFX_MSG_MAP(CRegister)
	ON_BN_CLICKED(IDC_INTER, OnInter)
	ON_WM_NCHITTEST()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_REXIT, OnRexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegister message handlers

void CRegister::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CRegister::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	//CDialog::OnCancel();
}

void CRegister::OnInter() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

UINT CRegister::OnNcHitTest(CPoint point) 
{
	UINT nHitTest = CDialog::OnNcHitTest(point);
	if(nHitTest == HTCLIENT)
		nHitTest = HTCAPTION;
	return nHitTest;
}

void CRegister::OnTimer(UINT nIDEvent) 
{
	static int i =0; 
	CClientDC dc(this);
	dc.BitBlt(0,0,m_dc[i].Width(),m_dc->Height(),&m_dc[i],0,0,SRCCOPY);
	if(++i>3)
		i=0;
	CDialog::OnTimer(nIDEvent);
}

void CRegister::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect   rect;    
	GetClientRect(rect);  
    dc.FillSolidRect(rect,RGB(100,149,237));  
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	
	
	CString str;
	for(int i = 0; i<COUNT;i++)
	{	
		str.Format("./picture/%01d.bmp",i);
		m_dc[i].LoadBitmap(str); 
	}
	
	SetTimer(0,700,NULL);	
	

}

void CRegister::OnRexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
