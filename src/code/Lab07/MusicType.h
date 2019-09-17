
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/**
*	@biref : item information class.
*	@author : 김민욱
*	@date: 2018.10.14
*/
class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{
		m_ID = "";
		m_SongName = "";
		m_Singer = "";
		m_Album = "";
		m_Genre = "";
		m_text = "";
		m_Birth = "";
		m_company = "";
		m_announce = "";
		m_runtime = "";
	}

	/**
	*	destructor.
	*/
	~MusicType() {}


	/**
	*	@brief	Get Singer.
	*	@pre	Singer is set.
	*	@post	none.
	*	@return	Singer.
	*/
	string GetSinger()
	{
		return m_Singer;
	}

	/**
	*	@brief	Get Birth.
	*	@pre	Birth is set.
	*	@post	none.
	*	@return	Birth.
	*/
	string GetBirth() {
		return m_Birth;
	}

	/**
	*	@brief	Get album
	*	@pre	album is set.
	*	@post	none.
	*	@return	album.
	*/
	string GetAlbum()
	{
		return m_Album;
	}


	/**
	*	@brief	Get 회사 이름
	*	@pre	회사 이름 is set.
	*	@post	none.
	*	@return	회사 이름을 리턴.
	*/
	string GetCompany()
	{
		return m_company;
	}

	/**
	*	@brief	Get 노래의 발매 날짜
	*	@pre	노래의 발매 날짜 is set.
	*	@post	none.
	*	@return	노래의 발매 날짜를 리턴.
	*/
	string GetAnnounce()
	{
		return m_announce;
	}

	/**
	*	@brief	Get 재생시간.
	*	@pre	재생시간 is set.
	*	@post	none.
	*	@return	 재생시간을 리턴.
	*/
	string GetRuntime()
	{
		return m_runtime;
	}

	/**
	*	@brief	Get Genre
	*	@pre	Genre is set.
	*	@post	none.
	*	@return	Genre.
	*/
	string GetGenre()
	{
		return m_Genre;
	}

	/**
	*	@brief	Get 노래 가사
	*	@pre	노래 가사  is set.
	*	@post	none.
	*	@return	노래 가사.
	*/
	string Gettext()
	{
		return m_text;
	}

	/**
	*	@brief	Set Singer.
	*	@pre	none.
	*	@post	Singer is set.
	*	@param	inSinger	Singer.
	*/
	void SetSinger(string inSinger)
	{
		m_Singer = inSinger;
	}

	/**
	*	@brief	Set Birth.
	*	@pre	none.
	*	@post	Birth is set.
	*	@param	inBirth	Birth.
	*/
	void SetBirth(string inBirth)
	{
		m_Birth = inBirth;
	}
	/**
	*	@brief	Set album.
	*	@pre	none.
	*	@post	album is set.
	*	@param	inAlbum	album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_Album = inAlbum;
	}

	/**
	*	@brief	Set Genre.
	*	@pre	none.
	*	@post	Genre is set.
	*	@param	inGenre	Genre.
	*/
	void SetGenre(string inGenre)
	{
		m_Genre = inGenre;
	}

	/**
	*	@brief	Set 노래 가사.
	*	@pre	none.
	*	@post	노래 가사 is set.
	*	@param	intext	text.
	*/
	void Settext(string intext) {
		m_text = intext;
	}

	/**
	*	@brief	Set Song record.
	*	@pre	none.
	*	@post	student Song is set.
	*	@param	inSN	Songname.
	*	@param	inSinger	Singer
	*	@param	inAlbum	Album.
	*	@param	inGenre	Genre.
	*	@param	intext	text(노래가사)
	*/
	void SetRecord(string inID, string inSN, string inSinger, string inAlbum, string inGenre, string inBirth, string intext)
	{
		SetID(inID);
		SetSongName(inSN);
		SetSinger(inSinger);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
		SetBirth(inBirth);
		Settext(intext);
		
	}


	/**
	*	@brief	Display Singer on screen.
	*	@pre	Singer is set.
	*	@post	Singer is on screen.
	*/
	void DisplaySingerOnScreen()
	{
		cout << "\t가수 : " << m_Singer << endl;
	};

	/**
	*	@brief	Display Album on screen.
	*	@pre	Album is set.
	*	@post	Album is on screen.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t앨범명 : " << m_Album << endl;
	};

	/**
	*	@brief	Display Birth on screen.
	*	@pre	Birth is set.
	*	@post	Birth is on screen.
	*/
	void DisplayBirthOnScreen() {
		cout << "\t가수생년월일 : " << m_Birth << endl;
	};
	/**
	*	@brief	Display Genre on screen.
	*	@pre	Genre is set.
	*	@post	Genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t장르 : " << m_Genre << endl;
	};

	/**
	*	@brief	Display text(노래가사) on screen.
	*	@pre	text(노래가사) is set.
	*	@post text(노래가사) is on screen.
	*/
	void DisplaytextOnScreen()
	{
		cout << "\t가사 : " << m_text << endl;
	};


	/**
	*	@brief	Set Singer from keyboard.
	*	@pre	none.
	*	@post	Singer is set.
	*/
	void SetSingerFromKB();

	/**
	*	@brief	Set Album from keyboard.
	*	@pre	none.
	*	@post	Album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set Genre from keyboard.
	*	@pre	none.
	*	@post	Genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set Genre from keyboard.
	*	@pre	none.
	*	@post	Genre is set.
	*/
	void SettextFromKB();
	
	/**
	*	@brief	Set Birth from keyboard.
	*/
	void SetBirthFromKB();

	/**
	*	@brief	Set song record from keyboard.
	*	@pre	none.
	*	@post	song record is set.
	*/
	void SetRecordFromKB();
	
	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator== (const MusicType &obj)
	{
		if (m_ID == obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator> (const MusicType &obj)
	{
		if (m_ID > obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator< (const MusicType &obj)
	{
		if (m_ID < obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator>= (const MusicType &obj)
	{
		if (m_ID >= obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator<= (const MusicType &obj)
	{
		if (m_ID <= obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	void operator= (const MusicType& obj)
	{
		m_ID = obj.m_ID;
		m_SongName = obj.m_SongName;
		m_Singer = obj.m_Singer;
		m_Genre = obj.m_Genre;
		m_Album = obj.m_Album;
		m_text = obj.m_text;
		m_Birth = obj.m_Birth;
		m_company = obj.m_company;
		m_runtime = obj.m_runtime;
		m_announce = obj.m_announce;
	}
	/**
	*	@brief	Get 노래 제목
	*	@pre	노래 제목  is set.
	*	@post	none.
	*	@return	노래 제목.
	*/
	string GetSongName()
	{
		return m_SongName;
	}
	/**
	*	@brief	Get ID
	*	@pre	ID is set.
	*	@post	none.
	*	@return ID.
	*/
	string GetID()
	{
		return m_ID;
	}
	/**
	*	@brief	Set 노래 제목.
	*	@pre	none.
	*	@post	노래 제목 is set.
	*/
	void SetSongName(string inSN)
	{
		m_SongName = inSN;
	}

	/**
	*	@brief	Set ID.
	*	@pre	none.
	*	@post	ID is set.
	*	@param	inID	ID.
	*/
	void SetID(string inID)
	{
		m_ID = inID;
	}


	/**
	*	@brief	Set PlayTime.
	*	@pre	none.
	*	@post	PlayTime is set.
	*	@param	inPlaytime	PlayTime.
	*/
	void SetPlayTime(int inPlaytime)
	{
		m_PlayTime = inPlaytime;
	}


	/**
	*	@brief	Display 노래 제목 on screen.
	*	@pre	노래 제목 is set.
	*	@post	노래 제목 is on screen.
	*/
	void DisplaySNOnScreen()
	{
		cout << "\t노래제목   : " << m_SongName << endl;
	}
	/**
	*	@brief	Display ID on screen.
	*	@pre	ID is set.
	*	@post	ID is on screen.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID		: " << m_ID << endl;
	}
	/**
	*	@brief	Set 노래제목 from keyboard.
	*	@pre	none.
	*	@post	노래제목 is set.
	*/
	void SetSNFromKB();
	/**
	*	@brief	Set ID from keyboard.
	*	@pre	none.
	*	@post	ID  is set.
	*/
	void SetIDFromKB();

	/**
	*	@brief	Set Company from keyboard.
	*	@pre	none.
	*	@post	Company  is set.
	*/
	void SetCompanyFromKB();

	/**
	*	@brief	Set Announce from keyboard.
	*	@pre	none.
	*	@post	Announce  is set.
	*/
	void SetAnnounceFromKB();

	/**
	*	@brief	Set Runtime from keyboard.
	*	@pre	none.
	*	@post	Runtime  is set.
	*/
	void SetRunTimeFromKB();

	/**
	*@brief operator overloading
	*/
	friend ostream& operator << (ostream& out, MusicType& item)
	{
		out << "\tID : " << item.GetID() << endl;
		out << "\t노래제목 : " << item.GetSongName() << endl;
		out << "\t가수이름 : " << item.GetSinger() << endl;
		out << "\t장르 : " << item.GetGenre() << endl;
		out << "\t앨범 명 : " << item.GetAlbum() << endl;	
		out << "\t가수의 생년월일 : " << item.GetBirth() << endl;
		out << "\t회사 이름 : " << item.GetCompany() << endl;
		out << "\t음악 발매 일 :" << item.GetAnnounce() << endl;
		out << "\t재생 시간 : " << item.GetRuntime() << endl;
		out << "\t가사 : " << item.Gettext() << endl << endl << endl;
		return out;
	}
protected:
	string m_ID; // < ID (primary Key)
	string m_SongName; // < 노래제목
	string m_Singer; // < singer
	string m_Genre; // < 장르
	string m_Album; //< album
	string m_text; // < 가사
	string m_Birth; //< 가수의 생년월일
	string m_company; // < 소속사(레코드사)
	string m_announce; // < 발표년 월일
	string m_runtime; // < 재생시간
	
	int m_PlayTime; // < 유저가 재생한 시간

};

#endif	// _MusicType_H
