#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int total_frames) {
    int pos = -1, farthest = index, i, j;
    for (i = 0; i < total_frames; i++) {
        int found = 0;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (found == 0)
            return i;  // Page not used in future ? replace it immediately
    }
    if (pos == -1)
        return 0;  // Default replacement
    return pos;
}

int main() {
    int pages[30], frames[10];
    int total_pages, total_frames, page_faults = 0;
    int i, j, flag1, flag2, pos;

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
        flag1 = flag2 = 0;

        // Check if page already in frame
        for (j = 0; j < total_frames; j++) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not present
        if (flag1 == 0) {
            for (j = 0; j < total_frames; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    page_faults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If all frames are full, find optimal page to replace
        if (flag2 == 0) {
            pos = findOptimal(pages, frames, total_pages, i + 1, total_frames);
            frames[pos] = pages[i];
            page_faults++;
        }

        // Print current frame state
        printf("%d\t", pages[i]);
        for (j = 0; j < total_frames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        if (flag1 == 0)
            printf("  <-- Page Fault");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    return 0;
}
