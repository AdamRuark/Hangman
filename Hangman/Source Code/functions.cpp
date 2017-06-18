#include "./functions.h"

void game_display(Word *user) {
	system("cls");
	cout << "HANGMAN" << endl << endl;
	cout << "Word: " << user->get_display() << endl << endl;
	cout << "Guessed Letters: " << user->get_guesses() << endl;		
	cout << "Attempts Left: " << user->get_attempts() << endl << endl;
}

string get_input() {
	string temp;
	bool run = true;

	while (run) {
		system("cls");
		cout << "Enter phrase: ";
		getline(cin, temp);
		string_upper(temp);
		for (int i = 0; i < temp.length(); i++) {
			if ((temp[i] < 'A' || temp[i] > 'Z') && temp[i] != ' ') {
				cout << endl << "Only use letters and spaces" << endl << endl;
				system("pause");
				run = true;
				break;
			}
			else {
				run = false;
			}
		}
	}
	return temp;
}

char get_char(Word *user) {
	char temp;
	do {
		game_display(user);
		cout << "Enter Letter: ";
		cin >> temp;
		temp = toupper(temp);

	} while (temp < 65 || temp > 90);

	return temp;
}

bool win_lose(Word *user) {
	if (user->get_attempts() == 0)
		return true;
	return false;
}

bool run_again(Word *user) {
	string input;
	do {
		system("cls");
		if (win_lose(user)) {
			cout << "You ran out of attempts" << endl << endl;

		}
		else {
			cout << "Congratulations! You guessed the phrase" << endl << endl;
		}
		cout << "The correct phrase was: " << user->get_user_word() << endl << endl;
		cout << "Would you like to play again?" << endl;
		cout << "Enter (Y/N): ";
		if (!(cin >> input)) {
			cin.clear();
			cin.ignore(1000, '/n');
		}

		//Wow these string arrays are not good. Seriously, don't do this again
		input[0] = toupper(input[0]);
	} while (input[0] != 'Y' && input[0] != 'N' || input.length() != 1);

	if (input[0] == 'Y')
		return true;
	else
		return false;
}

bool num_players() {
	char num;
	do {
		system("cls");
		cout << "HANGMAN" << endl << endl;
		cout << "Number of players (1/2): ";
		if (!(cin >> num)) {
			cin.clear();
			cin.ignore(1000, '/n');
		}
	} while (num < '1' || num > '2');
	if (num == '1')
		return true;
	else
		return false;
}

void rand_word(string &temp, ifstream &myfile) {
	int num;


	for (num = 0; getline(myfile, temp); num++) {/*get max # of items in file*/}

	num = rand() % num;

	myfile.clear();
	myfile.seekg(0, ios::beg);

	for (int i = 0; i < num; i++) {
		getline(myfile, temp);
	}
	myfile.close();
}


//I shouldn't even have this function but it was easier to copy and paste than to admit mistakes
void string_upper(string &user) {
	for (int i = 0; i < user.length(); i++) {
		user[i] = toupper(user[i]);
	}
}

bool get_file_name(ifstream &myfile) {
	string name, dir;
	do {
		dir = "./Categories/";
		system("cls");
		cout << "Enter file name or type \"quit\" to exit the game." << endl << endl;
		cout << "File Name: ";
		if (!(cin >> name)) {
			cin.clear();
			cin.ignore(1000, '/n');
		}
		else if (name == "quit") {
			break;
		}
		dir.append(name);
		dir.append(".txt");
		myfile.open(dir.c_str());

	} while (!(myfile.is_open()));

	if (name == "quit") {
		return true;
	}
	return false;
}
