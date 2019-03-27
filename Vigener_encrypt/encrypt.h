#pragma once
#include <iostream>

void encrypt(char* buffer, char* to_encrypt, int const& word_size, char* keyword, char** square);
void create_square(char** Vig_square, char* language, int letters_count);