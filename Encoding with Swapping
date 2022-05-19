#include <iostream>
#include <string>
using namespace::std;



string delete_junk(string);
string to_UpperCase(string);

string Encode(string, int);
string Decode(string , int);

int main() {
  int key = 5;
  string to_Encode;
	cout << endl; cout << "Input Key for Encoding:\n";
	getline(std::cin, to_Encode);
  cout<<Encode(to_Encode,key)<<endl;
  cout<<Decode(Encode(to_Encode,key),key)<<endl;
}



string to_UpperCase(string text) {
	text = delete_junk(text);
	for (int i = 0; i < text.length(); i++) {
		if (int(text[i]) >= 97 && int(text[i]) <= 122) {
			text[i] = char(int(text[i] - 32));
	
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

string Encode(string text, int key) {
	text = to_UpperCase(delete_junk(text));
	string encoded = "";
  // Make the length of text divisible by key
while(text.length()%key!=0) text+="Z";
  for(int j = 0;j<key;j++){
    for (int i = j; i< text.length(); i+=key) {
		  encoded+=text[i];
	  }
  }
	return encoded;
}


string Decode(string text, int key) {
	text = to_UpperCase(text);	
	string decoded = "";
    for(int j = 0;j<text.length()/key;j++){
    for (int i = j; i< text.length(); i+=text.length()/key) {
		  decoded+=text[i];
	  }
  }
  //clean to get only one Z at the end
  while(decoded.substr(decoded.length()-2,1)=="Z") decoded = decoded.substr(0,decoded.length()-1);
	return decoded;
}
