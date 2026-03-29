#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN      50

typedef struct {
    int id;
    char name[NAME_LEN];
    int age;
    float score;
} Student;

typedef struct {
    Student data[MAX_STUDENTS];
    int size;
} StudentList;

void init_student_list(StudentList *list)
{
    if (list == NULL) {
        return;
    }

    list->size = 0;
}

int add_student(StudentList *list, int id, const char *name,
        int age, float score)
{
    int i;

    if (list == NULL || name == NULL) {
        return 0;
    }

    if (list->size >= MAX_STUDENTS) {
        return 0;
    }

    for (i =0; i < list->size; i++) {
        if (list->data[i].id == id) {
            return 0;
        }
    }

    list->data[list->size].id = id;
    strncpy(list->data[list->size].name, name, NAME_LEN - 1);
    list->data[list->size].name[NAME_LEN - 1] = '\0';
    list->data[list->size].age = age;
    list->data[list->size].score = score;
    list->size++;

    return 1;
}

Student *find_student_by_id(StudentList *list, int id)
{
    int i;

    if (list == NULL) {
        return NULL;
    }

    for (i = 0; i < list->size; i++) {
        if (list->data[i].id == id) {
            return &list->data[i];
        }
    }

    return NULL;
}

void print_student(const Student *stu)
{
    if (stu == NULL) {
        printf("Student not fount.\n");
        return;
    }

    printf("ID: %d\n", stu->id);
    printf("Name: %s\n", stu->name);
    printf("Age: %d\n", stu->age);
    printf("Score: %.2f\n", stu->score);
}

void print_menu(void)
{
    printf("\n===== Student Management =====\n");
    printf("1. Add student\n");
    printf("2. Find student by id\n");
    printf("0. Exit\n");
    printf("Please enter your choice: ");
}

int main(void)
{
    Student list;
    int choice;
    int id;
    int age;
    float score;
    char name[NAME_LEN];
    Student *stu;

    init_student_list(&list);

    while (1) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        if (choice == 0) {
            printf("Program exited.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter id name age score: ");
                if (scanf("%d %49s %d %f", &id, name, &age, &score) != 4) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n') {
                    }
                    break;
                }
                
                if (add_student(&list, id, name, age, score)) {
                    printf("Student added successfully.\n");
                } else {
                    printf("Failed to add student. List may be full or id already exists.\n");
                }
                break;
            case 2:
                printf("Enter student id to find: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input.\n");
                    while (getchar() != '\n') {
                    }
                    break;
                }

                stu = find_student_by_id(&list, id);
                print_student(stu);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
