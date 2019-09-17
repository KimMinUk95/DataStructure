#pragma once

#include <iostream>
#include <string>
using namespace std;

/**
*	@brief : 회원가입을 위한 class.
*	@author : 김민욱
*	@date: 2018.12.03
*/

class Login
{
private : 
	string name; // < 회원 이름
	string password; // < 회원 비밀번호
	string ID; // < 회원 ID
	string mail; //< 회원 이메일

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
	*	@brief	회원가입
	*/
	void MakeID(string inId, string inpassword, string inName, string inMail)
	{
		ID = inId;
		name = inName;
		password = inpassword;
		mail = inMail;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator== (const Login &obj)
	{
		if (ID == obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator> (const Login &obj)
	{
		if (ID > obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator< (const Login &obj)
	{
		if (ID < obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator>= (const Login &obj)
	{
		if (ID >= obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	bool operator<= (const Login &obj)
	{
		if (ID <= obj.ID) {
			return 1;
		}
		else return 0;
	}

	/**
	*	@brief	오버로딩 연산자
	*/
	void operator= (const Login& obj)
	{
		ID = obj.ID;
		name = obj.name;
		password = obj.password;
		mail = obj.mail;
	}



};