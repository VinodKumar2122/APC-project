#include "apc.h"

int main(int argc,char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;

	//Validation
	if(validation(argc,argv)==FAILURE)
	{
		printf("ERROR: Inputs are Not Support\n");
		return 0;
	}
	printf("INFO: Validation SUccessfully\n");
	
	char operator=argv[2][0];
	char *str1=argv[1];
	char *str2=argv[3];


		switch (operator)
		{
			case '+':
                                
				/* call the function to perform the addition operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
                if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("ADDITION OPERATION IS FAILED\n");
					return 0;
				}
				printf("ADDITION OPERATION IS SUCCESS\n");
				printf("ADDITION IS: ");
				print_list(headR);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,str1,str2);
				if(strlen(str1)==strlen(str2))
				{
					int i=0;
					while(i<strlen(str1))
					{
						if(str1[i]>str2[i])
						{
							if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
							{
								printf("SUBTRACTION OPERATION IS FAILED\n");
								return 0;
							}
							break;
						}
						else if(str1[i]<str2[i])
						{
							if(subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR)==FAILURE)
							{
								printf("SUBTRACTION OPERATION IS FAILED\n");
								return 0;
							}
							headR->data=headR->data*(-1);
							break;
						}
						else
						{
							i++;
						}
					}
					if(i==strlen(str1))
					{
						digit_to_list(&head1,&tail1,&head2,&tail2,str1,str2);
					}
				}
				else if(strlen(str1)>strlen(str2))
				{
					if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
					{
						printf("SUBTRACTION OPERATION IS FAILED\n");
						return 0;
					}
				}
				else if(strlen(str1)<strlen(str2))
				{
					if(subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR)==FAILURE)
					{
						printf("SUBTRACTION OPERATION IS FAILED\n");
						return 0;
					}
					headR->data=headR->data*(-1);
				}
				
				printf("SUBTRACTION OPERATION IS SUCCESS\n");
				printf("SUBTRACTION IS: ");
				print_list(headR);
				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
				if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("MULTIPLICATION OPERATION IS FAILED\n");
					return 0;
				}
				printf("MULTIPLICATION OPERATION IS SUCCESS\n");
				printf("MULTIPLICATION IS: ");
				print_list(headR);
				break;
			case '/':	
				/* call the function to perform the division operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
				if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("DIVISION OPERATION IS FAILED\n");
					return 0;
				}
				printf("DIVISION OPERATION IS SUCCESS\n");
				printf("DIVISION IS: ");
				print_list(headR);
				break;
			default:
				printf("Invalid Input:-> Try again...\n");
		}
	return 0;
}
