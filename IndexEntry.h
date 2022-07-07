/**
 * Created by Steve Ntare on 6/23/2021.
*/
#include "DSVector.h"
#include "DSString.h"
#include "PaperWordEntry.h"
#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_INDEXENTRY_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_INDEXENTRY_H


class IndexEntry {
private:
    DSString word;
    DSVector<PaperWordEntry> locations;
public:

    IndexEntry();
    /**
     *
     * @param in will be set to word
     */
    IndexEntry(const DSString& in);

    /**
     *
     * @param in will be set to word
     * @param in2 will be set to vector of locations
     */

    IndexEntry(const DSString& in, const DSVector<PaperWordEntry>& in2);
    /**
     *
     * @param in is set to word
     * @param in2 is pushed back into the vector of locations
     */
    IndexEntry(const DSString& in,const PaperWordEntry& in2);
    /**
     *
     * @param in will be set to vector of locations
     */
    void setLocations(const DSVector<PaperWordEntry>& in);
    /**
     *
     * @param in will be set to word
     */
    void setWord(const DSString& in);
    /**
     *
     * @return locations vector
     */
    DSVector<PaperWordEntry>& getLocations();
    /**
     *
     * @return word
     */
    DSString& getWord();
    /**
     *
     * @param in is a PaperWordEntry object that gets pushed back into the location vector
     */
    void locationPush(const PaperWordEntry& in);

    void print();
    /**
     * cant be const
     * @param arg
     * @return
     */
    bool operator==(const IndexEntry &arg);
    /**
     * overwritten relational less than operator
     * @param arg
     * @return
     */
    bool operator<(const IndexEntry&arg);
    /**
     * overwritten greater than operator
     * @param arg
     * @return
     */
    bool operator>(const IndexEntry&arg);
    /**
     * overloaded ostream operator
     * @param os
     * @param dt
     * @return
     */
    friend std::ostream& operator<<(ostream& os, const IndexEntry& dt);
    IndexEntry& operator=(const IndexEntry&arg);

};


#endif //SU21_SRCH_ENG_MILES_AND_STEVE_INDEXENTRY_H