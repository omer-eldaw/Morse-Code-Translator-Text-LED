#include <iostream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

map<char, string> ascii_to_morse = {
    {'A',".-"},
    {'B',"-..."},
    {'C',"-.-."},
    {'D',"-.."},
    {'E',"."},
    {'F',"..-."},
    {'G',"--."},
    {'H',"...."},
    {'I',".."},
    {'J',".---"},
    {'K',"-.-"},
    {'L',".-.."},
    {'M',"--"},
    {'N',"-."},
    {'O',"---"},
    {'P',".--."},
    {'Q',"--.-"},
    {'R',".-."},
    {'S',"..."},
    {'T',"-"},
    {'U',"..-"},
    {'V',"...-"},
    {'W',".--"},
    {'X',"-..-"},
    {'Y',"-.--"},
    {'Z',"--.."},
    {'0',"-----"},
    {'1',".----"},
    {'2',"..---"},
    {'3',"...--"},
    {'4',"....-"},
    {'5',"....."},
    {'6',"-...."},
    {'7',"--..."},
    {'8',"---.."},
    {'9',"----."},
    {' ', " "},
};

map<string, char> morse_to_ascii;


char change_case (char c) {
    if (islower(c)) {
        return toupper(c);
    }
    else {
        return toupper(c);
    };
};

void Clear()
{
    cout << "\x1B[2J\x1B[H";
};


// int TextToLED(string Text) {


//     return 0;
// };


int main() {

    for (auto x : ascii_to_morse) {
        morse_to_ascii[x.second] = x.first;
    }

    string text_input;
    string option_selected_1;
    char option_selected_2;
    string morse_pulse;
    

    while (true) {

        Clear();

        cout << "Welcome to the Morse Code Translator\n\n\nSelect an option to:\n\n\n1 - Translate from MORSE to OUTPUT\n2 - Translate from OUTPUT to MORSE\n\n";

        getline(cin, option_selected_1);

        while(option_selected_1 == "1") {
            Clear();

            cout << "Input the text you want to translate from MORSE to OUTPUT\n\n\n";

            getline(cin, text_input);

            transform(text_input.begin(), text_input.end(), text_input.begin(), change_case);

            vector<char> seperated_char(text_input.begin(), text_input.end());
            

            for (int i =0; i < seperated_char.size(); i++) {

                string temp_pulse = ascii_to_morse.at(seperated_char[i]);

                if (temp_pulse == " ") {
                    morse_pulse.pop_back();
                    morse_pulse += "|";
                }

                else {
                    morse_pulse += (temp_pulse + " " );
                };
            }

            cout << "\n\nThe corresponding MORSE signal that will be sent will be: " << morse_pulse << "\n\nPlease confirm with Y/N\n\n" << endl;

            cin >> option_selected_2;

            if (toupper(option_selected_2) == 'Y') {
                cout << "\nMORSE signal has been sent successfully" << endl;
                
            } 

            else if (toupper(option_selected_2) == 'N') {
                break;
            };

            


        };
    };

    return 0;
}

