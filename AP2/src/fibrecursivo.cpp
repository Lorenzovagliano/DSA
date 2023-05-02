#include <iostream>
#include <chrono>
#include <time.h>
#include <cmath>
#include <sys/resource.h>

using namespace std;
using namespace std::chrono;

int fibrecursivo(int n){
    if(n < 3){
        return 1;
    }
    else{
        return fibrecursivo(n-1) + fibrecursivo(n-2);
    }
}

int main(int argc, char* argv[]) {
    int n = 5;
    if (argc > 1) {
        n = std::atoi(argv[1]);
    }

    struct timespec realBegin, realEnd, userBegin, userEnd, sysBegin, sysEnd; 
    clock_gettime(CLOCK_REALTIME, &realBegin);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userBegin);
    clock_gettime(CLOCK_BOOTTIME, &sysBegin);

    int result = fibrecursivo(n);

    clock_gettime(CLOCK_REALTIME, &realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userEnd);
    clock_gettime(CLOCK_BOOTTIME, &sysEnd);

    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    long nanoseconds = realEnd.tv_nsec - realBegin.tv_nsec;
    std::cout << "real: " << nanoseconds << "ns" << std::endl;

    nanoseconds = userEnd.tv_nsec - userBegin.tv_nsec;
    std::cout << "user: " << nanoseconds << "ns" << std::endl;

    nanoseconds = sysEnd.tv_nsec - sysBegin.tv_nsec;
    std::cout << "sys: " << nanoseconds << "ns" << std::endl;

    return 0;
}