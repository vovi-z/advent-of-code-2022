#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main() {

    std::ifstream input("input.txt");
    std::vector<std::vector<int>> all_calories = {};
    std::vector<int> backpack_calories = {};
    std::string temp = "";

    while(std::getline(input, temp)) {
        if (temp.size() == 0) {
            all_calories.push_back(backpack_calories);
            backpack_calories = {};
        }
        else {
            backpack_calories.push_back(std::stoi(temp));
        }
    }

    std::vector<int> sum_calories = {};
    for (std::vector<int> elf_calorie : all_calories) {
        int sum = 0;
        for (int cal : elf_calorie) {
            sum += cal;
        }
        sum_calories.push_back(sum);
    }

    // std::cout << *std::max_element(sum_calories.begin(), sum_calories.end());

    std::sort(sum_calories.begin(), sum_calories.end(), std::greater<int>());

    int top_three = 0;
    for (int i = 0; i < 3; i++) {
        top_three += sum_calories.at(i);
    }
    std::cout << top_three;

    return 0;
}