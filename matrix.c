#include <stdio.h>
#include <stdlib.h>

void print_matrix(int**, int, int);
void addition_matrix(int**, int**, int, int, int, int);
void subtraction_matrix(int**, int**, int, int, int, int);
void transpose_matrix(int**, int, int);
void multiply_matrix(int**, int**, int, int, int, int);
void free_matrix(int**, int size);

int** add = NULL;    //����� ���� ���� ���������͸� �����Ѵ�.
int** sub = NULL;
int** trans = NULL;
int** mul = NULL;

int main(){
  printf("[----- [����ȭ] [2022078036] -----]\n\n");

  printf("����� ũ�⸦ �Է��ϼ��� \n");
  int Ar, Ac; scanf("%d %d", &Ar, &Ac);        //�迭�� ��� ���� ũ�⸦ �Է¹޴´�
  int Br, Bc; scanf("%d %d", &Br, &Bc);        

  int** A = (int**)malloc(sizeof(int*)*Ar);    //���� ũ�⸸ŭ �޸𸮸� �Ҵ�޴´�
  int** B = (int**)malloc(sizeof(int*)*Br);

  for(int i=0; i<Ar; i++){                     //���� ũ�⸸ŭ �޸𸮸� �Ҵ�޴´�
      A[i] = (int*)malloc(sizeof(int)*Ac); 
  }

  for(int i=0; i<Br; i++){
      B[i] = (int*)malloc(sizeof(int)*Bc);
  }

  printf("����� ���� �Է��ϼ���\n");                                          
  for(int i=0; i<Ar; i++){            //����� ���� �Է¹޴´�
      for(int j=0; j<Ac; j++)
          scanf("%d", &A[i][j]);
  }
  for(int i=0; i<Br; i++){         
      for(int j=0; j<Bc; j++)
          scanf("%d", &B[i][j]);
  }

  printf("\nA\n"); print_matrix(A, Ar, Ac);   //�Է¹��� ����� ����Ѵ�
  printf("\nB\n"); print_matrix(B, Br, Bc);

  printf("\nA+B\n");
  addition_matrix(A, B, Ar, Ac, Br, Bc);      //�Լ� addition_matrix()�� ȣ���� add�� NULL�� �ƴϸ� ����� ���� ����Ѵ�
  if(add == NULL) 
    printf("����� ũ�Ⱑ �ٸ��ϴ�.\n");
  else
    print_matrix(add, Ar, Ac);

  printf("\nA-B\n");
  subtraction_matrix(A, B, Ar, Ac, Br, Bc);   //�Լ� subtraction_matrix()�� ȣ���� sub�� NULL�� �ƴϸ� ����� ���� ����Ѵ�
  if(sub == NULL)
    printf("����� ũ�Ⱑ �ٸ��ϴ�.\n");
  else
    print_matrix(sub, Ar, Ac);

  printf("\nA�� ��ġ��� T\n");                //�Լ� transpose_matrix()�� ȣ���� ��ġ����� ����Ѵ�
  transpose_matrix(A, Ar, Ac);    
  print_matrix(trans, Ac, Ar);

  printf("\nAxB\n");
  multiply_matrix(A, B, Ar, Ac, Br, Bc);      //�Լ� multiply_matrix()�� ȣ���� mul�� NULL�� �ƴϸ� ����� ���� ����Ѵ�
  if(mul == NULL)
    printf("����� ���� �� �����ϴ�.\n");
  else
    print_matrix(mul, Ar, Bc);

  //�޸� ����
  free_matrix(A, Ar);
  free_matrix(B, Br);
  free_matrix(add, Ar);
  free_matrix(sub, Ar);
  free_matrix(trans, Ar);
  free_matrix(mul, Ar);
  
  return 0;
}

/*����� �ּ�, ���� ũ��, ���� ũ�⸦ ���ڷ� �޾� ����� ����ϴ� �Լ�*/
void print_matrix(int **a, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%3d ", a[i][j]);
    printf("\n");
    }
}

