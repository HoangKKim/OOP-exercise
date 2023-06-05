#include "Book.h"

Book::Book(string mName, string mID, string mCategory)
{
	name = mName;
	id = mID;
	category = mCategory;
}

void Book::input()
{
	//cin.ignore();
	cout << "Name of book: ";
	getline(cin, name);
	cout << "ID: ";
	getline(cin, id);
	cout << "Category: ";
	getline(cin, category);
}

void Book::output()
{
	cout << "Name of book: " << name << endl;
	cout << "ID of book: " << id << endl;
	cout << "Category of book: " << category << endl;
}

string Book::getName()
{
	return this->name;
}

string Book::getID()
{
	return this->id;
}

string Book::getCategory()
{
	return this->category;
}

Library::Library(vector <Book> myList)
{
	list.resize(myList.size());
	for (int i = 0; i < list.size(); i++)
	{
		list[i] = myList[i];
	}
}

void Library::input()
{
	int n;
	cout << "Input the number of books in library: ";
	cin >> n;
	list.resize(n);

	cin.ignore();
	for (int i = 0; i < list.size(); i++)
	{
		cout << "Book " << i + 1 << endl;
		list[i].input();
	}
}

void Library::output()
{
	cout << "The number of books in library: " << list.size() << endl;
	for (int i = 0; i < list.size(); i++) 
	{
		cout << "Book " << i + 1 << endl;
		list[i].output();
		cout << endl;
	}
}

void Library::findBookByName(string mName)
{
	bool flag = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getName() == mName)
		{
			list[i].output();
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "This book is not exist" << endl;
	}
}

void Library::findBookByID(string mID)
{
	bool flag = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getID() == mID)
		{
			list[i].output();
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "This book is not exist" << endl;
	}
}

void Library::findBookByCategory(string mCategory)
{
	bool flag = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getCategory() == mCategory)
		{
			list[i].output();
			cout << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "This book is not exist" << endl;
	}
}
