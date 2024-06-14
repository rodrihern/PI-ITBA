#include "museumTicketADT.h"
#include <string.h>
#define DAYS 366

typedef struct nameNode {
    char * name;
    size_t len; // para que cuando lo retorne no haga falta volver a hacer el strlen
    struct namesNode * tail;
} nameNode;

typedef nameNode * nameList;

typedef struct tDay {
    size_t soldTickets;
    nameList firstVisitor;
    nameList visitorIterator;
} tDay;

typedef struct museumTicketCDT {
    tDay day[DAYS];
    size_t totalTickets;
} museumTicketCDT;


static int validDay(size_t day) {
    return (0 < day && day <= DAYS);
}
/**
* Reserva los recursos para administrar las ventas de tickets para visitar un museo en
* un año determinado
* Nota: Como no se indica el año para el que se lo utilizará se asume que el
* año será siempre bisiesto
*/
museumTicketADT newMuseumTicket(void) {
    return calloc(1, sizeof(museumTicketCDT));
}
/**
* Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año
* Retorna la cantidad actual de tickets registrados para visitar el museo ese día
* Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
* Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
*/
static cpyStr(const char * s, size_t len) {
    if(s == NULL) {
        return NULL;
    }
    return strcpy(malloc(len + 1), s);
}

static nameList insertName(nameList list, char * name, int * added) {
    int c;
    if(list == NULL || (c = strcmp(list->name, name)) > 0) {
        // inserto
        *added = 1;
        nameList new = malloc(sizeof(nameNode));
        new->len = strlen(name);
        new->name = cpyStr(name, new->len);
        new->tail = list;
        return new;
    }
    if(c < 0) {
        // inserto en la cola
        list->tail = insertName(list->tail, name, added);
    }
    return list;
}

int addTicket(museumTicketADT mt, size_t dayOfYear, const char * visitor) {
    if(!validDay(dayOfYear)) {
        return 0;
    }
    int added = 0;
    mt->day[dayOfYear].firstVisitor = insertName(mt->day[dayOfYear].firstVisitor, visitor, &added);
    mt->day[dayOfYear].soldTickets += added;
    mt->totalTickets += added;
    
    return mt->day[dayOfYear].soldTickets;
}


/**
* Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
* del año
* Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
*/
int dayTickets(const museumTicketADT mt, size_t dayOfYear) {
    if(!validDay(dayOfYear)) {
        return -1;
    }

    return mt->day[dayOfYear].soldTickets;

}

/**
* Funciones de iteración para poder consultar, para un día #dayOfYear del año,
* los nombres de los visitantes de los tickets registrados para visitar el museo
* ese día en orden alfabético por nombre de visitante.
* IMPORTANTE: Permitir utilizar estas funciones para distintos días del año
* EN SIMULTANEO (ver ejemplo en programa de prueba)
* Abortar si cualquiera de las funciones es invocada con un #dayOfYear igual a 0
* o mayor a 366
*/
void toBeginByDay(museumTicketADT mt, size_t dayOfYear) {
    if(!validDay(dayOfYear)) {
        exit(1);
    }

    mt->day[dayOfYear].visitorIterator = mt->day[dayOfYear].firstVisitor;
}
