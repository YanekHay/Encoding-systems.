#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

string Encode(string, string);
string Decode(string, string);
string ShiftBit(string, bool);
string ToBinary(string);
string ToBinary(char);
string XOR_string(string, string);
void SplitBy(string , int );

int main() {
	string code_text, to_Encode;

	//Getting inputs
	cout << endl; cout << "Input Key with one letter:\n";
	getline(std::cin, code_text);


	cout << endl; cout << "Input a text to Encode:\n";
	getline(std::cin, to_Encode);
	cout << "\n\n\n";

	cout << "Text:    "; SplitBy(ToBinary(to_Encode),8);
	cout << "Key:     "; SplitBy(ToBinary(code_text), 8);
	cout << "Enoded:  "; SplitBy(Encode(to_Encode, code_text), 8);

	//Decoding the Encoded text
	cout << "Decoded: ";  SplitBy(Decode(Encode(to_Encode, code_text), code_text),8);
	return 0;
}



string Encode(string text, string key) {
	string encoded = "";
	//Assume that Key consists of one letter.
	//That's why key[0]
	string t;
	t = XOR_string(ToBinary(text[0]), ToBinary(key[0]));
	encoded += ShiftBit(t , 0) ;
	for (int i = 1; i < text.length(); i++) {
		t = XOR_string(
					XOR_string(encoded.substr((i-1)*8,8), ToBinary(text[i])),
					ToBinary(key[0])
		);
			// { ^ } sign is XOR operator & Shift Left (ShiftBit(0))
		encoded += ShiftBit(t,0);
	}
	return (encoded);

}


string Decode(string text, string key) {
	string decoded = "";
	//Assume that Key consists of one letter.
	//That's why key[0]
	string t;
	for (int i = text.length()-8; i >=8 ; i-=8) {
		// Shift right XOR key XOR previous text[8] until the second octet
		t = XOR_string(
						(XOR_string(ShiftBit(text.substr(i, 8), 1), ToBinary(key[0]))),
						(text.substr(i-8, 8))
			);
		decoded = t + decoded;
	}
	// At the end XOR the first octet with the key. 
	decoded = (XOR_string(ShiftBit(text.substr(0, 8), 1), ToBinary(key[0]))) + decoded;
	return (decoded);
}

/// Function for converting text or charachter to binary code with octets(" "00000000" "11111111" "10100100" " )
 string ToBinary(string text) {
	 if (text == "0") return "00000000";
	string res ;
	for (std::size_t i = 0; i < text.length(); ++i)
	{
		res += bitset<8>(text.c_str()[i]).to_string();
	}
	return res;
}
 string ToBinary(char text) {
	 if (text == '0') return "00000000";
	 string res;
		 res += bitset<8>(text).to_string();

	 return res;
 }

 //Function for Bit-Shifting  *(* moving first char to the end |or| the last to the begining *)*
 //For dir input values 0(Left) or 1(Right)
 string ShiftBit(string Binary_text, bool dir) {
	 if (!dir) return  Binary_text = Binary_text.substr(1, Binary_text.length() - 1) + Binary_text[0];
	 else return Binary_text = Binary_text[Binary_text.length() - 1] + Binary_text.substr(0, Binary_text.length() - 1);
 }

 string XOR_string(string a, string b) {
	 string c = "";
	 for (int i = 0; i < a.length(); i++) {
		 c += to_string(((a[i]) + (b[i]) - 96) % 2);
	 }
	 return c;
 }


 void SplitBy(string text, int by) {
	 for (int i = 0; i <= text.length()-by; i += by) {
		 cout << text.substr(i, by)<< "  ";
	 }
	 cout << endl;
 }
