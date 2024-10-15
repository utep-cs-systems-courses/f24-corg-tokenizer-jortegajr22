#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *newList = (List *)malloc(sizeof(List));
  newList->root = NULL;
  return newList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *newItem = (Item *)malloc(sizeof(Item));
  
  
  int len = 0;
  while (str[len] !='\0'){
    len++;
  }
  //malloc new string and copy it into node
  newItem->str = (char *)malloc(len + 1) * sizeof(char));

  //manual copy string
  for (int i = 0; i < len; i++){
    newItem->str[i] = str[i];
  }
  newItem->next = NULL;//next pointer set to NULL
  int count = 0;
  //if the list is empty, set current as root
  if (list->root == NULL){
    list->root = newItem;
    newItem->id=0;
  }//end if

  else {
    Item *current = list->root;
    while (current->next !=NULL){
      current = current->next;
      count++;
    }
    
    //set newItem as lastnode
    newItem->id = count;
    current->next = newItem;
  }//end else
}//end add_history

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *current = list->root;

  while (current != NULL){
    if (current->id == id){//match found
      return current->str;
    }
    current = current->next;//continue search
  }
  return NULL;//No matching id
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *current = list->root;
  while (current != NULL){
    printf("ID: %d, Data: %f\n", current->id, current->str);//print id and data
    current = current->next;
  }
}


/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *current = list->root;
  Item *next;

  //iterate and free
  while (current != NULL){
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
}

#endif
