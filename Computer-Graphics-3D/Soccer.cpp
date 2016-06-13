// Soccer.cpp: implementation of the CSoccer class.
//
//////////////////////////////////////////////////////////////////////

#include "Soccer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSoccer::CSoccer()
{

}

CSoccer::~CSoccer()
{

}
void CSoccer::ReadData()
{
	if (!m_pModel) 
	{
        m_pModel = glmReadOBJ("data/soccerball.obj");
        if (!m_pModel) exit(0);
        glmUnitize(m_pModel);
        glmFacetNormals(m_pModel);
        glmVertexNormals(m_pModel, 90.0);
    }
}

void CSoccer::Draw()
{
	if (m_pModel)
		glmDraw(m_pModel, GLM_SMOOTH | GLM_MATERIAL);
}