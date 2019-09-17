#include "Application.h"


void Application :: PlayMusic()
{
	PlayTime data;
	SongType songname;
	string filename;
	string a = ".\\res\\";
	string b = ".wav";
	songname.SetSNFromKB();
	filename = songname.GetSongName();
	filename = a + filename + b;
	PlayRecentList.EnQueue(songname);
	LPWSTR ws = new wchar_t[filename.size() + 1];
	copy(filename.begin(), filename.end(), ws);
	ws[filename.size()] = 0;
	
	cout << "아무 키나 입력하시면 소리 재생이 멈춥니다.\n";
	time_t start, end;
	double playtime;
	PlaySound(ws, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	start = time(NULL);// 시간 측정 시작
	while (!_kbhit());
	PlaySound(NULL, 0, 0);
	end = time(NULL);//시간 측정 종료
	data.SetSongName(songname.GetSongName());
	data.SetPlayTime((double)(end - start));

	DeleteList.Add(data);
}


int	Application::DisplayDeleteList()
{
	PlayTime data;

	string SongName;

	cout << "\n\tMusic list" << endl;

	DeleteList.ResetList();
	int length = DeleteList.GetLength();
	int curIndex = DeleteList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.Display();
		curIndex = DeleteList.GetNextItem(data);
	}

	return 1;
}

