//
// Created by Steve Ntare on 6/25/2021.
//

#include "IndexHandler.h"

IndexHandler::IndexHandler() = default;

IndexEntry IndexHandler::findWordIn(IndexEntry &key) {
    bool found = false;
//
    //theIndex.find(key, found);
    IndexEntry the_return_value;
    found = theIndex.find_val(key, the_return_value);
    if(!found){
        cout << "Word "<< key.getWord() << " not found!" << endl;
    }
    //else{
        return the_return_value;
    //}
}

void IndexHandler::indexToAvl() {
    for(int i = 0; i < entries.getSize(); ++i){
        theIndex.add(entries[i]);
    }
}

void IndexHandler::getParsed(parser &in) {
    entries = in.getEntries();

}

void IndexHandler::printAVL() {
    theIndex.print();
}

void IndexHandler::findWord(const DSString& key) {
    IndexEntry search_key = (key);
    IndexEntry key_from_tree;
    key_from_tree = findWordIn(search_key);
    sort_for_miles_and_steve(key_from_tree);



//    for(int i = 0; i < key_from_tree.getLocations().getSize(); ++i) {
//        cout << key_from_tree.getWord() << " appears "
//             << key_from_tree.getLocations()[i].getLocs().getSize()
//             << " times in Paper "
//             << key_from_tree.getLocations()[i].getPaperID() << endl;
//    }
}

void IndexHandler::sort_for_miles_and_steve(IndexEntry &all_the_stuff) {
    theList.clear();
    usedIDs.clear();
    theList2.clear();
    int paperCount = 0;

    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){

        PaperWordEntry temp = all_the_stuff.getLocations()[i];

        theList.push_back(temp);
    }
    //sort
    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
           theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    //print
    cout << "Top Results For: " << all_the_stuff.getWord() << endl;
    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount  << " result[s] found, try broadening your search" << endl << endl << endl;
            break;
        }
        cout << "Paper " << paperCount++ + 1<< endl;
        cout << "Title: " << theList[i].getTitle() << endl;
        cout << "Paper ID: " << theList[i].getPaperID() << endl;
        cout << endl << endl;
    }
}

void IndexHandler::sort_for_miles_and_steveAnd(IndexEntry &all_the_stuff, IndexEntry& the_other_stuff) {
    theList.clear();
    usedIDs.clear();
    theList2.clear();
    int paperCount = 0;
    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
        for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
            if(all_the_stuff.getLocations()[i].getPaperID() ==  the_other_stuff.getLocations()[j].getPaperID()){
                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);


                continue;
            }

        }
    }
    //sort
    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
            theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    //print
    cout << "Top Results For: " << all_the_stuff.getWord() << " and " << the_other_stuff.getWord() << endl;

    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount  << " result[s] found, try broadening your search" << endl << endl << endl;
            break;
        }
        cout << "Paper " << paperCount++ + 1<< endl;
        cout << "Title: " << theList[i].getTitle() << endl;
        cout << "Paper ID: " << theList[i].getPaperID() << endl;

        cout << endl << endl;
    }

}

void IndexHandler::findWordAnd(const DSString &key, const DSString &key2) {


    IndexEntry search_key1 = (key);
    IndexEntry search_key2 = (key2);
    IndexEntry key_from_tree;
    IndexEntry key_from_tree2;
    key_from_tree = findWordIn(search_key1);
    key_from_tree2 = findWordIn(search_key2);
    sort_for_miles_and_steveAnd(key_from_tree, key_from_tree2);

}

