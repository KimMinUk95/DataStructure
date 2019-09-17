
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "BinarySearchTree.h"
#include "AlbumType.h"

/**
*	@brief : Artist information class.
*	@author : ��ο�
*	@date: 2018.10.14
*/

using namespace std;
class ArtistType : public baseclass
{
private:
	string m_Artist; // < ������ �̸�
	string m_Birth; // < ������ ���� ����
	string m_Company; //< �Ҽӻ�
	BinarySearchTree <AlbumType> ArtistAlbumList; // < ������ �ٹ� ����Ʈ
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
	* @brief : ArtistAlbumList�� �ٹ�Ÿ���� ������ �߰������ִ� �Լ�.
	* @post : ArtistAlbumList�� ������ �߰��ȴ�.
	* @return : �߰��� �� �Ǿ��ٸ� 1�� ����, �߰��� �ߵ��� �ʾҴٸ� 0�� �����Ѵ�.
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
	* @brief : ���� �̸��� ������ ��������� �����ִ� �Լ�.
	*/
	void DisplayAll()
	{
		cout << "���� �̸� : " << m_Artist << endl;
		cout << "������ �Ҽӻ� : " << m_Company << endl;
		cout << "������ ���� ���� : " << m_Birth << endl;
	}

	/**
	* @brief : ������ ���� ������ Ű����� �޾��ִ� �Լ�.
	*/

	void setBirthbyKB()
	{
		cout << "������ ���� ���� : ";
		cin >> m_Birth;
	}

	/**
	* @brief : ArtistAlbumList�� �ٹ�Ÿ���� ������ ���Ž����ִ� �Լ�.
	* @post : ArtistAlbumList�� ������ ���ŵȴ�.
	* @return : ���Ű� �� �Ǿ��ٸ� 1�� ����, ���Ű� �ߵ��� �ʾҴٸ� 0�� ����, ���� ���������� ArtistAlbumList�� ���̰� 0�̸� 2�� ����
	*/
	void DeleteAlbum(AlbumType& data)
	{
		ArtistAlbumList.DeleteItem(data);
	}

	/**
	* @brief : ArtistAlbumList�� �ٹ�Ÿ���� ������ ���Ž����ִ� �Լ�.
	* @post : ArtistAlbumList�� ������ ���ŵȴ�.
	* @return : ������ �� �Ǿ��ٸ� 1�� ����, ������ �ߵ��� �ʾҴٸ� 0�� �����Ѵ�.
	*/
	void ReplaceAlbum(AlbumType& data)
	{
		ArtistAlbumList.Replace(data);
	}
	/**
	* @brief : ���� �̸��� �Ķ���ͷ� �������ִ� �Լ�.
	*/
	void SetArtist(string inArtist)
	{
		m_Artist = inArtist;
	}

	/**
	* @brief : ������ ��������� �Ķ���ͷ� �������ִ� �Լ�.
	*/
	void SetBirth(string inBirth)
	{
		m_Birth = inBirth;
	}
	/**
	*	@brief	Get ���� �̸�
	*	@pre	���� �̸� is set.
	*	@post	none.
	*	@return	���� �̸�.
	*/
	string GetArtist()
	{
		return m_Artist;
	}


	/**
	* @brief : ������ �Ҽӻ縦 �Ķ���ͷ� �������ִ� �Լ�.
	*/
	void SetCompany(string inCompany)
	{
		m_Company = inCompany;
	}
	/**
	*	@brief	Get �Ҽӻ� �̸�
	*	@pre	�Ҽӻ� �̸� is set.
	*	@post	none.
	*	@return	�Ҽӻ� �̸�.
	*/
	string GetCompany()
	{
		return m_Company;
	}


	/**
	*	@brief	Get ������ ���� ����
	*	@pre	������ ���� ���� is set.
	*	@post	none.
	*	@return	������ ���� ����.
	*/
	string GetBirth()
	{
		return m_Birth;
	}
	

	/**
	*	@brief ��Ƽ��Ʈ Ÿ������ �ٲ��ִ� �Լ�.
	*/
	void SetInfoA(string inArtist,string inCompany ,string inBirth)
	{
		m_Artist = inArtist;
		m_Company = inCompany;
		m_Birth = inBirth;
	}

	/**
	* @brief ������ �����ε�
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
	* @brief ������ �����ε�
	*/
	bool operator> (const ArtistType &obj)
	{
		if (m_Artist > obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator< (const ArtistType &obj)
	{
		if (m_Artist < obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator>= (const ArtistType &obj)
	{
		if (m_Artist >= obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator<= (const ArtistType &obj)
	{
		if (m_Artist <= obj.m_Artist) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	void operator=(ArtistType& obj)
	{
		m_Artist = obj.m_Artist;
		m_Birth = obj.m_Birth;
		m_Company = obj.m_Company;
		ArtistAlbumList = obj.ArtistAlbumList;
	}

	/**
	*	@brief	�ٹ��̸��� �߰��Ǿ��ִ� ��� ���
	*/
	friend ostream& operator << (ostream& out, ArtistType& obj)
	{
		out << "�Ҽӻ� : " << obj.GetCompany() << endl;
		out << "���� �̸� : " << obj.GetArtist() << endl;
		out << "������ ������� : " << obj.GetBirth() << endl;
		out << "������ ���� �ٹ� �� : " << obj.GetArtistAlbumListLength() << endl;
		
		obj.GetList()->PrintTree(out);
		return out;
	}
};