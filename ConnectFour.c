/********DO NOT MODIFY THIS SECTION************
 * 
 * EECS 22 : Advanced C Programming
 * Fall 2018, Prof. Quoc-Viet Dang
 * 
 * HW1  : ConnectFour game
 * Template file : ConnectFour.c
 * 
 * Created on September 26, 2018, 12:06 AM by Ali Nickparsa <anickpar@uci.edu>
 */
/**********************************************
 
// Enter your name, last name and UCInet ID below://
 * 
 * *****************************
 * First Name :Jaeven 
 * Last Name:Laron
 * UCInet ID:23157357
 *
 */

#include <stdio.h>
#include <stdlib.h>
/*Declare your function definitions in the section below*/
/*Mandatory Options : 1-DisplayMenu 2- RegularGame 3-AnvilGame 4-CheckConnect 5-PrintBoard*/
/*You may add other functions if needed*/
/*********************************************************/
int displayMenu(void);
int printBoard(void);
int startBoard(void);
int checkConnect(void);
int regularGame(void);
int regularColor(void);
int anvilGame(void);
int anvilColor(void);
int printColor(void);
/*********************************************************/

/*Declare your global variables below (if any)*/
/**************************************************/
int board[6][7];
const int boardWidth = 7;
const int boardLength = 6;
int i, j;
int counter = 0;
int userCoordinate;
int conditional;
int win =0;
int checkAnvilOne = 0;
int checkAnvilTwo = 0;
int displayConditional;
int fullBoardCheck = 0;
char gameType;
char colorType;

/**************************************************/

/*Colors (you can add or remove from this list*/
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


/*Main function*/
int main(int argc, char** argv) {
	char postGame;
	int quit =0 ;
	while(quit != 1){
	if(quit == 1){
	break;
	}
	win = 0;
	displayMenu();
/*This asks the user which type of game they would like to play */
	if((gameType == 'r'|| gameType == 'R')&&(colorType == 'n'|| colorType == 'N')){
		regularGame();
		printf("Enter 'n' for new game or 'e' for exit:");
		scanf(" %c",&postGame);
		getchar();
		printf("\n");
		if(postGame=='n'||postGame=='N'){
			printf("Newgame");
			continue;	
		}
		else if(postGame=='e'||postGame=='E'){
                        quit = 1;
			break;
                }	
	}
	else  if((gameType == 'a'|| gameType == 'A')&&(colorType == 'n'||colorType =='N')){
		anvilGame();
		printf("Enter 'n' for new game or 'e' for exit:");
		scanf(" %c",&postGame);
		getchar();
		if(postGame=='n'||postGame=='N'){
			printf("New Game");
			continue;
		}
		else if(postGame=='e'||postGame=='E'){
                        quit = 1;
			break;
                }	
	}
	 else  if((gameType == 'r'|| gameType == 'R')&&(colorType == 'c'||colorType =='C')){
                regularColor();
                printf("Enter 'n' for new game or 'e' for exit:");
                scanf(" %c",&postGame);
                getchar();
         	       if(postGame=='n'||postGame=='N'){
                        printf("New Game");
			continue;
                }
		else if(postGame=='e'||postGame=='E'){
                        quit = 1;
			break;
                }
        }
	else  if((gameType == 'a'|| gameType == 'A')&&(colorType == 'c'||colorType =='C')){
                anvilColor();
                printf("Enter 'n' for new game or 'e' for exit:");
                scanf(" %c",&postGame);
                getchar();
                if(postGame=='n'||postGame=='N'){
                        printf("New Game");
			continue;
                }
		else if(postGame=='e'||postGame=='E'){
			quit = 1;
			break;
		}

        }
	
 	}          
    return 0;
}

