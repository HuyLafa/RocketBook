#ifndef PROFILE_H
#define PROFILE_H
#include <string>
#include "scrapbook.h"
#include "../database/profiledb.h"

/**
 * @brief The Profile class stores information about a user's profile:
 *      Picture
 *      Description
 *      Name
 *      Scrapbook
 */

class Profile
{
public:

    Profile();


    /**
     * @brief Profile
     * Constructor to create a new profile, knowing name, photo, description
     *
     * @param fullName Full name of the user/group
     * @param photo Photo link of the user/group
     * @param description Description of the user/group
     */
    Profile(QString dbPath, QString fullName, QString photo, QString description);

    /**
     * @brief Profile
     * Constructor to reconstruct a profile with ID, full name, photo, description, scrapbook
     * @param id The ID of the profile
     */
    Profile(QString dbPath, int id, QString fullName, QString photo, QString description, int scrapbookID);

    ~Profile();

    int getID() { return id; }
    QString getDescription() { return description; }
    QString getFullName() { return fullName; }
    QString getPicturePath() { return picturePath; }
    Scrapbook* getScrapbook() { return scrapBook; }

    void setDescription(QString &input) { description = input; }
    void setFullName(QString &input) { fullName = input; }
    void setPicturePath(QString &input) { picturePath = input; }

private:
    int id;
    static int idCnt;
    QString description;
    QString fullName;
    QString picturePath;
    ProfileDB* profileDB;
    Scrapbook* scrapBook;
};

#endif // PROFILE_H
