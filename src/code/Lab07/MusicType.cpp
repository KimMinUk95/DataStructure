#include "MusicType.h"


// Set Singer from keyboard.
void MusicType::SetSNFromKB()
{
	cout << "\t�뷡 ���� : ";
	cin >> m_SongName;
}
//Set SongID from keyboard
void MusicType::SetIDFromKB()
{
	cout << "\tID		: ";
	cin >> m_ID;
}
//Set SongID & SongName from keyboard
void MusicType::SetSingerFromKB()
{
	cout << "\t���� �̸� : ";
	cin >> m_Singer;
}
// Set Album from keyboard
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ� �̸� : ";
	cin >> m_Album;
}
void MusicType::SetBirthFromKB()
{
	cout << "\t������ ���� ���� : ";
	cin >> m_Birth;
}

void MusicType::SetCompanyFromKB()
{
	cout << "\tȸ�� �̸� : ";
	cin >> m_company;
}

void MusicType::SetAnnounceFromKB()
{
	cout << "\t�ٹ� �߸� ��: ";
	cin >> m_announce;
}

void MusicType::SetRunTimeFromKB() 
{
	cout << "\t����ð� : ";
	cin >> m_runtime;
}
// Set Genre from keyboard.
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣�� : ";
	cin >> m_Genre;
}
// Set �뷡 ���� from keyboard
void MusicType::SettextFromKB()
{
	cout << "\t���� : ";
	string remain;
	getline(cin, remain);
	getline(cin, m_text);
}
// Set music record from keyboard.
void MusicType::SetRecordFromKB()
{
	SetIDFromKB();
	SetSNFromKB();
	SetSingerFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	
	SetBirthFromKB();
	SetCompanyFromKB();
	SetAnnounceFromKB();
	SetRunTimeFromKB();
	SettextFromKB();
}


// Read a record from file.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_ID;
	fin >> m_SongName;
	fin >> m_Singer;
	fin >> m_Album;
	fin >> m_Genre;
	fin >> m_Birth;
	fin >> m_announce;
	fin >> m_company;
	fin >> m_runtime;
	getline(fin, m_text);
	return 1;
};


// Write a record into file.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_ID << " ";
	fout << m_SongName << " ";
	fout << m_Singer << " ";
	fout << m_Album << " ";
	fout << m_Genre << " ";
	fout << m_Birth << " ";
	fout << m_announce << " ";
	fout << m_company << " ";
	fout << m_runtime << " " ;
	fout << m_text << endl;
	return 1;
}

