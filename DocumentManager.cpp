#include "DocumentManager.h"

Document::Document() {}


Document::Document(std::string n, int i, int l) {
    name = n;
    id = i;
    licenseLimit = l;
    borrowedCount = 0;
}

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
    if(patrons.find(patronID) == patrons.end() || 
       documentIDs.find(docid) == documentIDs.end() || 
       documentIDs[docid].borrowedCount >= documentIDs[docid].licenseLimit) {
        return false;
    }

    documentIDs[docid].borrowedCount++;
    borrowedDocs[patronID].insert(docid);
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
if(borrowedDocs[patronID].find(docid) != borrowedDocs[patronID].end()) {
        documentIDs[docid].borrowedCount--;
        borrowedDocs[patronID].erase(docid);
    }
}