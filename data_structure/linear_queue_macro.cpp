#include "stdio.h"

struct QUEUE
{ 
  int d;
} queue[10000];

int wp, rp;
#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)

int main(void)
{

  return 0;
}
