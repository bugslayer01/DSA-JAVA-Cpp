#include <iostream>
#include <ctime>
using namespace std;

int main() {
    clock_t start = clock();  
    for (int i = 0; i <= 100000; ++i)
    cout<<i<<endl;
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;  
    std::cout << "Time taken by the program is : " << time_taken << " seconds" << std::endl;
    return 0;
}
