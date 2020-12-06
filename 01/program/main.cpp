#include <iostream>
#include "modulo.hpp"
#include <CkSpider.h>

int main(int argc, char* argv[]){

    int n = 0;
    std::string url;
    std::string aux;
    
    // Get input
    std::getline(std::cin, aux);
    n = std::stoi( aux );
    std::getline(std::cin, url);

    // Call function for crawling
    requestCrwaler(n, url);

    return 0;
}