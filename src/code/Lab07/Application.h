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
*	@author : 김민욱
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
	*	@brief	사용자에게 노래제목을 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByName();
	/**
	*	@brief	사용자에게 가수를 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByArtist();
	/**
	*	@brief	사용자에게 장르를 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/

	void SearchByGenre();
	/**
	*	@brief	사용자에게 앨범을 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void SearchByAlbum();
	/**
	*	@brief	사용자에게 노래 제목을 입력받아 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 노래 제목을 가지고 있는 MusicType이 m_MusicList에서 사라진다.
	*	@return	없다.
	*/
	void DeletemyMusic();

	/**
	*	@brief	사용자에게 노래 제목을 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 노래 제목을 가지고 있는 MusicType을 다시 입력받아 갱신한다.
	*	@return	없다.
	*/
	void ReplaceMusic();

	/**
	*	@brief	최근 재생목록(30개)를 보여준다.
	*	@pre	리스트가 초기화 되어있어야한다.
	*	@post	AddRecentlyMusicList의 정보로 m_GenreMusicList에서 찾아 모든 정보 출력
	*/
	int DisplayNewMusic();
	/**
	*	@brief	장르를 기준으로 음악 정보를 화면에 출력. 그리고 자세한 정보를 원한다면 출력
	*	@pre	리스트가 초기화 되어있어야한다.
	*	@post	장르를 기준으로 음악 정보가 화면에 출력된다.
	*/
	void DisplayMusicByGenre();
		
	/**
	*	@brief	장르가 일치하는 음악 정보를 찾아서 화면에 출력.(musiclist를 이용해서 비교)
	*	@pre	list should be initialized.
	*	@post	직접 입력받은 장르가 일치하는 음악 정보를 찾아서 화면에 출력한다.
	*/
	int AddMasterMusic();
	
	/**
	*	@brief	Display all my records(music list) in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllmyMusic();
	
	/**
	*	@brief	파라미터에서 가져온 데이터를 앨범리스트에 추가.
	*/
	void AddMusictoAlbumList(MusicType item);

	/**
	*	@brief	파라미터에서 가져온 데이터를 아트리스트리스트에 추가.
	*/
	void AddAlbumToArtistList(AlbumType& item);

	/**
	*	@brief	파라미터에서 가져온 데이터를 앨범리스트에 삭제.
	*/
	void DeleteMusicToGenreList(MusicType selectItem);

	/**
	*	@brief	파라미터에서 가져온 데이터를 앨범리스트에 삭제.
	*/
	void DeleteMusicToAlbumList(MusicType selectItem);
	
	/**
	*	@brief	파라미터에서 가져온 데이터를 뮤직리스트에 삭제.
	*/
	void DeleteMusicToSongList(MusicType item);

	/**
	*	@brief	파라미터에서 가져온 데이터를 장르리스트에 추가.
	*/
	void AddMusictoGenreList(MusicType item);

	/**
	*	@brief	파라미터에서 가져온 데이터를 송리스트에 추가.
	*/
	void AddMusictoSongList(MusicType item);

	/**
	*	@brief inArtist가 들어가있는 뮤직리스트의 자세한 정보를 출력
	*/
	void PrintNFindDetailArtist(Node <ArtistType>* root, string inArtist, ostream& out);

	/**
	*	@brief inGenre가 들어가있는 뮤직리스트의 자세한 정보를 출력
	*/
	void PrintNFindDetailGenre(Node<GenreType>* root, string inGenre, ostream& out);

	/**
	*	@brief inAlbum가 들어가있는 뮤직리스트의 자세한 정보를 출력
	*/
	void PrintNFindDetailAlbum(Node <AlbumType>* root, string inAlbum, ostream& out);

	/**
	*	@brief inSong이 들어가있는 뮤직리스트의 자세한 정보를 출력
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
	*	@brief	앨범을 기준으로 음악 정보를 화면에 출력.
	*	@pre	리스트가 초기화 되어있어야한다.
	*	@post	앨범을 기준으로 음악 정보가 화면에 출력된다.
	*/
	void DisplayMusicByAlbum();

	/**
	*	@brief	노래제목을 기준으로 음악 정보를 화면에 출력.
	*	@pre	리스트가 초기화 되어있어야한다.
	*	@post	노래제목을 기준으로 음악 정보가 화면에 출력된다.
	*/
	void DisplayMusicBySongName();

	/**
	*	@brief	가수들을 기준으로 음악 정보를 화면에 출력.
	*	@pre	리스트가 초기화 되어있어야한다.
	*	@post	가수들을 기준으로 음악 정보가 화면에 출력된다.
	*/
	void DisplayMusicByArtist();

	/**
	*	@brief	사용자에게 ID을 입력받아 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 노래 제목을 가지고 있는 MusicType이 m_MasterList에서 사라진다.
	*	@return	없다.
	*/
	void DeleteMasterMusic();

	/**
	*	@brief	param에서 가져온 item을 가수리스트에 삭제.
	*/
	void DeleteAlbumToArtistList(AlbumType& Item);

	/**
	*	@brief	음악을 Play 
	*/
	void PlayMusic();

	/**
	*	@brief	최근 재생한 음악들을 음악제목을 이용해서 보여주는 함수
	*/
	int DisplayPlayMusicList();

	/**
	*	@brief	최근 재생한 음악들을 재생한 시간을 측정해서 시간이 짧은 것부터 보여주는 함수
	*/
	int	DisplayDeleteList();


protected:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.

	baseclass m_MasterList;		// < 음악전체 리스트
	BinarySearchTree <MusicType> m_MusicList;	///< 나만의 음악전체 리스트
	BinarySearchTree<GenreType> m_GenreList;		// < 장르별 리스트
	BinarySearchTree<AlbumType> m_AlbumList; //<앨범별 리스트
	BinarySearchTree<ArtistType> m_ArtistList; // < 아티스트별 리스트
	BinarySearchTree<SongType> m_SongList; // < 노래리스트

	CircularQueueType<SongType> PlayRecentList; // < 최근 플레이한 리스트
	CircularQueueType<SimpleMusicType> AddRecentlyMusicList;	// < 최근 추가한 리스트

	SortedLinkedList<PlayTime> DeleteList; // < 삭제할만할 리스트
	SortedLinkedList <Login> m_MemberList;// < 회원리스트

	int m_Command;			///< current command number.
};