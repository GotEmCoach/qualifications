#include <ctype.h>
#include <stdlib.h>

#define MAX_ITEMS 25
#define NONE 0
#define TRUE 1
#define FALSE 0
typedef unsigned char uchar;
typedef struct Menus
{
    uint size;
    uchar *items[MAX_ITEMS];
} Menu, *pointer_to_menu;
struct Menu_methods
{
    pointer_to_menu (*set_menu_items)(Menu *)
}


uint set_size(Menu menu)
{
    uint i = 0;
    while (menu.items[i] != NULL)
    {
        i++;
    }
    return i;
}


uint menu_selection(Menu menu)
{
    uint answer;
    while(TRUE)
    {
        char choice[100];
        printf("Please select from the following:\n");
        for (uint i = 0; i < menu.size; i++) 
        {
            printf("%d. %s\n", i + 1, menu.items[i]);
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


