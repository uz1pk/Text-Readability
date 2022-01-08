/*
Name: Usman Zaheer
Class: CIS 2500
Driver function for whole program
*/

#include "fleschIndex.h"

int main(int argc, char *argv[]) {
    char *textString;
    int totalWords, totalSentences, totalSyllables, fleschScore;
    
    if(argc > 1) {
        textString = readFile(argv[1]);

        totalSentences = countSentences(textString);
        totalWords = countWords(textString);
        totalSyllables = countSyllables(textString);
        fleschScore = calculateFleschIndex(totalSyllables, totalWords, totalSentences);

        outputFormattedFleschScores(totalSyllables, totalWords, fleschScore, totalSentences);
    }
}