void Application::Logina() 
{
	while (1)
	{
		m_Command = GetLogin();
		switch (m_Command)
		{
		case 1:
			int num;
			num = LoginToApp();
			if (num== 2)
			{
				MasterRun();
			}
			else if (num== 1) 
			{
				Run();
			}
			else if(num==0)
			{
				continue;
			}
			break;
		case 2:
			MakeID();
			break;
		default:
			cout << "잘못된 입력입니다" << endl;
		}
	}
}
int Application::LoginToApp()
{
	string ID, Password;
	cout << "\tID : ";
	cin >> ID;
	cout << "\tPassword : ";
	cin >> Password;
	Login member;
	member.SetID(ID);
	member.SetPassWord(Password);
	if (member.GetID() == "MASTER" && member.GetPassWord() == "1234") 
	{
		return 2;
	}
	
	Login data;
	m_MemberList.ResetList();
	while (m_MemberList.GetNextItem(data) != -1)
	{
		if (data.GetID() == ID && data.GetPassWord() == Password)
		{
			return 1;
		}
		else
		{
			cout << "\t잘못된 정보입니다." << endl;
			cout << "\tID와 Password를 확인해주세요. " << endl;
			return 0;
		}
	}
}
int Application::MakeID()
{

	string id, password, mail, name;
	Login member;
	cout << "\t----------" << endl;
	cout << "\t회원 가입" << endl;
	cout << "\t만들고 싶은 ID : ";
	cin >> id;
	cout << "\tPassword : ";
	cin >> password;
	cout << "\t이름: ";
	cin >> name;
	cout << "\t메일 명: ";
	cin >> mail;
	member.MakeID(id, password, name, mail);
	Login data;
	m_MemberList.ResetList();
	while (m_MemberList.GetNextItem(data) != -1)
	{
		if (data.GetName() == name && data.GetMail() == mail)
		{
			cout << "\t회원가입이 이미 되어있습니다." << endl;
			return 0;
		}
	}

	if (m_MemberList.Get(member))
	{
		cout << "\t중복된 ID가 존재합니다 " << endl;
		return 0;
	}
	else {
		cout << "\t회원가입 완료!" << endl;
		m_MemberList.Add(member);
		return 1;
	}

}
int Application::GetLogin()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 로그인" << endl;
	cout << "\t   2 : 회원 가입" << endl;
	cout << "\t   3 : 프로그램 종료" << endl;
	cout << endl << "\t번호를 선택합니다--> ";
	cin >> command;
	cout << endl;
	return command;
}
int Application::GetMaster()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t------Master Mode------" << endl;
	cout << "\t   1 : 음악 리스트(Master List)에 추가" << endl;
	cout << "\t   2 : 음악 리스트(Master List)에서 삭제" << endl;
	cout << "\t   3 : 음악 리스트(Master List)에서 갱신" << endl;
	cout << "\t   4 : 파일에서 데이터를 읽어줍니다" << endl;
	cout << "\t   5 : 파일에서 데이터를 씁니다" << endl;
	cout << "\t   6 : 모든 음악을 보여줍니다" << endl;
	cout << "\t   7 : ID를 이용하여 자세한 음악 정보를 검색해합니다" << endl;
	cout << "\t	  0 : 뒤로 가기" << endl;
	cout << endl << "\t번호를 선택합니다--> ";

	cin >> command;
	cout << endl;
	return command;
}
void Application::MasterRun()
{
	while (1)
	{
		m_Command = GetMaster();

		switch (m_Command)
		{
		case 1:
			AddMasterMusic();
			break;
		case 2:	
			DeleteMasterMusic();
			break;
		case 3:
			ReplaceMusic();
			break;
		case 4:	
			ReadDataFromFile();
			break;
		case 5:	
			WriteDataToFile();
			break;
		case 6:	
			DisplayAllMusic();
			break;
		case 7:
			PlayMusic();
			break;
		case 8:
			DisplayPlayMusicList();
			break;	
		case 0:
			return;
		default:
			cout << "\t잘못된 입력\n";
			break;
		}

	}

}


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1://음악 재생
			PlayMusic();
			
			break;
		case 2:	// 나만의 음악 리스트에 추가
			AddmyMusic();
			
			break;
		case 3:	//나만의 음악 리스트에서 삭제
			DeletemyMusic();
			
			break;
		case 4://나만의 음악 리스트를 보여줍니다
			DisplayAllmyMusic();
			
			break;
		case 5://최근에 추가한 나만의 음악 리스트
			DisplayNewMusic();
			
			break;
		case 6://최근에 재생한 나만의 음악 리스트
			DisplayPlayMusicList();
		
			break;
		case 7:	//삭제를 추천하는 음악 리스트
			DisplayDeleteList();
	
			break;
		case 8:	//노래제목으로 검색
			SearchByName();
		
			break;
		case 9:	//가수이름으로 검색
			SearchByArtist();
			
			break;
		case 10://앨범이름으로 검색	
			SearchByAlbum();
		
			break;
		case 11:	// 장르이름으로 검색
			SearchByGenre();
			
			break;
		case 12:	//장르별로 출력
			DisplayMusicByGenre();
		
			break;
		case 13: // 앨범별로 출력
			DisplayMusicByAlbum();
			break;
		case 14: //노래이름별로 출력
			DisplayMusicBySongName();
			break;
		case 15:// 가수이름별로 출력
			DisplayMusicByArtist();
			
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}

	}

}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t------User Mode------" << endl;
	cout << "\t   1 : 음악 재생" << endl;
	cout << "\t   2 : 나만의 음악 리스트에 추가" << endl;
	cout << "\t   3 : 나만의 음악 리스트에서 삭제" << endl;
	cout << "\t   4 : 나만의 음악 리스트를 보여줍니다" << endl;
	cout << "\t   5 : 최근에 추가한 나만의 음악 리스트" << endl;
	cout << "\t   6 : 최근에 재생한 나만의 음악 리스트" << endl;
	cout << "\t   7 : 삭제를 추천하는 음악 리스트" << endl;
	cout << "\t   8 : 노래제목으로 검색" << endl;
	cout << "\t   9 : 가수이름으로 검색" << endl;
	cout << "\t   10 : 앨범이름으로 검색" << endl;
	cout << "\t   11 : 장르이름으로 검색" << endl;
	cout << "\t   12 : 장르별로 출력" << endl;
	cout << "\t   13 : 앨범별로 출력" << endl;
	cout << "\t   14 : 노래제목별로 출력" << endl;
	cout << "\t   15 : 가수이름별로 출력" << endl;

	cout << "\t	0: 뒤로가기	" << endl;

	cout << endl << "\t 번호를 선택해주세요--> ";
	cin >> command;
	cout << endl;

	return command;
}

