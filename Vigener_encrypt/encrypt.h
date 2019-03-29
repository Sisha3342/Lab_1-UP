#pragma once
#include <atltime.h>

void encrypt(char* buffer, char* to_encrypt, int const& word_size, CString keyword, char** square);
void create_square(char** Vig_square, const char* language, int letters_count);