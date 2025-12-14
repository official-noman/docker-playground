#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*
====================================================================
 MEGA C PROGRAM (Educational)
 - Menu driven
 - Structures
 - Arrays & Strings
 - Matrix operations
 - File handling
 - Utility algorithms
====================================================================
*/

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define FILE_NAME "students.txt"

/* -------------------- STRUCTURES -------------------- */
typedef struct {
    int id;
    char name[MAX_NAME];
    float marks;
} Student;

/* -------------------- GLOBALS -------------------- */
Student students[MAX_STUDENTS];
int studentCount = 0;

/* -------------------- FUNCTION DECLARATIONS -------------------- */
void mainMenu();

/* Student management */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

/* File handling */
void saveToFile();
void loadFromFile();

/* String utilities */
void stringMenu();
void reverseString();
void countVowels();
void toUpperLower();

/* Matrix utilities */
void matrixMenu();
void matrixAddition();
void matrixTranspose();

/* Algorithms */
void algorithmMenu();
void bubbleSort();
void linearSearch();

/* Helpers */
void clearInput();

/* -------------------- MAIN -------------------- */
int main() {
    loadFromFile();
    mainMenu();
    saveToFile();
    return 0;
}

/* -------------------- MENUS -------------------- */
void mainMenu() {
    int choice;
    do {
        printf("\n========== MAIN MENU =========="
               "\n1. Student Management"
               "\n2. String Utilities"
               "\n3. Matrix Utilities"
               "\n4. Algorithms"
               "\n0. Exit"
               "\nChoose: ");
        scanf("%d", &choice);
        clearInput();

        switch (choice) {
            case 1: {
                int ch;
                do {
                    printf("\n--- Student Management ---"
                           "\n1. Add Student"
                           "\n2. Display Students"
                           "\n3. Search Student"
                           "\n4. Update Student"
                           "\n5. Delete Student"
                           "\n0. Back"
                           "\nChoose: ");
                    scanf("%d", &ch);
                    clearInput();

                    switch (ch) {
                        case 1: addStudent(); break;
                        case 2: displayStudents(); break;
                        case 3: searchStudent(); break;
                        case 4: updateStudent(); break;
                        case 5: deleteStudent(); break;
                    }
                } while (ch != 0);
                break;
            }
            case 2: stringMenu(); break;
            case 3: matrixMenu(); break;
            case 4: algorithmMenu(); break;
        }
    } while (choice != 0);
}

/* -------------------- STUDENT FUNCTIONS -------------------- */
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list full!\n");
        return;
    }
    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    clearInput();
    printf("Enter Name: ");
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    clearInput();

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nID\tName\t\tMarks\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    clearInput();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Found: %s | Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    clearInput();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new name: ");
            fgets(students[i].name, MAX_NAME, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            clearInput();
            printf("Updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    clearInput();

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

/* -------------------- FILE HANDLING -------------------- */
void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) return;
    fprintf(fp, "%d\n", studentCount);
    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;
    fscanf(fp, "%d\n", &studentCount);
    for (int i = 0; i < studentCount; i++) {
        fscanf(fp, "%d,%49[^,],%f\n", &students[i].id, students[i].name, &students[i].marks);
    }
    fclose(fp);
}

/* -------------------- STRING UTILITIES -------------------- */
void stringMenu() {
    int ch;
    do {
        printf("\n--- String Utilities ---"
               "\n1. Reverse String"
               "\n2. Count Vowels"
               "\n3. Uppercase & Lowercase"
               "\n0. Back"
               "\nChoose: ");
        scanf("%d", &ch);
        clearInput();

        switch (ch) {
            case 1: reverseString(); break;
            case 2: countVowels(); break;
            case 3: toUpperLower(); break;
        }
    } while (ch != 0);
}

void reverseString() {
    char s[200];
    printf("Enter string: ");
    fgets(s, 200, stdin);
    s[strcspn(s, "\n")] = '\0';
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }
    printf("Reversed: %s\n", s);
}

void countVowels() {
    char s[200];
    int count = 0;
    printf("Enter string: ");
    fgets(s, 200, stdin);
    for (int i = 0; s[i]; i++) {
        char c = tolower(s[i]);
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count++;
    }
    printf("Vowels: %d\n", count);
}

void toUpperLower() {
    char s[200];
    printf("Enter string: ");
    fgets(s, 200, stdin);
    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) s[i] = toupper(s[i]);
        else if (isupper(s[i])) s[i] = tolower(s[i]);
    }
    printf("Converted: %s\n", s);
}

/* -------------------- MATRIX UTILITIES -------------------- */
void matrixMenu() {
    int ch;
    do {
        printf("\n--- Matrix Utilities ---"
               "\n1. Matrix Addition"
               "\n2. Matrix Transpose"
               "\n0. Back"
               "\nChoose: ");
        scanf("%d", &ch);
        clearInput();

        switch (ch) {
            case 1: matrixAddition(); break;
            case 2: matrixTranspose(); break;
        }
    } while (ch != 0);
}

void matrixAddition() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[10][10], b[10][10];
    printf("Enter matrix A:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
    printf("Enter matrix B:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &b[i][j]);

    printf("Result:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", a[i][j] + b[i][j]);
        printf("\n");
    }
}

void matrixTranspose() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[10][10];
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);

    printf("Transpose:\n");
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) printf("%d ", a[i][j]);
        printf("\n");
    }
}

/* -------------------- ALGORITHMS -------------------- */
void algorithmMenu() {
    int ch;
    do {
        printf("\n--- Algorithms ---"
               "\n1. Bubble Sort"
               "\n2. Linear Search"
               "\n0. Back"
               "\nChoose: ");
        scanf("%d", &ch);
        clearInput();

        switch (ch) {
            case 1: bubbleSort(); break;
            case 2: linearSearch(); break;
        }
    } while (ch != 0);
}

void bubbleSort() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
    printf("Sorted: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void linearSearch() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter key: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found!\n");
}

/* -------------------- HELPERS -------------------- */
void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
