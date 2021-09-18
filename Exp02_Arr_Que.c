#include<stdio.h>
#include<stdlib.h>
#include "queueadt.c"

#define mxsize 5

void desesort(QUE *q)
{
   int i,j,temp;
   for(i=0;i<q->rear;i++)
      for(j=i+1;j<=q->rear;j++)
	 if(q->arr[i]<q->arr[j])
	   {
	      temp = q->arr[i];
	      q->arr[i] = q->arr[j];
	      q->arr[j] = temp;
	   }
}

int main()
{
   QUE q;
   int x,ch=1;
   initq(&q);
   printf("\n M E N U for operations on Queue......\n");
   printf("1. Add element in an queue \n");
   printf("2. Delete element from an queue \n");
   printf("3. Print queue \n");
   printf("4. Peek element\n");
   printf("5. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : insertq(&q);
		 if(!isemptyq(q))
		    printdq(q);
		 else
		    printf("\nEmpty Queue...!!!");
		 break;
	case 2 : removeq(&q);
		 if(!isemptyq(q))
		    printdq(q);
                 else
                    printf("\nEmpty Queue...!!!");
		 break;
	case 3 : printdq(q);
		 break;
	case 4 : if(!isemptyq(q))
		 {
		    x = peekq(q);
		    printf("%d is at the front of an queue.\n",x);
		 }
		 else
		    printf("Cannot peek as Queue is Empty.....\n");
		 break;
	case 5 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
   }
   return 0;
}
/* OUTPUT OF SAMPLE RUN 1
 M E N U for operations on Queue......
1. Add element in an queue
2. Delete element from an queue
3. Print queue
4. Peek element
5. Quit

Enter your choice of operation : 1
Enter value to be added : 12
Elements of queue are.....
12

Enter your choice of operation : 1
Enter value to be added : 23
Elements of queue are.....
12	23

Enter your choice of operation : 4
12 is at the front of an queue.

Enter your choice of operation : 2
12 is removed from queue.
Elements of queue are.....
23

Enter your choice of operation : 1
Enter value to be added : 234
Elements of queue are.....
23	234	

Enter your choice of operation : 1
Enter value to be added : 2345
Elements of queue are.....
23	234	2345	

Enter your choice of operation : 1
Enter value to be added : 12
Elements of queue are.....
23	234	2345	12	

Enter your choice of operation : 1
No space to add element in queue.....Cannot add.
Elements of queue are.....
23	234	2345	12	

Enter your choice of operation : 2
23 is removed from queue.
Elements of queue are.....
234	2345	12	

Enter your choice of operation : 2
234 is removed from queue.
Elements of queue are.....
2345	12	

Enter your choice of operation : 2
2345 is removed from queue.
Elements of queue are.....
12	

Enter your choice of operation : 2
12 is removed from queue.

Empty Queue...!!!
Enter your choice of operation : 1
Enter value to be added : 12
Elements of queue are.....
12	

Enter your choice of operation : 1
Enter value to be added : 234
Elements of queue are.....
12	234	

Enter your choice of operation : 3
Elements of queue are.....
12	234	

Enter your choice of operation : 4
12 is at the front of an queue.

Enter your choice of operation : 5

*/
