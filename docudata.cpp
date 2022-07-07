/**
 * Created by Miles Friedman
 * 6/23/21
 */

#include "docudata.h"
docudata::docudata(const DSString& idIn, const DSString& titleIn){
id = idIn;
title = titleIn;
}

void docudata::pushText(const DSString& text) {
    texts.push_back(text);
    textSize++;
}

void docudata::pushAuthor(const DSString& author) {
   authors.push_back(author);
    authSize++;
}

docudata::docudata(const docudata &doc) {
    authors = doc.authors;
    texts = doc.texts;
    id = doc.id;
    title = doc.title;
}

void docudata::Tokenize() {
    int location = 1;
    for (int j = 0; j < texts.getSize(); ++j) {
        char word[100];
        int counter = 0;
        char* fed = texts[j].c_str();
        for (int i = 0; i < strlen(fed); i++) {
            if (fed[i] == ' ') {
                if(counter > 3) {
                    word[counter] = '\0';
                    DSString def = word;
                    PaperWordEntry temp(id, def, location, title);
                    //if the word is already found insert location of this word
                    if (documents.isFound(temp)) {
                        int index = documents.find(temp);
                        documents[index].locsPush(location);
                    } else {
                        documents.push_back(temp);

                    }
                }
                    location++;
                    counter = 0;


            } else if (isalpha(fed[i])){
                word[counter] = tolower(fed[i]);
                counter++;

            }

        }
    }
}

void docudata::print() {
    cout << "Paper id: " << id << endl;
    cout << "Title: " << title << endl;
    cout
            << "---------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout
            << "---------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "Author Info:" << endl;
    for(int i = 0; i < authSize; ++i){
        cout << authors[i] << endl;
    }
    cout
            << "---------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout
            << "---------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "Body Text" << endl;
    for(int i = 0; i < textSize; ++i){
        cout << texts[i] << endl;

    }
}

DSVector<PaperWordEntry>& docudata::getDocs() {
    return documents;
}

void docudata::printDocs() {
    for(int i = 0; i < documents.getSize(); ++i){
        documents[i].print();
    }
}

docudata& docudata::operator=(const docudata &arg) {
    authors = arg.authors;
    texts = arg.texts;
    id = arg.id;
    documents = arg.documents;
    title = arg.title;
    authSize = arg.authSize;
    textSize = arg.textSize;
    return *this;
}
