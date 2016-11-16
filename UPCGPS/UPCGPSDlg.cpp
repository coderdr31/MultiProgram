// UPCGPSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UPCGPS.h"
#include "UPCGPSDlg.h"
#include "MemDC.h"
#include "value.h"
#include "math.h"

#include "yjsssl0.h"
#include "Gym1.h"
#include "Tyc2.h"
#include "3.h"
#include "4.h"
#include "C5.h"
#include "C6.h"
#include "C8.h"
#include "C88.h"
#include "C9.h"
#include "C10.h"
#include "C11.h"
#include "C12.h"
#include "C13.h"
#include "C14.h"
#include "C15.h"
#include "C16.h"
#include "C17.h"
#include "C18.h"
#include "C19.h"
#include "C20.h"
#include "EGraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int mway[300];
 value vv;
 extern CUPCGPSApp theApp;

 

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSDlg dialog


CUPCGPSDlg::CUPCGPSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUPCGPSDlg::IDD, pParent)
{
    coe = 1;
	mouseState = 0;
	curw = pw = 903;
    curh = ph = 688; 
	ssx = ssy = sx =sy = 0 ;
	mdc.Create(903*10,688*10,NULL);
	fmdc.Create(903,688,NULL);

	//{{AFX_DATA_INIT(CUPCGPSDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUPCGPSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUPCGPSDlg)
	DDX_Control(pDX, IDC_COMBO2, m_end_combol);
	DDX_Control(pDX, IDC_COMBO1, m_start_combol);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUPCGPSDlg, CDialog)
	//{{AFX_MSG_MAP(CUPCGPSDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEARCH_BUTTON, OnSearchButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BIG_BUTTON, OnBigButton)
	ON_BN_CLICKED(IDC_SMALL_BUTTON, OnSmallButton)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_CHANGECOL_BUTTON, OnChangecolButton)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_EG_BUTTON, OnEgButton)
	ON_COMMAND(ID_REST, OnRest)
	ON_COMMAND(ID_STUDY, OnStudy)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSDlg message handlers


BOOL CUPCGPSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	 
	theApp.SetDialogBkColor(RGB(64,224,208),NULL);
	mdc.FillSolidRect(0,0,(int)pw* 10,(int)ph * 10,RGB(192, 192, 192));
    fmdc.DeleteDC();
	fmdc.LoadBitmap("./picture/4.bmp");
	mdc.StretchBlt(0, 0, 903, 688, &fmdc, 0, 0, 903, 688, SRCCOPY);

	freopen("coordinate.txt", "r", stdin);
	for(int i = 0; i < 80; i++){	
		scanf("%d %d", &vv.coordinate[i].x, &vv.coordinate[i].y);
	}
	
	fclose(stdin);
	
	int max = 10000;
	for( i = 0; i < NUMBER_; i++)
		for(int j = 0; j < NUMBER_; j++)
			vv.minLength[i][j] = max;

		freopen("relation.txt", "r", stdin);
		int st, et;
		for(i = 0; i < 116; i++)
		{
			scanf("%d %d", &st, &et);
			vv.minLength[st][et] = vv.minLength[et][st] = sqrt((vv.coordinate[st].x - vv.coordinate[et].x) * (vv.coordinate[st].x - vv.coordinate[et].x) + (vv.coordinate[st].y - vv.coordinate[et].y) * (vv.coordinate[st].y - vv.coordinate[et].y));
	
		}
		fclose(stdin);
		
		for(i = 0; i < NUMBER_; i++)
			for(int j = 0; j < NUMBER_; j++)
			{
				if(vv.minLength[i][j] != max)
					vv.way[i][j] = j;
				else
					vv.way[i][j] = 0;
			}
			for(int k = 0; k < NUMBER_; k++)
				for(i = 0; i < NUMBER_; i++)
					for(int j = 0; j < NUMBER_; j++)
					{
						if(vv.minLength[i][j] > (vv.minLength[i][k] + vv.minLength[k][j]))
						{
							vv.minLength[i][j] = vv.minLength[i][k] + vv.minLength[k][j];				
							vv.way[i][j] = vv.way[i][k];
						}
					}
	freopen("coordinate2.txt", "r", stdin);
	for( i = 0; i < 21; i++)
	{   int x, y;
		scanf("%d %d", &x, &y);
		CPoint point1(x, y), point2(x + 50, y + 50);
		rect[i].TopLeft() = point1;
		rect[i].BottomRight() = point2;
	}
	fclose(stdin);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUPCGPSDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.FillSolidRect(0,0,(int)pw,(int)ph,RGB(192, 192, 192));
	dc.BitBlt((int)ssx,(int)ssy,(int)pw-(int)ssx,(int)ph-(int)ssy,&mdc,(int)sx,(int)sy,SRCCOPY);
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUPCGPSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUPCGPSDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CUPCGPSDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CUPCGPSDlg::OnSearchButton() 
{
	// TODO: Add your control notification handler code here
	
	RedrawWindow();
	int i = m_start_combol.GetCurSel();
	int j = m_end_combol.GetCurSel();
	
	if(i == j)
		AfxMessageBox("起始点相同，请选择不同的起点和终点");
	else
	{
		CString str;
		str.Format("%f", vv.minLength[i][j] *2.2);
		str ="两点之间距离为"+ str + "米";
		CClientDC dc(this);
	    dc.TextOut(990,400,str);
		str.Format("%f", vv.minLength[i][j] *2.2*12/1000);
		str ="步行需要"+ str + "分钟";
		dc.TextOut(990,430,str);

		str.Format("%f", vv.minLength[i][j] *2.2*0.48/1000);
		str ="驾车需要"+ str + "分钟";
		dc.TextOut(990,460,str);



		int k=0;
		int next = vv.way[i][j];
		mway[0] = i;
		while(next != j)
		{
			k++;
			mway[k] = next;
			next = vv.way[next][j];
		}
		mway[k + 1] = j;
		
		CPen pen(PS_SOLID, 4, RGB(255,0,0));               
		CClientDC dc_s(this);
		CPen *lastPen = dc_s.SelectObject(&pen);                           
		dc_s.MoveTo(vv.coordinate[mway[0]].x, vv.coordinate[mway[0]].y);                      
		for(int q=1;q<=k+1;q++)
		{
			dc_s.LineTo(vv.coordinate[mway[q]].x, vv.coordinate[mway[q]].y);
			Sleep(550);
		}
		dc_s.SelectObject(lastPen);
		
	
	}

		
}


void CUPCGPSDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (point.x <= 903 && point.y <= 688)
	{
		mouseState = 1;
		pAar.RemoveAll();
		pAar.Add(point);
  
	} 
	else
	{
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CUPCGPSDlg::OnMouseMove(UINT nFlags, CPoint point) 
{


	CRect rect101,rect102;
	CPoint pointl1(902, 0), pointl2(1236,209);
	rect101.TopLeft() = pointl1;
	rect101.BottomRight() = pointl2;
	CPoint pointl3(902, 209), pointl4(1236,368);
	rect102.TopLeft() = pointl3;
	rect102.BottomRight() = pointl4;

	if (rect101.PtInRect(point))
	{
		HCURSOR hCur101 = LoadCursor(AfxGetInstanceHandle() ,MAKEINTRESOURCE(IDC_CURSOR3));
		::SetCursor(hCur101);

	}
	if (rect102.PtInRect(point))
	{
		HCURSOR hCur102 = LoadCursor(AfxGetInstanceHandle() ,MAKEINTRESOURCE(IDC_CURSOR4));
		::SetCursor(hCur102);
		
	}





	CClientDC dc(this);
	CString str;
	str.Format("%04d %04d", point.x, point.y);
	dc.TextOut(10, 20, str);

	switch(mouseState)
	{
	case 1:
	   if (point.x <= 903 && point.y <= 688)
	   {   
		   HCURSOR hCur = LoadCursor(AfxGetInstanceHandle() ,MAKEINTRESOURCE(IDC_CURSOR1));
		   ::SetCursor(hCur);


		   int nu = pAar.GetSize(); 
		   CPoint &p2 =pAar[nu-1];
           ssx+=point.x-p2.x;
		   ssy+=point.y-p2.y;
		   
		   CClientDC dc(this);
		   dc.FillSolidRect(0,0,(int)pw,(int)ph,RGB(192, 192, 192));
		   dc.BitBlt((int)ssx,(int)ssy,(int)pw-(int)ssx,(int)ph-(int)ssy,&mdc,(int)sx,(int)sy,SRCCOPY);

		   for(int i = 0; i < 80; i++)
		   {
			   vv.coordinate[i].x+=point.x-p2.x;
			   vv.coordinate[i].y+=point.y-p2.y;
		   }	 
			 for( i = 0; i < 21; i++){
				 CPoint point11;
				 point11 = rect[i].TopLeft();
				 point11.x+=point.x-p2.x;
				 point11.y+=point.y-p2.y;
				 CPoint point22(point11.x + 50,point11.y + 50);
				 rect[i].TopLeft() = point11;
				 rect[i].BottomRight() = point22;
				 rect[i].NormalizeRect();
			 }	 
		    pAar.Add(point);
		   } 
	   else{
            mouseState = 0;
	   }
	   
		   break;
	case  0:
		
		for(int i1 = 0; i1 < 21; i1++)
		{
			if(rect[i1].PtInRect(point)){
				HCURSOR hCur1 = LoadCursor(AfxGetInstanceHandle() ,MAKEINTRESOURCE(IDC_CURSOR2));
				::SetCursor(hCur1);
			}		
		}
		break;




	   }
		
	
	
	
	
	CDialog::OnMouseMove(nFlags, point);
}

  

void CUPCGPSDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	mouseState = 0;
	pAar.RemoveAll();
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CUPCGPSDlg::OnBigButton() 
{		
	Resize(1.1);
}

void CUPCGPSDlg::OnSmallButton() 
{   
	Resize(1/1.1);
}

void CUPCGPSDlg::Resize(double x)
{
	double lssx = ssx;  double lssy = ssy;
	double cc ;
	cc = x;
	coe = coe *cc;
	ssx = pw/2 - ((pw/2 - ssx) * cc);
	ssy = ph/2 - ((ph/2 - ssy) * cc);
	curw = curw * cc;
	curh = curh * cc;
	mdc.FillSolidRect(0,0,903*10,688*10,RGB(192, 192, 192));
	mdc.StretchBlt(0, 0,(int)curw,(int)curh,&fmdc, 0, 0, 903, 688, SRCCOPY);
	CClientDC dc(this);
	dc.FillSolidRect(0,0,903,688,RGB(192, 192, 192));
	dc.BitBlt((int)ssx,(int)ssy,903-(int)ssx,688-(int)ssy,&mdc,0,0,SRCCOPY);

	
	for(int  i = 0; i < 21; i++){
		CPoint point11;
		point11 = rect[i].TopLeft();
		point11.x= long(cc*(point11.x-lssx) + ssx);
		point11.y = long(cc*(point11.y-lssy) + ssy);
		CPoint point22((int)(point11.x + 50 * coe),(int)(point11.y + 50 * coe));
		rect[i].TopLeft() = point11;
		rect[i].BottomRight() = point22;
		rect[i].NormalizeRect();
			 }

	for( i = 0; i < 80; i++)
	{
		vv.coordinate[i].x = long(cc*(vv.coordinate[i].x-lssx) + ssx);
		vv.coordinate[i].y = long(cc*(vv.coordinate[i].y-lssy) + ssy);
	}
	

}

void CUPCGPSDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	for (int i = 0;i <= 20;i++)
	{
		if (rect[i].PtInRect(point))
		{
			switch(i)
			{
			case 0:
				{
					Cyjsssl0 dlg0;
					dlg0.DoModal();
					break;
				}
			case 1:
				{
					CGym1 dlg1;
					dlg1.DoModal();
					break;
				}
			case 2:
				{
					CTyc2 dlg2;
					dlg2.DoModal();
					break;
				}
			case 3:
				{
					C3 dlg3;
					dlg3.DoModal();
					break;
				}
			case 4:
				{
					C4 dlg4;
					dlg4.DoModal();
					break;
				}
			case 5:
				{
					CC5 dlg5;
					dlg5.DoModal();
					break;
				}
			case 6:
				{
					CC6 dlg6;
					dlg6.DoModal();
					break;
				}
			case 7:
				{
					CC8 dlg7;
					dlg7.DoModal();
					break;
				}
			case 8:
				{
					CC88 dlg8;
					dlg8.DoModal();
					break;
				}
			case 9:
				{
					CC9 dlg9;
					dlg9.DoModal();
					break;
				}
			case 10:
				{
					CC10 dlg10;
					dlg10.DoModal();
					break;
				}
			case 11:
				{
					CC11 dlg11;
					dlg11.DoModal();
					break;
				}
			case 12:
				{
					CC12 dlg12;
					dlg12.DoModal();
					break;
				}
			case 13:
				{
					CC13 dlg13;
					dlg13.DoModal();
					break;
				}
			case 14:
				{
					CC14 dlg14;
					dlg14.DoModal();
					break;
				}
			case 15:
				{
					CC15 dlg15;
					dlg15.DoModal();
					break;
				}
			case 16:
				{
					CC16 dlg16;
					dlg16.DoModal();
					break;
				}
			case 17:
				{
					CC17 dlg17;
					dlg17.DoModal();
					break;
				}
			case 18:
				{
					CC18 dlg18;
					dlg18.DoModal();
					break;
				}
			case 19:
				{
					CC19 dlg19;
					dlg19.DoModal();
					break;
				}
			case 20:
				{
					CC20 dlg20;
					dlg20.DoModal();
					break;
				}
		


			}
		}
	}

	CDialog::OnLButtonDblClk(nFlags, point);
}

