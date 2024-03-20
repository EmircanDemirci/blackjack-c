#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void welcomeMessage();
void play();

void drawCard(char* cardType, int* sumOfCards ,  char** cards , int* cardCount , char** cardValues);//draw cards for create card
void displayCards(char** cards , int cardCount , char** cardValues);//for display all cards that we or computer get


int getOrPassChoice;//choice for get or pass card

int sumOfCards;//sum of cards int values
int sumOfCompCards;//sum of computers cards int value

//card types array
char* cardTypes[] = {"m", "ka", "s", "k"};


int main()
{
    //Oyunculara oyunun baþýnda 2 kart daðýtýlýr.
    //Daðýtýlan kartlar eðer 16 sayýsýndan küçükse oyuncu kart ister.
    //Oyuncunun elindeki kartlar 21 sayýsýný geçerse oyuncu kaybetmiþ olur.
    //Oyunda amaç 21 sayýsýna en yakýn olmak ama 21 sayýsýný geçmemektir.

    //welcome player
    welcomeMessage();


}

void welcomeMessage(){
    //players name that we get from player
    char* playerName[10];
    int choice;//choice for play or exit

    //welcome message
    printf("Welcome dear player, what's your name?\n");
    scanf("%s" , playerName);
    if(strlen(playerName)+1>10){
        //if player name characters is greater than 10 app automatically exits

        printf("\033[0;31m");//red text
        printf("Please create name less than 10 characters!!");
        printf("\033[0;37m");//white text

        exit(0);
    }
    else{
        //else

        sleep(1);

        printf("\033[0;36m");//cyan text
        printf("Welcome to the blackjack,%s \n" , playerName);//welcomming
        printf("\033[0;37m");//white text

        sleep(1);

        system("cls");//command line clear

        printf("What do you want to do?");//asking player to what to do
        printf("\n 1)Play \n 2)Exit \n");
        scanf("%d" , &choice);

        if(choice == 1){
            system("cls");
            sleep(1);
            play();
        }
        else{
            //Quitting
            system("cls");

            printf("\033[0;31m");//red text
            printf("OK %s goodbye for now!" , playerName);
            printf("\033[0;37m");//white text

            sleep(1);
            exit(0);
        }
    }
}

void play(){
    //card arrays for player and computer
    char* playerCards[10];//array that save 10 cards
    char* computerCards[10];
    char* playerCardValues[10];//card values for player
    char* computerCardValues[10];
    int playerCardCount = 0;//follows players card count
    int computerCardCount = 0;

    srand(time(NULL));
    int randomIndex = rand() % 4; // create a number between 0-3

    //players cards
    printf("\033[0;36m");
    char* playerCardType = cardTypes[randomIndex]; // Select random card type
    drawCard(playerCardType, &sumOfCards , playerCards , &playerCardCount , playerCardValues);
    printf("\033[0;37m");//white text


    //computers cards
    printf("\033[0;32m");
    char* computerCardType = cardTypes[randomIndex]; // select random card type
    drawCard(computerCardType, &sumOfCompCards,computerCards , &computerCardCount , computerCardValues);
    printf("\033[0;37m");//white text

    //while sumofCards<17 and sumOfCompCards<17
    while(sumOfCards<17 && sumOfCompCards<17){
        printf("Do you want to get or pass? (1 or 2?)");
        scanf("%d" , &getOrPassChoice);
        if(getOrPassChoice == 1){
            randomIndex = rand() % 4; //create random index between 0-3
            printf("\033[0;36m");
            playerCardType = cardTypes[randomIndex]; // select random card type
            drawCard(playerCardType, &sumOfCards , playerCards , &playerCardCount , playerCardValues);
            printf("Your Cards:");
            displayCards(playerCards, playerCardCount , playerCardValues);
            printf("\033[0;37m");//white text

            // computer gets card
            printf("\033[0;32m");
            randomIndex = rand() % 4; // create random card index between 0-3
            computerCardType = cardTypes[randomIndex]; // select random card type
            drawCard(computerCardType, &sumOfCompCards,computerCards , &computerCardCount , computerCardValues);
            printf("Computers Cards:");
            displayCards(computerCards, computerCardCount , computerCardValues);
            printf("\033[0;37m");//white text
        }
        else if(getOrPassChoice == 2){
            printf("\033[0;36m");
            printf("Your Cards:");
            displayCards(playerCards, playerCardCount , playerCardValues);
            printf("\033[0;37m");
            // computer gets card
            printf("\033[0;32m");
            randomIndex = rand() % 4; // create random card index between 0-3
            computerCardType = cardTypes[randomIndex]; // select random card type
            drawCard(computerCardType, &sumOfCompCards,computerCards , &computerCardCount , computerCardValues);
            printf("Computers Cards:");
            displayCards(computerCards, computerCardCount , computerCardValues);
            printf("\033[0;37m");
        }
    }
    if(sumOfCards>21 || sumOfCompCards>21){
        printf("\033[0;36m");
        printf("Blackjack!");
        printf("\033[0;37m");
    }
    else if(sumOfCards>sumOfCompCards){
        printf("\033[0;36m");
        printf("Player wins!");
        printf("\033[0;37m");
    }
    else if(sumOfCards==sumOfCompCards){
        printf("Draw!");
    }
    else if(sumOfCards<sumOfCompCards){
        printf("\033[0;32m");
        printf("Computer wins!");
        printf("\033[0;37m");
    }
}

void drawCard(char* cardType , int* sumOfCards , char** cards , int* cardCount , char** cardValues){
    int cardValue = rand() % 10 + 1; //rand card value


    printf("New Cards:%s%d\n" , cardType,cardValue);
    *sumOfCards += cardValue;

    cards[*cardCount] = (char*) malloc(10 * sizeof(char));
    cardValues[*cardCount] = (char*) malloc(10 * sizeof(char));
    //add card to computers or players cards
    strcpy(cards[*cardCount] , cardType);
    sprintf(cardValues[*cardCount], "%d" , cardValue);
    *cardCount +=1;
}

void displayCards(char** cards , int cardCount , char** cardValues){
    for(int i=0;i<cardCount;i++){
        printf("%s%s \t" , cards[i],cardValues[i]);
    }
    printf("\n");
}
