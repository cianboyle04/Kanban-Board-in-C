#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "loadAndDisplay.h"

Linked_List* testData(void)
{
    //allocate memory to hold a linked list of items
    //malloc returns pointer address of allocated memory
    Linked_List* list1 = malloc(sizeof(Linked_List));

    //name the list with who owns the "items"
    strcpy(list1->name, "Birdo");
    //list1 is the end of the linked list, therefore points to NULL
    list1->next = NULL;

    //create items and assign names to data part of the "link" in the list
    Item* item1_1 = malloc(sizeof(Item));
    strcpy(item1_1->name, "Bullet Bill");
    Item* item1_2 = malloc(sizeof(Item));
    strcpy(item1_2->name, "Mushrooms");
    Item* item1_3 = malloc(sizeof(Item));
    strcpy(item1_3->name, "Lightning Strike");


    //link each node of the list together
    list1->firstItem = item1_1;
    item1_1->next = item1_2;
    item1_2->next = item1_3;
    item1_3->next = NULL;

    item1_1->prev=NULL;
    item1_2->prev=item1_1;
    item1_3->prev=item1_2;

    //create second list of items
    Linked_List* list2 = malloc(sizeof(Linked_List));

    //give name to this list of items
    strcpy(list2->name, "Wario");
    //link "list1" as the link part of this node
    list2->next = list1;

    //add nodes "items" to this list
    Item* item2_1 = malloc(sizeof(Item));
    strcpy(item2_1->name, "Red Shells");

    Item* item2_2 = malloc(sizeof(Item));
    strcpy(item2_2->name, "Blooper");


    list2->firstItem = item2_1;
    item2_1->next = item2_2;
    item2_2->next=NULL;

    item2_1->prev=NULL;
    item2_2->prev=item2_1;

    //create third list of items
    Linked_List* list3 = malloc(sizeof(Linked_List));

    //assign name
    strcpy(list3->name, "Luigi");
    //point this node to previous "list2"
    list3->next = list2;

    //add nodes "items" to this list
    Item* item3_1 = malloc(sizeof(Item));
    strcpy(item3_1->name, "Golden Mushroom");

    //the only item in this list of items points to NULL, ie, this list only has one item
    list3->firstItem = item3_1;
    item3_1->next = NULL;

    item3_1->prev=NULL;

    //create fourth list of items
    Linked_List* list4 = malloc(sizeof(Linked_List));

    //name list of items
    strcpy(list4->name, "Mario");
    //point this node to previous "list3"
    list4->next = list3;

    //create items
    Item* item4_1 = malloc(sizeof(Item));
    strcpy(item4_1->name, "Mega Mushroom");

    Item* item4_2 = malloc(sizeof(Item));
    strcpy(item4_2->name, "Blue Shell");

    list4->firstItem = item4_1;
    item4_1->next = item4_2;
    item4_2->next=NULL;

    item4_1->prev=NULL;
    item4_2->prev=item4_1;

    list1->prev = list2;
    list2->prev = list3;
    list3->prev = list4;
    list4->prev = NULL;

    //return pointer to list4 which will be printed first as it is head node
    return list4;

}

void printList(Linked_List* listPointer)
{
    //loop will end once final node, which points to NULL, is encountered
    while (listPointer != NULL)
    {
        //print person name which is being pointed to
        printf("%s:\n", listPointer->name);

        //for each name on the board, use itemPointer to point to the first item in node
        Item* itemPointer = listPointer->firstItem;

        while (itemPointer != NULL)
        {
            //print the item name of which is being currently pointed to
            printf("\t%s\n", itemPointer->name);

            //move itemPointer to next item in list of items
            itemPointer=itemPointer->next;
        }

        //move pointer along to next name on the board
        listPointer=listPointer->next;
    }

    //print new line separate different functions
    printf("\n");
}

void printList_toFile(Linked_List* listPointer, FILE* fp)
{

    //loop will end once final node, which points to NULL, is encountered
    while (listPointer != NULL)
    {
        //print person name which is being pointed to
        fprintf(fp ,"%s\n", listPointer->name);

        //for each name on the board, use itemPointer to point to the first item in node
        Item* itemPointer = listPointer->firstItem;

        while (itemPointer != NULL)
        {
            //print the item name of which is being currently pointed to
            fprintf(fp ,"%s\n", itemPointer->name);

            //move itemPointer to next item in list of items
            itemPointer=itemPointer->next;
        }
        fprintf(fp, "\n");
        //move pointer along to next name on the board
        listPointer=listPointer->next;
    }
}

FILE* loadFile(int mode)
{
    FILE *fp;

    char fileName[80];

    //tell user to enter file name
    printf("Enter filename:");


    //check whether file exists
    //if not, print error
    do{

        //clear buffer so that fgets is able to read in from command line
        fflush(stdin);

        //receive file name through fgets
        fgets(fileName, 80, stdin);

        //remove new-line character added be fgets
        fileName[strlen(fileName)-1]='\0';

        //open filename, entered by user
        //through using a mode variable, the same function can be used to open a file
        //but in different modes
        //if "1" is passed to this function, file will open in write mode
        //else will be opened for reading
        if(mode)
        {
            fp=fopen(fileName, "w");
        }
        else
        {
            fp=fopen(fileName, "r");
        }

        if(fp==NULL)
        {
            printf("\nError: could not open file %s. Please try again.\n", fileName);
            printf("Enter filename:");
        }

    }while(fp==NULL);

    printf("\n");

    //return pointer to file
    return fp;

}

