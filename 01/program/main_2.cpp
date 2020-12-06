#include <iostream>
#include "modulo.hpp"

int main(int argc, char* argv[]){

    int n = 0;
    std::string url;
    std::string aux;

    // Warning implementation
    std::cout << "Testando ..." << std::endl;
    
    // Get input
    std::getline(std::cin, aux);
    n = std::stoi( aux );
    std::getline(std::cin, url);

    // Call function for crawling
    teste(n, url);

    return 0;
}