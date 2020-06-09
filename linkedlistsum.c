#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
}*first = NULL,*second = NULL,*third=NULL;
void create(int A[],int n)
{     
int i;
struct Node *t,*last;
first = (struct Node *)malloc(sizeof(struct Node));
first->data = A[0];
first->next=NULL;
last = first;
for(i=1;i<n;i++)
{
t = (struct Node *)malloc(sizeof(struct Node));
t->data = A[i];
t->next = NULL;
last->next = t;
last = t;
}
}
// 2nd create function for b[]
void create2(int A[],int n)
{     
int i;
struct Node *t,*last;
second = (struct Node *)malloc(sizeof(struct Node));
second->data = A[0];
second->next=NULL;
last = second;
for(i=1;i<n;i++)
{
t = (struct Node *)malloc(sizeof(struct Node));
t->data = A[i];
t->next = NULL;
last->next = t;
last = t;
}
}
void display(struct Node *q)
{
while(q!=NULL)
{
printf("%d\n",q->data);
q = q->next;
}
}    
void rdisplay(struct Node *p)
{
while(p!=NULL)
{
rdisplay(p->next);
printf("%d",p->data); 
}
}
int count(struct Node *p)
{
int c = 0;
while(p)
{
c++;
p=p->next;
}
return c;
}
int sum(struct Node *p)
{
int sum = 0;
while(p)
{
sum = sum + p->data;
p = p->next;
}
return sum;
}
int add(struct Node *p)

{
if(p==0)
return 0;
else
{
return add(p->next) + p->data;
}
}
int max(struct Node *p)
{
int m = -32768;
while(p)
{
if(p->data > m)
m = p->data;
p=p->next;
}
return m;
}
int rmax(struct Node *p)
{
int x = 0;
if(p==0)
return -32768;
x=rmax(p->next);
if(x>p->data)
return x;
else 
return p->data;
}
struct Node * search(struct Node *p, int key)
{
while(p!=NULL)
{
if(key==p->data)
return p;
 p = p->next;
}
return NULL;
}
struct Node * rsearch(struct Node *p,int key)
{
if(p==NULL)
return NULL;
if(key==p->data)
return p;
return rsearch(p->next,key);
}
struct Node * searchfast(struct Node *p,int key)
{
struct Node *q = NULL;
while(p!=NULL)
{                     
if(key==p->data)
{
q->next=p->next;
p->next=first;
first=p;
return p;
}
q=p;
p=p->next;
}        
return NULL;
}
void insert(struct Node *p,int index,int x)
{
struct Node *t;
int i;
if(index < 0 || index > count(p)) 
 return;
t = (struct Node *)malloc(sizeof(struct Node));
t->data=x;
if(index==0)
{
t->next = first;
first = t;
}
else
{
for(i=0;i<index-1;i++)
p = p->next;
t->next = p->next;
p->next = t;
}
}
void insertlast(struct Node *t,int x) 
{
struct Node *last ;
t=(struct Node *)malloc(sizeof(struct Node));
t->data = x;
t->next = NULL;
if(first==NULL)
{
first=last=t;
}
else
{
last->next = t;
last=t;
}
}
void sortedlist(struct Node *p,int x)
{
struct Node *t,*q = NULL;
t = (struct Node *)malloc(sizeof(struct Node));
t->data = x;
t->next = NULL;
if(first==NULL)
first = t;
else
{
while(p && p->data < x)
{
q = p;
p=p->next;
}
if(p==first)
{
t->next = first;
first = t;
}
else
{
t->next = q->next;
q->next = t;
}
}
}
int  deletenode(struct Node *p,int index,int x)
{
int a = -1;
if(index < 1 || index > count(p))
{
return a;
}
else if(index==1)
{
struct Node *p = first;
first = first->next;
x = p->data;
free(p);
}
else if(index>0)
{
int i;
struct Node *p = first;
struct Node *q = NULL;
for(i=0;i<index-1;i++)
{
q = p;
p = p->next;
}
q->next = p->next;
x = p->data;
free(p);
}
return x;
}
int sortedlistasc(struct Node *p)
{
int x = -65336;
while(p!=NULL)
{
if(p->data<x)
return 0;
x = p->data;
p = p->next;
}
return 1;
}
int deleteduplicate(struct Node *p)
{

struct Node *q = p->next;
while(q!=NULL)
{
if(p->data != q->data)
{
p = q;
q = q->next;
}
else{
p->next = q->next;
free(q);
q = p->next;
}
}
}
void reverselinkedlist(struct Node *p)
{
int *a,i = 0;
struct Node *q = p;
a = (int *)malloc(sizeof(int)*count(p));
while(q!=NULL)
{
a[i] = q->data;
q = q->next;
i++;
}
q = p;
i--;
while(q!=NULL)
{
q->data = a[i];
q = q->next;
i--;
}
}
void reverseslidingpointer(struct Node *p)
{
p = first;
struct Node *q = NULL;
struct Node *r = NULL;
while(p!=NULL)
{
r = q;
q = p;
p = p->next;
q->next = r;
}
first = q;
}
void recursionreverse(struct Node *q,struct Node *p)
{
if(p!=NULL)
{
recursionreverse(p,p->next);
p->next = q;
}
else
first = q;
}
void concatenatetwolinkedlist(struct Node *p,struct Node *q)
{
third= p;
while(p->next!=NULL)
p = p->next;
p->next = q;
}
void mergetwolist(struct Node *p,struct Node *q)
{
struct Node *last;
if(p->data < q->data)
{
third = last = p;
p = p->next;
third->next = NULL;
}
else{
third = last = q;
q = q->next;
third->next = NULL;
}
while(p && q)
{
if(p->data < q->data)
{
last->next = p;
last = p;
p = p->next;
last->next = NULL;
}
else{
last->next = q;
last = q;
q = q->next;
last->next = NULL;
}
}
if(p) last->next=p;
if(q) last->next=q;
}
int isloop(struct Node *f)
{
struct Node *p,*q;
p=q=first;
do {
p = p->next;
q = q ->next;
q=q?q->next:q;
}while(p && q && p!=q);
if(p==q)
return 1;
else
return 0;
 }      
int main()
{
int A[]={1,2,3,4,5};
create(A,9);
struct Node *t1,*t2;
t1 = first->next->next;
t2 = first->next->next->next->next;
t2->next = t1;
printf("%d\n", isloop(first));
//int B[]={10,11,12,13,14,15,16,17,18};
//create2(B,9);
//mergetwolist(first,second);
//concatenatetwolinkedlist(first,second);
//printf("Concatenated output:\n");
//display(third);
//printf("\n\n");
//concatenatetwolinkedlist(first,r);
//recursionreverse(NULL,first);
//deleteduplicate(first);
//printf("%d\n",sortedlistasc(first));
//if(sortedlistasc(first))
//{
//printf("It is sorted");
//}
//else
//{
//printf("It is not sorted");
//}
//deletenode(first,2,5);
//sortedlist(first,55);
//insertlast(first,996);
//struct Node *temp;
//printf("%d",count(first));
//printf("%d",add(first));
//printf("%d",max(first));
//printf("%d",rmax(first));
//temp = searchfast(first,56);
//temp = searchfast(first,7);
//temp = searchfast(first,8);
//if(temp)
//printf("the key value is found %d\n",temp->data);
//else
//printf("key not found");
//printf("first\n");
//display(first);
//printf("\n\n");
//printf("second\n");
//display(third);
//printf("\n\n");
return 0;
}

