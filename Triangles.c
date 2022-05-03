/* Adrien Mery
 * Triangle drawing algorithm
*/

// declare the necessary libraries:
#include<stdio.h>

// declare the main function with the default parameters
int main()
{

// declare "rows" to contain the number of rows of the triangle
    int rows;

// print and scan for the number of rows ("rows") of triangle to print
    printf("Enter the number of rows in the triangle: ");
    scanf("%d", &rows);
// print a newline character to start the triangle below the "rows" prompt
    printf("\n");

// loop continues while i (the present row nb) <= (the total nb of rows)
    for(int i = 1; i <= rows; i++){

// loop continues while j is <= (the total nb of rows) - (the present row nb)
        for(int j = 0; j <= rows - i; j++)
            printf(" ");

// loop continues while k is <= (the present row nb)*2 - 1,
        for(int k = 1; k <= i * 2 - 1; k++){

// different situations for printing a "*": at the top, on the side or on the bottom
            if (k == 1 || (k == i * 2 - 1) || i == rows )
                printf("*");
            else
                printf(" ");
        }
// print a newline after every row
        printf("\n");
    }

    return 0;
}
