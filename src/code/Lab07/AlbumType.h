#pragma once
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "SimpleMusicType.h"
#include "MusicType.h"
#include "baseclass.h"
using namespace std;
/**
*	@brief : Album information class.
*	@author : 김민욱
*	@date: 2018.10.14
*/

class AlbumType : public baseclass
{
private:
	string m_Albumname; // < 앨범명
	string m_Company; // < 소속사 이름
	string m_Artist; // < 가수 이름
	string m_Birth; // < 가수 생년 월일
	int m_AlbumsongNum; // < 앨범수록곡 수

	
	BinarySearchTree<SimpleMusicType> AlbumMusic; // < 수록곡

public:
	/**
	* constructor
	*/
	AlbumType()
	{
		m_Albumname = "";
		m_Company = "";
		m_Artist = "";
		m_Birth = "";
		m_AlbumsongNum = 0;
	};

	/**
	* @brief 앨범리스트 안에 있는 앨범 뮤지리스트에 데이터를 추가해준다. 또한 추가할때 마다 수록곡 수를 1씩 증가시킨다.
	* @return 리턴값이 1이면 add가 된 것이고, 0이면 add가 되지 않은 것이다.
	*/
	void AddAlbumMusic(SimpleMusicType& data)
	{
		AlbumMusic.Add(data);
		m_AlbumsongNum++;
	}

	/**
	* @brief 앨범리스트 안에 있는 앨범 뮤직리스트에서 데이터를 제거해준다.
	* @return 만약에 앨범뮤직리스트를 제거할 때 앨범리스트의 크기가 0이 되어버린다면 리턴값이 2, 0이 아니라면 리턴값이 1, 삭제가 되지 않는다면 리턴값을 0 으로 만든다.
	*/
	void DeleteAlbumMusic(SimpleMusicType& data)
	{
		AlbumMusic.DeleteItem(data);
	}
	/**
	* @brief 앨범명을 지정해주는 함수
	*/
	void SetAlbum(string inAlbum)
	{
		m_Albumname = inAlbum;
	}

	BinarySearchTree<SimpleMusicType>* GetList() { return &AlbumMusic; }

	/**
	* @brief 가수의 이름을 지정해주는 함수
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}
	/**
	* @brief 앨범리스트 안에 있는 앨범 뮤지리스트에 데이터를 갱신해준다.
	* @return 리턴값이 1이면 data가 갱신된 것이고, 0이면 데이터가 갱신되지 않은 것이다.
	*/
	void ReplaceAlbumMusic(SimpleMusicType& data)
	{
		AlbumMusic.Replace(data);
	}
	/**
	*	@brief	Set Album.
	*	@pre	none.
	*	@post	Album is set.
	*	@param	inAlbum	album.
	*/
	string GetAlbum()
	{
		return m_Albumname;
	}

	/**
	*	@brief	Set Birth.
	*	@pre	none.
	*	@post	Birth is set.
	*	@param	inBirth	birth.
	*/
	void SetBirth(string inBirth)
	{
		m_Birth = inBirth;
	}
	
	string GetBirth()
	{
		return m_Birth;
	}

	/**
	*	@brief	Set Company.
	*	@pre	none.
	*	@post	Company is set.
	*	@param	inCompany	company.
	*/
	void SetCompany(string inCompany)
	{
		m_Company = inCompany;
	}

	
	string GetCompany()
	{
		return m_Company;
	}

	/**
	*	@brief	Get Artist
	*	@pre	Artist is set.
	*	@post	none.
	*	@return	Artist.
	*/

	string GetArtist()
	{
		return m_Artist;
	}

	/**
	*	@brief	Get 앨범의 수록곡 수
	*	@return	m_AlbumSongNumber.
	*/

	int GetAlbumSongNumber()
	{
		return AlbumMusic.GetLength(); // < 앨범수록곡 수
	}

	/**
	*	@brief	앨범타입으로 지정해주는 함수이다.
	*/

	void SetInfo(string inAlbum, string inArtist, string inBirth, string inCompany)
	{
		m_Albumname = inAlbum;
		m_Artist = inArtist;
		m_Birth = inBirth;
		m_Company = inCompany;

	}

	/**
	*	@brief	앨범타입 클래스에 있는 변수들을 출력해주는 함수이다.
	*/
	void DisplayAll()
	{
		cout << "\t앨범명 : " << m_Albumname << endl;
		cout << "\t가수 이름 : " << m_Artist << endl;
		cout << "\t앨범 수록곡 수 : " << AlbumMusic.GetLength() << endl;
	}

	/**
	* destructor
	*/
	~AlbumType() {};
	/**
	* @brief 연산자 오버로딩
	*/
	bool operator== (const AlbumType &obj)
	{
		if (m_Albumname == obj.m_Albumname)
		{
			return 1;
		}
		else return 0;
	}
	/**
	* @brief 연산자 오버로딩
	*/
	bool operator> (const AlbumType &obj)
	{
		if (m_Albumname > obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief 연산자 오버로딩
	*/
	bool operator< (const AlbumType &obj)
	{
		if (m_Albumname < obj.m_Albumname) {
			return 1;
		}
		else return 0;

	}
	/**
	* @brief 연산자 오버로딩
	*/
	bool operator>= (const AlbumType &obj)
	{
		if (m_Albumname >= obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief 연산자 오버로딩
	*/
	bool operator<= (const AlbumType &obj)
	{
		if (m_Albumname <= obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief 연산자 오버로딩
	*/
	void operator=(AlbumType& obj)
	{
		m_Albumname = obj.m_Albumname;
		m_Artist = obj.m_Artist;
		AlbumMusic = obj.AlbumMusic;
		m_Birth = obj.m_Birth;
		m_Company = obj.m_Company;
		m_AlbumsongNum = obj.m_AlbumsongNum;
	}
	int GetAlbumSong() {
		return m_AlbumsongNum;
	}
	/**
	*	@brief	앨범이름과 추가되어있는 곡수 출력
	*/
	friend ostream& operator << (ostream& out, AlbumType& obj)
	{
		out << "\t앨범 이름 : " << obj.GetAlbum() << endl;
		out << "\t앨범 수록곡수 : " << obj.GetAlbumSong() << endl;
		obj.Print(obj.GetList()->GetRoot(), out);
		return out;
	}

};