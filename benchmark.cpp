// #include <fstream>
// #include <iostream>
// #include <string>
// #include <chrono>

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         return 1;
//     }
//     std::ifstream in(argv[1]);
//     if (!in.is_open()) {
//         std::cout << "File doesn't open\n";
//         return 1;
//     }
//     std::string input_string;
//     in >> input_string;

//     std::chrono::time_point<std::chrono::system_clock> start, end;
//     start = std::chrono::system_clock::now();
//     get_count_unique_sub_palindrome(input_string);
//     end = std::chrono::system_clock::now();

    // int time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    // std::cout << "STRING SIZE: " << input_string.size() << "\n";
    // std::cout << "TIME: " << time << "\n";
//     in.close();
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <utility>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cout << "File doesn't open\n";
        return 1;
    }
    std::string input_string;
    in >> input_string;
    int size = std::atoi(input_string.c_str());
    input_string.clear();

    std::vector<int> sequence(size);
    int count1 = 0, count2 = 0;

    std::string temp;
    for (int i = 0; i < size; i++) {
        in >> temp;
        sequence[i] = std::atoi(temp.c_str());
        if (sequence[i] == 1) {
            count1++;
        } else if (sequence[i] == 2) {
            count2++;
        }
    }

    int cntSwap = 0;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < count1 + count2; i++) {
        if (i < count1) {
            if (sequence[i] == 2) {
                for (int j = count1; j < size; j++) {
                    if (sequence[j] == 1) {
                        std::swap(sequence[i], sequence[j]);
                        cntSwap++;
                        break;
                    }
                }
            } else if (sequence[i] == 3) {
                for (int j = size - 1; j >= count1; j--) {
                    if (sequence[j] == 1) {
                        std::swap(sequence[i], sequence[j]);
                        cntSwap++;
                        break;
                    }
                }
            }
        } else {
            if (sequence[i] == 3) {
                for (int j = count1 + count2; j < size; j++) {
                    if (sequence[j] == 2) {
                        std::swap(sequence[i], sequence[j]);
                        cntSwap++;
                        break;
                    }
                }
            }
        }
    }
    end = std::chrono::system_clock::now();
    int time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "SIZE SEQUENCE: " << size << "\n";
    std::cout << "TIME: " << time << "\n";
    std::cout << "RES: " << cntSwap << "\n";

    return 0;
}