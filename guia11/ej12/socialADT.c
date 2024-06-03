#include "socialADT.h"

typedef struct friend {
    char name[MAX_LEN];
    struct friend * tail;
} friend;

typedef struct person {
    char name[MAX_LEN];
    friend * realated;
    struct person * tail;
    size_t dimRelated;
} person;

typedef struct socialCDT {
    person * people;
    size_t dimPeople;
} socialCDT;


socialADT newSocial() {
    return calloc(1, sizeof(socialCDT));
}


static char * copyStr(const char * s) {
    return strcpy(malloc(strlen(s)+1), s);
}

static person * findPerson(const socialADT soc, const char * namePerson) {
    person * per = NULL;
    person * aux = soc->people;
    while(!per && aux) {
        if(strcmp(aux->name, namePerson) == 0) {
            per = aux;
        }
        aux = aux->tail;
    }

    return per;
}


static void freeRelated(friend * list) {
    if(list == NULL) {
        return;
    }
    freeRelated(list->tail);
    free(list);
}

static void freePeople(person * list) { 
    if(list == NULL) {
        return;
    }
    freeRelated(list->realated);
    freePeople(list->tail);
    free(list);
}

void freeSocial(socialADT soc) {
    freePeople(soc->people);
    free(soc);
}



static person * insertPerson(person * list, const char * name, int * added) {
    if(list == NULL || strcmp(list->name, name) > 0) {
        (*added)++;
        person * new = calloc(1, sizeof(person));
        strncpy(new->name, name, MAX_LEN-1);
        new->tail = list;
        return new;
    }
    if(strcmp(list->name, name) < 0) {
        list->tail = insertPerson(list->tail, name, added);
    }
    
    return list;
}

void addPerson(socialADT soc, const char * name) {
    int added = 0;

    soc->people = insertPerson(soc->people, name, &added);
    if(added) {
        soc->dimPeople++;
    }

}



static friend * insertFriend(friend * list, const char * name) {
    if(list == NULL || strcmp(list->name, name) >= 0) {
        friend * new = malloc(sizeof(friend));
        strncpy(new->name, name, MAX_LEN-1);
        new->tail = list;
        return new;
    }
    list->tail = insertFriend(list->tail, name);
    return list;
}



void addRelated(socialADT soc, const char * name, const char * related) {
    person * per = findPerson(soc, name);

    if(per) {
        per->realated = insertFriend(per->realated, related);
        per->dimRelated++;
    }



}


char ** related(const socialADT soc, const char * namePerson) {
    person * per = findPerson(soc, namePerson);

    int k = 0;
    char ** names;
    if(per) {
        names = malloc((per->dimRelated + 1) * sizeof(char *));
        friend * aux = per->realated;
        while(aux) {
            names[k++] = copyStr(aux->name);
            aux = aux->tail;
        }
    }
    else {
        names = malloc(sizeof(char *));
    }

    names[k] = NULL;
    return names;
}


/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** persons(const socialADT soc) {    

    char ** names = malloc((soc->dimPeople + 1) * sizeof(char *));
    person * aux = soc->people;

    int i;
    for(i = 0; aux; i++) {
        names[i] = copyStr(aux->name);
        aux = aux->tail;
    }
    
    names[i] = NULL;
    return names;
}