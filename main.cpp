// Alan Zhang 3/12/20
// main.cpp

#include "SNL.h"
#include <sstream>

using namespace std; 

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Format: ./snl [string]" << endl;
		exit(1);
	}

	stringstream ss;
	int N, L, S; // board size + # of ladders + # of snakes
	int a, b; // head + tail of ladder
	int c, d; // head + tail of snake

	ss << argv[1];

	int numBoards;
	ss >> numBoards;

	for (int i = 0; i < numBoards; i++) {
		SNL* game = new SNL();
		ss >> N >> L >> S;
		for (int j = 0; j < L; j++) {
			ss >> a >> b;
			for (int k = 0; k < game->ladders.size(); k = k + 2) {
				// if (game->ladders[k] == a) {
					// if(game->ladders[k + 1] < b) {
						// game->ladders[k + 1] = b;
						// b = -1;
						// break;
					// }
				// }
			}
			// if (b == -1) continue;

			game->ladders.push_back(a);
			game->ladders.push_back(b);
		}
		for (int j = 0; j < S; j++) {
			ss >> c >> d;
			for (int k = 0; k < game->snakes.size(); k = k + 2) {
				// if (game->snakes[k] == c) {
					// if(game->snakes[k + 1] > d) {
						// game->snakes[k + 1] = d;
						// b = -1;
						// break;
					// }
				// }
			}
			// if (b == -1) continue;

			game->snakes.push_back(c);
			game->snakes.push_back(d);
		}

		game->createBoard(N);
		cout << "Board Game #" << i + 1 << ":" << endl;
		game->printPath();
		delete game;
	}
	return 0;
}
