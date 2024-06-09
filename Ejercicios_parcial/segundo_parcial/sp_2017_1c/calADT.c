#include "calADT.h"
#include <stdlib.h>
#include <string.h>

typedef struct eventNode {
    tEvent event;
    struct eventNode * tail;
} eventNode;

typedef eventNode * eventList;

typedef struct calCDT {
    eventList firstEvent;
    eventList nextEvent;
} calCDT;

calADT newCal() {
    return calloc(1, sizeof(calCDT));
}

// devuevle 0 si son iguales, < 0 si d1 es anterior, > 0 si d1 es posterior
static int compareDate(tDate d1, tDate d2) {
    int c;
    if((c = d1.year - d2.year)) {
        return c;
    }
    if((c = d1.month - d2.month)) {
        return c;
    }
    return d1.day - d2.day;

    // return (c = d1.year - d2.year) ? c : (c = d1.month - d2.month) ? c : d1.day - d2.day;
}

static char * cpyStr(char * s) {
    return strcpy(malloc(strlen(s) + 1), s);
}

static eventList insertEvent(eventList list, tEvent elem, int * added) {
    int c;
    if(list == NULL || (c = compareDate(list->event.date, elem.date)) > 0) {
        // inserto
        *added = 1;
        eventList new = malloc(sizeof(eventNode));
        new->event.eventName = cpyStr(elem.eventName);
        new->event.date = elem.date;
        new->tail = list;
        return new;
    }
    if(c < 0) {
        // inserto en la cola
        list->tail = insertEvent(list->tail, elem, added);
    }
    // es igual asi que no inserto nada
    return list;
}

int addEvent(calADT cal, tEvent event) {
    int added = 0;
    cal->firstEvent = insertEvent(cal->firstEvent, event, &added);
    return added;
}

void toBegin(calADT cal) {
    cal->nextEvent = cal->firstEvent;
}

tEvent nextElement(calADT cal) {
    tEvent ans;
    if(cal->nextEvent == NULL) {
        tDate nullDate = {0};
        ans.eventName = NULL;
        ans.date = nullDate;
    }
    else {
        ans = cal->nextEvent->event;
        cal->nextEvent = cal->nextEvent->tail;
    }
    return ans;
}