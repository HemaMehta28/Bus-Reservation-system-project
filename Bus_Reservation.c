

#include <stdio.h>
char emails[100][100], passwords[100][100];
int Count = 0;
int busNumber[] = {1022, 2890, 3004, 4900};
int price[] = {1000, 5000, 3000, 2000};
int totalSeat[] = {50, 40, 50, 30};
int availableSeat[] = {50, 40, 50, 30};
int bookedSeat[] = {0, 0, 0, 0};
int menu();
int usermenu();
int route() 
{
    int choice;
    do {
        printf("-----------------Menu-------------------\n");
        printf("1. UK to Delhi\n");
        printf("2. UK to Mumbai\n");
        printf("3. UK to Jammu\n");
        printf("4. UK to Bihar\n");
        printf("5. Back to Main Menu\n");
        printf("Enter the route choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4) {
            printf("Route: ");
            switch (choice) {
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
            printf("Bus Number: %d\n", busNumber[choice - 1]);
            printf("Price: %d\n", price[choice - 1]);
            printf("Available Seat: %d\n", availableSeat[choice - 1]);
            int seats;
            printf("Enter the  number of seats to book: ");
            scanf("%d", &seats);
            if (seats <= availableSeat[choice - 1])
            {
                availableSeat[choice - 1] = availableSeat[choice - 1]-seats;
                bookedSeat[choice - 1] =   bookedSeat[choice - 1]+seats;
                printf("Seats booked successfully\n");
                printf("Total price: %d\n", seats * price[choice - 1]);
                printf("Available Seat: %d\n", availableSeat[choice - 1]);
                printf("Booked Seat: %d\n", bookedSeat[choice - 1]);
            } else 
            {
                printf("Sorry, seats are not available.\n");
            }
        } else if (choice == 5) 
        {
            usermenu();
        } else
        {
            printf("Invalid choice.\n");
        }
    } while (1);
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
        switch (choice) {
            case 1:
                route();
                break;
            case 2:
               
                break;
            case 3:
                printf("Check bus status\n");
                break;
            case 4:
                menu();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

int menu() {
    int choice, i, j;
    do {
        printf("Signin&Loginin*\n");
        printf("1. Sign in\n2. Login in\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("================= Sign Up==================\n");
                printf("Email: ");
                scanf("%s", emails[Count]);
                int exist = 0;
                for (i = 0; i < Count; i++) {
                    int match = 1;
                    for (j = 0; emails[i][j] != '\0' || emails[Count][j] != '\0'; j++) {
                        if (emails[i][j] != emails[Count][j]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match == 1) {
                        exist = 1;
                        break;
                    }
                }
                if (!exist) {
                    printf("Password: ");
                    scanf("%s", passwords[Count]);
                    Count++;
                    printf("Sign up successful!\n");
                    usermenu();
                    return 0;
                } else {
                    printf("Email already exists.\n");
                }
                break;
            case 2:
                if (Count > 0) {
                    printf("Log In\n");
                    char email[100], password[100];
                    printf("Email: ");
                    scanf("%s", email);
                    printf("Password: ");
                    scanf("%s", password);
                    int found = 0;
                    for (i = 0; i < Count; i++) {
                        int match = 1;
                        for (j = 0; emails[i][j] != '\0' || email[j] != '\0'; j++) {
                            if (emails[i][j] != email[j]) {
                                match = 0;
                                break;
                            }
                        }
                        if (match == 1) {
                            int match2 = 1;
                            for (j = 0; passwords[i][j] != '\0' || password[j] != '\0'; j++) {
                                if (passwords[i][j] != password[j]) {
                                    match2 = 0;
                                    break;
                                }
                            }
                            if (match2 == 1) {
                                printf("Login successful!\n");
                                usermenu();
                                return 0;
                            } else {
                                printf("Invalid password.\n");
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        printf("Invalid email or password.\n");
                    }
                } else {
                    printf("No users found.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}

int main() 
{
    menu();
    return 0;
}
