#include <stdio.h>

int main() {
    int frames[10], pages[30], temp[10];
    int total_pages, total_frames, page_faults = 0;
    int i, j, k = 0, flag, available;

    printf("Enter number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter number of pages: ");
    scanf("%d", &total_pages);

    printf("Enter page reference string:\n");
    for (i = 0; i < total_pages; i++)
        scanf("%d", &pages[i]);

    for (i = 0; i < total_frames; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");
    for (i = 0; i < total_pages; i++) {
        flag = 0;
        available = 0;

        // Check if page already in frame
        for (j = 0; j < total_frames; j++) {
            if (frames[j] == pages[i]) {
                available = 1;
                break;
            }
        }

        // If not available, replace using FIFO
        if (available == 0) {
            frames[k] = pages[i];
            k = (k + 1) % total_frames;
            page_faults++;
        }

        // Print frames
        printf("%d\t", pages[i]);
        for (j = 0; j < total_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
