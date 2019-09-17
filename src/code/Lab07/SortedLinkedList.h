#pragma once
#include <iostream>
#include <fstream>
#include <string>


/**
*	@brief : Structure for NodeType to use in Linked structure.
*	@author : 김민욱
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
*	@author : 김민욱
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
	*@brief 오버로딩 연산자
	*/
	void operator=(SortedLinkedList<T>& obj)
	{

		// 기존 노드 초기화
		MakeEmpty();
		// obj 리스트가 존재할 경우
		if (obj.GetLength())
		{
			// obj curPtr 초기화
			obj.ResetList();

			T item;
			//노드 복사
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
	*@brief item의 주솟값을 가져와주는 함수
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
	*	@brief	item과 일치하는 id를 가진 레코드를 제거.
	*	@pre	해당하는 id를 가진 레코드가 있어야함
	*	@post	해당 레코드가 제거됨.
	*/
	int Delete(T& item);
	/**
	*	@brief	item과 일치하는 id를 가진 레코드를 갱신.
	*	@pre	해당하는 id를 가진 레코드가 있어야함
	*	@post	해당 레코드가 item의 내용으로 갱신됨.
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
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
		m_nLength++;
		return 1;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		if (Get(item) == 1) {
			return 0;
		}
		else {
			// 가장 마지막 node 로 이동 후 삽입
			while (1)
			{
				// 이전 노드를 가리키는 포인터 갱신
				pre = m_pCurPointer;

				// iteration 을 이용해 node 포인터 갱신.
				GetNextItem(dummy);

				if (m_pCurPointer->data > node->data)
				{
					if (pre == NULL)
					{
						node->next = m_pCurPointer;
						m_pList = node;
						break;
					}   //넣을 자리 앞 원소가 존재하지 않을 때 첫번째 원소로 삽입.
					node->next = m_pCurPointer;
					pre->next = node;
					break;
				}   //지금 가리키는 원소의 data값이 node의 data값보다 클 경우 pre 뒷자리에 삽입.

					// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
				if (m_pCurPointer->next == NULL)
				{
					// 마지막 node 와 새로운 node 연결
					m_pCurPointer->next = node;
					break;
				}
			}
		}

	}

	m_nLength++;

	return 1;
}
// item의 주솟값을 가져와주는 함수.
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
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
int SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;
	if (m_pCurPointer == NULL)
	{
		return -1;
	}
	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
	return 0;
}

// item과 일치하는 id를 가진 레코드를 제거.
template <typename T>
int SortedLinkedList<T>::Delete(T& item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(item) == 0)	//해당하는 값이 없으면, 0보내고 종료
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id값이 일치
		{
			if (pre == NULL) //삭제해야할 노드가 맨처음일때
			{
				toDel = m_pList;	//잠시 옮겨두고 삭제
				m_pList = m_pList->next;	//맨처음을 두번째로바꿈
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//전 포인터와 다음포인터를 연결
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//맨마지막, 루프를 다돌았을때
			break;


	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

//item과 일치하는 id를 가진 레코드를 갱신.
template <typename T>
int SortedLinkedList<T>::Replace(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;   //변수 선언

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);   //변수 초기화

	while (moreToSearch && !found)   //리스트의 끝이 아니면서 아직 찾지 않았으면 반복한다.
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}   //일치하는 항목을 찾았을 때 found의 값을 변경해주고 리스트의 항목에 item을 복사해준다.
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}   //찾지 못했을 때 다음 항목으로 location을 옮기고 그 값이 NULL이면 리스트의 끝이므로 moreToSearch의 값을 변경해준다.
	}

	if (found)
		return 1;
	else
		return 0;   //수정에 성공하면 1, 그렇지 못하면 0을 리턴한다.
}
