/**
 * Author: Miles Friedman
 * Created 6/23
 */
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include <stdio.h>
#include <string.h>
#include "DSHashtable.h"
#include "DSString.h"
#include <map>
#include "docudata.h"
#include "AVLTree.h"
#include "IndexEntry.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/Writer.h"
using namespace std;
namespace fs = std::filesystem;
using namespace rapidjson;
#ifndef SU21_SRCH_ENG_MILES_AND_STEVE_PARSER_H
#define SU21_SRCH_ENG_MILES_AND_STEVE_PARSER_H


class parser {
private:
    int authorcounter = 0;
    DSVector<IndexEntry> entries;
    DSVector<docudata> parsedInfo;
    DSString filename = "/Users/yeet/Documents/GitHub/su21-srch-eng-miles-and-steve/ds_01/954d000b2e7252ffb05812341a6436d3d784494a.json";
    DSString pathname = "/Users/yeet/Documents/GitHub/su21-srch-eng-miles-and-steve/ds_01";

public:
    parser() {

    }

    parser(DSString file, DSString path) {
        filename = file;
        pathname = path;
    }

    /**
     *
     * @param filepath
     * given a file this method parses the file
     */
    void Parse(DSString file);

    /**
     *
     * @return the DSString filename
     */
    DSString& getFile() { return filename; }

    /**
     *
     * @return the DSString pathname
     */
    DSString& getPath() { return pathname; }

    /**
     *
     * @param file set to filename
     */
    void setFile(DSString file);

    /**
     *
     * @param path set to pathname
     */
    void setPath(DSString path);

    /**
     *
     * @param path
     * gives individual file paths to be parsed
     */
    void open_dir(DSString path);

    /**
     *
     * @return parsedInfo vector
     */
    DSVector<docudata> &getParsedInfo() { return parsedInfo; }

    /**
     *
     * @return entries vector
     */
    DSVector<IndexEntry> &getEntries() { return entries; }

    /**
     * Turns DocuData info into IndexEntry info
     */
    void createIndexEntries();

    /**
     * Prints IndexEntry info
     */
    void printEntries();
    /**
     * Inserts the authors from the docudata vector into authorList
     */
    int getAvgWords();
    void clear();
    int getAuthorCount(){return authorcounter;}


};

#endif //SU21_SRCH_ENG_MILES_AND_STEVE_PARSER_H
