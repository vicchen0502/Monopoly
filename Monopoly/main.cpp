#include "pch.h"
#include "Game.h"

using namespace std;

int main()
{
	Game mainGame("basemap.txt");
	srand(time(NULL));

	cout << "Press Enter to Continue...\n";
	getchar();
	return 0;
}