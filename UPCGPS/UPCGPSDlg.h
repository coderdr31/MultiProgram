// UPCGPSDlg.h : header file
//

#if !defined(AFX_UPCGPSDLG_H__4C1E56BD_DB8C_43DB_BF72_63F3658C9600__INCLUDED_)


#define AFX_UPCGPSDLG_H__4C1E56BD_DB8C_43DB_BF72_63F3658C9600__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUPCGPSDlg dialog

                

#include <AFXTEMPL.H>
class CUPCGPSDlg : public CDialog
{
// Construction
public:
	CPoint Curpoint;
	CRect rect[21];
	void Resize(double x);
	int mouseState;
	CArray<CPoint, CPoint> pAar;
	double ssy;	//屏幕起点位置
	double ssx;
	double sy;   //图起点位置
	double sx;
	double coe;    //放大，缩小倍数
	double curh;  //现图长
	double curw;   //现图宽
	
	double pw;  //原图长
	double ph;  //原图宽
	CMemDC mdc; 
	CMemDC fmdc;
    

	CUPCGPSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUPCGPSDlg)
	enum { IDD = IDD_UPCGPS_DIALOG };
	CComboBox	m_end_combol;
	CComboBox	m_start_combol;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUPCGPSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUPCGPSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSearchButton();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBigButton();
	afx_msg void OnSmallButton();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChangecolButton();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnEgButton();
	afx_msg void OnRest();
	afx_msg void OnStudy();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPCGPSDLG_H__4C1E56BD_DB8C_43DB_BF72_63F3658C9600__INCLUDED_)
