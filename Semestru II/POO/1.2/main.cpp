#include <iostream>
#include <cmath>
#define MATRIX_HEIGHT 30
#define MATRIX_WIDTH 30

using namespace std;
int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];
void Circle(int* ptr,int cx,int cy,int ray) {
    int i,j,dist;
    for(i=0; i<MATRIX_HEIGHT; i++) {
        for(j=0; j<MATRIX_WIDTH; j++) {
            dist = (int)(sqrt((i - cx)*(i - cx)+(j - cy)*(j - cy)));
            if(dist == ray) Matrix[i][j] = 1;
        }
    }
}
int main()
{
    int i,j;
    Circle(&Matrix[0][0],12,12,10);
    for(i=0; i<MATRIX_HEIGHT; i++) {
        for(j=0; j<MATRIX_WIDTH; j++) {
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
