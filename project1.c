#include <stdio.h>

#define MAX_SEATS 10

int seats[MAX_SEATS];
int reserved_seats = 0;
int available_seats = MAX_SEATS;

void display_seats() {
    printf("Seat Reservation Status:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 0) {
            printf("Seat %d: Available\n", i + 1);
        } else {
            printf("Seat %d: Reserved\n", i + 1);
        }
    }
}

void reserve_seat() {
    if (available_seats > 0) {
        int seat_number;
        printf("Enter seat number to reserve (1-%d): ", MAX_SEATS);
        scanf("%d", &seat_number);
        if (seat_number >= 1 && seat_number <= MAX_SEATS) {
            if (seats[seat_number - 1] == 0) {
                seats[seat_number - 1] = 1;
                reserved_seats++;
                available_seats--;
                printf("Seat %d reserved successfully.\n", seat_number);
            } else {
                printf("Seat %d is already reserved.\n", seat_number);
            }
        } else {
            printf("Invalid seat number.\n");
        }
    } else {
        printf("No seats available for reservation.\n");
    }
}

void cancel_reservation() {
    if (reserved_seats > 0) {
        int seat_number;
        printf("Enter seat number to cancel reservation (1-%d): ", MAX_SEATS);
        scanf("%d", &seat_number);
        if (seat_number >= 1 && seat_number <= MAX_SEATS) {
            if (seats[seat_number - 1] == 1) {
                seats[seat_number - 1] = 0;
                reserved_seats--;
                available_seats++;
                printf("Reservation for seat %d cancelled successfully.\n", seat_number);
            } else {
                printf("Seat %d is not reserved.\n", seat_number);
            }
        } else {
            printf("Invalid seat number.\n");
        }
    } else {
        printf("No reservations to cancel.\n");
    }
}

void display_stats() {
    printf("Total seats: %d\n", MAX_SEATS);
    printf("Available seats: %d\n", available_seats);
    printf("Reserved seats: %d\n", reserved_seats);
}


int main() {
    int choice;
    while (1) {
        printf("Theater Seat Reservation System\n");
        printf("1. Display seat reservation status\n");
        printf("2. Reserve a seat\n");
        printf("3. Cancel a reservation\n");
        printf("4. Display statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_seats();
                break;
            case 2:
                reserve_seat();
                break;
            case 3:
                cancel_reservation();
                break;
            case 4:
                display_stats();
                break;
            case 5:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    return 0;
}
