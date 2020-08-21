#include <iostream>
using namespace std;

class Chess {
private:
	int* chess;		// chess is a one-dimensional array.
	int chessSize;	// Size of the chess, for example, 8.
	int queenCount;	// Number of queens by now.
	int solutionNum;// Total number of solutions.
public:
	Chess() = delete;	// No default constructor.
	Chess(int chessSize) : chessSize(chessSize), queenCount(0), solutionNum(0) {
		chess = new int[chessSize];
		for (int i = 0; i < size(); i++) {
			chess[i] = -1;	// Means this row has not been set yet.
		}
	}
	~Chess() {
		delete[] chess;
	}

	int size() const { return chessSize; }
	int queens() const { return queenCount; }
	int solutions() const { return solutionNum; }

	void solve() {
		try_queen(0);	// Try put a queen from row 0.
	}
private:
	/* IMPORTANT FUNCTION IS TRY_QUEENS */
	void try_queen(int row) {
		if (queens() == size()) {
			print();	// Find one solution, print it out.
			++solutionNum;
		}
		else {
			for (int col = 0; col < size(); col++) {
				chess[row] = col;
				if (check_valid(row)) {
					++queenCount;
					try_queen(row + 1);
					--queenCount;
				}
			}
		}
	}
	bool check_valid(int row) {
		int col = chess[row];
		/* Check columns */
		for (int i = 0; i < row; i++) {
			if (chess[i] == col) { return false; }
		}
		/* Check diagonal */
		for (int i = 0; i < row; i++) {
			if (i + chess[i] == row + col) { return false; }
			if (i - chess[i] == row - col) { return false; }
		}
		return true;
	}
	void print() const {
		for (int i = 0; i < size(); i++) {
			cout << chess[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
	int n;
	cin >> n;
	Chess ch(n);
	ch.solve();
	cout << "Number of solutions: " << ch.solutions() << endl;
	system("pause");
	return 0;
}
