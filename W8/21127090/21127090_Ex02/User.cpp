#include "SourcePage.h"

User::User()
{
	username = password = '\0';
	mPlaylist.resize(0);
}

User::User(string mUname, string mPass, vector<Song*>playList)
{
	username = mUname;
	password = mPass;
	mPlaylist.resize(playList.size());
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		mPlaylist[i] = new Song;
		mPlaylist[i] = playList[i];
	}
}

User::User(const User& mUser)
{
	username = mUser.username;
	password = mUser.password;
	mPlaylist.resize(mUser.mPlaylist.size());
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		mPlaylist[i] = new Song;
		mPlaylist[i] = mUser.mPlaylist[i];
	}
}

bool User::haveSpace(string tmp)
{
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] == ' ')
		{
			return true;
		}
	}
	return false;
}

void User::logIn()
{
	cin.ignore();
	bool flag = true;
	do
	{
		flag = true;
		cout << "User name: ";
		getline(cin, username);
		cout << "Password: ";
		getline(cin, password);
		if (haveSpace(username))
		{
			cout << "invalid username - Login again!" << endl;
			flag = false;
		}
		else if(haveSpace(password)==true || password.length()<8)
		{
			cout << "invalid password - Login again!" << endl;
			flag = false;
		}
	} while (flag==false);
	cout << "Login successfully" << endl;
	
	
}

void User::signIn()
{
	string tmp;
	bool flag = true;
	do
	{
		flag = true;
		cout << "Username: ";
		getline(cin, tmp);
		if (haveSpace(tmp))
		{
			cout << "Invalid username, please try again!" << endl;
			flag = false;
		}
	} while (flag == false);

	do
	{
		flag = true;
		cout << "Password: ";
		getline(cin, tmp);
		if (haveSpace(tmp) || tmp.length() < 8)
		{
			cout << "Invalid password, please try again!" << endl;
			flag = false;
		}
	} while (flag == false);
	password = tmp;

	do
	{
		flag = true;
		cout << "Re-enter password: ";
		getline(cin, tmp);
		if (tmp != password)
		{
			cout << "Incorrect password" << endl;
			flag = false;
		}
	} while (flag == false);
	cout << "Sign in successfully" << endl;
}

void User::inputPlaylist()
{
	int n;
	cout << "Number of songs in playlist: ";
	cin >> n;
	cin.ignore();
	mPlaylist.resize(n);
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		mPlaylist[i] = new Song;
		mPlaylist[i]->input();
		cout << endl;
	} 
	cout << "Entering successfully!" << endl;
}

void User::outputPlaylist()
{
	cout << "Number of songs in playlist: " << mPlaylist.size();
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		mPlaylist[i]->output();
		cout << endl;
	}
}

void User::addSongInPlaylist()
{
	cout << "Enter the information of new song in your playlist" << endl;
	cin.ignore();
	int n = mPlaylist.size();
	mPlaylist.resize(n + 1);
	mPlaylist[n] = new Song;
	mPlaylist[n]->input();
	cout << "Add new song successfully!" << endl;
}

void User::eraseSongInPLaylist()
{
	string tmp;
	cin.ignore();
	if (mPlaylist.size() == 0)
	{
		cout << "Don't have any song in your playlist!" << endl;
		return;
	}
	cout << "Input the name of song is erased: ";
	getline(cin, tmp);
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		if (mPlaylist[i]->getNameOfSong() == tmp)
		{
			mPlaylist.erase(mPlaylist.begin() + i);
			cout << "Erasing successfully!" << endl;
			return;
		}
	}
	cout << "Erasing unsuccessfully!" << endl;
}

void User::mainMenu()
{
	cout << "1. Play music" << endl;
	cout << "2. Add a song in playlist" << endl;
	cout << "3. Erase a song in playlist" << endl;
	cout << "4. Enter your playlist" << endl;
	cout << "5. Print your playlist" << endl;
	cout << "6. Add a song " << endl;
	cout << "7. Print a song" << endl;
	cout << "8. Display top 5 songs" << endl;
}

int User::copyrightFee(Song tmp)
{
	return tmp.getCopyrightFee();
}

User::~User()
{
	password.clear();
	username.clear();
	for (int i = 0; i < mPlaylist.size(); i++)
	{
		delete mPlaylist[i];
		mPlaylist[i] = nullptr;
	}
	mPlaylist.clear();
}

void VipUser::mainMenu()
{
	User::mainMenu();
	cout << "9. Recommend song" << endl;
	cout << "10. Maintain VIP account" << endl;
}

int VipUser::copyrightFee(Song tmp)
{
	return tmp.getCopyrightFee() * 0.5;
}