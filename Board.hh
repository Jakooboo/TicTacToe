//
// Created by jakub on 04.06.19.
//

#ifndef TIC_BOARD_HH
#define TIC_BOARD_HH

#include <vector>
#include "ClearScreen.hh"

class Board {
public:
    Board(const int sizeOfBoard, const int numberOfElementsToWin, const int whatHasCPU);
    void drawBoard();
    int putElementOnBoard(int typeOfElement, int positionOfElement);
    virtual ~Board();
    int endOfGame = 0;
    int checkWin();
    int round = 0;
    int game();

protected:
    std::vector <int> gameBoard; //data with information about every position in board
    const int sizeOfBoard;//size of board's size
    const int numberOfElementsOnBoard;//total number=size^2
    const int numberOfElementsToWin;
    const int turn[2] = {-1,1};//        1 for circle    -1 for cross
    const int AI;//decides what has CPU controlled side
    int PLAYER;
    int ifMoveValid(int numberOfElement);
    int checkHorizontalElements();
    int checkVerticalElements();
    int checkDiagonalElements();
    int checkLeftToRightDiagonal();
    //int checkRightToLeftDiagonal();
    int evaluate();
    int minimax(int depth, bool isMax);
    bool isMoveLeft();
    int findBestMove();
    int cleanCell(int posOfCell);
    int MAXDEPTH = 9-sizeOfBoard;
};


#endif //TIC_BOARD_HH
