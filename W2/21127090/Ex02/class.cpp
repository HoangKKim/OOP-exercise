#include "func2.h"

string Student::getName()
{
	return this->name;
}

float Student::getScore()
{
	return this->score;
}

void Class::addStudent(Student newStudent)
{
	bool flag = true;
	for (int i = 0; i < arrStudent.size(); i++)
	{
		if (arrStudent[i].getName() == newStudent.getName())
		{
			cout << "Da co hoc sinh trong lop" << endl;
			return;
		}
	}
	arrStudent.push_back(newStudent);
	cout << "Them hoc sinh thanh cong" << endl;
}

void Class::deleteStudent(string deletedStudent)
{
	for (int i = 0; i < arrStudent.size(); i++)
	{
		if (arrStudent[i].getName() == deletedStudent)
		{
			arrStudent.erase(arrStudent.begin()+i);
			cout << "Xoa hoc sinh thanh cong" << endl;
			return;
		}
	}
	cout << "Khong co hoc sinh trong lop" << endl;
}

void Class::descendingOrder()
{
	quickSort(0, arrStudent.size()-1);
}

int Class::partition(int low, int high)
{
	float pivot = arrStudent[high].getScore();
	int left = low;
	int right = high - 1;
	while (true)
	{
		while (left <= right && arrStudent[left].getScore() > pivot)
		{
			left++;
		}
		while (right >= left && arrStudent[right].getScore() < pivot)
		{
			right--;
		}
		if (left >= right)
		{
			break;
		}
		swap(arrStudent[left], arrStudent[right]);
		left++;
		right--;
	}
	swap(arrStudent[left], arrStudent[high]);
	return left;
}

void Class::quickSort(int low, int high)
{
	if (low < high)
	{
		float pos = partition(low, high);
		quickSort(low, pos - 1);
		quickSort(pos + 1, high);
	}
}

void Class::output()
{
	for (int i = 0; i < arrStudent.size(); i++)
	{
		arrStudent[i].output();
		cout << endl;
	}
}

void Class::input(const char *filePath)
{
	int n;
	fstream fi;
	fi.open(filePath, ios::in);
	if (fi.is_open())
	{
		fi >> n;
		arrStudent.resize(n);
		for (int i = 0; i < arrStudent.size(); i++)
		{
			fi.ignore();
			arrStudent[i].inputTextFile(fi);
		}
		fi.close();
	}
}