#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head=NULL,*ptr=NULL,*temp=NULL;
int item,i,ch;
void insertend()
{	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&item);
	temp->data=item;
	temp->link=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
}
void insertbeg()
{	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&item);
	temp->data=item;
	temp->link=NULL;
	if(head==NULL)
	head=temp;
	else
	{
		temp->link=head;
		head=temp;
	}
}
int nodecount()
{
	int count=0;
	if(head==NULL)
	return 0;
	
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->link;

		}return count;
	}

}
void display()
{
	if(head==NULL)
	printf("Empty");
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}
void searchnode()
{
	int n;
	printf("Enter data");
	scanf("%d",&n);
	if(head==NULL)
	printf("Empty");
	else
	{
		ptr=head;
		int flag=1;
		while(ptr!=NULL)
		{
			if(item==ptr->data)
			{
				printf("Item found");
				flag=0;
				break;
			}
			else
			ptr=ptr->link;
			
		}
	
	if(flag==1)
	printf("element not found");
	}
}
void location()
{
	int count=nodecount();
	int pos;
	ptr=head;
	printf("Enter the position of the node");
	scanf("%d",&pos);
	if(pos==1)
	insertbeg();
	else if(pos==count+1)
	insertend();
	else if(pos>1 && pos<=count)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("Enter the element");
			scanf("%d",&item);
			temp->data=item;
			temp->link=NULL;
			for(i=1;i<pos-1;i++)
			ptr=ptr->link;
			temp->link=ptr->link;
			ptr->link=temp;
		}
		else
		printf("Invalid Position");
}
void delend()
{	
	
	if(head==NULL)
	printf("Empty");
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			temp=ptr;
			ptr=ptr->link;
		}
		if(ptr==head)
		head=NULL;

		temp->link=NULL;
		free(ptr);
		
	}
}
void delbeg()
{
	if(head==NULL)
	printf("Empty");
	else
	{
		ptr=head;
		head=head->link;
		free(ptr);
	}
}
void delloc()
{
	int count=nodecount();
	int pos;
	ptr=head;
	printf("Enter the position of the node");
	scanf("%d",&pos);
	if(pos==1)
	delbeg();
	else if(pos==count+1)
	delend();
	else if(pos>1 && pos<=count)
	{
		for(i=1;i<pos;i++)
		{
			temp=ptr;
			ptr=ptr->link;
		}
		temp->link=ptr->link;
	}	free(ptr);
}
void reverse()
{
	
        struct node *current = head; 
        struct node *prev = NULL, *next = NULL; 
  
  
        while (current != NULL) 
        { 
            
            next = current->link; 
            current->link = prev; 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
	
void main()
{
	while(1)
	{
		printf("\n1.Insert at end\n2.Insert at beginning\n3.Insert in location\n4.Search\n5.Display\n6.Delete at beginning\n7.Delete at end\n8.Delete by location\n9.Reversing");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insertend();break;
			case 2 : insertbeg();break;
			case 3 : location();break;
			case 4 : searchnode();break;
			case 5 : display();break;
			case 6 : delbeg();break;
			case 7 : delend();break;
			case 8 : delloc();break;
			case 9 : reverse();break;
			default: exit(0);
		}
	}
}

				

		

	
	

