#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i;
    int seek_time = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nHead Movement Sequence:\n");
    printf("%d", head);

    for (i = 0; i < n; i++) {
        printf(" -> %d", queue[i]);
        seek_time += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\n\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);

    return 0;
}
