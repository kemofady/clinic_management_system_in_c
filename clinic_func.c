#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

 // for reservation function
u32 arr[5]={-1,-1,-1,-1,-1};



typedef struct Node {
    u16 id;
    s8 first_name[10];
    s8 second_name[10];
    u8 age;
    s8 gender[10];
    u8 reservation;
    struct Node* next;
} Node;

Node* head = NULL; // make head node
int counter = 0; // to know how many nodes

void add_patient() {
    if (counter == 0) {
        head = (Node*)malloc(sizeof(Node));
        
        printf("Enter the first name: ");
        scanf("%s", head->first_name);
        printf("Enter the last name: ");
        scanf("%s", head->second_name);
        printf("Enter age: ");
        scanf("%hhu", &head->age);
        printf("Enter the gender: ");
        scanf("%s", head->gender);
        printf("Enter ID for the new patient you want to add: ");
        scanf("%hu", &head->id);
        
        head->next = NULL;
    } else {
        Node* last; // make last node point to new node
        Node* check_id;
        u16 check; // if id repeated or not
        Node* New = (Node*)malloc(sizeof(Node));
        
        printf("Enter the first name: ");
        scanf("%s", New->first_name);
        printf("Enter the last name: ");
        scanf("%s", New->second_name);
        printf("Enter age: ");
        scanf("%hhu", &New->age);
        printf("Enter the gender: ");
        scanf("%s", New->gender);
        printf("Enter ID for the new patient you want to add: ");
        scanf("%hu", &New->id);
        
        check_id = head;
        check = New->id;
        
        while (check_id != NULL) {
            if (check_id->id == check) {
                printf("The ID already exists\n");
                free(New);
                return;
            }
            check_id = check_id->next;
        }
        
        New->next = NULL;
        last = head;
        
        while (last->next != NULL) {
            last = last->next;
        }
        
        last->next = New;
    }
    
    counter++;
    printf("Added successfully\n");
}

//-----------------------------------------------------------

void edit_record() {
    u16 id;
    Node* check_id;
    Node* last = NULL;

    printf("Enter patient ID: ");
    scanf("%d", &id);

    check_id = head;
    // check if id not exists
    while (check_id != NULL) {
        if (check_id->id == id) {
            last = check_id;
            break;
        }
        check_id = check_id->next;
    }

    if (last == NULL) {
        printf("Incorrect patient ID\n");
        return;
    }

    // if id found
    printf("enter the first name: ");
    scanf("%s", last->first_name);
    printf("enter the last name: ");
    scanf("%s",& last->second_name);
    printf("enter age: ");
    scanf("%d", &last->age);
    printf("enter the gender: ");
    scanf("%s", &last->gender);

    printf("Patient record updated successfully\n");
}

//-----------------------------------------------------------

void reserve() {
    Node* last= NULL;
    Node* check_id;
    u8 res;
    u16 id;

	
    printf("Enter patient ID: ");
    scanf("%d",&id);

       check_id = head;
    // check if id not exists
    while (check_id != NULL) {
        if (check_id->id == id) {
            last = check_id;
	
            break;
        }
        check_id = check_id->next;
    }

    if (last == NULL) {
        printf("Incorrect patient ID\n");
        return;
    }
	
	
	
	  for (int i = 0; i < 5; i++) {
        switch (i) {
    case 0:
        if (arr[0] != -1) break;
        else {
            printf("\n From 2pm to 2:30pm available, to reserve this slot please press 1\n");
            break;
        }
    case 1:
        if (arr[1] != -1) break;
        else {
            printf(" From 2:30pm to 3pm available, to reserve this slot please press 2\n");
            break;
        }
    case 2:
        if (arr[2] != -1) break;
        else {
		printf(" From 3:30pm to 4pm available, to reserve this slot please press 3\n");
             break;
		}
    case 3:
         if (arr[3] != -1) break;
         else {
		printf(" From 4pm to 4:30pm available, to reserve this slot please press 4\n");
			break;
				}
     case 4:
          if (arr[4] != -1) break;
         else {
		printf(" From 4:30pm to 5pm available, to reserve this slot please press 5\n");
                break;
				}
        }
    }
	
	printf("Your choice: ");
	scanf("%d",&res);
	
			arr[res-1]=id ;
	   last->reservation = res;
	
    printf("reservation completed \n");
}

//-----------------------------------------------------------

void cancel_reserve() {
    Node* last= NULL;
    Node* check_id;
    
    u16 id;

	
    printf("Enter patient ID: ");
    scanf("%d",&id);

       check_id = head;
    // check if id not exists
    while (check_id != NULL) {
        if (check_id->id == id) {
            last = check_id;
	
            break;
        }
        check_id = check_id->next;
    }

    if (last == NULL) {
        printf("Incorrect patient ID\n");
        return;
    }
		for(u8 i=0;i<5;i++)
	{
			if(arr[i]==id)
			{
				arr[i]=-1;
			}
    }
	(last->reservation) = 0;
	printf("reservation  canceled  DONE\n");
	
}


void view_record() {
    Node* last = NULL;
    Node* check_id;
    u16 id;
    
    printf("Enter patient ID: ");
    scanf("%hu", &id);
    
    check_id = head;
    
    // check if id not exists
    while (check_id != NULL) {
        if (check_id->id == id) {
            last = check_id;
            break;
        }
        check_id = check_id->next;
    }
    
    if (last == NULL) {
        printf("Incorrect patient ID\n");
        return;
    }
    
    printf("\n");
    printf("First name: %s\n", last->first_name);
    printf("Last name: %s\n", last->second_name);
    printf("Age: %hhu\n", last->age);
    printf("Gender: %s\n", last->gender);
    printf("\n");
}

void view_reservation()
{
   for(int i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 : if(arr[0]==-1) break;
						else
							printf("From 2pm to 2:30pm is reserved by the ID Num: %d\n",arr[0]);
						break;
			case 1 : if(arr[1]==-1) break;
						else 
							printf("From 2:30pm to 3pm is reserved by the ID Num: %d\n",arr[1]);
						break;		
			case 2 : if(arr[2]==-1) break;
						else 
							printf("From 3:30pm to 4pm is reserved by the ID Num: %d\n",arr[2]);
						break;
			case 3 : if(arr[3]==-1) break;
						else
							printf("From 4pm to 4:30pm is reserved by the ID Num: %d\n",arr[3]);
						break;
			case 4 : if(arr[4]==-1) break;
						else
							printf("From 4:30pm to 5pm is reserved by the ID Num: %d\n",arr[4]); 
						break;						
		}
	}
}
	
