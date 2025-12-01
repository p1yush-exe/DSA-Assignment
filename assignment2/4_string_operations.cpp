#include <iostream>
#include <string>

// 4(a) Concatenate one string to another
std::string concatenate_strings(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

// 4(b) Reverse a string (in-place style)
std::string reverse_string(std::string s) {
    int left = 0;
    int right = static_cast<int>(s.length()) - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        ++left;
        --right;
    }
    return s;
}

// 4(c) Delete all vowels from the string
std::string delete_vowels(const std::string& s) {
    std::string vowels = "aeiouAEIOU";
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        bool is_vowel = false;
        for (size_t j = 0; j < vowels.length(); ++j) {
            if (s[i] == vowels[j]) {
                is_vowel = true;
                break;
            }
        }
        if (!is_vowel) {
            result += s[i];
        }
    }
    return result;
}

// 4(d) Sort the characters of a string in alphabetical order (simple bubble sort)
std::string sort_string_chars(std::string s) {
    int n = static_cast<int>(s.length());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    return s;
}

// 4(e) Convert a character from uppercase to lowercase
char to_lower_char(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // ASCII difference between 'a' and 'A'
    }
    return ch;
}

int main() {
    std::string s1, s2;

    std::cout << "Enter first string: ";
    std::getline(std::cin, s1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, s2);

    std::cout << "\n(a) Concatenate: " << concatenate_strings(s1, s2) << "\n";

    std::cout << "(b) Reverse first string: " << reverse_string(s1) << "\n";

    std::string sentence;
    std::cout << "\nEnter a string to delete vowels from: ";
    std::getline(std::cin, sentence);
    std::cout << "(c) Without vowels: " << delete_vowels(sentence) << "\n";

    std::string to_sort;
    std::cout << "\nEnter a string to sort its characters: ";
    std::getline(std::cin, to_sort);
    std::cout << "(d) Sorted characters: " << sort_string_chars(to_sort) << "\n";

    char ch;
    std::cout << "\nEnter a character (uppercase) to convert to lowercase: ";
    std::cin >> ch;
    std::cout << "(e) Lowercase: " << to_lower_char(ch) << "\n";

    return 0;
}
