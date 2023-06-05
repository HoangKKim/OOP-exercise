#include "Lib.h"

void File::addComponent(Component* iComponent)
{
	cout << "Adding file in file is invalid" << endl;
}

string File::getObjName()
{
	return "File";
}

Component* File::Clone()
{
	return new File(*this);
}

void File::removeComponent(Component* iComponent)
{
	delete iComponent;
	iComponent = NULL;
}