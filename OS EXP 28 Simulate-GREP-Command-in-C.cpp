
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50], pattern[50], line[200];

    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    printf("\nLines containing '%s':\n\n", pattern);

    int line_no = 1, found = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern)) {  // strstr() checks if pattern exists in line
            printf("%d: %s", line_no, line);
            found = 1;
        }
        line_no++;
    }

    if (!found)
        printf("No matches found.\n");

    fclose(fp);
    return 0;
}

