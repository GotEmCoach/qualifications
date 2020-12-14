#include <stdio.h>
#include <argp.h>
#include <ctype.h>
#include <stdlib.h>



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

int ult_puzzle()
{

}

int net_puzzle()
{

}

int file_puzzle()
{

}

int math_puzzle()
{

}
int resetpuzz()
{
    printf("Puzzle has already been solved.\n Would you like to reset it?");
    char *reset_choices =
    {
        "Yes",
        "No",
        NULL
    };
    uint reset = menu_selection(reset_choices);
    if (reset == 1)
    {
        return 0;
    }
    else if (reset == 0)
    {
        return 1;
    }
}


int get_size(char *ptrarray[])
{
    uint i = 0;
    while (ptrarray[i] != NULL)
    {
        i++;
    }
    return i;
}

//Demonstrates 3.1.3.e, 3.1.4.a, 3.1.8.a, 3.1.8.c
// 3.1.8.g, 3.1.8.i, 3.1.9, 3.1.10.a-b, 3.1.10.d-f
// 3.1.11.a-b  

uint menu_selection(char *menu_options[])
{
    uint answer;
    uint size = get_size(menu_options);
    while(1)
    {
        char choice[100];
        printf("Please select from the following:\n");
        for (int i = 0; i < size; i++) 
        {
            printf("%d. %s\n", i + 1, menu_options[i]);
        }
        printf("Selection: ");
        fgets(choice, 100, stdin);
        sscanf(choice, "%1d", &answer);
        if (answer > size || answer < 0)
        {
            printf("That is not a valid selection\n");
            answer = menu_selection(menu_options);
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
    int didarray[4];
    int didmath, didfile, didnet, didult = 0;
    char *puzz_menu[] = 
    {
        "Math Puzzle",
        "File Puzzle",
        "Network Puzzle",
        "Ultimate Puzzle",
        NULL
    };
    uint menu_choice = menu_selection(puzz_menu);
    switch (menu_choice)
    {
        case 1:
        {
            if (didarray[0] == 0)
            {
                didmath = math_puzzle();
                didarray[0] = didmath;
                break;
            }
            else if (didarray[0] == 1)
            {
                didmath = resetpuzz();
                didarray[0] = didmath;
                break;
            }
        }
        case 2:
        {
            if (didarray[1] == 0)
            {
                didmath = file_puzzle();
                didarray[0] = didmath;
                break;
            }
            
        }
        case 3:
        {
            if (didarray[2] == 0)
            {
                didmath = math_puzzle();
                didarray[0] = didmath;
                break;
            }
        }
        case 4:
        {
            if (didarray[3] == 0)
            {
                didmath = math_puzzle();
                didarray[0] = didmath;
                break;
            }
        }
        default:
            break;
    }
}

void greeting() 
{

}

int main()
{
    int didall;
    greeting();
    while (didall != 1)
    {
        didall = puzzle_menu();
    }
    return 0;
}