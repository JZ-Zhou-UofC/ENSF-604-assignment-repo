#include "HashTable.h"
#include "Node.h"
#include "List.h"
#include "Flight.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

HashTable::HashTable(int size)
{
    tableSize = size;
    totalRecords = 0;
    nonCollisionCount = 0;

    table = new List *[tableSize];
    for (int i = 0; i < tableSize; ++i)
    {
        table[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; ++i)
    {
        delete table[i];
    }
    delete[] table;
}

int HashTable::hashFunction(const string &flightID) const
{
    int hashValue = 0;
    for (char ch : flightID)
    {
        hashValue += (int)ch;
    }
    return hashValue % tableSize;
}

void HashTable::insert(const Flight &flight)
{
    int index = hashFunction(flight.getFlightID());

    if (table[index] == nullptr)
    {
        table[index] = new List();
    }

    table[index]->insert(flight);
    totalRecords++;

    if (table[index]->getSize() == 1)
    {
        nonCollisionCount++;
    }
}

Flight *HashTable::search(const string &flightID) const
{
    int index = hashFunction(flightID);

    if (table[index] != nullptr)
    {

        Node *foundNode = table[index]->search(flightID);

        if (foundNode != nullptr)
        {
            return &foundNode->data;
        }
    }

    return nullptr;
}

void HashTable::printTable() const
{
    // Printing hash table statistics
    cout << "Total records: " << getTotalRecords() << endl;
    cout << "Table size: " << this->getTableSize() << endl;
    cout << "Packing density: " << getPackingDensity() << endl;
    cout << "Table density: " << this->getTableDensity() << endl;
    cout << "Hash efficiency: " << this->getHashEfficiency() << endl;

    for (int i = 0; i < tableSize; ++i)
    {
        if (table[i] == nullptr)
        {
            cout << "bucket " << i << ": is empty \n";
        }
        else
        {
            cout << "bucket " << i << ": ";
            table[i]->printList();
        }
    }
}

double HashTable::getNonCollisionEfficiency() const
{
    return (double)nonCollisionCount / totalRecords;
}

int HashTable::calculateTotalSearchCost() const
{
    int totalCost = 0;

    for (int i = 0; i < tableSize; ++i)
    {

        if (table[i] != nullptr)
        {

            totalCost += table[i]->getSize();
        }
    }

    return totalCost;
}

double HashTable::getTableDensity() const
{
    int nonEmptyBuckets = 0;
    for (int i = 0; i < tableSize; ++i)
    {
        if (table[i] != nullptr)
        {
            nonEmptyBuckets++;
        }
    }
    return (double)(nonEmptyBuckets) / tableSize;
}

double HashTable::getPackingDensity() const
{
    return (double)totalRecords / tableSize;
}

double HashTable::getHashEfficiency() const
{
    double packingDensity = getPackingDensity();
    double avgReads = (double)calculateTotalSearchCost() / totalRecords;
    return packingDensity / avgReads;
}
