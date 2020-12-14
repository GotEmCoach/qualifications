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
int get_size(const char *thisarray[])
{
    uint i = 0;
    while (thisarray[i] != NULL)
    {
        i++;
    }
    return i;
}

uint menu_selection(const char *menu_options[])
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
            return answer;
        }
        else
        {
            break;
        }
    }
    return answer;
}

int ult_puzzle()
{
    printf("To do!\n");
    return 0;
}

int net_puzzle()
{
    printf("To do!\n");
    return 0;
}

int file_puzzle()
{
    printf("To do!\n");
    return 0;
}

int math_puzzle()
{
    printf("To do!\n");
    return 0;
}
int resetpuzz()
{
    printf("Puzzle has already been solved.\n Would you like to reset it?");
    const char *reset_choices[] =
    {
        "Yes",
        "No",
        NULL
    };
    uint reset = menu_selection(reset_choices);
    return reset;
}

//Demonstrates 3.1.3.e, 3.1.4.a, 3.1.8.a, 3.1.8.c
// 3.1.8.g, 3.1.8.i, 3.1.9, 3.1.10.a-b, 3.1.10.d-f
// 3.1.11.a-b  



int puzzle_menu()
{
    int didarray[4] = {0};
    int allcheck;
    int didmath, didfile, didnet, didult = 0;
    const char *puzz_menu[] =
    {
        "Math Puzzle",
        "File Puzzle",
        "Network Puzzle",
        "Ultimate Puzzle",
        "Done",
        NULL
    };
    int done = 0;
    while (done == 0)
    {
        uint menu_choice = menu_selection(puzz_menu);
        switch (menu_choice)
        {
            case 1:
            {
                if (didarray[0] == 0)
                {
                    didmath = math_puzzle();
                }
                else if (didarray[0] == 1)
                {
                    didmath = resetpuzz();
                }
                didarray[0] = didmath;
                break;
            }
            case 2:
            {
                if (didarray[1] == 0)
                {
                    didfile = file_puzzle();
                }
                else if (didarray[1] == 1)
                {
                    didfile = resetpuzz();
                }
                didarray[1] = didfile;
                break;
            }
            case 3:
            {
                if (didarray[2] == 0)
                {
                    didnet = math_puzzle();
                }
                else if (didarray[2] == 1)
                {
                    didnet = resetpuzz();
                }
                didarray[2] = didnet;
                break;
            }
            case 4:
            {
                if (didarray[3] == 0)
                {
                    didult = math_puzzle();
                }
                else if (didarray[3] == 1)
                {
                    didult = resetpuzz();
                }
                didarray[3] = didult;
                break;
            }
            case 5:
            {
                 for (int i = 0; i < 4; i++)
                {
                    if (didarray[i] == 1)
                    {
                        allcheck++;
                    }   
                }
                if (allcheck == 4)
                {
                    return 1;
                }
                else
                {
                    const char *exit_choices[]= 
                    {
                        "Yes",
                        "No",
                        NULL
                    };
                    printf("All progress will be lost.\nAre you sure you want to exit?\n");
                    uint exit = menu_selection(exit_choices);
                    if (exit == 0)
                    {
                        break;
                    }
                    else
                    {
                        return 0;
                    }     
                }
            }
            default:
            {
                break;
            }
        }
    }
}

void greeting() 
{
    printf("Welcome to the Puzzle game!\n");
    return;
}

int main()
{
    int didall;
    greeting();
    didall = puzzle_menu();
    return 0;
}