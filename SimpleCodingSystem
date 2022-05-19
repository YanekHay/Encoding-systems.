#include <iostream>
#include <string>
    
using namespace std;
string Code_Text(string, char[]);
string Decode_Text(string , char[]);

int main()
{
        string code_text;
        cout << "Input Code text" << endl; getline(cin, code_text); cout << endl;
        
        ///Making The text small lettered
    for (int i = 0; i < code_text.length(); i++) {
        if (int(code_text[i]) >= 65 && int(code_text[i]) <= 90) {
            code_text[i] = char(int(code_text[i]) + 32);
        }
    } 

    //   Creating an empty array for letters 
    bool coded_arr_bool[26];
    char code_array[26];
    int code_step = 0;
    for (int i = 0; i < sizeof(coded_arr_bool) / sizeof(*coded_arr_bool); i++) coded_arr_bool[i] = false;

    // Checking and filling all the existing letters
    for (int i = 0; i < code_text.length(); i++) {
        if (int(code_text[i]) == 32) { continue; }
        char letter = code_text[i];

        for (int j = 0; j < code_text.length(); j++) {
            if (code_text[i] == letter && coded_arr_bool[int(code_text[i]) - 97] == false) {
                code_array[code_step] = code_text[i];
                coded_arr_bool[int(code_text[i]) - 97] = true;
                code_step++;
            }
        }
    }

    // Adding missing letters at the end
    for (int i = 0; i < sizeof(coded_arr_bool) / sizeof(*coded_arr_bool); i++) {
        if (coded_arr_bool[i] == false) {
            code_array[code_step] = char(97 + i);
            code_step++;
        }

    }
    // Print the alphabet and the code
       /*for (int i = 0; i < sizeof(code_array) / sizeof(*code_array); i++) {
           cout << coded_arr_bool[i] << "  ";
       }
       cout << endl<<endl;*/
    for (int i = 0; i < sizeof(code_array) / sizeof(*code_array); i++) {
        cout << char(97 + i) << "  ";
    }
    cout << endl;

    for (int i = 0; i < sizeof(code_array) / sizeof(*code_array); i++) {
        cout << code_array[i] << "  ";
    }
    cout << endl << endl;
// Input a new text which will be Coded
    string text_toBeCoded, test_toBeDecoded;
    cout << "Input your text for Coding" << endl; getline(cin, text_toBeCoded); cout << endl;
    cout <<"Coded text is"<< endl<< Code_Text(text_toBeCoded, code_array)<<endl;

    // Input a new text which will be Decoded
    cout << "Input your text for Decoding" << endl; getline(cin, test_toBeDecoded); cout << endl;
    cout << "Decoded text is"<< endl << Decode_Text(test_toBeDecoded, code_array);

}




string Code_Text(string text, char  code[]) {
    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 65 && int(text[i]) <= 90) {
            text[i] = char(int(text[i]) + 32);
        }
    }

    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 97 && int(text[i]) <= 122) {
            text[i] = code[int(text[i]) - 97];
        }
    }
    return text;
}


string Decode_Text(string text, char  code[]) {
    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 65 && int(text[i]) <= 90) {
            text[i] = char(int(text[i]) + 32);
        }
    }

    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 97 && int(text[i]) <= 122) {
            char l = text[i];
            for (int j = 0; j < 26; j++) {
                if (l == code[j]) {
                    text[i] = char(j + 97);
                    break;
                }
            }
            
        }
    }
    return text;
}

            

