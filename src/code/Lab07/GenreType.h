#ifndef _GENRETYPE_H
#define _GENRETYPE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "SimpleMusicType.h"
#include "BinarySearchTree.h"
#include "baseclass.h"
/**
*	@brief : Gnere information class.
*	@author : 김민욱
*	@date: 2018.10.14
*/

class GenreType : public baseclass
{
private:
	BinarySearchTree<SimpleMusicType> m_GenreMusicList; // < 장르뮤직리스트
	string m_Genre; //< 장르

public:
	/**
	*	constructor.
	*/
	GenreType()
	{
		m_Genre = "";
	}
	
	/**
	*	destructor.
	*/
	~GenreType() {}
	BinarySearchTree<SimpleMusicType>* GetList() { return &m_GenreMusicList; }
	/**
	* @brief 장르 이름을 설정하는 함수
	*/
	void setGenreName(string inGenre)
	{
		m_Genre = inGenre;
	}


	/**
	*	@brief	Get m_Genre.
	*	@return	m_Genre.
	*/
	string getGenreName()
	{
		return m_Genre;
	}


	/**
	*	@brief	장르타입으로 세팅해주는 함수.
	*
	*/
	void setInfo(std::string inGenre)
	{
		m_Genre = inGenre;
	}

	/**
	*	@brief		장르MusicList에 SimpleMusicType을 넣어줍니다
	*	@return	넣었으면 1 넣지 못했으면 0을 반환.
	*/
	void addGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.Add(item);
	}

	/**
	*	@brief		장르MusicList에 데이터를 제거하는 함수.
	*	@return	제거가 되는데 그 뮤직리스트의 크기가 0이면 2를 리턴, 크기가 0이 아니면 1을 리턴, 제거가 안되면 0을 리턴.
	*/
	void deleteGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.DeleteItem(item);
	}

	/**
	*	@brief		장르MusicList에 데이터를 바꿔주는 함수.
	*	@return	제대로 바꾸었으면 1 바꾸지 못했으면 0을 반환.
	*/
	void replaceGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.Replace(item);
	}
	/**
	*	@brief		장르뮤직리스트는 심플뮤직타입이다. 하지만 이 함수를 이용하면 곡의 자세한 정보를 볼 수 있다.
	*/
	void GenreType::DisplayMusicDetailInGenre()
	{
		
	}
	int GetMusicLength() const
	{
		return m_GenreMusicList.GetLength();
	}
	/**
	*	@brief		장르 아이디와 장르를 간단히 보여주는 함수,
	*/
	void GenreType::DisplayAll()
	{
		cout << "Genre : " << m_Genre << endl;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	void operator=(GenreType& obj)
	{
		m_Genre = obj.m_Genre;
		m_GenreMusicList = obj.m_GenreMusicList;
	}
	/**
	*	@brief	오버로딩 연산자
	*
	*/
	bool operator== (const GenreType &obj)
	{
		if (m_Genre == obj.m_Genre) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*
	*/
	bool operator> (const GenreType &obj)
	{
		if (m_Genre > obj.m_Genre) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*
	*/
	bool operator< (const GenreType &obj)
	{
		if (m_Genre < obj.m_Genre) {
			return 1;
		}
		else return 0;

	}
	/**
	*	@brief	오버로딩 연산자
	*
	*/
	bool operator>= (const GenreType &obj)
	{
		if (m_Genre >= obj.m_Genre) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*
	*/
	bool operator<= (const GenreType &obj)
	{
		if (m_Genre <= obj.m_Genre) {
			return 1;
		}
		else return 0;
	}
	
	/**
	*	@brief	오버로딩 << 연산자
	*/
	friend ostream& operator << (ostream& out, GenreType& obj)
	{
		out << "\tGENRE : " << obj.getGenreName() << endl;
		out << "\t곡수 : " << obj.GetMusicLength() << endl;
		obj.Print(obj.GetList()->GetRoot(), out);
		return out;
	}


};
#endif //_GENRETYPE_H
