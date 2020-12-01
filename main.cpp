#include <iostream>
#include <vector>
#include <utility>

int main() {
    int size;
    std::cin >> size;
    std::vector<int> sequence(size);
    int count1 = 0, count2 = 0;

    for (int i = 0; i < size; i++) {
        std::cin >> sequence[i];
        if (sequence[i] == 1) {
            count1++;
        } else if (sequence[i] == 2) {
            count2++;
        }
    }

    int cntSwap = 0;

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

    std::cout << cntSwap << "\n";

    return 0;
}