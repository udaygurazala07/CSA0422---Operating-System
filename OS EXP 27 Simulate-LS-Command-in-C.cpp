#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *de;  // Pointer for directory entry
    DIR *dr = opendir(".");

    if (dr == NULL) {
        printf("Could not open current directory\n");
        return 0;
    }

    printf("Files and Directories in current folder:\n\n");

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}
