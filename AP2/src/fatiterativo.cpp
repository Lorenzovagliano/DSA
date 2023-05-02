#include <iostream>
#include <chrono>
#include <time.h>
#include <cmath>

using namespace std;
using namespace std::chrono;

int fatiterativo(int n){
    int f = 1;
    while(n > 0){
        f = f * n;
        n = n - 1;
    }
    return f;
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

    int result = fatiterativo(n);

    clock_gettime(CLOCK_REALTIME, &realEnd);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &userEnd);
    clock_gettime(CLOCK_BOOTTIME, &sysEnd);

    std::cout << "Fatorial(" << n << ") = " << result << std::endl;

    long nanoseconds = realEnd.tv_nsec - realBegin.tv_nsec;
    std::cout << "real: " << nanoseconds << "ns" << std::endl;

    nanoseconds = userEnd.tv_nsec - userBegin.tv_nsec;
    std::cout << "user: " << nanoseconds << "ns" << std::endl;

    nanoseconds = sysEnd.tv_nsec - sysBegin.tv_nsec;
    std::cout << "sys: " << nanoseconds << "ns" << std::endl;

    return 0;
}