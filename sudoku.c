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

int is_valid(Node* n){
  int sudo;
  int* flag;
  for(int i=0;i<9;i++)
  {
    flag=lineaVacia();
    for(int j=0;j<9;j++)
    {
      sudo=n->sudo[i][j];
      if(sudo!=0)
      {
        if(flag[sudo]!=0)
        {
          return 0;
        }
        flag[sudo]=1;
      }
    }
    flag=lineaVacia();
    for(int j=0;j<9;j++)
    {
      sudo=n->sudo[j][i];
      if(sudo!=0)
      {
        if(flag[sudo]!=0)
        {
          return 0;
        }
        flag[sudo]=1;
      }
    }
  }
  for(int l=0;l<9;l++)
  {
    flag=lineaVacia();
    for(int a=0;a<9;a++)
    {
      int i = 3 * (l / 3) + (a / 3);
      int j = 3 * (l % 3) + (a % 3);
      sudo=n->sudo[i][j];
      if(sudo==0)
      {
        continue;
      }
      if(flag[sudo]==0)
      {
        flag[sudo]=1;
      }
      else
      {
        return 0;
      }
    }
  }
  return 1;
}

int* lineaVacia()
{
  int* creador=(int*)malloc(sizeof(int)*10);
  for(int i=0;i<10;i++)
  {
    creador[i]=0;
  }
  return creador;
}


List* get_adj_nodes(Node* n){
    List* list=createList();

    
  
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