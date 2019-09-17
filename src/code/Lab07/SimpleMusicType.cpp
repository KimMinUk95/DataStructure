#include "SimpleMusicType.h"


// Set SongName from keyboard.
void SimpleMusicType::SetSNFromKB()
{
	cout << "\tSong Name : ";
	cin >> m_SongName;
}
//Set SongID from keyboard
void SimpleMusicType::SetIDFromKB()
{
	cout << "\tID		: ";
	cin >> m_ID;
}
//Set SongID & SongName from keyboard
void SimpleMusicType::SetSimpleFromKB()
{
	SetIDFromKB();
	SetSNFromKB();
}
// Compare two ID(primary key)
