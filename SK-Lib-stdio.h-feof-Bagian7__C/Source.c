#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    int  count, total = 0;
    char buffer[100];
    FILE* stream;

    fopen_s(&stream, "crt_feof.txt", "r");
    if (stream == NULL) {
        exit(1);
    }
        
    while (!feof(stream)) {
        count = fread(buffer, sizeof(char), 100, stream);
        if (ferror(stream)) {
            perror("Read error");
            break;
        }

        total += count;
    }

    printf("Number of bytes read = %d\n", total);

    _getch();
    fclose(stream);
}