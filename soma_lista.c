#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int key;
  float num;
  struct Node *nxt;
};

float sum(float min, struct Node *p)
{
  float sum_local = 0;
  if (p)
  {
    do
    {
      if (p->num >= min)
        sum_local = sum_local + p->num;
      p = p->nxt;
    } while (p);
    return sum_local;
  }
  else
    return 0;
}

int main(void)
{
  float min;
  struct Node *node1 = NULL;
  struct Node *node2 = NULL;
  struct Node *node3 = NULL;

  node1 = (struct Node *)malloc(sizeof(struct Node *));
  node1->key = 1;
  node1->num = 7.3;
  node2 = (struct Node *)malloc(sizeof(struct Node *));
  node2->key = 2;
  node2->num = 15.5;
  node3 = (struct Node *)malloc(sizeof(struct Node *));
  node3->key = 3;
  node3->num = 12.3;

  node1->nxt = node2;
  node2->nxt = node3;
  node3->nxt = NULL;

  printf("Digite o valor minimo: ");
  scanf("%f", &min);

  printf("%.2f", sum(min, node1));

  return 0;
}