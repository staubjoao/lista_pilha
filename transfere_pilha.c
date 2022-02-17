#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
  int top;
  int num[100];
};

void incia_pilha(struct Pilha *p)
{
  p->top = -1;
}

void insere_pilha(struct Pilha *p, int n)
{
  p->top++;
  p->num[p->top] = n;
}

void transfere_pilha(struct Pilha *p, struct Pilha *q)
{
  int cont = 0;
  while (p->top >= 0)
  {
    q->top++;
    q->num[q->top] = p->num[p->top];
    p->top--;
  }
}

void print_pilha(struct Pilha *p)
{
  int i = p->top;
  while (i >= 0)
  {
    printf("%d\n", p->num[i]);
    i--;
  }
}

int main()
{
  struct Pilha *p = (struct Pilha *)malloc(sizeof(struct Pilha));
  struct Pilha *q = (struct Pilha *)malloc(sizeof(struct Pilha));
  incia_pilha(p);
  incia_pilha(q);

  insere_pilha(p, 5);
  insere_pilha(p, 3);
  insere_pilha(p, 9);
  insere_pilha(p, 1);

  printf("Printa pilha P:\n");
  print_pilha(p);
  transfere_pilha(p, q);
  printf("Printa pilha Q:\n");
  print_pilha(q);

  return 0;
}