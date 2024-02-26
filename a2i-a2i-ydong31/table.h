/*************************************************************/
/*                                                           */
/*  Starter file for a2                                      */
/*                                                           */
/*  Author Name: Yiyuan Dong                                 */
/*                                                           */
/*************************************************************/

#ifndef table_h
#define table_h

#include "mylist.h"
#include <functional>
#include <string>
#include <utility>
#include <string.h>
#include <cstring>

// MARK: - Table class
template <class TYPE> class Table {
  public:
    Table() {}
    virtual bool insert(const std::string &key, const TYPE &value) = 0;
    virtual bool modify(const std::string &key, const TYPE &value) = 0;
    virtual bool remove(const std::string &key) = 0;
    virtual bool find(const std::string &key, TYPE &value) = 0;
    virtual int numRecords() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int capacity() const = 0;
    virtual ~Table() {}
};

// MARK: - Simple Table
template <class TYPE> class SimpleTable : public Table<TYPE> {

    struct Record {
        TYPE data_;
        std::string key_;
        Record(const std::string &key, const TYPE &data) {
            key_ = key;
            data_ = data;
        }
    };

    Record **records_; // the table
    int capacity_;     // capacity of the array

    void grow() {
        Record **newarray = new Record *[capacity_ * 2 + 1];
        int sz = numRecords();

        for (int i = 0; i < sz; i++) {
            newarray[i] = records_[i];
        }
        capacity_ *= 2;
        delete[] records_;
        records_ = newarray;
    }

  public:
    SimpleTable(int capacity);
    SimpleTable(const SimpleTable &rhs);
    SimpleTable(SimpleTable &&rhs);
    virtual bool insert(const std::string &key, const TYPE &value);
    virtual bool modify(const std::string &key, const TYPE &value);
    virtual bool remove(const std::string &key);
    virtual bool find(const std::string &key, TYPE &value);
    virtual const SimpleTable &operator=(const SimpleTable &rhs);
    virtual const SimpleTable &operator=(SimpleTable &&rhs);
    virtual ~SimpleTable();
    virtual bool isEmpty() const { return numRecords() == 0; }
    virtual int numRecords() const;
    virtual int capacity() const { return capacity_; }
};

template <class TYPE> int SimpleTable<TYPE>::numRecords() const {
    int rc = 0;
    for (int i = 0; records_[i] != nullptr; i++) {
        rc++;
    }
    return rc;
}

template <class TYPE>
SimpleTable<TYPE>::SimpleTable(int capacity) : Table<TYPE>() {
    records_ = new Record *[capacity + 1];
    capacity_ = capacity;
    for (int i = 0; i < capacity_ + 1; i++) {
        records_[i] = nullptr;
    }
}

template <class TYPE>
SimpleTable<TYPE>::SimpleTable(const SimpleTable<TYPE> &rhs) {
    records_ = new Record *[rhs.capacity_ + 1];
    capacity_ = rhs.capacity_;
    for (int i = 0; i < capacity_ + 1; i++) {
        records_[i] = nullptr;
    }
    for (int i = 0; i < rhs.numRecords(); i++) {
        insert(rhs.records_[i]->key_, rhs.records_[i]->data_);
    }
}
template <class TYPE> SimpleTable<TYPE>::SimpleTable(SimpleTable<TYPE> &&rhs) {
    capacity_ = rhs.capacity_;
    records_ = rhs.records_;
    rhs.records_ = nullptr;
    rhs.capacity_ = 0;
}

template <class TYPE>
bool SimpleTable<TYPE>::insert(const std::string &key, const TYPE &value) {
    int idx = -1;
    int sz = numRecords();
    bool rc = false;
    for (int i = 0; i < sz; i++) {
        if (records_[i]->key_ == key) {
            idx = i;
        }
    }
    if (idx == -1) {
        if (sz == capacity_) {
            grow();
        }
        records_[numRecords()] = new Record(key, value);
        for (int i = 0; i < sz - 1; i++) {
            for (int j = 0; j < sz - 1 - i; j++) {
                if (records_[j + 1]->key_ < records_[j]->key_) {
                    Record *tmp = records_[j];
                    records_[j] = records_[j + 1];
                    records_[j + 1] = tmp;
                }
            }
        }
        rc = true;
    }

    return rc;
}

