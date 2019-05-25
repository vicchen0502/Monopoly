#pragma once
#include "pch.h"
using namespace std;

// �֦��϶��y�z���c
struct hasChunkStatus
{
	int playerNumber; //���a�s��
	string playerName; //���a�W��
	int playerPosition; //���a��m
	int hasMoney; //���a�֦�������
	vector<string> hasBuffNuff; //���a�֦������|�ΩR�B�ĪG
	int hasChunkStage; //�֦����϶����š]�L�H�֦��B��l�B�@���B�G���B�T���^
	vector<int> hasChunkNumber; //�֦����϶��s��
	vector<int> hasChunkStagePrice; //�֦����϶����š]��l�B�@���B�G���B�T���^
};

class Player
{
private:
	static int PlayerQuatity; //�������a�`��
	static Player* PlayerList; //�������a�M��
	hasChunkStatus hasChunk; //���a�֦����϶��M��

public:
	// ��l�غc�l
	Player();
	// �a���a�W�٪��غc�l
	Player(string preferName);
	// �a���㪱�a��T���غc�l�A�Ω�Ū�ɲ��ͪ��a�ɨϥ�
	Player(hasChunkStatus preferHasChunk);
	// �W�[���a�`�ƶq
	static void addPlayerQuatity(Player* preferPlayerPointer);

	friend class Game;
	friend class Map;
};

