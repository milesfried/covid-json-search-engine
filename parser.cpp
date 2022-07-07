/**
 * Author: Miles Friedman
 * Created 6/23
 */
#include "parser.h"

void parser::open_dir(DSString path) {
    int x = 0;
    for (const auto & entry : fs::directory_iterator(path.c_str())){
        //if(x++ == 36){
           // break;
        //}
        DSString filepath = entry.path().c_str();
        Parse(filepath);
    }
}

void parser::Parse(DSString file) {
    ifstream ifs(file.c_str());
    IStreamWrapper isw(ifs);

    Document document;
    document.ParseStream(isw);


    DSString paperID = document["paper_id"].GetString();
    DSString titleName = document["metadata"]["title"].GetString();
    docudata temp(paperID, titleName);

//    DSString abstract = document["abstract"][0]["text"].GetString();
//    DSString body_text = document["body_text"]["text"].GetString();
    const rapidjson::Value &body_texts = document["body_text"];
    for (rapidjson::Value::ConstValueIterator itr = body_texts.Begin(); itr != body_texts.End(); ++itr) {
        const rapidjson::Value &body_text = *itr;

        for (rapidjson::Value::ConstMemberIterator itr2 = body_text.MemberBegin();
             itr2 != body_text.MemberEnd(); ++itr2) {
            if (itr2->name.IsString() && itr2->value.IsString()) {
                if (strlen(itr2->value.GetString()) > 0)
                    temp.pushText(itr2->value.GetString());
            }
            itr2++;
        }

    }
    // cout << "\nabstract: \n"<< abstract << endl;
    //cout << "\nbody text: \n" << body_text << endl;



    const rapidjson::Value &attributes = document["metadata"]["authors"];

    assert(attributes.IsArray()); // attributes is an array


    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin(); itr != attributes.End(); ++itr) {
        const rapidjson::Value &attribute = *itr;
        char name[1000] = "";
        for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
            if (itr2->name.IsString() && itr2->value.IsString()) {
                if (strlen(itr2->value.GetString()) > 0) {//this was miles fault
                    strcat(name, itr2->value.GetString()); //fontenot changed strcat to strcpy
                    strcat(name, " ");
                }

            }
        }
        temp.pushAuthor(name);
        authorcounter++;
    }

    temp.Tokenize();
    parsedInfo.push_back(temp);

//    DOM to string
//        StringBuffer buffer;
//        Writer<StringBuffer> writer(buffer);
//        document.Accept(writer);
//        cout << buffer.GetString() << endl;
//    }
}

void parser::setFile(DSString file) {
    filename = file;
}

void parser::setPath(DSString path) {
    pathname = path;
}

void parser::printEntries() {
    for(int i = 0; i < entries.getSize(); ++i){
        entries[i].print();
    }
}

void parser::createIndexEntries() {
    for(int i = 0; i < parsedInfo.getSize(); ++i){
        for (int j = 0; j < parsedInfo[i].getDocs().getSize(); ++j){
            DSString word = parsedInfo[i].getDocs()[j].getWord();
            IndexEntry temp(word, parsedInfo[i].getDocs()[j]);
            if(entries.isFound(temp)){
                int location = entries.find(temp);
                entries[location].locationPush(parsedInfo[i].getDocs()[j]);

            }
            else{
                entries.push_back(temp);

            }
        }
    }
}
int parser::getAvgWords() {
    double avgWords = 0;
    for(int i = 0; i < parsedInfo.getSize(); ++i){
        avgWords += parsedInfo[i].getDocs().getSize();
    }
    avgWords = avgWords / parsedInfo.getSize();
    return avgWords;
}

void parser::clear() {
    entries.clear();
    parsedInfo.clear();
}