/*�� ����� �ּ�, ���� ũ��, ���� ũ�⸦ ���ڷ� �޾� ������ �ϴ� �Լ�*/
void addition_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){  
  if(Ar==Br || Ac==Bc){                         //��� A�� B�� ��� ���� ũ�Ⱑ ���� ���ٸ� ������ �����Ѵ�
    add = (int**)malloc(sizeof(int*)*Ar);       //������ ����� ���� ����� �޸𸮸� �Ҵ��Ѵ�
    for(int i=0; i<Ac; i++){
        add[i] = (int*)malloc(sizeof(int)*Ac);
    }
    for(int i=0; i<Ar; i++){                    //����� ���� ������ add�� �����Ѵ�
      for(int j=0; j<Ac; j++){
        add[i][j] = a[i][j] + b[i][j];
      }
    }
  }
}

/*�� ����� �ּ�, ���� ũ��, ���� ũ�⸦ ���ڷ� �޾� ������ �ϴ� �Լ�*/
void subtraction_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){
  if(Ar==Br || Ac==Bc){                         //��� A�� B�� ��� ���� ũ�Ⱑ ���� ���ٸ� ������ �����Ѵ�
    sub = (int**)malloc(sizeof(int*)*Ar);       //������ ����� ���� ����� �޸𸮸� �Ҵ��Ѵ�

    for(int i=0; i<Ac; i++){                    
        sub[i] = (int*)malloc(sizeof(int)*Ac);
    }

    for(int i=0; i<Ar; i++){                    //����� ������ ������ sub�� �����Ѵ�
      for(int j=0; j<Ac; j++)
        sub[i][j] = a[i][j] - b[i][j];
    }
  }
}

/*��� A�� �ּ�, ���� ũ��, ���� ũ�⸦ ���ڷ� �޾� ��ġ����� ����� �Լ�*/
void transpose_matrix(int **a, int r, int c){
    trans = (int**)malloc(sizeof(int*)*c);         //��ġ����� ���� ũ��(A�� ���� ũ��)��ŭ �޸𸮸� �Ҵ��Ѵ�
  
    for(int i=0; i<c; i++){
        trans[i] = (int*)malloc(sizeof(int)*r);    //��ġ����� ���� ũ��(A�� ���� ũ��)��ŭ �޸𸮸� �Ҵ��Ѵ�
    }

    for(int i=0; i<c; i++){                        //A�� ��� ���� �ε����� �ٲپ� ��ġ����� ���� �޸𸮿� �����Ѵ�
      for(int j=0; j<r; j++){
        trans[i][j] = a[j][i];                     
      }
    }
}

/*�� ����� �ּ�, ���� ũ��, ���� ũ�⸦ ���ڷ� �޾� ���ϴ� �Լ�*/
void multiply_matrix(int **a, int **b, int Ar, int Ac, int Br, int Bc){
  if(Ac == Br){                                    //A�� ���� ũ��� B�� ���� ũ�Ⱑ ���ٸ� ������ �����ϵ��� �Ѵ�
    mul = (int**)malloc(sizeof(int*)*Ar);          //���� ����� ���� �޸𸮸� �Ҵ��Ѵ�
    for(int i=0; i<Ar; i++){
        mul[i] = (int*)malloc(sizeof(int)*Bc);
    }  
    for(int i=0; i<Ar; i++){                       //����� ���� ������ mul�� �����Ѵ�
      for(int j=0; j<Bc; j++){
        mul[i][j] = 0; 
        for(int k=0; k<Ac; k++){   
          mul[i][j] += a[i][k] * b[k][j];
        }
      }
    }
  }
}

/*����� �ּҿ� ���� ũ�⸦ ���ڷ� �ް�, �����Ҵ��� �޸𸮸� �����ϴ� �Լ�*/
void free_matrix(int **a, int size){
  for(int i=0; i<size; i++)             
    free(a[i]);
  
  free(a);
}
