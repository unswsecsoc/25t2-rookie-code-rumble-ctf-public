#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// this C code is not the actual source code for the challenge, it is simply here to help understand
// what the MIPS code is doing.

int main() {
    unsigned int your_bid = 0;
    unsigned int rival_bid = 1;

    printf("2hollis is coming back to Sydney.\n");
    printf("But his tickets are selling fast, and there's only 1 ticket left.\n");
    printf("Due to the outrageous demand for it, it's going on auction!\n");
    printf("Try to outbid everyone to win the ticket.\n\n");

    while (1) {
        printf("Enter your bid: ");
        int input;
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        if (input < 0) {
            printf("Bids must be non-negative.\n");
            continue;
        }

        your_bid = (unsigned int) input; // having some fun with unsigned ints, surely there shouldn't be any issues with this

        if (your_bid <= rival_bid) {
            printf("Your bid must be higher than the highest bid ($%u).\n", rival_bid);
            continue;
        }

        rival_bid = your_bid + 1; // hehe they'll never win

        if (rival_bid < 0) { 
            printf("You win the auction! See you at the concert <2\n");
            printf("<FLAG>\n");
            break;
        } else {
            printf("You have been outbid! The highest bid is now $%u.\n\n", rival_bid);
        }
    }

    return 0;
}
