/* Adrien Mery
 * Pascal triangle drawing algorithm
*/

// declare the necessary libraries:
#include <stdio.h>
#include <stdbool.h>

// create a factorial function which output the factorial of the input
int factorial(int k){
// define an internal variable "fact" that will be the output of the function
    int fact = 1;
// calculate the factorial recursively
    for(int i = 0; i < k; i++)
        fact = fact * (k - i);
// output the factorial
    return fact;
}

// create a choose function which outputs the combination n choose r
int choose(int n, int r){
// define an internal variable "combi" that will be the output of the function
    int combi;
// calculate the necessary combination
    combi = (factorial(n) / (factorial(r) * factorial(n - r)));
// output the combination
    return combi;
}

// create a spaces function to calculate the number of spaces to put between each combination in the Pascal Triangle
void printSpace(int space){
// prints spaces while the number of current spaces is not at the necessary number
    for(int i = 0; i < space; i++)
        printf(" ");
}

// create a triangle function to print the Pascal Triangle with the correct number of rows
void triangle(int rows){
// print the first row of the Pascal Triangle
    printSpace(3 * (rows - 1));
    printf("1");

// continue while the number of current rows has not reached the desired number of rows
    for(int n = 0; n < rows; n++) {
//print a row of the triangle, with the correct combinations and spaces
        for(int r = 0; r < n; r++) {
            if(r == 0)
                printSpace(3 * (rows - n - 1));
        printf("%d", choose(n, r));
        if(choose(n, r) >= 100)
            printSpace(3);
        else if(choose(n, r) >= 10)
            printSpace(4);
        else
            printSpace(5);
        }
        if(n > 0)
            printf("1");
        printf("     \n");
    }
}

// declare the main function with the default parameters
int main(int argc, char** argv){
    bool again = true;
// play again while the input is not < 0
    while (again == true){
// create an input variable with the number of rows, print a request and scan for its value
        int input;
        printf("Enter the number of rows: ");
        scanf("%d", &input);
// output a triangle only if the input is > 0
        if(input > 0)
            triangle(input);
// if input == 0, play again
        else if(input == 0)
            again = true;
// if input <= 0, exit the program
        else if(input < 0)
            again = false;
    }
}