void IndexHandler::sort_for_miles_and_steveOr(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff) {
    theList.clear();
    usedIDs.clear();
    theList2.clear();


    int paperCount = 0;

    bool check = false;
    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
        for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
            if(all_the_stuff.getLocations()[i].getPaperID() ==  the_other_stuff.getLocations()[j].getPaperID()){

                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);
                break;
            }

        }
    }
    if(theList.getSize() < 10){
        cout << "Top Results For: " << all_the_stuff.getWord() << " or " << the_other_stuff.getWord() << endl;
        for (int i = 1; i < theList.getSize(); ++i) {
            int j = i;
            while (j > 0 && theList[j] > theList[j - 1]) {
                PaperWordEntry temp = theList[j];
                theList[j] = theList[j - 1];
                theList[j - 1] = temp;
                --j;
            }
        }
        for(int i = 0; i < theList.getSize(); ++i){
            cout << "Paper " << paperCount++ + 1 << endl;
            bool wreck = false;
            while(!wreck){
                wreck = printIndex(theList[i]);
                ++i;
            }

        }
        for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
            PaperWordEntry temp = all_the_stuff.getLocations()[i];
            theList.push_back(temp);
        }
        for(int i = 0; i < the_other_stuff.getLocations().getSize(); ++i){
            PaperWordEntry temp = the_other_stuff.getLocations()[i];
            theList.push_back(temp);
        }
        check = true;
    }
    //sort
    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
            theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    //print
    if(!check)
        cout << "Top Results For: " << all_the_stuff.getWord() << " or " << the_other_stuff.getWord() << endl;

    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount  << " result[s] found, try broadening your search" << endl << endl << endl;
            break;
        }
        cout << "Paper " << paperCount++ + 1 << endl;
        bool wreck = false;
        while(!wreck){
            wreck = printIndex(theList[i]);
            ++i;
        }

    }

}

void IndexHandler::sort_for_miles_and_steveNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff) {
    int paperCount = 0;
    theList.clear();
    usedIDs.clear();
    theList2.clear();
    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
        for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
            if(all_the_stuff.getLocations()[i].getPaperID() ==  the_other_stuff.getLocations()[j].getPaperID()){
                continue;
            }
        }
        theList.push_back(all_the_stuff.getLocations()[i]);
    }
    //sort
    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
            theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    //print
    cout << "Top Results For: " << all_the_stuff.getWord() << " not " << the_other_stuff.getWord() << endl;

    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount  << " result[s] found, try broadening your search" << endl << endl << endl;
            break;
        }
        cout << "Paper " << paperCount++ + 1 << endl;
        cout << "Title: " << theList[i].getTitle() << endl;
        cout << "Paper ID: " << theList[i].getPaperID() << endl;

        cout << endl << endl;
    }
}

void IndexHandler::findWordNot(const DSString &key, const DSString &key2) {
    IndexEntry search_key1 = (key);
    IndexEntry search_key2 = (key2);
    IndexEntry key_from_tree;
    IndexEntry key_from_tree2;
    key_from_tree = findWordIn(search_key1);
    key_from_tree2 = findWordIn(search_key2);
    sort_for_miles_and_steveNot(key_from_tree, key_from_tree2);
}

void IndexHandler::findWordOr(const DSString &key, const DSString &key2) {
    IndexEntry search_key1 = (key);
    IndexEntry search_key2 = (key2);
    IndexEntry key_from_tree;
    IndexEntry key_from_tree2;
    key_from_tree = findWordIn(search_key1);
    key_from_tree2 = findWordIn(search_key2);
    sort_for_miles_and_steveOr(key_from_tree, key_from_tree2);
}

void IndexHandler::sort_for_miles_and_steveAndNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff,
                                                  IndexEntry &stuff_the_third) {
    theList.clear();
    usedIDs.clear();
    theList2.clear();
    int paperCount = 0;
    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
        for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
            if (all_the_stuff.getLocations()[i].getPaperID() ==  stuff_the_third.getLocations()[j].getPaperID()){
                continue;
            }
            if(all_the_stuff.getLocations()[i].getPaperID() ==  the_other_stuff.getLocations()[j].getPaperID()){
                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);
                break;
            }

        }
    }
    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
            theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    cout << "Top Results For: " << all_the_stuff.getWord() << " and " << the_other_stuff.getWord() << " not " << stuff_the_third.getWord() << endl;

    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount  << " result[s] found, try broadening your search" << endl << endl << endl;
            break;
        }
        cout << "Paper " << paperCount++ + 1 << endl;
        cout << "Title: " << theList[i].getTitle() << endl;
        cout << "Paper ID: " << theList[i].getPaperID() << endl;

        cout << endl << endl;
    }
}

