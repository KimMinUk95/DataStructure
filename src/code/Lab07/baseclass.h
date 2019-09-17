#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include "MusicType.h"
#include "BinarySearchTree.h"

using namespace std;
/**
*	@brief : base class.
*	@author : 김민욱
*	@date: 2018.11.16
*/
class baseclass {
protected:

	static BinarySearchTree <MusicType> mlist; 

public:
	/**
	*	@brief 현재 리스트의 갯수 return
	*/
	int GetLength()
	{
		return mlist.GetLength();
	}

	/**
	*	@brief 현재 리스트의 추가
	*/
	void Add(MusicType& data) 
	{
		mlist.Add(data);
	}

	/**
	*	@brief 현재 리스트를 get
	*/
	int Get(MusicType& data) 
	{
		return mlist.Get(data);
	}

	/**
	*	@brief 현재 리스트를 수정
	*/
	void Replace(MusicType& data) 
	{
		mlist.Replace(data);
	}

	/**
	*	@brief 현재 리스트의 삭제
	*/
	void DeleteItem(MusicType data) 
	{
		mlist.DeleteItem(data);
	}

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*/
	void PrintTree(ostream &out)const 
	{
		mlist.PrintTree(out);
	}
	/**
	*	@brief	mlist의 RetrieveItem을 return.
	*/
	void RetrieveItem(MusicType& item, bool &found) 
	{
		mlist.RetrieveItem(item, found);
	}

	/**
	*	@brief	자식클래스에서 마스터리스트의 정보를 가져오기 위한 함수
	*/
	void Print(Node <SimpleMusicType>* root, ostream& out)
	{
		if (root != NULL)
		{
			Print(root->left, out);

			MusicType data;
			data.SetID(root->data.GetID());

			mlist.Get(data);
			out << data;

			Print(root->right, out);
		}
	}
};