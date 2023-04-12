#include <stdio.h>
#include <stdlib.h>

void print_matrix(int**, int, int);
void addition_matrix(int**, int**, int, int, int, int);
void subtraction_matrix(int**, int**, int, int, int, int);
void transpose_matrix(int**, int, int);
void multiply_matrix(int**, int**, int, int, int, int);
void free_matrix(int**, int size);

int** add = NULL;    //연산된 값을 받을 전역포인터를 선언한다.
int** sub = NULL;
int** trans = NULL;
int** mul = NULL;

int main(){
  printf("[----- [오인화] [2022078036] -----]\n\n");

  printf("행렬의 크기를 입력하세요 \n");
  int Ar, Ac; scanf("%d %d", &Ar, &Ac);        //배열의 행과 열의 크기를 입력받는다
  int Br, Bc; scanf("%d %d", &Br, &Bc);        

  int** A = (int**)malloc(sizeof(int*)*Ar);    //행의 크기만큼 메모리를 할당받는다
  int** B = (int**)malloc(sizeof(int*)*Br);

  for(int i=0; i<Ar; i++){                     //열의 크기만큼 메모리를 할당받는다
      A[i] = (int*)malloc(sizeof(int)*Ac); 
  }

  for(int i=0; i<Br; i++){
      B[i] = (int*)malloc(sizeof(int)*Bc);
  }

  printf("행렬의 값을 입력하세요\n");                                          
  for(int i=0; i<Ar; i++){            //행렬의 값을 입력받는다
      for(int j=0; j<Ac; j++)
          scanf("%d", &A[i][j]);
  }
  for(int i=0; i<Br; i++){         
      for(int j=0; j<Bc; j++)
          scanf("%d", &B[i][j]);
  }

  printf("\nA\n"); print_matrix(A, Ar, Ac);   //입력받은 행렬을 출력한다
  printf("\nB\n"); print_matrix(B, Br, Bc);

  printf("\nA+B\n");
  addition_matrix(A, B, Ar, Ac, Br, Bc);      //함수 addition_matrix()를 호출해 add가 NULL이 아니면 행렬의 합을 출력한다
  if(add == NULL) 
    printf("행렬의 크기가 다릅니다.\n");
  else
    print_matrix(add, Ar, Ac);

  printf("\nA-B\n");
  subtraction_matrix(A, B, Ar, Ac, Br, Bc);   //함수 subtraction_matrix()를 호출해 sub이 NULL이 아니면 행렬의 차를 출력한다
  if(sub == NULL)
    printf("행렬의 크기가 다릅니다.\n");
  else
    print_matrix(sub, Ar, Ac);

  printf("\nA의 전치행렬 T\n");                //함수 transpose_matrix()를 호출해 전치행렬을 출력한다
  transpose_matrix(A, Ar, Ac);    
  print_matrix(trans, Ac, Ar);

  printf("\nAxB\n");
  multiply_matrix(A, B, Ar, Ac, Br, Bc);      //함수 multiply_matrix()를 호출해 mul이 NULL이 아니면 행렬의 곱을 출력한다
  if(mul == NULL)
    printf("행렬을 곱할 수 없습니다.\n");
  else
    print_matrix(mul, Ar, Bc);

  //메모리 해제
  free_matrix(A, Ar);
  free_matrix(B, Br);
  free_matrix(add, Ar);
  free_matrix(sub, Ar);
  free_matrix(trans, Ar);
  free_matrix(mul, Ar);
  
  return 0;
}

/*행렬의 주소, 행의 크기, 열의 크기를 인자로 받아 행렬을 출력하는 함수*/
void print_matrix(int **a, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%3d ", a[i][j]);
    printf("\n");
    }
}

/*두 행렬의 주소, 행의 크기, 열의 크기를 인자로 받아 덧셈을 하는 함수*/
void addition_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){  
  if(Ar==Br || Ac==Bc){                         //행렬 A와 B의 행과 열의 크기가 각각 같다면 덧셈을 수행한다
    add = (int**)malloc(sizeof(int*)*Ar);       //덧셈의 결과를 받을 행렬의 메모리를 할당한다
    for(int i=0; i<Ac; i++){
        add[i] = (int*)malloc(sizeof(int)*Ac);
    }
    for(int i=0; i<Ar; i++){                    //행렬의 합을 연산해 add에 대입한다
      for(int j=0; j<Ac; j++){
        add[i][j] = a[i][j] + b[i][j];
      }
    }
  }
}

/*두 행렬의 주소, 행의 크기, 열의 크기를 인자로 받아 뺄셈을 하는 함수*/
void subtraction_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){
  if(Ar==Br || Ac==Bc){                         //행렬 A와 B의 행과 열의 크기가 각각 같다면 뺄셈을 수행한다
    sub = (int**)malloc(sizeof(int*)*Ar);       //뺄셈의 결과를 받을 행렬의 메모리를 할당한다

    for(int i=0; i<Ac; i++){                    
        sub[i] = (int*)malloc(sizeof(int)*Ac);
    }

    for(int i=0; i<Ar; i++){                    //행렬의 뺄셈을 연산해 sub에 대입한다
      for(int j=0; j<Ac; j++)
        sub[i][j] = a[i][j] - b[i][j];
    }
  }
}

/*행렬 A의 주소, 행의 크기, 열의 크기를 인자로 받아 전치행렬을 만드는 함수*/
void transpose_matrix(int **a, int r, int c){
    trans = (int**)malloc(sizeof(int*)*c);         //전치행렬의 행의 크기(A의 열의 크기)만큼 메모리를 할당한다
  
    for(int i=0; i<c; i++){
        trans[i] = (int*)malloc(sizeof(int)*r);    //전치행렬의 열의 크기(A의 행의 크기)만큼 메모리를 할당한다
    }

    for(int i=0; i<c; i++){                        //A의 행과 열의 인덱스를 바꾸어 전치행렬을 위한 메모리에 대입한다
      for(int j=0; j<r; j++){
        trans[i][j] = a[j][i];                     
      }
    }
}

/*두 행렬의 주소, 행의 크기, 열의 크기를 인자로 받아 곱하는 함수*/
void multiply_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){
  if(Ac == Br){                                    //A의 열의 크기와 B의 행의 크기가 같다면 연산을 실행하도록 한다
    mul = (int**)malloc(sizeof(int*)*Ar);          //곱의 결과를 받을 메모리를 할당한다
    for(int i=0; i<Ar; i++){
        mul[i] = (int*)malloc(sizeof(int)*Bc);
    }  
    for(int i=0; i<Ar; i++){                       //행렬의 곱을 연산해 mul에 대입한다
      for(int j=0; j<Bc; j++){
        mul[i][j] = 0; 
        for(int k=0; k<Ac; k++){   
          mul[i][j] += a[i][k] * b[k][j];
        }
      }
    }
  }
}

/*행렬의 주소와 행의 크기를 인자로 받고, 동적할당한 메모리를 해제하는 함수*/
void free_matrix(int **a, int size){
  for(int i=0; i<size; i++)             
    free(a[i]);
  
  free(a);
}
