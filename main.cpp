/**
 * Author: Miles Friedman & Steve Ntare
 * Created: 6/20/21
 */
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include "DSString.h"
#include "parser.h"
#include <map>
#include "AVLTree.h"
#include "IndexHandler.h"
#include "include/rapidjson/document.h"
#include "include/rapidjson/istreamwrapper.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include <chrono>
#include "Query.h"

using namespace std::chrono;
using namespace std;
namespace fs = std::filesystem;
using namespace rapidjson;






int main(int argc, char**argv) {
    auto start = high_resolution_clock::now();
    Query run;
    run.displayMenu();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Program Run In " << duration.count() / 1000000 << " seconds" << endl;
    return 0;
}
