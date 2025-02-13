#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// 유효한 문자를 생성하는 함수
char getValidChar() {
    const string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
    return validChars[rnd.next(validChars.length())];
}

// 유효한 문자열을 생성하는 함수
string getValidString(int maxLength) {
    int length = rnd.next(1, maxLength);
    string result;
    for (int i = 0; i < length; i++) {
        result += getValidChar();
    }
    return result;
}

// book을 생성하는 함수
string generateBook(int bookMaxLength, int tagMaxLength) {
    string name = getValidString(tagMaxLength);
    string author = getValidString(tagMaxLength);
    string book = name + " " + author;
    
    // 남은 공간을 태그로 채움
    while (book.length() < bookMaxLength) {
        string tag = getValidString(min(tagMaxLength, bookMaxLength - (int)book.length() - 1));
        if (book.length() + tag.length() + 1 <= bookMaxLength) {
            book += " " + tag;
        } else {
            break;
        }
    }
    
    return book;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int N = atoi(argv[1]);
    int bookMaxLength = atoi(argv[2]);
    int tagMaxLength = atoi(argv[3]);
    
    set<string> uniqueBooks;
    
    cout << N << endl;
    
    while (uniqueBooks.size() < N) {
        string book = generateBook(bookMaxLength, tagMaxLength);
        if (uniqueBooks.find(book) == uniqueBooks.end()) {
            uniqueBooks.insert(book);
            cout << book << endl;
        }
    }
    
    return 0;
}
