
//
// Created by Steve Ntare on 6/25/2021.
//

#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_DSHASHTABLE_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_DSHASHTABLE_H
#define DEBUG true
#include "DSVector.h"
#include <iomanip>
using namespace std;

template<class K, class V>
class DSHashTable {
private:
    struct Entry{
        K key;
        V value;
        Entry(){}
        Entry(K k, V v): key(k), value(v){}
    };
    DSVector<Entry>* table = nullptr;
    int num_elements = 0;
    int table_size = 0;
public:
    DSHashTable(){
        table_size = 100;
        table = new DSVector<Entry> [table_size];
    }
    ~DSHashTable(){
        delete[] table;
        num_elements = 0;
        table_size = 100;
    }
    void insert (const K& theKey, const V& theValue) {
        auto hash_value = std::hash<K>{}(theKey);
        unsigned long location = hash_value % table_size;
        Entry e(theKey, theValue);
        if(DEBUG) cout << "hash value is " << hash_value << ", loc " << location << endl;
        table[location].push_back(e);
        num_elements++;
    }
    V& get_value(const K& theKey){
        unsigned long location = std::hash<K>{}(theKey) % table_size;
        bool found = false;
        for (auto e : table[location]){
            if(DEBUG) std::cout << e.value << std::endl;
            if(e.key == theKey){
                return e.value;
            }
        }
        if(!found){
            if(DEBUG) cout << "Did not find " << theKey << " in this hash table.";
        }
    }
};


#endif //SU21_SRCH_ENG_MILES_AND_STEVE_DSHASHTABLE_H