int anvilGame(void){
	startBoard();
        printBoard();
	win = 0;
	counter = 1;
	checkAnvilOne = 0;
	checkAnvilTwo = 0;
        while(win != 1){
                if(counter%2==0){
                         conditional = 1;
                        while(conditional==1){
                                printf("Player 2 (O):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth+1 || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
				if(userCoordinate==8 && checkAnvilTwo != 0){
                                        printf("Anvil Checker Used Already!\n");
                                        continue;
                                }
                                /*Anvil Checker*/
                                if(userCoordinate==8){
                                        while(conditional == 1){
                                                checkAnvilTwo = 1;
                                                printf("You have selected the anvil.\n");
                                                printf("Select which column to place it in:");
                                                scanf("%d",&userCoordinate);
                                                if(userCoordinate > boardWidth+1 || userCoordinate < 0){
                                                        printf("\nInvalid Coordinate. Try Again.\n");
                                                        continue;
                                                }
                                                for(i=0;i<boardLength;i++){
                                                        if(board[i][userCoordinate-1]!=0 || board[i][userCoordinate-1]!=3){
                                                                board[i][userCoordinate-1]= 0;
                                                                conditional=0;
                                                        }
                                                }
                                                for(i=7;7-i<boardWidth;i--){
                                                        if(board[i-1][userCoordinate-1]== 0){
                                                                board[i-1][userCoordinate-1]= 3;
                                                                conditional=0;
                                                                break;
                                                        }
                                                }
                                        }
                                        continue;
                                }
                                for(i= 7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1] = 2;
                                                conditional = 0;
                                                break;
                                        }

                                }
                                if(i == 0){
                                printf("\nColumn Full,Please Try Again.\n");
                                }
                        }
                }
                else{
                        conditional = 1;

                        while(conditional==1){
                                printf("Player 1 (X):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth+1 || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
				if(userCoordinate==8 && checkAnvilOne != 0){
					printf("Anvil Checker Used Already!\n");
					continue;
				}
				/*Anvil Checker*/
				if(userCoordinate==8){
					while(conditional == 1){
						checkAnvilOne = 1;
						printf("You have selected the anvil.\n");
						printf("Select which column to place it in:");
						scanf("%d",&userCoordinate);
						if(userCoordinate > boardWidth+1 || userCoordinate < 0){
                                        		printf("\nInvalid Coordinate. Try Again.\n");
                                        		continue;
						}
						for(i=0;i<boardLength;i++){
                                        		if(board[i][userCoordinate-1]!=0 && board[i][userCoordinate-1]!=3){
								board[i][userCoordinate-1]= 0;
                                                		conditional=0;
        
							}
						}
						for(i=7;7-i<boardWidth;i--){
                                                	if(board[i-1][userCoordinate-1]==0){
                                                        	board[i-1][userCoordinate-1]= 3;
                                                        	conditional=0;
                                                        	break;
                                                	}
                                        	}
					}
					continue;
				}
                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 1;
                                                conditional=0;
                           
                                                break;
                                        }
                                }
                                if(i==0){
                                printf("\nColumn Full, Please Try again\n");
                                }
                                }

                }
                checkConnect();
                printBoard();
		/*Check to see if board is full*/
                if(counter==(3*boardLength*boardWidth)){
			printf("Player 2 Wins");
                	break;
                }
                if(win == 1){
                        break;
                }
	counter++;
        }	
	return 0;
}

int anvilColor(void){
	startBoard();
        printBoard();
	win = 0;
	counter = 1;
	checkAnvilOne = 0;
	checkAnvilTwo = 0;
        while(win != 1){
                if(counter%2==0){
                         conditional = 1;
                        while(conditional==1){
                                printf("Player 2 (O):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth+1 || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
				if(userCoordinate==8 && checkAnvilTwo != 0){
                                        printf("Anvil Checker Used Already!\n");
                                        continue;
                                }
                                /*Anvil Checker*/
                                if(userCoordinate==8){
                                        while(conditional == 1){
                                                checkAnvilTwo = 1;
                                                printf("You have selected the anvil.\n");
                                                printf("Select which column to place it in:");
                                                scanf("%d",&userCoordinate);
                                                if(userCoordinate > boardWidth+1 || userCoordinate < 0){
                                                        printf("\nInvalid Coordinate. Try Again.\n");
                                                        continue;
                                                }
                                                for(i=0;i<boardLength;i++){
                                                        if(board[i][userCoordinate-1]!=0 && board[i][userCoordinate-1]!=3){
                                                                board[i][userCoordinate-1]= 0;
                                                                conditional=0;
                                                        }
                                                }
                                                for(i=7;7-i<boardWidth;i--){
                                                        if(board[i-1][userCoordinate-1]==0){
                                                                board[i-1][userCoordinate-1]= 3;
                                                                conditional=0;
                                                                break;
                                                        }
                                                }
                                        }
                                        continue;
                                }

                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 2;
                                                conditional = 0;
                                                break;
                                        }
                                }
                                if(i==0){
                                printf("\nColumn Full,Please Try Again.\n");
                                }
                        }
                }
                else{
                        conditional = 1;
                        while(conditional==1){
                                printf("Player 1 (X):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth+1 || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
                                if(userCoordinate==8 && checkAnvilOne != 0){
                                        printf("Anvil Checker Used Already!\n");
                                        continue;
                                }
                                /*Anvil Checker*/
                                if(userCoordinate==8){
                                        while(conditional == 1){
                                                checkAnvilOne = 1;
                                                printf("You have selected the anvil.\n");
                                                printf("Select which column to place it in:");
                                                scanf("%d",&userCoordinate);
                                                if(userCoordinate > boardWidth+1 || userCoordinate < 0){
                                                        printf("\nInvalid Coordinate. Try Again.\n");
                                                        continue;
                                                }
                                                for(i=0;i<boardLength;i++){
                                                        if(board[i][userCoordinate-1]!=0 && board[i][userCoordinate-1]!=3){
                                                                board[i][userCoordinate-1]= 0;
                                                                conditional=0;
                                                        }
                                                }
                                                for(i=7;7-i<boardWidth;i--){
                                                        if(board[i-1][userCoordinate-1]==0){
                                                                board[i-1][userCoordinate-1]= 3;
                                                                conditional=0;
                                                                break;
                                                        }
                                                }
                                        }
                                        continue;
                                }

                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 1;
                                                conditional=0;
                                                break;
                                        }
                                }
                                if(i==0){
                                printf("\nColumn Full, Please Try again\n");
                                }
                                }

                }
                checkConnect();
                printColor();
                if(counter==(3*boardLength*boardWidth)){
                        printf("Player 2 Wins");
                        break;
                }
                if(win == 1){
                        break;
                }
	counter++;
        }
        return 0;
}

