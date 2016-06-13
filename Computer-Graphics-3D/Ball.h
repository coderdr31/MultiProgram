// Soccer.h: interface for the CSoccer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCCER1_H__B7493E27_FCE3_486F_99FB_CD7875B920C6__INCLUDED_)
#define AFX_SOCCER1_H__B7493E27_FCE3_486F_99FB_CD7875B920C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "3DObject.h"

class CSoccer : public C3DObject  
{
public:
	CSoccer();
	virtual ~CSoccer();
	void ReadData();
	void Draw();

};

#endif // !defined(AFX_SOCCER1_H__B7493E27_FCE3_486F_99FB_CD7875B920C6__INCLUDED_)
