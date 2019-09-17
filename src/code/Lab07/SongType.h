#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "baseclass.h"
using namespace std;

/**
*	@brief : Song Information class
*	@author : ��ο�
*	@date: 2018.10.14
*/
class SongType : public baseclass
{
protected:
	string m_SongName; // < �뷡����
	string m_ID;
public:
	/*
	* constructor
	*/
	SongType() {
		m_ID = "";
		m_SongName = "";
		
	}
	/*
	* destrutor
	*/
	~SongType() {}

	/**
	*	@brief	Get �뷡 ����
	*	@pre	�뷡 ���� is set.
	*	@post	none.
	*	@return	�뷡 ������ ����.
	*/
	string GetSongName()
	{
		return m_SongName;
	}

	/**
	*	@brief	Get ID
	*/
	string GetID() 
	{ return m_ID; }

	/**
	*	@brief	Set ID
	*/
	void SetID(string inID) 
	{ m_ID = inID; }

	/**
	*	@brief	Set Song Name.
	*	@pre	none.
	*	@post	SongName is set.
	*	@param	inSongName	m_SongName.
	*/
	void SetSongName(string inSongName)
	{
		m_SongName = inSongName;
	}


	/**
	*	@brief	Display �뷡 ���� on screen.
	*	@pre	�뷡 ���� is set.
	*	@post	�뷡 ���� is on screen.
	*/
	void DisplaySongName()
	{
		cout << "\t�뷡 ���� : " << m_SongName << endl;
	}

	/**
	*	@brief	Set �뷡 ���� from keyboard.
	*	@pre	none.
	*	@post	�뷡 ���� is set.
	*/
	void SetSNFromKB()
	{
		cout << "\t�뷡 ����	: ";
		cin >> m_SongName;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator== (const SongType &obj)
	{
		if (m_SongName == obj.m_SongName)
		{
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator> (const SongType &obj)
	{
		if (m_SongName > obj.m_SongName)
		{
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator< (const SongType &obj)
	{
		if (m_SongName < obj.m_SongName)
		{
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator>= (const SongType &obj)
	{
		if (m_SongName >= obj.m_SongName)
		{
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	bool operator<= (const SongType &obj)
	{
		if (m_SongName <= obj.m_SongName) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief ������ �����ε�
	*/
	void operator= (const SongType& obj)
	{
		m_SongName = obj.m_SongName;
		m_ID = obj.m_ID;
	}
	/**
	* @brief ������ << �����ε�
	*/
	friend ostream& operator << (ostream& out, SongType& obj)
	{
			MusicType data;
			data.SetID(obj.GetID());
			mlist.Get(data);
			out << data;
			return out;
	}

	/**
	*	@brief	��Ÿ������ �������ִ� �Լ�.
	*/
	void setinfo(string inId, string inSN) {
		m_ID = inId;
		m_SongName = inSN;
	}
};
