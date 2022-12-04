#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

bool is_within(int x, int y, int z) {
    return y <= x && x <= z;
}

int main() {
    std::ifstream input("input.txt");
    std::string temp;

    int count = 0;
    while(std::getline(input, temp)) {
        std::stringstream ss_temp(temp);
        std::getline(ss_temp, temp, '-');
        int r1_begin = std::stoi(temp);

        std::getline(ss_temp, temp, ',');
        int r1_end = std::stoi(temp);

        std::getline(ss_temp, temp, '-');
        int r2_begin = std::stoi(temp);

        std::getline(ss_temp, temp, '-');
        int r2_end = std::stoi(temp);

        if ((r1_begin <= r2_begin && r1_end >= r2_end) || (r2_begin <= r1_begin && r2_end >= r1_end)) {
            count++;
        }
        else if (is_within(r1_begin, r2_begin, r2_end) || is_within(r1_end, r2_begin, r2_end) ||
                 is_within(r2_begin, r1_begin, r1_end) || is_within(r2_end, r1_begin, r1_end)) {
            count++;
        }
    }

    std::cout << count;
    
    return 0;
}
