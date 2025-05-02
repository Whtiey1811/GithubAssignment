#include <tinyxml2.h>
#include <iostream>
#include <stdio.h>

using namespace tinyxml2;

int main() {
    XMLDocument doc;
    doc.LoadFile("catalog.xml");
    
    XMLElement* root = doc.FirstChildElement("catalog");
    if (root == nullptr) {
        std::cerr << "No catalog element found." << std::endl;
        return 1;
    }

    for (XMLElement* book = root->FirstChildElement("book"); book != nullptr; book = book->NextSiblingElement("book")) {
        const char* title = book->FirstChildElement("title")->GetText();
        if (title) {
            std::cout << "Book title: " << title << std::endl;
        }
    }

    return 0;
}
