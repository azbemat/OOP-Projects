// Name:	Anas Zakariyah Bemat
// Email:	azbemat@myseneca.ca
// ID:		165239187
// Date:	2021-03-21

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SONGCOLLECTION_H__
#define SDDS_SONGCOLLECTION_H__

#include <string>
#include <vector>
#include <list>

namespace sdds {

	struct Song {
		std::string m_artist = "";
		std::string m_title = "";
		std::string m_album = "";
		double m_price = 0;
		size_t m_year = 0;
		size_t m_length = 0;
	};

	class SongCollection {

		std::vector<Song*> m_songs;

	public:
		SongCollection(const std::string);
		void display(std::ostream& out) const;
		void sort(const std::string);
		void cleanAlbum();
		bool inCollection(const std::string) const;
		std::list<Song> getSongsForArtist(const std::string) const;
		~SongCollection();

		void trim(std::string& str) const;
		
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif // !SDDS_SONGCOLLECTION_H__
