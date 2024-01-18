#include <iostream>
#include <fstream>

using namespace std;

const string words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string numbers[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main(void) {
    ifstream file;
    file.open("input.txt");
    string str;
    int first = 0, last = 0;
    int total1 = 0, total2 = 0;
    string::size_type minpos, maxpos, pos;

    // Part 1
    while(getline(file, str)) {
        first = 0;
        last = 0;
        for (auto ch : str) {
            if (isdigit(ch)) {
                if (first == 0) {
                    first = ch - '0';
                }

                last = ch - '0';
            }
        }

        total1 += first * 10 + last;
    }

    file.close();

    file.open("input.txt");

    first = 0;
    last = 0;

    // Part 2
    while (getline(file, str)) {
        minpos = 1000;
        maxpos = 0;
        for (int i = 0; i < 9; i++) {
            pos = str.find(words[i], 0);

            while (pos != string::npos) {
                if (pos < minpos) {
                    first = i+1;
                    minpos = pos;
                }

                if (pos >= maxpos) {
                    last = i+1;
                    maxpos = pos;
                }

                pos = str.find(words[i], pos+1);
            }
        }

        for (int i = 0; i < 9; i++) {
            pos = str.find(numbers[i], 0);

            while (pos != string::npos) {
                if (pos < minpos) {
                    first = i+1;
                    minpos = pos;
                }

                if (pos >= maxpos) {
                    last = i+1;
                    maxpos = pos;
                }

                pos = str.find(numbers[i], pos+1);
            }
        }

        total2 += first * 10 + last;
    }

    cout << "Part 1 answer is: " << total1 << endl;
    cout << "Part 2 answer is: " << total2 << endl;

    file.close();

    return 0;
}