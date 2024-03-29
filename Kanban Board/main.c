#include <stdio.h>
#include "loadAndDisplay.h"
#include "menu.h"
#include "editItemInList.h"

int main(void)
{
    //initialize variable to hold user option
    int choice;

    //listPointer will automatically be assigned test data
    //this pointer will be able to be altered when it points to a new linkedList, which is not the test data
    Linked_List* listPointer = testData();

    //enter main loop which will keep running as long as user doesn't select 6 (quit)
    do{
        //function which will simply display the menu
        displayMenu();

        //receive choice
        choice=userChoice();

        if(choice==1)
        {
            //list is printed through function which needs the address of first node of linked list
            printList(listPointer);
        }
        else if(choice==2)
        {
            //load file function will be passed "0" which denotes that it will be opening the file for reading
            //pointer to open file stream is returned
            FILE* fp=loadFile(0);
            listPointer=createLinkedList(fp);

            //close file stream
            fclose(fp);
        }
        else if(choice==3)
        {
            //load function which takes in pointer to the linked list for editing
            editList(listPointer);
        }
        else if(choice==4)
        {
            // function which takes in pointer to the linked list and pointer to that pointer for editing
            editBoard(listPointer, &listPointer);
        }
        else if(choice==5)
        {
            //load file function will be passed "1" which denotes that it will be opening the file for writing
            //pointer to open file stream is returned
            FILE* fp=loadFile(1);
            //linked list and pointer to file passed which as a result prints linked list to file
            printList_toFile(listPointer, fp);

            //file stream is then closed through pointer which was passed to main function
            fclose(fp);
        }


    }while(choice!=6); //exit if user picks 6

    printf("Quiting...");

    return 0;
}

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣠⠤⠤⠴⠶⠒⠒⠒⠚⠋⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠤⠖⠒⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠤⠖⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⣤⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⢰⡟⢹⣆⣀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠴⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣼⠋⣿⡤⡀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣉⡟⢧⡼⢿⣹⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠖⠋⠁⠀⠀⢀⣤⣴⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠶⠋⠓⠋⠳⠃⠀⠀⠀⠀⠀⠀⠀⣶⣦⠉⠀⣶⡆⠀⢰⣶⡆⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠸⠽⠛⠞⠫⠂⠀⠀⠀⠀⠀⢠⣿⣿⣤⣼⣿⣤⣤⣿⣧⡄⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢼⣿⣦⣿⣷⣴⣿⡆⠀⠀⠀⠀⠀⣿⣿⣿⣿⠿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠛⢻⣿⣿⣿⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢸⣿⣿⠋⢻⣿⣿⠀⠀⠀⠀⠀⠀⣿⣿⣿⡇⠀⣿⣿⣿⣇⠀⠀⠀⠀⠀⢠⣿⣿⣿⡿⠀⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⢸⣿⣿⣦⣼⣿⣿⡆⠀⠀⠀⠀⠀⣿⣿⣿⣷⣶⣿⣿⣿⣿⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⡿⠿⠿⠿⣿⣿⣿⣿⣿⡿⠿⠿⠛⠻⠿⠿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⡇⠀⢰⣿⣿⣿⣿⣿⠀⠀⣾⣿⣿⣿⡟⠉⢀⣴⣶⣶⣶⣶⣄⢸⣿⣿⣿⡇⠀⢠⣶⣶⣶⣤⣀⠈⠹⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⠀⠀⣿⣿⣿⡟⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⡆⠀⠘⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⠀⠀⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⡇⠀⠸⣿⣿⣿⣿⣿⠀⠀⣿⣿⣿⣇⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢸⣿⣿⣿⣿⣿⡏⠀⢠⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⡀⠀⢿⣿⣿⣿⠟⠀⢠⣿⣿⣿⣿⣄⠀⠙⢿⣿⣿⣿⣿⠟⢸⣿⣿⣿⡇⠀⠸⣿⣿⣿⡿⠟⠀⣠⣾⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⣈⣉⣀⣤⣴⣿⣿⣿⣿⣿⣿⣷⣤⣄⣀⣉⣁⣠⣤⣾⣿⣿⣯⣥⣤⣤⣤⣤⣤⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⠿⢿⣿⣿⠿⣿⣿⣿⠿⣿⣿⠿⠿⠿⠿⣿⣿⡿⢿⣿⣿⣿⣿⠿⣿⣿⠿⢿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⣶⡀⢻⣿⠀⣿⣿⣿⠀⣿⣿⠀⠿⠟⠂⣼⣿⡇⢸⣿⣿⣿⣿⠀⣿⣿⠀⡄⠻⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠿⠿⠟⢀⣾⣿⡄⠹⠿⠟⢀⣿⣿⠀⠿⠿⠂⣸⣿⡇⠘⠿⠿⢿⣿⠀⣿⣿⠀⣿⣦⡈⠀⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⢶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢉⣴⣦⣈⡙⠛⠛⠛⠛⢛⣋⣩⣭⣥⣭⣍⣉⡙⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⣿⣿⣿⣦⣌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⠿⠿⠿⠛⠛⠋⠉⣠⡀⠀⢶⣄⠀⣠⡉⡙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣷⣶⣤⣤⠀⣤⡄⠀⢺⣦⠀⠙⣷⡄⠈⢿⣾⡟⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⠀⠈⢿⣆⠀⠻⣧⡀⠘⢿⣤⣾⡟⣰⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⠀⠀⠈⢻⣦⠀⠹⣷⡀⣸⣿⠏⣰⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⠀⠀⠀⠀⢻⣧⠀⢘⣿⣿⠏⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⡇⠀⠀⠀⠀⠹⣷⣾⣿⠏⢠⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⡀⠀⠀⠀⣰⣿⣿⠏⢠⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣷⡀⠀⣼⣿⣿⠏⢠⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣷⣄⠘⢿⠋⢀⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣧⣀⠀⠾⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⢦⣀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⡄⠈⠉⠀⠀⠀⠀⠀⠀⢀⡤⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⢤⣀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⢀⣠⠴⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠓⠲⠤⣄⣀⣀⣀⡤⠴⠖⠋⠉⠀⠀⠀



 77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
