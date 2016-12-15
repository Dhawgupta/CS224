#include <stdio.h>
#include <string.h>
#include <stdlib.h>

		
typedef struct subjects
{
	char name[6];
	struct subjects	*next;
}subjects; // Structure for Subjects i.e. Linked List
typedef struct student
{
	char rollno[9];
	char name[21];
	float cpi;
	int nosub;
	subjects *head; // Head for subjects
	subjects *tail; // Tail for subjects
	struct student *parent; // Parent 
	struct student *left; // Left child 
	struct student *right; // Right child
}student; // Structure for the student 
student *stud_top = NULL;
void add_student(); // Add a student 
void add_subject_to_student(); // Add a Subject
void update_cpi(); // Upadte the Cpi
void print(student *); // Print the values
void successor(); // Print the Successor
void height_tree(); // Find the height of tree
void delete_student_by_name(); //  Delete student by their names
void delete_student_by_rollno(); //  Delete student by the Roll Number
int main()
{
	while(1){
	printf("Enter from the folllowing choice : \n");
	printf("1. Add a student\n2. Add a subject to a student\n3. Update cpi\n");
	printf("4. Print\n5. Successor\n6. Height\n7. Delete a Student by Name\n8. Delete a student by roll No.\n9. Exit\n:  ");
	int n;
	scanf("%d",&n);

	do // Menu
	{
	switch(n)
	{ 
		case 1:add_student();
				break;
		case 2:add_subject_to_student();
				break;
		case 3:update_cpi();
				break;
		case 4:print(stud_top);
				break;
		case 5:successor();
				break;
		case 6:height_tree();
				break;
		case 7:delete_student_by_name();
				break;
		case 8:delete_student_by_rollno();
				break;
		case 9: printf("Exiting..........\n");
				break;
		default:printf("Sorry Wrong Choice");
	}
	}while(n<1 || n>9);
	if(n == 9)
		break;
}

}
void insert_subject(student *t) // Normal Linked list insertion
{
	subjects *temp = (subjects *)malloc(sizeof(subjects)); //Allocating memory for subjects
	printf("Enter the Subject taken >");scanf("%s",temp->name);
	temp->next = NULL; // Setting up the temporary subject node
	if (t->tail == NULL)
	{
		t->tail= temp;
		t->head = temp;
		return;
	}
	t->tail->next = temp; // Set up the tail and Head
	t->tail = temp;
}
student* search_tree(student * t, char a[9]) // To search the tree and return the pointer
{
	if(t == NULL || strcmp(t->rollno,a) == 0) // Case where the name matches or It is at the end
		return t; 
	if (strcmp(a,t->rollno) < 0) return search_tree(t->left,a); // Other Wise seach the left and right tree
	else return search_tree(t->right,a);

}
void print(student *p) // To print the  student in sorted order
{
	if(p != NULL)
	{
		print(p->left); // First print the Left node I.e. to Sort
		printf("%s %s %f ",p->rollno,p->name,p->cpi); // Printing the Currnet Node i.e. Middle one
		subjects *temp;
		temp = p->head;
		while(temp != NULL)
		{
			printf("%s ",temp->name);
			temp = temp->next;
		}	
		printf("\n");
		print(p->right); // printing the right hand side node
	}
	
}	
void add_student()
{	
	student *t; // New student pointer
	t = (student *)malloc(sizeof(student)); // Add Details
	printf("\nRoll No > ");scanf("%s",t->rollno);		
	printf("\nName > "); scanf("%s",t->name);	
	printf("\nCPI > ");scanf("%f",&t->cpi);
	printf("\nNo  of Subjects Taken > ");scanf("%d",&t->nosub);
	int i=0;
	t->head = NULL;
	t->tail = NULL;
	t->parent = NULL;
	for(i=0 ;i< t->nosub;i++)
		insert_subject(t); // Entering the subjects
	t->left = NULL;
	t->right = NULL;
	student *y = NULL;
	student *x = stud_top;
	while(x != NULL)
	{
		y = x;
		int i= strcmp(t->rollno,x->rollno); // Checking for the brnach and finding the appropiate place
		if(i<0)	
			x = x->left; // going left is key is smaller
		else if(i>0) 
			x = x->right; // going right is key is larger
	}
	t->parent = y;
	
	if(y!= NULL)
		 i=strcmp(t->rollno,y->rollno);
	if(y == NULL) 
		stud_top = t;
	else if(i<0) 
		y->left = t;
	else if(i>0)
		y->right = t;
	return;
}
void add_subject_to_student()
{
	char a[9]; 
	printf("Enter the Roll No > ");scanf("%s",a);
	student *p = search_tree(stud_top,a);
	if(p == NULL){ printf("\nEntry Not found"); return;}
	else
	{
		p->nosub++;
		insert_subject(p); // Adding the subject
	}
}
void update_cpi()
{
	char a[9]; 
	printf("Enter the Roll No > ");scanf("%s",a);
	student *p = search_tree(stud_top,a); // Searching the ROll Number to Change
	if(p == NULL){ printf("\nEntry Not found"); return;}
	else
	{
		printf("\nEnter the New CPi instead of %f :",p->cpi);
		scanf("%f",&p->cpi); 
	}
}
student *tree_min(student *t) // For finding the minimum of Tree
{
	while (t->left != NULL) // Going to the lef always
		t = t->left;
	return t;
}
student *tree_successor()
{
	printf("Enter the Roll No : ");
	char a[9];
	scanf("%s",a);
	student *p = search_tree(stud_top,a); // Search the roll number 
	if(p->right!= NULL) // Go to the right if not null
		return tree_min(p->right); // Find the minimum of the right bracnh of treee
	student* y = p->parent; // Taking the Parent 
	while(y != NULL && p == y->right) 
	{
		p = y;
		y = y->parent;

	}
	return y;
}
void successor() // the successor of the node
{
	student *p = tree_successor();
	printf("%s %s %f ",p->rollno,p->name,p->cpi);
		subjects *temp;
		temp = p->head;
		while(temp != NULL)
		{
			printf("%s ",temp->name);
			temp = temp->next;
		}	
		printf("\n");
}
int height(student *x)
{
	int height_left =0,height_right = 0;
	
	if(x->left!=NULL)
		height_left =  height(x->left);
	if(x->right != NULL)
		height_right = height(x->right);
	if(height_right > height_left)
		return 1+ height_right;
	else if(height_right < height_left)
		return 1+ height_left;
	else
		return height_left +1;

}
void height_tree()
{
	int h  =height(stud_top);
	printf("\nThe Height of Tree is : %d",h);
}
void tree_transplant(student *u,student *v) // transfer node v in place of node u
{
	if (u->parent == NULL)
		stud_top = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else u->parent->right = v;
	if(v != NULL)
		v->parent = u->parent;
}
void delete_node(student *p)
{
	if(p->left == NULL)
		tree_transplant(p,p->right); // if Left child id not there go to right and skip p
	else if(p->right == NULL) tree_transplant(p,p->left); // if right is NULL same
	else
	{
		student* y = tree_min(p->right); // Find the successor of p to switch 
		if(y->parent != p) 
		{
			tree_transplant(y,y->right);
			y->right = p->right;
			y->right->parent = y;
		}
		tree_transplant(p,y);
		y->left = p->left;
		y->left->parent =y;
	}

}
void delete_student_by_rollno()
{
	printf("Enter the Roll No : ");
	char a[9];
	scanf("%s",a);
	student *p = search_tree(stud_top,a); // Search for Roll number
	delete_node(p); // Delete the P node

	
}

void delete_name(student *t,char a[21])
{
	if(t == NULL || strcmp(t->name,a) == 0) // Base condition and check for name equaltiy
	{
		if(t == NULL)
			return;
		else
		{
			delete_node(t);
		}
	}
	delete_name(t->left,a); // Deleting the multiple names
	delete_name(t->right,a);
}
void delete_student_by_name()
{
	printf("Enter the student Name to Delete : ");
	char name[21];
	scanf("%s",name);
	student *t = stud_top;
	delete_name(t,name); // Calling delete function of stud_top
}