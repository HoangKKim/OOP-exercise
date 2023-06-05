#include "SourcePage.h"

int main()
{
	MusicApp mMusicApp;
	cout << "Enter list of songs " << endl;
	mMusicApp.input();
	mMusicApp.output();
	system("cls");
	mMusicApp.userMenu();
}