int regularGame(void){
	startBoard();
	printBoard();
	win = 0;
	counter = 1;
	 while(win != 1){
                if(counter%2==0){
                     	 conditional = 1;
                        while(conditional==1){
                                printf("Player 2 (O):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 2;
                                                conditional = 0;
                                                break;
                                        }

                                }
                                if(i==0){
                                printf("\nColumn Full,Please Try Again.\n");
                                }
                        }
                }
                else{
                        conditional = 1;

                        while(conditional==1){
                                printf("Player 1 (X):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 1;
                                                conditional=0;
                                                break;
                                        }
                                }
                                if(i==0){
                                printf("\nColumn Full, Please Try again\n");
                                }
                                }

                }
                checkConnect();
                printBoard();
		if(counter==(boardLength*boardWidth)){
                        printf("Player 2 Wins");
                        break;
                }
                if(win == 1){
                	break;
                }
	counter++;
	}
	return 0;
}

int regularColor(void){
	startBoard();
        printColor();
	counter = 1;
	win = 0;
         while(win != 1){
                if(counter%2==0){
                         conditional = 1;
                        while(conditional==1){
                                printf("Player 2 (O):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 2;
               
                                                conditional = 0;
                                                break;
                                        }

                                }
                                if(i==0){
                                printf("\nColumn Full,Please Try Again.\n");
                                }
                        }
                }
                else{
                        conditional = 1;

                        while(conditional==1){
                                printf("Player 1 (X):\n");
                                printf("Enter Coordinate Number:");
                                scanf(" %d",&userCoordinate);
                                if(userCoordinate == 0){
                                exit(0);
                                }
                                if(userCoordinate >boardWidth || userCoordinate<0){
                                        printf("\nInvalid Coordinate. Try Again.\n");
                                        continue;
                                }
                                for(i=7;7-i<boardWidth;i--){
                                        if(board[i-1][userCoordinate-1]==0){
                                                board[i-1][userCoordinate-1]= 1;
                                                conditional=0;
                                            
                                                break;
                                        }
                                }
                                if(i==0){
                                printf("\nColumn Full, Please Try again\n");
                                }
                                }

                }
                checkConnect();
                printColor();
                if(counter==(boardLength*boardWidth)){
                        printf("Player 2 Wins");
			break;
                }
                if(win == 1){
                        break;
                }
	counter++;
        }
        return 0;
}

