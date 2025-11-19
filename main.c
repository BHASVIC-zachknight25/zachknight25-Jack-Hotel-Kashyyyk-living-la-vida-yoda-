#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void check_in(void);
int choice;

int main(void) {
    printf("Welcome to Hotel Kashyyyk!\n\n");
    printf("What would you like to do?\n 1. CHECK IN \n 2. BOOK DINNER \n 3. CHECK OUT");
    scanf("%d",&choice);
    if
    check_in();
    return 0;

}

void check_in(void) {
    srand((unsigned)time(NULL));

    int price = 0;

    // Getting User Data
    char firstname[20];
    printf("Welcome to The Check In Tab, Please fill in the following details");
    printf("\n Enter your first name: ");
    scanf("%19s", firstname);

    char surname[20];
    printf("Enter your surname: ");
    scanf("%19s", surname);

    int age;
    printf("Enter your age (You must be at least 16): ");
    scanf("%d", &age);

    if (age < 16) {
        printf("Sorry, you must be 16 or older to book.\n");
        return;
    }

    int amt_ppl;
    printf("Enter number of people in your group: ");
    scanf("%d", &amt_ppl);

    int days;
    printf("How many days are you staying? ");
    scanf("%d", &days);

    char newspaper[5];
    printf("Would you like to receive a newspaper? (yes/no): ");
    scanf("%4s", newspaper);

    if (strcasecmp(newspaper, "yes") == 0) {
        printf("You will receive a newspaper in the morning ;) \n");
    }

    // Board type selection
    char board_type[5];
    printf("\nFull board costs 20 per day, Half board 15 per day, Bed & Breakfast 5 per day.\n");
    printf("Enter your board type (FB / HB / BB): ");
    scanf("%4s", board_type);

    // Room prices
    printf("\nRoom prices:\n");
    printf("Rooms 1 & 2 - 100\nRoom 3 - 85\nRooms 4 & 5 - 75\nRoom 6 - 50\n");

    int room;
    printf("\nWhich room do you want (1-6)? ");
    scanf("%d", &room);

    // Determine room price
    int room_price;
    switch (room) {
        case 1:
        case 2: room_price = 100; break;
        case 3: room_price = 85; break;
        case 4:
        case 5: room_price = 75; break;
        case 6: room_price = 50; break;
        default:
            printf("Invalid room selection — defaulting to Room 6 (£50).\n");
            room_price = 50;
    }

    // Board type price
    int board_cost_per_person;
    if (strcasecmp(board_type, "FB") == 0) {
        board_cost_per_person = 20;
    } else if (strcasecmp(board_type, "HB") == 0) {
        board_cost_per_person = 15;
    } else if (strcasecmp(board_type, "BB") == 0) {
        board_cost_per_person = 5;
    } else {
        printf("Unknown board type. Defaulting to Bed & Breakfast (BB).\n");
        board_cost_per_person = 5;
        strcpy(board_type, "BB");
    }

    // Price calculations
    int total_room_cost = room_price * days;
    int total_board_cost = board_cost_per_person * days * amt_ppl;
    price = total_room_cost + total_board_cost;

    // Generate booking reference
    char u_id[50];
    int random_num = rand() % 101;
    sprintf(u_id, "%s%d", surname, random_num);

    // Print booking summary
    printf("\n========== BOOKING DETAILS ==========\n");
    printf("Guest name      : %s %s\n", firstname, surname);
    printf("Guest age       : %d\n", age);
    printf("Group size      : %d\n", amt_ppl);
    printf("Newspaper       : %s\n", newspaper);
    printf("Room selected   : %d (%d per night)\n", room, room_price);
    printf("Board type      : %s (%d per person per day)\n", board_type, board_cost_per_person);
    printf("Days staying    : %d\n", days);
    printf("-------------------------------------\n");
    printf("Room total      : %d\n", total_room_cost);
    printf("Board total     : %d\n", total_board_cost);
    printf("TOTAL PRICE     : %d\n", price);
    printf("Booking ref     : %s\n", u_id);
    printf("=====================================\n");
}