template <class TYPE>
bool SimpleTable<TYPE>::modify(const std::string &key, const TYPE &value) {
    int idx = -1;
    bool rc = false;
    for (int i = 0; i < numRecords(); i++) {
        if (records_[i]->key_ == key) {
            idx = i;
        }
    }
    if (idx != -1) {
        records_[idx]->data_ = value;
    }
    return rc;
}

template <class TYPE> bool SimpleTable<TYPE>::remove(const std::string &key) {
    int idx = -1;
    for (int i = 0; i < numRecords(); i++) {
        if (records_[i]->key_ == key) {
            idx = i;
        }
    }
    if (idx != -1) {
        delete records_[idx];
        for (int i = idx; i < numRecords() - 1; i++) {
            records_[i] = records_[i + 1];
        }
        records_[numRecords() - 1] = nullptr;
        return true;
    } else {
        return false;
    }
}

template <class TYPE>
bool SimpleTable<TYPE>::find(const std::string &key, TYPE &value) {
    int idx = -1;
    int size = numRecords();
    for (int i = 0; i < size; i++) {
        if (records_[i]->key_ == key) {
            idx = i;
        }
    }
    if (idx == -1) {
        return false;
    } else {
        value = records_[idx]->data_;
        return true;
    }
}

template <class TYPE>
const SimpleTable<TYPE> &
SimpleTable<TYPE>::operator=(const SimpleTable<TYPE> &rhs) {
    if (this != &rhs) {
        if (records_) {
            while (numRecords() != 0) {
                remove(records_[0]->key_);
            }
            delete[] records_;
        }
        records_ = new Record *[rhs.capacity_ + 1];
        capacity_ = rhs.capacity_;
        for (int i = 0; i < capacity_; i++) {
            records_[i] = nullptr;
        }
        for (int i = 0; i < rhs.numRecords(); i++) {
            insert(rhs.records_[i]->key_, rhs.records_[i]->data_);
        }
    }
    return *this;
}
template <class TYPE>
const SimpleTable<TYPE> &SimpleTable<TYPE>::operator=(SimpleTable<TYPE> &&rhs) {
    if (records_) {
        while (numRecords() != 0) {
            remove(records_[0]->key_);
        }
        delete[] records_;
    }
    records_ = rhs.records_;
    capacity_ = rhs.capacity_;
    rhs.records_ = nullptr;
    rhs.capacity_ = 0;

    return *this;
}
template <class TYPE> SimpleTable<TYPE>::~SimpleTable() {
    if (records_) {
        int sz = numRecords();
        for (int i = 0; i < sz; i++) {
            remove(records_[0]->key_);
        }
        delete[] records_;
    }
}

