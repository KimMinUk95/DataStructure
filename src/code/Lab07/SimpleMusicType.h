#pragma once
#include <iostream>
#include <string>
#include "MusicType.h"


using namespace std;
/**
*	 simple music information class.
*	@author : 김민욱
*	@date: 2018.10.14
*/
class SimpleMusicType
{
public:
	/**
	*	constructor.
	*/
	SimpleMusicType()
	{
		m_ID = "";
		m_SongName = "";
	}
	/**
	*	destructor.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief	Get Song name
	*	@pre	Song name is set
	*	@post	none.
	*	@return	Song name.
	*/
	string GetSongName()
	{
		return m_SongName;
	}
	/**
	*	@brief	Get Song ID
	*	@pre	Song ID is set
	*	@post	none.
	*	@return	Song ID.
	*/
	string GetID()
	{
		return m_ID;
	}

	/**
	*	@brief	Set song name.
	*	@pre	none.
	*	@post	Song name is set.
	*	@param	inSN	song name.
	*/
	void SetSongName(string inSN)
	{
		m_SongName = inSN;
	}

	/**
	*	@brief	Set song ID.
	*	@pre	none.
	*	@post	Song ID is set.
	*	@param	inID	song ID.
	*/
	void SetID(string inID)
	{
		m_ID = inID;
	}
	/**
	*	@brief	Display Song name on screen.
	*	@pre	Song name is set.
	*	@post	Song name is on screen.
	*/
	void DisplaySNOnScreen()
	{
		cout << "\tSongName   : " << m_SongName << endl;
	}
	/**
	*	@brief	Display Song ID on screen.
	*	@pre	Song ID is set.
	*	@post	Song ID is on screen.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID		: " << m_ID << endl;
	}
	/**
	*	@brief	Display Song name&ID on screen.
	*	@pre	Song name&ID are set.
	*	@post	Song name&ID are on screen.
	*/
	void DisplaySimpleOnScreen()
	{
		DisplayIDOnScreen();
		DisplaySNOnScreen();
	}
	/**
	*	@brief	Set song name from keyboard.
	*	@pre	none.
	*	@post	Song name is set.
	*/
	void SetSNFromKB();
	/**
	*	@brief	Set song ID from keyboard.
	*	@pre	none.
	*	@post	Song ID is set.
	*/
	void SetIDFromKB();
	/**
	*	@brief	Set song ID&song name from keyboard.
	*	@pre	none.
	*	@post	Song ID& song name are set.
	*/
	void SetSimpleFromKB();

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator== (const SimpleMusicType &obj)
	{
		if (m_ID == obj.m_ID) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator> (const SimpleMusicType &obj)
	{
		if (m_ID > obj.m_ID) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator< (const SimpleMusicType &obj)
	{
		if (m_ID < obj.m_ID) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator>= (const SimpleMusicType &obj)
	{
		if (m_ID >= obj.m_ID) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	bool operator<= (const SimpleMusicType &obj)
	{
		if (m_ID <= obj.m_ID) {
			return 1;
		}
		else return 0;
	}

	/**
	* @brief 연산자 오버로딩
	*/
	void operator=(const SimpleMusicType& obj) {
		m_ID = obj.m_ID;
		m_SongName = obj.m_SongName;
	}

	/**
	*@brief 심플뮤직타입으로 타입을 세팅해주는 함수.
	*/
	void setinfo(string inId, string inSN) {
		m_ID = inId;
		m_SongName = inSN;
	}

	
protected:
	string m_ID;  // < ID(primary Key)
	string m_SongName; // < song name
};

