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
*	@author : ��ο�
*	@date: 2018.10.14
*/

class AlbumType : public baseclass
{
private:
	string m_Albumname; // < �ٹ���
	string m_Company; // < �Ҽӻ� �̸�
	string m_Artist; // < ���� �̸�
	string m_Birth; // < ���� ���� ����
	int m_AlbumsongNum; // < �ٹ����ϰ� ��

	
	BinarySearchTree<SimpleMusicType> AlbumMusic; // < ���ϰ�

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
	* @brief �ٹ�����Ʈ �ȿ� �ִ� �ٹ� ��������Ʈ�� �����͸� �߰����ش�. ���� �߰��Ҷ� ���� ���ϰ� ���� 1�� ������Ų��.
	* @return ���ϰ��� 1�̸� add�� �� ���̰�, 0�̸� add�� ���� ���� ���̴�.
	*/
	void AddAlbumMusic(SimpleMusicType& data)
	{
		AlbumMusic.Add(data);
		m_AlbumsongNum++;
	}

	/**
	* @brief �ٹ�����Ʈ �ȿ� �ִ� �ٹ� ��������Ʈ���� �����͸� �������ش�.
	* @return ���࿡ �ٹ���������Ʈ�� ������ �� �ٹ�����Ʈ�� ũ�Ⱑ 0�� �Ǿ�����ٸ� ���ϰ��� 2, 0�� �ƴ϶�� ���ϰ��� 1, ������ ���� �ʴ´ٸ� ���ϰ��� 0 ���� �����.
	*/
	void DeleteAlbumMusic(SimpleMusicType& data)
	{
		AlbumMusic.DeleteItem(data);
	}
	/**
	* @brief �ٹ����� �������ִ� �Լ�
	*/
	void SetAlbum(string inAlbum)
	{
		m_Albumname = inAlbum;
	}

	BinarySearchTree<SimpleMusicType>* GetList() { return &AlbumMusic; }

	/**
	* @brief ������ �̸��� �������ִ� �Լ�
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}
	/**
	* @brief �ٹ�����Ʈ �ȿ� �ִ� �ٹ� ��������Ʈ�� �����͸� �������ش�.
	* @return ���ϰ��� 1�̸� data�� ���ŵ� ���̰�, 0�̸� �����Ͱ� ���ŵ��� ���� ���̴�.
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
	*	@brief	Get �ٹ��� ���ϰ� ��
	*	@return	m_AlbumSongNumber.
	*/

	int GetAlbumSongNumber()
	{
		return AlbumMusic.GetLength(); // < �ٹ����ϰ� ��
	}

	/**
	*	@brief	�ٹ�Ÿ������ �������ִ� �Լ��̴�.
	*/

	void SetInfo(string inAlbum, string inArtist, string inBirth, string inCompany)
	{
		m_Albumname = inAlbum;
		m_Artist = inArtist;
		m_Birth = inBirth;
		m_Company = inCompany;

	}

	/**
	*	@brief	�ٹ�Ÿ�� Ŭ������ �ִ� �������� ������ִ� �Լ��̴�.
	*/
	void DisplayAll()
	{
		cout << "\t�ٹ��� : " << m_Albumname << endl;
		cout << "\t���� �̸� : " << m_Artist << endl;
		cout << "\t�ٹ� ���ϰ� �� : " << AlbumMusic.GetLength() << endl;
	}

	/**
	* destructor
	*/
	~AlbumType() {};
	/**
	* @brief ������ �����ε�
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
	* @brief ������ �����ε�
	*/
	bool operator> (const AlbumType &obj)
	{
		if (m_Albumname > obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief ������ �����ε�
	*/
	bool operator< (const AlbumType &obj)
	{
		if (m_Albumname < obj.m_Albumname) {
			return 1;
		}
		else return 0;

	}
	/**
	* @brief ������ �����ε�
	*/
	bool operator>= (const AlbumType &obj)
	{
		if (m_Albumname >= obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief ������ �����ε�
	*/
	bool operator<= (const AlbumType &obj)
	{
		if (m_Albumname <= obj.m_Albumname) {
			return 1;
		}
		else return 0;
	}
	/**
	* @brief ������ �����ε�
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
	*	@brief	�ٹ��̸��� �߰��Ǿ��ִ� ��� ���
	*/
	friend ostream& operator << (ostream& out, AlbumType& obj)
	{
		out << "\t�ٹ� �̸� : " << obj.GetAlbum() << endl;
		out << "\t�ٹ� ���ϰ�� : " << obj.GetAlbumSong() << endl;
		obj.Print(obj.GetList()->GetRoot(), out);
		return out;
	}

};