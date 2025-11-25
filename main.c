#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_BOOKINGS 100
#define NUM_TABLES 3
#define NUM_SITTINGS 2

char *table_names[NUM_TABLES] = {"Endor", "Naboo", "Tatooine"};
char *sitting_times[NUM_SITTINGS] = {"7pm", "9pm"};
int table_capacity = 4;

// Track bookings for each table and sitting
int table_occupied[NUM_TABLES][NUM_SITTINGS] = {0}; // number of people booked


typedef struct {
    char booking_id[50];
    char firstname[20];
    char surname[20];
    int age;
    int amt_ppl;
    int days;
    char board_type[5];
    int room;
    char newspaper[5];
} Booking;

Booking bookings[MAX_BOOKINGS];
int booking_count = 0;


void check_in(void);
void dinner_booking(void);
void check_out(void);
int choice;

int main(void) {
    printf("Welcome to Hotel Kashyyyk!\n\n");

    while (1) {

        while (1) {
            printf("What would you like to do?\n");
            printf(" 1. CHECK IN\n 2. BOOK DINNER\n 3. CHECK OUT\n 4. EXIT\n");
            printf("Enter choice: ");

            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Enter 1–4.\n");
                while (getchar() != '\n');
                continue;
            }

            if (choice >= 1 && choice <= 4)
                break;

            printf("Invalid choice. Enter 1–4.\n");
        }

        if (choice == 1)
            check_in();
        else if (choice == 2)
            dinner_booking();
        else if (choice == 3)
            check_out();
        else
            break;
    }

    printf("We hope you enjoyed your stay at Hotel Kashyyyk! \n Proudly hosted by La Vida Yoda Enterprise. \n Have A Great Day!");
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
    if (firstname == "Jack") {
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣬⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⠋⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠘⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⡿⠁⢲⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠔⠒⠈⣉⡉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⠆⣰⣿⣿⣿⣿⣿⣿⣿⣿⣋⣤⣤⣶⢾⣿⣿⣦⣄⠀⠈⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⡟⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⢈⣈⡀⠙⠛⠷⢦⡀⠀⡹⠋⠛⢻⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⠟⠛⢿⠇⢻⣿⣿⣿⣿⣿⣿⣿⡿⠛⠀⠀⠠⠖⠛⠋⠛⠳⠀⠀⠀⠙⠆⠀⡾⠀⠀⠻⠿⢿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⡟⠀⣴⣄⡀⢾⣿⣿⣿⣿⣿⣿⣿⣿⡇⢀⣀⣤⡙⠂⠀⠀⡄⠀⠀⠀⠀⣴⣾⣧⠀⠀⠀⠀⠀⠀⠃⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⡇⠀⣾⣿⣿⣦⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣀⠀⠐⠃⠀⢀⣠⣼⣿⣿⣿⠀⠀⠀⠀⠀⢤⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⡇⠘⠋⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠅⣠⣼⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⡾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⡀⣀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢹⣦⣤⣤⣦⡄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣧⢸⣿⣧⣼⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⠀⠹⣿⠇⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡻⢃⣾⡿⠿⢿⣿⣿⣿⠙⠻⣿⠟⢻⠇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⡄⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠘⠏⠀⢀⣀⣙⡛⠋⠀⠀⠈⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣤⣤⣭⠀⠀⠀⢀⣠⣆⠃⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢩⣿⡟⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⡟⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠹⠿⠿⠛⠋⠉⠉⠁⠀⠈⠙⠋⠃⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⠇⢤⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⡁⢠⣤⣤⣄⣤⣤⣤⣀⣀⣀⣀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⠓⠀⣸⣿⣿⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⡏⢀⠄⣸⣿⣿⣿⣿⣿⠟⠉⠉⠉⠉⠀⠀⢀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⠐⣡⣾⣿⣿⣿⣿⣿⣿⠻⣎⠻⣿⣿⣿⣿⣇⢘⣠⣹⣿⣿⣿⣿⣧⣀⡀⣀⣀⠀⢀⠀⣼⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⢁⣼⣿⣿⣿⣿⣿⣿⣿⣿⣧⡙⢷⣽⣿⣮⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡟⠀⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣭⢻⣿⣿⣮⣻⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠙⠙⠃⢰⣌⠣⡀⣄⡀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⡟⠈⠙⠛⠿⠿⠿⠋⠀⠀⠀⠀⠀⢀⣄⣹⣇⠱⠘⣿⣷⣦⣀⠘⠻⣿⣿⣿⣿⣿⣿⣿\n");
        printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠻⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠟⢻⣿⠀⡆⢸⡇⢿⣿⣷⣄⡀⢤⣿⣿⣿⣿⣿");
    }

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
    // Save booking info
    if (booking_count < MAX_BOOKINGS) {
        Booking *b = &bookings[booking_count];

        strcpy(b->booking_id, u_id);
        strcpy(b->firstname, firstname);
        strcpy(b->surname, surname);
        strcpy(b->newspaper, newspaper);
        b->age = age;
        b->amt_ppl = amt_ppl;
        b->days = days;
        strcpy(b->board_type, board_type);
        b->room = room;

        booking_count++;
        printf("Booking saved.\n");
    } else {
        printf("Error: Booking storage full.\n");
    }

}

