/* File: proj1.cpp
** Date: 9/25/19
** Author: Mitchell Angelos
** UMBC ID: CV55655 (a242@umbc.edu)
** Disc. Section: 23
** Description:
**   A farmer chases a rabbit around a grid.
*/ 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/* initializeGame()
** Inputs: a 2D char array, the board's height, the board's width
**   an array of characters for the welcome message
** No return, creates a board */ 
void initializeGame(char board[10][10], int boardHeight,
		    int boardWidth, const char welcomeMessage[]);
/* printBoard()
** Inputs: a 2D char array, board height, board width
** No return, prints board*/
void printBoard(char board[10][10], int boardHeight, int boardWidth);
/* updateFarmerPosition()
** Inputs: a row, a col, a 2d char array, a character
** No return, updates the farmer's position on the board */
void updateFarmerPosition(int yPos, int xPos, char board[10][10], char symbol);
/* updateRabbitPosition()
** Inputs: a row, a col, a 2d char array, a character
** No return, updates the rabbit's position on the board */
void updateRabbitPosition(int yPos, int xPos, char board[10][10], char symbol);
/* giveRabbitInitialPosition()
** Inputs: a 2d char array, board height, board width, a character
** No return, gives the rabbit an initial position on the board*/
void giveRabbitInitialPosition(char board[10][10], int boardHeight, int boardWidth, char symbol);
/* giveFarmerInitialPosition()
** Inputs: a 2d char array, board height, board width, a character
** No return, gives the farmer an initial position on the board*/
void giveFarmerInitialPosition(char board[10][10], int boardHeight, int boardWidth, char symbol);
/* getDistanceFromRabbit()
** Inputs: a 2d char array, an int board height, an int board width
** the farmer's character, the rabbit's character
** No return, prints where to find the rabbit */
void getDistanceFromRabbit(char board[10][10], int boardHeight, int boardWidth,
			   char farmer, char rabbit);
/* moveRabbit()
** Inputs: a 2d char array, an int board height, an int board width,
** the rabbit's character, the farmer's character
** Returns 1 if you win, returns 0 if game is still going */
int moveRabbit(char board[10][10], int boardHeight, int boardWidth, char rabbit, char farmer);
/* moveFarmer()
** Inputs: a 2d char array, an int board height, an int board width, the farmer's character
** Returns 1 if you win, returns 0 if game is still going */
int moveFarmer(char board[10][10], int boardHeight, int boardWidth, char farmer);
/* restartGame()
** Inputs: None
** Returns true if the user wants to play another game,
** returns false if the user does not want to play another game */
bool restartGame();

int main(){

  // constant variables
  const char welcomeMessage[] = {"Welcome to Chase the Rabbit!"};
  const char endGame[] = {"You've caught the rabbit!"};
  const int BOARD_HEIGHT = 10;
  const int BOARD_WIDTH = 10;
  const char FARMER_SYMBOL = 'F';
  const char RABBIT_SYMBOL = 'R';

  // controls if the user wants to play multiple times
  do{
    // declares and initializes the game board
    char board[BOARD_HEIGHT][BOARD_WIDTH] = {};
    // fills the board with empty spaces and shows the welcome message
    initializeGame(board, BOARD_HEIGHT, BOARD_WIDTH, welcomeMessage);
    // gets the initial position of the farmer from the user
    giveFarmerInitialPosition(board, BOARD_HEIGHT, BOARD_WIDTH, FARMER_SYMBOL);
    // gives the rabbit a random position on the board
    giveRabbitInitialPosition(board, BOARD_HEIGHT, BOARD_WIDTH, RABBIT_SYMBOL);
    
    //tag to keep the game going
    bool continueTheGame = true;
    //game loop
    while(continueTheGame){
      //moves the farmer and rabbit, checks if the game is over or not
      if(moveFarmer(board, BOARD_HEIGHT, BOARD_WIDTH, FARMER_SYMBOL) == 1 ||
	 moveRabbit(board, BOARD_HEIGHT, BOARD_WIDTH, RABBIT_SYMBOL, FARMER_SYMBOL) == 1){
	continueTheGame = false; //game is over
      }else{
	// prints the board
	printBoard(board, BOARD_HEIGHT, BOARD_WIDTH);
	// prints what direction the rabbit is in
	getDistanceFromRabbit(board, BOARD_HEIGHT, BOARD_WIDTH, FARMER_SYMBOL, RABBIT_SYMBOL);
      }
    }
    cout << endGame << endl;
  }while(restartGame() == true); //asks user if they want to play again or not
  return 0;
}

