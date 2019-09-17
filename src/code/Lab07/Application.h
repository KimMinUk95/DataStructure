#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <time.h>
using namespace std;

#include "GenreType.h"
#include "CircularQueueType.h"
#include "MusicType.h"
#include "SimpleMusicType.h"
#include "BinarySearchTree.h"
#include "AlbumType.h"
#include "ArtistType.h"
#include "SongType.h"
#include "Login.h"
#include "PlayTime.h"
#include "SortedLinkedList.h"

#define FILENAMESIZE 1024
//#define SOUND_FILE_NAME ".\\res\\GoodDay.wav"

/**
*	@brief : application class for item management simply.
*	@author : ��ο�
*	@date : 2018.11.27
*/
class Application 
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	destructor.
	*/
	~Application() {}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into musiclist & gerelist
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddmyMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	����ڿ��� �뷡������ �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByName();
	/**
	*	@brief	����ڿ��� ������ �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByArtist();
	/**
	*	@brief	����ڿ��� �帣�� �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByGenre();
	/**
	*	@brief	����ڿ��� �ٹ��� �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void SearchByAlbum();
	/**
	*	@brief	����ڿ��� �뷡 ������ �Է¹޾� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� �뷡 ������ ������ �ִ� MusicType�� m_MusicList���� �������.
	*	@return	����.
	*/
	void DeletemyMusic();

	/**
	*	@brief	����ڿ��� �뷡 ������ �Է¹޾� SortedList�� Replace�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� �뷡 ������ ������ �ִ� MusicType�� �ٽ� �Է¹޾� �����Ѵ�.
	*	@return	����.
	*/
	void ReplaceMusic();

	/**
	*	@brief	�ֱ� ������(30��)�� �����ش�.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	AddRecentlyMusicList�� ������ m_GenreMusicList���� ã�� ��� ���� ���
	*/
	int DisplayNewMusic();
	/**
	*	@brief	�帣�� �������� ���� ������ ȭ�鿡 ���. �׸��� �ڼ��� ������ ���Ѵٸ� ���
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�帣�� �������� ���� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayMusicByGenre();
		
	/**
	*	@brief	�帣�� ��ġ�ϴ� ���� ������ ã�Ƽ� ȭ�鿡 ���.(musiclist�� �̿��ؼ� ��)
	*	@pre	list should be initialized.
	*	@post	���� �Է¹��� �帣�� ��ġ�ϴ� ���� ������ ã�Ƽ� ȭ�鿡 ����Ѵ�.
	*/
	int AddMasterMusic();
	
	/**
	*	@brief	Display all my records(music list) in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllmyMusic();
	
	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� �ٹ�����Ʈ�� �߰�.
	*/
	void AddMusictoAlbumList(MusicType item);

	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� ��Ʈ����Ʈ����Ʈ�� �߰�.
	*/
	void AddAlbumToArtistList(AlbumType& item);

	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� �ٹ�����Ʈ�� ����.
	*/
	void DeleteMusicToGenreList(MusicType selectItem);

	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� �ٹ�����Ʈ�� ����.
	*/
	void DeleteMusicToAlbumList(MusicType selectItem);
	
	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� ��������Ʈ�� ����.
	*/
	void DeleteMusicToSongList(MusicType item);

	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� �帣����Ʈ�� �߰�.
	*/
	void AddMusictoGenreList(MusicType item);

	/**
	*	@brief	�Ķ���Ϳ��� ������ �����͸� �۸���Ʈ�� �߰�.
	*/
	void AddMusictoSongList(MusicType item);

	/**
	*	@brief inArtist�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
	*/
	void PrintNFindDetailArtist(Node <ArtistType>* root, string inArtist, ostream& out);

	/**
	*	@brief inGenre�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
	*/
	void PrintNFindDetailGenre(Node<GenreType>* root, string inGenre, ostream& out);

	/**
	*	@brief inAlbum�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
	*/
	void PrintNFindDetailAlbum(Node <AlbumType>* root, string inAlbum, ostream& out);

	/**
	*	@brief inSong�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
	*/
	void PrintNFindDetailSongName(Node <SongType>* root, string inSong, ostream& out);
	
	/**
	*	@brief	Display Login command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	Login command.
	*/
	int GetLogin();
	
	/**
	*	@brief	Login Program driver.
	*	@pre	Login program is started.
	*	@post	Login program is finished.
	*/
	void Logina();
	
	/**
	*	@brief	Login Program driver.
	*	@pre	Login program is started.
	*	@post	Login program is finished.
	*/
	int LoginToApp();

	/**
	*	@brief	Display Master mode command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	Master mode command.
	*/
	int MakeID();
	
	/**
	*	@brief	Master mode Program driver.
	*	@pre	Master mode program is started.
	*	@post	Maaster mode program is finished.
	*/
	int GetMaster();

	/**
	*	@brief	Master mode Program driver.
	*	@pre	Master mode program is started.
	*	@post	Master mode program is finished.
	*/
	void MasterRun();

	/**
	*	@brief	�ٹ��� �������� ���� ������ ȭ�鿡 ���.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�ٹ��� �������� ���� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	�뷡������ �������� ���� ������ ȭ�鿡 ���.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�뷡������ �������� ���� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayMusicBySongName();

	/**
	*	@brief	�������� �������� ���� ������ ȭ�鿡 ���.
	*	@pre	����Ʈ�� �ʱ�ȭ �Ǿ��־���Ѵ�.
	*	@post	�������� �������� ���� ������ ȭ�鿡 ��µȴ�.
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	����ڿ��� ID�� �Է¹޾� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� �뷡 ������ ������ �ִ� MusicType�� m_MasterList���� �������.
	*	@return	����.
	*/
	void DeleteMasterMusic();

	/**
	*	@brief	param���� ������ item�� ��������Ʈ�� ����.
	*/
	void DeleteAlbumToArtistList(AlbumType& Item);

	/**
	*	@brief	������ Play 
	*/
	void PlayMusic();

	/**
	*	@brief	�ֱ� ����� ���ǵ��� ���������� �̿��ؼ� �����ִ� �Լ�
	*/
	int DisplayPlayMusicList();

	/**
	*	@brief	�ֱ� ����� ���ǵ��� ����� �ð��� �����ؼ� �ð��� ª�� �ͺ��� �����ִ� �Լ�
	*/
	int	DisplayDeleteList();


protected:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.

	baseclass m_MasterList;		// < ������ü ����Ʈ
	BinarySearchTree <MusicType> m_MusicList;	///< ������ ������ü ����Ʈ
	BinarySearchTree<GenreType> m_GenreList;		// < �帣�� ����Ʈ
	BinarySearchTree<AlbumType> m_AlbumList; //<�ٹ��� ����Ʈ
	BinarySearchTree<ArtistType> m_ArtistList; // < ��Ƽ��Ʈ�� ����Ʈ
	BinarySearchTree<SongType> m_SongList; // < �뷡����Ʈ

	CircularQueueType<SongType> PlayRecentList; // < �ֱ� �÷����� ����Ʈ
	CircularQueueType<SimpleMusicType> AddRecentlyMusicList;	// < �ֱ� �߰��� ����Ʈ

	SortedLinkedList<PlayTime> DeleteList; // < �����Ҹ��� ����Ʈ
	SortedLinkedList <Login> m_MemberList;// < ȸ������Ʈ

	int m_Command;			///< current command number.
};