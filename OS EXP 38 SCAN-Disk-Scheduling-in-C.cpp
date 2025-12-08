#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, temp, size, direction;
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

    printf("Enter head movement direction (1 for high/end, 0 for low/start): ");
    scanf("%d", &direction);

    // Add the end points (0 and max track)
    queue[n++] = 0;
    queue[n++] = size - 1;

    // Sort all requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find position of head
    int pos;
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
    if (direction == 1) {
        for (i = pos; i < n; i++) {
            distance = abs(queue[i] - current);
            seek_time += distance;
            current = queue[i];
            printf(" -> %d", current);
        }
        // Reverse direction
        for (i = pos - 1; i >= 0; i--) {
            distance = abs(queue[i] - current);
            seek_time += distance;
            current = queue[i];
            printf(" -> %d", current);
        }
    }
    // Move toward lower end first
    else {
        for (i = pos - 1; i >= 0; i--) {
            distance = abs(queue[i] - current);
            seek_time += distance;
            current = queue[i];
            printf(" -> %d", current);
        }
        // Reverse direction
        for (i = pos; i < n; i++) {
            distance = abs(queue[i] - current);
            seek_time += distance;
            current = queue[i];
            printf(" -> %d", current);
        }
    }

    printf("\n\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / (n - 2)); // exclude added endpoints
    return 0;
}
