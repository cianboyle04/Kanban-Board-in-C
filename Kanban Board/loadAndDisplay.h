//node of linked list which will contain items and also link to next and previous items
typedef struct item {

    char name[50];
    struct item* next;
    struct item* prev;

} Item;

//node of board linked list which contains owner name and also pointer to their items
typedef struct list {

    char name[50];
    struct list* next;
    struct list* prev;
    Item* firstItem;

} Linked_List;

//create function which returns pointer to test data which is defined/held in "testData" function
Linked_List* testData(void);

//function which will print a linked list through accessing address of first node
void printList(Linked_List* listPointer);

//function which will print the list to a file, using appropriate function for file printing
//function takes in pointer to open file stream and also the address of first node in linked list
void printList_toFile(Linked_List* listPointer, FILE *fp);

//function to open a file from directory
FILE* loadFile(int mode);

//functions which will create a linked list from contents of a file

Linked_List* createLinkedList(FILE *fp);

Linked_List* listLink(char *name);

Item* itemLink(char *name);

void addItemToList(Linked_List* list, char *itemName);

