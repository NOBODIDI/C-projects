/* Adrien Mery
 * Blackjack game
*/

/* declare the necessary libraries:
 * time.h to obtain "random numbers"
 * stdlib.h for standard functions and expressions such as rand()
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare the main function with the default parameters
int main(int argc, char **argv)
{

	if(argc==1)
		srand(time(NULL));
	else
		srand(atoi(argv[1])); //obligatory for this lab

 /* Declare integer variables for this program:
 * playCd : Player card, initialized as a random value between 1 and 13
 * playWorth : Player's total points
 * dealCd : Dealer card, initialized as a random value between 1 and 13
 * dealWorth : Dealer's total points
 * playResp : Answer of the player for "hit", initialized as 1 for the first loop
 * cards: player and dealer cards after the first one
*/
    int dealCd = rand() %13+1;
    int playCd = rand() %13+1;
    int playWorth, dealWorth, cards;
    int playResp = 1;

    // print the opening statement with the initial player and dealer cards
	printf("First cards: player %d, dealer %d\n", playCd, dealCd);

    // convert the dealer card to a value and add it to the player worth in a separate variable
	if(dealCd >= 10)
		dealWorth = 10;
	else
		dealWorth = dealCd;
    // convert the player card to a value and add it to the player worth in a separate variable
	if(playCd >= 10)
		playWorth = 10;
	else
		playWorth = playCd;

    // checks that the player worth is not over 21 at the beginning of his turn
	while(playWorth <= 21 && playResp != 0 ){

        // prints and scans for the player response
		printf("Type 1 for Hit, 0 to Stay:");
		scanf("%d", &playResp);

        // in case of a "Hit"
		if(playResp == 1){

            // player gets one card
            cards = rand() %13+1;
            // convert the player card to a value and add it to the player worth in a separate variable
			if(cards >= 10)
				 playWorth += 10;
			else
				 playWorth += cards;

            // prints the player card and new player worth before the next turn
			printf("Player gets a %d, worth is %d\n", cards, playWorth);
		}
	}

    // check that the player worth is not over 21, if yes dealer does not need to play
	if(playWorth <= 21){
        // print statement to display dealer cards
        printf("Dealer gets:");

        //
		while(dealWorth < 17){ // replace by: while(dealWorth <= 21 && dealWorth < playWorth)
            // dealer gets one card
            cards = rand() %13+1;
            // convert the dealer card to a value and add it to the dealer worth in a separate variable
			if(cards >= 10)
				dealWorth += 10;
			else
				dealWorth += cards;

			// display the cards after the "Dealer gets:" print
			printf(" %d", cards);
		}

        // print a newline character to display game results
		printf("\n");
	}

	// print the different game results
	if(playWorth > 21)
		printf("Player over 21, Dealer wins\n");

	else if( dealWorth >= 21)
        printf("Dealer over 21, Player wins\n");

	else if( dealWorth > playWorth)
        printf("Dealer better than Player, Dealer wins\n");

	else
        printf("Tie!\n");

	return 0;
}
