#include "funcs.h"

void rplWords(string& text, const string& word1, const string& word2)
{
	size_t pos = 0;
	while ((pos = text.find(word1, pos)) != string::npos)
	{
		text.replace(pos, word1.size(), word2);
		pos += word2.size();
	}
	return;
}

void toUpper(string& text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (i == 0 && text[i] >= 'a' && text[i] <= 'z')
			text[i] = text[i] - 32;
		if (text[i] == '.' || text[i] == '?' || text[i] == '!')
		{
			if (i + 1 < text.length() && text[i + 1] == ' ')
				i++;
			if (i + 1 < text.length() && text[i + 1] >= 'a' && text[i + 1] <= 'z')
				text[i + 1] = text[i + 1] - 32;
		}
	}
	return;
}

void countL(const string& text)
{
	int* array_1 = new int[26];
	for (int i = 0; i < 26; i++)
	{
		*(array_1 + i) = 0;
	}
	for (char c : text)
	{
		c = tolower(c);
		if (c >= 'a' && c <= 'z') {
			int index = c - 97;
			*(array_1 + index) += 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (*(array_1 + i) > 0) { 
			cout << char(i + 'a') << " appears " << array_1[i] << " times" << endl;
		}
	}
	delete[] array_1;
	return;
}

int countDigits(const string& text)
{
	int counter = 0;
	for (char c : text)
	{
		if (c >= '0' && c <= '9')
			counter++;
	}
	return counter;
}