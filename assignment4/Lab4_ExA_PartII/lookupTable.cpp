#include "lookupTable.h"
/*
 * lookupTable.cpp
 *  ENSF 694 Lab 4, exercise A part II
 *  Created by Mahmood Moussavi
 *  Completed by: John Zhou
 */
LT_Node::LT_Node(const Pair &pairA, LT_Node *nextA) : pairM(pairA), nextM(nextA)
{
}
LookupTable::LookupTable() : sizeM(0), headM(nullptr), cursorM(nullptr)
{
}

LookupTable::LookupTable(const LookupTable &source) : headM(nullptr), cursorM(nullptr), sizeM(source.sizeM)
{

    if (source.headM == nullptr)
    {
        return;
    }

    headM = new LT_Node(source.headM->pairM, nullptr);

    LT_Node *sourcePtr = source.headM->nextM;
    LT_Node *destPtr = headM;
    if (source.cursorM == source.headM)
    {
        cursorM = headM;
    }

    while (sourcePtr != nullptr)
    {
        destPtr->nextM = new LT_Node(sourcePtr->pairM, nullptr);

        if (source.cursorM == sourcePtr)
        {
            cursorM = destPtr->nextM;
        }
        destPtr = destPtr->nextM;
        sourcePtr = sourcePtr->nextM;
    }
}
LookupTable &LookupTable::operator=(const LookupTable &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    LT_Node *current = headM;
    while (current != nullptr)
    {
        LT_Node *temp = current;
        current = current->nextM;
        delete temp;
    }
    headM = new LT_Node(rhs.headM->pairM, nullptr);

    LT_Node *rhsPtr = rhs.headM->nextM;
    LT_Node *destPtr = headM;
    if (rhs.cursorM == rhs.headM)
    {
        cursorM = headM;
    }

    while (rhsPtr != nullptr)
    {
        destPtr->nextM = new LT_Node(rhsPtr->pairM, nullptr);

        if (rhs.cursorM == rhsPtr)
        {
            cursorM = destPtr->nextM;
        }
        destPtr = destPtr->nextM;
        rhsPtr = rhsPtr->nextM;
    }
    sizeM = rhs.sizeM;

    return *this;
}
LookupTable::~LookupTable()
{
    LT_Node *current = headM;
    while (current != nullptr)
    {
        LT_Node *temp = current;
        current = current->nextM;
        delete temp;
    }
}
LookupTable &LookupTable::begin()
{
    cursorM = headM;
    return *this;
}

int LookupTable::size() const
{
    return sizeM;
}

int LookupTable::cursor_ok() const
{
    return cursorM == nullptr ? 0 : 1;
}

const int &LookupTable::cursor_key() const
{

    return cursorM->pairM.key;
}
const Type &LookupTable::cursor_datum() const
{
    return cursorM->pairM.datum;
}
void LookupTable::insert(const Pair &pairA)
{

    LT_Node *current = headM;
    cursorM = nullptr;
    while (current != nullptr)
    {
        if (current->pairM.key == pairA.key)
        {

            current->pairM.datum = pairA.datum;

            return;
        }
        current = current->nextM;
    }
    LT_Node *newElement = new LT_Node(pairA, nullptr);
    if (headM == nullptr || pairA.key < headM->pairM.key)
    {
        newElement->nextM = headM;
        headM = newElement;
    }
    else
    {
        LT_Node *prevNode = headM;
        while (prevNode->nextM != nullptr && prevNode->nextM->pairM.key < pairA.key)
        {
            prevNode = prevNode->nextM;
        }
        newElement->nextM = prevNode->nextM;
        prevNode->nextM = newElement;
    }

    sizeM++;
}

int LookupTable::remove(const int &keyA)
{
    LT_Node *prev = nullptr;
    LT_Node *current = headM;

    while (current != nullptr)
    {
        if (current->pairM.key == keyA)
        {
            if (prev == nullptr)
            {
                headM = current->nextM;
            }
            else
            {
                prev->nextM = current->nextM;
            }
            delete current;
            sizeM--;
            cursorM = nullptr;
            return keyA;
        }
        prev = current;
        current = current->nextM;
    }

    cursorM = nullptr;
    return 0;
}

void LookupTable::find(const int &keyA)
{
    LT_Node *current = headM;
    while (current != nullptr)
    {
        if (current->pairM.key == keyA)
        {
            cursorM = current;
            return;
        }
        current = current->nextM;
    }
    cursorM = nullptr;
}

void LookupTable::go_to_first()
{
    if (sizeM > 0)
    {
        cursorM = headM;
    }
    else
    {
        cursorM = nullptr;
    }
}

void LookupTable::step_fwd()

{
    if (!cursor_ok())
    {
        return;
    }
    if (cursorM->nextM != nullptr)
    {
        cursorM = cursorM->nextM;
    }
    else
    {
        cursorM = nullptr;
    }
}

void LookupTable::make_empty()
{
    LT_Node *current = headM;
    while (current != nullptr)
    {
        LT_Node *temp = current;
        current = current->nextM;
        delete temp;
    }
    headM = nullptr;
    cursorM = nullptr;
    sizeM = 0;
}

void LookupTable::display() const
{
    LT_Node *current = headM;
    while (current != nullptr)
    {
        std::cout << current->pairM.key << "x = " << current->pairM.datum.getx() << "y= " << current->pairM.datum.gety() << "label = " << current->pairM.datum.get_label() << endl;
        
        current = current->nextM;
    }
    std::cout << std::endl;
}


bool LookupTable::isEmpty() const
{
    return sizeM == 0;
}

int *LookupTable::retrieve_at(int i)
{
    if (i < 0 || i >= sizeM)
    {
        return nullptr;
    }

    LT_Node *current = headM;
    int count = 0;
    while (current != nullptr && count < i)
    {
        current = current->nextM;
        count++;
    }

    if (current != nullptr)
    {
        return &(current->pairM.key);
    }
    else
    {
        return nullptr;
    }
}