bool restartGame(){

  const char validAnswers[] = {'y', 'n'};
  const int answers_length = 2;
  const char restart[] = {"Would you like to play again? (y/n): "};
  char answer = ' ';
  bool invalidAnswer = true;
  bool returner = true;
  while(invalidAnswer == true){
    invalidAnswer = false;
    cout << restart;
    cin >> answer; //gets answer if users wants to restart game
    if(answer == validAnswers[0]){
      returner = true; // wants to restart game
    }else if(answer == validAnswers[1]){
      returner = false; //wants to end the game
    }else{
      invalidAnswer = true; //asks user again for a valid input
    }
  }
  return returner;
}

void initializeGame(char board[10][10], int boardHeight,
		    int boardWidth, const char welcomeMessage[]){
  //puts spaces into the board
  for (int i = 0; i < boardHeight; i++){
    for (int j = 0; j < boardWidth; j++){
      board[i][j] = ' '; //sets the space to empty
    }
  }
  cout << welcomeMessage << endl; //prints welcome message
}

void printBoard(char board[10][10], int boardHeight, int boardWidth){
  //prints the board
  for(int i = 0; i < boardHeight; i++){
    for (int j = 0; j < boardWidth; j++){
      cout << "|" << board[i][j]; //adds border
    }
    //goes onto next line
    cout << "|" << endl;
  }
}

void updateFarmerPosition(int yPos, int xPos, char board[10][10], char symbol){
  board[xPos][yPos] = symbol; //sets x,y on board to farmer char
}

void updateRabbitPosition(int yPos, int xPos, char board[10][10], char symbol){
  board[xPos][yPos] = symbol; //sets x,y on board to rabbit char
}

void getDistanceFromRabbit(char board[10][10], int boardHeight, int boardWidth,
			   char farmer, char rabbit){
  int farmerRow = 0;
  int farmerCol = 0;
  int rabbitRow = 0;
  int rabbitCol = 0;
  for(int i = 0; i < boardHeight; i++){
    for(int j = 0; j < boardWidth; j++){
      if(board[i][j] == farmer){ //if this space on the board is the farmer
	farmerRow = i; //set the x and y
	farmerCol = j;
      }else if(board[i][j] == rabbit){ //if the space on the board is the rabbit
	rabbitRow = i; //set the x and y
	rabbitCol = j;
      }
    }
  }
  
  int distanceY = farmerRow - rabbitRow; //north and south distance
  int distanceX = farmerCol - rabbitCol; //east and west distance
  const int AMNT = 4;
  const int LENG = 40;
  const char directionOutput[AMNT][LENG] = {{"The rabbit is north of the farmer."},
					    {"The rabbit is south of the farmer."},
					    {"The rabbit is west of the farmer."},
					    {"The rabbit is east of the farmer."}};
  //checks if north/south distance is larger than east/west distance
  if(abs(distanceY) > abs(distanceX)){
    if(distanceY > 0){ //if the distance is greater than 0, it's north
      cout << directionOutput[0] << endl;
    }else{ //otherwise it's south
      cout << directionOutput[1] << endl;
    }
    // checks if east/west distance is larger than north/south distance
  }else if(abs(distanceY) <= abs(distanceX)){
    if(distanceX > 0){ //west distance (> 0)
      cout << directionOutput[2] << endl;
    }else{ //east distance (< 0)
      cout << directionOutput[3] << endl;
    }
  }
}


void giveFarmerInitialPosition(char board[10][10], int boardHeight, int boardWidth, char symbol){
  
  const char X_MESSAGE[] = {"Enter the farmer's starting column. "};
  const char Y_MESSAGE[] = {"Enter the farmer's starting row. "};
  int tempCoordX = -1;
  int tempCoordY = -1;
  // gets the column to start in, making sure it's a valid input
  while(tempCoordX < 0 || tempCoordX >= boardWidth){
    cout << X_MESSAGE << "(0 to " << boardWidth - 1 << "): ";
    cin >> tempCoordX;
  }
  // gets the row to start in, making sure it's a valid input
  while(tempCoordY < 0 || tempCoordY >= boardHeight){
    cout << Y_MESSAGE << "(0 to " << boardHeight - 1 << "): ";
    cin >> tempCoordY;
  }
  //updates the farmer's initial position onto the board
  updateFarmerPosition(tempCoordX, tempCoordY, board, symbol);
}

void giveRabbitInitialPosition(char board[10][10], int boardHeight, int boardWidth, char symbol){

  const char EMPTY_SPACE = ' ';
  int row = 0;
  int col = 0;
  
  //seeds the random number generator
  srand(time(NULL));

  //gets a random integer in range of the board height or width
  do{
    row = rand() % boardWidth; //random row
    col = rand() % boardHeight; //random column
  }while(board[row][col] != EMPTY_SPACE);
  // ^^ if the rabbit is at the same place as the farmer
  board[row][col] = symbol; //puts the rabbit onto the board
}

