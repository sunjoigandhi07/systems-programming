#include <stdio.h>

struct freq{
        int value;
        int amount;
};

//Read scores from file 
void readScores(int* array, int* size) {
        int temp;
        int i = 0;
        //check to see if at end of file        
        while(scanf("%d", &temp) != -1) {
                array[i] = temp;
                i++;
        }
        *size = i;
}

//display the scores that were read from file
void displayScores(int* array, int* size) {
        int count = 0;
        while(count < *size) {
            printf("Score %d : %d\n", count, array[count]);
                count++;
        }
}

//calculate how often each score appears 
void calcHist(struct freq* structArray, int* array, int* size) {
        int i;
        int structArraySize = 0;

        for(int i = 0; i < *size; i++) {
                //adding a new struct for the value 
                int temp = array[i];
                int marker = 0;
                int j =0;

                while(j < structArraySize) {
                        if(temp == structArray[j].value) {
                            structArray[j].amount++;
                                marker++;

                        }
                j++;
                }

                //if no entry for value 
                if(marker == 0) {
                        structArray[structArraySize].value = temp;
                        structArray[structArraySize].amount = 1;
                        structArraySize++;
                }
        }
        *size = structArraySize;
}

//display results of calcHist 
void displayHist(struct freq* array, int* size) {
     int count = 0;
        printf("HISTOGRAM:\n");
        while(count < *size) {
                printf("Value  %d : freq  %d\n", array[count].value, array[count].amount);
                count++;
        }
}

void swap(int* x, int*y) {
        int temp = *x;
        *x = *y;
        *y = temp;
}

void sortHist(struct freq* array, int* size) {
        int min;
        for(int i = 0; i < *size-1; i++) {
                min = i;
                for(int j = i+1; j < *size; j++) {
                        if(array[j].value < array[min].value) {
                             min = j;
                        }
        //      swap(&array[min].value, &array[i].value);
                swap(&array[i].value, &array[min].value);
                }
        }
}

int main(){
        int size;
        int a[100];


        readScores(a, &size);
        displayScores(a, &size);
        struct freq histogram [size];
        calcHist(histogram, a ,&size);
        displayHist(histogram, &size);
        sortHist(histogram, &size);
        displayHist(histogram, &size);
}

