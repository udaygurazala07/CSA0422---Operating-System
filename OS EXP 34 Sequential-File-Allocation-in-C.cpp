#include <stdio.h>
#include <string.h>
struct file {
    char name[20];
    int start;
    int size;
    int blocks[20];
};

int main() {
    struct file f[10];
    int memory[50] = {0};
    int n, i, j, k, flag, m, count = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name: ");
        scanf("%s", f[i].name);

        printf("Enter start block and size of file: ");
        scanf("%d%d", &f[i].start, &f[i].size);

        flag = 0;
        for (j = f[i].start; j < (f[i].start + f[i].size); j++) {
            if (memory[j] == 1) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            for (j = f[i].start, k = 0; k < f[i].size; j++, k++) {
                memory[j] = 1;
                f[i].blocks[k] = j;
            }
            printf("File %s allocated successfully.\n", f[i].name);
        } else {
            printf("File %s cannot be allocated (space already occupied).\n", f[i].name);
            f[i].start = -1; // mark as not allocated
        }
    }

    printf("\nFile\tStart\tSize\tBlocks Allocated\n");
    for (i = 0; i < n; i++) {
        if (f[i].start != -1) {
            printf("%s\t%d\t%d\t", f[i].name, f[i].start, f[i].size);
            for (j = 0; j < f[i].size; j++)
                printf("%d ", f[i].blocks[j]);
            printf("\n");
        }
    }

    // Access simulation
    printf("\nEnter file name to access: ");
    char fname[20];
    scanf("%s", fname);
    flag = 0;

    for (i = 0; i < n; i++) {
        if (f[i].start != -1 && strcmp(f[i].name, fname) == 0) {
            printf("Accessing file %s sequentially...\n", f[i].name);
            for (j = 0; j < f[i].size; j++)
                printf("Reading block %d...\n", f[i].blocks[j]);
            flag = 1;
            break;
        }
    }

    if (!flag)
        printf("File not found or not allocated!\n");

    return 0;
}
