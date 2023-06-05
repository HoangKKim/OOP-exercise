#include "func2.h"

Hero::Hero()
{
	Skill* defaultSkill = new Skill;
	heroName = "player";
	heroHealth = 100;
	heroMana = 100;
	heroLevel = 1;
	skillList.push_back(defaultSkill);
}

Hero::Hero(string name, unsigned int health, unsigned int mana, unsigned int level, vector<Skill*> list)
{
	heroName = name;
	heroHealth = health;
	heroMana = mana;
	heroLevel = level;
	skillList = list;
}

Hero::Hero(const Hero& srcHero)
{
	heroName = srcHero.heroName;
	heroHealth = srcHero.heroHealth;
	heroMana = srcHero.heroMana;
	heroLevel = srcHero.heroLevel;
	skillList = srcHero.skillList;
}

Hero::~Hero()
{
	heroName = '\0';
	heroHealth = 0;
	heroMana = 0;
	heroLevel = 0;
	for (int i = 0; i < skillList.size(); i++)
	{
		delete skillList[i];
		skillList[i] = NULL;
	}
	skillList.clear();
}

void Hero::setName(string name)
{
	heroName = name;
}

void Hero::setHealth(unsigned int health)
{
	heroHealth = health;
}

void Hero::setMana(unsigned int mana)
{
	heroMana = mana;
}

void Hero::setLevel(unsigned int level)
{
	heroLevel = level;
}

void Hero::setSkillList(vector<Skill*> list)
{
	skillList = list;
}

string Hero::getName()
{
	return heroName;
}

unsigned int Hero::getHealth()
{
	return heroHealth;
}

unsigned int Hero::getMana()
{
	return heroMana;
}

unsigned int Hero::getLevel()
{
	return heroLevel;
}

vector <Skill*> Hero::getSkillList()
{
	return skillList;
}

void Hero:: input()
{
	int n;
	cout << "Input hero information: " << endl;
	cout << "Hero name: ";
	getline(cin, heroName);
	cout << "Hero health: ";
	cin >> heroHealth;
	cout << "Hero mana: ";
	cin >> heroMana;
	cout << "Hero level: ";
	cin >> heroLevel;
	cout << "Number of skills in list: ";
	cin >> n;
	skillList.resize(n);
	cout << "Skill list: " << endl;
	for (int i = 0; i < n; i++)
	{
		skillList[i] = new Skill;
		skillList[i]->input();
	}
	
}

void Hero::output()
{
	cout << "Hero information: " << endl;
	cout << "- Hero name: " << heroName << endl;
	cout << "- Hero health: " << heroHealth << endl;
	cout << "- Hero mana: " << heroMana << endl;
	cout << "- Hero level: " << heroLevel << endl;
	cout << "- Skill list: " << endl;
	for (int i = 0; i < skillList.size(); i++)
	{
		skillList[i]->output();
	}
}

void Hero::learnedSkill()
{
	for (int i = 0; i < skillList.size(); i++)
	{
		if (heroLevel >= skillList[i]->getSkillLevel())
		{
			skillList[i]->output();
		}
	}
}

void Hero::cutSkill(int n)
{
	if (n >= skillList.size())
	{
		skillList.clear();
		return;
	}
	else
	{
		int tmp = skillList.size() - n;
		for (int i = skillList.size() - 1; i >= tmp; i--)
		{
			delete skillList[i];
			skillList[i] = nullptr;
			skillList.erase(skillList.begin() + i);
		}
	}
	cout << "List skills after erasing: " << endl;
	for (int i = 0; i < skillList.size(); i++)
	{
		skillList[i]->output();
	}
}