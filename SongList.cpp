/*
The implementation file for class SongList
*/

#include "SongList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* Default constructor. It initializes the list to be empty.
*/
SongList::SongList()
{
	capacity = SONGLIST_CAPACITY;
	list = new Song[capacity];
	size = 0;
}

/* A constructor that initializes the list with data from the passed in file.
in: fileName
*/
SongList::SongList(int initCapacity, const char fileName[])
{
	capacity = initCapacity;
	list = new Song[capacity];
	size = 0;
	loadSongs(fileName);
}
/* Destructor. It releases the memory allocated for the array.
*/
SongList::~SongList()
{
	if (list != NULL)
		delete[] list;
}

/* This function reads the entries from the file and adds them to the list.
in: fileName
*/
void SongList::loadSongs(const char fileName[])
{
	ifstream in;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	Song aSong;

	in.open(fileName);
	if (!in)
	{
		in.clear();
		cerr << endl << "Failed to open filename '" << fileName << "' for input!" << endl << endl;
		exit (1);
	}

	in.getline(title, MAX_CHAR, ';');
	aSong.setTitle(title);

	while (!in.eof()) 
	{
									
		in.getline(artist, MAX_CHAR, ';');
		aSong.setArtist(artist);								
		in.getline(duration, MAX_CHAR, ';');				
		aSong.setDuration(duration);
		in.getline(album, MAX_CHAR, '\n');
		aSong.setAlbum(album);

		addSong(aSong);

		in.getline(title, MAX_CHAR, ';');		//start the next record
		aSong.setTitle(title);
	}
	in.close();
}

/* This function returns the size of the list.
return: size
*/
int SongList::getSize() const
{
	return size;
}

/* This function returns the Song object at the specified position through parameter
in: index
out: aSong
return: true if the entry exists, false if illegal index is passed in
*/
bool SongList::get(int index, Song &aSong) const
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	if (index < 0 || index >= size)
	{
		return false;
	}

	list[index].getArtist(artist);
	list[index].getDuration(duration);
	list[index].getAlbum(album);
	list[index].getTitle(title); 

	aSong.setArtist(artist);
	aSong.setDuration(duration);
	aSong.setAlbum(album);
	aSong.setTitle(title);
	return true;
}



/* This function searches the list for an entry with passed in artist.
in: artist
out: match
return: true if a match is found and match will be returned through parameter.
false if a match can not be found and match contains garbage.
*/
bool SongList::searchArtist(const char artist[], Song &match) const
{
	int index;
	char currentTitle[MAX_CHAR];
	char currentArtist[MAX_CHAR];
	char currentDuration[MAX_CHAR];
	char currentAlbum[MAX_CHAR];

	for (index = 0; index<size; index++)
	{
		list[index].getTitle(currentTitle);
		list[index].getArtist(currentArtist);
		list[index].getDuration(currentDuration);
		list[index].getAlbum(currentAlbum);
		
		if (strcmp(artist, currentArtist) == 0)
		{
			match.setTitle(currentTitle);
			match.setArtist(currentArtist);
			match.setDuration(currentDuration);
			match.setAlbum(currentAlbum);
			cout << endl << currentArtist << endl << currentTitle << endl << currentDuration << endl << currentAlbum << endl << endl;

		}
	}
	if (index == size)
	{
		return false;
	}
	else
	{
		return true;
	}
}



/* This function searches the list for an entry with passed in album.
in: album
out: match
return: true if a match is found and match will be returned through parameter.
false if a match can not be found and match contains garbage.
*/
bool SongList::searchAlbum(const char album[], Song &match) const
{
	int index;
	char currentTitle[MAX_CHAR];
	char currentArtist[MAX_CHAR];
	char currentDuration[MAX_CHAR];
	char currentAlbum[MAX_CHAR];

	for (index = 0; index<size; index++)
	{
		list[index].getTitle(currentTitle);
		list[index].getArtist(currentArtist);
		list[index].getDuration(currentDuration);
		list[index].getAlbum(currentAlbum);
		
		if (strcmp(album, currentAlbum) == 0)
		{
			match.setTitle(currentTitle);
			match.setArtist(currentArtist);
			match.setDuration(currentDuration);
			match.setAlbum(currentAlbum); 
			cout << endl << currentTitle << endl << currentArtist << endl << currentDuration << endl << currentAlbum << endl << endl;
		
		}
	}
	if (index == size)
	{
			return false;
	}
	else
	{
		return true;
	}
}




/* This function prints all the entries to the standard output.
*/
void SongList::printAll() const
{
	int index;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	for (index = 0; index<size; index++)
	{
		list[index].getTitle(title);
		list[index].getArtist(artist);
		list[index].getDuration(duration);
		list[index].getAlbum(album);
		cout << "Title: "  << title << endl << "Artist: " << artist << endl << "Duration: "<< duration << endl << "Album: "<< album << endl << endl;
	}
}


/* This function saves the list to the external file.
in: fileName
*/
void SongList::saveSongs(const char fileName[]) const
{
	ofstream out;
	int index;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	out.open(fileName);
	if (!out)
	{
		out.clear();
		cerr << endl << "Failed to open filename '" << fileName << "' for output." << endl << endl;
		exit(1);
	}

	for (index = 0; index<size; index++)
	{
		list[index].getTitle(title);
		list[index].getArtist(artist);
		list[index].getDuration(duration);
		list[index].getAlbum(album);

		out << title << ';' << artist << ';' << duration << ';' << album << endl;
	}

	out.close();
}


/* This function adds a passed in entry to the end of the list.
in: anEntry
*/
void SongList::addSong(const Song &aSong)
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	if (size == capacity)
	{
		expandList();
	}
	aSong.getTitle(title);
	aSong.getArtist(artist);
	aSong.getDuration(duration);
	aSong.getAlbum(album);
	list[size].setTitle(title);
	list[size].setArtist(artist);
	list[size].setDuration(duration);
	list[size].setAlbum(album);

	size++;
}

/* This function removes a passed in song from the list.
in: song ... is this part right?
*/
void SongList::removeSong(const int delIndex, Song &aSong) //do i need to make const int index? do i need to change to removIndex?
{

	char temp[MAX_CHAR];

	if (delIndex<0 || delIndex >= size)
	{
		cout << "Invalid index number. " << endl;
		exit(1);
	}
	else
	{
		for (int i = delIndex; i < size -1; i++)
		{
			list[i + 1].getTitle(temp);
			list[i].setTitle(temp);

			list[i + 1].getArtist(temp);
			list[i].setArtist(temp);

			list[i + 1].getDuration(temp);
			list[i].setDuration(temp);

			list[i + 1].getAlbum(temp);
			list[i].setAlbum(temp);
		}
		size--;
	}
}


/* This function creates a new array that is twice as big as the current one. It copies the Song
objects over to this new array.
making the array twice as big is a middle ground of efficiency. more efficient than
changing the array size every time a new object is added, and doesn't take up a 
massive, unnecessary amount of memory (ie making the array size enormous and leaving most of it empty)
*/
void SongList::expandList()
{
	Song * tempList;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	int index;

	//create new array
	capacity *= 2;
	tempList = new Song[capacity];

	//copy over the contents
	for (index = 0; index<size; index++)
	{
		list[index].getTitle(title);
		list[index].getArtist(artist);
		list[index].getDuration(duration);
		list[index].getAlbum(album);
		tempList[index].setTitle(title);
		tempList[index].setArtist(artist);
		tempList[index].setDuration(duration);
		tempList[index].setAlbum(album);
	}

	//release the memory from the old array
	delete[] list;

	//make list point to the new array
	list = tempList;
	tempList = NULL;
}