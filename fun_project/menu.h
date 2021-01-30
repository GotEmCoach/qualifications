#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_ITEMS 50
#define NONE 0
#define TRUE 1
#define FALSE 0

typedef unsigned char uchar;
typedef struct Menus
{
    
} Menu;

uint get_size(uchar *items[])
{
    uint i = 0;
    while (items[i] != NULL)
    {
        i++;
    }
    return i;
}

uint menu_selection(uint size, uchar *items[])
{
    uint answer;
    while(TRUE)
    {
        char choice[100];
        printf("Please select from the following:\n");
        for (uint i = 0; i < menu.size; i++) 
        {
            printf("%d. %s\n", i + 1, *menu.items[i]);
        }
        printf("Selection: ");
        fgets(choice, 10, stdin);
        sscanf(choice, "%1d", &answer);
        printf("\n\n");
        if (answer > menu.size || answer < 0)
        {
            printf("That is not a valid selection\n");
            answer = NONE;
            answer = menu_selection(menu);
            printf("Exiting the Cception....\n\n");
            return answer;
        }
        else
        {
            break;
        }
    }
    return answer;
}


