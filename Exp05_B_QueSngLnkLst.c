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

LIST* insertelement(LIST *rear, LIST **front)
{
   LIST *nnode;
   int val;
   nnode = getnode();
   if(rear == NULL)
     {
       *front = nnode;
       rear = nnode;
     }
   else
      rear->link = nnode;
   rear = nnode;
   return rear;
}


LIST* removelement(LIST *front, LIST **rear)
{
   LIST *temp;
   int x;
   if(front == NULL)
      printf("Queue is Empty.....cannot remove.....\n");
   else
   {
      temp = front;
      x = temp->data;
      if(front == *rear)
      {
	 free(temp);
	 front = *rear = NULL;
      }
      else
	 {
	   front = temp->link;
	   temp->link = NULL;
	   free(temp);
	 }
      printf("%d is remove from an queue.....\n",x);
   }
  return front;
 }

void printqueue(LIST *start)
  {
    LIST *temp=start;

    if(start==NULL)
       printf("Queue is Empty.....\n");
    else
    {
       printf("Elements of Queue are.....\n");
       while(temp != NULL)
       {
	 printf("%d -> ",temp->data);
	 temp = temp->link;
       };
       printf("NULL\n");
    }
  }

int getelement(LIST *front)
{
   return front->data;
}

int main()
{
   LIST *front, *rear;
   int x,ch=1;
   front = NULL;
   rear = NULL;
   printf("Operations of an QUEUE using Linked List.....\n");
   printf("\n M E N U for Queue operations......\n");
   printf("1. Insert an element \n2. Delete an element from queue\n");
   printf("3. Print queue \n4. get element at front\n");
   printf("5. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : rear = insertelement(rear,&front);
		 printqueue(front);
		 break;
	case 2 : front = removelement(front,&rear);
		 printqueue(front);
		 break;
	case 3 : printqueue(front);
		 break;
	case 4 : if(front != NULL)
		 {
		    x = getelement(front);
		    printf("%d is at front of an queue.....\n",x);
		 }
		 else
		     printf("Queue is Empty.....\n");
		 break;
	case 5 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
     }
   return 0;
}

/* OUTPUT OF SAMPLE RUN 1
Operations of an QUEUE using Linked List.....

 M E N U for Queue operations......
1. Insert an element 
2. Delete an element from queue
3. Print queue 
4. get element at front
5. Quit

Enter your choice of operation : 1
Enter value : 12
Elements of Queue are.....
12 -> NULL

Enter your choice of operation : 1
Enter value : 13
Elements of Queue are.....
12 -> 13 -> NULL

Enter your choice of operation : 1
Enter value : 14
Elements of Queue are.....
12 -> 13 -> 14 -> NULL

Enter your choice of operation : 3
Elements of Queue are.....
12 -> 13 -> 14 -> NULL

Enter your choice of operation : 4
12 is at front of an queue.....

Enter your choice of operation : 2
12 is remove from an queue.....
Elements of Queue are.....
13 -> 14 -> NULL

Enter your choice of operation : 2
13 is remove from an queue.....
Elements of Queue are.....
14 -> NULL

Enter your choice of operation : 2
14 is remove from an queue.....
Queue is Empty.....

Enter your choice of operation : 1
Enter value : 123
Elements of Queue are.....
123 -> NULL

Enter your choice of operation : 5

*/