// MARK: - Chaining Table
template <class TYPE> class ChainingTable : public Table<TYPE> {
    struct Record {
        TYPE data_;
        std::string key_;

        Record(){};
        Record(const std::string &key, const TYPE &data) {
            key_ = key;
            data_ = data;
        }
        bool &operator==(const Record &other) { return key_ = other.key_; }
    };

    DList<Record> **table_ = nullptr; // the table
    int capacity_;         // capacity of the array
    double maxLoadFactor_;
    int numRecords_ = 0;
    std::hash<std::string> hashFunction;

  public:
    ChainingTable(int capacity, double maxLoadFactor = 1.0);
    ChainingTable(const ChainingTable &other);
    ChainingTable(ChainingTable &&other);
    double loadFactor() const;
    virtual bool insert(const std::string &key, const TYPE &value);
    virtual bool modify(const std::string &key, const TYPE &value);
    virtual bool remove(const std::string &key);
    virtual bool find(const std::string &key, TYPE &value);
    virtual const ChainingTable &operator=(const ChainingTable &other);
    virtual const ChainingTable &operator=(ChainingTable &&other);
    virtual ~ChainingTable();
    virtual bool isEmpty() const;
    virtual int numRecords() const;
    virtual int capacity() const;
private:
    // MARK: private helpers
    int generateIndex(const std::string &key){
        // This function takes a key, hashes the key, returns an int which is the result of hashed key mod capacity
        size_t hashValue = hashFunction(key);
        return hashValue % capacity_;
    }
    
    void growTable() {
        // This function grows the table by doubling its capacity, rehashes all the records and place them in the new table.
        int oldCap = capacity_;
        capacity_ *= 2;
        DList<Record> **newtable = new DList<Record> *[capacity_];
        // memset(newtable, 0, capacity_ * sizeof(*newtable));
        for (int i = 0; i < capacity_; i++) newtable[i] = nullptr;

        for(int i = 0; i < oldCap; i++) {
            
            if(table_[i] == nullptr) continue;

            typename DList<Record>::iterator it = table_[i]->begin();

            int idx = generateIndex((*it).key_);

            /* -------------- Rare Case, Not in test case ? ---------------
                Situation where the newtable[idx] is not nullptr when we try to move the pointer of the DList over
                For instance, table[0] has 2 records, the first one got relocated to newtable[2], and the second relocated to newtable[3]
                table[1] has one element, and new index is 3, then we have a collision. 
                The while loop copies the first record over to the new location, then erase the node and generate a new index for the next record
                The process is repeated until an empty slot is found so we can simple move the pointer over, or until the end of the list is reached
            */
            while(newtable[idx]) {
                std::cout<< "Newtable pre-occupied" << std::endl;
                Record newRecord = Record((*it).key_, (*it).data_);
                newtable[idx]->insert(newtable[idx]->end(), newRecord);
                it = table_[i]->erase(it);
                if(it != table_[i]->end()) idx = generateIndex((*it).key_);  
                else break;
            }
            if(it == table_[i]->end()) continue;
            //---------------------------------------------------------------

            newtable[idx] = table_[i];

            it++;
            while(it != table_[i]->end()) {
                int nextIdx = generateIndex((*it).key_);
                if(idx == nextIdx ) {
                    //NOTE: Special cases: same index as the front node
                    it++;
                    continue;
                };
                if (newtable[nextIdx] == nullptr) newtable[nextIdx] = new DList<Record>;
                Record newRecord = Record((*it).key_, (*it).data_);
                newtable[nextIdx]->insert(newtable[nextIdx]->end(), newRecord);
                it = table_[i]->erase(it);
            }
        }

        delete[] table_;
        table_ = newtable;

    }
    
    void deleteTable() {
        // This function deallocates memories for the table, deletes each objects and finally deletes the table pointers.
        if(table_) {
            for(int i = 0; i < capacity_; i++)  delete table_[i];
            delete [] table_;
            table_ = nullptr;
        }
    }
    
};

template <class TYPE>
ChainingTable<TYPE>::ChainingTable(int capacity, double maxLoadFactor)
    : Table<TYPE>() {
    /* MARK: Constructor
    The constructor for the ChainingTable accepts one argument
    capacity is the capacity (number of elements for the array) of the table.
    maxLoadFactor is defaulted to 1.0 (100%).
    */
    capacity_ = capacity;
    maxLoadFactor_ = maxLoadFactor;
    table_ = new DList<Record>* [capacity_];
    for (int i = 0; i < capacity_; i++) table_[i] = nullptr;
    // memset(table_, 0, capacity_ * sizeof(*table_));
        
}

template <class TYPE>
ChainingTable<TYPE>::ChainingTable(const ChainingTable<TYPE> &other) {
    //  MARK: Copy Constructor
    *this = other;
}

