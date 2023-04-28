#pragma once

#include <string>
#include <map>

using namespace std;

void Insert(map<string, string> &phoneBook, string phone, string name) {
    phoneBook.insert(pair<string, string>(phone, name));
}

void UpdateName(map<string, string> &phoneBook, string phone, string name) {
    if (phoneBook.find(phone) != phoneBook.end()) {
        phoneBook[phone] = name;
    }
}

void UpdatePhone(map<string, string> &phoneBook, string old_phone, string new_phone) {
    auto iter = phoneBook.find(old_phone);
    if (iter != phoneBook.end()) {
        string name = iter->second;
        phoneBook.erase(iter);
        phoneBook[new_phone] = name;
    } else {
        cout << "Ошибка: телефон " << old_phone << " не найден." << endl;
    }
}

void Delete(map<string, string> &phoneBook, string phone) {
    phoneBook.erase(phone);
}

string FindByPhone(map<string, string> &phoneBook, string phone) {
    auto iter = phoneBook.find(phone);
    if (iter != phoneBook.end()) {
        return iter->second;
    } else {
        return "Телефон не найден";
    }
}

map<string, string> FindByName(map<string, string> &phoneBook, string name) {
    map<string, string> result;

    for (auto item: phoneBook) {
        if (item.second == name) {
            result.insert(item);
        }
    }

    return result;
}