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

    /**
     * @brief Profile constructor
     */
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
    /**
     * @brief Profile destructor
     */
    ~Profile();
    /**
     * @brief getId
     * @return profile Id
     */
    int getID() { return id; }
    /**
     * @brief getDescription
     * @return Profile description
     */
    QString getDescription() { return description; }
    /**
     * @brief getFullName
     * @return Profile name
     */
    QString getFullName() { return fullName; }
    /**
     * @brief getPicturePath
     * @return Profile picture path
     */
    QString getPicturePath() { return picturePath; }
    /**
     * @brief getScrapbook
     * @return Profile' description's scrapbook
     */
    Scrapbook* getScrapbook() { return scrapBook; }
    /**
     * @brief setDescription
     * @param &input New profile description
     */
    void setDescription(QString &input) { description = input; }
    /**
     * @brief setFullName
     * @param &input New profile name
     */
    void setFullName(QString &input) { fullName = input; }
    /**
     * @brief setPicturePath
     * @param &input New profile picture path
     */
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
