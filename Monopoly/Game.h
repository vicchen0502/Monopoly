#pragma once
#include "pch.h"
#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	int totalPlayer; //玩家總數
	int currentCount; //剩餘遊戲局數
	int currentPlayer; //目前輪到的玩家
	Map mainMap;

public:
	// 建構子，輸入讀取檔案的檔案名稱
	Game(string preferFile);
	// 載入遊戲
	void LoadGame(string preferFile);
	// 儲存遊戲
	void SaveGame(string preferFile);
	// 重新開始
	void NewGame();
	//擲骰子
	void RollingDice(Player &preferPlayer);
	// 玩家移動幾格
	void PlayerMove(int preferAddVector, Player &preferPlayer);

	friend class Map;
	friend class Player;
};
