//
// Created by Miles Friedman on 6/29/21.
//

#include <chrono>
#include "Query.h"
#include <string>

using namespace std::chrono;

void Query::clearIndex() {
    index.clear();
    parse.clear();
    articlesIndexed = 0;
    wordsPerArticle = 0;
    uniqueWords = 0;
    authorSize = 0;
    hasContent = false;
    cout << "Index Cleared!" << endl << endl;

}

void Query::addIndex() {
    char fileName[500];
    cout << "Please Provide The Path To The New Index" << endl << endl;
    cin >> fileName;
    cout << "Updating Index..." << endl;
    auto start = high_resolution_clock::now();

    parse.open_dir(fileName);
    parse.createIndexEntries();
    index.getParsed(parse);
    index.indexToAvl();
    authorSize = parse.getAuthorCount();
    articlesIndexed = parse.getParsedInfo().getSize();
    wordsPerArticle = parse.getAvgWords();
    uniqueWords = index.getIndex().getSize();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    hasContent = true;
    cout << "Index Updated in " << duration.count() / 1000000 << " seconds!" << endl << endl;
}

int Query::searchIndexMenu() {
    int input;
    cout << "Input The Number Of A Menu Option:" << endl;
    cout << "1. Single Word Search" << endl;
    cout << "2. AND Search" << endl;
    cout << "3. OR Search" << endl;
    cout << "4. NOT Search" << endl;
    cout << "5. AND NOT Search" << endl;
    cout << "6. OR NOT Search" << endl;
    cin >> input;
    return input;
}

void Query::singleSearch() {
    char* searchTerm1;
    char temp[100];

    cout << "Please Input The Word To Search For" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    index.findWord(searchTerm1);


}

void Query::orNotSearch() {
    char* searchTerm1;
    char* searchTerm2;
    char* searchTerm3;
    char temp[100];
    char temp2[100];
    char temp3[100];

    cout << "Please Input The First Word To Search For:" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Second Word To Search For" << endl;
    cin >> temp2;
    searchTerm2 = temp2;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Word To NOT Search For" << endl;
    cin >> temp3;
    searchTerm3 = temp3;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << searchTerm1 << " " << searchTerm2 << " " << searchTerm3 << endl;

    index.findWordOrNot(searchTerm1, searchTerm2, searchTerm3);
}

void Query::andNotSearch() {
    char* searchTerm1;
    char* searchTerm2;
    char* searchTerm3;
    char temp[100];
    char temp2[100];
    char temp3[100];

    cout << "Please Input The First Word To Search For:" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Second Word To Search For" << endl;
    cin >> temp2;
    searchTerm2 = temp2;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Word To NOT Search For" << endl;
    cin >> temp3;
    searchTerm3 = temp3;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    index.findWordAndNot(searchTerm1, searchTerm2, searchTerm3);
}

void Query::notSearch() {
    char* searchTerm1;
    char* searchTerm2;
    char temp[100];
    char temp2[100];
    cout << "Please Input The First Word To Search For:" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Word To NOT Search For" << endl;
    cin >> temp2;
    searchTerm2 = temp2;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    index.findWordNot(searchTerm1, searchTerm2);
}

void Query::orSearch() {
    char* searchTerm1;
    char* searchTerm2;
    char temp[100];
    char temp2[100];

    cout << "Please Input The First Word To Search For:" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Second Word To Search For" << endl;
    cin >> temp2;
    searchTerm2 = temp2;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    index.findWordOr(searchTerm1, searchTerm2);
}

void Query::andSearch() {
    char* searchTerm1;
    char* searchTerm2;
    char temp[100];
    char temp2[100];
    cout << "Please Input The First Word To Search For:" << endl;
    cin >> temp;
    searchTerm1 = temp;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Please Input The Second Word To Search For" << endl;
    cin >> temp2;
    searchTerm2 = temp2;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    index.findWordAnd(searchTerm1, searchTerm2);

}

void Query::printStats() {
    cout << articlesIndexed << " articles indexed" << endl;
    cout << wordsPerArticle << " average words per article" << endl;
    cout << uniqueWords << " unique words in the index" << endl;
    cout << authorSize << " authors found" << endl;

}
