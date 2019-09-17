#pragma once


#include <iostream>
#include <string>
using namespace std;
/**
*	@brief : 유저가 듣는 재생시간 class.
*	@author : 김민욱
*	@date: 2018.12.03
*/
class PlayTime
{
private :
	double playtime; // < 유저가 음악을 듣는 시간
	string Songname; // < 음악이름
public:
	/**
	*	@brief	Set PlayTime
	*	@pre	none.
	*	@post	Playtime is set.
	*	@param	inPlaytime	playtime.
	*/
	void SetPlayTime(int inplaytime)
	{
		playtime = inplaytime;
	}
	/**
	*	@brief	Get PlayTime
	*	@pre	Playtime is set.
	*	@post	none.
	*	@return	PlayTime을 리턴.
	*/
	double GetPlayTime()
	{
		return playtime;
	}

	/**
	*	@brief	Set Song Name.
	*	@pre	none.
	*	@post	SongName is set.
	*	@param	inSongName	SongName.
	*/
	void SetSongName(string inSongName)
	{
		Songname = inSongName;
	}
	/**
	*	@brief	Get 노래 제목
	*	@pre	노래 제목 is set.
	*	@post	none.
	*	@return	노래 제목을 리턴.
	*/
	string GetSongName()
	{
		return Songname;
	}
	/**
	*	@brief	노래제목과 재생한시간을 보여주는 함수
	*/
	void Display()
	{
		cout << "\t노래 제목: " << Songname << endl;
		cout << "\t내가 재생한 시간 : " << playtime << " 초"<<endl;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator== (const PlayTime &obj)
	{
		if (playtime == obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator> (const PlayTime &obj)
	{
		if (playtime > obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator< (const PlayTime &obj)
	{
		if (playtime < obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator>= (const PlayTime &obj)
	{
		if (playtime >= obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator<= (const PlayTime &obj)
	{
		if (playtime <= obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	오버로딩 연산자
	*/
	void operator= (const PlayTime& obj)
	{
		playtime = obj.playtime;
		Songname = obj.Songname;
	}


}