void dinner_booking(void) {
    printf("WELCOME TO THE DINNER BOOKING TAB\n");
    char id[50];
    printf("Enter your Booking ID: ");
    scanf("%49s", id);

    Booking *guest = NULL;
    for (int i = 0; i < booking_count; i++) {
        if (strcmp(bookings[i].booking_id, id) == 0) {
            guest = &bookings[i];
            break;
        }
    }

    if (!guest) {
        printf("Booking ID not found.\n");
        return;
    }

    // Only FB or HB can book dinner
    if (strcasecmp(guest->board_type, "FB") != 0 && strcasecmp(guest->board_type, "HB") != 0) {
        printf("Only Full Board (FB) or Half Board (HB) guests can book dinner.\n");
        return;
    }

    printf("\nBooking details for ID %s:\n", guest->booking_id);
    printf("Name: %s %s\nBoard type: %s\nNumber of people: %d\n",
           guest->firstname, guest->surname, guest->board_type, guest->amt_ppl);

    // Show available tables
    int found_option = 0;
    printf("\nAvailable tables for your party size:\n");
    for (int i = 0; i < NUM_TABLES; i++) {
        for (int j = 0; j < NUM_SITTINGS; j++) {
            if ((table_capacity - table_occupied[i][j]) >= guest->amt_ppl) {
                printf("%d) Table %s at %s\n", i * NUM_SITTINGS + j + 1, table_names[i], sitting_times[j]);
                found_option = 1;
            }
        }
    }

    if (!found_option) {
        printf("No tables available for your party size.\n");
        return;
    }


    int choice;
    printf("Enter the number of the table/time you want to book: ");
    scanf("%d", &choice);

    int t_index = (choice - 1) / NUM_SITTINGS;
    int s_index = (choice - 1) % NUM_SITTINGS;

    // Book the table
    table_occupied[t_index][s_index] += guest->amt_ppl;
    printf("Table %s at %s successfully booked for %d people!\n",
           table_names[t_index], sitting_times[s_index], guest->amt_ppl);
}




void check_out(void) {
    char id[50];
    printf("Enter your booking ID: ");
    scanf("%49s", id);

    Booking *b = NULL;
    for (int i = 0; i < booking_count; i++) {
        if (strcmp(bookings[i].booking_id, id) == 0) {
            b = &bookings[i];
            break;
        }
    }

    if (!b) {
        printf("No booking found with ID %s\n", id);
        return;
    }

    printf("\n===== CHECK-OUT =====\n");
    printf("Booking ID: %s\n", b->booking_id);
    printf("Guest: %s %s\n", b->firstname, b->surname);


    int room_prices[] = {100,100,85,75,75,50};
    int room_index = (b->room >= 1 && b->room <=6) ? b->room-1 : 5;
    double room_total = room_prices[room_index] * b->days;
    if (b->age > 65) room_total *= 0.9; // 10% discount

    printf("Room total: GBP %.2f\n", room_total);


    int board_rate = 0;
    if (strcasecmp(b->board_type,"FB")==0) board_rate=20;
    else if (strcasecmp(b->board_type,"HB")==0) board_rate=15;
    else board_rate=5;

    double board_total = board_rate * b->days * b->amt_ppl;

    // Child discount
    if (b->age <=16) board_total *= 0.5;

    printf("Board total: GBP %.2f\n", board_total);


    double newspaper_cost = 0;
    if (strcasecmp(b->newspaper,"yes")==0) newspaper_cost = 5.5;
    if (newspaper_cost>0) printf("Newspaper: GBP %.2f\n", newspaper_cost);

    double total = room_total + board_total + newspaper_cost;
    printf("-------------------------\n");
    printf("TOTAL BILL: GBP%.2f\n", total);
    printf("=========================\n");


    printf("Room %d is now available for new guests.\n", b->room);
}



