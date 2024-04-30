#include <iostream>
#include <string>
#include <unordered_map>



void TuringMachine(const std::string& input) {
    std::string tape = std::string(3, '_') + input + std::string(input.size() + 1, '_') + std::string(3, '_');
    std::unordered_map<std::string, std::vector<char>> transitions = {
            {"A0", {'0', 'R', 'A'}}, // A - set *
            {"A1", {'1', 'R', 'A'}},
            {"A_", {'*', 'L', 'T'}},
            {"T_", {'_', 'H', 'C'}}, // T - end if zero input else forward to F or D
            {"T0", {'#', 'R', 'F'}},
            {"T1", {'#', 'R', 'D'}},
            {"F*", {'*', 'R', 'F'}}, // F - 0 forwarding
            {"F0", {'0', 'R', 'F'}},
            {"F1", {'1', 'R', 'F'}},
            {"F_", {'0', 'H', 'R'}},
            {"D*", {'*', 'R', 'D'}}, // D - 1 forwarding
            {"D0", {'0', 'R', 'D'}},
            {"D1", {'1', 'R', 'D'}},
            {"D_", {'1', 'H', 'K'}},
            {"R*", {'*', 'L', 'R'}}, // R - return 0 on last position
            {"R0", {'0', 'L', 'R'}},
            {"R1", {'1', 'L', 'R'}},
            {"R#", {'0', 'L', 'T'}},
            {"K*", {'*', 'L', 'K'}}, // R - return 1 on last position
            {"K0", {'0', 'L', 'K'}},
            {"K1", {'1', 'L', 'K'}},
            {"K#", {'1', 'L', 'T'}}
        };

    char state = 'A';
    size_t idx = 3;

    while (state != 'C' && idx < tape.size()) {
        char currentSymbol = tape[idx];
        auto transition_key = std::string() + state + currentSymbol;
        auto transition = transitions.at(transition_key);
        tape[idx] = transition[0];
        char move = transition[1];
        state = transition[2];

        if (move == 'R') {
            idx++;
        } else if (move == 'L') {
            idx--;
        }
    }
    std::cout << "Result: " << tape << std::endl;
}



int main() {
    std::string input = "1000101";
    try {
        TuringMachine(input);
    } catch (const std::exception& ex) {
        std::cout << "Excepetion: " << ex.what() << std::endl;
    }

    return 0;
}
