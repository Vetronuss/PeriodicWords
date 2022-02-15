#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

string toPeriodic(string word)
{
	string str = "";
	string elements[118] = {"Ac", "Ag", "Al", "Am", "Ar", "As", "At", "Au", "Ba", "Be", "Bh", "Bi", "Bk", "Br", "Ca", "Cd", "Ce", "Cf", "Cl", "Cn", "Cm", "Co", "Cr", "Cs", "Cu", "Ds", "Db", "Dy", "Er", "Es", "Eu", "Fm", "Fl", "Fe", "Fr", "Ga", "Gd", "Ge", "He", "Hg", "Hf", "Ho", "Hs", "In", "Ir", "Kr", "La", "Li", "Lr", "Lv", "Lu", "Md", "Mg", "Mn", "Mt", "Mo", "Mc", "Na", "Nb", "Nd", "Ne", "Ni", "Nh", "No", "Np", "Og", "Os", "Pb", "Pa", "Pd", "Po", "Pr", "Pm", "Pt", "Pu", "Ra", "Rb", "Re", "Rf", "Rg", "Rh", "Rn", "Ru", "Sb", "Sc", "Sm", "Sg", "Se", "Si", "Sn", "Sr", "Ta", "Tb", "Tc", "Te", "Th", "Ts", "Tl", "Ti", "Tm", "Xe", "Yb", "Zn", "Zr", "B", "C", "F", "H", "I", "K", "N", "O", "P", "S", "W", "U", "V", "Y"};
	string current = "";
	int trys = 0;
	for (int k = 0; word.length() > 0; k++){
		for (int i = 0; i < 118; i++)
		{
			bool match = true;
			for (int o = 0; o < elements[i].length(); o++)
			{
				if (tolower(word[o]) != tolower(elements[i][o]))
				{
					match = false;
					break;
				}
			} 
			if (match)
			{
				current += elements[i];
				word.erase(0,elements[i].length());
				k+= elements[i].length()-1;
				elements[i] = "-";
			}
		}
		
		//note to self: DONT DO THIS EVER AGAIN:
		if (trys > 100){
			current+= "*";
			break;
		}else
		{
			trys++;
		}
	}
	
	return current;
}

void generateWords()
{
	ifstream read;
	string word;
	read.open("words.txt");
	string longest;
	for (int i = 0; i < 20; i++){
		longest = " ";
	}
	while (!read.eof())
	{
		read >> word;
		if (word.length() >= 18)
		{
			string converted = toPeriodic(word);
			if (converted.find('*') != string::npos)
			{
				
			}else
			{
				//found periodic word
				cout << converted << endl;
				if (longest.length() < converted.length())
				{
					longest = converted;
				}
			}
		}
	}
	cout << "Longest Word: " << longest << endl;
	cout << "Word Length: " << longest.length() << endl;
	string b = "";
	for (int i = 0; i < longest.length(); i++)
	{
		b += tolower(longest[i]);
	}
	cout << "Easy Read: " << b;
	read.close();
}


int main() 
{
	generateWords();
	return 0;
} 