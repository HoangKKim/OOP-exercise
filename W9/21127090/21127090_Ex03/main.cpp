#include "Lib.h"

int main()
{
	Component* mComponent = new Folder;
	cout << "Set name of Disk: ";
	string tmp;
	cin >> tmp;
	mComponent->setName(tmp);
	system("cls");
	cout << "Reputating on " << mComponent->getName() << endl;
	mComponent->input();
	cout << endl;
	cout << "Display on " << mComponent->getName()<< endl;
	mComponent->display(0);
	cout << "Size of disk " << mComponent->getName() << ": " << mComponent->getSize();
	mComponent->deleteSampleObject();
	mComponent->~Component();
	delete mComponent;
}