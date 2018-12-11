#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *last=NULL,*ptr=NULL,*temp=NULL;
int item,i,ch;
void insertend()
{	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&item);
	temp->data=item;
	temp->link=NULL;
	if(last==NULL)
	{
		last=temp;
		temp->link=last;
	}
	else
	{
		temp->link=last->link;
		last->link=temp;
		last=temp;
	}
}
void insertbeg()
{	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element");
	scanf("%d",&item);
	temp->data=item;
	temp->link=NULL;
	if(last==NULL)
	{
		last=temp;
		temp->link=last;
	}
	else
	{
		temp->link=last->link;
		last->link=temp;
	}
}
void nodecount()
{
	int count=0;
	if(last==NULL)
	printf("Empty\n");
	else
	{
		ptr=last->link;
		do
		{
			count++;
			ptr=ptr->link;

		}while(ptr!=last->link);
		printf("%d elements\n", count);
	}

}
void display()
{
	if(last==NULL)
	printf("Empty");
	else
	{	ptr=last->link;
		do
		{
			printf("%d-->",ptr->data);
			ptr=ptr->link;
		}while(ptr!=last->link);
	}
}
void delend()
{	
	
	if(last==NULL)
	printf("Empty");
	else if(last->link==last)
	{
		ptr=last;
		last=NULL;
		free(ptr);
	}
	else
	{
		ptr=last->link;
		while(ptr!=last)
		{
			temp=ptr;
			ptr=ptr->link;
		}
		
		temp->link=last->link;
		last=temp;
		free(ptr);
		
	}
}
void delbeg()
{
	if(last==NULL)
	printf("Empty");
	else if(last->link==last)
	{
		ptr=last;
		last=NULL;
		free(ptr);
	}
	else
	{
		ptr=last->link;
		last->link=ptr->link;
		free(ptr);
	}
}

	
void main()
{
	while(1)
	{
		printf("\n1.Insert at end\n2.Insert at beginning\n3.Count\n4.Display\n5.Delete at beginning\n6.Delete at end\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insertend();break;
			case 2 : insertbeg();break;
			case 3 : nodecount();break;
			case 4 : display();break;
			case 5 : delbeg();break;
			case 6 : delend();break;
			default: exit(0);
		}
	}
}

				

		

	
	

