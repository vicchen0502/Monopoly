#include "Player.h"
Player::Player()
{
	hasChunk.playerNumber = PlayerQuatity;
	hasChunk.playerName = "N/A";
	hasChunk.playerPosition = 0;
	hasChunk.hasMoney = 0;

	addPlayerQuatity(this);
}
Player::Player(string preferName)
{
	hasChunk.playerNumber = PlayerQuatity;
	hasChunk.playerName = preferName;
	hasChunk.playerPosition = 0;
	hasChunk.hasMoney = 0;

	addPlayerQuatity(this);
}
Player::Player(hasChunkStatus preferHasChunk)
{
	hasChunk.playerNumber = preferHasChunk.playerNumber;
	hasChunk.playerName = preferHasChunk.playerName;
	hasChunk.playerPosition = preferHasChunk.playerPosition;
	hasChunk.hasMoney = preferHasChunk.hasMoney;
	hasChunk.hasBuffNuff = preferHasChunk.hasBuffNuff;
	hasChunk.hasChunkNumber = preferHasChunk.hasChunkNumber;
	hasChunk.hasChunkStage = preferHasChunk.hasChunkStage;

	addPlayerQuatity(this);
}
void Player::addPlayerQuatity(Player* preferPlayerPointer)
{
	PlayerQuatity += 1; //玩家總數+1
	PlayerList = new Player(*preferPlayerPointer); //玩家清單加入新玩家
}