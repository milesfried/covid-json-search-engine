/**
 * Created by Steve Ntare on 6/23/2021.
*/

#include "PaperWordEntry.h"

PaperWordEntry::PaperWordEntry() {

}

PaperWordEntry::PaperWordEntry(const DSString& in, const DSVector<int>& in2) {
    paperID = in;
    locs = in2;
}

PaperWordEntry::PaperWordEntry(const DSString& in,const DSString& in2, int in3,  const DSString& in4) {
    paperID = in;
    word = in2;
    locs.push_back(in3);
    title = in4;
}



void PaperWordEntry::setPaperID(const DSString& in) {
    paperID = in;
}

void PaperWordEntry::setLocs(const DSVector<int>& in) {
    locs = in;
}

DSString& PaperWordEntry::getPaperID() {
    return paperID;
}

DSVector<int>& PaperWordEntry::getLocs() {
    return locs;
}

void PaperWordEntry::locsPush(int in) {
    locs.push_back(in);
}

void PaperWordEntry::setWord(const DSString& in) {
    word = in;
}

bool PaperWordEntry::operator==(const PaperWordEntry &arg) {
    if(getWord() == arg.word){
        return true;
    }else{
        return false;
    }
}



void PaperWordEntry::print() {
    cout << "Word: " << word << endl;
    cout << "Paper ID: " << paperID << endl;
    cout << "Locations: ";
    for(int i = 0; i < locs.getSize(); ++i){
        cout << locs[i] << endl;
    }
}

PaperWordEntry& PaperWordEntry::operator=(const PaperWordEntry &arg) {
    word = arg.word;
    paperID = arg.paperID;
    locs = arg.locs;
    title = arg.title;
    return *this;
}

bool PaperWordEntry::operator<(PaperWordEntry &arg) {
    if(getLocs().getSize() < arg.getLocs().getSize()){
        return true;
    }
    return false;
}
bool PaperWordEntry::operator>(PaperWordEntry &arg) {
    if(getLocs().getSize() < arg.getLocs().getSize()){
        return false;
    }
    return true;
}
