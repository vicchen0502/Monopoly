#pragma once
#include "pch.h"
using namespace std;


class Map
{
	// 區塊結構
	struct chunk
	{
		int chunkNumber; //區塊編號
		string chunkName; //區塊名稱
		int chunkType; //區塊類型
		int chunkInitialPrice; //區塊初始價格
		int chunkPassPrice1; //區塊一階過路費
		int chunkPassPrice2; //區塊二階過路費
		int chunkPassPrice3; //區塊三階過路費
		string chunkMemo; //區塊備註，提供機會命運述之用
	};
private:
	vector<chunk> chunkList; //姬路地圖上的所有Chunk
	string mapName;

	friend class Game;
	friend class Player;
};