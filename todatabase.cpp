#include <iostream>
#include <memory>
#include "todatabase.h"
#include "query.h"
#include "sqlite_wrapper.h"
ToDatabase::ToDatabase() :
    _fUKR("<td>U</td>"),
    _fENG("<td>E</td>"),
    _uStart("t\" >"),
    _eStart("t\">"),
    _IDStart("<td>")
{
    uLength = _uStart.length();
    eLength = _eStart.length();
    _IDLength = _IDStart.length();
    _IDL = 6;
}

void ToDatabase::operator =(std::string &page)
{
    _page = std::move(page);
}

void ToDatabase::insert(const std::string &databaseName, const std::string &tableName)
{
    if (_page.size() == 0)
    {
        std::cout << "Page is empty" << std::endl;
        return;
    }
    std::unique_ptr<Sqlite_wrapper> base = std::unique_ptr<Sqlite_wrapper>(Sqlite_wrapper::connectToDatabase(databaseName));
    std::string columnID = "ID";
    std::string columnUKR = "Ukrainian";
    std::string columnENG = "English";
    base->createTable(tableName);
        base->createColumn(columnID, "varchar(6)");
            base->setAsPK();
        base->addColumn();
        base->createColumn(columnUKR, "varchar");
        base->addColumn();
        base->createColumn(columnENG, "varchar");
        base->addColumn();
    base->addTable();
    auto ukrPos = _page.find(_fUKR);
    while (ukrPos != std::string::npos)
    {
        auto startPos = _page.find(_uStart, ukrPos) + uLength;
        auto endPos = _page.find(" <", startPos);
        _Ukrainian = _page.substr(startPos, endPos - startPos);
        while (_Ukrainian.find("&#x27;") != std::string::npos)
            _Ukrainian.replace(_Ukrainian.find("&#x27;"), 6, "\"");
        startPos = _page.find("<td>", endPos) + _IDLength;
        _ID = _page.substr(startPos, _IDL);
        auto engPos = _page.find(_fENG, endPos);
        startPos = _page.find(_eStart, engPos) + eLength;
        endPos = _page.find(" <", startPos);
        _English = _page.substr(startPos, endPos - startPos);
        Query query;
        query.insertInto(tableName, {columnID, columnUKR, columnENG}, {_ID, _Ukrainian, _English});
        base->modifyingExec(query.toString());
        ukrPos = _page.find(_fUKR, endPos);
    }
    base->disconnectFromDatabase();
}
