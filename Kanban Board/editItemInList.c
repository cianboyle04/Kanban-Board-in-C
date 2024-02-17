#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "loadAndDisplay.h"
#include "editItemInList.h"

void editList(Linked_List* listPointer)
{
    //execute function which will find the address of a node entered by a user
    Linked_List *listNode=findListNode(listPointer);

    //obtain valid option through getOption function
    int option;

    do{

        //print options for user
        printf("Options:\n");
        printf("1. Edit an item\n");
        printf("2. Add a new item\n");
        printf("3. Delete an item\n");
        printf("4. Return to main menu\n");

        option=getOption();

        //option 1 = edit item
        if(option==1)
        {
            //error handling if there are no items in a list
            if(listNode->firstItem==NULL)
            {
                printf("No Items in List!\n");
            }
            else
            {
                //ask user what item they would like to edit
                printf("Please enter the name of the item to edit:");

                //get memory address of the item, user would like to edit
                Item *itemNode=findItemNode(listNode->firstItem);

                //edit the item
                editItem(itemNode);
            }

        }
            //option 2 = add an item
        else if(option==2)
        {
            //add an item to a list
            addItem(listNode->firstItem, listNode);
        }
            //option 3 = delete an item
        else if(option==3)
        {
            //error handling if there are no items in a list
            if(listNode->firstItem==NULL)
            {
                printf("No Items in List!\n");
            }
            else
            {
                //ask user what item they want to delete
                printf("Please enter the name of the item to delete:");

                //find the address of the item
                Item *itemNode=findItemNode(listNode->firstItem);

                //delete item
                deleteItem(itemNode, listNode);
            }

        }

        //as the getOption function only allows input of 1-4, if it is 1-3, above functions execute
        //the only other number that can be entered is 4 which will return user to main menu
    }while(option!=4);

}

int getOption(void)
{
    //initialise variable to take in from user
    int option;

    //enter do-while loop to ensure correct value entered
    do{

        printf("Enter your option:");
        scanf("%d", &option);

        if(option<1 || option>4)
        {
            printf("Invalid input. Please try again\n");
        }

    }while(option<1 || option>4);

    printf("\n");

    //return the entered option, between 1-4
    return option;
}

Linked_List* findListNode(Linked_List* listPointer)
{
    //initialise variable to hold name, input from the user
    char toEdit[50];

    //boolean which will turn to false when the node has been found
    bool notFound=true;

    //set the pointer to linked list to head so that if an invalid name is entered,
    //we can return to start of the list to look for the list again when the user
    //has hopefully entered a correct name
    Linked_List* head=listPointer;

    printf("Please enter the name of the list to edit:");

    do{

        //set the list pointer to start of list on each iteration to ensure the list is found
        listPointer=head;

        //clear the buffer
        fflush(stdin);
        fgets(toEdit, 50, stdin);
        fflush(stdin);

        //remove new line character
        toEdit[strlen(toEdit)-1] = '\0';

        //enter loop which will keep going until the end of the item list is found
        while(listPointer!=NULL)
        {
            //if item is found, boolean turns to false to exit loop
            if(strcmp(toEdit, listPointer->name)==0)
            {
                notFound=false;
                break;
            }
            //else, pointer moves along
            else
            {
                listPointer=listPointer->next;
            }
        }

        //if not found is true, user will be prompted to enter another name
        if(notFound)
        {
            printf("Could not find list. Please try again.\n");
        }

    }while(notFound);

    printf("\n");

    //return address of list, user would like to access
    return listPointer;

}

