#include <stdio.h>
#include <stdlib.h>

struct GridData {

    unsigned int maxwidth, userwidth, maxheight;
    unsigned char* pData;

};
struct GridData* CreateGrid(unsigned int width, unsigned int height){

}
void DestroyGrid(struct GridData* pGridData){

}
void CalcNextGrid(struct GridData* pGridData){

}

unsigned int CalcNext8x(unsigned int x){
    unsigned int mod8 = x % 8;
    return mod8 ? x - mod8 + 8 : x;
}

unsigned int IsBitSet(unsigned int bitPosition, unsigned char* pByte){
    unsigned char mask = 1 << bitPosition;
    unsigned char testMask = *pByte & mask;
    return testMask > 0 ? 1 : 0;
}

unsigned int IsCellSetInLine(unsigned int colPosition, unsigned char* pLine){
    unsigned int bitPosition = 7 - (colPosition & 0x7);
    unsigned int byteIndex = colPosition >> 3;
    return IsBitSet(bitPosition, &(pLine[byteIndex]));
}

unsigned char* GetLine(unsigned int rowPosition, struct GridData* pGrid){
    return &(pGrid->pData[(pGrid->maxwidth >> 3) * rowPosition]);
}

unsigned int IsCellSet(unsigned int colPosition, unsigned int rowPosition, struct GridData* pGrid){
    return IsCellSetInLine(colPosition, GetLine(rowPosition, pGrid));
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
