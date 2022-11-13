#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cerr << "A file name must be provided.\n";
        exit(1);
    }

    if (argc > 2)
        std::cerr << "Only 1 file name can be accepted.";

    std::ifstream file(/* file name */ argv[1]);

    std::map<std::string, int> counter;

    while (!file.eof()) {
        std::string word;
        file >> word;

        std::transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) { return std::tolower(c); });

        // что за магия я сам не понял
        word.erase(std::remove_if(word.begin(), word.end(),
                       [](unsigned char c) { return std::ispunct(c); }),
            word.end());

        if (!word.empty())
            counter[word]++;
    }

    for (auto pair : counter) {
        std::cout << "Word \"" << pair.first << "\" found " << pair.second << " time";

        if (pair.second > 1)
            std::cout << 's';

        std::cout << std::endl;
    }

    return 0;
}
