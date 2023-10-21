#include <iostream>
#include <string>
#include <vector>

std::string shift(const std::string& s, const std::string& key);

int main() {
    std::string text;
    std::string key;
    std::cout << "Enter your text:\n";
    std::getline(std::cin, text);
    std::cout << "Enter the key:\n";
    std::getline(std::cin, key);
    std::cout << "You text has been encrypt: " << shift(text, key)  << std::endl;
    return 0;
}

std::vector<int> getArrayIndexes(const std::string& word) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::vector<int> arrayIndexes;
    for (char charInAlphabet : alphabet) {
        for (int i = 0; i < word.length(); i++) {
            if (charInAlphabet == word[i]) {
                arrayIndexes.push_back(i);
                break;
            }
        }
    }
    return arrayIndexes;
}

inline std::string shift(const std::string& s, const std::string& key) {
    std::string line = s;
    line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
    std::vector<std::vector<char>> matrix;
    int index = 0;
    for (int i = 0; i < (line.length() + key.length() - 1) / key.length(); i++) {
        matrix.push_back(std::vector<char>());
        while (index - i * key.length() < key.length()) {
            if (index < line.length()) {
                matrix[i].push_back(line[index]);
            }
            index++;
        }
    }

    std::vector<int> indexes = getArrayIndexes(key);
    std::string result = "";

    for (int column : indexes) {
        for (int i = 0; i < matrix.size(); i++) {
            if (column < matrix[i].size()) {
                result += matrix[i][column];
            }
        }
    }
    return result;
}