//
// Created by jakub on 04.06.19.
//

#include "Board.hh"

void Board::drawBoard() {
    clearScreen();
    for(int i = 0; i < numberOfElementsOnBoard; i++)
    {
        if(i%this->sizeOfBoard==0) std::cout << "\n";
        if(this->gameBoard[i]==0) std::cout << "-" << "\t";
        else if(this->gameBoard[i]==1) std::cout << "O" << "\t";
        else if(this->gameBoard[i]==-1) std::cout << "X" << "\t";
        else {
            std::cerr << "Board has wrong cell.";
            exit(-1);
        }
    }
}


int Board::ifMoveValid(int positionOfElement) {
    if(this->gameBoard[positionOfElement]==0)
    return 0;
    else return -1;
}

int Board::putElementOnBoard(int typeOfElement, int positionOfElement) {
    if(this->ifMoveValid(positionOfElement)==0) {
        this->gameBoard[positionOfElement] = typeOfElement;
        return 0;
    }
    else return 1;
}

Board::Board(const int decidedSizeOfBoard, const int decidedNumberOfElementsToWin, const int whatHasCPU) :
sizeOfBoard(decidedSizeOfBoard), numberOfElementsToWin(decidedNumberOfElementsToWin),
numberOfElementsOnBoard(decidedSizeOfBoard*decidedSizeOfBoard),
AI(whatHasCPU){
    PLAYER = -AI;
    for(int i = 0; i < numberOfElementsOnBoard; i++) this->gameBoard.push_back(0);
}

Board::~Board() {

}

int Board::checkHorizontalElements() {//checking every row
    int sumOfElements;//points
    for(int i = 0; i < this->sizeOfBoard; i++) {
        sumOfElements=0;
        for(int j = 0; j< this->sizeOfBoard; j++){
            if(this->gameBoard[sizeOfBoard*i+j] == 0){//zeros points if empty cell
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[sizeOfBoard*i+j]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[sizeOfBoard*i+j]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[sizeOfBoard*i+j];//sums points
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) return -1;
        }
    }
    return 0;
}

int Board::checkVerticalElements() {//checking every column
    int sumOfElements;//points
    for(int i = 0; i < this->sizeOfBoard; i++) {
        sumOfElements=0;
        for(int j = 0; j< this->sizeOfBoard; j++){
            if(this->gameBoard[sizeOfBoard*j+i] == 0){//zeros points if empty cell
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[sizeOfBoard*j+i]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[sizeOfBoard*j+i]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[sizeOfBoard*j+i];//sums points
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) return -1;
        }
    }
    return 0;
}

int Board::checkLeftToRightDiagonal() {
    int sumOfElements=0;//points
    for(int i = 0; i < (sizeOfBoard-numberOfElementsToWin+1) ; i++){//checking starting at left column from up to down declining
        sumOfElements = 0;
        for(int j = i*sizeOfBoard; j < numberOfElementsOnBoard ; j=j+sizeOfBoard+1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[j]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[j]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                //std::cout << "Left2Right diagonal 1st part";
                return -1;
            }
        }
    }
    for(int i = numberOfElementsToWin; i <= sizeOfBoard ; i++){//checking starting at left column from up to down climbing
        sumOfElements = 0;
        for(int j = (i-1)*sizeOfBoard; j > 0 ; j=j-sizeOfBoard+1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[j]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[j]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                //std::cout << "Left2Right diagonal 1st part";
                return -1;
            }
        }
    }
    for(int i = 1; i <= this->sizeOfBoard-numberOfElementsToWin; i++){//checking starting at first row from left to right
        sumOfElements = 0;
        for(int j = i; j <= (this->numberOfElementsOnBoard-1-(i*sizeOfBoard)); j=j+sizeOfBoard+1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[j]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[j]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                //std::cout << "Left2Right diagonal 2nd part";
                return -1;
            }
        }
    }
    for(int i = 1; i <= this->sizeOfBoard-numberOfElementsToWin; i++){//checking startin at last row without first column from left to right
        sumOfElements = 0;
        for(int j = i+(sizeOfBoard*(sizeOfBoard-1)); j > (sizeOfBoard*i); j=j-sizeOfBoard+1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                if(sumOfElements>0 && this->gameBoard[j]<0) sumOfElements=0;
                else if(sumOfElements<0 && this->gameBoard[j]>0) sumOfElements=0;
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                //std::cout << "Left2Right diagonal 3rd part";
                return -1;
            }
        }
    }
    return 0;
}
/*
int Board::checkRightToLeftDiagonal() {
    int sumOfElements=0;//points
    for(int i = this->numberOfElementsToWin; i >= 0; i--){//checking starting at right column from down to up
        sumOfElements = 0;
        for(int j = ((i-1)*sizeOfBoard+4); j < this->numberOfElementsOnBoard; j=j+sizeOfBoard-1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                std::cout << "Right2Left diagonal 1st part";
                return -1;
            }
        }
    }
    int helpfulDiagonalCounter = this->numberOfElementsToWin-1;
    for(int i = this->numberOfElementsToWin-1; i <= this->sizeOfBoard-2; i++){//checking starting at first row without first column from left to right
        sumOfElements = 0;
        helpfulDiagonalCounter--;
        for(int j = i; j <= (numberOfElementsOnBoard-1-(helpfulDiagonalCounter*this->sizeOfBoard)); j=j+sizeOfBoard-1){
            if(this->gameBoard[j] == 0){
                sumOfElements=0;
            }
            else{
                sumOfElements+=this->gameBoard[j];
            }
            if(sumOfElements == this->numberOfElementsToWin) return 1;
            else if(sumOfElements == -(this->numberOfElementsToWin)) {
                        std::cout << "R2L diagonal 2nd part";
                        return -1;
                }
        }
    }
    return 0;
}
*/
int Board::checkDiagonalElements() {
    int a = checkLeftToRightDiagonal();
    if(a!=0) return a;
//    int b = checkRightToLeftDiagonal();
//   if(b!=0) return b;
    else return 0;
}

