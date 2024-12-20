#include <iostream>
#include <cstdlib> 
#include <map> 

using namespace std;

//TODO: add your documentation here
// TO DO: implement jacobsthal
//      Hint: it should return a long long (integers)
//            it should take a cache (map or vector) of long longs as well


long long jacobsthal(int n, map<int, long long>& memo) {
    if (n < 2) return n;


    // checking if the value is already computed
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    long long result = jacobsthal(n - 1, memo) + 2 * jacobsthal(n - 2, memo);

    memo[n] = result;

    return result;
}

int main(int argc, char* argv[]) {
    // Read n from command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1; 
    }

    // Convert n to an integer
    int n = std::atoi(argv[1]); 

    // Jacobsthal numbers cache (could use vector, too)
    std::map<int, long long> memo;

    // Compute Jacobsthal of n
    long long j_n = jacobsthal(n, memo); 
    std::cout << "Jacobsthal(" << n << ") = " << j_n << std::endl;

    return 0; 
}
