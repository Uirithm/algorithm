#include "stdio.h"

#define STACK_MAX (10)

int Sp = STACK_MAX;
int Stack[STACK_MAX + 1];

int Push(int d)
{ 
  if (Sp == 0) return -1; 
    Stack[--Sp] = d;  
 
  return Sp;
}

int Pop(int *p)
{ 
  if (Sp == STACK_MAX) return -1; 
  *p = Stack[Sp++];

  return Sp;
}

int main(void)
{

  return 0;
}
