#include <iostream>
#include <iomanip>
#include <chrono>
#include <CkSpider.h>
#include "modulo.hpp"

void requestCrwaler(int n, std::string url){

    int i = 0;
    double countTime = 0.0;
    //auto start, end;
    CkSpider spider;
    
    //  The spider object crawls a single web site at a time.  As you'll see
    //  in later examples, you can collect outbound links and use them to
    //  crawl the web.  For now, we'll simply spider 10 pages of chilkatsoft.com
    spider.Initialize(url.c_str());

    //  Add the 1st URL:
    spider.AddUnspidered(url.c_str());

    //  Begin crawling the site by calling CrawlNext repeatedly.
   
    for (i = 0; i < n; i++) {

        // Start time for request URL
        auto start = std::chrono::high_resolution_clock::now(); 
        
        bool success;
        success = spider.CrawlNext();
        if (success == true) {
            //  Show the URL of the page just spidered.
            std::cout << i+1 << " - Title: {" << spider.lastHtmlTitle()<< "}, URL: {" << spider.lastUrl()  << "}" << std::endl;
            //  The HTML is available in the LastHtml property
        }
        else {
            //  Did we get an error or are there no more URLs to crawl?
            if (spider.get_NumUnspidered() == 0) {
                std::cout << "No more URLs to spider" << std::endl;
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
