#pragma once

#include <iostream>
#include <string>
using namespace std;

/**
*	@brief : ȸ�������� ���� class.
*	@author : ��ο�
*	@date: 2018.12.03
*/

class Login
{
private : 
	string name; // < ȸ�� �̸�
	string password; // < ȸ�� ��й�ȣ
	string ID; // < ȸ�� ID
	string mail; //< ȸ�� �̸���

public:
	/**
	*	constructor.
	*/
	Login() 
	{
		name = "";
		password = "";
		ID = "";
		mail = "";
	};

	/**
	*	destructor.
	*/
	~Login() {};
	
	/**
	*	@brief	Get ID.
	*	@pre	ID is set.
	*	@post	none.
	*	@return	ID.
	*/
	string GetID()
	{
		return ID;
	}

	/**
	*	@brief	Set ID.
	*	@pre	none.
	*	@post	ID is set.
	*	@param	inID	ID.
	*/
	void SetID(string inID)
	{
		ID = inID;
	}

	/**
	*	@brief	Set Password.
	*	@pre	none.
	*	@post	Password is set.
	*	@param	inPW	password.
	*/
	void SetPassWord(string inPW) 
	{
		password = inPW;
	}

	/**
	*	@brief	Get PassWord.
	*	@pre	PassWord is set.
	*	@post	none.
	*	@return	Password.
	*/
	string GetPassWord()
	{
		return password;
	}

	/**
	*	@brief	Get Name.
	*	@pre	Name is set.
	*	@post	none.
	*	@return	Name.
	*/
	string GetName()
	{
		return name;
	}

	/**
	*	@brief	Get mail.
	*	@pre	mail is set.
	*	@post	none.
	*	@return	mail.
	*/
	string GetMail()
	{
		return mail;
	}

	/**
	*	@brief	ȸ������
	*/
	void MakeID(string inId, string inpassword, string inName, string inMail)
	{
		ID = inId;
		name = inName;
		password = inpassword;
		mail = inMail;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator== (const Login &obj)
	{
		if (ID == obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator> (const Login &obj)
	{
		if (ID > obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator< (const Login &obj)
	{
		if (ID < obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator>= (const Login &obj)
	{
		if (ID >= obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	�����ε� ������
	*/
	bool operator<= (const Login &obj)
	{
		if (ID <= obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	�����ε� ������
	*/
	void operator= (const Login& obj)
	{
		ID = obj.ID;
		name = obj.name;
		password = obj.password;
		mail = obj.mail;
	}



};