void IndexHandler::findWordAndNot(const DSString &key, const DSString &key2, const DSString &key3) {
    IndexEntry search_key1 = (key);
    IndexEntry search_key2 = (key2);
    IndexEntry search_key3 = (key3);
    IndexEntry key_from_tree;
    IndexEntry key_from_tree2;
    IndexEntry key_from_tree3;
    key_from_tree = findWordIn(search_key1);
    key_from_tree2 = findWordIn(search_key2);
    key_from_tree3 = findWordIn(search_key3);
    sort_for_miles_and_steveAndNot(key_from_tree, key_from_tree2, key_from_tree3);
}

void IndexHandler::clearAVL() {
    theIndex.clear();
}

void IndexHandler::sort_for_miles_and_steveOrNot(IndexEntry &all_the_stuff, IndexEntry &the_other_stuff,
                                                 IndexEntry &stuff_the_third) {
    bool check = false;
    theList.clear();
    usedIDs.clear();
    theList2.clear();
    int paperCount = 0;
    for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
        for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
            if (all_the_stuff.getLocations()[i].getPaperID() ==  stuff_the_third.getLocations()[j].getPaperID()){
                continue;
            }
            if(all_the_stuff.getLocations()[i].getPaperID() ==  the_other_stuff.getLocations()[j].getPaperID()){
                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);
                break;
            }

        }
    }
    if(theList.getSize() < 10){
        cout << "Top Results For: " << all_the_stuff.getWord() << " or " << the_other_stuff.getWord() << " not "
             << stuff_the_third.getWord() << endl;
        for (int i = 1; i < theList.getSize(); ++i) {
            int j = i;
            while (j > 0 && theList[j] > theList[j - 1]) {
                PaperWordEntry temp = theList[j];
                theList[j] = theList[j - 1];
                theList[j - 1] = temp;
                --j;
            }
        }
        for(int i = 0; i < theList.getSize(); ++i){
            cout << "Paper " << paperCount++ + 1<< endl;
            bool wreck = false;
            while(!wreck){
                wreck = printIndex(theList[i]);
                ++i;
            }

        }
        for(int i = 0; i < all_the_stuff.getLocations().getSize(); ++i){
            for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
                if (all_the_stuff.getLocations()[i].getPaperID() ==  stuff_the_third.getLocations()[j].getPaperID()){
                    continue;
                }
                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);
            }
        }
        for(int i = 0; i < the_other_stuff.getLocations().getSize(); ++i){
            for(int j = 0; j < the_other_stuff.getLocations().getSize(); ++j) {
                if (all_the_stuff.getLocations()[i].getPaperID() ==  stuff_the_third.getLocations()[j].getPaperID()){
                    continue;
                }
                PaperWordEntry temp = all_the_stuff.getLocations()[i];
                theList.push_back(temp);
            }
            PaperWordEntry temp = the_other_stuff.getLocations()[i];
            theList.push_back(temp);
        }
        check = true;
    }

    for (int i = 1; i < theList.getSize(); ++i) {
        int j = i;
        while (j > 0 && theList[j] > theList[j - 1]) {
            PaperWordEntry temp = theList[j];
            theList[j] = theList[j - 1];
            theList[j - 1] = temp;
            --j;
        }
    }
    if(!check) {
        cout << "Top Results For: " << all_the_stuff.getWord() << " or " << the_other_stuff.getWord() << " not "
             << stuff_the_third.getWord() << endl;
    }
    for(int i = 0; paperCount < 10; ++i) {
        if (theList[i].getTitle() == ""){
            cout << "Only " << paperCount << " result[s] found, try broadening your search" << endl << endl << endl;
            break;

        }
        cout << "Paper " << ++paperCount << endl;
        bool wreck = false;
        while(!wreck){
        wreck = printIndex(theList[i]);
            ++i;
        }

    }
}

void IndexHandler::findWordOrNot(const DSString &key, const DSString &key2, const DSString &key3) {
    IndexEntry search_key1 = (key);
    IndexEntry search_key2 = (key2);

    IndexEntry search_key3 = (key3);
    IndexEntry key_from_tree;
    IndexEntry key_from_tree2;
    IndexEntry key_from_tree3;
    key_from_tree = findWordIn(search_key1);
    key_from_tree2 = findWordIn(search_key2);
    key_from_tree3 = findWordIn(search_key3);
    sort_for_miles_and_steveOrNot(key_from_tree, key_from_tree2, key_from_tree3);
}