int moveFarmer(char board[10][10], int boardHeight, int boardWidth, char farmer){
  
  const int COUNT = 4;
  const int LENGTH = 9;
  const int MIN_ANS = 1;
  const int MAX_ANS = 4;
  const char EMPTY_SPACE = ' ';
  const char menu[COUNT][LENGTH] = {{"Go north"}, {"Go east "}, {"Go south"}, {"Go west "}};
  const char question[] = {"Enter the number for the direction you want to search: "};
  const char INVALID_MOVE[] = {"You cannot move that way, please enter a valid move."};
  
  int farmerRow = 0;
  int farmerCol = 0;
  //finds the farmer's row and column
  for(int i = 0; i < boardHeight; i++){
    for(int j = 0; j < boardWidth; j++){
      if(board[i][j] == farmer){
	farmerRow = i;
	farmerCol = j;
      }
    }
  }
  
  int direc = 0;
  //prints the menu and asks the user where they would like to go
  while((direc < MIN_ANS) || (direc > MAX_ANS)){
    for(int i = 0; i < COUNT; i++){
      cout << i+1 << ". " << menu[i] << endl; //menu printing
    }
    cout << question;
    cin >> direc; //the input for direction
  }

  const char moveArray[4][7] = {{"north "}, {"east  "}, {"south "}, {"west  "}};
  bool invalidMove = false;
  int move = -1;
  board[farmerRow][farmerCol] = ' '; //sets the space where the farmer 
  // moves FROM to an empty space
  switch(direc){
  case 1: //the north case
    if(farmerRow - 1 >= 0){
      farmerRow--; //compensates for move north
      move = 0; //for printing purposes
    }else{
      invalidMove = true;
    }
    break;
  case 2: //the east case
    if(farmerCol + 1 <= boardWidth - 1){
      farmerCol++; //move east
      move = 1; //printing
    }else{
      invalidMove = true;
    }
    break;
  case 3: //the south case
    if(farmerRow + 1 <= boardHeight - 1){
      farmerRow++; //move south
      move = 2; //printing
    }else{
      invalidMove = true;
    }
    break;
  case 4: //the west case
    if(farmerCol - 1 >= 0){
      farmerCol--; //move west
      move = 3; //printing
    }else{
      invalidMove = true;
    }
    break;
  }

  const char invalMove[] = {"You aren't allowed to move that way."};
  const char farmerMoves[] = {"The farmer moves "};
  if(invalidMove == true){
    /* if it was determined that the move the user tried to make is
       not valid, it will print it's invalid. User will not move. */
    cout << invalMove << endl;
  }else if(board[farmerRow][farmerCol] != EMPTY_SPACE){
    /* if the new space is not empty (the rabbit's position), it replaces
    ** the position with the farmer and returns 1 to signify the game 
    ** has been won. */
    board[farmerRow][farmerCol] = farmer;
    cout << farmerMoves << moveArray[move] << endl;
    return 1;
  }
  /* puts farmer into the new position and returns 0 signifying the game
  ** is still in progress. */
  board[farmerRow][farmerCol] = farmer;
  cout << farmerMoves << moveArray[move] << endl;
  return 0;
  
}

int moveRabbit(char board[10][10], int boardHeight, int boardWidth, char rabbit, char farmer){
  int row = -1;
  int col = -1;
  //finds the rabbit's position.
  for(int i = 0; i < boardHeight; i++){
    for(int j = 0; j < boardWidth; j++){
      if(board[i][j] == rabbit){
	row = i; //rabbit row
	col = j; //rabbit column
      }
    }
  }
  const int MAX = 5;
  const int MIN = 1;
  int direc = (rand() % (MAX + 1 - MIN)) + MIN; 
  //creates a random direction for the rabbit to move
  board[row][col] = ' ';  //makes the rabbit's old space into an empty space
  const char noMove[] = {"The rabbit nibbles on some food and does not move."};
  const char moved[] = {"The rabbit moves to another location in search of food."};
  switch(direc){
  case 1: // case north
    if(row - 1 >= 0){
      cout << moved << endl; //prints the rabbit moved
      row--; //compensates for new position
    }else{
      cout << noMove << endl; //prints the rabbit did not move
    }
    break;
  case 2: // case east
    if(col + 1 <= boardWidth - 1){
      cout << moved << endl;
      col++;
    }else{
      cout << noMove << endl;
    }
    break;
  case 3: // case south
    if(row + 1 <= boardHeight - 1){
      cout << moved << endl;
      row++;
    }else{
      cout << noMove << endl;
    }
    break;
  case 4: // case west
    if(col - 1 >= 0){
      cout << moved << endl;
      col--;
    }else{
      cout << noMove << endl;
    }
    break;
  case 5:
    cout << noMove << endl;
    break;
  }
  // if the rabbit moves into the farmer
  if(board[row][col] == farmer){
    board[row][col] = farmer; //replace the rabbit's icon with the farmer's
    return 1; // return 1, the game has been won.
  }
  // sets the new position to the rabbit
  board[row][col] = rabbit;
  return 0; // return 0, the game is still in progress.
  
}
