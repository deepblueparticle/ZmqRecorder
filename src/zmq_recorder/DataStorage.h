
#ifndef _DATA_STORAGE_H_
#define _DATA_STORAGE_H_

#include <boost/shared_ptr.hpp>
#include <sqlite3cc.h>

class DataStorage
{
public:
    /**
     * Creates a new database and stores the needed tables in it
     *  * Activities
     *  * Marks
     *  * Plots
     */
    DataStorage();
    virtual ~DataStorage();

    /**
     * Stores the given data into the database
     */
    void storeData(const std::string& data);

private:
    /**
     * Initializes a new database with the given name for
     *  * Activities
     *  * Marks
     *  * Plots
     */
    void initDatabase(const std::string& filename);
    /**
     * This function returns the current DateStr in the following form:
     * DDMonYYYY_HHMMSS -> 31Apr2014_235959
     */
    std::string getCurrentDateStr();
    /**
     * Adds the given data to the DB
     */
    void updateData(const std::string& data);

    /**
     * This is the connection to the database
     */
    boost::shared_ptr<sqlite::connection> connection_;

};

#endif //_DATA_STORAGE_H_