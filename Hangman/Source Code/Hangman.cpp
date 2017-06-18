#include "./functions.h"


int main(){
	bool run = true;
	string temp;
	Word *user;
	ifstream myfile;

	srand(time(NULL));

	while (run) {

		//1 player
		if (num_players()) {
			if (get_file_name(myfile)) {
				break;
			}
			rand_word(temp, myfile);
		}

		//2 players
		else {
			temp = get_input();
		}
		system("cls");

		user = new Word(temp);
		while (user->complete()) {
			user->set_guesses(get_char(user));
		}
		run = run_again(user);

		delete user;
	}

    return 0;
}

