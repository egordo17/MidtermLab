#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 15
#define JOB 15

struct Person {
    char name[NAME];
    int age;
    int salary;
    char job[JOB];
};

void showPerson(struct Person* person);

int main() {
    struct Person* people = (struct Person*)malloc(sizeof(struct Person) * 20); // Dynamic allocation for 20 people
    if (people == NULL) {
        printf("Memory allocation failure!\n");
        return 1;
    }

    struct Person* inputPerson = (struct Person*)malloc(sizeof(struct Person)); // Allocate memory for a single input
    if (inputPerson == NULL) {
        printf("Memory allocation failure!\n");
        free(people);
        return 1;
    }

    int size = 0;
    while (size < 20) {
        printf("Enter people into the database:\n");
        printf("To continue press Enter:\n");
        printf("To exit the program enter X:\n");
        printf("To show the info in the database enter S:\n");
        printf("Enter name:\n");
        scanf("%s", inputPerson->name);

        if (strcmp(inputPerson->name, "X") == 0 || strcmp(inputPerson->name, "x") == 0) {
            break; // Exit the program
        }

        if (strcmp(inputPerson->name, "S") == 0 || strcmp(inputPerson->name, "s") == 0) {
            printf("Showing all people in the database:\n");
            for (int i = 0; i < size; i++) {
                showPerson(&people[i]); // Pass the address of each person
            }
            continue; // Skip adding another person after showing
        }

        printf("Enter Age:\n");
        scanf("%d", &(inputPerson->age));
        printf("Enter Salary:\n");
        scanf("%d", &(inputPerson->salary));
        printf("Enter Job:\n");
        scanf("%s", inputPerson->job);

        // Copy inputPerson to the array
        people[size] = *inputPerson; // Copy the data
        size++;
    }

    // Free allocated memory
    free(inputPerson);
    free(people);

    return 0;
}

void showPerson(struct Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Salary: %d\n", person->salary);
    printf("Job: %s\n", person->job);
    printf("-------------------------\n");
}
