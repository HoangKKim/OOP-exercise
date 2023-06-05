#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Component
{
protected: 
	string name;
	float size;
	static vector<Component*> sampleObject;
public:
	string getName()
	{
		return this->name;
	}
	virtual float getSize()
	{
		return this->size;
	}
	virtual void setSize(float mSize)
	{
		this->size = mSize;
	}
	virtual void setName(string mName)
	{
		this->name = mName;
	}
	virtual void addComponent(Component* iComponent) = 0;
	virtual void removeComponent(Component* iComponent) = 0;
	virtual ~Component() {}
	virtual void display(int depth) {}
	virtual Component* Clone() = 0;
	static void addSampleObject(Component* smplOb);
	static Component* createObjectByName(string mName);
	static void deleteSampleObject();
	virtual string getObjName() = 0;
	virtual void input()=0;
};

class Folder :public Component // folder
{
private:
	vector <Component*> Components;
public:
	Folder();
	float getSize();
	void display(int depth);
	void addComponent(Component* iComponent);
	void removeComponent(Component* iComponent);
	Component* Clone();
	string getObjName();
	void input();
	~Folder();
};

class File : public Component
{
public:
	void addComponent(Component* iComponent);
	void removeComponent(Component* iComponent);
	Component* Clone();
	string getObjName();
	void input() {}
	File() {};
	~File() {};
};