#include <iostream>
#include <string>

using namespace std;

string vigenere_cipher(string text, string key) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string encrypted_text = "";
    int key_len = key.length();
    int text_len = text.length();
    for (int i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            char lower_text_char = tolower(text[i]);
            char lower_key_char = tolower(key[i % key_len]);
            int char_index = alphabet.find(lower_text_char);
            int key_index = alphabet.find(lower_key_char);
            char encrypted_char = alphabet[(char_index + key_index) % alphabet.length()];
            if (isupper(text[i])) {
                encrypted_char = toupper(encrypted_char);
            }

            encrypted_text += encrypted_char;
        }
        else {
            encrypted_text += text[i];
        }
    }

    return encrypted_text;
}

int main() {
    string key;
    string netext;
    cout << "Key: ";
    cin >> key;
    cout << "text: ";
    cin.ignore();
    getline(cin, netext);
    string text = netext;
    string encrypted_text = vigenere_cipher(text, key);
    cout << "enc text::" << endl;
    cout << encrypted_text << endl;
    return 0;
}