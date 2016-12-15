#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char rollno[9];
	char *name;
	float cpi;
	char *s[10];
	student *left;
	student *right;

};
student *top = NULL;
void add_student();
void add_subject_to_student();
void update_cpi();
void print();
void successor();
void height();
void delete_student();
void delete_student_by_rollno();

int main()
{
	printf("Enter from the folllowing choice : ");
	printf("1. Add a student\n2. Add a subject to a student\n3. Update cpi\n4. Print\n5. Successor\n6. Height\n7. Delete a Student by Name\n8. Delete a student by roll No.\n:  ");
	
}