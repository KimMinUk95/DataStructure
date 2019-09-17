#pragma once


#include <iostream>
#include <string>
using namespace std;
/**
*	@brief : ������ ��� ����ð� class.
*	@author : ��ο�
*	@date: 2018.12.03
*/
class PlayTime
{
private :
	double playtime; // < ������ ������ ��� �ð�
	string Songname; // < �����̸�
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
	*	@return	PlayTime�� ����.
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
	*	@brief	Get �뷡 ����
	*	@pre	�뷡 ���� is set.
	*	@post	none.
	*	@return	�뷡 ������ ����.
	*/
	string GetSongName()
	{
		return Songname;
	}
	/**
	*	@brief	�뷡����� ����ѽð��� �����ִ� �Լ�
	*/
	void Display()
	{
		cout << "\t�뷡 ����: " << Songname << endl;
		cout << "\t���� ����� �ð� : " << playtime << " ��"<<endl;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator== (const PlayTime &obj)
	{
		if (playtime == obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator> (const PlayTime &obj)
	{
		if (playtime > obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator< (const PlayTime &obj)
	{
		if (playtime < obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator>= (const PlayTime &obj)
	{
		if (playtime >= obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	bool operator<= (const PlayTime &obj)
	{
		if (playtime <= obj.playtime) {
			return 1;
		}
		else return 0;
	}
	/**
	*	@brief	�����ε� ������
	*/
	void operator= (const PlayTime& obj)
	{
		playtime = obj.playtime;
		Songname = obj.Songname;
	}


}
