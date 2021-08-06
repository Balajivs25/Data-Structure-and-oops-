#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL,*tail=NULL;
void insert_begin(int x)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	if(head==NULL)
	{
		head=tail=n;
	}
	else
	{
		n->next=head;
		head->prev=n;
		head=n;
	}
}
void insert_last(int x)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	if(head==NULL)
	{
		head=tail=n;
	}
	else
	{
		tail->next=n;
		n->prev=tail;
		tail=n;
	}
}
void insert_middle(int x,int pos)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	n->prev=NULL;
	if(pos==1)
	{
		insert_begin(x);
	}
	else
	{
		int i;
		struct node *p=head;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
			
		}
		n->next=p->next;
		n->prev=p;
		p->next=n;
		n->next->prev=n;
	}
}
void display()
{
	struct node *i;
	for(i=head;i!=NULL;i=i->next)
	{
		printf("%d-->",i->data);
	}
}
void display_in_reverse()
{
	struct node *i;
	for(i=tail;i!=NULL;i=i->prev)
	{
		printf("%d-->",i->data);
	}
}
void delete_at_begin()
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		struct node *t=head;
		head=head->next;
		free(t);
		head -> prev=NULL;
	}
}
void delete_at_last()
{
	tail=tail->prev;
	tail->next=NULL;
}
void delete_at_middle(int pos)
{
	if(pos==1)
	{
		delete_at_begin();
		
	}
	else
	{
		int i;
		struct node*p=head;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
			
		}
		p->next=p->next->next;
		p->next->prev=p;
		
	}
}
void search(int x)
{
    if(head==NULL)
    {
        printf("LIST Empty");
    }
    else
    {
        struct node *i;
        for(i=head;i!=NULL;i=i->next)
        {
            if(i->data==x)
            {
                printf("founded");
            }
            
        }
        printf("not Fouded");
    }
}
void count()
{
    struct node *p=head;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    printf("%d",c);
}
int main()
{
    insert_begin(10);
    insert_begin(20);
    insert_begin(30);
    insert_begin(40);
    insert_last(100);
    display();
    printf("\n");
    insert_middle(90,1);
    display();
    printf("\n");
    insert_middle(45,3);
    delete_at_begin();
    printf("\n");
    display();
   printf("\n");
   display_in_reverse();
   delete_at_last();
   printf("\n");
   display();
   delete_at_middle(3);
   printf("\n");
   display();
    printf("\n");
   display_in_reverse();
   count();
   
}
