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
  int i, j, k;
  for(i = 0; i < 9; i++){
    for(j = 0; j < 9; j++){
      if (n->sudo[i][j]){
        for(k = j+1; k < 9; k++ ){
          if(n->sudo[i][j] == n->sudo[i][k]) return 0;
        }
      }
    }
  }
  for(j = 0; j < 9; j++){
    for(i = 0; i < 9; i++){
      if (n->sudo[i][j]){
        for(k = i+1; k < 9; k++ ){
          if(n->sudo[i][j] == n->sudo[k][j]) return 0;
        }
      }
    }
  }
  int * a = (int*)malloc(sizeof(int)*10);
  for(int l=0;l<10;l++)
  {
    a[l]=0;
  }
  for( l=0;l<9;l++)
  {
    
    for(int m=0;m<9;m++)
    {
      int i = 3 * (l / 3) + (m / 3);
      int j = 3 * (l % 3) + (m % 3);
      
      if(n->sudo[i][j]==0)
      {
        continue;
      }
      if(a[n->sudo[i][j]]==0)
      {
        a[n->sudo[i][j]]=1;
      }
      else
      {
        return 0;
      }
    }
  }
    return 1;
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