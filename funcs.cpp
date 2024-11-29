#include "funcs.h"

int countFunc(const string& text, const string& word)
{
	int counter = 0;
	size_t pos = text.find(word);
	while (pos != string::npos)
	{
		counter++;
		pos = text.find(word, pos + word.size());
	}
	return counter;
}

int countS(const string& text)
{
	int counter = 0;
	size_t pos = 0;
	while ((pos = text.find_first_of(".!?", pos)) != std::string::npos) {
		counter++;     
		pos++; 
	}
	return counter;
}

int DotsAndCommas(const string& text)
{
	int counter = 0;
	size_t pos = 0;
	while ((pos = text.find_first_of(".,", pos)) != std::string::npos) {
		counter++;
		pos++;
	}
	return counter;
}

void reverseText(string& text)
{
	for (size_t i = 0; i < text.size() / 2; i++)
		swap(text[i], text[text.size() - 1 - i]);
	return;
}

void reverseS(string& text)
{
	size_t start = 0;
	for (size_t i = 0; i <= text.size(); i++)
	{
		if (i == text.size() || text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			size_t end = i - 1;
			while (start < end)
			{
				swap(text[start], text[end]);
				start++; end--;
			}
			start = i + 1;
		}
	}
}