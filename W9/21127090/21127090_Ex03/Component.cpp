#include "Lib.h"

vector<Component*> Component::sampleObject;

void Component::addSampleObject(Component* smplOb)
{
	if (smplOb == NULL)
	{
		return;
	}
	int pos = -1;
	for (int i = 0; i < sampleObject.size(); i++)
	{
		if (sampleObject[i]->getObjName() == smplOb->getObjName())
		{
			pos = i;
		}
	}
	if (pos == -1)
	{
		sampleObject.push_back(smplOb);
	}
}

Component* Component::createObjectByName(string mName)
{
	for (int i = 0; i < sampleObject.size(); i++)
	{
		if (sampleObject[i]->getObjName() == mName)
		{
			return sampleObject[i]->Clone();
		}
	}
	cout << "Don't have data" << endl;
	return NULL;
}

void Component::deleteSampleObject()
{
	for (int i = 0; i < sampleObject.size(); i++)
	{
		delete sampleObject[i];
		sampleObject[i] = NULL;
	}
}
