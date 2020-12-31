#include <stdio.h>
#include <stdlib.h>

struct Node{
int col;
int data;
struct Node *next;
}*first=NULL;

void Create(struct Node *A[],int m,struct Node *p)
{
int i,n,k;
struct Node *last=NULL;

    for(i=0;i<m;i++){
        printf("enter nuber of element in row %d ",i);
        scanf("%d",&k);

        A[i]=NULL;

        for(int j=0;j<k;j++){
                p=(struct Node *)malloc(sizeof(struct Node));

                printf("enter column and data ");

                scanf("%d%d",&p->col,&p->data);

                p->next=NULL;

                if(A[i]==NULL)
                    {
                    A[i]=p;
                    last=p;
                   }

                    else {
                    last->next=p;
                    last=p;
                }
        }
}

}

void Display(struct Node *A[],int m,int n)

{

struct Node *p=NULL;

int i,j;

for(i=0;i<m;i++)

{

p=A[i];

for(j=0;j<n;j++)

{

if(p && j==p->col)

{

printf("%d ",p->data);

p=p->next;

}

else

printf("0 ");

}

printf("\n");

}

}

int main()

{

struct Node *A[4];

Create(A,2,first);

Display(A,2,3);

return 0;

}
