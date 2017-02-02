//memory leak detection tool headers
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <cctype>

#include <cstring>

#include "Song.h"
#include "SongList.h"
#include "InputTools.h"

using namespace std;

//user-interface related functions
void displayMenu();
int readInCommand();
void processCommand(char command, SongList& list);
void readInSong(Song& aSong);
void readSearchArtist(char artist[]);
void readSearchAlbum(char album[]);

//void readSearchArtist(char artist[]);
//void readSearchAlbum(char album[]);

//Song getSong(); 

int main()
{
	//enable memory leak detection tools
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char command;
	char fileName[] = "Songs.txt";
	SongList list(1, fileName);

	displayMenu();
	command = readInCommand();
	while (command != 6)
	{
		processCommand(command, list);
		displayMenu();
		command = readInCommand();
	}

	list.saveSongs(fileName);

	return 0;
}

/* Displays the main menu */

void displayMenu()
{
	cout << endl << "Music Library" << endl << endl;
	cout << "1) Display all songs" << endl;
	cout << "2) Add new song" << endl;
	cout << "3) Remove song" << endl;
	cout << "4) Search song by artist" << endl;
	cout << "5) Search song by album" << endl;
	cout << "6) Save all and Quit" << endl << endl;

}

/*this function reads in the user's choice. */
int readInCommand()
{
	char cmd;

	cmd = readInt("Enter Choice: ");

	return (cmd); //should i be returning a char? or an int? change the funct to int readInCommand?
}

/* This function processes the command passed in.
in: command
in/out: list and listSize
*/
void processCommand(char command, SongList& list)
{
	Song song;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	int delIndex;

	switch (command)
	{
	case 1: list.printAll();
		break;
	case 2: readInSong(song);
		list.addSong(song);
		break;
	case 3: delIndex = readInt("Enter the index of the song you'd like to remove: ");
		if ((0 < delIndex) && (delIndex < (list.getSize()))) //this ok?
		{
			list.removeSong(delIndex, song);
		}
		else
		{
			cout << "Invalid index number." << endl << endl;
		}
		break;
	case 4: readSearchArtist(artist);
		if (list.searchArtist(artist, song))
		{
			song.getTitle(title);
			song.getArtist(artist);
			song.getDuration(duration);
			song.getAlbum(album);

		}
		else
		{
			cout << endl << "Seach Complete." << endl << endl;
			
		}
		break;
	case 5: readSearchAlbum(album);
		if (list.searchAlbum(album, song))
		{
			song.getTitle(title);
			song.getArtist(artist);
			song.getDuration(duration);
			song.getAlbum(album);
			
		}
		else
		{
			cout << endl << "Seach Complete." << endl << endl;
			
		}
		break; 

	default: cout << endl << "Invalid input." << endl;
		break;
	}
}

/*
this function reads in a song.
out: aSong
*/
void readInSong(Song& aSong)
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	
	//read in song details
	readString("Song Title: ", title, MAX_CHAR);
	readString("Artist Name: ", artist, MAX_CHAR);
	readString("Song Duration: ", duration, MAX_CHAR);
	readString("Album Title: ", album, MAX_CHAR);

	//populate the passed in object

	aSong.setTitle(title);
	aSong.setArtist(artist);
	aSong.setDuration(duration);
	aSong.setAlbum(album);
}

void readSearchArtist(char artist[])
{
	readString("Enter the Artist name you'd like to search for: ", artist, MAX_CHAR);
}

void readSearchAlbum(char album[])
{
	readString("Enter the Album name you'd like to search for: ", album, MAX_CHAR);
}