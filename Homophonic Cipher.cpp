#include <iostream>
#include <stdlib.h>     
#include <time.h>
#include <string>

using namespace::std;

int** GenerateArray(int**, int);
int FindInKey(int, int**, int);
string EncodeText(string, int**, int);
string DecodeText(string, int**, int);
string RemoveExtra(string);
string RemoveSpaces(string);
string to_lower(string);
char to_lower(char);

int main() {
	int n = 27; // Adding Spacebar too
	int **cipherNums = new int* [n+1]; // The [n]th element is an array[size is n] which contains information about the lengths of each row
	srand(time(0));
	cipherNums = GenerateArray(cipherNums,n);
	
	
	string code_text;
	
	cout << endl; cout << " Input Code text  "<< endl;
	 getline(std::cin, code_text);
	 code_text=  EncodeText(code_text, cipherNums,n);
	 cout << code_text<<endl;
	 //cout << code_text << endl;


	 cout << DecodeText(code_text, cipherNums, n);
	return 0;
}

int** GenerateArray(int** a,int n) {	
	int m, *rowLengths = new int[n];	
	int seed = 0, * buffer = new int[n];
	int rangeA = 0, rangeB = 99; //The range of the random elements


	// Creating a matrice with randomly sized columns for the letters. 
	//NO REPETITIONS!

	for (int i = 0; i < n; i++) {
		if (i == n - 1) { cout << endl << "SpaceBar  "; }
		else { cout << endl << char(i + 65) << "  "; }
		m = rand() % 3 + 2;
		rowLengths[i] = m;		
		buffer[i] = 0;
		a[i] = new int[m];
		
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % (rangeB-rangeA)+rangeA;
			buffer[i]++;				
			again:
		   
			//Going over the matrice to find out repeating elements
			for (int k = 0; k <= i; k++) {						
						
				for (int l = 0; l < buffer[k]; l++) {
							
					if ((k == i && k!=n && l == j)) goto label;	// For not checking the current element with itself				
					if (a[i][j] == a[k][l] ) {
								
								//cout << "(REP:" << a[i][j] << ":" << char(k + 65) << " & " << l << ") ";
								srand(seed + time(0));
								a[i][j] = rand() % 98 + 1;
								seed++;
								goto again;
							}												
						}
					}			
		label:;
			cout << a[i][j] << "  ";
		}		
		
	}
	a[n] = rowLengths;
	return a;
}
int FindInKey(int value, int** Key,int n) {
	int res;
  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Key[n][i]; j++) {
			if (value == Key[i][j]) {
				res = i;
							
				return res;
			}
		}
	}
	return res;
}
string EncodeText(string text, int** Key, int n) {
	string result = "", add_0 = "", tx="";
	text = RemoveExtra(to_lower(text));
	
	for (int i = 0; i < text.length(); i++) {
		
		add_0 = "";
			if (text[i] == ' ') { //Key[n][n] returns the size of n-th row			
				result += " " + to_string(Key[n - 1][rand() % (Key[n][n - 1] - 1)]);
			}
			else {
				srand(time(0) + i);
				tx = to_string(Key[int(text[i]) - 97][rand() % (Key[n][int(text[i]) - 97] - 1)]);
				if (tx.length() == 1) add_0 = "0";
				result += " " + add_0 + tx;
			}
	}
	return result;
}

string DecodeText(string text, int** Key, int n) {
	string result = "", a="";
	int val;
	int find;
	text = RemoveSpaces(text);
	//text = RemoveExtra(text);
  
	cout << endl << "*** "<< text << endl;
	for (int i = 0; i < text.length(); i+=2) {
    a="";
    a=text.substr(i,2);
		val= stoi(a);
		//<<text[i] << text[i+1]<< endl;
		find = FindInKey(stoi(a), Key, n);
		if (find==(n-1)) result += " ";//Key[n][n] returns the size of n-th row
      
		else result += char(find+97);
		
	}
	return result;
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
		text = char(int(text) + 32);
	}
	return text;
}

string RemoveExtra(string text) {
	string val;
	int q = 0;
	for (int i = 0; i < text.length(); i++) {
		if ((int(text[i]) >= 97 && int(text[i]) <= 122) || int(text[i]) == 32 || (int(text[i]) >= 48 && int(text[i]) <= 57)) {
			val += " ";
			val[q] = text[i];
			q++;
		}
	}
	return val;
}

string RemoveSpaces(string text) {
	string val;
	int q = 0;
	for (int i = 0; i < text.length(); i++) {
		if ( int(text[i]) != 32 ) {
			//val += " ";
			val +=text[i];
			q++;
		}
	}
	return val;
}
