#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

typedef struct node LIST;

LIST* getnode()
{
  LIST* nn;
  nn = (LIST*)malloc(sizeof(LIST));
  printf("Enter value : ");
  scanf("%d",&nn->data);
  nn->link = NULL;
  return nn;
}

LIST* pushlist(LIST *TOPS)
{
   LIST *nnode;
   nnode = getnode();
   if(TOPS==NULL)
      TOPS = nnode;
   else
      nnode->link = TOPS;
   TOPS = nnode;
   return TOPS;
}

LIST* poplist(LIST *TOPS)
{
   LIST *temp = TOPS;
   if(TOPS==NULL)
       printf("Stack is underflow.....\n");
   else
      {
	 temp = TOPS;
	 TOPS = temp->link;
	 temp->link = NULL;
	 printf("%d is being popped.....\n",temp->data);
	 free(temp);
      }
   return TOPS;
}

void printlist(LIST *TOPS)
{
   LIST *temp = TOPS;
   if(TOPS==NULL)
       printf("Stack is underflow.....\n");
   else
      {
	 printf("Elements of stack are.....\n");
	 while(temp != NULL)
	 {
	    printf("%d\n",temp->data);
	    temp = temp->link;
	 }
	 printf("NULL\n");
      }
}

int peeknode(LIST *TOPS)
{
    return TOPS->data;
}

int main()
{
   LIST *top;
   int x,ch=1;
   top = NULL;
   printf("Creation of Stack.....\n");
   printf("\n M E N U for Stack using Linked List......\n");
   printf("1. Push node \n2. Pop node\n");
   printf("3. Peek \n4. Print Stack\n5. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : top = pushlist(top);
		 printlist(top);
		 break;
	case 2 : top = poplist(top);
		 printlist(top);
		 break;
	case 3 : if(top != NULL)
		 {
		    x = peeknode(top);
		    printf("%d is at top of Stack.....\n",x);
		 }
		 else
		   printf("Stack is Empty.....\n");
		 break;
	case 4 : printlist(top);
		 break;
	case 5 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
     }
   return 0;
}

/* OUTPUT OF SAMPLE RUN 1

Creation of Stack.....

 M E N U for Stack using Linked List......
1. Push node 
2. Pop node
3. Peek 
4. Print Stack
5. Quit

Enter your choice of operation : 1
Enter value : 12
Elements of stack are.....
12
NULL

Enter your choice of operation : 1
Enter value : 45
Elements of stack are.....
45
12
NULL

Enter your choice of operation : 1
Enter value : 67
Elements of stack are.....
67
45
12
NULL

Enter your choice of operation : 4
Elements of stack are.....
67
45
12
NULL

Enter your choice of operation : 3
67 is at top of Stack.....

Enter your choice of operation : 2
67 is being popped.....
Elements of stack are.....
45
12
NULL

Enter your choice of operation : 2
45 is being popped.....
Elements of stack are.....
12
NULL

Enter your choice of operation : 2
12 is being popped.....
Stack is underflow.....

Enter your choice of operation : 2
Stack is underflow.....
Stack is underflow.....

Enter your choice of operation : 1
Enter value : 23
Elements of stack are.....
23
NULL

Enter your choice of operation : 5

*/
