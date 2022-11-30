#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <vector>

constexpr int numberSize = 4;

std::vector<int> generate();
void validateInput(std::vector<int> answer);

int main()
{
    std::vector<int> sequence = generate();

    while (true)
    {
        std::string answerString;

        std::cout << "Your guess: ";
        std::cin >> answerString;
        std::cout << std::endl;

        std::vector<int> answer;
        for (int i = 0; i < answerString.size(); ++i)
        {
            answer.push_back(answerString[i] - '0');
        }

        try { validateInput(answer); }
        catch(std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            continue;
        }

        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < numberSize; ++i)
        {
            if (sequence[i] == answer[i])
                ++bulls;
            
            for (int j = i + 1; j < numberSize; ++j)
            {
                if (answer[i] == sequence[j])
                    ++cows;
            }
        }

        if (bulls == numberSize)
        {
            break;
        }
        else
        {
            std::cout << "Bulls: " << bulls << "\n" << "Cows: " << cows << std::endl;
        }
    }

    return 0;
}

std::vector<int> generate()
{
    std::vector<int> numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::random_shuffle(begin(numbers), end(numbers));
    std::vector<int> result;

    for (int i = 0; i < numberSize; ++i)
        result.push_back(numbers[i]);

    return result;
}

void validateInput(std::vector<int> answer)
{
    if (answer.size() != numberSize)
        throw std::runtime_error("The number consists of 4 digits. Try again.");

    
    std::sort(answer.begin(), answer.end());

    for (int i = 0; i < (numberSize - 1); ++i)
    {
        if (answer[i] == answer[i + 1])
            throw std::runtime_error("All digits must be distinct. Try again.");
    }
}
