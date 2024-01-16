#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct parm {
  int threadNum;
  int* results;
  int start;
  int stop;
}Parm;

int isPrime(int val) {

  if(val >= 1 && val <= 3) {
    return 1;
  }

  for(int i = 2; i < val; i++) {
    if(val%i == 0) {
      return 0;
    }
  }

  return 1;
}

int primeRange(int x, int y) {
  int primeCounter = 0;

  for(int i = x; i < y; i++) {
    if(isPrime(i)) {
        primeCounter++;
    }
  }
  return primeCounter;
}

void* myRun(void* parm) {
  Parm* theParms = (Parm*)parm;

  printf("Thread %d with range %d to %d\n", theParms->threadNum, theParms->start,
theParms->stop);

  for (int i=theParms->start; i<theParms->stop; i++) {
    int temp = primeRange(theParms->start, theParms->stop);
   theParms->results[theParms->threadNum] = temp;
  }
  return NULL;
}
int main() {
  /*
  //no thread
  
  int n = 100;
  int test1 = primeRange(0, n);

  printf("%d\n", test1);

  //thread
  int numThreads = 4;
  int ths[numThreads];

  for(int i = 0; i<numThreads; i++) {
    int start = (n/numThreads) * i;
    int stop = (n/numThreads) * (i+1);

    printf("Working on %d to %d\n", start, stop);

    int temp = primeRange(start, stop);
    printf("%d\n", temp);
    ths[i] = temp;
  }

  int final = 0;
  for(int i = 0; i < numThreads; i++) {
    final += ths[i];
  }

  printf("%d\n", final);
*/

  int n = 100;
  int numThreads = 4;
  int* results = (int*)malloc(numThreads * sizeof(int));

  pthread_t ths[numThreads];

  for (int i=0; i< numThreads; i++) {
    int start = (n/numThreads)*i;
    int stop = (n/numThreads)*(i+1);

    Parm* p = (Parm*)malloc(1 * sizeof(Parm));
    p->threadNum = i;

    p->start = start;
    p->stop = stop;
    p->results = results;
    pthread_create(&(ths[i]), NULL, myRun, (void*)p);
  }

  for (int i=0; i<numThreads; i++) {
          pthread_join(ths[i], NULL);  // blocking
  }


  int final = 0;
  for(int i=0; i < numThreads; i++) {
         final += results[i];
  }
        printf("%d\n", final);
}
