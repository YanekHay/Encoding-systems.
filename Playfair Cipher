#include <iostream>
#include <string>
    
using namespace std;
string RemoveExtra(string);
string Code_Text(string, char[5][5]);
string Decode_Text(string , char[5][5]);
string RemoveRepetitions(string);
string to_lower(string);
char to_lower(char);
string replace_with(string, char, char);
int main()
{
    string code_text;

    cout << "Input Code text" << endl; getline(cin, code_text); cout << endl;

    /// Asking about letter "J" to the user
    string action_j;
    char replacing_letter;
    do {
        cout << "If you want to delete the letter 'J' then type 'delete'" << endl << "For replacing it with the letter, type the letter you want to replace with" << endl;
        cin >> action_j;

    } while ((action_j.length() != 1) && (action_j != "delete") || (to_lower(action_j)=="j"));
    replacing_letter = (action_j.length() == 1) ? to_lower(action_j)[0] : ' ';
    code_text = RemoveExtra(replace_with(to_lower(code_text), 'j', replacing_letter));
    
    //   Creating an empty array for letters 
    bool coded_arr_bool[26];
    char code_array[5][5];
    int  row=0, col=0;
    for (int i = 0; i < sizeof(coded_arr_bool) / sizeof(*coded_arr_bool); i++) coded_arr_bool[i] = false;

    // Checking and filling all the existing letters
    for (int i = 0; i < code_text.length(); i++) {
        if (int(code_text[i]) == 32) { continue; }
        char letter = code_text[i];
        
                if (code_text[i] == letter && coded_arr_bool[int(code_text[i]) - 97] == false) {
                    code_array[row][col] = code_text[i];
                    coded_arr_bool[int(code_text[i]) - 97] = true;                    
                    col++;
                    if (col == 5) {
                        col = 0;
                        row++;
                    }
                }
    }    

         
    // Adding missing letters at the end
    for (int i = 0; i < sizeof(coded_arr_bool) / sizeof(*coded_arr_bool); i++) {
            if (coded_arr_bool[i] == false && i != 9 ) {
                code_array[row][col] = char(97 + i);
                col++;
                if (col == 5) {
                    col = 0;
                    row++;
                }
            }

        }
    /// Prints the Key
    for (int j = 0; j < 5; j++) {
            cout << endl;
            for (int k = 0; k < 5; k++) {
                cout << code_array[j][k];
            }
        }
    cout << endl;
   
        
        
        
        // Input a new text which will be Coded and decoded
        string text_toBeCoded, text_toBeDecoded;

        while(text_toBeCoded.length()<2){
        cout << "Input your text for Coding" << endl; cin.ignore(); getline(cin, text_toBeCoded); cout << endl;
        
        }
        text_toBeCoded = RemoveExtra(replace_with(to_lower(text_toBeCoded), 'j', replacing_letter));
        cout << Code_Text(text_toBeCoded, code_array)<<endl;

        while (text_toBeDecoded.length() < 2) {
        cout << "Input your text for Coding" << endl;  getline(cin, text_toBeDecoded); cout << endl;
        
        }
        text_toBeDecoded = RemoveExtra(replace_with(to_lower(text_toBeDecoded), 'j', replacing_letter));
        cout << replace_with( Decode_Text(text_toBeDecoded, code_array),replacing_letter,'j') << endl;
        cout << replace_with( Decode_Text(text_toBeDecoded, code_array),replacing_letter,'j') << endl;

    
}



string RemoveExtra(string text) {
    string val;
    int q = 0;
    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 97 && int(text[i]) <= 122) {
            val += " ";
            val[q] = text[i];
            q++;
        }            
    }
    return val;
}
string Code_Text(string text, char key[5][5]) {
    
    int r1, r2, c1, c2;
    text = RemoveRepetitions(RemoveExtra(to_lower(text)));
    
    if (text.length() % 2 == 1) text =text + "z";
    
   for(int i=0;i<text.length();i+=2){
       
       /// Finding the indexes of letters
       for (int j = 0; j < 5; j++) {
           for (int k = 0; k < 5; k++) {
               if (text[i] == key[j][k]) {
                   r1 = j;
                   c1 = k;
               }
               else if (text[i+1] == key[j][k]) {
                   r2 = j;
                   c2 = k;
               }

               
           }
       }
       if(r1 == r2) {
           text[i] = key[r1][(c1 + 1)%5 ];
           text[i + 1] = key[r2][(c2 + 1) % 5];
       }
       else if (c1 == c2) {
           text[i] = key[(r1 + 1) % 5][c1];
           text[i + 1] = key[(r2 + 1) % 5][c2];
       }
       else {
           text[i] = key[r1][c2];
           text[i + 1] = key[r2][c1];
       }
   }
    return text;
}
string Decode_Text(string text, char  key[5][5]) {
    int r1, r2, c1, c2;
    text = RemoveExtra(to_lower(text));

    for (int i = 0; i < text.length(); i += 2) {

        /// Finding the indexes of letters
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (text[i] == key[j][k]) {
                    r1 = j;
                    c1 = k;
                }
                else if (text[i + 1] == key[j][k]) {
                    r2 = j;
                    c2 = k;
                }


            }
        }

        if (r1 == r2) {
            text[i] = key[r1][c1 + ((c1 != 0) ? (-1) : 4)];
            text[i + 1] = key[r2][c2 + ((c2!=0)?(-1):4)];
        }
        else if (c1 == c2) {
            text[i] = key[r1 + ((r1 != 0) ? (-1) : 4)][c1];
            text[i + 1] = key[r2 + ((r2 != 0) ? (-1) : 4)][c2];
        }
        else {
            text[i] = key[r1][c2];
            text[i + 1] = key[r2][c1];
        }
    }

    
    return text;
}
string RemoveRepetitions(string text) {
    string val;
    int q = 0;
    for (int i = 0; i < text.length(); i+=2) {
        if (text[i] != text[i + 1]) {
            val += "  ";
            val[q] = text[i];
            val[q + 1] = text[i + 1];
            q += 2;
        }
        else {
            val += "   ";
            val[q] = text[i];
            val[q + 1] = 'z';
            val[q + 2] = text[i + 1];
            q += 3;
        }
        
    }
    return val;
}

///Making The text small lettered
string to_lower(string text) {
    
    for (int i = 0; i < text.length(); i++) {
        if (int(text[i]) >= 65 && int(text[i]) <= 90) {
            text[i] = char(int(text[i]) + 32);
        }
    }
    return text;
}
char to_lower(char text) {

            if (int(text) >= 65 && int(text) <= 90) {
            text = char(int(text) + 32);        }
    return text;
}


 /// Replacing function
string replace_with(string text, char which, char with) {    
    for (int i = 0; i < text.length(); i++) {
        if (to_lower(text[i]) == to_lower(which)) {
            text[i] = with;
        }
    }
    return text;
}
