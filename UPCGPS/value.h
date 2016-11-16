// value.h: interface for the value class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALUE_H__A7CB026B_0F42_4F7B_8195_63A9DFB58308__INCLUDED_)
#define AFX_VALUE_H__A7CB026B_0F42_4F7B_8195_63A9DFB58308__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NUMBER_ 100

class value  
{
public:
	value();
	virtual ~value();

	CPoint coordinate[NUMBER_];           
	double  weight[NUMBER_][NUMBER_];
	int way[NUMBER_][NUMBER_];
	double minLength[NUMBER_][NUMBER_];


};

#endif // !defined(AFX_VALUE_H__A7CB026B_0F42_4F7B_8195_63A9DFB58308__INCLUDED_)
