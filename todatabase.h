#ifndef TODATABASE_H
#define TODATABASE_H
#include <string>


class ToDatabase
{
    std::string _page;
    std::string _ID;
    std::string _Ukrainian;
    std::string _English;
    std::string _fUKR;
    std::string _fENG;
    std::string _uStart;
    int uLength;
    int eLength;
    std::string _eStart;
    std::string _IDStart;
    int _IDLength;
    int _IDL;
public:
    ToDatabase();
    void operator =(std::string &page);
    void insert(const std::string &databaseName, const std::string &tableName);
};

#endif // TODATABASE_H
