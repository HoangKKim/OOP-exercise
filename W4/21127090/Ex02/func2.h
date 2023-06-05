#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Skill
{
private:
	string skillName;
	unsigned int skillLevel;
public:
	// constructor and destructor
	Skill();
	Skill(string, unsigned int);
	Skill(const Skill&);
	~Skill();

	// getter, setter
	void setSkillName(string name);
	void setSkillLevel(unsigned int level);
	string getSkillName();
	unsigned int getSkillLevel();

	// input, output
	void input();
	void output();
};

class Hero
{
private:
	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;
public:
	// constructor, destructor
	Hero();
	Hero(string, unsigned int, unsigned int, unsigned int, vector<Skill*>);
	Hero(const Hero& srcHero);
	~Hero();

	// setter, getter
	void setName(string);
	void setHealth(unsigned int);
	void setMana(unsigned int);
	void setLevel(unsigned int);
	void setSkillList(vector<Skill*>);
	string getName();
	unsigned int getHealth();
	unsigned int getMana();
	unsigned int getLevel();
	vector<Skill*> getSkillList();

	// input, output
	void input();
	void output();

	void learnedSkill();
	void cutSkill(int);
};