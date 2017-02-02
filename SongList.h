/*
The header file for class SongList.
*/

#ifndef SONGLIST_H
#define SONGLIST_H

#include "Song.h"

const int SONGLIST_CAPACITY = 400;
const int OUTPUT_WIDTH = 40; //?

class SongList
{
public:
	//constructors
	SongList();
	SongList(int initCapacity, const char fileName[]);

	//destructor
	~SongList();

	//accessor functions
	bool get(int index, Song& aSong) const;
	bool searchArtist(const char artist[], Song& match) const;
	bool searchAlbum(const char album[], Song& match) const; //do i need to change var name?
	int getSize() const;
	void printAll() const;
	void saveSongs(const char fileName[]) const;

	//mutator functions
	void addSong(const Song& aSong);
	void removeSong(const int delIndex, Song& aSong);
	void loadSongs(const char fileName[]);

private:
	Song * list;
	int size;
	int capacity;

	void expandList();
};

#endif