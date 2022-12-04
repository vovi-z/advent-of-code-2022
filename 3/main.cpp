#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
    std::ifstream input("input.txt");
    std::vector<std::string> rucksacks = {};
    std::string temp = "";

    int res = 0;
    while (std::getline(input, temp)) {
        std::string first_half = temp.substr(0, temp.size() / 2);
        std::string second_half = temp.substr(temp.size() / 2);

        std::set<char> characters;
        for (char c : first_half) {
            characters.insert(c);
        }

        for (char c : second_half) {
            if (characters.find(c) != characters.end()) {
                int ic = (int)c;
                if (65 <= ic && ic <= 90) {
                    res += ic - 38;  
                }
                else {
                    res += ic - 96;
                }
                break;
            }
        }
    }
    input.close();

    input.open("input.txt");
    int res2 = 0;
    while (std::getline(input, temp)) {
        std::set<char> set1 = {};
        std::set<char> set2 = {};
        std::set<char> set3 = {};
        for (char c : temp) {
            set1.insert(c);
        }
        
        std::getline(input, temp);
        for (char c : temp) {
            set2.insert(c);
        }

        std::getline(input, temp);
        for (char c : temp) {
            set3.insert(c);
        }

        char ans;
        for (char c : set1) {
            if (set2.find(c) != set2.end() && set3.find(c) != set3.end()) {
                ans = c;
                break;
            }
        }

        int ic = (int)ans;
        if (65 <= ic && ic <= 90) {
            res2 += ic - 38;
        }
        else {
            res2 += ic - 96;
        }
    }

    std::cout << res << '\n';
    std::cout << res2;

    return 0;
}
