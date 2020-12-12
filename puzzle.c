#include <stdio.h>
#include <argp.h>
#include <ctype.h>




//TO DO: declaration of C data types
//TO DO: create/implement function with different arrays
//TO DO: handle command line args
//TO DO: math skillz
//TO DO: file stuff
//TO DO: write functions that do all the things
//TO DO: input validation
//TO DO: pointers (int)
//TO DO: flow control
//TO DO: networking stuff
//TO DO: hash function
//TO DO: sort routine
//TO DO: state machine
//TO DO: Dijksta's Algo weighted graph
//TO DO: use bit wise operator
//TO DO: memory control
//TO DO: Thread control

int puzzle_four()
{

}

int puzzle_three()
{

}

int puzzle_two()
{

}

int puzzle_one()
{

}

//Demonstrates 3.1.3.e, 3.1.4.a, 3.1.8.a, 3.1.8.c
// 3.1.8.g, 3.1.8.i, 3.1.9, 3.1.10.a-b, 3.1.10.d-f
// 3.1.11.a-b  
int *menu_selection(char **menu_options, int size)
{
    int *answer;
    while(1)
    {
        char choice[100];
        printf("Please select from the following:\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d. %s\n", i + 1, menu_options[i]);
        }
        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d", &answer);
        if (answer > size || answer < 0)
        {
            printf("That is not a valid selection\n");
            answer = menu_selection(menu_options, size);
        }
        else
        {
            break;
        }
    }
    return answer;
}

int puzzle_menu()
{

}

void greeting() 
{

}

void main()
{
    int didall;
    greeting();
    while (didall != 1)
    {
        didall = puzzle_menu();
    }
}