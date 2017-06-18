#pragma once

#include <stdlib.h>		//srand, rand
#include <time.h>		//time
#include <string>		//string
#include <iostream>		//cout, cin
#include <fstream>		//ifstream

using namespace std;

class Word {
	private:
		string user_word;
		string display;
		string guesses;
		int attempts;
	public:
		Word(string);
		string get_user_word();
		string get_display();
		bool complete();
		int get_attempts();
		string get_guesses();
		bool set_guesses(char);
		void string_upper(string &);


};