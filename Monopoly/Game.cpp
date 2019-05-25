#include "Game.h"

using namespace std;

Game::Game(string preferFile)
{
	// ...Ū��
	ifstream fin(preferFile);
	vector<string> inputString;
	if (!fin.is_open())
		cout << "Open file error" << endl;
	while (!fin.eof())
	{
		char input[200];
		fin.getline(input,200);
		string temp(input);
		inputString.push_back(temp);
	}
	fin.close;

	stringstream sin("");
	Map currentMap;
	sin.clear();
	sin << inputString[0];
	sin >> currentMap.mapName >> currentCount >> totalPlayer;
	for (int i = 0; i <= 27; i++)
	{
		sin.clear();
		sin << inputString[i + 1];
		Map::chunk inputChunk;
		sin >> inputChunk.chunkNumber >> inputChunk.chunkName >> inputChunk.chunkType;
		if (inputChunk.chunkType == 1)
		{
			sin >> inputChunk.chunkInitialPrice
				>> inputChunk.chunkPassPrice1
				>> inputChunk.chunkPassPrice2
				>> inputChunk.chunkPassPrice3;
		}
		currentMap.chunkList.push_back(inputChunk);
	}
	sin.clear();
	string buffer;
	sin << inputString[29];
	sin >> buffer >> currentPlayer;
	for (int i = 30; i <= inputString.size() - 1; i++)
	{
		hasChunkStatus whoseChunk;
		sin.clear();
		sin << inputString[i];
		sin >> whoseChunk.playerNumber
			>> whoseChunk.playerPosition
			>> whoseChunk.hasMoney;
		while (!sin.eof())
		{
			int chunkNumber = 0, chunkStage = 0;
			sin >> chunkNumber >> chunkStage;
			whoseChunk.hasChunkNumber.push_back(chunkNumber);
			whoseChunk.hasChunkStagePrice.push_back(chunkStage);
		}
		Player(whoseChunk);

		
	}
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
}
void Game::LoadGame(string preferFile)
{
	// ...Ū��
	ifstream fin(preferFile);
	vector<string> inputString;
	if (!fin.is_open())
		cout << "Open file error" << endl;
	while (!fin.eof())
	{
		char input[200];
		fin.getline(input, 200);
		string temp(input);
		inputString.push_back(temp);
	}
	fin.close;

	stringstream sin("");
	Map currentMap;
	sin.clear();
	sin << inputString[0];
	sin >> currentMap.mapName >> currentCount >> totalPlayer;
	for (int i = 0; i <= 27; i++)
	{
		sin.clear();
		sin << inputString[i + 1];
		Map::chunk inputChunk;
		sin >> inputChunk.chunkNumber >> inputChunk.chunkName >> inputChunk.chunkType;
		if (inputChunk.chunkType == 1)
		{
			sin >> inputChunk.chunkInitialPrice
				>> inputChunk.chunkPassPrice1
				>> inputChunk.chunkPassPrice2
				>> inputChunk.chunkPassPrice3;
		}
		currentMap.chunkList.push_back(inputChunk);
	}
	sin.clear();
	string buffer;
	sin << inputString[29];
	sin >> buffer >> currentPlayer;
	for (int i = 30; i <= inputString.size() - 1; i++)
	{
		hasChunkStatus whoseChunk;
		sin.clear();
		sin << inputString[i];
		sin >> whoseChunk.playerNumber
			>> whoseChunk.playerPosition
			>> whoseChunk.hasMoney;
		while (!sin.eof())
		{
			int chunkNumber = 0, chunkStage = 0;
			sin >> chunkNumber >> chunkStage;
			whoseChunk.hasChunkNumber.push_back(chunkNumber);
			whoseChunk.hasChunkStagePrice.push_back(chunkStage);
		}
		Player(whoseChunk);


	}
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
}
void Game::SaveGame(string preferFile)
{
	// ...�s��
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
}
void Game::NewGame()
{
	// ...Ū��basemap�ɮ�
	ifstream fin("basemap.txt");
	vector<string> inputString;
	if (!fin.is_open())
		cout << "Open file error" << endl;
	while (!fin.eof())
	{
		char input[200];
		fin.getline(input, 200);
		string temp(input);
		inputString.push_back(temp);
	}
	fin.close;

	stringstream sin("");
	Map currentMap;
	sin.clear();
	sin << inputString[0];
	sin >> currentMap.mapName >> currentCount >> totalPlayer;
	for (int i = 0; i <= 27; i++)
	{
		sin.clear();
		sin << inputString[i + 1];
		Map::chunk inputChunk;
		sin >> inputChunk.chunkNumber >> inputChunk.chunkName >> inputChunk.chunkType;
		if (inputChunk.chunkType == 1)
		{
			sin >> inputChunk.chunkInitialPrice
				>> inputChunk.chunkPassPrice1
				>> inputChunk.chunkPassPrice2
				>> inputChunk.chunkPassPrice3;
		}
		currentMap.chunkList.push_back(inputChunk);
	}
	sin.clear();
	string buffer;
	sin << inputString[29];
	sin >> buffer >> currentPlayer;
	for (int i = 30; i <= inputString.size() - 1; i++)
	{
		hasChunkStatus whoseChunk;
		sin.clear();
		sin << inputString[i];
		sin >> whoseChunk.playerNumber
			>> whoseChunk.playerPosition
			>> whoseChunk.hasMoney;
		while (!sin.eof())
		{
			int chunkNumber = 0, chunkStage = 0;
			sin >> chunkNumber >> chunkStage;
			whoseChunk.hasChunkNumber.push_back(chunkNumber);
			whoseChunk.hasChunkStagePrice.push_back(chunkStage);
		}
		Player(whoseChunk);


	}
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
	// ��smainMap�BcurrentPlayer�BcurrentCount�BtotalPlayer��
}
void Game::RollingDice(Player &preferPlayer)
{
	cout << "���쪱�a " << preferPlayer.hasChunk.playerName << " �Y��l\n";

	// �ˬd���a���L�S��ĪG...

	int diceNumber = rand() % 6 + 1;	//�Y��l�A1-6
	cout << "���a " << preferPlayer.hasChunk.playerName << " �Y�X�G" << diceNumber << "�I\n"; //�L�X���ܰT��

	PlayerMove(diceNumber, preferPlayer);
}