void CUPCGPSDlg::OnChangecolButton() 
{
	CColorDialog dlg;
	if(IDCANCEL == dlg.DoModal())
		return ;
    COLORREF col = dlg.GetColor();
	theApp.SetDialogBkColor(col,NULL);
	Invalidate();
	
}

BOOL CUPCGPSDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	if(pt.x < 903 && pt.y < 688)
	{
		pw = pt.x * 2;
		ph = pt.y * 2;
		double x;
		if(zDelta > 0)
		{
			x = 1.1 * zDelta / 120;
		}
		else if(zDelta < 0)
		{
			x = -(120 / (zDelta * 1.1));
		}
		else if(zDelta == 0)
			x = 1;
		Resize(x);
		pw = 903;
		ph = 688;
	}
	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}

void CUPCGPSDlg::OnEgButton() 
{
	CEGraph dlg51;
	dlg51.DoModal();	
}

void CUPCGPSDlg::OnRest() 
{
	double len1 = (Curpoint.x - vv.coordinate[11].x) * (Curpoint.x - vv.coordinate[11].x) + (Curpoint.y - vv.coordinate[11].y) * (Curpoint.y - vv.coordinate[11].y);
	double len2 = (Curpoint.x - vv.coordinate[12].x) * (Curpoint.x - vv.coordinate[12].x) + (Curpoint.y - vv.coordinate[12].y) * (Curpoint.y - vv.coordinate[12].y);
	double len3 = (Curpoint.x - vv.coordinate[20].x) * (Curpoint.x - vv.coordinate[20].x) + (Curpoint.y - vv.coordinate[20].y) * (Curpoint.y - vv.coordinate[20].y);
	int i=1; double ii=len1;
	if (len1 > len2)
	{ i = 2;
	  ii = len2;
	}
 	if (len3 < ii)
	{
		i = 3;
	}
	

//	str.Format("%lf %lf %lf", len1, len2, len3);
//	CClientDC dc(this);
//	dc.TextOut(10, 50, str);
	CString str;
	switch (i){
	case 1:
		str = "离 荟萃餐厅 最近";
		break;
	case 2:
	    str = "离 玉兰餐厅 最近";
		break;
	case 3:
	    str = "离 唐岛湾餐厅 最近";
		break;
	}
	AfxMessageBox(str);
	
		

	// TODO: Add your command handler code here
	
}

