#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

void add_patient();
void edit_record();
void reserve();
void cancel_reserve();
void view_record();
void view_reservation();

void main (){
    u8 mode=1 ;
    u16 password ;
	u8 flag=0;   //for mode 
    u8 flag1=0;   //for choice
    u8 choice;  
	u8 choice_2;  
	u8 change;
	u8 change_mode2;
	
    printf("*************clinic management system************* \n\n");
    printf("enter one for admin  mode [1] \n");
	printf("enter one for user  mode [2] \n");
	printf("your choice : ");
    scanf("%d",&mode);
while(flag!=1){
    //admin mode 
    if (mode==1)
    {
        printf("\nEnter password for admin :");


        for (int i = 0; i<3; i++)
        {
            scanf ("%d",&password);

            //code area
            if(password == 1234)
            {  
				while (flag1 == 0)
				{
                
                    printf("-----------------------------------------\n");
					printf("****************Admin mode****************\n");
                    printf("\n for add new patient record press [1] \n");
                    printf(" for edit patient record press [2] \n");
                    printf(" for reserve a slot with the doctor press [3] \n");
					
                    printf(" for cancel reservation press [4] \n");
					printf(" for change mode or exits press [5] \n");
					printf("Enter your choice : ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1:
                           add_patient();
							
                           break;

                        case 2:
							edit_record();
                            break;
                        case 3:
							reserve();
                            break;

                        case 4:
							cancel_reserve();
                            break;
						case 5:
						   printf("For change mode to user press [1]\n");
						   printf("For exit program  press [2]\n");
						   printf("Enter your choice : ");
						   scanf("%d",&change);
						   
						   if(change ==1){
							   mode=2;
							 flag1=1;  
						   }
							if(change ==2){
							 flag1=1;
							 flag=1;
						   }
						    
							break;
                        default:
                            printf("incorrect choice");
                            break;
                    }
                }
                
                break;
            }



            else if (i<2)
            { 
                printf ("incorrect password \n");
                printf("Try again: ");
            }
            else{
                printf("incorrect password for three times , no more tries");
                flag=1;
				break ;  
            }
        }
          
    }

    //user mode 
    if(mode==2){
		flag1=1;
        while (flag1 == 1)
			{
				printf("-----------------------------------------\n");
				printf ("          welcome user mode \n");
				printf(" for view patient record press [1] \n");
                printf(" for view today's reservation press [2] \n");
				printf(" for change mode or exits press [3] \n");
				printf("Enter your choice : ");
                scanf("%d",&choice_2);
				switch(choice_2)
                    {
                        case 1:
                           view_record();
						   
							
                           break;

                        case 2:
							view_reservation();
                            break;
                        case 3:
						   printf("For change mode to admin press [1]\n");
						   printf("For exit program  press [2]\n");
						   printf("Enter your choice : ");
						   scanf("%d",&change_mode2);
						   
						   if(change_mode2 ==1){
							   mode=1;
							 flag1=0; 
																 
						   }
							if(change_mode2 ==2){
							 flag1=0;  
							 flag=1;
						   } 
							break;
							
                            default:
                            printf("incorrect choice");
                            break;
                    }
         
            }
	}

    if (mode>=3){
        printf("\nincorrect input\n");
			flag=1;
    }
}
 printf("*******		THANK YOU	*******");
}
