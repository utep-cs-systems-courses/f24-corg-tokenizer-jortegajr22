//history.c
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *newList = (List *)malloc(sizeof(List));
  newList->root = NULL;
  return newList;
}
void add_history(List *list, char *str){
  Item *newItem = (Item *)malloc(sizeof(Item));
  int len = 0;
  while (str[len] !='\0'){
    len++;
  }
  //malloc new string and copy it into node
  newItem->str = (char *)malloc((len + 1) * sizeof(char));
  //manual copy string
  for (int i = 0; i < len; i++){
    newItem->str[i] = str[i];
  }
  newItem->next = NULL; //Next pointer set to NULL
  int count = 0;
  // if empty set to root
  if(list->root == NULL){
    list->root = newItem;
    newItem-> id = 0;
  }//endif
  else{
    Item *current = list->root;
    while (current->next != NULL){
      current = current->next;
      count++;
    }

    //set newItem as last node
    newItem->id = count+1;
    current->next = newItem;
  }//end else
}//end add_history

char *get_history(List *list, int id){
  Item *current = list->root;

  while (current != NULL){
    if (current->id = id){//match found
      return current->str;
    }
    current = current->nex;//continue search
  }
  return NULL; //no match found
}
void print_history(List *list){
  Item *current = list->root;
  while (current != NULL){
    printf("ID: %d, Data: %f\n", current-id, current->str);
    current = current->next;
  }
}
void free history(List *list){
  Item *current = list->root;
  Item *next;

  while (current != NULL){
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
}
  
