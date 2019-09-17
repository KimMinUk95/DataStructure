#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "baseclass.h"
using namespace std;

/**
*	@brief : Song Information class
*	@author : 김민욱
*	@date: 2018.10.14
*/
class SongType : public baseclass
{
protected:
	string m_SongName; // < 노래제목
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
	*	@brief	Get 노래 제목
	*	@pre	노래 제목 is set.
	*	@post	none.
	*	@return	노래 제목을 리턴.
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
	*	@brief	Display 노래 제목 on screen.
	*	@pre	노래 제목 is set.
	*	@post	노래 제목 is on screen.
	*/
	void DisplaySongName()
	{
		cout << "\t노래 제목 : " << m_SongName << endl;
	}

	/**
	*	@brief	Set 노래 제목 from keyboard.
	*	@pre	none.
	*	@post	노래 제목 is set.
	*/
	void SetSNFromKB()
	{
		cout << "\t노래 제목	: ";
		cin >> m_SongName;
	}

	/**
	* @brief 연산자 오버로딩
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
	* @brief 연산자 오버로딩
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
	* @brief 연산자 오버로딩
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
	* @brief 연산자 오버로딩
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
	* @brief 연산자 오버로딩
	*/
	bool operator<= (const SongType &obj)
	{
		if (m_SongName <= obj.m_SongName) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	void operator= (const SongType& obj)
	{
		m_SongName = obj.m_SongName;
		m_ID = obj.m_ID;
	}
	/**
	* @brief 연산자 << 오버로딩
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
	*	@brief	송타입으로 세팅해주는 함수.
	*/
	void setinfo(string inId, string inSN) {
		m_ID = inId;
		m_SongName = inSN;
	}
};
