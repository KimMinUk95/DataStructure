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
	
	cout << "�ƹ� Ű�� �Է��Ͻø� �Ҹ� ����� ����ϴ�.\n";
	time_t start, end;
	double playtime;
	PlaySound(ws, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	start = time(NULL);// �ð� ���� ����
	while (!_kbhit());
	PlaySound(NULL, 0, 0);
	end = time(NULL);//�ð� ���� ����
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
			cout << "�߸��� �Է��Դϴ�" << endl;
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
			cout << "\t�߸��� �����Դϴ�." << endl;
			cout << "\tID�� Password�� Ȯ�����ּ���. " << endl;
			return 0;
		}
	}
}
int Application::MakeID()
{

	string id, password, mail, name;
	Login member;
	cout << "\t----------" << endl;
	cout << "\tȸ�� ����" << endl;
	cout << "\t����� ���� ID : ";
	cin >> id;
	cout << "\tPassword : ";
	cin >> password;
	cout << "\t�̸�: ";
	cin >> name;
	cout << "\t���� ��: ";
	cin >> mail;
	member.MakeID(id, password, name, mail);
	Login data;
	m_MemberList.ResetList();
	while (m_MemberList.GetNextItem(data) != -1)
	{
		if (data.GetName() == name && data.GetMail() == mail)
		{
			cout << "\tȸ�������� �̹� �Ǿ��ֽ��ϴ�." << endl;
			return 0;
		}
	}

	if (m_MemberList.Get(member))
	{
		cout << "\t�ߺ��� ID�� �����մϴ� " << endl;
		return 0;
	}
	else {
		cout << "\tȸ������ �Ϸ�!" << endl;
		m_MemberList.Add(member);
		return 1;
	}

}
int Application::GetLogin()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : �α���" << endl;
	cout << "\t   2 : ȸ�� ����" << endl;
	cout << "\t   3 : ���α׷� ����" << endl;
	cout << endl << "\t��ȣ�� �����մϴ�--> ";
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
	cout << "\t   1 : ���� ����Ʈ(Master List)�� �߰�" << endl;
	cout << "\t   2 : ���� ����Ʈ(Master List)���� ����" << endl;
	cout << "\t   3 : ���� ����Ʈ(Master List)���� ����" << endl;
	cout << "\t   4 : ���Ͽ��� �����͸� �о��ݴϴ�" << endl;
	cout << "\t   5 : ���Ͽ��� �����͸� ���ϴ�" << endl;
	cout << "\t   6 : ��� ������ �����ݴϴ�" << endl;
	cout << "\t   7 : ID�� �̿��Ͽ� �ڼ��� ���� ������ �˻����մϴ�" << endl;
	cout << "\t	  0 : �ڷ� ����" << endl;
	cout << endl << "\t��ȣ�� �����մϴ�--> ";

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
			cout << "\t�߸��� �Է�\n";
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
		case 1://���� ���
			PlayMusic();
			
			break;
		case 2:	// ������ ���� ����Ʈ�� �߰�
			AddmyMusic();
			
			break;
		case 3:	//������ ���� ����Ʈ���� ����
			DeletemyMusic();
			
			break;
		case 4://������ ���� ����Ʈ�� �����ݴϴ�
			DisplayAllmyMusic();
			
			break;
		case 5://�ֱٿ� �߰��� ������ ���� ����Ʈ
			DisplayNewMusic();
			
			break;
		case 6://�ֱٿ� ����� ������ ���� ����Ʈ
			DisplayPlayMusicList();
		
			break;
		case 7:	//������ ��õ�ϴ� ���� ����Ʈ
			DisplayDeleteList();
	
			break;
		case 8:	//�뷡�������� �˻�
			SearchByName();
		
			break;
		case 9:	//�����̸����� �˻�
			SearchByArtist();
			
			break;
		case 10://�ٹ��̸����� �˻�	
			SearchByAlbum();
		
			break;
		case 11:	// �帣�̸����� �˻�
			SearchByGenre();
			
			break;
		case 12:	//�帣���� ���
			DisplayMusicByGenre();
		
			break;
		case 13: // �ٹ����� ���
			DisplayMusicByAlbum();
			break;
		case 14: //�뷡�̸����� ���
			DisplayMusicBySongName();
			break;
		case 15:// �����̸����� ���
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
	cout << "\t   1 : ���� ���" << endl;
	cout << "\t   2 : ������ ���� ����Ʈ�� �߰�" << endl;
	cout << "\t   3 : ������ ���� ����Ʈ���� ����" << endl;
	cout << "\t   4 : ������ ���� ����Ʈ�� �����ݴϴ�" << endl;
	cout << "\t   5 : �ֱٿ� �߰��� ������ ���� ����Ʈ" << endl;
	cout << "\t   6 : �ֱٿ� ����� ������ ���� ����Ʈ" << endl;
	cout << "\t   7 : ������ ��õ�ϴ� ���� ����Ʈ" << endl;
	cout << "\t   8 : �뷡�������� �˻�" << endl;
	cout << "\t   9 : �����̸����� �˻�" << endl;
	cout << "\t   10 : �ٹ��̸����� �˻�" << endl;
	cout << "\t   11 : �帣�̸����� �˻�" << endl;
	cout << "\t   12 : �帣���� ���" << endl;
	cout << "\t   13 : �ٹ����� ���" << endl;
	cout << "\t   14 : �뷡���񺰷� ���" << endl;
	cout << "\t   15 : �����̸����� ���" << endl;

	cout << "\t	0: �ڷΰ���	" << endl;

	cout << endl << "\t ��ȣ�� �������ּ���--> ";
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

	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	MusicType item;
	SimpleMusicType item2;
	GenreType temp;
	DisplayAllMusic();
	cout << "�� ����Ʈ�� �߰��ϰ� ���� ������ ID�� �Է��Ͻÿ� : " << endl;
	item.SetIDFromKB();
	
	if (m_MasterList.Get(item)) 
	{
		m_MusicList.Add(item);
		item2.setinfo(item.GetID(), item.GetSongName());
	}
	else {
		cout << "��Ͽ� ���� �뷡�Դϴ�." << endl;
	}
	//�ֱٸ���Ʈ
	AddRecentlyMusicList.EnQueue(item2);
	//�帣����Ʈ
	AddMusictoGenreList(item);
	//�帣����Ʈ
	
	AddMusictoAlbumList(item);
	
	AddMusictoSongList(item);
	// ���� list ���
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

