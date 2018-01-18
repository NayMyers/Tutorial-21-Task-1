#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<vector>


using namespace std;
template<typename T>
class TemplateBubbleSort
{
private:
	vector<T> values;
	int _swapattempts = 0;
public:
	T getValue(int valueindex);
	int numberofvalues(void); {return values.size(); }
	void addValue(T value);
	void displayValues(void);
	void sortValues(void);
	int swapattempts(void){ return _swapattempts; }
};
template <typename T>
void TemplateBubbleSort::addValue(T value)
{
	values.pushback(value);
}
template <typename T>
void TemplateBubbleSort<char>::sortValues(void)
{
	bool swap;
	T placeHolder
		do
		{
			swap = false;
			for (int x = 0; x< int(values.size() - 1); x++)
			{
				if (values[x].compare(values[x + 1]))
				{
					placeHolder = values[x];
					values[x] = values[x + 1];
					values[x + 1] = placeHolder;
					swap = true;
				}
			}
		} while (swap);
}

class Word
{
public:
	string word;
	bool beensorted = false;
};

class SortedWord
{
public:
	string word;
	vector<int>indexes;
};

class AnagramFinder
{
private:
	vector<Word> words;
	string word;
	bool beenSorted = false;
	vector<SortedWord> sortedwords;
	bool sorted = false;
	void sortWords(void);
	string sortWord(string word);
	void addSortedWord(string sortedword, int wordindex);
	bool existingSortedWord(int sortedwordcout, int wordindex);
public:
	void addword(string word);
	void displayWords(void);
	void displayAnagrams(void);
	int numberOfWords(void);
	int wordoperations = 0;
	//number of key operations - based on n = number of words
	int swapoperations = 0;
	//stored seperately because it is a factor of n and m (where m is average word length)
};
void AnagramFinder::addword(string word)
{
	for (int x = 0; x < int(words.size()); x++)
	{
		if (words[x].word == word) return; //word allready exists
	}
	Word NewWord;
	NewWord.word = word;

	words.push_back(NewWord);
	sorted = false;
}
void AnagramFinder::displayWords(void)
{
	for (int x = 0; x<int(words.size()); x++)
	{
		cout << "Word: " << x << words[x].word << endl;
	}
}
void AnagramFinder::displayAnagrams(void)
{
	if (!sorted)sortWords();
	//display
	for (int sortedwordcount = 0; sortedwordcount < sortedwords.size(); sortedwordcount++)
	{
		for (int indexcount = 0; indexcount < sortedwords[sortedwordcount].indexes.size(); indexcount++)
		{
			cout << words[sortedwords[sortedwordcount].indexes[indexcount]].word << ", ";
			cout << endl;
		}
	}
}
int AnagramFinder::numberOfWords(void)
{
	return words.size();
}
void AnagramFinder::addSortedWord(string sortedword, int wordindex)
{
	//this method checks to see if the sorted word already exists 
	//if it does, it adds the index to the original word
	// if it does not , it adds both the word and the word index
	for (int sortedwordcount = 0; sortedwordcount < sortedwords.size(); sortedwordcount++)
	{
		if (sortedword == sortedwords[sortedwordcount].word)//sorted word already exists
		{
			sortedwords[sortedwordcount].indexes.push_back(wordindex);//so add index only 
			return;
		}
	}
	SortedWord NewWord;
	NewWord.word = sortedword;
	NewWord.indexes.push_back(wordindex);

	sortedwords.push_back(NewWord);
}
template <typename T>
string AnagramFinder::sortWord(string word)
{
	TemplateBubbleSort<char> LetterSort; //bubblesort
	string sortedword;

	for (int lettercount = 0; lettercount < word.size(); lettercount++)
	{
		if (word[lettercount] != " ") LetterSort.addValue(word[lettercount]);
	}
	LetterSort.sortValues(); // run sort method of TemplateBubbleSort with the values provided

	for (int lettercount = 0; lettercount < LetterSort.numberofvalues(); lettercount++)
	{
		sortedword += LetterSort.getValue(lettercount);
	}
	swapoperations += LetterSort.swapattempts();
	return sortedword;
}


int main(void)
{
	

	return 0;
}