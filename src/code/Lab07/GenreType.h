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
*	@author : ��ο�
*	@date: 2018.10.14
*/

class GenreType : public baseclass
{
private:
	BinarySearchTree<SimpleMusicType> m_GenreMusicList; // < �帣��������Ʈ
	string m_Genre; //< �帣

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
	* @brief �帣 �̸��� �����ϴ� �Լ�
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
	*	@brief	�帣Ÿ������ �������ִ� �Լ�.
	*
	*/
	void setInfo(std::string inGenre)
	{
		m_Genre = inGenre;
	}

	/**
	*	@brief		�帣MusicList�� SimpleMusicType�� �־��ݴϴ�
	*	@return	�־����� 1 ���� �������� 0�� ��ȯ.
	*/
	void addGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.Add(item);
	}

	/**
	*	@brief		�帣MusicList�� �����͸� �����ϴ� �Լ�.
	*	@return	���Ű� �Ǵµ� �� ��������Ʈ�� ũ�Ⱑ 0�̸� 2�� ����, ũ�Ⱑ 0�� �ƴϸ� 1�� ����, ���Ű� �ȵǸ� 0�� ����.
	*/
	void deleteGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.DeleteItem(item);
	}

	/**
	*	@brief		�帣MusicList�� �����͸� �ٲ��ִ� �Լ�.
	*	@return	����� �ٲپ����� 1 �ٲ��� �������� 0�� ��ȯ.
	*/
	void replaceGenre(SimpleMusicType& item)
	{
		m_GenreMusicList.Replace(item);
	}
	/**
	*	@brief		�帣��������Ʈ�� ���ù���Ÿ���̴�. ������ �� �Լ��� �̿��ϸ� ���� �ڼ��� ������ �� �� �ִ�.
	*/
	void GenreType::DisplayMusicDetailInGenre()
	{
		
	}
	int GetMusicLength() const
	{
		return m_GenreMusicList.GetLength();
	}
	/**
	*	@brief		�帣 ���̵�� �帣�� ������ �����ִ� �Լ�,
	*/
	void GenreType::DisplayAll()
	{
		cout << "Genre : " << m_Genre << endl;
	}
	/**
	*	@brief	�����ε� ������
	*/
	void operator=(GenreType& obj)
	{
		m_Genre = obj.m_Genre;
		m_GenreMusicList = obj.m_GenreMusicList;
	}
	/**
	*	@brief	�����ε� ������
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
	*	@brief	�����ε� ������
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
	*	@brief	�����ε� ������
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
	*	@brief	�����ε� ������
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
	*	@brief	�����ε� ������
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
	*	@brief	�����ε� << ������
	*/
	friend ostream& operator << (ostream& out, GenreType& obj)
	{
		out << "\tGENRE : " << obj.getGenreName() << endl;
		out << "\t��� : " << obj.GetMusicLength() << endl;
		obj.Print(obj.GetList()->GetRoot(), out);
		return out;
	}


};
#endif //_GENRETYPE_H
