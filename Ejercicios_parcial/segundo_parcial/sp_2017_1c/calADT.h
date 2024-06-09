typedef struct calCDT * calADT;

typedef struct tDate {
    unsigned char day;
    unsigned char month;
    unsigned short year;
} tDate;

typedef struct tEvent {
    char * eventName;
    tDate date;
} tEvent;

calADT newCal();

int addEvent(calADT cal, tEvent event);

void toBegin(calADT cal);

tEvent nextElement(calADT cal);