#define N 3
#define M 5

#define pRed 0.2989
#define pGreen 0.5870
#define pBlue 0.1140

void rgbToGrey(const unsigned char colorImg[N][3*M], unsigned char greyImg[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3*M; j += 3) {
            greyImg[i][j/3] = colorImg[i][j] * pRed + colorImg[i][j+1] * pGreen + colorImg[i][j+2] * pBlue;
        }
    }
}