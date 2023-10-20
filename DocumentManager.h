#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <unordered_map>
#include <string>
#include <set>

class Document {
public:
    std::string name;
    int id;
    int licenseLimit;
    int borrowedCount;

    Document();
    Document(std::string n, int i, int l);
};

class DocumentManager {
private:
    std::unordered_map<std::string, Document> documentNames;
    std::unordered_map<int, Document> documentIDs;
    std::set<int> patrons;
    std::unordered_map<int, std::set<int>> borrowedDocs;

public:
    void addDocument(std::string name, int id, int license_limit);
    void addPatron(int patronID);
    int search(std::string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);
};

#endif