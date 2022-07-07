/**
// Created by Steve Ntare on 6/25/2021.
*/

#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_INDEXHANDLER_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_INDEXHANDLER_H
#include "parser.h"
#include "docudata.h"
#include "AVLTree.h"
#include "DSVector.h"
#include "IndexEntry.h"

class IndexHandler {
private:
    AVLTree<IndexEntry> theIndex;
    DSVector<IndexEntry> entries;
    DSVector<PaperWordEntry> theList;
    DSVector<PaperWordEntry> theList2;
    DSVector<DSString> usedIDs;
    IndexEntry findWordIn(IndexEntry &key);

public:
    IndexHandler();

    /**
     *
     * @param in is used to fill the entries vector
     */
    void getParsed(parser &in);
    AVLTree<IndexEntry> getIndex(){ return theIndex;}

    /**
     * Converts the entries vector to an AVLTree
     */
    void indexToAvl();

    void clearAVL();

    /**
     * prints the AVLTREE
     */
    void printAVL();

    /**
     *
     * @param key
     */
    void findWord(const DSString &key);

    void findWordAnd(const DSString &key, const DSString &key2);

    void findWordOr(const DSString &key, const DSString &key2);

    void findWordNot(const DSString &key, const DSString &key2);

    void findWordAndNot(const DSString &key, const DSString &key2, const DSString &key3);

    void findWordOrNot(const DSString &key, const DSString &key2, const DSString &key3);



    /**
 * So that certain professors don't get tripped in front of the bus
 * again, one of you needs to turn this into an actual sort function.
 *
 * @param all_the_stuff
 */
    void sort_for_miles_and_steve(IndexEntry &all_the_stuff);

    void sort_for_miles_and_steveAnd(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff);

    void sort_for_miles_and_steveOr(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff);

    void sort_for_miles_and_steveNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff);

    void sort_for_miles_and_steveAndNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff, IndexEntry &stuff_the_third);

    void sort_for_miles_and_steveOrNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff, IndexEntry &stuff_the_third);


    void clear(){
        theIndex.clear();
        entries.clear();
        theList.clear();
        theList2.clear();
    }

    void printMap();
    bool printIndex(PaperWordEntry& in) {
        bool Print = true;
        for (int i = 0; i < usedIDs.getSize(); ++i) {
            if (usedIDs[i] == in.getPaperID()) {
                Print = false;
            }
        }
        if (Print) {
        cout << "Title: " << in.getTitle() << endl;
        cout << "Paper ID: " << in.getPaperID() << endl << endl << endl;
            usedIDs.push_back(in.getPaperID());
        }

        return Print;

    }


};
#endif //SU21_SRCH_ENG_MILES_AND_STEVE_INDEXHANDLER_H

