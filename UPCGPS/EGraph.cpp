// EGraph.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "EGraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEGraph dialog


CEGraph::CEGraph(CWnd* pParent /*=NULL*/)
	: CDialog(CEGraph::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEGraph)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEGraph::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEGraph)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEGraph, CDialog)
	//{{AFX_MSG_MAP(CEGraph)
	ON_COMMAND(ID_REST, OnRest)
	ON_COMMAND(ID_STUDY, OnStudy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEGraph message handlers

void CEGraph::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CEGraph::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CEGraph::OnRest() 
{
	
}

void CEGraph::OnStudy() 
{
	
}
