
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


/**
*	@biref : item information class.
*	@author : ��ο�
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
	*	@brief	Get ȸ�� �̸�
	*	@pre	ȸ�� �̸� is set.
	*	@post	none.
	*	@return	ȸ�� �̸��� ����.
	*/
	string GetCompany()
	{
		return m_company;
	}

	/**
	*	@brief	Get �뷡�� �߸� ��¥
	*	@pre	�뷡�� �߸� ��¥ is set.
	*	@post	none.
	*	@return	�뷡�� �߸� ��¥�� ����.
	*/
	string GetAnnounce()
	{
		return m_announce;
	}

	/**
	*	@brief	Get ����ð�.
	*	@pre	����ð� is set.
	*	@post	none.
	*	@return	 ����ð��� ����.
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
	*	@brief	Get �뷡 ����
	*	@pre	�뷡 ����  is set.
	*	@post	none.
	*	@return	�뷡 ����.
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
	*	@brief	Set �뷡 ����.
	*	@pre	none.
	*	@post	�뷡 ���� is set.
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
	*	@param	intext	text(�뷡����)
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
		cout << "\t���� : " << m_Singer << endl;
	};

	/**
	*	@brief	Display Album on screen.
	*	@pre	Album is set.
	*	@post	Album is on screen.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ��� : " << m_Album << endl;
	};

	/**
	*	@brief	Display Birth on screen.
	*	@pre	Birth is set.
	*	@post	Birth is on screen.
	*/
	void DisplayBirthOnScreen() {
		cout << "\t����������� : " << m_Birth << endl;
	};
	/**
	*	@brief	Display Genre on screen.
	*	@pre	Genre is set.
	*	@post	Genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t�帣 : " << m_Genre << endl;
	};

	/**
	*	@brief	Display text(�뷡����) on screen.
	*	@pre	text(�뷡����) is set.
	*	@post text(�뷡����) is on screen.
	*/
	void DisplaytextOnScreen()
	{
		cout << "\t���� : " << m_text << endl;
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
	*	@brief	�����ε� ������
	*/
	bool operator== (const MusicType &obj)
	{
		if (m_ID == obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator> (const MusicType &obj)
	{
		if (m_ID > obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator< (const MusicType &obj)
	{
		if (m_ID < obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator>= (const MusicType &obj)
	{
		if (m_ID >= obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator<= (const MusicType &obj)
	{
		if (m_ID <= obj.m_ID) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
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
	*	@brief	Get �뷡 ����
	*	@pre	�뷡 ����  is set.
	*	@post	none.
	*	@return	�뷡 ����.
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
	*	@brief	Set �뷡 ����.
	*	@pre	none.
	*	@post	�뷡 ���� is set.
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
	*	@brief	Display �뷡 ���� on screen.
	*	@pre	�뷡 ���� is set.
	*	@post	�뷡 ���� is on screen.
	*/
	void DisplaySNOnScreen()
	{
		cout << "\t�뷡����   : " << m_SongName << endl;
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
	*	@brief	Set �뷡���� from keyboard.
	*	@pre	none.
	*	@post	�뷡���� is set.
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
		out << "\t�뷡���� : " << item.GetSongName() << endl;
		out << "\t�����̸� : " << item.GetSinger() << endl;
		out << "\t�帣 : " << item.GetGenre() << endl;
		out << "\t�ٹ� �� : " << item.GetAlbum() << endl;	
		out << "\t������ ������� : " << item.GetBirth() << endl;
		out << "\tȸ�� �̸� : " << item.GetCompany() << endl;
		out << "\t���� �߸� �� :" << item.GetAnnounce() << endl;
		out << "\t��� �ð� : " << item.GetRuntime() << endl;
		out << "\t���� : " << item.Gettext() << endl << endl << endl;
		return out;
	}
protected:
	string m_ID; // < ID (primary Key)
	string m_SongName; // < �뷡����
	string m_Singer; // < singer
	string m_Genre; // < �帣
	string m_Album; //< album
	string m_text; // < ����
	string m_Birth; //< ������ �������
	string m_company; // < �Ҽӻ�(���ڵ��)
	string m_announce; // < ��ǥ�� ����
	string m_runtime; // < ����ð�
	
	int m_PlayTime; // < ������ ����� �ð�

};

#endif	// _MusicType_H
