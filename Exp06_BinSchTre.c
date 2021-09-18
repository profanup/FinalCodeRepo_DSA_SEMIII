#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct bstreenode
{
  int info;
  struct bstreenode *left,*right;
}BST;

BST * getnode()
{
  BST *nn;
  nn = (BST *)malloc(sizeof(BST));
  printf("Enter the value : ");
  scanf("%d",&nn->info);
  nn->left = NULL;
  nn->right = NULL;
  return nn;
}

BST * createtree(BST *root)
{
  BST *nn,*temp,*prnt;
  int ch=1;
  while(ch)
  {
     nn = getnode();
     if(root == NULL)
       root = nn;
     else
       {
	 temp = root;
	 while(temp != NULL)
	   {
	      prnt = temp;
	      if(nn->info == temp->info)
		{
		  printf("Warning ! Duplicate values are not allowed....\n");
		  break;
		}
	      if(nn->info < temp->info)
		temp = temp->left;
	      else
		 temp = temp->right;
	   }
	 if(temp==NULL)
	   {
	     if(nn->info < prnt->info)
		prnt->left = nn;
	     else
		prnt->right = nn;
	   }
       }
       printf("Do you want to add node in the BST (1-Yes/0-No) : ");
       scanf("%d",&ch);
     }
     return root;
}

void inorder(BST *root)
{
  if(root != NULL)
    {
       inorder(root->left);
       printf("%d\t",root->info);
       inorder(root->right);
    }
}

void preorder(BST *root)
{
  if(root != NULL)
    {
       printf("%d\t",root->info);
       preorder(root->left);
       preorder(root->right);
    }
}

void postorder(BST *root)
{
  if(root != NULL)
    {
       postorder(root->left);
       postorder(root->right);
       printf("%d\t",root->info);
    }
}

BST * insertnode(BST *root)
{
   BST *nn,*temp,*prnt;
   nn = getnode();
   temp = root;
   if(root == NULL)
     {
       root = nn;
       return root;
     }
   while(temp != NULL)
      {
	 prnt = temp;
	 if(nn->info == temp->info)
	  {
	    printf("Warning ! Duplicate values are not allowed....\n");
	    break;
	  }
	 if(nn->info < temp->info)
	    temp = temp->left;
	 else
	    temp = temp->right;
      }
    if(temp==NULL)
     {
       if(nn->info < prnt->info)
	 prnt->left = nn;
       else
	  prnt->right = nn;
     }
   return root;
}

void searchnode(BST *root)
{
   int val;
   BST *temp;
   temp = root;
   printf("Enter value to be searched : ");
   scanf("%d",&val);
   while((temp != NULL) && (val != temp->info))
     {
	if(val < temp->info)
	   temp = temp->left;
	else
	   temp = temp->right;
     }
   if(temp != NULL)
     printf("%d is present in the tree......\n",val);
   else
      printf("%d is not present in the tree......\n",val);
}

BST * deletenode(BST *root)
{
   BST *temp, *prev, *curr;
   int val;
   printf("Enter value to be deleted : ");
   scanf("%d",&val);
   prev = NULL;
   temp=root;
   while((temp != NULL) && (val != temp->info))
     {
	prev = temp;
	if(val < temp->info)
	   temp = temp->left;
	else
	   temp = temp->right;
     }
   if(temp == NULL)
     {
       printf("%d is not present in the BST.....cannot delete.....\n",val);
       return root;
     }
   else
      {
	if(prev != NULL)
	{
	 if((temp->left == NULL) && (temp->right == NULL))
	   {
	     if(val < prev->info)
		prev->left = NULL;
	     else
		prev->right = NULL;
	   }
	 else
	    if((temp->left != NULL) && (temp->right == NULL))
	     {
	       if(val < prev->info)
		 prev->left = temp->left;
	       else
		 prev->right = temp->left;
	     }
	    else
	       if((temp->left == NULL) && (temp->right != NULL))
		{
		  if(val < prev->info)
		    prev->left = temp->right;
		  else
		     prev->right = temp->right;
		}
	       else
		 {
		   curr = temp->right;
		   while(curr->left != NULL)
		      curr = curr->left;
		   curr->left = temp->left;
		   if(temp->info < prev->info)
			prev->left = temp->right;
		   else
			prev->right = temp->right;
		 }
	    }
	 if(temp == root)
	 {
	   curr = temp->right;
	   while(curr->left != NULL)
	       curr = curr->left;
	   curr->left = temp->left;
	   root = temp->right;
	 }
	 temp->left = temp->right = NULL;
	 free(temp);
	 printf("%d is deleted from the BST.....\n",val);
      }
   return root;
}

int leafcnt(BST *root)
{
   int c = 0;
   if(root != NULL)
     {
       c = c + leafcnt(root->left);
       if((root->left == NULL) && (root->right == NULL))
	  c++;
       c = c + leafcnt(root->right);
     }
   return c;
}

int totalcnt(BST *root)
{
   int c=0;
   if(root != NULL)
     {
       c = c + totalcnt(root->left);
       c++;
       c = c + totalcnt(root->right);
     }
   return c;
}

int parntcnt(BST *root)
{
   int c = 0;
   if(root != NULL)
     {
       c = c + parntcnt(root->left);
       if((root->left != NULL) || (root->right != NULL))
	  c++;
       c = c + parntcnt(root->right);
     }
   return c;
}

int main()
{
   BST *root;
   int count=0,ch=1;
   root = NULL;
   printf("Creation of Binary Search Tree.....\n");
   root = createtree(root);
   printf("\n M E N U for Binary Search Tree operations......\n");
   printf("1. Insert node \n2. Delete node\n");
   printf("3. Search node \n4. Inorder Traversal of tree\n5. Preorder Traversal of tree\n");
   printf("6. Postorder Traversal of tree\n7. Count total nodes of tree\n");
   printf("8. Count leaf nodes of tree\n9. Count parent nodes of tree\n");
   printf("10.Exit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : root = insertnode(root);
		 break;
	case 2 : root = deletenode(root);
		 break;
	case 3 : searchnode(root);
		 break;
	case 4 : if(root != NULL)
		    {
		       printf("Inorder Traversal of BST is .....\n");
		       inorder(root);
		    }
		 else
		     printf("BST is Empty.....\n");
		 break;
	case 5 : if(root != NULL)
		    {
		       printf("Preorder Traversal of BST is .....\n");
		       preorder(root);
		    }
		 else
		     printf("BST is Empty.....\n");
		 break;
	case 6 : if(root != NULL)
		    {
		       printf("Postorder Traversal of BST is .....\n");
		       postorder(root);
		    }
		 else
		     printf("BST is Empty.....\n");
		 break;
	case 7 : count = totalcnt(root);
		 printf("Total number of nodes in the BST = %d \n",count);
		 break;
	case 8 : count = leafcnt(root);
		 printf("Total number of leaf nodes in the BST = %d \n",count);
		 break;
	case 9 : count = parntcnt(root);
		 printf("Total number of parent nodes in the BST = %d \n",count);
		 break;
	case 10: exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
     }
   return 0;
}
