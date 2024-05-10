
int esPotenciaDe3(int n) {
    if(n == 1) {
        return 1;
    }
    if(n <= 0) { // seria mejor con una wrapper para esta condicion
        return 0;
    }
    return (n%3 == 0) && esPotenciaDe3(n/3);

}
