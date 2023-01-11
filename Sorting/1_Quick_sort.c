#include<stdio.h>
#include<stdlib.h>

void quick(int A[], int N,  int Beg, int End , int *LocPtr){
        int Left, Right,temp;
        Left = Beg;
        Right= End;
        *LocPtr=Beg;
        step2:
        while (A[*LocPtr]<=A[Right]&&*LocPtr!=Right)
        {
            Right--;
        }
        if(*LocPtr==Right)
        return;
        if(A[*LocPtr]>A[Right]){
            temp=A[*LocPtr];
            A[*LocPtr] = A[Right];
            A[Right] = temp;
            *LocPtr = Right;
        }
        goto step3;
        step3:
        while(A[Left]<=A[*LocPtr]&&Left!=*LocPtr)
        Left++;
            if(*LocPtr==Left)
            return;
            if(A[Left]>A[*LocPtr]){
                temp=A[Left];
                A[Left] = A[*LocPtr];
                A[*LocPtr]=temp;
                *LocPtr=Left;
            }
            goto step2;
}
void quick_Sort(int A[], int N){
    int Beg,End,Loc,Top=-1;

    int Lower[10] ,Upper[10];
    if(N>1)
    {
        Top++;
        Lower[Top] = 0;
        Upper[Top] = N-1;
    }
    while(Top!=-1){
        Beg = Lower[Top];
        End = Upper[Top];
        Top--;
        quick(A,N,Beg,End,&Loc);
        if(Beg<Loc-1){
            Top++;
            Lower[Top]=Beg;
            Upper[Top] = Loc-1;   
        }
        if(Loc+1<End){
            Top--;
            Lower[Top] = Loc+1;
            Upper[Top] = End;
        }
    }
}
int main(){

    int A[]= {13,45,6,43,211,98,65};
    quick_Sort(A,7);
    for(int i = 0 ; i<7;i++){
        printf("%d, ", A[i]);
    }
    return 0;
}