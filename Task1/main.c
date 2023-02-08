#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    int value = 0;
    value = atoi(argv[0]);
    int i = 0;
    int seqFound = 0;
    while (i < (sizeof(int) * 8) - 2) {
        if (!((value >> i) & 1)) {
            if (seqFound) {
                printf("Bad sequence at %d bit", i);
                return 0;
            }
            i++;
            continue;
        }
        seqFound = 1;
        i++;
    }
    if (seqFound) {
        printf("Good mask!");
        return;
    }
    printf("Bad mask!");
    return 0;
}