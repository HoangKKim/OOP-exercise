#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Book
{
private:
	string name;
	string id;
	string category;
public:
	Book()
	{
		name = "undefined";
		id = "00000";
		category = "undefined";
	}
	Book(string mName, string mID, string mCategory);
	~Book()
	{
		name.clear();
		id.clear();
		category.clear();
	}
	string getName();
	string getID();
	string getCategory();
	void input();
	void output();
};

class Library :public Book
{
private: 
	vector <Book> list;
public:
	Library()
	{
		list.resize(0);
	}
	Library(vector<Book> mList);
	~Library()
	{
		list.clear();
	}
	void findBookByName(string mName);
	void findBookByID(string mID);
	void findBookByCategory(string mCategory);
	void input();
	void output();
};
