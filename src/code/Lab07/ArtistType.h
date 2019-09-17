
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BinarySearchTree.h"
#include "AlbumType.h"

/**
*	@brief : Artist information class.
*	@author : 김민욱
*	@date: 2018.10.14
*/

using namespace std;
class ArtistType : public baseclass
{
private:
	string m_Artist; // < 가수의 이름
	string m_Birth; // < 가수의 생년 월일
	string m_Company; //< 소속사
	BinarySearchTree <AlbumType> ArtistAlbumList; // < 가수의 앨범 리스트
public:
	/**
	* @brief : constructor
	*/
	ArtistType()
	{
		m_Company = "";
		m_Artist = "";
		m_Birth = "";
	};

	/**
	* @brief : desstructor
	*/
	~ArtistType() {};

	BinarySearchTree<AlbumType>* GetList() { return &ArtistAlbumList; }

	/**
	* @brief : ArtistAlbumList에 앨범타입의 정보를 추가시켜주는 함수.
	* @post : ArtistAlbumList에 정보가 추가된다.
	* @return : 추가가 잘 되었다면 1을 리턴, 추가가 잘되지 않았다면 0을 리턴한다.
	*/

	void AddAlbum(AlbumType& data)
	{
		ArtistAlbumList.Add(data);
	}
	int GetArtistAlbumListLength() const
	{
		return ArtistAlbumList.GetLength();
	}

	/**
	* @brief : 가수 이름과 가수의 생년월일을 보여주는 함수.
	*/
	void DisplayAll()
	{
		cout << "가수 이름 : " << m_Artist << endl;
		cout << "가수의 소속사 : " << m_Company << endl;
		cout << "가수의 생년 월일 : " << m_Birth << endl;
	}

	/**
	* @brief : 가수의 생년 월일을 키보드로 받아주는 함수.
	*/

	void setBirthbyKB()
	{
		cout << "가수의 생년 월일 : ";
		cin >> m_Birth;
	}

	/**
	* @brief : ArtistAlbumList에 앨범타입의 정보를 제거시켜주는 함수.
	* @post : ArtistAlbumList에 정보가 제거된다.
	* @return : 제거가 잘 되었다면 1을 리턴, 제거가 잘되지 않았다면 0을 리턴, 또한 제거했을때 ArtistAlbumList의 길이가 0이면 2를 리턴
	*/
	void DeleteAlbum(AlbumType& data)
	{
		ArtistAlbumList.DeleteItem(data);
	}

	/**
	* @brief : ArtistAlbumList에 앨범타입의 정보를 갱신시켜주는 함수.
	* @post : ArtistAlbumList에 정보가 갱신된다.
	* @return : 갱신이 잘 되었다면 1을 리턴, 갱신이 잘되지 않았다면 0을 리턴한다.
	*/
	void ReplaceAlbum(AlbumType& data)
	{
		ArtistAlbumList.Replace(data);
	}
	/**
	* @brief : 가수 이름을 파라미터로 지정해주는 함수.
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	* @brief : 가수의 생년월일을 파라미터로 지정해주는 함수.
	*/
	void SetBirth(string inBirth)
	{
		m_Birth = inBirth;
	}
	/**
	*	@brief	Get 가수 이름
	*	@pre	가수 이름 is set.
	*	@post	none.
	*	@return	가수 이름.
	*/
	string GetArtist()
	{
		return m_Artist;
	}


	/**
	* @brief : 가수의 소속사를 파라미터로 지정해주는 함수.
	*/
	void SetCompany(string inCompany)
	{
		m_Company = inCompany;
	}
	/**
	*	@brief	Get 소속사 이름
	*	@pre	소속사 이름 is set.
	*	@post	none.
	*	@return	소속사 이름.
	*/
	string GetCompany()
	{
		return m_Company;
	}


	/**
	*	@brief	Get 가수의 생년 월일
	*	@pre	가수의 생년 월일 is set.
	*	@post	none.
	*	@return	가수의 생년 월일.
	*/
	string GetBirth()
	{
		return m_Birth;
	}
	

	/**
	*	@brief 아티스트 타입으로 바꿔주는 함수.
	*/
	void SetInfoA(string inArtist,string inCompany ,string inBirth)
	{
		m_Artist = inArtist;
		m_Company = inCompany;
		m_Birth = inBirth;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator== (const ArtistType &obj)
	{
		if (m_Artist == obj.m_Artist)
		{
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator> (const ArtistType &obj)
	{
		if (m_Artist > obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator< (const ArtistType &obj)
	{
		if (m_Artist < obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator>= (const ArtistType &obj)
	{
		if (m_Artist >= obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator<= (const ArtistType &obj)
	{
		if (m_Artist <= obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	void operator=(ArtistType& obj)
	{
		m_Artist = obj.m_Artist;
		m_Birth = obj.m_Birth;
		m_Company = obj.m_Company;
		ArtistAlbumList = obj.ArtistAlbumList;
	}

	/**
	*	@brief	앨범이름과 추가되어있는 곡수 출력
	*/
	friend ostream& operator << (ostream& out, ArtistType& obj)
	{
		out << "소속사 : " << obj.GetCompany() << endl;
		out << "가수 이름 : " << obj.GetArtist() << endl;
		out << "가수의 생년월일 : " << obj.GetBirth() << endl;
		out << "가수가 만든 앨범 수 : " << obj.GetArtistAlbumListLength() << endl;
		
		obj.GetList()->PrintTree(out);
		return out;
	}
};