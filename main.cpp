#include <iostream>
#include "Board.hh"

int main() {
    std::cout << "\nInsert size of board: ";
    int size;
    std::cin >> size;
    std::cout << "\nInsert marks in a row to win: ";
    int row;
    std::cin >> row;
    std::cout << "\nInsert 1 if you want to start, otherwise insert any other integer: ";
    int whoFirst;
    std::cin >> whoFirst;
    if (whoFirst==1) {
        Board match(size,row, -1);
        match.game();
        std::cout << "Win: " <<  match.checkWin();
    }
    else{
        Board match(size,row, 1);
        match.game();
        std::cout << "Win: " <<  match.checkWin();
    }
    /*match.putElementOnBoard(-1,8);
    match.putElementOnBoard(-1,5);
    match.putElementOnBoard(-1,2);
    match.drawBoard();*/
    return 0;
}