#include <stdio.h>
#include "menu.h"

void displayMenu(void)
{
    //print options to terminal for user
    printf("Menu\n");
    printf("1. Display board\n");
    printf("2. Load board from a file\n");
    printf("3. Edit list\n");
    printf("4. Edit Board\n");
    printf("5. Save board to a file\n");
    printf("6. Quit\n\n");
}

int userChoice(void)
{
    //declare variable which will be returned
    int choice;

    //enter loop to ensure user picks valid input
    do{
        printf("Enter your choice (1-5):");

        scanf("%d", &choice);

        if(choice<1 || choice>6)
        {
            //print statement if user doesn't enter correct input
            printf("Invalid input. Please try again.\n");
        }

    }while(choice<1 || choice>6);//exit once valid input is entered

    printf("\n");

    //return choice input by user
    return choice;
}