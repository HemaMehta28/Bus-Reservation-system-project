
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char names[100][100],emails[100][100], passwords[100][100];
int Count = 0;
int busNumber[][2] = {{1022, 1023}, {2890, 2891}, {3004, 3005}, {4900, 4901}};
int price[][2] = {{1000, 1000}, {5000, 5000}, {3000, 3000}, {2000, 2000}};
int totalSeat[][2] = {{50, 50}, {40, 40}, {50, 50}, {30, 30}};
int availableSeat[][2] = {{50, 50}, {40, 40}, {50, 50}, {30, 30}};
int bookedSeat[][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
int GST=100;
int menu();
int usermenu();
int Index;


int Route()
{
    int routeChoice;
    printf("-----------------Menu-------------------\n");
    printf("1. UK to Delhi\n");
    printf("2. UK to Mumbai\n");
    printf("3. UK to Jammu\n");
    printf("4. UK to Bihar\n");
    printf("5. Back to Main Menu\n");
    printf("------------------------------------------\n\n");
    printf("Enter the route choice: ");
    scanf("%d", &routeChoice);
    return routeChoice;
}



int BookTicket()
 {
    int busChoice;
    do {
        int routeChoice = Route();
        if (routeChoice >= 1 && routeChoice <= 4)
         {
            printf("\nBuses available for this route:\n");
            for (int i = 0; i < 2; i++) {
                printf("%d. Bus Number: %d\n", i + 1, busNumber[routeChoice - 1][i]);
            }
            printf("\nEnter the bus choice: ");
            scanf("%d", &busChoice);
            if (busChoice >= 1 && busChoice <= 2) {
                printf("----------------------------------------------\n");
                printf("Bus Number: %d\n", busNumber[routeChoice - 1][busChoice - 1]);
                printf("Price with GST: %d\n", GST+price[routeChoice - 1][busChoice - 1]);
                printf("Available Seat: %d\n", availableSeat[routeChoice - 1][busChoice - 1]);
                printf("----------------------------------------------\n");
                int seats;
                printf("\nEnter number of seats to book: ");
                scanf("%d", &seats);
                if (seats <= availableSeat[routeChoice - 1][busChoice - 1]) {
                    availableSeat[routeChoice - 1][busChoice - 1] -= seats;
                    bookedSeat[routeChoice - 1][busChoice - 1] += seats;
                    printf("\n-------------------\nSeats booked successfully\n-------------------\n\n");
                    printf("====================Recipt======================\n");
                    printf("Name: %s\n", names[Index]);
                    printf("Email: %s\n", emails[Index]);
                    printf("Bus Number: %d\n", busNumber[routeChoice - 1][busChoice - 1]);
                    printf("Route: ");
                    switch (routeChoice) 
                    {
                        case 1:
                            printf("UK to Delhi\n");
                            break;
                        case 2:
                            printf("UK to Mumbai\n");
                            break;
                        case 3:
                            printf("UK to Jammu\n");
                            break;
                        case 4:
                            printf("UK to Bihar\n");
                            break;
                    }
                    printf("Number of Seats: %d\n", seats);
                    printf("Total Price with GST: %d\n", seats * price[routeChoice - 1][busChoice - 1]+GST);
                    printf("================================================\n");
                } else {
                    printf("----------------------------\nSorry, seats are not available.\n---------------------------\n");
                }
            } else {
                printf("---------------------------\nInvalid bus choice.\n-------------------------\n");
            }
        } else if (routeChoice == 5) {
            usermenu();
        } else {
            printf("------------------------------\nInvalid choice.\n--------------------------\n");
        }
    } while (1);
    return 0;
}




int cancelTicket()
 {
     int busChoice;
     int routeChoice =Route();
    if (routeChoice >= 1 && routeChoice <= 4) 
    {
        printf("\nBuses available for this route:\n");
        for (int i = 0; i < 2; i++) 
        {
            printf("%d. Bus Number: %d\n", i + 1, busNumber[routeChoice - 1][i]);
        }
        printf("\nEnter the bus choice: ");
        scanf("%d", &busChoice);
        if (busChoice >= 1 && busChoice <= 2) 
        {
             printf("----------------------------------------------\n");
            printf("Bus Number: %d\n", busNumber[routeChoice - 1][busChoice - 1]);
            printf("Booked Seat: %d\n", bookedSeat[routeChoice - 1][busChoice - 1]);
             printf("----------------------------------------------\n");
            int seats;
            printf("Enter number of seats to cancel: ");
            scanf("%d", &seats);
            if (seats <= bookedSeat[routeChoice - 1][busChoice - 1]) 
            {
                availableSeat[routeChoice - 1][busChoice - 1] += seats;
                bookedSeat[routeChoice - 1][busChoice - 1] -= seats;
                printf("-------------------\nTicket cancelled successfully\n-------------------\n");
                 printf("====================Recipt======================\n");
                  printf("Name: %s\n", names[Index]);
                    printf("Email: %s\n", emails[Index]);
                    printf("Bus Number: %d\n", busNumber[routeChoice - 1][busChoice - 1]);
                    printf("Route: ");
                    switch (routeChoice) 
                    {
                        case 1:
                            printf("UK to Delhi\n");
                            break;
                        case 2:
                            printf("UK to Mumbai\n");
                            break;
                        case 3:
                            printf("UK to Jammu\n");
                            break;
                        case 4:
                            printf("UK to Bihar\n");
                            break;
                    }
                    printf("Refund amount without GST: %d\n", seats * price[routeChoice - 1][busChoice - 1]-GST);
                    printf("Booked Seat: %d\n", bookedSeat[routeChoice - 1][busChoice - 1]);
                    printf("\n==================================================\n");
            } 
            else 
            {
                printf("-------------------\nSorry, you have not booked that many seats.\n-------------------\n");
            }
        } else 
        {
            printf("--------------------------------------\nInvalid bus choice.\n--------------------------------\n");
        }
    } else if (routeChoice == 5) 
    {
        usermenu();
    } else 
    {
        printf("-------------------------------\nInvalid choice.\n---------------------------------\n");
    }
    return 0;
}






int usermenu() 
{
    int choice;
    while (1) 
    {
        printf("============= = UserMenu = =============\n");
        printf("1. Book a ticket\n");
        printf("2. Cancel a ticket\n");
        printf("3. Check bus status\n");
        printf("4. Logout\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                BookTicket();
                break;
            case 2:
                cancelTicket();
                break;
            case 3:
               
            case 4:
               
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}



int menu() 
{
    int choice, i, j;
    do {
        printf("*********************************Signin&Loginin***********************************\n");
        printf("1. Sign in\n2. Login in\n3. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n\n\t\t========================== Sign Up======================\n");
                while(1) {
                    printf("\n\nPlease enter your name: ");
                    scanf("%s", names[Count]);
                    int validName = 1;
                    for (int i = 0; names[Count][i] != '\0'; i++) {
                        if (!((names[Count][i] >= 'A' && names[Count][i] <= 'Z') || (names[Count][i] >= 'a' && names[Count][i] <= 'z')))
                        {
                            validName = 0;
                            break;
                        }
                    }
                    if (validName == 0) 
                    {
                        printf("Invalid name. Name should only contain alphabets.\n");
                    } else {
                        break;
                    }
                }
                while(1) {
                    printf("\n\nPlease enter the Email: ");
                    scanf("%s", emails[Count]);
                    int atTheRate = 0, dot = 0;
                    for (int i = 0; emails[Count][i] != '\0'; i++) 
                    {
                        if (emails[Count][i] == '@') {
                            atTheRate++;
                        }
                        if (emails[Count][i] == '.') {
                            dot++;
                        }
                    }
                    if (atTheRate != 1 || dot == 0 || emails[Count][0] == '@' || emails[Count][strlen(emails[Count]) - 1] == '.' || emails[Count][strlen(emails[Count]) - 1] == '@') 
                    {
                        printf("Invalid email format.\n");
                    } else 
                    {
                        int exist = 0;
                        for (i = 0; i < Count; i++)
                         {
                            int match = 1;
                            for (j = 0; emails[i][j] != '\0' || emails[Count][j] != '\0'; j++) {
                                if (emails[i][j] != emails[Count][j]) {
                                    match = 0;
                                    break;
                                }
                            }
                            if (match == 1) 
                            {
                                exist = 1;
                                break;
                            }
                        }
                        if (exist == 0) {
                            break;
                        } else {
                            printf("Email already exists.\n");
                        }
                    }
                }
                while(1) 
                {
                printf("\nplease enter the Password: ");
                scanf("%s", passwords[Count]);
                if (strlen(passwords[Count]) < 8)
                 {
                printf("Password should be at least 8 characters long.\n");
               } 
               else
                {
                int upper = 0, lower = 0, digit = 0, special = 0;
               for (int i = 0; passwords[Count][i] != '\0'; i++) 
               {
            if (passwords[Count][i] >= 'A' && passwords[Count][i] <= 'Z') 
            {
                upper++;
            }
            if (passwords[Count][i] >= 'a' && passwords[Count][i] <= 'z')
             {
                lower++;
            }
            if (passwords[Count][i] >= '0' && passwords[Count][i] <= '9') 
            {
                digit++;
            }
            if ((passwords[Count][i] >= '!' && passwords[Count][i] <= '/') || (passwords[Count][i] >= ':' && passwords[Count][i] <= '@') || (passwords[Count][i] >= '[' && passwords[Count][i] <= '`') || (passwords[Count][i] >= '{' && passwords[Count][i] <= '~')) 
            {
                special++;
            }
        }
        if (upper == 0 || lower == 0 || digit == 0 || special == 0) 
        {
            printf("Password should contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
        } else
        {
            break;
        }
    }
}
        Count++;
        Index = Count - 1;
        printf("-------------------\nSign up successful!\n-------------------\n");
        usermenu();
        break;
          
        case 2:
            
          if (Count > 0) 
          {
              printf("\n\t\t=========================Log In========================\n\n");
              char email[100], password[100];
              
            while(1) 
            {
            printf("\n\nPlease enter the Email: ");
            scanf("%s", email);
            int found = 0;
            for (i = 0; i < Count; i++) {
                int match = 1;
                for (j = 0; emails[i][j] != '\0' || email[j] != '\0'; j++) 
                {
                    if (emails[i][j] != email[j]) 
                    {
                        match = 0;
                        break;
                    }
                }
                if (match == 1) 
                {
                    found = 1;
                    Index = i;
                    break;
                }
            }
            if (found == 1) 
            {
                break;
            } else {
                printf("-------------------\nInvalid email.\n-------------------\n");
            }
        }
        while(1) {
            printf("please enter the Password: ");
            scanf("%s", password);
            int match2 = 1;
            for (j = 0; passwords[Index][j] != '\0' || password[j] != '\0'; j++) {
                if (passwords[Index][j] != password[j]) {
                    match2 = 0;
                    break;
                }
            }
            if (match2 == 1) 
            {
                printf("-------------------\nLogin successful!\n-------------------\n");
                usermenu();
                return 0;
            } else 
            {
                printf("-------------------\nInvalid password.\n-------------------\n");
            }
        }
    } 
    else 
    {
        printf("-------------------\nPlease sign in First.\n-------------------\n");
        break;
    }
    
            case 3:
                printf("-------------------\n*****Exit****\n-------------------\n");
                exit(0);
               
            default:
                printf("-------------------\nInvalid choice.\n-------------------\n");
        }
    } while (1);
    return 0;
}


int main()
{
    menu();
    return 0;
}
