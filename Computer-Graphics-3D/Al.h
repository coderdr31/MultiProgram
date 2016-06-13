// Al.h: interface for the CAl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AL_H__582ACFA4_8FC7_42FF_BAD1_5A2CEBA3A56F__INCLUDED_)
#define AFX_AL_H__582ACFA4_8FC7_42FF_BAD1_5A2CEBA3A56F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "3DObject.h"

class CAl : public C3DObject 
{
public:
	CAl();
	virtual ~CAl();
    void ReadData();
	void Draw();

};

#endif // !defined(AFX_AL_H__582ACFA4_8FC7_42FF_BAD1_5A2CEBA3A56F__INCLUDED_)