//ã�� �뷡 ������ ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
void Application::SearchByName()
{

	cout << "\tã�� �뷡 ���� ";
	string findtext;	//����ڿ��Լ� ID���� �Է¹޴´�.
	cin >> findtext;
	PrintNFindDetailSongName(m_SongList.GetRoot(), findtext, cout);
	
}

//inSong�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
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

//ã�� ������ ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
void Application::SearchByArtist()
{
	cout << "\tã�� ���� ";
	MusicType data;	//Get�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	string findtext;	//����ڿ��Լ� ID���� �Է¹޴´�.
	cin >> findtext;
	PrintNFindDetailArtist(m_ArtistList.GetRoot(), findtext, cout);
}

//inArtist�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
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

//ã�� �帣�� ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
void Application::SearchByGenre()
{
	cout << "\tã�� �帣 ";
	GenreType data;

	string findtext;	//����ڿ��Լ� Genre���� �Է¹޴´�.
	cin >> findtext;

	PrintNFindDetailGenre(m_GenreList.GetRoot(), findtext, cout);

}

//inGenre�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
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

//ã�� �ٹ��� ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
void Application::SearchByAlbum()
{
	cout << "\tã�� �ٹ� ";
	string findtext;	//����ڿ��Լ� Album���� �Է¹޴´�.
	cin >> findtext;
	PrintNFindDetailAlbum(m_AlbumList.GetRoot(), findtext, cout);
}

