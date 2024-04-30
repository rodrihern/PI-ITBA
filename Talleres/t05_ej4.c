// ejercicio del jueguito de la matriz
#define FIL 7
#define COL 6

// calcula la distancia en la direccion inc_i, int_j --> devuelve cuanto se puede mover en esa direccion
int calculateDistance(const char m[][COL], int rows, int cols, int pos_i, int pos_j, int inc_i, int inc_j) {
    int distance = 0, hitObstacle = 0;
    int i = pos_i + inc_i, j = pos_j + inc_j;
    
    while(0 <= i && i < rows && 0 <= j && j < cols && !hitObstacle) {
    	if(m[i][j] == '0') {
    		distance++;
    		i += inc_i;
    		j += inc_j;
		}
		else {
			hitObstacle = 1;
		}
	}

    return distance;


}


int dirToDegrees(const int d[]) {
    if(d[0] == -1){
        if(d[1] == -1) return 135;
        if(d[1] == 0) return 90;
        if(d[1] == 1) return 45;
    }
    if (d[0] == 0) {
        if (d[1] == -1) return 180;
        if (d[1] == 1) return 0;
    }
    if(d[0] == 1) {
        if(d[1] == -1) return 225;
        if(d[1] == 0) return 270;
        if(d[1] == 1) return 315;
    }
    return -1;
}

int calculaDireccion(const char tablero[][COL], int rows, int cols, int pos_i, int pos_j) {
    if (pos_i < 0 || rows <= pos_i || pos_j < 0 || cols <= pos_j) {
        return -1;
    }
    
    int dir[] = {0, 0}; // vector donde me guardo la direccion (inc_i, inc_j)
    int maxDistance = 0, currentDistance;
    for (int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i != 0 || j != 0) { // no quiero llamar a la funcion en la direccion (0, 0)
                currentDistance = calculateDistance(tablero, rows, cols, pos_i, pos_j, i, j);
                if(currentDistance > maxDistance) {
                    maxDistance = currentDistance;
                    dir[0] = i;
                    dir[1] = j;
                }
            }
        }
    }

    return dirToDegrees(dir);
    

}