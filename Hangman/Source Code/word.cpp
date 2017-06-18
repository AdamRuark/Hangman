#include "./word.h"

Word::Word(string user) {
	user_word = user;
	string_upper(user_word);
	for (int i = 0; i < user_word.length(); i++) {
		if (user_word[i] == ' ') {
			display.push_back(' ');
		}
		else {
			display.push_back('_');
		}
	}
	attempts = 10;
}

void Word::string_upper(string &user) {
	for (int i = 0; i < user.length(); i++) {
		user[i] = toupper(user[i]);
	}
}

int Word::get_attempts() {
	return attempts;
}

string Word::get_user_word() {
	return user_word;
}

string Word::get_display() {
	string temp;
	for (int i = 0; i < display.length(); i++) {
		temp.push_back(display[i]);
		temp.push_back(' ');
	}
	temp.pop_back();
	return temp;
}

string Word::get_guesses() {		
	string temp;
	for (int i = 0; i < guesses.length(); i++) {
		temp.push_back(guesses[i]);
		temp.push_back(',');
	}
	if(guesses.length() > 0)
		temp.pop_back();
	return temp;
}

bool Word::set_guesses(char chr) {
	bool in_word = false, in_guess = false;

	//check if guess is in word
	for (int i = 0; i < user_word.length(); i++) {
		if (user_word[i] == chr) {
			in_word = true;
			display[i] = chr;
		}
	}

	//if incorrect, see if it is in list of guessed letters
	if (!in_word) {
		for (int i = 0; i < guesses.length(); i++) {
			if (guesses[i] == chr) {
				in_guess = true;
				break;
			}
		}

		//if not, add letter to list and decrease attempts left
		if (!in_guess) {
			guesses.push_back(chr);
			attempts--;
		}
	}
	return in_word;
}
 
bool Word::complete() {
	for (int i = 0; i < display.length(); i++) {
		if (display[i] == '_' && attempts > 0) {
			return true;	//keep running
		}
	}
	return false;	//end game
}