//inAlbum�� ���ִ� ��������Ʈ�� �ڼ��� ������ ���
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
			cout << "ã�ҽ��ϴ�" << endl;
			out << data;
		}
		PrintNFindDetailAlbum(root->right, inAlbum, out);
	}
}


//ã�� �뷡 ������ ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
void Application::DeletemyMusic()
{
	cout << "\t����";
	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	SimpleMusicType data2;
	data.SetIDFromKB();	//����ڿ��Լ� ID���� �Է¹޴´�.
	data2.setinfo(data.GetID(), data.GetSongName());
	bool found;
	m_MusicList.RetrieveItem(data, found);
	if (found == true) {
		m_MusicList.DeleteItem(data);
		DeleteMusicToGenreList(data);
		DeleteMusicToAlbumList(data);
		DeleteMusicToSongList(data);
		cout << "\n\t������ ���������� �����Ͽ����ϴ�." << endl;
	}
	else
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.

	DisplayAllmyMusic();
}

void Application::DeleteMasterMusic()
{
	cout << "\t����";
	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	SimpleMusicType data2;
	data.SetIDFromKB();	//����ڿ��Լ� ID���� �Է¹޴´�.
	data2.setinfo(data.GetID(), data.GetSongName());
	bool found;
	m_MasterList.RetrieveItem(data, found);
	if(found == true)
	{
		m_MasterList.DeleteItem(data);
		
		cout << "\n\t������ ���������� �����Ͽ����ϴ�." << endl;
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
		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.

	DisplayAllMusic();
}
//�Ķ���Ϳ��� ������ �����͸� �帣����Ʈ�� ����.
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

//�Ķ���Ϳ��� ������ �����͸� �ٹ�����Ʈ�� ����.
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
//�Ķ���Ϳ��� ������ �����͸� �۸���Ʈ�� �߰�.
void Application::AddMusictoSongList(MusicType item)
{
	SongType songdata;
	songdata.setinfo(item.GetID(), item.GetSongName());
	m_SongList.Add(songdata);
}
//�Ķ���Ϳ��� ������ �����͸� �۸���Ʈ�� ����.
void Application::DeleteMusicToSongList(MusicType item)
{
	SongType song;
	song.SetSongName(item.GetSongName());
	m_SongList.DeleteItem(song);
}

//ã�� �뷡 ������ ����ڿ��� �Է¹ް� SortedList�� Replace�Լ��� ȣ���Ѵ�.
void Application::ReplaceMusic()
{
	cout << "\t������ ���ϴ� �׸��� ";
	MusicType data;	//Replace�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
	MusicType change;
	data.SetIDFromKB();	//����ڿ��Լ� ������ �׸��� ID�� �Է¹޴´�
	bool found;
	
	if(m_MasterList.Get(data)== false)
	{
	
		cout << "\t�׸��� ã�� �� �����ϴ�." << endl;		//ã�� �� ������ �޽����� ����Ѵ�.
		return;
	}
	else	//ã�� �� ������
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

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_MasterList.Add(data);
		
	}

	m_InFile.close();	// file close

						// ���� list ���
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;
	
	// list �����͸� �ʱ�ȭ

	m_MasterList.PrintTree(m_OutFile);

	m_OutFile.close();	// file close

	return 1;
}
//�ֱ� ���� �߰������ ��½����ش�.
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
			cout << "�ش��ϴ� ID�� �����ϴ�" << endl;
			return 0;
		}
	}
}

//�ֱ� ������ �����ִ� �Լ�
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



//�帣���� ������ ��½����ش�
void Application::DisplayMusicByGenre()
{
	m_GenreList.PrintTree(cout);
}
//�ٹ����� ������ ��½����ش�.
void Application::DisplayMusicByAlbum()
{
	m_AlbumList.PrintTree(cout);
}
//�������� ���� ���������� ���
void Application::DisplayMusicBySongName()
{
	m_SongList.PrintTree(cout);
}
//�������� ���������� ���
void Application::DisplayMusicByArtist()
{
	m_ArtistList.PrintTree(cout);
}