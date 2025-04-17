#include "apc.h"


int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail2;
    int flag = 0;
    while (temp1!=NULL) 
    {
        if (temp1->data != 0) 
        {
            flag = 1;
            break;
        }
        temp1 = temp1->prev;
    }
    if (flag == 0) 
    {
        printf("INFO: DIVISION IS NOT POSSIBLE\n");
        return FAILURE;
    }

    if (*head2 && *head2 == *tail2 && (*head2)->data == 1) 
    {
        copy_list(head1, tail1, headR, tailR);
        return SUCCESS;
    } 
    *headR = NULL;
    *tailR = NULL;
    int count = 0;
    while (compare_numbers(head1, tail1, head2, tail2) >= 0) 
    {
        Dlist *tempHead = NULL, *tempTail = NULL;

        if (subtraction_(head1, tail1, head2, tail2, &tempHead, &tempTail) == FAILURE)
        {
            return FAILURE;
        }
        *head1 = tempHead;
        *tail1 = tempTail;
        count++;
    }
    if (insert_first(headR, tailR, count) == FAILURE) 
    {
        printf("ERROR: Insertion first Failed\n");
        return FAILURE;
    }
    return SUCCESS;
}


int subtraction_(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    *headR = NULL;
    *tailR = NULL;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0, diff;

    while (temp1 != NULL || temp2 != NULL) 
    {
        int num1 = (temp1) ? temp1->data : 0;
        int num2 = (temp2) ? temp2->data : 0;

        num1 -= borrow;
        if (num1 < num2) 
        {
            num1 += 10;
            borrow = 1;
        } 
        else 
        {
            borrow = 0;
        }
        diff = num1 - num2;
        if(insert_first(headR, tailR, diff)==FAILURE)
        {
            return FAILURE;
        }

        if(temp1)
        {
            temp1 = temp1->prev;
        }    
        if(temp2) 
        {
            temp2 = temp2->prev;
        }
    }

    while (*headR && (*headR)->data == 0 && (*headR)->next != NULL) 
    {
        if(delete_first(headR, tailR)==FAILURE)
        {
            return FAILURE;
        }
    }
    if (*headR == NULL) 
    {
        insert_first(headR, tailR, 0); 
    }
    return SUCCESS;
}

int delete_first(Dlist **headR, Dlist **tailR)
{
    if (*headR == NULL)
    {
        return FAILURE; 
    }
    Dlist *temp = *headR;
    *headR = (*headR)->next;
    if (*headR) 
    {
        (*headR)->prev = NULL;
    }
    else 
    {
        *tailR = NULL;
    }
    free(temp);
    return SUCCESS;
}

int compare_numbers(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int len1 = 0, len2 = 0;
    while (temp1) 
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) 
    {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    temp1 = *head1;
    temp2 = *head2;
    while (temp1 && temp2) 
    {
        if(temp1->data > temp2->data) 
        return 1;
        if(temp1->data < temp2->data) 
        return -1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0; 
}

int copy_list(Dlist **src_head, Dlist **src_tail, Dlist **dest_head, Dlist **dest_tail)
{
    delete_list(dest_head, dest_tail); // Ensure destination list is empty before copying
    Dlist *temp = *src_head;
    while (temp)
    {
        if (insert_last(dest_head, dest_tail, temp->data) == FAILURE)
        {
            return FAILURE; // Handle insertion failure
        }
        temp = temp->next;
    }
    return SUCCESS;
}

void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *current = *head;
    while (current)
    {
        Dlist *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    *tail = NULL;
}