void Game::PlayerMove(int preferAddVector, Player &preferPlayer)
{
	if (preferPlayer.hasChunk.hasBuffNuff.size() > 0)
	{
		// ���W��q�ĪG�A���ˬd
	}
	else
	{
		// ���a���ʨ�V�e����
		preferPlayer.hasChunk.playerPosition += preferAddVector;

		// �ˬd�Ӱ϶���type
		if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = 1)
		{
			// �p�G�O�a��...
			// �a���S�i�����L�H�֦��B��l�֦��B�@���B�G���B�T��
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = 0)
		{
			// �p�G�O�_�I...
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = -1)
		{
			// �p�G�O���|...
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = -2)
		{
			// �p�G�O�R�B...
		}
	}

	currentCount -= 1; //�w�����@��

	// ��ܵe���A�e�����T�w�O�n�t�~�W�ߤ@��class�٬O�����bGame�̡A���ѥi�H�A�Q��
	// ���a���y�Y��l�A�o�˷|�Φ��L���j��
	if (preferPlayer.hasChunk.playerNumber < Player::PlayerQuatity - 1 && currentCount > 0)
	{
		RollingDice(Player::PlayerList[preferPlayer.hasChunk.playerNumber + 1]);
	}
	else if (preferPlayer.hasChunk.playerNumber == Player::PlayerQuatity - 1 && currentCount > 0)
	{
		RollingDice(Player::PlayerList[0]);
	}
	else
	{
		// 20���w�i�槹���A�C������
		cout << "Game Over\n";
	}

}