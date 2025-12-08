#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, size, i, j, temp;
    int seek_time = 0, distance, current;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter total number of tracks on disk: ");
    scanf("%d", &size);

    // Add start (0) and end (max-1) positions
    queue[n++] = 0;
    queue[n++] = size - 1;

    // Sort the request array
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find head position
    int pos = 0;
    for (i = 0; i < n; i++) {
        if (head < queue[i]) {
            pos = i;
            break;
        }
    }

    printf("\nHead Movement Sequence:\n");
    current = head;
    printf("%d", current);

    // Move toward higher end first
    for (i = pos; i < n; i++) {
        distance = abs(queue[i] - current);
        seek_time += distance;
        current = queue[i];
        printf(" -> %d", current);
    }

    // Jump from end to beginning
    seek_time += abs((size - 1) - 0);
    current = 0;
    printf(" -> 0");

    // Continue servicing requests on the left side
    for (i = 0; i < pos; i++) {
        distance = abs(queue[i] - current);
        seek_time += distance;
        current = queue[i];
        printf(" -> %d", current);
    }

    printf("\n\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / (n - 2)); // exclude added endpoints
    return 0;
}
