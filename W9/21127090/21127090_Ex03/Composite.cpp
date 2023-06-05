#include "Lib.h"

Folder::Folder()
{
	Components.resize(0);
}

float Folder::getSize()
{
	float totalSize = this->size;
	/*if (this->Components.size() == 0)
	{
		return this->size;
	}*/
	for (int i = 0; i < Components.size(); i++)
	{
		totalSize = totalSize + Components[i]->getSize(); // dequy
	}
	return totalSize;
}

void Folder::addComponent(Component* iComponent)
{
	cout << "Name of " << iComponent->getObjName() << ": ";
	string name;
	getline(cin,name);
	iComponent->setName(name);
	cout << "Size: ";
	float mSize;
	cin >> mSize;
	iComponent->setSize(mSize);
	Components.push_back(iComponent);
}

void Folder::display(int depth)
{
	for (int i = 0; i < Components.size(); i++)
	{
		for (int j = 0; j < depth; j++)
		{
			cout << " ";
		}
		cout << Components[i]->getName() <<" - "<<Components[i]->getObjName() << endl;
		Components[i]->display(depth+1);
	}
}

void Folder::removeComponent(Component* iComponent)
{
	for (int i = 0; i < Components.size(); i++)
	{
		if (Components[i] == iComponent)
		{
			Components.erase(Components.begin() + i);
		}
	}
}

Folder::~Folder()
{
	for (int i = 0; i < Components.size(); i++)
	{
		delete Components[i];
		Components[i] = NULL;
	}
}

string Folder::getObjName()
{
	return "Folder";
}

Component* Folder::Clone()
{
	return new Folder(*this);
}

void Folder::input()
{
	bool flag = true;
	Component::addSampleObject(new Folder);
	Component::addSampleObject(new File);
	do
	{
		flag = true;
		cout << "Enter File or Folder to create: ";
		string tmp;
		cin >> tmp;
		cin.ignore();
		Component* tmpD = Component::createObjectByName(tmp);
		if (tmpD != NULL)
		{
			this->addComponent(tmpD);
			if (tmpD->getObjName() == "Folder")
			{
				cout << "Continue in Folder " << tmpD->getName() << " (yes or no) : ";
				cin.ignore();
				cin >> tmp;
				if (tmp == "yes")
				{
					tmpD->input();
				}
				else flag = false;
			}
			cout << "Continue in " << this->getName() << " (yes or no) : ";
			cin.ignore();
			cin >> tmp;
			if (tmp == "yes")
			{
				flag = true;
			}
			else flag = false;

		} 		
		

	} while (flag == true);
}
