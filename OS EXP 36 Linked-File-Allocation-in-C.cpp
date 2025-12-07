#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BLOCKS 50

struct File {
    char name[20];
    int start;
    int end;
    int size;
    int blocks[MAX_BLOCKS];
};

int main() {
    struct File files[10];
    int memory[MAX_BLOCKS] = {0};
    int n, i, j, k, flag, totalFiles = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name: ");
        scanf("%s", files[i].name);

        printf("Enter number of blocks required: ");
        scanf("%d", &files[i].size);

        printf("Enter the block numbers for the file: ");
        for (j = 0; j < files[i].size; j++) {
            scanf("%d", &files[i].blocks[j]);
        }

        // Check if all blocks are free
        flag = 0;
        for (j = 0; j < files[i].size; j++) {
            if (files[i].blocks[j] < 0 || files[i].blocks[j] >= MAX_BLOCKS) {
                printf("Invalid block number %d! Allocation failed.\n", files[i].blocks[j]);
                flag = 1;
                break;
            }
            if (memory[files[i].blocks[j]] == 1) {
                printf("Block %d already allocated! Allocation failed.\n", files[i].blocks[j]);
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            i--;
            continue;
        }

        // Allocate the blocks
        for (j = 0; j < files[i].size; j++)
            memory[files[i].blocks[j]] = 1;

        files[i].start = files[i].blocks[0];
        files[i].end = files[i].blocks[files[i].size - 1];
        totalFiles++;

        printf("File %s allocated successfully.\n", files[i].name);
        printf("Start Block: %d, End Block: %d\n", files[i].start, files[i].end);
    }

    printf("\nFile Allocation Table (Linked Allocation)\n");
    printf("-------------------------------------------\n");
    printf("File\tStart\tEnd\tBlocks (Linked Order)\n");
    for (i = 0; i < totalFiles; i++) {
        printf("%s\t%d\t%d\t", files[i].name, files[i].start, files[i].end);
        for (j = 0; j < files[i].size; j++) {
            if (j == files[i].size - 1)
                printf("%d(NULL)", files[i].blocks[j]);  // Last block has no next link
            else
                printf("%d->", files[i].blocks[j]);      // Link to next block
        }
        printf("\n");
    }

    // Simulate file access
    char fname[20];
    printf("\nEnter file name to access: ");
    scanf("%s", fname);

    flag = 0;
    for (i = 0; i < totalFiles; i++) {
        if (strcmp(fname, files[i].name) == 0) {
            printf("Accessing file %s...\n", fname);
            for (j = 0; j < files[i].size; j++) {
                if (j == files[i].size - 1)
                    printf("Reading block %d -> NULL\n", files[i].blocks[j]);
                else
                    printf("Reading block %d -> %d\n", files[i].blocks[j], files[i].blocks[j + 1]);
            }
            flag = 1;
            break;
        }
    }

    if (!flag)
        printf("File not found!\n");

    return 0;
}