Item* findItemNode(Item* itemPointer)
{
    //find item node is similar to find list however uses an item struct instead of linked list
    char toEdit[50];
    bool notFound=true;

    //hold head address in pointer
    Item *head=itemPointer;

    //enter loop until a correct name is entered
    do{

        itemPointer=head;

        //clear buffer and receive input from the user
        fflush(stdin);
        fgets(toEdit, 50, stdin);
        fflush(stdin);

        //remove new line
        toEdit[strlen(toEdit)-1] = '\0';

        //enter loop to keep going until end of list
        while(itemPointer!=NULL)
        {
            //exit loop if node found
            if(strcmp(toEdit, itemPointer->name)==0)
            {
                notFound=false;
                break;
            }

            //otherwise move pointer along
            else
            {
                itemPointer= itemPointer->next;
            }
        }

        if(notFound)
        {
            printf("Could not find item. Please try again.\n");
        }


    }while(notFound);

    printf("\n");

    //return address of item, user would like to access
    return itemPointer;
}

void editItem(Item *itemNode)
{
    //initialise variable to hold new name
    char newName[50];

    printf("Enter new name for item '%s':", itemNode->name);

    //receive name from user and clear the buffer
    fflush(stdin);
    fgets(newName, 50, stdin);
    fflush(stdin);

    //remove new line character
    newName[strlen(newName)-1] = '\0';

    //copy the newly entered name into the item->name slot of the item, user would like to edit
    strcpy(itemNode->name, newName);
}

void addItem(Item *itemNode, Linked_List *listPointer)
{
    //enter if statement if there are no items currently in the list
    if(listPointer->firstItem==NULL)
    {
        //create new item
        Item *newItem= malloc(sizeof(Item));

        //point the entire list->firstItem to the newly initialised item
        listPointer->firstItem=newItem;

        //variable to hold it's name
        char newName[50];

        printf("Enter the name of the new item:");

        //receive name and clear buffer
        fflush(stdin);
        fgets(newName, 50, stdin);
        fflush(stdin);

        //remove new line
        newName[strlen(newName)-1] = '\0';

        //copy the name entered by the user into the new items name
        strcpy(newItem->name, newName);

        //as it is the only item in the list, the double pointers point to nothing
        newItem->next=NULL;
        newItem->prev=NULL;
    }

    //if there are already item in the list, enter else condition
    else
    {
        //find the end of the list, ie where to add the new item on to
        while(itemNode->next!=NULL)
        {
            itemNode=itemNode->next;
        }

        //create new item which will be added
        Item *newItem= malloc(sizeof(Item));

        //link the last item to the newly created item
        itemNode->next=newItem;

        //variable to hold name
        char newName[50];

        printf("Enter the name of the new item:");

        //get new item name from user
        fflush(stdin);
        fgets(newName, 50, stdin);
        fflush(stdin);

        //remove new line
        newName[strlen(newName)-1] = '\0';

        //copy name into the name slot of new item
        strcpy(newItem->name, newName);

        //link the next pointer to null, as new item is now at the end of the list
        newItem->next=NULL;
        //link prev pointer to the previous, last item of the list
        newItem->prev=itemNode;
    }

}

void deleteItem(Item *itemPointer, Linked_List *listPointer)
{

    //condition if the item is the only item in the list
    if(itemPointer->prev==NULL && itemPointer->next==NULL)
    {
        //set the firstitem, ie the only item to null as there is no items anymore
        listPointer->firstItem=NULL;
    }

    //condition if it is the first item in list
    else if(itemPointer==listPointer->firstItem)
    {
        //set the list's first item pointer to be the address of the second item in list
        listPointer->firstItem=itemPointer->next;
    }

    //condition if it is the last item in list
    else if(itemPointer->next==NULL)
    {
        //set the items previous pointer's next pointer to NULL
        itemPointer->prev->next=NULL;
    }

    //condition if item is anywhere else
    else
    {
        //link the previous items next pointer, to the current items next pointer
        itemPointer->prev->next=itemPointer->next;

        //link the next items previous pointer to the current items previous pointer
        itemPointer->next->prev=itemPointer->prev;

        //as a result, none of the pointers will point to the current item
    }

    //free the current item pointer as it is no longer in use and no longer being pointed to
    free(itemPointer);

}

