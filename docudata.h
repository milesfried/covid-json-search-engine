/**
 * Author: Miles Friedman
 * Created: 6/23/21
 */
#include <iostream>
#include "DSString.h"
#include "DSVector.h"
#include "PaperWordEntry.h"

#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_DOCUDATA_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_DOCUDATA_H


class docudata {
private:
    DSVector<DSString> authors;
    DSVector<DSString> texts;
    DSString id;
    DSVector<PaperWordEntry> documents;
    DSString title;
    int authSize = 0;
    int textSize = 0;
public:
    /**
     *
     * @param idIn is set to id
     * @param titleIn is set to title
     */
    docudata(const DSString& idIn, const DSString& titleIn);
    /**
     *
     * @return authors
     */
    DSVector<DSString>& getAuthors(){return authors;}
    /**
     *
     * @return texts
     */
    DSVector<DSString>& getTexts(){return texts;}
    /**
     *
     * @return id
     */
    DSString& getID(){return id;}
    /**
     *
     * @return title
     */
    DSString& getTitle(){return title;}
    /**
     *
     * @param author is pushed into the authors vector
     */
    void pushAuthor(const DSString& author);
    /**
     *
     * @param text is pushed into the texts vector
     */
    void pushText(const DSString& text);
    /**
     *
     * @param doc copy constructor
     */
    docudata(const docudata& doc);
    /**
     * prints out data members
     */
    void print();
    /**
     * default constructor
     */
    docudata() = default;
    /**
     * creates a vector of paperwordentry objexts
     */
    void Tokenize();
    /**
     * prints from the documents vector
     */
    void printDocs();
    /**
     *
     * @return documents
     */
    DSVector<PaperWordEntry>& getDocs();
    docudata& operator=(const docudata&arg);

};

#endif //SU21_SRCH_ENG_MILES_AND_STEVE_DOCUDATA_H

