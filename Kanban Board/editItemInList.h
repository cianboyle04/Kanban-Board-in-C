//function which will edit items in a list
void editList(Linked_List* listPointer);

//function which will find list in the entire linked list
Linked_List* findListNode(Linked_List* listPointer);

//function which will find item in the item linked list
Item* findItemNode(Item* itemPointer);

//function which receives valid input from the user
int getOption(void);

//function which will edit and items name by accessing its address
void editItem(Item *itemNode);

//function which will add an item to the end of a list
void addItem(Item *itemNode, Linked_List *listPointer);

//function which will delete and item
void deleteItem(Item *itemPointer, Linked_List *listPointer);

//function which will edit the lists
void editBoard(Linked_List* listPointer, Linked_List **headPointer);

//function which will edit the list name by access the node address
void editListName(Linked_List *listNode);

//function which will add new list to start of previously defined list
void addListToBoard(Linked_List **listNode);

//function which will delete an entire list and free its items and itself
void deleteList(Linked_List *listNode, Linked_List **headNode);

//function called by delete list, to free all the items
void freeItems(Item *firstItem);
