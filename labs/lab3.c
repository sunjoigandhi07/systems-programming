#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int binToDec(char* bin) {
        int num = 0;

        while(*bin){
                num*=2;
                if(*bin =='1') {
                        num +=1;
                } else {

                }
                ++bin;
        }
        return num;
}

char valueToChar(int c) {
        if(c >= 10) {
                return 'A' + (c-10);
        } else {
                return c+'0';
        }
}

char* decToBin(int dec) {
        int shift;
        int count = 0;
        char* output = (char*)malloc(32+1);

        for(int i = 31; i >=0; i--) {
                shift = dec >>i;
                if(shift & 1) {
                        *(output+count) ='1';
                } else {
                        *(output+count) ='0';
                }
                count++;

        }
        return output;
}
int baseToDec(int base, char* value) {
        int num =0;
        while(*value){
                num *= base;

                if((*value - '0')<22) {
                        num += *value- '0';
                } else
                        num +=((*value - '0') - 39);
                        ++value;
        }
        return num;
}

char* decToBase(int base, int value) {
        int count = 0;
        char temp[50];

        int val = value;
        int k= 0;

        while(val != 0) {
                temp[k] = valueToChar(val % base);
                val = val /base;
                k++;
        }

        char* returnBinary = (char*)malloc(k + 1*sizeof(char));
        for(int i = 0; i <= k; i++) {
                returnBinary[i] = temp[k-i-1];
        }
        return returnBinary;
}
int main() {
        int num = binToDec("11001");
        char* test = decToBin(5);

        printf("%d\n", num);
        printf("%s\n", test);

        int num2 = baseToDec(2, "11001");
        int num3 = baseToDec(8, "157");
        int num4 = baseToDec(16, "f8");

        printf("%d\n", num2);
        printf("%d\n", num3);
        printf("%d\n", num4);

        char* num5 = decToBase(2, 25);
        char* num6 = decToBase(8, 111);
        char* num7 = decToBase(16, 248);

        printf("%s\n", num5);
        printf("%s\n", num6);
        printf("%s\n", num7);

}
    
