#include <iostream>
#include "BMP.h"
#include "Table.h"
#include <random>
#include <thread>
#include <chrono>


int main() {

    Table table(48, 27);

    auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());


    BMP image(1920, 1080);
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    while (true) {
        if (table.liveCellCnt < 150) {
            for (int y = 0; y < 27; y++) {
                for (int x = 0; x < 48; ++x) {
                    table.table[y][x] = gen();
                }
            }
        }
        for (int y = 0; y < 27; y++) {
            for (int x = 0; x < 48; ++x) {
                if (table.table[y][x])
                    image.fill_region(x * 40, y * 40, 40, 40, 0, 0, 255, 255);
                else
                    image.fill_region(x * 40, y * 40, 40, 40, 0, 0, 0, 255);
            }
        }
        image.write("test.bmp");
        system(" gsettings set org.mate.background picture-filename /home/sarosi/CLionProjects/life_on_paper/cmake-build-debug/test.bmp");
        table.nextgen();
        std::cout << table.liveCellCnt << std::endl;
        sleep_for(nanoseconds(500000000));  // sleep_until(system_clock::now() + seconds(1));

    }

    return 0;
}