template <class TYPE>
ChainingTable<TYPE>::ChainingTable(ChainingTable<TYPE> &&other) {
    //  MARK: Move Constructor
    *this = std::move(other);
}

template <class TYPE>
bool ChainingTable<TYPE>::insert(const std::string &key, const TYPE &value) {
    /* MARK: Insert
    This function is passed a key-value pair.
    If the table already has a record with a matching key, the function does
    nothing and returns false. Otherwise, the new key-value pair is added to the
    table and true is returned. When inserting, if adding a new record causes
    the load factor to exceed the maxLoadFactor, function will grow the array.
    (each time the table is grown, the capacity is doubled)
    */
    
    bool found = false;
    int index = generateIndex(key);
    if(table_[index] != nullptr)
        for (typename DList<Record>::iterator it = table_[index]->begin(); !found && it != table_[index]->end();
             it++)
            if ((*it).key_ == key) found = true;

    if(!found && double(numRecords_)/double(capacity_) == maxLoadFactor_) {
        growTable();
        index = generateIndex(key);
    }

    if (table_[index] == nullptr)
        table_[index] = new DList<Record>;
    
        
    if (!found) {
        table_[index]->insert(table_[index]->end(), Record(key, value));
        numRecords_++;
    }
    
    return !found;
}

template <class TYPE>
bool ChainingTable<TYPE>::modify(const std::string &key, const TYPE &value) {
    /* MARK: Modify
    This function is passed a key-value pair.
    If the table already has a record with a matching key, the record's value
    is replaced by the value passed to this function. If no record exists with a
    matching key, function does nothing and returns false.
    */
    
    bool found = false;
    int index = generateIndex(key);
    if (table_[index] != nullptr) {
        for (typename DList<Record>::iterator it = table_[index]->begin(); !found && it != table_[index]->end();
             it++) {
            if ((*it).key_ == key){
                (*it).data_ = value;
                found = true;
            }
        }
    }
    return found;
}

template <class TYPE> bool ChainingTable<TYPE>::remove(const std::string &key) {
    /* MARK: Remove
    This function is passed a key.
    If the table contains a record with a matching key,
    the record (both the key and the value) is removed from the table and true is returned.
    Otherwise, function does nothing and returns false.
    */
    
    bool found = false;
    int index = generateIndex(key);

    if(table_[index]) {
        for (typename DList<Record>::iterator it = table_[index]->begin(); !found && it != table_[index]->end();
             it++) {

            if ((*it).key_ == key){
                it = table_[index]->erase(it);
                numRecords_--;
                found = true;
            }
        }
    }
    
    return found;
}

template <class TYPE>
bool ChainingTable<TYPE>::find(const std::string &key, TYPE &value) {
    /* MARK: Find
    This function is passed a key and a reference for passing back a found
    value. If the table contains a record with a matching key, the function
    returns true, and passes back the value from the record. If it does not find
    a record with a matching key, function returns false.
    */
    
    bool found = false;
    int index = generateIndex(key);
    if (table_[index] != nullptr) {
        for (typename DList<Record>::iterator it = table_[index]->begin(); !found && it != table_[index]->end();
             it++) {
            if ((*it).key_ == key){
                value = (*it).data_;
                found = true;
            }
        }
    }

    return found;
}

template <class TYPE>
const ChainingTable<TYPE> &
ChainingTable<TYPE>::operator=(const ChainingTable<TYPE> &other) {
    //  MARK: Copy Assignment
    if (this != &other && other.table_) {
        deleteTable();
        capacity_ = other.capacity_;
        maxLoadFactor_ = other.maxLoadFactor_;
        numRecords_ = other.numRecords_;
        
        table_ = new DList<Record>* [capacity_];
        // memset(table_, 0, capacity_ * sizeof(*table_));
        for (int i = 0; i < capacity_; i++) table_[i] = nullptr;

        for(int i = 0; i < capacity_; i++){
            if(other.table_[i])
                table_[i]= new DList<Record>(*other.table_[i]);
        }
    }
    
    if(!other.table_) {
        deleteTable();
        table_ = nullptr;
        capacity_ = 0;
        numRecords_ = 0;
    }
    return *this;
}

