#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct freq{
        char* value;
        int amount;
}histogram;

//Read scores from file 
char** readScores (int* size) {
        char** array = (char**)malloc(100*sizeof(char*));
        int i = 0;
        char* temp = (char*)malloc(10*sizeof(char));
        int num;

        while(scanf("%s", temp) != -1) {
                num= strlen(temp);
                array[i] = (char*)malloc((num+1)*sizeof(char));
                strcpy(array[i], temp);
                i++;
        //      printf("%s\n", temp); 
        }
        *size = i;
        return array;
}

//display the scores that were read from file
void displayScores(char** array, int *size) {
        int count = 0;
        while(count < *size) {
                printf("Word %d: %s\n", count, array[count]);
                count++;
        }

}

//calculate how often each score appears 
int calcHist (histogram** h, char** array, int* size) {
        int structArraySize = 0;
        histogram* structArray = (histogram*)malloc(10*sizeof(histogram));

        for(int i = 0; i < *size; i++) {
                //adding a new struct for the value
                char* temp = array[i];
                int marker = 0;
                int j =0;

                while(j < structArraySize) {
                        if(strcmp(temp, structArray[j].value)==0) {
                                structArray[j].amount++;
                                 marker++;

                        }
                        j++;
                }
                //if no entry for the word 
                if(marker == 0) {
                        structArray[structArraySize].value = temp;
                        structArray[structArraySize].amount = 1;
                        structArraySize++;
                }
        }
        *h = structArray;
        return structArraySize;
}


//display results of calcHist 
void displayHist(histogram* array, int* size) {
        int count =0;
        printf("HISTOGRAM: \n");
        while(count < *size) {
                printf("Word- %s: freq %d\n", array[count].value, array[count].amount);
        count++;
        }
}

void swap(histogram* x, histogram* y) {
       histogram temp = *x;
       *x = *y;
       *y = temp;
}

void sortHist(histogram* a, int hCount) {
        int i;
        int j;
        int max;

        for(i = 0; i < hCount-1; i++) {
                min = i;
                for(j = i+1; j < hCount; j++) {
                        if(a[j].amount < a[min].amount) {
                                max = j;
                               swap(&a[min],&a[i]);
                        }
                }
        }
}

int main() {
        histogram* hist;
        int counter;
        int size;

        char** array = readScores(&size);
        displayScores(array, &size);
        printf("\n");
        counter = calcHist(&hist, array, &size);
        displayHist(hist, &counter);
        printf("\n");

        sortHist(hist, counter);
        printf("SORTED ");
        displayHist(hist, &counter);
        printf("the end\n");

        return 0;
        free(array);
        free(hist);
}
              