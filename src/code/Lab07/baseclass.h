#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include "MusicType.h"
#include "BinarySearchTree.h"

using namespace std;
/**
*	@brief : base class.
*	@author : ��ο�
*	@date: 2018.11.16
*/
class baseclass {
protected:

	static BinarySearchTree <MusicType> mlist; 

public:
	/**
	*	@brief ���� ����Ʈ�� ���� return
	*/
	int GetLength()
	{
		return mlist.GetLength();
	}

	/**
	*	@brief ���� ����Ʈ�� �߰�
	*/
	void Add(MusicType& data) 
	{
		mlist.Add(data);
	}

	/**
	*	@brief ���� ����Ʈ�� get
	*/
	int Get(MusicType& data) 
	{
		return mlist.Get(data);
	}

	/**
	*	@brief ���� ����Ʈ�� ����
	*/
	void Replace(MusicType& data) 
	{
		mlist.Replace(data);
	}

	/**
	*	@brief ���� ����Ʈ�� ����
	*/
	void DeleteItem(MusicType data) 
	{
		mlist.DeleteItem(data);
	}

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*/
	void PrintTree(ostream &out)const 
	{
		mlist.PrintTree(out);
	}
	/**
	*	@brief	mlist�� RetrieveItem�� return.
	*/
	void RetrieveItem(MusicType& item, bool &found) 
	{
		mlist.RetrieveItem(item, found);
	}

	/**
	*	@brief	�ڽ�Ŭ�������� �����͸���Ʈ�� ������ �������� ���� �Լ�
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