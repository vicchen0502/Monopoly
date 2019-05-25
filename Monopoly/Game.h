#pragma once
#include "pch.h"
#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
private:
	int totalPlayer; //���a�`��
	int currentCount; //�Ѿl�C������
	int currentPlayer; //�ثe���쪺���a
	Map mainMap;

public:
	// �غc�l�A��JŪ���ɮת��ɮצW��
	Game(string preferFile);
	// ���J�C��
	void LoadGame(string preferFile);
	// �x�s�C��
	void SaveGame(string preferFile);
	// ���s�}�l
	void NewGame();
	//�Y��l
	void RollingDice(Player &preferPlayer);
	// ���a���ʴX��
	void PlayerMove(int preferAddVector, Player &preferPlayer);

	friend class Map;
	friend class Player;
};
