#include <stdio.h>
#include <string.h>

struct File {
    char name[30];
    int user_perm;   // owner permissions
    int group_perm;  // group permissions
    int other_perm;  // others permissions
};

void displayPermissions(int perm) {
    printf("%c", (perm & 4) ? 'r' : '-');
    printf("%c", (perm & 2) ? 'w' : '-');
    printf("%c", (perm & 1) ? 'x' : '-');
}

int main() {
    struct File f;
    strcpy(f.name, "sample.txt");

    // Assign permissions: 7 = rwx, 5 = r-x, 4 = r--
    f.user_perm = 7;   // rwx
    f.group_perm = 5;  // r-x
    f.other_perm = 4;  // r--

    printf("File Name: %s\n", f.name);
    printf("Owner Permissions : ");
    displayPermissions(f.user_perm);
    printf("\nGroup Permissions : ");
    displayPermissions(f.group_perm);
    printf("\nOthers Permissions: ");
    displayPermissions(f.other_perm);
    printf("\n");

    return 0;
}
