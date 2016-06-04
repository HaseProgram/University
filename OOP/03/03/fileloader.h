#pragma once

/*!
\brief  Loader from file
\author Dmitry Zaitsev
\version 2.0
\date 29 May 2016

Provide loading model from file
*/

#include <stdio.h>
#include "baseloader.h"
#include "compositeobject.h"
#include "exceptionfileloader.h"

class FLoader : public BaseLoader
{
public:
	FLoader(const char* filename);

	void openFile();
	void closeFile();

	bool readAmount(unsigned int& amount);

	virtual Point readPoint() override;
	virtual Edge readEdge(Model* model) const override;

	void readPoints(Model*);
	void readEdges(Model*);

	virtual Model* readModel() override;

	virtual BaseObject* loadModel();	

private:
	const char* filename;
	FILE* file;
	int amountPoints;
	int amountEdges;
};