// add new record to masterlist
int Application::AddMasterMusic()
{
	MusicType item;
	item.SetRecordFromKB();
	m_MasterList.Add(item);
	DisplayAllMusic();
	return 1;
}

// Add new record into list.
int Application::AddmyMusic()
{

	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	MusicType item;
	SimpleMusicType item2;
	GenreType temp;
	DisplayAllMusic();
	cout << "내 리스트에 추가하고 싶은 음악의 ID를 입력하시오 : " << endl;
	item.SetIDFromKB();
	
	if (m_MasterList.Get(item)) 
	{
		m_MusicList.Add(item);
		item2.setinfo(item.GetID(), item.GetSongName());
	}
	else {
		cout << "목록에 없는 노래입니다." << endl;
	}
	//최근리스트
	AddRecentlyMusicList.EnQueue(item2);
	//장르리스트
	AddMusictoGenreList(item);
	//장르리스트
	
	AddMusictoAlbumList(item);
	
	AddMusictoSongList(item);
	// 현재 list 출력
	DisplayAllmyMusic();

	return 1;
}

// add music to genrelist
void Application::AddMusictoGenreList(MusicType item) 
{
	GenreType data;
	SimpleMusicType item2;
	item2.setinfo(item.GetID(), item.GetSongName());
	data.setGenreName(item.GetGenre());
	if (m_GenreList.GetLength() == 0)
	{
		
		data.setGenreName(item.GetGenre());
		data.addGenre(item2);
		m_GenreList.Add(data);
	}
	else
	{
		bool found;
		GenreType temp;
		temp.setGenreName(item.GetGenre());
		m_GenreList.RetrieveItem(temp, found);
		if (found == true)
		{
			if (temp.getGenreName() == item.GetGenre())
			{
				temp.addGenre(item2);
				m_GenreList.Replace(temp);
				DisplayAllMusic();
			}
			else {
				GenreType tmp;
				tmp.setGenreName(item.GetGenre());
				tmp.addGenre(item2);
				m_GenreList.Add(tmp);
			}
		}
		else {
			GenreType tmp;
			tmp.setGenreName(item.GetGenre());
			tmp.addGenre(item2);
			m_GenreList.Add(tmp);
		}
	}
}
void Application::DeleteAlbumToArtistList(AlbumType& selectItem)
{
	ArtistType walkArtist;
	walkArtist.SetArtist(selectItem.GetArtist());
	if (m_ArtistList.Get(walkArtist)) {
		walkArtist.DeleteAlbum(selectItem);
		if (walkArtist.GetArtistAlbumListLength() == 0) {
			m_ArtistList.DeleteItem(walkArtist);
		}
		else {
			m_ArtistList.Replace(walkArtist);
		}
	}
}

//add music to albumlist
void Application::AddMusictoAlbumList(MusicType item)
{
	AlbumType data;
	data.SetAlbum(item.GetAlbum());
	
	SimpleMusicType item2;
	item2.setinfo(item.GetID(), item.GetSongName());
	if (m_AlbumList.GetLength() == 0)
	{
		data.SetInfo(item.GetAlbum(), item.GetSinger(), item.GetBirth(), item.GetCompany());
		data.AddAlbumMusic(item2);
		AddAlbumToArtistList(data);
		m_AlbumList.Add(data);
	}
	else
	{
		bool found;
		AlbumType temp;
		temp.SetAlbum(item.GetAlbum());
		m_AlbumList.RetrieveItem(temp, found);
		if (found == true)
		{
				AlbumType tmp;
				tmp.SetInfo(item.GetAlbum(), item.GetSinger(), item.GetBirth(), item.GetCompany());
				tmp.AddAlbumMusic(item2);
				AddAlbumToArtistList(tmp);
				m_AlbumList.Add(tmp);
		}
		else {
			AlbumType tmp;
			tmp.SetInfo(item.GetAlbum(), item.GetSinger(), item.GetBirth(), item.GetCompany());
			tmp.AddAlbumMusic(item2);
			AddAlbumToArtistList(tmp);
			m_AlbumList.Add(tmp);
			
		}
	}
}

