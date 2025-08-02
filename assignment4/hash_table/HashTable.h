
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"
#include "Flight.h"
#include <string>

class HashTable
{
private:
    List **table; // Array of pointers to List objects (buckets)
    int tableSize;
    int totalRecords;
    int nonCollisionCount; // counter to track number of non-collison records
    // int elementsUsed;      // the number of elements of the table that are use

    // Simple hash function
    int hashFunction(const std::string &flightID) const;
    // REQUIRES: flightID is a non-empty string
    // PROMISES: - Computes a hash value based on the sum of the ASCII values of all characters in flightID.
    //           - The resulting hash value is then reduced modulo tableSize to ensure it fits within the bounds of the table.

public:
    HashTable(int size);
    // REQUIRES: size > 0
    // PROMISES: - Initializes a hash table with 'size' buckets.
    //           - All buckets are initially set to nullptr.
    //           - Initializes totalRecords and nonCollisionCount to 0.
    ~HashTable();
    // PROMISES: - Deletes all lists stored in the table and the table array itself.
    void insert(const Flight &flight);
    // REQUIRES: flight is a valid Flight object.
    // PROMISES: - Computes the hash index for the flight's ID using the hash function
    //           - Inserts the flight into the corresponding list (chaining).

    Flight *search(const std::string &flightID) const;
    // REQUIRES: flightID is a non-empty string.
    // PROMISES: - Computes the hash index for flightID.
    //           - Searches through the chain (linked list) at that index.
    //           - Returns a pointer to the found Flight object, or nullptr if not found.

    void printTable() const;
    // PROMISES: - Prints statistics about the hash table.
    //           - Prints the list of flights at each non-empty bucket index.

    int getTableSize() const { return tableSize; };
    // PROMISES: Returns the size of the hash table (number of buckets).

    int getTotalRecords() const { return totalRecords; };
    // PROMISES: Returns the total number of flight records inserted into the hash table.

    double getNonCollisionEfficiency() const;
    // PROMISES: - Calculates and returns the ratio of records that did not experience collisions.
    //           - Formula: nonCollisionCount / totalRecords.

    int calculateTotalSearchCost() const;
    // PROMISES: - Calculates and returns the total cost of searching all records.
    //           - For each bucket, adds the length of its chain to the total search cost.

    double getTableDensity() const;
    // PROMISES: - Calculates and returns the table density.
    //           - Formula: number of non-empty buckets / tableSize.

    double getPackingDensity() const;
    // PROMISES: - Calculates and returns the packing density.
    //           - Formula: totalRecords / tableSize.

    double getHashEfficiency() const;
    // PROMISES: - Calculates and returns the hash efficiency.
    //           - Formula: Packing Density / Average number of reads per record.
};

#endif
