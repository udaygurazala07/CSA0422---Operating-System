#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50], data[1000];
    int choice;

    while (1) {
        printf("\n--- File Management Operations ---\n");
        printf("1. Create and Write File\n");
        printf("2. Read File\n");
        printf("3. Append to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                gets(filename);
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error creating file!\n");
                    exit(1);
                }
                printf("Enter data to write: ");
                gets(data);
                fprintf(fp, "%s", data);
                fclose(fp);
                printf("File created and data written successfully.\n");
                break;

            case 2:
                printf("Enter filename to read: ");
                gets(filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("File not found!\n");
                    break;
                }
                printf("\n--- File Content ---\n");
                while (fgets(data, sizeof(data), fp) != NULL) {
                    printf("%s", data);
                }
                fclose(fp);
                printf("\n--- End of File ---\n");
                break;

            case 3:
                printf("Enter filename to append: ");
                gets(filename);
                fp = fopen(filename, "a");
                if (fp == NULL) {
                    printf("File not found!\n");
                    break;
                }
                printf("Enter data to append: ");
                gets(data);
                fprintf(fp, "\n%s", data);
                fclose(fp);
                printf("Data appended successfully.\n");
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
