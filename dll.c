#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *llink;
 struct node *rlink;
 };

 struct node *temp,*ptr,*head=NULL;

void insert_end()
{
 temp=(struct node*)malloc(sizeof(struct node*));
 printf("Enter data\n");
 scanf("%d",&temp->data);
 temp->llink=NULL;
 temp->rlink=NULL;

 if(head==NULL)
 {
 head=temp;
 }

 else
 {
 ptr=head;
 while(ptr->rlink!=NULL)
 {
 ptr=ptr->rlink;
 }
 ptr->rlink=temp;
 temp->llink=ptr;
 }
}
void insert_beg()
{
 temp=(struct node*)malloc(sizeof(struct node*));
 printf("Enter the data\n");
 scanf("%d",&temp->data);
 temp->llink=NULL;
 temp->rlink=NULL;

 if(head==NULL)
 head=temp;
 else
 {
 temp->rlink=head;
 head->llink=temp;
 head=temp;
 }
}

void insert_loc()
{
 int count=0,pos;
 ptr=head;

 while(ptr!=NULL)
 {
 count++;
 ptr=ptr->rlink;
 }
 printf("Enter the position of the node\n");
 scanf("%d",&pos);

 if(pos==1)
 insert_beg();
 else if(pos==count+1)
 insert_end();
 else if(pos>1&&pos<=count)
 {
 temp=(struct node*)malloc(sizeof(struct node*));
 printf("Enter the datan");
 scanf("%d",&temp->data);
 temp->llink=NULL;
  temp->rlink=NULL;

 ptr=head;
 int i;
 for(i=1;i<pos-1;i++)
 {
  ptr=ptr->rlink;
  }
  temp->rlink=ptr->rlink;
  temp->llink=ptr;
  ptr->rlink->llink=temp;
  ptr->rlink=temp;
 }
 else
 {
 printf("Wrong location\n");
 }
}
void del_beg()
{
  if(head==NULL)
  printf("Linked list is empty\n");
  else if(head->rlink==NULL)
  head=NULL;
  else
  {
  ptr=head;
  head=head->rlink;
  head->llink=NULL;
  free(ptr);
  }
}

void del_end()
{
 if(head==NULL)
 printf("List is empty\n");
 else if(head->rlink==NULL)
 head=NULL;
 else
 {
 ptr=head;
 while(ptr->rlink!=NULL)
 ptr=ptr->rlink;
 
 temp=ptr;
 (ptr->llink)->rlink=NULL;
 free(temp);
 }
}

void display()
{
    if(head==NULL)
    printf("List is empty\n");
    else
    {
    ptr=head;
    while(ptr!=NULL)
    {
      printf("%d-->",ptr->data);
      ptr=ptr->rlink;
     }
   }
}
 
     void count_node()
    {
    int count=0;
    if(head==NULL)
    printf("List is empty");
    else
    {
    ptr=head;
    while(ptr!=NULL)
    {
    count++;
    ptr=ptr->rlink;
    }
    printf("Count=%d",count);
    }
    }
   
 void search_node()
 {
 
 int item,flag=0;
 printf("Enter the data to be searched\n");
 scanf("%d",&item);
 
 if(head==NULL)
   printf("List is empty\n");
  
   else
   {
   ptr=head;
   while(ptr!=NULL)
   {
    if(item==ptr->data)
    {
    printf("Item found");
    flag=1;
    break;
    }
    else
    ptr=ptr->rlink;
    }
    if(flag==0)
    printf("Item not found");
    }
    }
   
     void del_loc_based()
       {
         int count=0,pos;
         printf("Enter the location\n");
         scanf("%d",&pos);
         ptr=head;
         while(ptr!=NULL)
         {
         count++;
         ptr=ptr->rlink;
         }
        
         if(pos==1)
         del_beg();
         else if(pos>1&&pos<=count)
         {
         ptr=head;
         int i;
         for(i=1;i<pos;i++)
         {
         temp=ptr;
         ptr=ptr->rlink;
         }
         temp->rlink=ptr->rlink;
         ptr->llink=temp;
         }
         else
         printf("Wrong location\n");
       }
  
  
   
   
  void main()
     {
       while(1)
       {
       int ch;
       printf("\n1.Insert_end\n2.Insert_beg\n3.Insert at loc\n4.Search node\n5.Display\n6.Count data nodes\n7.Delete_beginning\n8.Delete_end\n9.Delte_at_loc\n10.Exit\n");
       printf("Enter your choice \n");
       scanf("%d",&ch);
      
       switch(ch)
       {
       case 1:insert_end();
       break;
      
       case 2:insert_beg();
       break;
      
       case 3:insert_loc();
       break;
      
       case 4:search_node();
       break;
      
       case 5:display();
       break;
      
       case 6:count_node();
       break;
      
       case 7:del_beg();
       break;
      
       case 8:
       del_end();
       break;
      
       case 9:
       del_loc_based();
       break;
     
       case 10:
       exit(0);
      
       default:
       printf("Wrong choice");
      
      
    }
    }
}
