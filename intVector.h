#include <stdio.h>
#include <stdlib.h>

#define ERROR_STATEMENT int error; int *err = &error;
#define ERROR_OCCURED (*err == -1)
#define NOT_ERROR_OCCURED *err == 1
#define ERROR err
#define IF_ERROR_QUIT( err_code, array ) if (*err == -1) { printf("Error occured, exiting ..."); freeAll( (array), err); exit( (err_code) ); }

/*
*error = -1   -> ERROR OCCURED
*error = 1    -> NO ERROR OCCURED
*/

typedef struct element
{
    int index;
    int value;
    struct element *next;
    struct element *previous;
} element;

typedef element *IntVector;

IntVector create(int value, int *error)
{
    IntVector head = (IntVector)malloc(sizeof(element));

    if (head == NULL)
    {
        *error = -1;
        return NULL;
    }
    else
    {   
        head->index = 0;
        head->value = value;
        head->next = NULL;
        head->previous = NULL;
        *error = 1;
        return head;
    }
}
void freeAll(IntVector vector, int *error)
{
    if (vector != NULL)
    {
        IntVector tmp;
        while (vector != NULL)
        {
            tmp = vector;
            vector = vector->next;
            free(tmp);
        }
        *error = 1;
        return;
    }else
    {
        *error = -1;
        return;
    }
}
int getLength(IntVector vector, int *error)
{
    if (vector != NULL)
    {
        int length = 0;
        while (vector != NULL)
        {
            length ++;
            vector = vector->next;
        }
        *error = 1;
        return length;
        
    }else
    {
        *error = -1;
        return -1;
    }
}
int getLastIndex(IntVector vector, int *error)
{
    if (vector != NULL)
    {
        int length = 0;
        while (vector != NULL)
        {
            length ++;
            vector = vector->next;
        }
        *error = 1;
        return (length - 1);
        
    }else
    {
        *error = -1;
        return -1;
    }
}
IntVector addElementAt(IntVector vector, int index, int value, int *error)
{
    // --- getLength ---
    int length = 0;
    IntVector tmp = vector;
    if (tmp != NULL)
    {
        
        while (tmp != NULL)
        {
            length ++;
            tmp = tmp->next;
        }
        *error = 1;
    }else
    {
        *error = -1;
        return vector;
    }
    // --------------------------

    if (index > length || index < 0)
    {
        *error = -1;
        return vector;
    } else
    {
        tmp = vector;

        if (index == length) /* aggiunta alla fine */
        {   
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            
            IntVector elem = (IntVector)malloc(sizeof(element));
            
            if (elem == NULL)
            {
                *error = -1;
                return vector;
            } else
            {
                elem->value = value;
                elem->index = index;
                elem->next = NULL;
                elem = elem;
                elem->previous = tmp;
                tmp->next = elem;
                *error = 1;
                return vector;
            }

        } else if (index == 0) /* aggiunta all'inizio */
        {   
            IntVector elem = (IntVector)malloc(sizeof(element));
            
            if (elem == NULL)
            {
                *error = -1;
                return vector;
            } else
            {
                elem->value = value;
                elem->index = 0;
                elem->previous = NULL;
                vector = elem;
                elem->next = tmp;
                tmp->previous = elem;

                while (tmp != NULL)
                {
                    tmp->index ++;
                    tmp = tmp->next;
                }

                *error = 1;
                return vector;
            }
        }else  /* aggiunta in mezzo */
        {  
            IntVector elem = (IntVector)malloc(sizeof(element));
            
            if (elem == NULL)
            {
                *error = -1;
                return vector;
            } else
            {
               while (tmp->index != index)
                {
                    tmp = tmp->next;
                }
                
                elem->value = value;
                elem->index = tmp->index;
                tmp->previous->next = elem;
                elem->previous = tmp->previous;
                elem->next = tmp;
                tmp->previous = elem;

                while (tmp != NULL)
                {
                    tmp->index ++;
                    tmp = tmp->next;
                }

                *error = 1;
                return vector;
            }
        }
    }
}
IntVector removeElementAt(IntVector vector, int index, int *error)
{
    // --- getLength ---
    int length = 0;
    IntVector tmp = vector;
    if (tmp != NULL)
    {
        
        while (tmp != NULL)
        {
            length ++;
            tmp = tmp->next;
        }
        *error = 1;
    }else
    {
        *error = -1;
        return vector;
    }
    // --------------------------
    if (index >= length || index < 0)
    {
        *error = -1;
        return vector;
        
    } else
    {
        
        if (length - 1 == 0) /* rimasto un solo elemento */
        {
            *error = -1;
            return vector;
        }else
        {
            if (index == 0)   /* rimozione dall'inizio */
            {
                tmp = vector;

                while (tmp->index != (index + 1) )
                {
                    tmp = tmp->next;
                }

                free(tmp->previous);
                tmp->previous = NULL;
                vector = tmp;

                while (tmp != NULL)
                {
                    tmp->index --;
                    tmp = tmp->next;
                }
                *error = 1;
                return vector;
            } else if (index == (length - 1) )    /* rimozione dalla fine */
            {
                tmp = vector;

                while (tmp->index != (index - 1) )
                {
                    tmp = tmp->next;
                }

                free(tmp->next);
                tmp->next = NULL;
                *error = 1;
                return vector;
            } else   /* rimozione dal mezzo */
            {
                tmp = vector;

                while (tmp->index != (index + 1) )
                {
                    tmp = tmp->next;
                }

                IntVector tmp2 = tmp->previous->previous;

                free(tmp->previous);
                tmp2->next = tmp;
                tmp->previous = tmp2;

                while (tmp != NULL)
                {
                    tmp->index --;
                    tmp = tmp->next;
                }
                *error = 1;
                return vector;
            } 
        }
    }
    
}
int getValueUsingIndex(IntVector vector, int index, int *error)
{
    // --- getLength ---
    int length = 0;
    IntVector tmp = vector;
    if (tmp != NULL)
    {
        
        while (tmp != NULL)
        {
            length ++;
            tmp = tmp->next;
        }
        *error = 1;
    }else
    {
        *error = -1;
        return -1;
    }
    // --------------------------

    if (index >= length || index < 0)
    {
        *error = -1;
        return -1;
    } else 
    {
        tmp = vector;

        while (tmp->index != index)
        {
            tmp = tmp->next;
        }

        *error = 1;
        return tmp->value;
    }
}
void setValueUsingIndex(IntVector vector, int index, int value, int *error)
{
    // --- getLength ---
    int length = 0;
    IntVector tmp = vector;
    if (tmp != NULL)
    {
        
        while (tmp != NULL)
        {
            length ++;
            tmp = tmp->next;
        }
        *error = 1;
    }else
    {
        *error = -1;
        return;
    }
    // --------------------------

    if (index >= length || index < 0)
    {
        *error = -1;
        return;
    } else 
    {
        tmp = vector;

        while (tmp->index != index)
        {
            tmp = tmp->next;
        }

        tmp->value = value;
        *error = 1;
        return;
    }
}
void quickSort(IntVector vector, int first, int last, int *error)
{
    int i, j, pivot, temp;

    if(first < last){
        pivot = first;
        i = first;
        j = last;     
      
        while(i < j){
            while(getValueUsingIndex(vector, i, error) <= getValueUsingIndex(vector, pivot, error) && i < last)
                i ++;
            while(getValueUsingIndex(vector, j, error) > getValueUsingIndex(vector, pivot, error))
                j --;
            if(i < j){   
                temp = getValueUsingIndex(vector, i, error);
                setValueUsingIndex(vector, i, getValueUsingIndex(vector, j, error), error);
                setValueUsingIndex(vector, j, temp, error);            
            }
        }

        temp = getValueUsingIndex(vector, pivot, error);
        setValueUsingIndex(vector, pivot, getValueUsingIndex(vector, j, error), error);
        setValueUsingIndex(vector, j, temp, error);

        if (*error == -1)
        {
            *error = -1;
            return;
        }
        *error = 1;

      quickSort(vector, first, j-1, error);
      quickSort(vector, j+1, last, error);
    }
}
IntVector removeLastElement(IntVector vector, int *error)
{
    if (vector != NULL)
    {
        removeElementAt(vector, getLastIndex(vector, error), error);
        if (*error == -1)
        {
            *error = -1;
            return vector;
        }
        
        *error = 1;
        return vector;
    }else
    {
        *error = -1;
        return vector;
    }
}
IntVector addLastElement(IntVector vector, int value, int *error)
{
    if (vector != NULL)
    {
        addElementAt(vector, getLength(vector, error), value, error);
        if (*error == -1)
        {
            *error = -1;
            return vector;
        }
        
        *error = 1;
        return vector;
    }else
    {
        *error = -1;
        return vector;
    }
}
void printVector(IntVector vector){
    while (vector != NULL)
    {
        printf("index = %d - value = %d\n", vector->index, vector->value);
        vector = vector->next;
    }
}
