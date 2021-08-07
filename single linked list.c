#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    
};
struct node *head=NULL,*tail=NULL;
void insert_begin(int x)
{
   struct node *n=malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;
   if(head==NULL)
   {
       head=tail=n;
   }
   else
   {
       n->next=head;
       head=n;
   }
}
void insert_last(int x)
{
    struct node *n=malloc(sizeof(struct node));
   n->data=x;
   n->next=NULL;
    if(head==NULL)
   {
       head=tail=n;
   }
   else
   {
       tail->next=n;
       tail=n;
   }
}
   
void insert_middle(int x,int pos)
{
    struct node *n=malloc(sizeof(struct node));
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
       for(i=head;i!=NULL;i=i->next)
       {
           printf("%d-->",i->data);
       }
   }
   void delete_begin()
   {
       if(head==NULL)
        return;
        else
        {
            struct node *t=head;
            head=head->next;
            free(t);
        }
   }
   void delete_end()
   {
       struct node *p;
       p=head;
       while(p->next->next!=NULL)
       {
           p=p->next;
       }
       p->next=NULL;
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
     while(p!=NULL)
     {
         c++;
         p=p->next;
     }
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
    insert_middle(45,3);
    printf("\n");
    delete_begin();
    delete_end();
    display();
    count();
}