// add album to artistlist 
void Application::AddAlbumToArtistList(AlbumType& item)
{
	if (m_ArtistList.GetLength() == 0) {
		ArtistType data;
		data.SetInfoA(item.GetArtist(), item.GetCompany(), item.GetBirth());
		data.AddAlbum(item);
		m_ArtistList.Add(data);
	}
	else {
		ArtistType data;
		data.SetInfoA(item.GetArtist(), item.GetCompany(), item.GetBirth());
		if (m_ArtistList.Get(data)) {
			data.AddAlbum(item);
			m_ArtistList.Replace(data);
		}
		else {
			ArtistType newdata;
			newdata.SetInfoA(item.GetArtist(), item.GetCompany(), item.GetBirth());
			newdata.AddAlbum(item);
			m_ArtistList.Add(newdata);
		}
	}
}

// Display all my records in the list on screen.
void Application::DisplayAllmyMusic()
{
	m_MusicList.PrintTree(cout);
}

// Display all records in the list on screen.
void Application::DisplayAllMusic()
{
	m_MasterList.PrintTree(cout);
}

//찾을 노래 제목을 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
void Application::SearchByName()
{

	cout << "\t찾을 노래 제목 ";
	string findtext;	//사용자에게서 ID값을 입력받는다.
	cin >> findtext;
	PrintNFindDetailSongName(m_SongList.GetRoot(), findtext, cout);
	
}

//inSong이 들어가있는 뮤직리스트의 자세한 정보를 출력
void Application:: PrintNFindDetailSongName(Node <SongType>* root, string inSong, ostream& out)
{
	if (root != NULL)
	{
		PrintNFindDetailSongName(root->left, inSong, out);
		SongType data;
		data.SetSongName(root->data.GetSongName());
		m_SongList.Get(data);
		if (data.GetSongName().find(inSong) != string::npos)
		{
			out << data;
		}
		PrintNFindDetailSongName(root->right, inSong, out);
	}
}

//찾을 가수를 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
void Application::SearchByArtist()
{
	cout << "\t찾을 가수 ";
	MusicType data;	//Get함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	string findtext;	//사용자에게서 ID값을 입력받는다.
	cin >> findtext;
	PrintNFindDetailArtist(m_ArtistList.GetRoot(), findtext, cout);
}

//inArtist가 들어가있는 뮤직리스트의 자세한 정보를 출력
void Application::PrintNFindDetailArtist(Node <ArtistType>* root, string inArtist, ostream& out)
{
	if (root != NULL)
	{
		PrintNFindDetailArtist(root->left, inArtist, out);
		ArtistType data;
		data.SetArtist(root->data.GetArtist());
		m_ArtistList.Get(data);
		if (data.GetArtist().find(inArtist) != string::npos)
		{
			out << data;
		}
		PrintNFindDetailArtist(root->right, inArtist, out);
	}
}

//찾을 장르를 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
void Application::SearchByGenre()
{
	cout << "\t찾을 장르 ";
	GenreType data;

	string findtext;	//사용자에게서 Genre값을 입력받는다.
	cin >> findtext;

	PrintNFindDetailGenre(m_GenreList.GetRoot(), findtext, cout);

}

//inGenre가 들어가있는 뮤직리스트의 자세한 정보를 출력
void Application::PrintNFindDetailGenre(Node <GenreType>* root, string inGenre, ostream& out)
{
	if (root != NULL) 
	{
		PrintNFindDetailGenre(root->left, inGenre, out);
		GenreType data; 
		data.setGenreName(root->data.getGenreName());
		m_GenreList.Get(data);
		if (data.getGenreName().find(inGenre) != string::npos)
		{
			out << data;
		}
		PrintNFindDetailGenre(root->right, inGenre, out);
	}
}

