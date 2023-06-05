#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Song
{
private:
	string nameOfSong;
	string lyric;
	string nameOfSinger;
	string genre;
	string released;
	int numberOfListens;
	string kindOfSong;
	bool isCopyright;
	int price;
public:
	Song();
	Song(string, string, string, string, string, int, string, bool, int);
	Song(const Song& mSong);
	string getNameOfSong();
	int getNumberOfListens();
	string getKindOfSong();
	int getCopyrightFee();
	string getLyric();
	void input();
	void output();
	~Song();

};

class User
{
protected:
	string username;
	string password;
	vector <Song*> mPlaylist;
public:
	User();
	User(string, string, vector<Song*>);
	User(const User& mUser);
	void addSongInPlaylist();
	void eraseSongInPLaylist();
	void inputPlaylist();
	void outputPlaylist();
	virtual int copyrightFee(Song tmp);
	virtual void signIn();
	virtual void logIn();
	virtual void mainMenu();
	~User();
private:
	bool haveSpace(string tmp);
};

class VipUser : public User
{
public:
	int copyrightFee(Song tmp);
	void mainMenu();
};

class MusicApp
{
private:
	vector <Song*> listSong;
	User* mUser;
public:
	MusicApp();
	MusicApp(vector <Song*>, User*);
	MusicApp(MusicApp const& mMsApp);
	void input();
	void output();
	void addASong();
	void printASong();
	void displayTop5Song();
	void playMusic();
	void userMenu();
	void recommendSong();
	void maintainVipAccount();
	~MusicApp();
};