int Board::checkWin() {
    int a = checkDiagonalElements();
    if(a!=0){
        std::cout << "Diagonal Win";
        this->endOfGame=1;
        return a;
    }
    int b = checkVerticalElements();
    if(b!=0){
        std::cout << "Vertical Win";
        this->endOfGame=1;
        return b;
    }
    int c = checkHorizontalElements();
    if(c!=0){
        std::cout << "Horizontal Win";
        this->endOfGame=1;
        return c;
    }
    if(isMoveLeft()==false){
        this->endOfGame=1;
        return 99;
    }
    return 0;
}

int Board::game() {
    int x = 0, y = 0;
    int stateOfGame;
    this->drawBoard();
    while(this->endOfGame == 0){
        round++;
        if(turn[round%2]==AI){
            putElementOnBoard(AI,findBestMove());
        }
        else{
            do{
                std::cout << "\nGive x: ";
                std::cin >> x;
            } while (x<1 || x > sizeOfBoard);
            do{
                std::cout << "\nGive y: ";
                std::cin >> y;
            } while (y<1 || y > sizeOfBoard);
            if(putElementOnBoard(turn[round%2],(y-1)*this->sizeOfBoard+x-1)!=0) round--;
        }
        this->drawBoard();
        stateOfGame=this->checkWin();
    }
    if (stateOfGame==-1) std::cout << "\nCrosses win!\n";
    else if (stateOfGame==1) std::cout << "\nNoughts win!\n";
    else if (stateOfGame==99) std::cout << "\nThere was a tie!\n";
    return 0;
}

int Board::evaluate() {
    int a = checkHorizontalElements();
    if (a==AI) return 10;
    else if(a==PLAYER) return -10;
    a = checkVerticalElements();
    if (a==AI) return 10;
    else if(a==PLAYER) return -10;
    a = checkDiagonalElements();
    if (a==AI) return 10;
    else if(a==PLAYER) return -10;
    return 0;
}

int Board::minimax(int depth, bool isMax) {
    int score = this->evaluate();
//    std::cout << "\nScore: " << score;
    if (score!=0) return score;
    if (isMoveLeft()==false) return 0;
    if (depth == MAXDEPTH) return 0;//reduces depth due to time computing
    if(isMax){
        int best = -1000;
        for(int i = 0; i < numberOfElementsOnBoard; i++){
            if(gameBoard[i]==0){
                putElementOnBoard(AI,i);
                best = std::max(best, minimax(depth+1,!isMax));
                cleanCell(i);
            }
        }
        return best;
    }
    else{
        int best = 1000;
        for(int i = 0; i < numberOfElementsOnBoard; i++){
            if(gameBoard[i]==0){
                putElementOnBoard(PLAYER,i);
                best = std::min(best, minimax(depth+1, !isMax));
                cleanCell(i);
            }
        }
        return best;
    }
}

bool Board::isMoveLeft() {//checks if there is any empty cell
    for(int i = 0; i < this->numberOfElementsOnBoard; i++)
    {
        if (gameBoard[i]==0) return true;
    }
    return false;
}

int Board::findBestMove() {//primary function to control oponent CPU
    int bestValue = -1000;
    int tmpPosition = 0;

    for(int i = 0; i < numberOfElementsOnBoard; i++){//checks every left cell
        if(gameBoard[i]==0){
            putElementOnBoard(AI,i);
//            drawBoard();
            int newValue = minimax(0,false);//simulates next phases of game
            cleanCell(i);

            //std::cout << "Best V: " << bestValue << "\tPos: " << i << "\n";
            if(newValue > bestValue){//chooses the best option
                tmpPosition=i;
                bestValue=newValue;
            }
        }
    }
    //std::cout << tmpPosition;
    return tmpPosition;
}

int Board::cleanCell(int posOfCell) {
    gameBoard[posOfCell]=0;
    return 0;
}
