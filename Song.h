#ifndef SONG_H
#define SONG_H

const int MAX_CHAR = 50; 

class Song
{
public:
	//constructors //....should i use a copy constructor to populate my tempList?
	Song(); 
	Song(const char title[], const char artist[], const char duration[], const char album[]);

	//destructor
	~Song();

	//accessor functions
	void getTitle(char title[]) const; //do i want these to be const?
	void getArtist(char artist[]) const;
	void getDuration(char duration[]) const;
	void getAlbum(char album[]) const;
	void print() const;

	//mutator functions
	void setTitle(const char title[]); 
	void setArtist(const char artist[]);
	void setDuration(const char duration[]);
	void setAlbum(const char album[]);


private:
	char *title;
	char *artist;
	char *duration;
	char *album;
};

#endif
