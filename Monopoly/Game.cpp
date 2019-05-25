#include "Game.h"

using namespace std;

Game::Game(string preferFile)
{
	// ...讀檔
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
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
}
void Game::LoadGame(string preferFile)
{
	// ...讀檔
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
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
}
void Game::SaveGame(string preferFile)
{
	// ...存檔
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
}
void Game::NewGame()
{
	// ...讀取basemap檔案
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
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
	// 更新mainMap、currentPlayer、currentCount、totalPlayer等
}
void Game::RollingDice(Player &preferPlayer)
{
	cout << "輪到玩家 " << preferPlayer.hasChunk.playerName << " 擲骰子\n";

	// 檢查玩家有無特殊效果...

	int diceNumber = rand() % 6 + 1;	//擲骰子，1-6
	cout << "玩家 " << preferPlayer.hasChunk.playerName << " 擲出：" << diceNumber << "點\n"; //印出提示訊息

	PlayerMove(diceNumber, preferPlayer);
}

void Game::PlayerMove(int preferAddVector, Player &preferPlayer)
{
	if (preferPlayer.hasChunk.hasBuffNuff.size() > 0)
	{
		// 有增減益效果，需檢查
	}
	else
	{
		// 玩家移動到向前移動
		preferPlayer.hasChunk.playerPosition += preferAddVector;

		// 檢查該區塊的type
		if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = 1)
		{
			// 如果是地產...
			// 地產又可分為無人擁有、初始擁有、一階、二階、三階
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = 0)
		{
			// 如果是起點...
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = -1)
		{
			// 如果是機會...
		}
		else if (mainMap.chunkList[preferPlayer.hasChunk.playerPosition].chunkType = -2)
		{
			// 如果是命運...
		}
	}

	currentCount -= 1; //已完成一局

	// 顯示畫面，畫面不確定是要另外獨立一個class還是直接在Game裡，明天可以再討論
	// 玩家輪流擲骰子，這樣會形成無限迴圈
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
		// 20局已進行完成，遊戲結束
		cout << "Game Over\n";
	}

}