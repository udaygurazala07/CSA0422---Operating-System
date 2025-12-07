#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[30], time[10];
    int total_pages, total_frames, counter = 0, page_faults = 0;
    int i, j, pos, flag1, flag2;

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
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If not available, find least recently used frame
        if (flag1 == 0) {
            for (j = 0; j < total_frames; j++) {
                if (frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            pos = findLRU(time, total_frames);
            counter++;
            page_faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

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
