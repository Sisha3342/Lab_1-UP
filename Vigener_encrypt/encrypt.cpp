#include "encrypt.h"

void create_square(char** Vig_square, char* language, int letters_count)
{
	char s = 'a', c;

	//char Vig_square[letters_count + 2][letters_count + 2];
	
	Vig_square[0][0] = '0';

	if (!strcmp(language, "Eng"))
	{
		for (auto i = 1; i <= letters_count; i++, s++)
		{
			Vig_square[i][0] = s;
			Vig_square[0][i] = s;
		}

		Vig_square[letters_count + 1][0] = '\0';
		Vig_square[0][letters_count + 1] = '\0';

		for (auto i = 1; i <= letters_count; i++)
		{
			c = Vig_square[i][0];

			auto j = 1;
			for(; j <= letters_count; j++, c++)
			{
				Vig_square[i][j] = c;

				if (c == 'z')
					c = 'a' - 1;
			}

			Vig_square[i][j] = '\0';
		}
	}
}

void encrypt(char* buffer, char* to_encrypt, int const& word_size, char* keyword, char** square)
{
	int const letters_count = strlen(square[0]), key_size = strlen(keyword);
	
	int index1, index2; 

	for (int i = 0, j = 0; i < word_size; i++, j++)
	{
		if (j == key_size)
			j = 0;

		index1 = strchr(square[0], keyword[j]) - square[0];
		index2 = strchr(square[0], to_encrypt[i]) - square[0];
		buffer[i] = square[index1][index2];
	}
	buffer[word_size] = '\0';
}