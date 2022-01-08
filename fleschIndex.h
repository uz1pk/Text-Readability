/*
Name: Usman Zaheer
Class: CIS 2500
Helper function for fleschIndex.c
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* readFile (char* filename);

int calculateFleschIndex(int syllables, int words, int sentences);

void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount);

int countWords(char* textString);

int countSentences(char* textString);

int countSyllables (char* textString);
