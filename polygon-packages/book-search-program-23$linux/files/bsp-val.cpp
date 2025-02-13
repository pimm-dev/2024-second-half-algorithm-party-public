#include "testlib.h"
#include <string>
#include <vector>
#include <set>
#include <format>

using namespace std;

bool isValidStr(const string& s) {
    for (char c : s) {
        if (!isalnum(c) && c != '-' && c != '_') {
            return false;
        }
    }
    return true;
}

bool isValidMethods(const string& methods);  // Forward declaration

bool isValidMethod(const string& method) {
    if (method.empty()) return false;
    
    if (method[0] == 'A' || method[0] == 'O') {
        if (method.size() < 4 || method[1] != '(' || method.back() != ')') return false;
        return isValidMethods(method.substr(2, method.size() - 3));
    }
    
    else if (method[0] == 'N') {
        if (method.size() < 4 || method[1] != '(' || method.back() != ')') return false;
        return isValidMethod(method.substr(2, method.size() - 3));
    }
    
    else if (method.substr(0, 2) == "n:" || method.substr(0, 3) == "ni:" || 
        method.substr(0, 2) == "a:" || method.substr(0, 2) == "t:") {
        string content = method.substr(method.find(":") + 1);
        ensuref(content.length() <= 20, "name, author and tag shuold not exceed 20 characters");
        return isValidStr(content);
    }
    
    return false;
}

bool isValidMethods(const string& methods) {
    vector<string> parts;
    int depth = 0;
    string current;
    
    for (char c : methods) {
        if (c == '(') depth++;
        if (c == ')') depth--;
        
        if (c == ',' && depth == 0) {
            if (!current.empty()) {
                parts.push_back(current);
                current.clear();
            }
        } else if (c != ' ') {
            current += c;
        }
    }
    
    if (!current.empty()) {
        parts.push_back(current);
    }
    
    for (const string& part : parts) {
        if (!isValidMethod(part)) return false;
    }
    
    return true;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 200, "N");
    inf.readEoln();

    set<pair<string, string>> books;

    for (int i = 0; i < N; i++) {
        string line = inf.readLine();
        vector<string> parts = split(line, ' ');
        
        ensuref(parts.size() >= 2, "Each book should have at least name and author");
        ensuref(line.length() <= 200, "Book information should not exceed 200 characters");
        
        for (string part : parts) {
            ensuref(part.size() <= 20, "name, author and tag shuold not exceed 20 characters");
        }
        
        string name = parts[0];
        string author = parts[1];
        
        ensuref(isValidStr(name), "Invalid book name");
        ensuref(isValidStr(author), "Invalid author name");
        
        ensuref(books.count({name, author}) == 0, "Duplicate book found");
        books.insert({name, author});

        for (size_t j = 2; j < parts.size(); j++) {
            ensuref(isValidStr(parts[j]), "Invalid tag");
        }
    }

    int M = inf.readInt(1, 500, "M");
    inf.readEoln();

    for (int i = 0; i < M; i++) {
        string search = inf.readLine();
        ensuref(search.length() <= 500, "Search string should not exceed 500 characters");
        for (int i = 0; i < search.size() - 1; i++) {
            if (search[i] == ',') {
                ensuref(search[i+1] == ' ', "No space string after comma");
            }
        }
        ensuref(isValidMethods(search), "Invalid search string");
    }
    
    inf.readEof();

    return 0;
}
