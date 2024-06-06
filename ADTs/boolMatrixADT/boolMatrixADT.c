#include "boolMatrixADT.h"

// Nodo para guardar el valor de una columna
struct column {
    size_t col;
    struct column * tail;
};

typedef struct column * ListCol;

struct row {
    size_t row; // valor de la fila
    ListCol firstCol;
    struct row * tail;
};
typedef struct row * ListRow;

struct boolMatrixCDT {
    ListRow firstRow;
    boolean defaultValue;   // por defecto false
};

boolMatrixADT newBoolMatrix(void) {
    return calloc(1, sizeof(struct boolMatrixCDT));
}

static ListCol addCol(ListCol l, size_t col) {
    if (l==NULL || col < l->col) {
        ListCol aux = malloc(sizeof(*aux));
        aux->col=col;
        aux->tail=l;
        return aux;
    }
    if ( col > l->col ) {
        l->tail = addCol(l->tail, col);
    }
    return l;
}

static ListRow addRow(ListRow l, size_t row, size_t col) {
    if ( l==NULL || row < l->row) {
        ListRow aux = malloc(sizeof(*aux));
        aux->row = row;
        aux->tail =l;
        aux->firstCol = addCol(NULL, col);
        return aux;
    }
    if ( row == l->row) {
        l->firstCol = addCol(l->firstCol, col);
        return l;
    }
    l->tail = addRow(l->tail, row, col);
    return l;
}

ListCol removeCol(ListCol l, size_t col) {
    if ( l==NULL || l->col > col) {
        return l;
    }
    if ( l->col == col) {
        ListCol aux = l->tail;
        free(l);
        return aux;
    }
    l->tail = removeCol(l->tail, col);
    return l;
}

static ListRow removeRow(ListRow l, size_t row, size_t col) {
    if (l==NULL || l->row > row) {
        return l;
    }
    if ( l->row == row) {
        l->firstCol = removeCol(l->firstCol, col);
        // OPCIONAL: si la fila quedó sin trues, la eliminamos
        if ( l->firstCol == NULL) {
            ListRow aux = l->tail;
            free(l);
            return aux;
        }
        return l;
    }
    l->tail = removeRow(l->tail, row, col);
    return l;
}

void setValue(boolMatrixADT m, size_t row, size_t col, boolean value) {
    if ( value != m->defaultValue) {
        m->firstRow = addRow(m->firstRow, row, col);
    } else {
        m->firstRow = removeRow(m->firstRow, row, col);
    }
}

static boolean belongsCol(ListCol l, size_t col) {
    if ( l==NULL || l->col > col) {
        return false;
    }
    if ( l->col == col) {
        return true;
    }
    return belongsCol(l->tail, col);
}

static boolean belongs(ListRow l, size_t row, size_t col) {
    if ( l==NULL || l->row > row) {
        return false;
    }
    if ( l->row == row) {
        return belongsCol(l->firstCol, col);
    }
    return belongs(l->tail, row, col);
}

static boolean belongsIter(ListRow l, size_t row, size_t col) {
   for(; l != NULL && l->row <= row; l = l->tail) {
       if ( l->row == row) {
           ListCol c;
            for( c = l->firstCol; c != NULL && c->col < col; c=c->tail)
                ;
            return c!=NULL && c->col==col;

            // Alternativa
           for( ListCol c = l->firstCol; c != NULL && c->col <= col; c=c->tail) {
               if ( c->col==col) {
                   return true;
               }
           }
           return false;
       }
   }
   return false;
}

boolean getValue(const boolMatrixADT m, size_t row, size_t col) {
    return m->defaultValue != belongs(m->firstRow, row, col);
}

void negate(boolMatrixADT m) {
    m->defaultValue = ! m->defaultValue;
}

static void freeCol(ListCol l) {
    if (l==NULL) {
        return;
    }
    freeCol(l->tail);
    free(l);
}

static void freeRow(ListRow l) {
    if ( l==NULL) {
        return;
    }
    ListRow aux = l->tail;
    freeCol(l->firstCol);
    free(l);
    freeRow(aux);
}

void freeBoolMatrix(boolMatrixADT m) {
    freeRow(m->firstRow);
    free(m);
}