#define ENE 1
#define FEB 2
#define DIC 12

int esBisiesto(int year) {
    return 0;
}

int unDiaMas(int *day, int *month, int *year) {
    int dayMonth[] = {31, (esBisiesto(*year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(*month < 1 || 12 < *month || *day < 1 || dayMonth[*month-1] < *day) {
        return 0;
    }

    if(*day == dayMonth[*month-1]) {
        *day = 1;
        if(*month == DIC) {
            (*year)++;
            *month = ENE;
        }
        else {
            (*month)++;
        }
    }
    else {
        (*day)++;
    }

    return 1;
}