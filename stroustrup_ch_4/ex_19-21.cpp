#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

bool isNumber(const std::string& str);

class ScoreBoard
{
    std::vector<std::string> names;
    std::vector<int> scores;
public:
    ScoreBoard() = default;

    inline const std::vector<std::string>& Names() const { return names; }
    inline const std::vector<int>& Scores() const { return scores; }
    void addName(const std::string& name);
    void addScore(int score);

    void validate();

    int findByName(const std::string& name) const;
    std::vector<std::string> findByScore(const int score) const;
};

int main()
{
    ScoreBoard board;

    std::cout << "Enter list: ";

    std::string nameScorePairs;
    std::getline(std::cin, nameScorePairs);
    std::stringstream ss(nameScorePairs);
    std::string name;
    int score;

    while (ss >> name >> score)
    {
        board.addName(name);
        board.addScore(score);
    }

    board.validate();

    for (int i = 0; i < board.Scores().size(); ++i)
    {
        std::cout << board.Names().at(i) << ' ' << board.Scores().at(i) << std::endl;
    }

    while (true)
    {
        std::cout << "Name or score: ";
        std::string nameOrScore; 
        std::cin >> nameOrScore;

        try
        {
            if (isNumber(nameOrScore))
            {
                std::vector<std::string> names =
                    board.findByScore(std::stoi(nameOrScore));

                std::string separator = "";
                for (auto name : names)
                {
                    std::cout << separator << name;
                    separator = ", ";
                }
                std::cout << std::endl;
            }
            else
                std::cout << board.findByName(nameOrScore) << std::endl;
        }
        catch (std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }
    }

    return 0;
}

void ScoreBoard::addName(const std::string &name)
{
    names.push_back(name);
}

void ScoreBoard::addScore(int score)
{
    scores.push_back(score);
}

void ScoreBoard::validate()
{
    std::map<std::string, int> nameCounts;

    for (std::string& name : names)
    {
        auto [it, success] = nameCounts.insert({ name, 1 });
        if (!success)
            it->second++;
    }

    bool foundDupe = false;
    for (auto [name, count] : nameCounts)
    {
        if (count > 1)
        {
            std::cout << name << " entered " << count << " times" << std::endl;
            foundDupe = true;
        }
    }

    if (foundDupe)
    {
        std::cout << "All the names must be unique" << std::endl;
        exit(1);
    }
}

int ScoreBoard::findByName(const std::string& name) const
{
    auto it = std::find(names.begin(), names.end(), name);

    if (it == names.end())
    {
        throw std::runtime_error("name not found");
    }

    return scores.at(it - names.begin());
}

std::vector<std::string> ScoreBoard::findByScore(const int score) const
{
    std::vector<std::string> matches;

    for (int i = 0; i < scores.size(); ++i)
    {
        if (score == scores[i])
            matches.push_back(names[i]);
    }

    if (!matches.size())
    {
        throw std::runtime_error("score not found");
    }

    return matches;
}

bool isNumber(const std::string& str)
{
    std::string::const_iterator it = str.begin();

    while (it != str.end() && std::isdigit(*it))
        ++it;

    return !str.empty() && it == str.end();
}
