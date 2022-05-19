#include <iostream>
#include <string>
#include <vector>
using namespace::std;

vector<vector<char>> Table();

const vector<vector<char>> table = Table();

template <class T>
void print(std::vector<T> const& );
template <class T>
void print(std::vector<vector<T>> );

string delete_junk(string);
string to_UpperCase(string);
string build_key(string, string);

string Encode(string, string);
string Decode(string , string );

int main(){
	print(table);

	string code_text,to_Encode;
	cout << endl; cout << "Input Code text:\n";
	getline(std::cin, code_text);	

	cout << endl; cout << "Input a text to Encode:\n";
	getline(std::cin, to_Encode);	

	cout << endl <<Encode(to_Encode, build_key(code_text, to_Encode));
  cout<<endl<<build_key(code_text,to_Encode);
	cout << endl << Decode(Encode(to_Encode, build_key(code_text, to_Encode)), build_key(code_text, to_Encode));

	return 0;
}

vector<vector<char>> Table() {
	vector<vector<char>> letters;
	vector<char> row;
	int shift = 0, char_val = 65;
	for (int i = 0; i <= 25; i++) {
		row.clear();
		char_val = shift + 65;
		for (int j = 0; j <= 25; j++) {
			if (char_val == 91) { char_val = 65; }
			row.push_back(char(char_val));
			char_val++;
		}
		shift++;
		letters.push_back(row);
	}

	return letters;
}
template <class T>
void print(std::vector<T> const& input){
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << ' ';
	}
}
template <class T>
void print(vector<vector<T>> matrice){
	for (int i = 0; i < matrice.size(); i++) {		
		for (int j = 0; j < matrice[i].size(); j++) {
			cout << matrice[i][j] << ' ';
		}
		cout << endl;
	}
}


string to_UpperCase(string text) {
	text = delete_junk(text);
	for (int i = 0; i < text.length(); i++) {
		if (int(text[i]) >= 97 && int(text[i]) <= 122) {
			text[i] = char(int(text[i] - 32));
		}
	}
	return text;
}

string delete_junk(string text) {
	string ret = "";
	for (int i = 0; i < text.length(); i++) {
		if (!((int(text[i]) < 65 || int(text[i]) > 90) && (int(text[i]) < 97 || int(text[i]) > 122))) {
			ret += text[i];
		}
	}
	return ret;
}

string build_key(string key, string text) {
	key = to_UpperCase(key);
	text = to_UpperCase(text);

	int q = 0;

	while(key.length()<text.length()){	
		key += key[q];
		q++;
	}
	return key;
}

string Encode(string text, string key) {
	text = to_UpperCase(text);
	
	string encoded = "";
	for (int i = 0; i< text.length(); i++) {
		encoded +=char(65+(int(text[i])+int(key[i])-130)%26);
	}
	return encoded;

}


string Decode(string text, string key) {
	text = to_UpperCase(text);	
	string decoded = "";
	for (int i = 0; i < text.length(); i++) {
	decoded += char(65+(int(text[i])-int(key[i])+26)%26);	
	}

	return decoded;
}