template <class TYPE>
const ChainingTable<TYPE> &
ChainingTable<TYPE>::operator=(ChainingTable<TYPE> &&other) {
    // MARK: Move Assignment
    if(this != &other) {
        deleteTable();
        capacity_ = other.capacity_;
        maxLoadFactor_ = other.maxLoadFactor_;
        numRecords_ = other.numRecords_;
        table_ = other.table_;
        other.table_ = nullptr;
        other.capacity_ = 0;
        other.maxLoadFactor_ = 0;
        other.numRecords_ = 0;
    }
    
    return *this;
}

template <class TYPE> ChainingTable<TYPE>::~ChainingTable() {
    // Destructor
    deleteTable();
}

template <class TYPE> bool ChainingTable<TYPE>::isEmpty() const {
    //  This function returns true if the table is empty. Otherwise, it returns false.
    return numRecords_ == 0;
}

template <class TYPE> int ChainingTable<TYPE>::numRecords() const {
    //  This function returns the number of records in the table.
    return numRecords_;
}

template <class TYPE> int ChainingTable<TYPE>::capacity() const {
    //  This function returns capacity of the table.
    return capacity_;
}

template <class TYPE> double ChainingTable<TYPE>::loadFactor() const {
    //  This function returns the load factor of the table. (number of records divided by the capacity of the table)
    return double(numRecords_)/double(capacity_);
}

// MARK: - LPTable
template <class TYPE> class LPTable : public Table<TYPE> {
    
    struct Record {
        TYPE data_;
        std::string key_;

        Record(){};
        Record(const std::string &key, const TYPE &data) {
            key_ = key;
            data_ = data;
        }
        bool &operator==(const Record &other) { return key_ = other.key_; }
    };
    
    // status of slot
    const short EMPTY = 0;
    const short  USED = 1;
    const short  DELETED = 2;
  
    Record **table_ = nullptr;
    int *tombstone_ = nullptr; // A list of int storing the status of each slot in the table array: EMPTY 0, USED 1, DELETED 2
    int capacity_;
    double maxLoadFactor_;
    int numRecords_ = 0;
    std::hash<std::string> hashFunction;
    
  public:
    LPTable(int capacity, double maxLoadFactor = 0.7);
    LPTable(const LPTable &other);
    LPTable(LPTable &&other);
    double loadFactor() const;
    virtual bool insert(const std::string &key, const TYPE &value);
    virtual bool modify(const std::string &key, const TYPE &value);
    virtual bool remove(const std::string &key);
    virtual bool find(const std::string &key, TYPE &value);
    virtual const LPTable &operator=(const LPTable &other);
    virtual const LPTable &operator=(LPTable &&other);
    virtual ~LPTable();
    virtual bool isEmpty() const;
    virtual int numRecords() const;
    virtual int capacity() const;
private:
    // MARK: private helpers

    int findSlot(const std::string &key, int *tombstone){
        /*
         This function finds an avaiable slot in the array to insert the record.
         It takes a key and a tombstone as parameters.
         Tombstone is a list of integers, indicating the status of the slot: DELETED, USED, EMPTY.
         The key is hashed the avaiable index is calculated using linear probing: (hash(key) + i) mod capacity.
         */
        size_t hashValue = hashFunction(key);
        int idx, status, i = 0;
        do {
            idx = (hashValue + i) % capacity_;
            status = tombstone[idx];
            i++;
        } while(status==USED);
            
        return idx;
    }
    
    int searchKey(const std::string &key){
        /*
         This function searches the table for a record by key, returns the index of the record if the record is found.
         If the key is not found, the function returns -1.
         */

        bool found = false;
        size_t hashValue = hashFunction(key);
        int idx, status, i = 0;
        do {
            idx = (hashValue + i) % capacity_;
            status = tombstone_[idx];
            if(table_[idx] != nullptr && table_[idx]->key_ == key)  found = true;
            i++;
        } while(status!=EMPTY && !found);
        
        return found ? idx : -1;
        
    }
    
    void growTable() {
        /*
         This function grows the table by doubling its capacity, rehashes all the records and place them in the new table.
         This function also resets the tombstone as well.
         */
        int oldCap = capacity_;
        capacity_ = capacity_ * 2;
        Record **newtable = new Record *[capacity_];
        int *newTombstone = new int[capacity_];
        memset(newTombstone, 0, capacity_ * sizeof(int));
        // memset(newtable, 0, capacity_ * sizeof(*table_));
        for (int i = 0; i < capacity_; i++) newtable[i] = nullptr;

        for(int i = 0; i < oldCap; i++) {
            if(tombstone_[i] != USED) continue;
            int newIdx = findSlot(table_[i]->key_, newTombstone);

            newtable[newIdx] = table_[i];
            newTombstone[newIdx] = USED;
        }

        delete [] table_;
        delete [] tombstone_;
        
        table_ = newtable;
        tombstone_ = newTombstone;
    }
    
    void deleteTable() {
        /*
         This function deallocates memories for the table, deletes each objects and finally deletes the table pointers.
         This function also deletes the tombstone.
         */
        if(table_) {
            for(int i = 0; i < capacity_; i++) delete table_[i];
            delete [] table_;
            table_ = nullptr;
        }
        
        if(tombstone_) delete [] tombstone_;
    }
};

