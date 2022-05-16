#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int* lista_0()
{
  int* list=(int*)malloc(sizeof(int)*10);
  for(int i=0;i<10;i++)
  {
    list[i]=0;
  }
  return list;
}

int is_valid(Node* n){
  int sudo;
  int* ar;
  for(int i=0;i<9;i++)
  {
    ar=lista_0();
    for(int j=0;j<9;j++)
    {
      sudo=n->sudo[i][j];
      if(sudo!=0)
      {
        if(ar[sudo]!=0)
        {
          return 0;
        }
        ar[sudo]=1;
      }
    }
    ar=lista_0();
    for(int j=0;j<9;j++)
    {
      sudo=n->sudo[j][i];
      if(sudo!=0)
      {
        if(ar[sudo]!=0)
        {
          return 0;
        }
        ar[sudo]=1;
      }
    }
  }
  for(int l=0;l<9;l++)
  {
    ar=lista_0();
    for(int a=0;a<9;a++)
    {
      int i = 3 * (l / 3) + (a / 3);
      int j = 3 * (l % 3) + (a % 3);
      sudo=n->sudo[i][j];
      if(sudo==0)
      {
        continue;
      }
      if(ar[sudo]==0)
      {
        ar[sudo]=1;
      }
      else
      {
        return 0;
      }
    }
  }
  return 1;
}

int posicionActual(Node*n,int casilla)
{
  for(int i=0;i<9;i++)
    {
      if(n->sudo[casilla][i]==0)
      {
        return i;
      }
    }
  return 0;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

    for(int i=0;i<9;i++)
  {
    if(posicionActual(n,i)!=0)
    {
      for(int j=1;j<10;j++)
      {
        Node* Adj=copy(n);
        int detector=posicionActual(n,i);
        Adj->sudo[i][detector]=j;
        if(is_valid(Adj)==1)
        {
          pushBack(list,Adj);
        }
      }
    }
    break;
  }
  
    return list;
}


int is_final(Node* n){
  int i, j, k = 1;
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if(n->sudo[i][j] == 0){
        k = 0;
        break;
      }
    }
  }
  if ( k == 0){
    return 0;
  }else{
    return 1;
  }
  
}

Node* DFS(Node* initial, int* cont){
  
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/

//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