Linked_List* createLinkedList(FILE *fp)
{
    //boolean which will track if whether the line before was a "\n" character or not
    //as this signifies the end of someone's items and the start of a new name and new set of items
    //set to true initially as the first line of the text file is always going to be a name followed by items
    bool createNewName=true;

    //pointer to entire linked list
    Linked_List *head = NULL;

    //the current list which will be used to link lists
    Linked_List *currentList = NULL;

    //line variable which will hold the contents of each line of the text file
    char line[100];

    //while loop which will keep running as long as we have not reached the end of the file
    while((fgets(line, 100, fp))!=NULL)
    {
        //if the line is blank, ie, a "\n" character, the next line will be a name
        if(strcmp(line, "\n")==0)
        {
            //set boolean to true so in next iteration of while loop
            //we create a new link to our linked list
            createNewName=true;
            continue;
        }

        //if line is not just "\n", then it holds contents to add to our linked list
        else
        {
            //if boolean from above is true, we want to create a new link
            if(createNewName)
            {
                //a new node of our linked list is created, given the name of the contents of the line
                //a pointer to it is returned which we store in newList, which will then be used
                Linked_List* newList = listLink(line);

                //once we have added the name, we know each following line, as long as it is not a "\n" character,
                //is going to be an item, so we can set boolean to false again and will be set true again when needed
                createNewName=false;

                //if our head is still pointing to NULL, the node which has been created will be the first link
                //therefore, it will not have a previous pointer
                if(head==NULL)
                {
                    //the head is set to our new list, which will not be modified
                    head=newList;

                    //currentList is also set to newList, however will be modified later
                    currentList=newList;
                }

                //if we are linking an item to the linked list, we correct assign double links to the right nodes
                else
                {
                    //currentList, which still holds pointer to previous node, will have it's "next" pointer assigned
                    //to the new list we have created
                    //similarly, newList "prev" pointer is assigned the previous node as it is a double linked list
                    currentList->next=newList;
                    newList->prev=currentList;

                    //as we are now finished with the previous node and know it is linked to our new list we have created
                    //we set currentList to be our new list we have created as it will be the previous list in the next iteration
                    currentList=newList;
                }

                continue;
            }

            //if the boolean is false, we know that the line is an item, rather than a name
            else
            {
                //use addItemToList function which takes in a link to linked list and the whole line (name of item)
                //function adds item to linked list, inside our main linked list
                addItemToList(currentList, line);
            }
        }
    }

    //pointer to the first node of the linked list is returned
    return head;
}

Linked_List* listLink(char *name)
{
    //allocate memory to hold a new node
    Linked_List* newLink = malloc(sizeof(Linked_List));

    //remove the new line character which would mess the format
    //as name in node would be "name\n" rather than "name"
    if(name[strlen(name)-1]=='\n')
    {
        name[strlen(name)-1]='\0';
    }
    //add name which was passed to function as the data of node
    strcpy(newLink->name, name);

    //set all pointers of struct to NULL but will be changed later when we link nodes
    newLink->next = NULL;
    newLink->prev = NULL;
    newLink->firstItem = NULL;

    //return address of this node
    return newLink;
}

Item* itemLink(char *name)
{
    //allocate memory to hold an item node
    Item* newItem = (Item*)malloc(sizeof(Item));

    //remove new line for formatting
    //so name is "name" rather than "name\n" due to how data is saved in files
    if(name[strlen(name)-1]=='\n')
    {
        name[strlen(name)-1]='\0';
    }

    //add name which was passed to function as the data of node
    strcpy(newItem->name, name);

    //set pointers to NULL but will be changed later in "addItemToList" function
    newItem->next = NULL;
    newItem->prev = NULL;

    //return pointer to new item node
    return newItem;
}

void addItemToList(Linked_List* list, char *itemName)
{
    //first create a new item node
    Item* newItem = itemLink(itemName);

    //check if there's already a first item in the linked list
    //if not, set the item to be the first item in the list
    if(list->firstItem==NULL)
    {
        list->firstItem=newItem;
    }

    //if a first item exists
    else
    {
        //create "currentItem" which will return a pointer to "list->firstItem"
        //ie, the first item in the list
        Item* currentItem = list->firstItem;

        //loop which will bring us to the end of the list,
        //ie, where we actually want to link the"newItem" to
        while (currentItem->next != NULL)
        {
            //if "currentItem->next != NULL" then there is something linked to currentItem
            //therefore it cannot be the end of the list

            //as a result, we move the pointer along to the next item
            currentItem=currentItem->next;
        }

        //once the end has been reached, we set "currentItem->next", which was NULL, to the address of the newItem
        //we also link "newItem->prev" to the "previous" last item as we are creating a doubly linked list

        currentItem->next = newItem;
        newItem->prev = currentItem;
    }
}

