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

class FLoaderImpl : public BaseLoaderImpl
{
public:
	FLoaderImpl(const char* filename);
	virtual BaseSceneElement* loadModel(BaseSceneElement*) override;
private:
	void openFile();
	void closeFile();

	bool readAmount(unsigned int& amount);

	Point readPoint();
	Edge readEdge(Model* model) const;

	void readPoints(Model*);
	void readEdges(Model*);

	Model* readModel();

	const char* filename;
	FILE* file;
	int amountPoints;
	int amountEdges;
};

class FLoader : public BaseLoader
{
public:
	FLoader(const char* filename) : BaseLoader(new FLoaderImpl(filename)) {}
	virtual BaseSceneElement* loadModel(BaseSceneElement*) override;
};