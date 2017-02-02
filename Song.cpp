/*
The implementation file for class Song.
*/

#include "Song.h"
#include <iostream>
#include <cstring>

using namespace std;

/* Default constructor. It initializes the Song member objects to a default value.
*/
Song::Song()
{
	title = new char[strlen("empty title") + 1];
	strcpy(title, "empty title");
	artist = new char[strlen("empty artist") + 1];
	strcpy(artist, "empty artist");
	duration = new char[strlen("empty duration") + 1];
	strcpy(duration, "empty duration");
	album = new char[strlen("empty album") + 1];
	strcpy(album, "empty album");

}
/* Constructor. It initializes the title/artist/etc with the passed in value.
in: title, artist, duration, album
*/
Song::Song(const char title[], const char artist[], const char duration[], const char album[])
{

	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);	//this->title refers to the instance variable "title"
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist); //this->artist refers to the instance variable "artist"
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
	this->album = new char[strlen(album) + 1];
	strcpy(this->album, album);

}

/* Destructor. It releases the dynamic char array allocated for title/artist/duration/album.
*/
Song::~Song()
{
	if (title != NULL)
		delete[] title;
	if (artist != NULL)
		delete[] artist;
	if (duration != NULL)
		delete[] duration;
	if (album != NULL)
		delete[] album;
}

/* This function returns the title of the entry through the parameter.
out: title
*/
void Song::getTitle(char title[]) const
{
	strcpy(title, this->title);
}
void Song::getArtist(char artist[]) const
{
	strcpy(artist, this->artist);
}
void Song::getDuration(char duration[]) const
{
	strcpy(duration, this->duration);
}
void Song::getAlbum(char album[]) const
{
	strcpy(album, this->album);
}

/* This function prints the state of the object to stdout.
*/
void Song::print() const
{

	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Duration: " << duration << endl;
	cout << "Album: " << album << endl;

}


/* This function sets the title to the passed in value.
in: title
*/
void Song::setTitle(const char title[])
{
	if (this->title != NULL)
	{
		delete[] this->title;
	}
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}
void Song::setArtist(const char artist[])
{
	if (this->artist != NULL)
	{
		delete[] this->artist;
	}
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);
}

void Song::setDuration(const char duration[])
{
	if (this->duration != NULL)
	{
		delete[] this->duration;
	}
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
}

void Song::setAlbum(const char album[])
{
	if (this->album != NULL)
	{
		delete[] this->album;
	}
	this->album = new char[strlen(album) + 1];
	strcpy(this->album, album);
}
