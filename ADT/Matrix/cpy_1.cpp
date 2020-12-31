#include<stdlib.h>

#include<stdio.h>

struct Node{

int col;

int data;

struct Node *next;

}*poly=NULL;



int main()
{


int n,m,i,c,j,i1;

struct Node *t,*last=NULL,*p;

printf("Enter number of rows:");

scanf("%d",&m);

printf("Enter number of cols:");

scanf("%d",&n);

struct Node *A[m];

for(i=0;i<m;i++){

A[i]=NULL;//(struct Node*)malloc(sizeof(struct Node));//no need to create node

printf("Enter number of non-zero elements in row %i:",i);

scanf("%d",&c);

for(i1=0;i1<c;i1++){

t=(struct Node*)malloc(sizeof(struct Node));
t->next=NULL; // include this line
printf("Enter col number:");

scanf("%d",&t->col);

printf("Enter data value:");

scanf("%d",&t->data);

if(A[i]==NULL){//this should be A[i]

A[i]=last=t;// this should be A[i]

}else{

last->next=t;//mistake here

last=t;

}

}

}

for(i=0;i<m;i++)

{

p=A[i];

for(j=0;j<n;j++)

{

if(p && j==p->col)//check if p is not null

{

printf("%d ",p->data);

p=p->next;

}

else

{

printf("0 ");

}

}

printf("\n");

}

return 0;

}
