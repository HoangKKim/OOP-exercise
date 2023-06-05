#include "func2.h"

Skill::Skill()
{
	skillName = "Default";
	skillLevel = 1;
}

Skill::Skill(string name, unsigned int level)
{
	skillName = name;
	skillLevel = level;
}

Skill::Skill(const Skill& sk)
{
	skillName = sk.skillName;
	skillLevel = sk.skillLevel;
}

Skill::~Skill()
{
	skillName = '\0';
	skillLevel = 0;
}

void Skill::setSkillName(string name)
{
	skillName = name;
}

void Skill::setSkillLevel(unsigned int level)
{
	skillLevel = level;
}

string Skill::getSkillName()
{
	return skillName;
}

unsigned int Skill::getSkillLevel()
{
	return skillLevel;
}

void Skill::input()
{
	cin.ignore();
	cout << "Skill name: ";
	getline(cin, skillName);
	cout << "Skill level: ";
	cin >> skillLevel;
}

void Skill::output()
{
	cout << " + Skill name: " << skillName << endl;
	cout << " + Skill level: " << skillLevel << endl;
}


