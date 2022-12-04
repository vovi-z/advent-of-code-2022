#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>

/*
A - rock
B - paper
C - scissors

X - rock
Y - paper
Z - scissors

rock - 1
paper - 2
scissors - 3

0 if lose
3 if draw
6 if win
*/

int main() {
    std::ifstream input("input.txt");
    std::string temp;

    int res = 0;
    int res2 = 0;
    while (std::getline(input, temp)) {
        std::stringstream ss_temp(temp);
        std::string char1;
        std::string char2;
        std::getline(ss_temp, char1, ' ');
        std::getline(ss_temp, char2, ' ');

        if (char2 == "X") {
            res += 1;
            if (char1 == "A") {
                res += 3;
            }
            else if (char1 == "C") {
                res += 6;
            }
        }
        else if (char2 == "Y") {
            res += 2;
            if (char1 == "B") {
                res += 3;
            }
            else if (char1 == "A") {
                res += 6;
            }
        }
        else {
            res += 3;
            if (char1 == "C") {
                res += 3;
            }
            else if (char1 == "B") {
                res += 6;
            }
        }

        // X => lose
        // Y => draw
        // Z => win


        if (char2 == "X") {
            if (char1 == "A") {
                res2 += 3;
            }
            else if (char1 == "B") {
                res2 += 1;
            }
            else {
                res2 += 2;
            }
        }
        else if (char2 == "Y") {
            res2 += 3;
            if (char1 == "A") {
                res2 += 1;
            }
            else if (char1 == "B") {
                res2 += 2;
            }
            else {
                res2 += 3;
            }
        }
        else {
            res2 += 6;
            if (char1 == "A") {
                res2 += 2;
            }
            else if (char1 == "B") {
                res2 += 3;
            }
            else {
                res2 += 1;
            }
        }

    }

    std::cout << res << '\n';
    std::cout << res2;


    return 0;
}
