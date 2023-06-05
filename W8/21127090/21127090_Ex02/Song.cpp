#include "SourcePage.h"

Song::Song()
{
	nameOfSong = nameOfSinger = lyric = genre = released = kindOfSong = '\0';
	numberOfListens = 0;
	isCopyright = 0;
	price = 0;
}

Song::Song(string m_nameOfSong, string m_lyric, string m_nameOfSinger, string m_genre, string m_released, int m_numberOfListens
	, string m_kindOfSong, bool m_isCopyright, int m_price)
{
	nameOfSong = m_nameOfSong;
	lyric = m_lyric;
	nameOfSinger = m_nameOfSinger;
	genre = m_genre;
	released = m_released;
	numberOfListens = m_numberOfListens;
	kindOfSong = m_kindOfSong;
	isCopyright = m_isCopyright;
	price = m_price;
}

Song::Song(const Song& mSong)
{
	nameOfSong = mSong.nameOfSong;
	lyric = mSong.lyric;
	nameOfSinger = mSong.nameOfSinger;
	genre = mSong.genre;
	released = mSong.released;
	numberOfListens = mSong.numberOfListens;
	kindOfSong = mSong.kindOfSong;
	isCopyright = mSong.isCopyright;
	price = mSong.price;
}

void Song::input()
{
	string tmp;
	cout << "Name of song: ";
	getline(cin, nameOfSong);
	cout << "Name of singer: ";
	getline(cin, nameOfSinger);
	cout << "Genre: ";
	getline(cin, genre);
	cout << "Released: ";
	getline(cin, released);
	cout << "Kind of song: ";
	getline(cin, kindOfSong);
	cout << "Number of listens: ";
	cin >> numberOfListens;
	cin.ignore();
	cout << "Is a copyright song: ";
	getline(cin, tmp);
	if (tmp == "Copyright")
	{
		isCopyright = true;
	}
	else isCopyright = false;
	if (isCopyright)
	{
		cout << "Price of copyright: ";
		cin >> price;
		cin.ignore();
	}
	else price = 0;

	cout << "Lyric: ";
	getline(cin, lyric);
	
}	

void Song::output()
{
	cout << "Name of song: " << nameOfSong << endl;
	cout << "Name of singer: " << nameOfSinger << endl;
	cout << "Genre: " << genre << endl;
	cout << "Released: " << released << endl;
	cout << "Kind of song: " << kindOfSong << endl;
	cout << "Number of listens: " << numberOfListens << endl;
	cout << "Is a copyright song: ";
	if (isCopyright == true)
	{
		cout << "Yes" << endl;
		cout << "Price of copyright: " << price << endl;
	}
	else cout << "No" << endl;
	cout << "Lyric: " << lyric << endl;

}

Song::~Song()
{
	nameOfSong.clear();
	nameOfSinger.clear();
	lyric.clear();
	released.clear();
	genre.clear();
	kindOfSong.clear();
	numberOfListens = 0;
	isCopyright = false;
	price = 0;
}

string Song::getNameOfSong()
{
	return nameOfSong;
}

int Song::getNumberOfListens()
{
	return numberOfListens;
}

string Song::getKindOfSong()
{
	return kindOfSong;
}

int Song::getCopyrightFee()
{
	return price;	
}

string Song::getLyric()
{
	return lyric;
}