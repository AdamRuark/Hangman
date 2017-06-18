#pragma once
#include "./word.h"

void game_display(Word *);
string get_input();
char get_char(Word *);
bool win_lose(Word *);
bool run_again(Word *);
bool num_players();
void rand_word(string &, ifstream &);
void string_upper(string &);
bool get_file_name(ifstream &);