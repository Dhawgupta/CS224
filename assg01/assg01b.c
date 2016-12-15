
  	Sign Out
Compose   Addresses   Folders   Options   Search   Help   Calendar   Bookmarks   	IITP


Viewing a text attachment - View message
Download this as a file

#include<stdio.h>
#include<stdlib.h>
 
struct node{
        int data;
        struct node *p;
};
struct node *head = NULL;
struct node *tail = NULL;

int main()
{        
        printf("Select from the choices :\n");
        printf("\n1. Insert at Front \n2. Insert at end\n3. Delete from Front\n4. Delete
from end\n5. Delete Largest\n6. Delete Smallest\n7. Display");
        int c;
        scanf("%d",&c);
        switch(c)
        {
        
        }
}

void insert_front()
{
        int d;
        printf("Enter the data to insert: ");
        scanf("%d",&d);
        //int s = size(linked_list)
        struct node *temp = malloc(sizeof(struct node));
        temp->data = d;
        temp->p = head;
        //if(head->p == NULL)
        head = temp;
  free(temp);
}

void insert_end()
{
        int d;
        printf("Enter the data to insert; ");
        scanf("%d",&d);
        struct node *temp = malloc(sizeof(struct node));
        temp->data = d;
        temp->p = NULL;
        tail->p = temp;
        tail->p = temp;
        
}

void delete_front()
{
        struct node *temp = front;
        front = front->p;
        free(temp);
}
void delete_end()
{
        struct node *temp = head;
        if ( temp->p != NULL)
        {        
                while(temp->p->p != NULL)
                {
                        temp = temp->p;
                }
                tail = temp;
                temp = temp->p;
                tail->p = NULL;
        }
        else 
        {                
                free(temp);
                printf("Now list is EMPTY!!");
        }
}
void delete_largest()
{
        struct node *temp = head;
        int max = head->data;
        struct node *maxp = head;
        while(temp->p != NULL)
        {
                if(max < temp->data)
                {
                        max = temp->data;
                        maxp = temp;
                }
                temp = temp->p;
        }
        if(head->p == NULL)
        {
                temp = head;
                free(temp);
                head = NULL;
                 tail = NULL;
        }
        if(head->p->p ==NULL)
        {
                if(head->data > tail->data)
                {
                        temp = head;
                        head=  tail;
                        free(temp);
                }
                else 
                {
                        temp = tail;
                        tail = head;
                        free(temp);
                }

                
                
                                  
                
                

        

 