//찾을 앨범을 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
void Application::SearchByAlbum()
{
	cout << "\t찾을 앨범 ";
	string findtext;	//사용자에게서 Album값을 입력받는다.
	cin >> findtext;
	PrintNFindDetailAlbum(m_AlbumList.GetRoot(), findtext, cout);
}

//inAlbum가 들어가있는 뮤직리스트의 자세한 정보를 출력
void Application::PrintNFindDetailAlbum(Node <AlbumType>* root, string inAlbum, ostream& out)
{
	if (root != NULL)
	{
		PrintNFindDetailAlbum(root->left, inAlbum, out);
		AlbumType data;
		data.SetAlbum(root->data.GetAlbum());
		m_AlbumList.Get(data);
		if (data.GetAlbum().find(inAlbum) != string::npos)
		{
			cout << "찾았습니다" << endl;
			out << data;
		}
		PrintNFindDetailAlbum(root->right, inAlbum, out);
	}
}


//찾을 노래 제목을 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
void Application::DeletemyMusic()
{
	cout << "\t지울";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	SimpleMusicType data2;
	data.SetIDFromKB();	//사용자에게서 ID값을 입력받는다.
	data2.setinfo(data.GetID(), data.GetSongName());
	bool found;
	m_MusicList.RetrieveItem(data, found);
	if (found == true) {
		m_MusicList.DeleteItem(data);
		DeleteMusicToGenreList(data);
		DeleteMusicToAlbumList(data);
		DeleteMusicToSongList(data);
		cout << "\n\t삭제가 정상적으로 동작하였습니다." << endl;
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.

	DisplayAllmyMusic();
}

void Application::DeleteMasterMusic()
{
	cout << "\t지울";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	SimpleMusicType data2;
	data.SetIDFromKB();	//사용자에게서 ID값을 입력받는다.
	data2.setinfo(data.GetID(), data.GetSongName());
	bool found;
	m_MasterList.RetrieveItem(data, found);
	if(found == true)
	{
		m_MasterList.DeleteItem(data);
		
		cout << "\n\t삭제가 정상적으로 동작하였습니다." << endl;
		m_MusicList.RetrieveItem(data, found);
		if (found == true)
		{
			m_MusicList.DeleteItem(data);
			DeleteMusicToAlbumList(data);
			DeleteMusicToGenreList(data);
			DeleteMusicToSongList(data);
		}
	}

	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.

	DisplayAllMusic();
}
//파라미터에서 가져온 데이터를 장르리스트에 삭제.
void Application::DeleteMusicToGenreList(MusicType item)
{
	GenreType walk;
	walk.setGenreName(item.GetGenre());
	if (m_GenreList.Get(walk)) {
		SimpleMusicType data;
		data.setinfo(item.GetID(), item.GetSongName());
		walk.deleteGenre(data);
		if (walk.GetMusicLength() == 0) {
			m_GenreList.DeleteItem(walk);
		}
		else {
			m_GenreList.Replace(walk);
		}
	}
}

//파라미터에서 가져온 데이터를 앨범리스트에 삭제.
void Application::DeleteMusicToAlbumList(MusicType item)
{
	AlbumType walk;
	walk.SetAlbum(item.GetAlbum());
	if (m_AlbumList.Get(walk)) {
		SimpleMusicType data;
		data.setinfo(item.GetID(), item.GetSongName());
		walk.DeleteAlbumMusic(data);
		if (walk.GetAlbumSongNumber() == 0) {
			m_AlbumList.DeleteItem(walk);
		}
		else {
			AddAlbumToArtistList(walk);
			m_AlbumList.Replace(walk);
		}
	}
}
//파라미터에서 가져온 데이터를 송리스트에 추가.
void Application::AddMusictoSongList(MusicType item)
{
	SongType songdata;
	songdata.setinfo(item.GetID(), item.GetSongName());
	m_SongList.Add(songdata);
}
//파라미터에서 가져온 데이터를 송리스트에 삭제.
void Application::DeleteMusicToSongList(MusicType item)
{
	SongType song;
	song.SetSongName(item.GetSongName());
	m_SongList.DeleteItem(song);
}

//찾을 노래 제목을 사용자에게 입력받고 SortedList의 Replace함수를 호출한다.
void Application::ReplaceMusic()
{
	cout << "\t변경을 원하는 항목의 ";
	MusicType data;	//Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	MusicType change;
	data.SetIDFromKB();	//사용자에게서 수정할 항목의 ID를 입력받는다
	bool found;
	
	if(m_MasterList.Get(data)== false)
	{
	
		cout << "\t항목을 찾을 수 없습니다." << endl;		//찾을 수 없을때 메시지를 출력한다.
		return;
	}
	else	//찾을 수 있을때
	{
		change.SetID(data.GetID());
		change.SetSNFromKB();
		change.SetSingerFromKB();
		change.SetAlbumFromKB();
		change.SetGenreFromKB();
		
		change.SetBirthFromKB();
		change.SetCompanyFromKB();
		change.SetAnnounceFromKB();
		change.SetRunTimeFromKB();
		change.SettextFromKB();
		m_MasterList.Replace(change);
	
		if (m_MusicList.GetLength() != 0)
		{
			m_MusicList.Replace(change);
			DeleteMusicToGenreList(data);
			DeleteMusicToAlbumList(data);
			DeleteMusicToSongList(data);
			AddMusictoGenreList(change);
			AddMusictoAlbumList(change);
			AddMusictoSongList(change);
		}
		
		
		DisplayAllMusic();
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_MasterList.Add(data);
		
	}

	m_InFile.close();	// file close

						// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;
	
	// list 포인터를 초기화

	m_MasterList.PrintTree(m_OutFile);

	m_OutFile.close();	// file close

	return 1;
}
//최근 음악 추가목록을 출력시켜준다.
int Application::DisplayNewMusic() {
	MusicType walk;
	SimpleMusicType walk2;
	SimpleMusicType tmp;
	string id;
	walk2.setinfo(walk.GetID(), walk.GetSongName());
	AddRecentlyMusicList.ResetCurrentPointer();
	int next = AddRecentlyMusicList.GetNextItem(walk2);
	while (next != -1) {
		m_MusicList.Get(walk);
		walk2.DisplaySimpleOnScreen();
		if (next == 0)
			break;
		next = AddRecentlyMusicList.GetNextItem(walk2);
	}
	return 0;

	cout << "Select ID : ";
	cin >> id;
	SongType musictmp;
	
	AddRecentlyMusicList.ResetCurrentPointer();
	while (AddRecentlyMusicList.GetNextItem(tmp) != -1)
	{
		if (tmp.GetID() == id)
		{
			musictmp.setinfo(tmp.GetID(), tmp.GetSongName());
			cout << musictmp;
			return 1;
		}
		else 
		{
			cout << "해당하는 ID가 없습니다" << endl;
			return 0;
		}
	}
}

//최근 재생목록 보여주는 함수
int Application::DisplayPlayMusicList() {
	MusicType walk;
	SongType data;
	SongType tmp;
	string songname;
	data.setinfo(walk.GetID(), walk.GetSongName());
	PlayRecentList.ResetCurrentPointer();
	int next = PlayRecentList.GetNextItem(data);
	while (next != -1) {
		m_MusicList.Get(walk);
		data.DisplaySongName();
		if (next == 0)
			break;
		next = PlayRecentList.GetNextItem(data);
	}
	
	return 1;	
}



//장르별로 음악을 출력시켜준다
void Application::DisplayMusicByGenre()
{
	m_GenreList.PrintTree(cout);
}
//앨범별로 음악을 출력시켜준다.
void Application::DisplayMusicByAlbum()
{
	m_AlbumList.PrintTree(cout);
}
//음악제목 별로 음악정보를 출력
void Application::DisplayMusicBySongName()
{
	m_SongList.PrintTree(cout);
}
//가수별로 음악정보를 출력
void Application::DisplayMusicByArtist()
{
	m_ArtistList.PrintTree(cout);
}