777777777777777777777777777777777777777777777777777777777777777?Y777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777YPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPY?777777YB777777777J5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5Y7777777777?J777777?YY55555555555555555555555555555555555YY?77777777777
777777777777777P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@G77777YB7777777Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P77777777YB777775PY?????????????????????????????????????YPP7777777777
77777777777777Y@@@@@@&B#######&@@@@@@&BBBBBBBBBGGG&@@@@@@@P7777YB777777?@@                                                        @@57777777YB77775G777777JYYYYYYYYJJJJJYYYYYYYYYYYYY?7777777PP777777777
77777777777777J@@@@@@@&&&&&&&&@@@@@@@@&&@@@@@@@@@@@@@@@@@@57777YB777777?@@    #BBB######################################&&&&&     @@Y7777777YB7777YB777777?JJJJJJJJJJJJJJJJJJJJJJJJJJ?7777777G5777777777
777777777777777Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&577777YB7777777J#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y77777777YB77777YG5JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ5P57777777777
77777777777777777?JYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYJ?7777777YB777777777?JYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYJ?7777777777YB7777777?JYYYYYYYYJYYYYYYYYYYYYYYYYYYYYYYYYYYJJ777777777777
777777777777777777777777777777777777777777777777777777777777777YB777777777777777777777777777777777777777777777777777777777777777777777777777YG777777777777777@J77777777777777777777777777777777777777777
777777777777777777777777777777777777777777777777777777777777777YB777777777777777777777777777777777777777777777777777777777777777777777777777YB77???JJJJJJJJ????@@@77777777777777777777777777777777777777
7777777777777777?JJJJJJJJJJJJJJJJJJJ777777777777777777777777777YB777777777777777777777777777777777777777777777777777777777777777777777@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@7777777777777777777777777777777777
777777777777777JP^^^^^^^^^^^:::::..P5?7777777777777777777777777YB777777777777777777777777777777777777777777777777777777777777777@@@@@@@@@@@?5B77777777777777J55@@@GY777777777777777777777777777777777777
777777777777777YY                  5PJ7777777777777777777777777YB7777777777777777777777????????????JJJJJJJ7777777777777777?@@@@@@@@@77777777YG777777777?????J@J??????JJJJJ?77777777777777777777777777777
777777777777777YY                  P5J7777777777777777777777777YB77777777777777777777?G~~~~~~~~~~~^^^^:::557777777777@@@@@@@@@77777777777777YB77777777P?~~~~~~~~~~~^^^^::^B?7777777777777777777777777777
777777777777777YJ                  G5J7777777777777777777777??7JB77777777777777777777JP                  JGJ7777@@@@@@@@@7777777777777777777YB77777777G:                  #Y?777777777777777777777777777
77777777777777757                  B5J7777777777777777777JYY7PY5B77777777777777777777JP :^^     .::.   . YP@@@@@@@@@777777777777777777777777YG!7777777G:    .        .   .#Y?777777777777777777777777777
777777777777777P!                  BYJ777777777777777?YY?~.   PBB77777777777777777777J5 . .~~^~^:. ^~^^. 5PJ77?77777777777777Y5YYYYYYY555555B#PGG?7777B.  ^:::~~^^^~:::^ .#Y?777777777777777777777777777
777777777777777G^            .~~:  BYJ77?JYJJY777?JYJ!:        P&J7777777777777777777YY                  P5J7777777777777777?@@@@@@@@@@@@@@@@@@@@5?777B.                 :BJ?777777777777777777777777777
777777777777777B.           :?  5  #YJJY7:  :BYYJ!:             5GJ?777777777777777775?.~::~~^^^~^:^.    G5J7777777777777777?@@@@@@@@@@@@@@@@@@@@PJ777B   ~^:^~^:^~^:^:  ^BY?777777777777777777777777777
777777777777777PJ77!!~~~~^~~G   J5JGPP~    7&!:                  YGY?7777777777777777P!           .      G5J7777777777777777?@@@@@@@@@@@@@@@@@@@@5J77?G                  ~BJ?777777777777777777777777777
77777777777777777??JJJJJJJJ5G   7G?GJ    .5Y57                    JG77777777777777777G^         .J:~7    BYJ7777777777777777?@@@@@@@@@@@@@@@@@@@@5J77?P                  !BJ?777777777777777777777777777
7777777777777777777777777J?7B.  .BP?    .G?775Y                    7P7777777777777777PJ!!~~^^^::5:  !Y~!7BYJ7777777777777777J@@@@@@@@@@@@@@@@@@@@YJ77?G!!~~^^^::::^^^~~!!PPY?777777777777777777777777777
777777777777777777777777P^?55?   7P     !P7777Y5                    YP777777777777?7@@??JJJJYYYY#    #YYJJ557777777777777777Y@@@@@@@@@@@@@@@@@@@@YJ7777?JJJJYYYYYYYYYYYYYJJJ?777777777777777777777777777
77777777777777777777777?G  Y5G.         .B77777Y5                :!JY?77777777?Y@@@@@@@@7777777G    YY7J5:^G7?JJ77777777777P@@@@@@@@@@@@@@@@@@@@YJ777777777777777777777777777777777777777777777777777777
777777777777777777777777B.  PB?          !P77777Y5           .^JGY?77777777?55P@@@@@77@@@77777?G    :G7G   JG5.:P?777777777G@@@@@@@@@@@@@@@@@@@&YJ777777777777777775JJJJJJJJJJJJJJJ???PJ7777777777777777
777777777777777777777777Y5   ~.           ?P77777Y5      :!JYYJYB77777777777J@@@@?777777777777?G     GB^   ^@.  ^G777777777JGBB###&&&&&&&&#&&BBGYY7777777777777777JG                  JPJ777777777777777
7777777777777777777777777P7                !P?7777J5:~J55?~^PJ7JB777777777@@@@@Y777777777777777G     ?Y    .#    G?777777777777777777777777YB77???7777777777777777JP                  YPJ777777777777777
77777777777777777777777777G~                .Y5J?JJ557:    7577YB777777?@@@@@7777777777777777777B            :    J57???????????J?7777777777YG77777777777777777777JP                  5PJ777777777777777
777777777777777777777777777G!                 .~!^.     .75J777YB7777@@@@@7777777777777JJJJ?77777B                 ^G!!!!!!!~~~~^^55777777777YB7777777777777777777Y5                  PPJ777777777777777
7777777777777777777777777777P7                        .75J77777JB@@@@@?77777777777777G^ .~7YYJ77B.                .J             ?GJ77777777YB777777777777777777775J                  G5J777777777777777
777777777777777777777777777775Y                     .?5J77777?@@@@@?77777777777777777YY.    .~?Y#.                 5             YGJ77777777YB77777777777777777777P7                  G5J777777777777777
77777777777777777777Y&&&&&&&&&@#                  .?5?7?JJY@@@5Y5B77777777777777777777?5?.      :                  5             5PJ77777777YB777777777777777777777P~                  BYJ77777777777777
777777777777777777775@@@@@@@@@@&                :J5?Y555YYJ?777JB77777777777777777777777J57                       .J             PPJ77777777YB777777777777777777777G!                 .BYJ77777777777777
777777777777777777775@@@@@@@@@@G              :J5?7777777777777YB7777777777777777777777777J57.                    J:             P5J77777777YB777777777777777777777?YYYYYYYYYYYYY55555P5YY77777777777777
77777777777777777777P@@@@@@@@@@B!~:..       :J5?777777777777777YB777777777777777777777777777J5?:                 ?^              G5J77777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777G@@@@@@@@@@@@@@@@&&#GJ7J5?77777777777777777YB77777777777777777777777777777?YY7^:             J:              BYJ77777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777B@@@@@@@@@@@@@@@@@@@#YJ77777777777777777777YB77777777777777777777777777777777?JG!             5^::...::::^^~!BYY77777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777#@@@@@@@@@@@@@@@@@@@#J?77777777777777777777YB77777777777777777777777777777777777G^            .#5YYYY555555YYJJJ77777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777&@@@@@@@@@@@@@@@@@@@#JJ77777777777777777777YB777777777777777777777777777777777777G:            ^P77777777777777777777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777#&@@@@@@@@@@@@@@@@&&GYJ77777777777777777777YB777777777777777777777777777777777777?G^:::::::::::.P57777777777777777777777YB7777777777777777777777777777777777777777777777777777777777
7777777777777777777777???JJJJYYYYYYJJJJJJJ?77777777777777777777YB7777777777777777777777777777777777777?JJJJJJJJJJJJJJ?7777777777777777777777YB7777777777777777777777777777777777777777777777777777777777
777777777777777777777777777777777777777777777777777777777777777?5777777777777777777777777777777777777777777777777777777777777777777777777777YB7777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777J57777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
77777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
