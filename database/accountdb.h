#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include <QString>
#include <QtSql>
#include <QDebug>

typedef std::tuple<int, QString, QString, int, int> AccountInfoType;
/**
 * @brief The AccountDB class
 *
 * Create an sqlite3 table named "Accounts" in a database file.
 * The database structure:
 * Column 1: AccountID INTEGER PRIMARY KEY
 * Column 2: Username TEXT UNIQUE
 * Column 3: Password TEXT
 * Column 4: ProfileID INTEGER
 * Column 5: AdminRights
 */
class AccountDB
{
public:
    /**
     * @brief AccountDB
     *
     * Construct an account database at ../database/RocketDB.sqlite
     */
    AccountDB();

    /**
     * @brief AccountDB
     * Construct an account database, given the path and the name of the database
     * @param path full path name of the accountdb
     */
    AccountDB(const QString& path);

    /**
     * @brief AccountDB
     * Construct an account database, given the path and the connection name of the database
     * @param path
     * @param connectionName
     */
    AccountDB(const QString &path, const QString &connectionName);

    /**
     * @brief ~AccountDB
     *
     * Default destructor for account database
     */
    ~AccountDB();

    /**
     * @brief isOpen
     *
     * Check whether account database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addAccount
     * Add a new account to the database table
     *
     * @param accountID Account ID
     * @param username
     * @param password
     * @param profileID
     * @return true if added, false if not added
     */
    bool addAccount(int accountID, const QString &username, const QString &password, int profileID, int adminRights);

    /**
     * @brief removeAccount
     * Remove an entire account from the database, knowing the username
     *
     * @param username the username of the account removed
     * @return true if succeeded, false if failed
     */
    bool removeAccount(const QString& username);

    /**
     * @brief retrieveAccountInfo
     * Return a string including details of the account with the username and password
     * For example, a possible return is "1 vuh Avengers214 2"
     *
     * @param username username of the account
     * @param password password of the account
     * @return a string with AccountID, Username, Password, ProfileID; return "" if the account does not exist.
     */
    AccountInfoType retrieveAccountInfo(const QString& username);

    int retrieveAccountID(const QString& username);

    /**
     * @brief accountExists
     * Check if account exists, knowing the username
     *
     * @param username the username of the account checked
     * @return true if yes, false if no
     */
    bool accountExists(const QString& username) const;

    /**
     * @brief removeAllAccounts
     * Remove all accounts existing in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllAccounts();

    /**
     * @brief getMaxAccountID
     * Get the maximum ID used for account
     * @return the maximum ID used for account
     */
    int getMaxAccountID();

    /**
     * @brief getUsername
     * Get the the username of an account for a given account Id
     *
     * @param accountId Account Id.
     * @return username of account which has the specified account Id
     */
    QString getUsername(int accountID);

    /**
     * @brief getProfileID
     * Get the profile ID of an account for a given account ID
     * @param accountID
     * @return the profile ID
     */
    int getProfileID(int accountID);

    QStringList getAllUsernames();

private:
    QString connectionName;
};

#endif // ACCOUNTDB_H


