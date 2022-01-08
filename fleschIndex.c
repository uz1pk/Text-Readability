/*
Name: Usman Zaheer
Class: CIS 2500
All function can sufficently perform given tasks
*/

#include "fleschIndex.h"

int calculateFleschIndex(int syllables, int words, int sentences) {
    return round(206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences));
}
//Function just does the required, used round to round it up/down

void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount) {
    printf("Flesch Index = %d\n", fleshIndex);
    printf("Syllable Count = %d\n", syllables);
    printf("Word Count = %d\n", words);
    printf("Sentence Count = %d\n", sentenceCount);
}
//print function

char* readFile (char* filename) {
    char* textString;
	int size;
	FILE* fptr = fopen(filename, "r");
	fseek(fptr, 0, SEEK_END);
	size = ftell(fptr);
	textString = malloc(sizeof(char) * (size + 1));
	fseek(fptr, 0, SEEK_SET);
	fread(textString, 1, (size + 1), fptr);
    return textString;
}
//In this function I seek to end of the file, get the size of file, and malloc that space, 
//and write into the char* and return it

int countWords(char* textString) {
    int totalWords = 0;
    int size = strlen(textString);
    char string[size];
    strcpy(string, textString);

    char* piece = strtok(string, " \n");
    while(piece != NULL) {
        piece = strtok(NULL, " \n \t \r");
        totalWords = totalWords + 1;
    }
    return totalWords;
}
//simple strtok to read the total number of words, I made sure that it accounts for all spaces
//this includes spaces, newline, tab and enter.

int countSentences(char* textString) {
    int size = strlen(textString);
    int sentences = 0;

    for(int i = 0; i < size; ++i) {
        if(textString[i] == '!' || textString[i] == '.' || textString[i] == '?') {
            sentences = sentences + 1;
        }
    }
    return sentences;
}
//Loop through the string and checks for anything that is considered to be end sentence.

int countSyllables (char* textString) {
    int size = strlen(textString);
    int vowels = 0, syllables = 0;
    for(int i = 0; i < size; ++i) {
        textString[i] = tolower(textString[i]);
    }

    char* piece = strtok(textString, " \n");
    while(piece != NULL) {
        int tempSize = strlen(piece);
        for(int i = 0; i < tempSize; ++i) {
            if((piece[i] == 'a') || (piece[i] == 'e') || (piece[i] == 'o') || (piece[i] == 'i') || (piece[i] == 'u') || (piece[i] == 'y')) {
                vowels = vowels + 1;
                if((piece[i + 1] == 'a') || (piece[i + 1] == 'e') || (piece[i + 1] == 'i') || (piece[i + 1] == 'o') || (piece[i + 1] == 'u') || (piece[i + 1] == 'y')) {
                    vowels = vowels - 1;
                    if(piece[tempSize - 1] == 'e') {
                        vowels = vowels - 1;
                        if(piece[tempSize - 2] == 'e' && (piece[tempSize - 1] == '!' || piece[tempSize - 1] == '.' || piece[tempSize - 1] == ',' || piece[tempSize - 1] == '?' || piece[tempSize - 1] == '\n' || piece[tempSize - 1] == '\t' || piece[tempSize - 1] == '\r')) {
                            vowels = vowels - 1;
                            if(vowels == 0) {
                                vowels = vowels + 1;
                            }
                        }
                    }
                }
            }
        }
        syllables = syllables + vowels;
        vowels = 0;
        piece = strtok(NULL, " \n \t \r");
    }
    return syllables;
}
/*
This function first lowercases everything so my if statements aren't huge,
it then uses strtok to go word by word, From there it first checks for all instances of vowels
in the word and tallys it up. The following statement checks for if there is another vowel infront of
another vowel and ticks off the tally. Next statement checks if the last character of the word is an e
letter and tallys off the total syllable count. Then it check for if e is the last character and if there is a
space, sentence ending symbol and ticks off again. From there it will add the vowels from that word
and add it to the total count of syllables.
*/
