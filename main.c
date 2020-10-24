#include <stdio.h>
#include <stdlib.h>

struct GridData {

    unsigned int maxwidth, userwidth, userheight;
    unsigned char* pData;

};
struct GridData* CreateGrid(unsigned int width, unsigned int height){

    // Check realwidth and datasize:
    //We are going to use 1 bit per cell. Memory is addressable byte per byte, meaning 8 bits each piece, so we must
    //use the next 8x number for width. For example if we are using 74 columns in the grid we should use 10 bytes a.k.a.
    //(80 bits).
    //User width = 74, maxwidth = 80                => in cell units.
    size_t realWidth = (width % 8) ? ((width >> 3) + 1) << 3 : width;
    size_t dataSize = (realWidth >> 3) * height;//  => in byte units.

    //Allocate memory size
    size_t dataOffset = sizeof(struct GridData);
    void* pMemoryBuffer = malloc(dataOffset + dataSize);

    //Initialize Pointers
    struct GridData* pGridData = (struct GridData*) pMemoryBuffer;
    pGridData->pData = (unsigned char*)(pMemoryBuffer + dataOffset);

    //Initialize GridData
    pGridData->maxwidth = realWidth;
    pGridData->userwidth = width;
    pGridData->userheight = height;

    return pGridData;

}
void DestroyGrid(struct GridData* pGridData){

    free(pGridData);

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
