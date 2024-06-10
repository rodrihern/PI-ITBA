#include "addressBookADT.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>

typedef struct contactNode{
    tContact info;
    struct contactNode * tail;
} contactNode;

typedef contactNode * contactList;

typedef struct groupNode{
    char * name;
    contactList firstContact;
    struct groupNode * tail;
} groupNode;

typedef groupNode * groupList;

typedef struct addressBookCDT {
    groupList firstGroup;
    groupList nextGroup;
    contactList nextContact;
} addressBookCDT;


/* Crea un nuevo TAD vacÃ­o */
addressBookADT newAddressBook() {
    return calloc(1, sizeof(addressBookCDT));
}

static char * cpyStr(const char * s) {
    return strcpy(malloc(strlen(s) + 1), s);
}


// inserta ordenado un grupo y deja en added un 1 si lo agrego
static groupList insertGroup(groupList list, const char * name, int * added) {
    int c;
    if(list == NULL || (c = strcasecmp(list->name, name)) > 0) {
        // inserto
        *added = 1;
        groupList new = malloc(sizeof(groupNode));
        new->name = cpyStr(name);
        new->firstContact = NULL;
        new->tail = list;
        return new;
    }
    if(c < 0) {
        // inserto en la cola
        list->tail = insertGroup(list->tail, name, added);
    }
    //retorno porque el elemento ya existia
    return list;
}

int addGroup(addressBookADT ab, const char * groupName) {
    int added = 0;
    ab->firstGroup = insertGroup(ab->firstGroup, groupName, &added);
    return added;
}


// retorna un puntero al grupo si el grupo existe, NULL si no
static groupList findGroup(groupList list, const char * name) {
    groupList ans = NULL;
    while(!ans && list) {
        if(strcasecmp(list->name, name) == 0) {
            ans = list;
        }
        list = list->tail;
    }
    return ans; 
}

// inserta un contacto ordenado y deja en added un 1 si lo agrego
static contactList insertContact(contactList list, tContact contact, int * added) {
    int c;
    if(list == NULL || (c = strcasecmp(list->info.name, contact.name)) > 0) {
        //inserto
        *added = 1;
        contactList new = malloc(sizeof(contactNode));
        new->info = contact;
        new->tail = list;
        return new;
    }
    if(c < 0) {
        // inserto en la cola
        list->tail = insertContact(list->tail, contact, added);
    }
    // ya existia el contacto
    return list;
}



int addContact(addressBookADT ab, const char * groupName, tContact contact) {
    groupList group = findGroup(ab->firstGroup, groupName);
    if(group == NULL) {
        return 0;
    }
    int added = 0;
    group->firstContact = insertContact(group->firstContact, contact, &added);
    return added;
}



void toBeginForGroup(addressBookADT ab, const char * groupName) {
    groupList group = findGroup(ab->firstGroup, groupName);
    if(group == NULL) {
        return;
    }
    ab->nextContact = group->firstContact;
}



int hasNextForGroup(addressBookADT ab) {
    return ab->nextContact != NULL;
}


tContact nextForGroup(addressBookADT ab) {
    if(!hasNextForGroup(ab)) {
        exit(1);
    }
    tContact ans = ab->nextContact->info;
    ab->nextContact = ab->nextContact->tail;
    return ans;
}



void toBegin(addressBookADT ab) {
    ab->nextGroup = ab->firstGroup;
}



int hasNext(addressBookADT ab) {
    return ab->nextGroup != NULL;
}



char * next(addressBookADT ab) {
    if(!hasNext(ab)) {
        exit(1);
    }
    char * ans = cpyStr(ab->nextGroup->name) ;
    ab->nextGroup = ab->nextGroup->tail;
    return cpyStr(ans);
}