void editBoard(Linked_List* listPointer, Linked_List **headPointer)
{

    //initialise variable to hold option
    int option;

    do{

        //display options for the user
        printf("Options:\n");
        printf("1. Edit the name of a list\n");
        printf("2. Add a new list\n");
        printf("3. Delete a list\n");
        printf("4. Return to main menu\n");

        //receive valid input
        option=getOption();

        //option 1 = edit list name
        if(option==1)
        {
            //find the address of the list of which the user would like to change it's name
            Linked_List *listNode=findListNode(listPointer);

            //edit the address of the list the user would like to edit
            editListName(listNode);
        }

            //option 2 = add list to start of linked list
        else if(option==2)
        {
            //function takes in the head pointer which is a pointer to a pointer
            addListToBoard(headPointer);
        }

            //option 3 = delete list
        else if(option==3)
        {
            //find the address of the list the user would like to delete
            Linked_List *listNode=findListNode(listPointer);

            //delete the list at that address
            //also take in the pointer of the pointer to the start of the list, in case user deletes first list
            deleteList(listNode, headPointer);
        }

        //if 4 is entered, return to main menu
    }while(option!=4);

}

void editListName(Linked_List *listNode)
{
    //variable to hold new list name
    char newName[50];

    printf("Enter new name for list '%s':", listNode->name);

    //get new name and clearing buffer
    fflush(stdin);
    fgets(newName, 50, stdin);
    fflush(stdin);

    //get rid of new line character
    newName[strlen(newName)-1] = '\0';

    //copy the new name into the name slot of the node, user wanted to edit
    strcpy(listNode->name, newName);
}

void addListToBoard(Linked_List **headNode)
{
    //create new list which will be added to the start
    Linked_List  *newList= malloc(sizeof(Linked_List));

    //variable to hold new name
    char newItemName[50];

    printf("Enter name of the new list:");

    //get input and clear buffer
    fflush(stdin);
    fgets(newItemName, 50, stdin);
    fflush(stdin);

    //get rid of new line character
    newItemName[strlen(newItemName)-1] = '\0';

    //copy name into newItem
    strcpy(newList->name, newItemName);

    //as the new list is added at the start
    //we link the next pointer to the address of the pointer to the old, head node
    newList->next=*headNode;
    //new list prev is set to null as it is the first item in the list
    newList->prev=NULL;

    //we then set the head node to the newly added list
    *headNode=newList;
}

void deleteList(Linked_List *listNode, Linked_List **headNode)
{
    //condition if first list
    if(listNode->prev==NULL)
    {
        //call function to free all items in the list
        freeItems(listNode->firstItem);

        //set the pointer to the head of the list to the second list in the linked list
        *headNode=listNode->next;

        //set the second items previous to null as it is now first in the list
        listNode->next->prev=NULL;
    }

    //condition if last list
    else if(listNode->next==NULL)
    {
        //free all items in the list
        freeItems(listNode->firstItem);
        //set the second last null, (which is now the last) next pointer to null
        listNode->prev->next=NULL;
    }

    //condition for anything else
    else
    {
        //free all associated items
        freeItems(listNode->firstItem);

        //set the list in front prev to the current list prev
        listNode->next->prev=listNode->prev;

        //set the list behind's next to the current lists next
        listNode->prev->next=listNode->next;

        //as a result we cut out the list in the middle, the one we wanted to get rid of as nothing points to it now
    }

    //free the memory held by the list itself
    free(listNode);
}

void freeItems(Item *firstItem)
{
    //if there are no items in the list, return as there is nothing to free
    if(firstItem==NULL)
    {
        return;
    }

    //create a temp item which will hold the previous item so it can be freed so
    //we can move to the next item
    Item *tempItem;

    //while there are still items in the list, keep going in loop
    while(firstItem->next!=NULL)
    {
        //set the current item to a temp
        tempItem=firstItem;

        //move current along so we can get the next address
        firstItem=firstItem->next;

        //free the temp which is now the previous item
        free(tempItem);
    }

    //free the last item in the list
    free(firstItem);
}