template <class TYPE>
LPTable<TYPE>::LPTable(int capacity, double maxLoadFactor) : Table<TYPE>() {
    /*
    The constructor for the LPTable accepts one argument
    capacity is the capacity (number of elements for the array) of the table.
    maxLoadFactor defaults to 0.7 (70%).
    When inserting, if adding a new record causes the load factor to exceed the
    maxLoadFactor, the function will grow the array
    */
    capacity_ = capacity;
    maxLoadFactor_ = maxLoadFactor;
    table_ = new Record* [capacity_];
    tombstone_ = new int[capacity_];
    
    memset(tombstone_, 0, capacity_ * sizeof(int));
    // memset(table_, 0, capacity_ * sizeof(*table_));
    for (int i = 0; i < capacity_; i++) table_[i] = nullptr;
    
}


template <class TYPE> LPTable<TYPE>::LPTable(const LPTable<TYPE> &other) {
    //  MARK: Copy constructor
    *this = other;
}


template <class TYPE> LPTable<TYPE>::LPTable(LPTable<TYPE> &&other) {
    //  MARK: ove constructor
    *this = std::move(other);
}

template <class TYPE>
bool LPTable<TYPE>::insert(const std::string &key, const TYPE &value) {
    /* MARK: Insert
    This function is passed a key-value pair.
    If your table already has a record with a matching key, the function does
    nothing and returns false. Otherwise, the new key-value pair is added to the
    table, and true is returned. When inserting, if adding a new record causes
    the load factor to exceed the maxLoadFactor, the function will grow the
    array. (each time the table is grown, the capacity is doubled)
    */
    int keyIndex = searchKey(key);  //  index of the Record in the table. -1 means record not found
    bool found = keyIndex >= 0;

    if(!found && double(numRecords_)/double(capacity_) >= maxLoadFactor_)
        growTable();

    if (!found) {
        int idx = findSlot(key, tombstone_);
        table_[idx] = new Record(key, value);
        tombstone_[idx] = USED;
        numRecords_++;
    }
    
    return !found;
}

