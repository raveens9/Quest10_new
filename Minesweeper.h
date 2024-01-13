
using namespace std;

//20/ENG/139
//21/ENG/053 
//21/ENG/055

//Class creation done by 21/ENG/055
class MineSweeper {
public:
    int size;
    int mines;
    int flags;
    std::vector<std::vector<char> > board;
    std::vector<std::vector<bool> > revealed;


    MineSweeper(int size, int mines, int flags) : size(size), mines(mines), flags(flags)
    {
        initializeBoard();
        placeMines();
        initializeRevealed();
    }

    void initializeBoard() {
        board.resize(size, std::vector<char>(size, 'c'));
    }

    void placeMines() {
        std::srand(std::time(0));
        for (int i = 0; i < mines; ++i) {
            int row = std::rand() % size;
            int col = std::rand() % size;
            while (board[row][col] == 'M') {
                row = std::rand() % size;
                col = std::rand() % size;
            }
            board[row][col] = 'M';
        }
    }

    void initializeRevealed() {
        revealed.resize(size, std::vector<bool>(size, false));
    }

    void displayBoard() {
        std::cout << "  ";
        for (int i = 0; i < size; ++i) {
            std::cout << char('A' + i) << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < size; ++i) {
            std::cout << char('A' + i) << " ";
            for (int j = 0; j < size; ++j) {
                if (revealed[i][j]) {
                    std::cout << board[i][j] << " ";
                }
                
                else {
                    std::cout << 'c' << " ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

//Revealing done by all members
    void revealLocation(int row, int col) {
        if (revealed[row][col]) {
            std::cout << "Location already revealed." << std::endl;
            return;
        }

        revealed[row][col] = true;

        if (board[row][col] == 'M') {
            gameOver();
            return;
        }
        else {
            board[row][col] = char('0' + countMinesAround(row, col));
        }
    }

    void flagLocation(int row, int col) {
    std::cout << "You have " << flags - 1 << " flags remaining" << endl;

    if (flags > 0 && board[row][col] == 'c') {
        board[row][col] = 'F';  
        flags--;
    } else {
        std::cout << "Invalid flagging operation. Check if the location is covered and you have available flags." << std::endl;
    }
}

    int countMinesAround(int row, int col) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newRow = row + i;
                int newCol = col + j;

                if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
                    if (board[newRow][newCol] == 'M') {
                        count++;
                    }
                }
            }
        }
        return count;
    }

//Game end done by 20/ENG/139
    void gameOver() {
        std::cout << "Game Over! Mines were at the following locations:" << std::endl;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == 'M') {
                    std::cout << char('A' + i) << char('A' + j) << " ";
                }
            }
        }

        std::cout << std::endl;

        std::cout << "Press any key to exit..." << std::endl;
        char dummy;
        std::cin >> dummy; 

        exit(0); 
    }

    void resetGame() {
        flags = mines;
        initializeBoard();
        placeMines();
        initializeRevealed();
        std::cout << "Choose a field size:" << std::endl;
    }

};
