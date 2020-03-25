// Alan Zhang 3/12/20
// SNL.cpp

#include "SNL.h"

using namespace std;

void SNL::createBoard(int n) {
	int size = n * n;
	board.resize(size);

	// initialize the board
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < 7; j++) {
			if (i + j + 1 <= size) {
				board[i].paths.push_back(i + j + 1);		
			} else {
				board[i].paths.push_back(size);
			}
		}
	}

	// insert ladders
	for (int i = 0; i < ladders.size(); i = i + 2) {
		// for (int j = 0; j < size; j++) {
			// for (int k = 0; k < board[j].paths.size(); k++) {
				// cout << board[j].paths[k] << " " << ladders[i] << endl;
				// if (board[j].paths[k] == ladders[i]) {
				if (board[ladders[i] - 1].paths.size() == 6) {
					board[ladders[i] - 1].paths.clear();
				}
				board[ladders[i] - 1].paths.push_back(ladders[i + 1]);
				// }
			// }
		// }
	}

	for (int i = 0; i < snakes.size(); i = i + 2) {
		// for (int j = 0; j < size; j++) {
			// for (int k = 0; k < board[j].paths.size(); k++) {
				// cout << board[j].paths[k] << " " << ladders[i] << endl;
				// if (board[j].paths[k] == snakes[i]) {
					if (board[snakes[i] - 1].paths.size() == 6) {
						board[snakes[i] - 1].paths.clear();
					}
					board[snakes[i] - 1].paths.push_back(snakes[i + 1]);
				// }
			// }
		// }
	}

	// for (int i = 0; i < board.size(); i++) {
	// 	cout << i + 1 << ": ";
	// 	for (int j = 0; j < board[i].paths.size(); j++) {
	// 		cout << board[i].paths[j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

void SNL::printPath() {
	visitors.resize(board.size());
	fill(visitors.begin(), visitors.end(), false);
	prev.resize(board.size());
	fill(prev.begin(), prev.end(), -1);

	int index = 1; // starting index
	q.push(index); // starting pos enqueued
	visitors[0] = true; // starting pos visited
	prev[0] = 0;

 	while (!q.empty()) {
		index = q.front() - 1;
		q.pop();

		for (int i = board[index].paths.size() - 1; i >= 0; i--) {
			if (!visitors[board[index].paths[i] - 1]) {
				// cout << index + 1 << " " << board[index].paths[i] << endl;
				prev[board[index].paths[i] - 1] = index;
				q.push(board[index].paths[i]);
				visitors[board[index].paths[i] - 1] = true;
			}
		}
	}

	// for (int i = 0; i < prev.size(); i++) {
	// 	cout << i << ": " << prev[i] << endl;
	// }

	index = board.size() - 1;
	string s = "";
	int counter = 0;
	bool passThru = false;

	while (index != 0) {
		if (index - prev[index] > 6) {
			s.insert(0, to_string(prev[index] + 1) + "+" + to_string(index + 1) + " ");
			// cout << "prob	lem 4" << endl;
			passThru = true;
			index = prev[index];
			counter++;
		} else if (index - prev[index] < -6) {
			// cout << "problem 3" << endl;
			s.insert(0, to_string(prev[index] + 1) + "-" + to_string(index + 1) + " ");
			passThru = true;
			index = prev[index];
			counter++;
		}

		if (passThru) {
			// cout << "problem 2" << endl;
			if (!(index - prev[index] > 6) && !(index - prev[index] < -6)) {
				index = prev[index];
			}
			passThru = false;
		} else {
			// cout << "problem 1" << endl;
			// cout << index << endl;	
			s.insert(0, to_string(index + 1) + " ");
			counter++;
			index = prev[index];
		}
	}

	s.insert(0, "1 ");

	cout << counter << endl;
	cout << s << endl;
}