template <class TYPE>
bool LPTable<TYPE>::modify(const std::string &key, const TYPE &value) {
    /* MARK: Modify
    This function is passed a key-value pair.
    If your table already has a record with a matching key, the record's value
    is replaced by the value passed to this function. If no record exists with a
    matching key, the function does nothing and returns false.
    */
    int idx = searchKey(key);   //  index of the Record in the table. -1 means record not found
    if(idx != -1) table_[idx]->data_ = value;
    return idx != -1;
}

template <class TYPE> bool LPTable<TYPE>::remove(const std::string &key) {
    /* MARK: Remove
    This function is passed a key.
    If your table contains a record with a matching key,
    the record (both the key and the value) is removed from the table
    */

    int idx = searchKey(key);   //  index of the Record in the table. -1 means record not found
    
    if(idx != -1) {
        delete table_[idx];
        table_[idx] = nullptr;
        tombstone_[idx] = DELETED;
    }
    
    return idx != -1;
}

template <class TYPE>
bool LPTable<TYPE>::find(const std::string &key, TYPE &value) {
    /* MARK: Find
   This function is passed a key and a reference for passing back a found value.
   If your table contains a record with a matching key, the function returns
   true, and passes back the value from the record. If it does not find a record
   with a matching key, function returns false.
   */

    int idx = searchKey(key);   //  index of the Record in the table. -1 means record not found
    if(idx != -1) value = table_[idx]->data_;
    return idx != -1;   // idx != -1 means found

}

template <class TYPE>
const LPTable<TYPE> &LPTable<TYPE>::operator=(const LPTable<TYPE> &other) {
    //  MARK: Copy Assignment
    if (this != &other && other.table_) {
        deleteTable();
        
        capacity_ = other.capacity_;
        maxLoadFactor_ = other.maxLoadFactor_;
        numRecords_ = other.numRecords_;
        
        table_ = new Record* [capacity_];
        tombstone_ = new int[capacity_];
        // memset(table_, 0, capacity_ * sizeof(*table_));
        for (int i = 0; i < capacity_; i++) table_[i] = nullptr;
        memcpy(tombstone_, other.tombstone_, capacity() * sizeof(int));
        
        for(int i = 0; i < capacity_; i++){
            if(other.table_[i])
                table_[i]= new Record (*other.table_[i]);
        }
    }
    
    if(!other.table_) {
        deleteTable();
        
        table_ = nullptr;
        tombstone_ = nullptr;
        
        capacity_ = 0;
//        maxLoadFactor_ = 0;
        numRecords_ = 0;
    }
    return *this;
}

template <class TYPE>
const LPTable<TYPE> &LPTable<TYPE>::operator=(LPTable<TYPE> &&other) {
    //  MARK: Move Assignment
    if(this != &other) {
        deleteTable();

        table_ = other.table_;
        tombstone_ = other.tombstone_;
        capacity_ = other.capacity_;
        maxLoadFactor_ = other.maxLoadFactor_;
        numRecords_ = other.numRecords_;
        
        other.table_ = nullptr;
        other.tombstone_ = nullptr;
        other.capacity_ = 0;
//        other.maxLoadFactor_ = 0;
        other.numRecords_ = 0;
    }
    
    return *this;
}

template <class TYPE> LPTable<TYPE>::~LPTable() {
    //  Destructor
    deleteTable();
    
}

template <class TYPE> bool LPTable<TYPE>::isEmpty() const {
    //  This function returns true if the table is empty. Otherwise, it returns false.
    return numRecords_ == 0;
}

template <class TYPE> int LPTable<TYPE>::numRecords() const {
    //  This function returns the number of records in the table.
    return numRecords_;
}
template <class TYPE> int LPTable<TYPE>::capacity() const {
    //  This function returns capacity of the table.
    return capacity_;
}
template <class TYPE> double LPTable<TYPE>::loadFactor() const {
    //  This function returns the load factor of the table. (number of records divided by the capacity of the table)
    return double(numRecords_)/(capacity_);
}

#endif
