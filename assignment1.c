/*   Program description: Thus is a C program which allows bank customers to manage their 
    PIN on an ATM. The user must select one of the options from the menu to manage their PIN or can choose option 4 to end the program.

    Author: Ella Fahey
    Student ID: C22396101
    Date: 14/11/22
*/

#include <stdio.h>//header files that allow certain functions to be used in the program
#include <stdlib.h>

int main ()
{
    //intital variables
    int PIN = 1234;
    int enteredPIN = 0;
    char selection = 0;
    int verifiedPIN = 0;
    int numAttemptsCorrect = 0;
    int numAttemptsIncorrect = 0;

    //do-while loop to display menu to the user repeatedly
    do
    {   
        //initial menu displayed to the user
        printf("\nWelcome!\n");
        printf("\n|    Menu    |\n");
        printf("\n1. Enter PIN and verify correct\n");
        printf("2. Change PIN\n");
        printf("3. Display the number of times the PIN was entered (i) Successfully (ii) Incorrectly\n");
        printf("4. Exit program\n");

        printf("\nPlease select option 1, 2, 3 or 4 to manage your PIN\n");
        scanf("%1s", &selection); // allows the user to input an option

        while(getchar() != '\n');// clears the buffer to ignore the "Enter" key used when the user selects an option from the menu
        switch(selection)
        {
            case '1'://if(selection =='1') i.e the user chooses the first option on the menu
            {
                printf("Please enter your PIN\n");
                scanf("%d", &enteredPIN);
                
                if (enteredPIN == PIN)
                {
                    printf("\nCorrect PIN entered\n");
                    numAttemptsCorrect++; //counts the number of correct attempts the user makes to enter the pin
                }
                else
                {
                    printf("ERROR!\nIncorrect PIN entered\n");
                    numAttemptsIncorrect++; //counts the number of incorrect attempts the user makes to enter the pin
                }
                break; 
            }
            case'2': //if(selection =='2') i.e. if the user wishes to change their PIN
            {
                printf("\nPlease enter a new PIN\n");
                
                if (!scanf("%d", &PIN) || PIN < 1000 || PIN > 9999)//If the user doesnt enter an integer or if they enter a PIN that is  more or less than 4 digits
                {
                    printf("\nInvalid PIN entered\nPlease enter a 4 digit PIN\nEnter Integers only!\n");
                }
                else // If the user does enter an integer
                {
                    printf("\nPlease verify your new PIN\n");
                    scanf("%d", &verifiedPIN);
                    if(PIN == verifiedPIN)// (the verified PIN will now be the default PIN when the program is run)
                    {
                        printf("\nPIN verified\n");
                    }
                    else // (if the new PIN is not the same as the verified PIN)
                    {
                        printf("\nERROR!\nIncorrect PIN entered\n");
                    }
                }
                while(getchar() != '\n');
                break;
            }
            case '3': //displaying the number of attempts the user made to input the PIN thorughout the program
            {
                printf("\nNumber of correct attempts: %d \n", numAttemptsCorrect);
                printf("\nNumbers of incorrect attempts: %d \n", numAttemptsIncorrect);
                break;
            }
            case '4': // ends program
            {
                printf("Program ended\n");
                exit(0);// Terminates the program when option 4 is selected
            }
           default://Displays 'invalid option selected' if the user enters a number other than 1, 2, 3 or 4
           {
                printf("Error!\nInvalid option selected\n");// Displays an error if the user enters any number other than 1-4
                break;
            }
        }
        
    } while(selection!=4);// while the number entered is not equal to four

    return 0;
    
} // end main