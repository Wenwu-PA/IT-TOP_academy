#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <fstream>
#include <cstring>

class Abonent {
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[200];
    
public:
    Abonent();
    Abonent(const char* name, const char* home, const char* work, 
            const char* mobile, const char* info);
    Abonent(const Abonent& other);
    ~Abonent();
    
    inline const char* getFullName() const { return fullName; }
    inline const char* getHomePhone() const { return homePhone; }
    inline const char* getWorkPhone() const { return workPhone; }
    inline const char* getMobilePhone() const { return mobilePhone; }
    inline const char* getAdditionalInfo() const { return additionalInfo; }
    
    void setFullName(const char* name);
    inline void setHomePhone(const char* phone) { strcpy(homePhone, phone); }
    inline void setWorkPhone(const char* phone) { strcpy(workPhone, phone); }
    inline void setMobilePhone(const char* phone) { strcpy(mobilePhone, phone); }
    inline void setAdditionalInfo(const char* info) { strcpy(additionalInfo, info); }
    
    void display() const;
    void edit();
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
};

class PhoneBook {
private:
    Abonent* abonents;
    int capacity;
    int count;
    
    void resize();
    
public:
    PhoneBook();
    PhoneBook(int initialCapacity);
    PhoneBook(const PhoneBook& other);
    ~PhoneBook();
    
    void addAbonent();
    void addAbonent(const Abonent& abonent);
    void removeAbonent(int index);
    void removeAbonent(const char* name);
    void searchByName(const char* name) const;
    void displayAll() const;
    
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
    
    inline int getCount() const { return count; }
    inline int getCapacity() const { return capacity; }
    inline Abonent* getAbonent(int index) { return (index >= 0 && index < count) ? &abonents[index] : nullptr; }
};

#endif