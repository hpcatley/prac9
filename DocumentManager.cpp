#include "DocumentManager.h"

Document::Document(std::string n, int i, int l) : name(n), id(i), licenseLimit(l), borrowedCount(0) {}

void DocumentManager::addDocument(std::string name, int id, int licenseLimit) {
    Document doc(name, id, licenseLimit);
    documentNames[name] = doc;
    documentIDs[id] = doc;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name) {
    if(documentNames.find(name) != documentNames.end()) {
        return documentNames[name].id;
    }
    return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {

}

void DocumentManager::returnDocument(int docid, int patronID) {

}