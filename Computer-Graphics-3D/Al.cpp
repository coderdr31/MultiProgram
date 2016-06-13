// Al.cpp: implementation of the CAl class.
//
//////////////////////////////////////////////////////////////////////

#include "Al.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAl::CAl()
{

}

CAl::~CAl()
{

}

void CAl::ReadData()
{
	if (!m_pModel) 
	{
        m_pModel = glmReadOBJ("data/al.obj");
        if (!m_pModel) exit(0);
        glmUnitize(m_pModel);
        glmFacetNormals(m_pModel);
        glmVertexNormals(m_pModel, 90.0);
    }
}

void CAl::Draw()
{
	if (m_pModel)
		glmDraw(m_pModel, GLM_SMOOTH | GLM_MATERIAL);
}