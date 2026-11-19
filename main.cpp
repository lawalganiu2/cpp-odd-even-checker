#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter an integer (or 'q' to quit): ";

        // Read a token as text first so the user can also enter 'q'.
        if (!(std::cin >> input)) {
            // End the program cleanly if there is no more input.
            std::cout << "\nGoodbye!\n";
            break;
        }

        if (input == "q" || input == "Q") {
            std::cout << "Goodbye!\n";
            break;
        }

        // Parse the whole token as an integer, rejecting values like "7abc".
        std::istringstream inputParser(input);
        long long number;
        char extraCharacter;

        if ((inputParser >> number) && !(inputParser >> extraCharacter)) {
            // A remainder of zero means the number is evenly divisible by 2.
            if (number % 2 == 0) {
                std::cout << number << " is Even.\n";
            } else {
                std::cout << number << " is Odd.\n";
            }
        } else {
            std::cout << "Error: please enter a whole integer, or 'q' to quit.\n";

            // Clear any stream error and discard the rest of the current line
            // before prompting again. This also handles extra text after a token.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
