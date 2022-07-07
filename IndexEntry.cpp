/**
 * Created by Steve Ntare on 6/23/2021.
 * Edited by Miles on 6/25/2021: Added '==' operator
*/

#include "IndexEntry.h"

IndexEntry::IndexEntry() {

}

IndexEntry::IndexEntry(const DSString& in, const DSVector<PaperWordEntry>& in2) {
    word = in;
    locations = in2;
}
IndexEntry::IndexEntry(const DSString& in){
    word = in;

}

IndexEntry::IndexEntry(const DSString& in, const PaperWordEntry& in2) {
    word = in;
    locations.push_back(in2);
}

void IndexEntry::setLocations(const DSVector<PaperWordEntry>& in) {
    locations = in;
}

void IndexEntry::setWord(const DSString& in) {
    word = in;
}

DSVector<PaperWordEntry>& IndexEntry::getLocations() {
    return locations;
}

DSString& IndexEntry::getWord() {
    return word;
}

void IndexEntry::locationPush(const PaperWordEntry& in) {
    locations.push_back(in);
}


bool IndexEntry::operator==(const IndexEntry &arg) {
    if(getWord() == arg.word){
        return true;
    }else{
        return false;
    }
}

void IndexEntry::print() {
    for(int i = 0; i < locations.getSize(); ++i){

        locations[i].print();
        cout << endl << endl;
    }
}

bool IndexEntry::operator<(const IndexEntry &arg) {
    if(word < arg.word){
        return true;
    }
    return false;
}
bool IndexEntry::operator>(const IndexEntry &arg) {
    if(word < arg.word){
        return false;
    }
    return true;
}

std::ostream &operator<<(ostream &os, const IndexEntry &dt) {
    os << dt.word << endl;
    return os;
}

IndexEntry &IndexEntry::operator=(const IndexEntry &arg) {
    word = arg.word;
    locations = arg.locations;
    return *this;
}
