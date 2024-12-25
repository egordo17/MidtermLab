#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 15
#define JOB 15
struct Person{
    char name[NAME];
    int age;
    int salary;
    char job[JOB];
};

void showPerson(struct Person person);

int main(){
    struct Person people[20];
    struct Person* inputPerson = (struct Person*)malloc(sizeof(struct Person)*20);
    if (inputPerson == NULL){
        printf("Memorie allocation failure!!");
        free(inputPerson);
        return 1;
    }
    char* name = (char*)malloc(sizeof(char) * 15);
    if (name == NULL){
        printf("Memorie allocation failure!!");
        free(name);
        return 1;
    }
    char* job = (char*)malloc(sizeof(char) * 15);
    if (job == NULL){
        printf("Memorie allocation failure!!");
        free(job);
        return 1;
    }
    
    int size = 0;
    while( size < 20 ){
        printf("Enter people into the data base:\n");
        printf("To continue press enter:\n");
        printf("To exit the program enter X:\n");
        printf("To show the info in the data base enter S: \n");
        printf("Enter name:\n");
        scanf("%s",inputPerson->name);
        if(strcmp(inputPerson->name, "X") == 0 || strcmp(inputPerson->name, "x") == 0 ){
            break;
        }
        if(strcmp(inputPerson->name, "S") == 0 || strcmp(inputPerson->name, "s") == 0 ){
            int i = 0;
            while( i< size ){
             
                showPerson(people[size]);
                i++;
            }
        } 
      
        //printf("Enter Name:\n");
        //scanf("%s", inputPerson->name);
        printf("Enter Age:\n");
        scanf("%d", &(inputPerson->age));
        printf("Enter Salary:\n");
        scanf("%d", &(inputPerson->salary));
        printf("Enter Job:\n");
        scanf("%s", inputPerson->job);
        
        people[size] = *inputPerson;
        size++;
        
    }
    free(inputPerson);
    free(job);
    free(name);
}

 void showPerson(struct Person person){
     printf("Name: %s\n", person.name);
     printf("Age: %d\n", person.age);
     printf("Salary: %d\n", person.salary);
     printf("Job: %s\n", person.job);
 }