void CUPCGPSDlg::OnStudy() 
{
	// TODO: Add your command handler code here
	double len1 = (Curpoint.x - vv.coordinate[17].x) * (Curpoint.x - vv.coordinate[17].x) + (Curpoint.y - vv.coordinate[17].y) * (Curpoint.y - vv.coordinate[17].y);
	double len2 = (Curpoint.x - vv.coordinate[15].x) * (Curpoint.x - vv.coordinate[15].x) + (Curpoint.y - vv.coordinate[15].y) * (Curpoint.y - vv.coordinate[15].y);
	double len3 = (Curpoint.x - vv.coordinate[21].x) * (Curpoint.x - vv.coordinate[21].x) + (Curpoint.y - vv.coordinate[21].y) * (Curpoint.y - vv.coordinate[21].y);
	double len4 = (Curpoint.x - vv.coordinate[22].x) * (Curpoint.x - vv.coordinate[22].x) + (Curpoint.y - vv.coordinate[22].y) * (Curpoint.y - vv.coordinate[22].y);
	
	int i=1; double ii=len1;
	if (len1 > len2)
	{ i = 2;
	ii = len2;
	}
	if (len3 < ii)
	{
		i = 3; 	ii = len3;
	}
	if (len4 < ii)
	{
		i = 4;
	}

	CString str;
	switch (i){
	case 1:
		str = "离 讲堂群 最近";
		break;
	case 2:
		str = "离 图书馆 最近";
		break;
	case 3:
		str = "离 南教 最近";
		break;
	case 4:
		str = "离 文理楼 最近";
		break;
	}
	AfxMessageBox(str);
	
	
	
}

void CUPCGPSDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	Curpoint = point;
	CMenu popMenu;
	popMenu.LoadMenu(IDR_MENU);		//载入菜单
	CMenu *pPopup;
	pPopup=popMenu.GetSubMenu(0);	//获得子菜单指针
	
	pPopup->EnableMenuItem(ID_REST ,MF_BYCOMMAND|MF_ENABLED);	//允许菜单项使用
	pPopup->EnableMenuItem(ID_STUDY ,MF_BYCOMMAND|MF_ENABLED);	//允许菜单项使用
	
	pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);			//显示弹出菜单，参数依次为(鼠标在菜单左边|跟踪右键，x，y，this)
	pPopup->Detach();
	popMenu.DestroyMenu();

}
