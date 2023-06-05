#include "SourcePage.h"

MusicApp::MusicApp()
{
	listSong.resize(0);
	mUser = new User;
}

MusicApp::MusicApp(vector<Song*> mListSong, User* myUser)
{
	mUser = new User;
	*mUser = *myUser;
	listSong.resize(mListSong.size());
	for (int i = 0; i < listSong.size(); i++)
	{
		listSong[i] = new Song;
		*listSong[i] = *mListSong[i];
	}
}

MusicApp::MusicApp(MusicApp const& mMsApp)
{
	for (int i = 0; i < listSong.size(); i++)
	{
		delete listSong[i];
	}
	listSong.clear();

	delete mMsApp.mUser;

	mUser = new User;
	*mUser = *mMsApp.mUser;

	listSong.resize(mMsApp.listSong.size());
	for (int i = 0; i < listSong.size(); i++)
	{
		listSong[i] = new Song;
		*listSong[i] = *mMsApp.listSong[i];
	}
}

MusicApp::~MusicApp()
{
	delete mUser;
	mUser = nullptr;
	for (int i = 0; i < listSong.size(); i++)
	{
		delete listSong[i];
		listSong[i] = NULL;
	}
	listSong.clear();
}

void MusicApp::input()
{
	int n;
	cout << "Number of songs: ";
	cin >> n;
	listSong.resize(n);
	cin.ignore();
	for (int i = 0; i < listSong.size(); i++)
	{
		listSong[i] = new Song;
		listSong[i]->input();
		cout << endl;
	}
}

void MusicApp::output()
{
	cout << "The number of songs: " << listSong.size() << endl;
	for (int i = 0; i < listSong.size(); i++)
	{
		cout << "THE " << i + 1 << " SONG " << endl;
		listSong[i]->output();
		cout << endl;
	}
}

void MusicApp::addASong()
{
	int i = listSong.size();
	listSong.resize(i + 1);
	listSong[i] = new Song;
	cin.ignore();
	listSong[i]->input();
}

void MusicApp::printASong()
{
	string name;
	cin.ignore();
	cout << "Enter name of song printing: ";
	getline(cin, name);
	for (int i = 0; i < listSong.size(); i++)
	{
		if (listSong[i]->getNameOfSong() == name)
		{
			listSong[i]->output();
			return;
		}
	}
}

void MusicApp::displayTop5Song()
{
	for (int i = 0; i < listSong.size() - 1; i++)
	{
		for (int j = i + 1; j < listSong.size(); j++)
		{
			if (listSong[i]->getNumberOfListens() < listSong[j]->getNumberOfListens())
			{
				swap(*listSong[i], *listSong[j]);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		listSong[i]->output();
	}
}

void MusicApp::userMenu()
{
	int choice;
	string tmp;
	cout << "1. Log in" << endl;
	cout << "2. Sign in" << endl;
	cout << "Enter number of your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		mUser = new User;
		mUser->logIn();
	}
	else
	{
		string tmp;
		cin.ignore();
		cout << "Sign in with VIP account: ";
		getline(cin, tmp);
		if (tmp == "True")
		{
			mUser = new VipUser;
		}
		else mUser = new User;
		mUser->signIn();
	}

	system("cls");
	bool flag = true;
	while (flag)
	{
		mUser->mainMenu();
		cout << "Your number of choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			playMusic();
			break;
		case 2:
			mUser->addSongInPlaylist();
			break;
		case 3:
			mUser->eraseSongInPLaylist();
			break;
		case 4:
			mUser->inputPlaylist();
			break;
		case 5:
			mUser->outputPlaylist();
			break;
		case 6:
			addASong();
			break;
		case 7:
			printASong();
			break;
		case 8:
			displayTop5Song();
			break;
		case 9:
			recommendSong();
			break;
		case 10:
			maintainVipAccount();
			break;
		default:
			return;
		}
		cout << "Continue? - Yes or No: ";
		cin >> tmp;
		if (tmp == "Yes")
		{
			flag == true;
			system("cls");
		}
		else flag = false;
	}
	

}

void MusicApp::playMusic()
{
	srand((unsigned int)time(NULL));
	cout << "**********Playing music**********" << endl;
	int i = rand() % (listSong.size()-1 - 0 + 1) + 0;
	cout << listSong[i]->getNameOfSong() << endl;
	cout << listSong[i]->getLyric() << endl;
	cout << "Copyright fee is: " << mUser->copyrightFee(*listSong[i]);
}

void MusicApp::maintainVipAccount()
{
	int money;
	cout << "Fee: 10$/month" << endl;
	cout << "Enter the number of extension money ($): ";
	cin >> money;
	int t = money / 10;
	cout << "Your duration is " << t << " month(s)" << endl;

}

void MusicApp::recommendSong()
{
	string tmp;
	bool flag = false;
	int max = 0, pos = 0;
	cin.ignore();
	cout << "Enter kind of song: ";
	getline(cin, tmp);
	for (int i = 0; i < listSong.size(); i++)
	{
		if (tmp == listSong[i]->getKindOfSong() && max < listSong[i]->getNumberOfListens())
		{
			max = listSong[i]->getNumberOfListens();
			pos = i;
			flag = true;
		}
	}
	if (flag == true)
	{
		cout << "Reccomending song " << endl;
		listSong[pos]->output();
	}
	else cout << "Don't have any data" << endl;
}