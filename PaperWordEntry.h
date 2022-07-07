/**
 *
 * Created by Steve Ntare on 6/23/2021.
 * Miles Update 6/24: Added word DSString
 **/
#include "DSString.h"
#include "DSVector.h"
#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_PAPERWORDENTRY_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_PAPERWORDENTRY_H


class PaperWordEntry {
private:
    DSString word;
    DSString paperID;
    DSVector<int> locs;
    DSString title;
public:
    PaperWordEntry();
    /**
     *
     * @param in will be set to paperID
     * @param in2 will be set to locs vector
     */
    PaperWordEntry(const DSString& in, const DSVector<int>& in2);
    /**
     *
     * @param in will be set to paperID
     */
    PaperWordEntry(const DSString& in,const DSString& in2, int in3, const DSString& in4);
    /**
     *
     * @param in will be set to paperID
     */
    void setPaperID(const DSString& in);
    /**
     *
     * @param in will be set to locs vector
     */
    void setLocs(const DSVector<int>& in);
    /**
     *
     * @param in will be set to word
     */
    void setWord(const DSString& in);
    /**
     *
     * @return paperID
     */
    DSString& getPaperID();
    /**
     *
     * @return locs vector
     */
    DSVector<int>& getLocs();
    /**
     *
     * @return word
     * CONST ERROR TANGENT WITH operator== being const
     */
     DSString& getWord(){return word;}
    /**
     *
     * @param in is an integer that gets pushed back into the locs vector
     */
    void locsPush(int in);
    /**
     *
     * @param arg
     * @return true if arg.word == this.word else false
     */
    bool operator== (const PaperWordEntry& arg);
    /**
     *
     * @param arg
     * @return true if arg.locs size is > this.locs size
     */
    bool operator<(PaperWordEntry& arg);
    bool operator>(PaperWordEntry& arg);
    /**
     *
     * @param arg
     * @return sets this object's contents = to arg's
     */
    PaperWordEntry& operator= (const PaperWordEntry& arg);
    void print();
    DSString& getTitle(){return title;}

};


#endif //SU21_SRCH_ENG_MILES_AND_STEVE_PAPERWORDENTRY_H