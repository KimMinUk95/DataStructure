#pragma once
#include <iostream>
#include <fstream>
#include <string>


/**
*	@brief : Structure for NodeType to use in Linked structure.
*	@author : ��ο�
*	@date: 2018.10.14
*/

; using namespace std;
template <typename T>
struct NodeType
{

	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
	void operator=(const NodeType<T>& obj)
	{
		data = obj.data;

	}
};


/**
*	Simple unsorted list class for managing items.
*	@author : ��ο�
*	@date: 2018.10.14
*/
template <typename T>
class SortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SortedLinkedList();

	/**
	*	destructor.
	*/
	~SortedLinkedList();
	/**
	*@brief �����ε� ������
	*/
	void operator=(SortedLinkedList<T>& obj)
	{

		// ���� ��� �ʱ�ȭ
		MakeEmpty();
		// obj ����Ʈ�� ������ ���
		if (obj.GetLength())
		{
			// obj curPtr �ʱ�ȭ
			obj.ResetList();

			T item;
			//��� ����
			while (obj.GetNextItem(item) == 0)
				Add(item);
		}
	}
	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();
	/**
	*@brief item�� �ּڰ��� �������ִ� �Լ�
	*/
	T* GetPoint(T& item);
	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T& item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	int GetNextItem(T& item);
	/**
	*	@brief	item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 ���ŵ�.
	*/
	int Delete(T& item);
	/**
	*	@brief	item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 item�� �������� ���ŵ�.
	*/
	int Replace(T& item);
private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int SortedLinkedList<T>::Add(T& item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
		m_nLength++;
		return 1;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		if (Get(item) == 1) {
			return 0;
		}
		else {
			// ���� ������ node �� �̵� �� ����
			while (1)
			{
				// ���� ��带 ����Ű�� ������ ����
				pre = m_pCurPointer;

				// iteration �� �̿��� node ������ ����.
				GetNextItem(dummy);

				if (m_pCurPointer->data > node->data)
				{
					if (pre == NULL)
					{
						node->next = m_pCurPointer;
						m_pList = node;
						break;
					}   //���� �ڸ� �� ���Ұ� �������� ���� �� ù��° ���ҷ� ����.
					node->next = m_pCurPointer;
					pre->next = node;
					break;
				}   //���� ����Ű�� ������ data���� node�� data������ Ŭ ��� pre ���ڸ��� ����.

					// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
				if (m_pCurPointer->next == NULL)
				{
					// ������ node �� ���ο� node ����
					m_pCurPointer->next = node;
					break;
				}
			}
		}

	}

	m_nLength++;

	return 1;
}
// item�� �ּڰ��� �������ִ� �Լ�.
template<typename T>
T* SortedLinkedList<T>::GetPoint(T& item)
{
	if (Get(item)) {
		return &item;
	}
	return nullptr;
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
int SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;
	if (m_pCurPointer == NULL)
	{
		return -1;
	}
	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
	return 0;
}

// item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
template <typename T>
int SortedLinkedList<T>::Delete(T& item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(item) == 0)	//�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id���� ��ġ
		{
			if (pre == NULL) //�����ؾ��� ��尡 ��ó���϶�
			{
				toDel = m_pList;	//��� �Űܵΰ� ����
				m_pList = m_pList->next;	//��ó���� �ι�°�ιٲ�
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//�� �����Ϳ� ���������͸� ����
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����, ������ �ٵ�������
			break;


	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

//item�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
template <typename T>
int SortedLinkedList<T>::Replace(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;   //���� ����

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);   //���� �ʱ�ȭ

	while (moreToSearch && !found)   //����Ʈ�� ���� �ƴϸ鼭 ���� ã�� �ʾ����� �ݺ��Ѵ�.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}   //��ġ�ϴ� �׸��� ã���� �� found�� ���� �������ְ� ����Ʈ�� �׸� item�� �������ش�.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}   //ã�� ������ �� ���� �׸����� location�� �ű�� �� ���� NULL�̸� ����Ʈ�� ���̹Ƿ� moreToSearch�� ���� �������ش�.
	}

	if (found)
		return 1;
	else
		return 0;   //������ �����ϸ� 1, �׷��� ���ϸ� 0�� �����Ѵ�.
}
