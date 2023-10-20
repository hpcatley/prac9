#include "DocumentManager.h"

Document::Document(std::string n, int i, int l) : name(n), id(i), license_limit(l), borrowed_count(0) {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
    Document doc(name, id, license_limit);
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
    if(patrons.find(patronID) == patrons.end() || 
       documentIDs.find(docid) == documentIDs.end() || 
       documentIDs[docid].borrowed_count >= documentIDs[docid].license_limit) {
        return false;
    }

    documentIDs[docid].borrowed_count++;
    patron_borrowed_docs[patronID].insert(docid);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if(patron_borrowed_docs[patronID].find(docid) != patron_borrowed_docs[patronID].end()) {
        documentIDs[docid].borrowed_count--;
        patron_borrowed_docs[patronID].erase(docid);
    }
}