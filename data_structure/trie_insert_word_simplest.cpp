#include "stdio.h"
#include "malloc.h"

struct NODE
{ 
  NODE* next[26]; 
  int end_of_word;
} root;

#define GETIDX(X) ((X) - ('a'))

void Insert_Word(char *str)
{  
  NODE *node = &root;

  for (int i = 0; str[i] != '\0'; ++i) 
  {  
    if (node->next[GETIDX(str[i])] == (NODE*)0)   
      node->next[GETIDX(str[i])] = (NODE*)calloc(1, sizeof(NODE));
  
    node = node->next[GETIDX(str[i])];   
  } 
  node->end_of_word = 1;
}

int main()
{ 
  Insert_Word("apply"); 
  Insert_Word("apple");

  return 0;
}
