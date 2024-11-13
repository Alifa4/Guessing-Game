#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number within a range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to play a guessing game
void playGuessingGame() {
    int secretNumber, guess, attempts = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random secret number between 1 and 100
    secretNumber = generateRandomNumber(1, 100);

    printf("Welcome to the Guessing Game!\n");
    printf("I've chosen a secret number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed it in %d attempts.\n", attempts);
        }
    } while (guess != secretNumber);
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Play Guessing Game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGuessingGame();
                break;
            case 2:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}
