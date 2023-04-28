#pragma once

#include <fstream>
#include <string>
#include <map>

using namespace std;

// <phone>|<name>

map<string, string> ImportFromFile(string path) {
    map<string, string> result;

    ifstream file;
    file.open(path);

    string line;
    while (getline(file, line)) {
        int position = line.find('|');
        string phone = line.substr(0, position);
        string name = line.substr(position + 1);

        result.insert(pair<string, string>(phone, name));
    }

    file.close();

    return result;
}

void ExportToFile(string path, map<string, string>& phoneBook) {
    ofstream file;
    file.open(path);

    for (auto item : phoneBook) {
        file << item.first << "|" << item.second << endl;
    }

    file.close();
}
