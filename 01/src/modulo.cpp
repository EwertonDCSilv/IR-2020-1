#include <iostream>
#include <iomanip>
#include <chrono>
#include <CkSpider.h>
#include "modulo.hpp"

void requestCrwaler(int n, std::string url){

    int i = 0;
    double countTime = 0.0;
    CkSpider spider;
    
    // Object spider for crawls pages
    spider.Initialize(url.c_str());

    //  Begin crawling the site by calling CrawlNext repeatedly.
    for (i = 0; i < n + 1 ; i++) {

        // Start time for request URL
        auto start = std::chrono::high_resolution_clock::now(); 
        
        bool success;
        success = spider.CrawlNext();
        if (success == true) {
            std::cout << i+1 << " - Title: {" << spider.lastHtmlTitle()<< "}, URL: {" << spider.lastUrl()  << "}" << std::endl;
        }
        else {
            //  Did we get an error or are there no more URLs to crawl?
            if (spider.get_NumUnspidered() == 0) {
                std::cout << "No more URLs to spider" << std::endl;
                break;
            }
            else {
                std::cout << spider.lastErrorText() <<  std::endl;
            }
        }

        // End time for request URL
        auto end = std::chrono::high_resolution_clock::now(); 
        countTime = countTime + (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) * 1e-9;

        //  Sleep 1 second before spidering the next URL.
        spider.SleepMs(1000);
    }

    // Mean time for request
    std::cout << "Mean time: " << countTime/double(n) << std::setprecision(4) <<  " seconds per page" << std::endl;
}
