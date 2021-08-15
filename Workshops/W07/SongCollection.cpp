// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-21

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <list>

#include "SongCollection.h"

namespace sdds {

	SongCollection::SongCollection(const std::string fileName) {

		std::ifstream filename(fileName);

		if(!filename.is_open())
			throw "File name is incorrect.";
		else {
			while (!filename.eof()) {
				Song* song = new Song;
				std::string temp, temp2;
				getline(filename, temp);

				song->m_title = temp.substr(0, 25);
				trim(song->m_title);
				song->m_artist = temp.substr(25, 25);
				trim(song->m_artist);
				song->m_album = temp.substr(50, 25);
				trim(song->m_album);
				temp2 = temp.substr(75, 5);
				trim(temp2);

				song->m_year = (temp2 == "") ? 0 : std::stoi(temp2);
				song->m_length = std::stoi(temp.substr(80, 5));
				song->m_price = std::stod(temp.substr(85, 5));

				// Push songs in to the container
				m_songs.push_back(song);
			}
		}
	}

	void SongCollection::display(std::ostream& out) const {

		int time = 0;
		for_each(m_songs.begin(), m_songs.end(), [&out, &time](const Song* i) {
			out << *i << std::endl;
			time += i->m_length;
		});

		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "|";
		out << std::setw(76) << std::setfill(' ') << std::right;
		out << "Total Listening Time" << ": " << time / 3600;
		out << ":" << (time - (time / 3600 * 3600)) / 60;
		out << ":" << (time - (time / 3600 * 3600)) % 60;
		out << " |";
		out << std::endl;

	}

	// comparator function for Sort
	bool compareTitle(Song* s1, Song* s2) {
		return (s1->m_title < s2->m_title);
	}

	bool compareAlbum(Song* s1, Song* s2) {
		return (s1->m_album < s2->m_album);
	}

	bool compareLength(Song* s1, Song* s2) {
		return (s1->m_length < s2->m_length);
	}

	void SongCollection::sort(const std::string srt) {

		if (srt == "title")
			std::sort(m_songs.begin(), m_songs.end(), compareTitle);
		else if (srt == "album")
			std::sort(m_songs.begin(), m_songs.end(), compareAlbum);
		else if (srt == "length")
			std::sort(m_songs.begin(), m_songs.end(), compareLength);

	}

	void SongCollection::cleanAlbum() {
		for_each(m_songs.begin(), m_songs.end(), [&](Song* s) {
			if (s->m_album == "[None]")
				s->m_album = "";
		});
	}

	bool SongCollection::inCollection(const std::string artist) const {
		return std::any_of(m_songs.begin(), m_songs.end(), [&](const Song* s) { return (artist == s->m_artist); });
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string artist) const {

		std::list<Song> songList;

		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song* s) {
			if (s->m_artist == artist)
				songList.push_back(*s);
		});
		return songList;

	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {

		int minute = theSong.m_length / 60;
		int second = theSong.m_length % 60;

		out << "| ";
		out << std::setw(20) << std::setfill(' ') << std::left << theSong.m_title;

		out << " | ";
		out << std::setw(15) << std::left << theSong.m_artist;

		out << " | ";
		out << std::setw(20) << std::left << theSong.m_album;

		out << " | ";
		out << std::setw(6) << std::right;

		if (theSong.m_year == 0)
			out << "";
		else
			out << theSong.m_year;

		out << " | ";
		out << std::right << minute << ":" << std::setw(2) << std::setfill('0') << second;

		out << " | ";
		out << std::fixed << std::setprecision(2) << theSong.m_price;

		out << " |";

		return out;
	}

	SongCollection::~SongCollection() {
		for (auto i = m_songs.begin(); i != m_songs.end(); i++)
			delete* i;
	}

	void SongCollection::trim(std::string& str) const {
		const std::string white_space = " \n\r\t\f\v";
		size_t start = str.find_first_not_of(white_space);
		str = (start == std::string::npos) ? "" : str.substr(start);

		size_t end = str.find_last_not_of(white_space);
		str = (end == std::string::npos) ? "" : str.substr(0, end + 1);
	}

}