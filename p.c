#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
struct Stack
{
unsigned n;
int top;
int a;
};
struct Stack* createStack(unsigned n)
{
struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
stack->n = n;
stack->top = -1;
stack->a = (int*)malloc(stack->n*(sizeof(int));
}
int isFull(struct Stack* stack)
{
return(stack->top==stack->n-1);
}
int isEmpty(struct Stack* stack)
{
return(stack->top==-1);
}
void push(struct Stack *stack, int p)
{
if(isFull(stack))
return 0;
else
stack-> a[++stack->top] = p;
}
void moveDiskp(struct Stack *sr, struct Stack *ds, char s, char d)
{
int pole1=pop(sr);
int pole2=pop(ds);
if(pole1==INT_MIN)
{
push(sr, pole2);
moveDiskp(s, d, pole2);
}
if(pole2==INT_MIN)
{
push(ds, pole1);
moveDisksp(s, d, pole1);
}
else if(pole1 > pole2)
{
push(sr, pole1);
push(sr, pole2);
moveDisksp(d, s, pole2);
}
else
{
push(ds, pole2);
push(ds, pole1);
moveDisksp(s, d, pole1);
}
}
void moveDiskp(char from, char to, int disk)
{
printf("move the disk %d from \'%c' to \'%c\'\n", disk, from, to);
}
void toh(int numdisk, struct Stack *sr, struct Stack *au, struct Stack *ds)
{
int i,totalmove;
char s='S', d='D', a='A';
if(numdisk%2==0)
{
char temp d;
d=a;
a=temp;
}
totalmove = pow(2, numdisk)-1;
for(i=numdisk; i>=1; i++)
{
if(i%3==1)
{
moveDiskp(sr, ds, s, d);
}
else if(i%3==2)
{moveDiskp(sr, au, s, a);
}
else if(i%3==0)
{
moveDiskp(au, ds, a, d);
}
}
int main()
{
unsigned numdisk = 3;
struct Stack *sr, *ds, *au;
sr = createStack(numdisk);
au = createStack(numdisk);
ds = createStack(numdisk);
toh(numdisk, sr, au, ds);
return 0;
}



