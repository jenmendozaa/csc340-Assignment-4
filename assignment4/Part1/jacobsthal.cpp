#include <iostream>
#include <cstdlib> 

//TODO: add your documentation here
// TO DO: implement jacobsthal
//      Hint: it should return a long long (integers)

long long jacobsthal(int n ) {
        if (n < 2) return n;
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
    }


int main(int argc, char* argv[]) {
    // Read n from command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    // Convert n to an integer
    int n = std::atoi(argv[1]);

    // Compute Jacobsthal of n
    long long result = jacobsthal(n);
    std::cout << "Jacobsthal(" << n << ") = " << result << std::endl;

    return 0;
}
