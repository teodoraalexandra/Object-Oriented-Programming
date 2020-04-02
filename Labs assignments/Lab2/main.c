#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LEN 80


int getMonthOne(const char *str){
    return str[3];
}

int getMonthTwo(const char *str){
    return str[4];
}

int getDay(char one, char two) {
    char str1[16];
    str1[0] = one;
    str1[1] = '\0';

    char str2[16];
    str2[0] = two;
    str2[1] = '\0';

    strcat(str1, str2);

    char *num = str1;
    int val = atoi(num);

    if ((val >= 1) && (val <= 31)) {
        return val;
    }
    else {
        printf("Wrong day! Enter between 1 and 31\n");
        return -1;
    }
}

int main()
{
	char s1[MAX_STRING_LEN];
	char lista_printare[MAX_STRING_LEN];
	char convertire[MAX_STRING_LEN];

    int i, l, day;

	printf("Enter the dates using dd-mm-yyyy: ");

    scanf("%[^'\n']s",s1);

	char delim[] = " ";

	char *date = strtok(s1, delim);

	while(date != NULL)
	{
		if (getMonthOne(date) == '1')
        {
		    if (getMonthTwo(date) == '0') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 273);
                }

            } else if (getMonthTwo(date) == '1') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 304);
                }

		    } else if (getMonthTwo(date) == '2'){
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 334);
                }

		    } else {
                printf("Your month from %s for is wrong. Check again.\n", date);
		    }
        }
		else if (getMonthOne(date) == '0')
        {
            if (getMonthTwo(date) == '1') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day);
                }

            } else if (getMonthTwo(date) == '2') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 31);
                }

            } else if (getMonthTwo(date) == '3') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 59);
                }

            } else if (getMonthTwo(date) == '4') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 90);
                }

            } else if (getMonthTwo(date) == '5') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 120);
                }

            } else if (getMonthTwo(date) == '6') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 151);
                }

            } else if (getMonthTwo(date) == '7') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 181);
                }

            } else if (getMonthTwo(date) == '8') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 212);
                }

            } else if (getMonthTwo(date) == '9') {
                day = getDay(date[0], date[1]);
                if (day != -1) {
                    printf("%d ", day + 243);
                }

            } else {
                printf("Your month from %s for is wrong. Check again.\n", date);
            }
        }
		else
        {
		    printf("Your month from %s for is wrong. Check again.\n", date);
        }
		date = strtok(NULL, delim);
	}
}
