#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
//#include "../spdlog/include/spdlog/spdlog.h"

#include <iostream>
#include "Date.h"
//#include "AppZoo.h"

int main() {
    Date d;

    std::cout << d.toString() << '\n';
    return 0;

    //spdlog::info("Welcome to spdlog!");

    /*int status = -1;
    try {
        // ��������, 
       auto appLogLevel = spdlog::level::trace;
       // AppZoo app("logs/applog.txt", appLogLevel);
        AppZoo app(appLogLevel);
        status = app.run();
    }
    catch (const spdlog::spdlog_ex& ex)
    {

        std::cerr << "Log init failed: " << ex.what() << std::endl;
    }

    return status;*/
}



