#include <stdio.h>

typedef unsigned short bitSet;

//creates a new bit set 
bitSet makeBitSet(){
        bitSet bs = 90;
        return bs;
}

//Displays the 16 bits of the bitset to the screen 
void displayBitSet(bitSet bs) {
        for(int i= 15; i >=0; i--) {
                printf("%d", (bs >> i) & 1);
        }
        printf("\n");
}

//Sets bit index of the bitset to 1 
void setBit(bitSet* bs, int index) {
        *bs |= (1 << index);
}

//Sets bit index of the bitset to 0 
void clearBit(bitSet* bs, int index) {
        *bs &= ~(1 << index);
}

//returns the value of the bit at index 
int bitValue(bitSet bs, int index) {
        int bit = (bs >> index) & 1;
}

int main() {

        bitSet set = makeBitSet();
        displayBitSet(set);
        setBit(&set, 10);
        displayBitSet(set);
        clearBit(&set, 10);
        displayBitSet(set);
        printf("%d\n", bitValue(set, 10));

}