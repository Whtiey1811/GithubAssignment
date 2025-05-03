#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide the XML file as a command line argument." << std::endl;
        return 1;
    }


    XMLDocument doc;
    XMLError eResult = doc.LoadFile(argv[1]);

    if (eResult != XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << eResult << std::endl;
        return 1;
    }


    XMLElement *root = doc.FirstChildElement("catalog");
    if (!root) {
        std::cerr << "Could not find catalog element." << std::endl;
        return 1;
    }

    XMLElement *book = root->FirstChildElement("book");
    while (book) {
        XMLElement *title = book->FirstChildElement("title");
        if (title) {
            std::cout << "Book Title: " << title->GetText() << std::endl;
        }
        book = book->NextSiblingElement("book");
    }

    return 0;
}
