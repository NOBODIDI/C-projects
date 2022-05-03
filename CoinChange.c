/* Adrien Mery
 * Algorithm that inputs the number of cents
 * and outputs the coins used to make up that amount
 * with the minimum number of coins.
*/

// declare the necessary libraries:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* declare variables:
 * amount: number of cents to convert to coins
 * playAgain: determine whether the code should prompt the user for input again
 */
int amount = 1;
bool playAgain = true;

// declare the main function with the default parameters
int main(int argc, char **argv)
{
// prompt the user only if the amount entered was between the bounds at the previous input
   while (playAgain == true){
// print and scan for the "amount" to convert to coins
        printf("Please give an amount in cents less than 100: ");
        scanf("%d", &amount);

// converts to coins only if within the correct bounds
        if (amount > 0 && amount < 100){
// prints the number of cents to convert to coins
            printf("%d cents: ", amount);

// if the integer quotient of the amount to convert divided by 25 (value of a quarter) is > 0
                if (amount % 25 < 25 && ((int) amount / 25) > 0 && ((int) amount / 25) > 0){
// ...print the number of quarters necessary with the right grammar
                    if (((int) amount / 25) == 1)
                        printf("%d quarter", (int) amount / 25);
                    else if (((int) amount / 25) > 1)
                        printf("%d quarters", (int) amount / 25);
// ...substract the value of the quarters from the "amount" to convert to coins
                    amount -= ((int) amount / 25) * 25;
// ...if the "amount" is not 0, print a comma for the next coins
                    if (amount != 0)
                        printf(", ");
                }

// if the integer quotient of the amount to convert divided by 10 (value of a dime) is > 0
                if (amount % 10 < 10 && ((int) amount / 10) > 0 && ((int) amount / 10) > 0){
// ...print the number of dimes necessary with the right grammar
                    if (((int) amount / 10) == 1)
                        printf("%d dime", (int) amount / 10);
                    else if (((int) amount / 10) > 1)
                        printf("%d dimes", (int) amount / 10);
// ...substract the value of the dimes from the "amount" to convert to coins
                    amount -= ((int) amount / 10) * 10;
// ...if the "amount" is not 0, print a comma for the next coins
                    if (amount != 0)
                        printf(", ");
                }

// if the integer quotient of the amount to convert divided by 5 (value of a nickel) is > 0
                if (amount % 5 < 5 && ((int) amount / 5) > 0 && ((int) amount / 5) > 0){
// ...print the number of nickels necessary with the right grammar
                    if (((int) amount / 5) == 1)
                        printf("%d nickel", (int) amount / 5);
                    else if (((int) amount / 5) > 1)
                    printf("%d nickels", (int) amount / 5);
// ...substract the value of the nickelss from the "amount" to convert to coins
                    amount -= ((int) amount / 5) * 5;
// ...if the "amount" is not 0, print a comma for the next coins
                    if (amount != 0)
                        printf(", ");
                }
// if the amount to convert is > 0 and < 5
                if (amount < 5 && amount > 0){
// ...print the number of cents necessary with the right grammar
                    if (amount == 1)
                        printf("%d cent", amount);
                    else if (amount > 1)
                        printf("%d cents", amount);
                }
// ...if the "amount" is 0, print a dot to end the coin sequence
                if (amount % 1 == 0){
                    printf(".\n");
        }

        }
// if the "amount" to convert is zero, print "Goodbye"
        else if (amount == 0){
            printf("Goodbye\n");
            playAgain = false;

        }
// if the amount is not within the bounds, change the value of playAgain so that the prgm does not prompt user again
        else
            playAgain = false;
    }
        return 0;
}



