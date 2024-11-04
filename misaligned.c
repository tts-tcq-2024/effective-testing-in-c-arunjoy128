#include <assert.h>
#include <stdio.h>
#include <string.h>

void printString(char *string){
    printf("%s",string);
}

int printColorMap(char *stringColorMap) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    char tempString[3];
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            sprintf(tempString, "%d", i * 5 + j);
            strcpy(stringColorMap, tempString);
            strcat(stringColorMap, " | ");
            strcat(stringColorMap, majorColor[i]);
            strcat(stringColorMap, " | ");
            strcat(stringColorMap, minorColor[i]);
            strcat(stringColorMap, "\n");
        }
    }
    printString(stringColorMap);
    return i * j;
}

int main() {
    char expectedColorMap[500] = 
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";
    char stringColorMap[] = {"\0"};
    int result = printColorMap(stringColorMap);
    assert(result == 25);
    assert(strcmp(stringColorMap,expectedColorMap) == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
