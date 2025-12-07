#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int main(void) {
    int bitmap[MAX_BLOCKS] = {0};   /* 0 = free, 1 = used */
    int indexBlock;
    int n;
    int blocks[MAX_BLOCKS];
    int i;

    printf("Total blocks: 0 .. %d\n", MAX_BLOCKS - 1);

    /* read index block */
    printf("Enter index block number: ");
    if (scanf("%d", &indexBlock) != 1) {
        fprintf(stderr, "Invalid input for index block.\n");
        return 1;
    }
    if (indexBlock < 0 || indexBlock >= MAX_BLOCKS) {
        fprintf(stderr, "Index block out of range (0..%d).\n", MAX_BLOCKS - 1);
        return 1;
    }

    /* read number of data blocks */
    printf("Enter number of data blocks needed for the file: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for number of blocks.\n");
        return 1;
    }
    if (n <= 0 || n > MAX_BLOCKS - 1) {
        fprintf(stderr, "Number of blocks must be between 1 and %d.\n", MAX_BLOCKS - 1);
        return 1;
    }

    /* Collect data block numbers with checks */
    int temp_used[MAX_BLOCKS] = {0}; /* detect duplicates in this input */
    for (i = 0; i < n; i++) {
        printf("Enter block number #%d: ", i + 1);
        if (scanf("%d", &blocks[i]) != 1) {
            fprintf(stderr, "Invalid input for block number.\n");
            return 1;
        }
        if (blocks[i] < 0 || blocks[i] >= MAX_BLOCKS) {
            fprintf(stderr, "Block %d out of range (0..%d).\n", blocks[i], MAX_BLOCKS - 1);
            return 1;
        }
        if (blocks[i] == indexBlock) {
            fprintf(stderr, "Block %d is the index block. Cannot use it as a data block.\n", blocks[i]);
            return 1;
        }
        if (temp_used[blocks[i]]) {
            fprintf(stderr, "Duplicate data block %d entered.\n", blocks[i]);
            return 1;
        }
        if (bitmap[blocks[i]]) {
            fprintf(stderr, "Block %d is already allocated.\n", blocks[i]);
            return 1;
        }
        temp_used[blocks[i]] = 1;
    }

    /* All checks passed — perform allocation */
    bitmap[indexBlock] = 1;
    for (i = 0; i < n; i++) bitmap[blocks[i]] = 1;

    /* Report */
    printf("\nFile allocated successfully.\n");
    printf("Index block: %d\n", indexBlock);
    printf("Data blocks: ");
    for (i = 0; i < n; i++) printf("%d ", blocks[i]);
    printf("\n\nSimulating access via index block %d:\n", indexBlock);
    for (i = 0; i < n; i++) {
        printf("Index entry %d -> block %d  (reading)\n", i, blocks[i]);
    }

    return 0;
}
