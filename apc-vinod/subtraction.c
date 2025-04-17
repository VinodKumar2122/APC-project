#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0, difference;

    *headR = NULL;
    *tailR = NULL;

    while (temp1 != NULL) 
    {
        int num1 = temp1->data;
        int num2 = (temp2 != NULL) ? temp2->data : 0;

        if (borrow)   // Apply the borrow if needed
        {
            if (num1 > 0) 
            {
                num1 -= 1;
                borrow = 0;
            } 
            else 
            {
                num1 = 9;
                borrow = 1;
            }
        }

        // Compute the difference
        if (num1 < num2) 
        {
            num1 += 10;
            borrow = 1;
        }
        difference = num1 - num2;

        if (insert_first(headR, tailR, difference) == FAILURE)   // Insert result into the head of the result list
        {
            printf("ERROR: Insertion failed in subtraction\n");
            return FAILURE;
        }

        temp1 = temp1->prev;
        if (temp2 != NULL) 
        {
            temp2 = temp2->prev;
        }
           
    }
    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL)    ////Remove leading zeros
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }
    return SUCCESS;
}
