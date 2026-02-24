#include "ui_utils.hpp"

#include <charconv>
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

namespace uiutils {

bool promptYesNo(const std::string &prompt) {
    if(prompt == "y")
    {
        return true;
    } else
    {
        return false;
    }

    std::cout << "Neplatny vstup zadaj znovu: y/n" << std::endl;
    std::string newPrompt = nullptr;

    std::cin >> newPrompt;

    return promptYesNo(newPrompt);
}

int chooseOption(const std::string& prompt,
                 const std::vector<std::string>& options) {
    std::cout << prompt << std::endl;
    for (size_t idx = 0; idx < options.size(); ++idx) {
        std::cout << idx << ". " << options[idx] << std::endl;
    }

    int i = -1;
    for (;;) {
        std::cout << "Zadaj moznost: ";
        if (!(std::cin >> i)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // prompt again
        }
        if (i >= 0 && i < static_cast<int>(options.size())) {
            std::cout << "\n";
            return i;
        }
        std::cout << "Neplatna moznost, skus znova.\n";
    }
}


std::optional<int> chooseOptionOpt(
    const std::string &prompt,
    const std::vector<std::string> &options,
    int maxTries
) {
    std::cout << prompt << std::endl;
    for(int i = 0; i < options.size(); i++)
    {
        std::cout << i << "." << options.at(i) << std::endl;
    }
    

     int i = -1;
     bool is_valid = false;


    for(int pocetMoznosti = 0; pocetMoznosti < maxTries; pocetMoznosti++)
    {
        std::cout << "Zadaj možnosť: ";
        std::cin >> i;
        if(i >= 0 || i < options.size())
        {
            std::cout << "\n";
            is_valid = true;
            break;
        }
    }

    std::cout << "\n";

    if(is_valid)
    {
        return i;
    }
    return std::nullopt;


}

int readInt(const std::string &prompt) {
    while (true) {
        std::string s = readString(prompt);
        if (auto result = parseInt(s)) {
            std::cout << "\n";
            return *result;
        }
        std::cout << "Neplatny vstup" << std::endl;
    }
}

std::optional<int> readIntOpt(const std::string &prompt, int maxTries) {
    std::optional<int> result = std::nullopt;

    do
    {
        std::string s = readString(prompt);
        result = parseInt(s);
        --maxTries;
    } while (!result.has_value() && maxTries >0 );

    std::cout << "\n";
    return result;
    
}

std::string readString(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return input;
}

std::optional<int> parseInt(const std::string &s) {
    int result;

    const char *first = s.data();
    const char *last = s.data() + s.size();
    const std::from_chars_result fcResult
        = std::from_chars(first, last, result);

    return fcResult.ec == std::errc() && fcResult.ptr == last
             ? std::optional<int>(result)
             : std::nullopt;
}

} // namespace uiutils
