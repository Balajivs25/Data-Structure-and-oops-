#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    //use python da , its easy
};
struct node *head=NULL,*tail=NULL;
void insert_begin(int x)
{
   struct node *n=(struct node*)malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;
   if(head==NULL)
   {
       head=tail=n;
   }
   else
   {
       n->next=head;
       tail->next=n;
       head=n;
   }
}
void insert_last(int x)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;
    if(head==NULL)
   {
       head=tail=n;
   }
   else
   {
       tail->next=n;
       n->next=head;
       tail=n;
       
   }
}
   
void insert_middle(int x,int pos)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;
   if(pos==1)
   {
       insert_begin(x);
   }
   else
   {
       int i;
       struct node*p=head;
       for(i=1;i<pos-1;i++)
       {
           p=p->next;
       }
       n->next=p->next;
       p->next=n;
   }
}
   void display()
   {
       struct node*i;
       for(i=head;i->next!=head;i=i->next)
       {
           printf("%d-->",i->data);
       }
       printf("%d-->",i->data);
   }
   void delete_begin()
   {
       if(head==NULL)
        return;
        else
        {
            struct node *t=head;
            head=head->next;
            tail->next=head; 
            free(t);
        }
   }
   void delete_end()
   {
       struct node *p;
       p=head;
       while(p->next->next!=head)
       {
           p=p->next;
       }
       p->next=head;
       free(tail);
       p=tail;
   
       
   }
   void delete_middle(int pos)
   {
        if(pos==1)
         {
          delete_begin();
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
    }
   }
 void count()
 {
     struct node *p=head;
     int c=0;
     while(p->next!=head)
     {
         c++;
         p=p->next;
     }
     c++;
     printf("count %d",c);
 }
   
int main()
{
    insert_begin(10);
    insert_begin(20);
    insert_begin(30);
    insert_begin(40);
    insert_last(100);
    insert_middle(45,1);
    display();
    printf("\n");
    insert_middle(45,3);
    display();
    printf("\n");
    delete_begin();
    display();
    delete_end();
    printf("\n");
    display();
    delete_middle(3);
    printf("\n");
    display();
    count();
}

