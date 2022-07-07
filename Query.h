//
// Created by Miles Friedman on 6/29/21.
//

#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_QUERY_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_QUERY_H
#include <iostream>
#include "parser.h"
#include "IndexHandler.h"

using namespace std;


class Query {
private:
    parser parse;
    IndexHandler index;
    bool hasContent = false;
    int articlesIndexed = 0;
    int wordsPerArticle = 0;
    int uniqueWords = 0;
    int authorSize = 0;
    void addIndex();
    void clearIndex();
    int searchIndexMenu();
    void singleSearch();
    void andSearch();
    void orSearch();
    void notSearch();
    void andNotSearch();
    void orNotSearch();
    void printStats();
    void singleAuthorSearch();
    docudata& idToDocuData(DSString id){
        for(int i = 0; i < parse.getParsedInfo().getSize(); ++i){
            if(id == parse.getParsedInfo()[i].getID()){
                return parse.getParsedInfo()[i];

            }
        }
    }
public:
    Query() = default;


    void displayMenu() {

        int in = 0;
        while (in != 5) {
            cout << "Input The Number Of A Menu Option:" << endl;
            cout << "1. Add Index" << endl;
            cout << "2. Clear Index" << endl;
            cout << "3. Search Index" << endl;
            cout << "4. Display Stats" << endl;
            cout << "5. Quit" << endl;
            cin >> in;
            /**
             * adds a dir to the index
             */
            if (in == 1) {
                addIndex();
            }
            /**
             * clear index
             */
            else if (in == 2) {
                clearIndex();
            }
            /**
             * contains a if-else branch to search for the user's desired terms
             */
            else if (in == 3) {
                if (hasContent) {
                    int newin = searchIndexMenu();
                    // single search
                    if (newin == 1) {
                        singleSearch();
                    }
                        // and search
                    else if (newin == 2) {
                        andSearch();
                    }
                        //or search
                    else if (newin == 3) {
                        orSearch();
                    }
                        //not search
                    else if (newin == 4) {
                        notSearch();
                    }
                        //andnot search
                    else if (newin == 5) {
                        andNotSearch();
                    }
                        //ornot search
                    else if (newin == 6) {
                        orNotSearch();
                    }
                    char *id;
                    char temp[100];
                    cout << "Copy and Paste The Paper ID of The Article You Want To Open Or Enter 0 To Continue"
                         << endl;
                    cin >> temp;
                    id = temp;
                    if (strcmp(id, "0") == 0) {

                    } else {
                        int charCount = 0;
                        docudata cpp = idToDocuData(id);
                        for (int j = 0; charCount < 1400; ++j) {

                            if (cpp.getTexts()[j].getLength() > 0) {
                                cout << cpp.getTexts()[j] << endl;
                                charCount += strlen(cpp.getTexts()[j].c_str());
                            }
                        }

                    }

                } else {
                    cout << "Cannot search an empty index" << endl;
                }
            }
            /**
             * Displays stats about the index
             */
            else if (in == 4) {
                printStats();
            }
            /**
             * quits the program
             */
            else if (in == 5) {
                break;
            }
        }
    }
};


#endif //SU21_SRCH_ENG_MILES_AND_STEVE_QUERY_H
