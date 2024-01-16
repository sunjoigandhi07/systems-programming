#include <iostream>
#include <thread>
#include <omp.h>
#include <mutex>

int primeNumberFinder(int num){
  int temp = 2;
  if (num <=  1){
    return 0;
  }

  while (temp != num){
    if (num%temp == 0){
      return 0;
    } else {
      temp++;
    }
  }
  return 1;
}

std::mutex screenLock;
void blocking(int n, int start, int stop){

  omp_set_num_threads(n);

  int total = 0;
  double startTime = omp_get_wtime();

#pragma omp parallel reduction (+:total)
  {

#pragma omp for schedule(static, (stop-start)/n) nowait
    for (int i = start; i < stop; i++){
      if (primeNumberFinder(i)){
	total = total + 1;
      }
    }

    screenLock.lock();
    double stopTime = omp_get_wtime();   

    std::cout <<"Time for "<< omp_get_thread_num() << ": " << stopTime - startTime << " with " << total << " found\n";

    screenLock.unlock();
  }
    std:: cout << "total: " << total << "\n";

}

void striping (int n, int start, int stop){

  
  omp_set_num_threads(n);

  int total = 0;
  double startTime = omp_get_wtime();

#pragma omp parallel reduction(+:total)
  {
   
#pragma omp for schedule(static, 1) nowait
    for (int i = start; i < stop; i++){
      if (primeNumberFinder(i)){
	total = total + 1;
      }
    }

    screenLock.lock();

    double stopTime = omp_get_wtime();
    std::cout <<"Time for "<< omp_get_thread_num() << ": " << stopTime - startTime << " with " << total << " found\n";

    screenLock.unlock();
  }
    std:: cout << "total: " << total << "\n";
}

int main(){

  blocking(5, 1000, 1000000);
  striping (5,1000, 1000000);

}