int checkConnect(void){
/*Checks Horizontal Win*/
                for(i=0;i<boardLength;i++){
                        for(j=0;j<boardWidth-3;j++){
                                if(board[i][j] != 0 && board[i][j] == 1 && board[i][j]==board[i][j+1] &&board [i][j]==board[i][j+2] && board[i][j]==board[i][j+3]){
                                        printf("\nPlayer 1 winner!\n");
					win = 1;
                                }
				else if(board[i][j] != 0 && board[i][j] == 2 && board[i][j]==board[i][j+1] &&board [i][j]==board[i][j+2] && board[i][j]==board[i][j+3]){
                                        printf("\nPlayer 2 winner!\n");
                                        win = 1;
                                }

                        }
                }
/*Checks Vertical Winner*/
                 for(i=0;i<boardLength-3;i++){
                        for(j=0;j<boardWidth;j++){
                                if(board[i][j] != 0 && board[i][j] == 1 && board[i][j]==board[i+1][j] &&board [i][j]==board[i+2][j] && board[i][j]==board[i+3][j]){
                                        printf("\nPlayer 1 winner!\n");
					win = 1;
                                }
				if(board[i][j] != 0 && board[i][j] == 2 && board[i][j]==board[i+1][j] &&board [i][j]==board[i+2][j] && board[i][j]==board[i+3][j]){
                                        printf("\nPlayer 2 winner!\n");
                                        win = 1;
                                }
                        }

                }
/*Checks Right Diagonal Winner*/
                for(i=0;i<boardLength-3;i++){
                        for(j=0;j<boardWidth-3;j++){
                                if(board[i][j] != 0 && board[i][j] == 1 && board[i][j]==board[i+1][j+1] &&board [i][j]==board[i+2][j+2] && board[i][j]==board[i+3][j+3]){
                                        printf("\nPlayer 1 winner!\n");
					win = 1;
                                }
				 if(board[i][j] != 0 && board[i][j] == 2 &&  board[i][j]==board[i+1][j+1] &&board [i][j]==board[i+2][j+2] && board[i][j]==board[i+3][j+3]){
                                        printf("\nPlayer 2 winner!\n");
                                        win = 1;
                                }
                        }

                }
/*Checks Left Diagonal Winner*/
                for(i=0;i<boardLength-3;i++){
                        for(j=3;j<boardWidth;j++){
                                if(board[i][j] != 0 && board[i][j] == 1 &&  board[i][j]==board[i+1][j-1] &&board [i][j]==board[i+2][j-2] && board[i][j]==board[i+3][j-3]){
                                        printf("\nPlayer 1 winner!\n");
					win = 1;
                                }
				if(board[i][j] != 0 && board[i][j]== 2 &&  board[i][j]==board[i+1][j-1] &&board [i][j]==board[i+2][j-2] && board[i][j]==board[i+3][j-3]){
                                        printf("\nPlayer 2 winner!\n");
                                        win = 1;
                                }

                        }
                }
	return 0;
}

int displayMenu(void){
        printf("        *      %s EECS 22%s CONNECT 4 GAME          * \n",KRED,KNRM);
        printf("Please select the type of game you would like to play: \n ");
        printf("1-(R): Regular Game \n " );
        printf("2-(A): Anvil Game \n ");
        printf("Please enter 'R' or 'A':");
	scanf(" %c",&gameType);
	getchar();
	if(gameType == 'r'|| gameType == 'R'){
		printf("You have chosen a regular game.\n");
	}
	else if(gameType == 'a'|| gameType=='A'){
		printf("You have chose an Anvil game.\n");
	}
	printf("Please enter:\n");
	printf("'n' for normal game\n");
	printf("'c' for %sc%so%sl%so%sr%se%sd%s game\n",KMAG,KRED,KGRN,KBLU,KYEL,KCYN,KRED,KNRM);
	scanf(" %c",&colorType);
	getchar();
return 0;
}

int printBoard(void){
	for(i= 0;i < boardLength;i++){
                for(j= 0;j < boardWidth;j++){
			if(board[i][j]== 0){
				if(j== 6){
					printf("| |\n");
				}
				else{
					printf("| ");
				}
			}
			else if(board[i][j]== 1){
				if(j==6){
                                        printf("|X|\n");
                                }
                                else{
                                        printf("|X");
                                }
			}
			else if(board[i][j]== 2){
				if(j== 6){
                                        printf("|O|\n");
                                }
                                else{
                                        printf("|O");
                                }
			}
			else if(board[i][j]== 3){
                                if(j==6){
                                        printf("|A|\n");
                                }
                                else{
                                        printf("|A");
                                }
                        }

		}
		printf("-------------------------\n");
	}
	printf(" 1 2 3 4 5 6 7\n\n");
	return 0;
}

int printColor(void){
	for(i=0;i<boardLength;i++){
                for(j=0;j<boardWidth;j++){
                        if(board[i][j]==0){
                                if(j==6){
                                        printf("| |\n");
                                }
                                else{
                                        printf("| ");
                                }
                        }
                        else if(board[i][j]==1){
                                if(j==6){
                                        printf("|%sX%s|\n",KRED,KNRM);
                                }
                                else{
                                        printf("|%sX%s",KRED,KNRM);
                                }
                        }
                        else if(board[i][j]==2){
                                if(j==6){
                                        printf("%s|O|%s\n",KBLU,KNRM);
                                }
                                else{
                                        printf("%s|O%s",KBLU,KNRM);
                                }
                        }
                        else if(board[i][j]==3){
                                if(j==6){
                                        printf("%s|A|%s\n",KMAG,KNRM);
                                }
                                else{
                                        printf("%s|A%s",KMAG,KNRM);
                                }
                        }

                }
                printf("-------------------------\n");
        }
        printf(" 1 2 3 4 5 6 7\n\n");
	return 0;
}


int startBoard(void){
 	for(i=0;i<boardLength;i++){
                for(j=0;j<boardWidth;j++){
                        board[i][j]=0;
                }
        }
	return 0;
}


