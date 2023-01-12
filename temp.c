//CODE USED IN THIS VIDEO
#include<stdio.h>
void quick(int A[] , int N , int BEG , int END , int *LOCPTR){
    int LEFT , RIGHT ;
    LEFT = BEG ; 
    RIGHT = END ; 
    *LOCPTR = BEG ; 
step2:    
    while(A[*LOCPTR]<=A[RIGHT] && *LOCPTR!=RIGHT)
        RIGHT-- ; 
    if(*LOCPTR == RIGHT)
    return ; 
    if(A[*LOCPTR]>A[RIGHT]){
        int temp ;
        temp = A[*LOCPTR];
        A[*LOCPTR] = A[RIGHT];
        A[RIGHT] = temp;
        *LOCPTR = RIGHT ; 
    }
    goto step3;
step3:
    while (A[LEFT]<=A[*LOCPTR] && LEFT!=*LOCPTR)  
        LEFT++;
    if(*LOCPTR == LEFT)
    return;
    if(A[LEFT]> A[*LOCPTR]){
        int temp ; 
        temp = A[LEFT];
        A[LEFT] = A[*LOCPTR];
        A[*LOCPTR] = temp ; 
        *LOCPTR = LEFT ; 
    }  
    goto step2;    
}

void  quick_sort(int A[] , int N){
    int TOP = -1  , BEG  , END , LOC; 
    int LOWER[10] , UPPER[10];
    if(N>1){
        TOP++;
        LOWER[TOP] = 0 ; 
        UPPER[TOP] = N - 1 ;

    }
    while(TOP != -1){
       BEG = LOWER[TOP];
       END = UPPER[TOP];
       TOP--;
       quick(A,N,BEG,END ,&LOC);
       if(BEG<LOC -1){
           TOP++;
           LOWER[TOP] = BEG ; 
           UPPER[TOP] = LOC - 1;
       }
       if(LOC+1<END){
           TOP++;
           LOWER[TOP]= LOC+1;
           UPPER[TOP] = END;

       }
    }
}

int main(){
    int A[] = {44 , 33 , 11 , 55 , 77 , 90 , 40 , 60 , 99 , 22 , 88 , 66};
    int i ;
    quick_sort(A,12);
    for(i=0;i<=11;i++)
    printf(" %d " , A[i]);
return 0;
}