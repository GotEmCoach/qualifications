#include <stdio.h>
#include <argp.h>
#include <ctype.h>
#include <stdlib.h>
#include "menu.h"
#include "math_puzzle.h"
#include "file_puzzle.h"
#include "net_puzzle.h"
#include "ult_puzzle.h"

//TO DO: declaration of C data types
//TO DO: create/implement function with different arrays
//TO DO: handle command line args
//TO DO: math skillz
//TO DO: file stuff
//TO DO: write functions that do all the things
//TO DO: input validation
//TO DO: pointers (uint)
//TO DO: flow control
//TO DO: networking stuff
//TO DO: hash function
//TO DO: sort routine
//TO DO: state machine
//TO DO: Dijksta's Algo weighted graph
//TO DO: use bit wise operator
//TO DO: memory control
//TO DO: Thread control

uint resetpuzz()
{
    printf("Puzzle has already been solved.\n Would you like to reset it?");
    Menu reset_menu;
    uchar *reset_items[] =
    {
        "Yes",
        "No",
        NULL
    };
    set_items(reset_menu, reset_items);
    reset_menu.size = get_size(reset_menu);
    uint reset = 0;
    reset = menu_selection(reset_menu);
    return reset;
}

 

/* Function to run each puzzle for the switch statement below.
*  Originally was doing for each array item in the didarray
*  for the puzzle_menu function. but turns out you can pass
*  actual functions. That's fun.
*/
void did_index_check(uint *did_u_do_it, uint (*puzz_run)())
{
    if (*did_u_do_it == 0)
    {
        *did_u_do_it = puzz_run();
    }
    else if (*did_u_do_it == 1)
    {
        *did_u_do_it = resetpuzz();
    }
    return;
}


uint puzzle_menu()
{
    uint answerkey[5] = {0};
    uint *didarray = answerkey;
    uint allcheck;
    Menu puzz_menu =
    {
        0;
        {
            "Math Puzzle",
            "File Puzzle",
            "Network Puzzle",
            "Ultimate Puzzle",
            "Done",
            NULL
        };
    };
    set_items(puzz_menu, puzz_items);
    puzz_menu.size = get_size(puzz_menu);
    uint done = 0;
    while (done == 0)
    {
        uint menu_choice = 0;
        menu_choice = menu_selection(puzz_menu);
        switch (menu_choice)
        {
            case 1:
            {
                did_index_check(didarray, math_puzzle);
                break;
            }
            case 2:
            {
                did_index_check(didarray+1, file_puzzle);
                break;
            }
            case 3:
            {
                did_index_check(didarray+2, net_puzzle);
                break;
            }
            case 4:
            {
                did_index_check(didarray+3, ult_puzzle);
                break;
            }
            case 5:
            {
                 for (uint i = 0; i < 4; i++)
                {
                    if (*didarray+i == 1)
                    {
                        allcheck++;
                    }   
                }
                if (allcheck == 4)
                {
                    return TRUE;
                }
                else
                {
                    Menu exit_menu;
                    uchar *exit_items[] = 
                    {
                        "Yes",
                        "No",
                        NULL
                    };
                    set_items(exit_menu, exit_items);
                    exit_menu.size = get_size(exit_menu);
                    printf("All progress will be lost.\nAre you sure you want to exit?\n");
                    if (menu_selection(exit_menu) == 2)
                    {
                        printf("Sending you back to menu then.\n");
                    }
                    else
                    {
                        return 0;
                    }
                    break;     
                }
            }
            default:
            {
                return 0;
                break;
            }
        }
    }
    return 0;
}

void greeting() 
{
    printf("Welcome to the Puzzle game!\n");
    return;
}

uint main()
{
    greeting();
    if (puzzle_menu() == 1)
    {
        printf("To Do\n");
    }
    //open browser to this.
    //https://www.youtube.com/watch?v=xfr64zoBTAQ
    return 0;
}