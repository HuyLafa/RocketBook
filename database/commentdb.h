#ifndef COMMENTDB_H
#define COMMENTDB_H

#include "postdb.h"

typedef std::tuple<int, int, int, QString> CommentInfoType;

/**
 * @brief The CommentDB class
 *
 * Create an sqlite3 table named "Comments" in a database file.
 * The database structure:
 * Column 1: CommentID INTEGER PRIMARY KEY
 * Column 2: AccountID INTEGER NOT NULL
 * Column 3: BlogID TEXT
 * Column 4: CommentContent TEXT NOT NULL
 */
class CommentDB: public PostDB
{
public:
    /**
     * @brief CommentDB
     *
     * Construct a comment database at CommentDB.sqlite
     */
    CommentDB();

    /**
     * @brief CommentDB
     * Construct a comment database, given the path
     * @param path full path name of the CommentDB
     */
    CommentDB(const QString& path);

    /**
     * @brief ~CommentDB
     *
     * Default destructor for comment database
     */
    ~CommentDB();

    /**
     * @brief addComment
     * Add a new account to the database table
     *
     * @param accountID Account ID
     * @param username
     * @param password
     * @param profileID
     * @return true if added, false if not added
     */
    bool addComment(int commentID,
                    int accountID,
                    int blogID,
                    const QString &content);

    /**
     * @brief removeComment
     * Remove a comment from the database, given the id
     *
     * @param id the comment's id
     * @return true if succeeded, false if failed
     */
    bool removeComment(int id);

    /**
     * @brief retrieveComment
     * Return a tuple containing information about the comment
     *
     * @param id the comment's id.
     * @return a string with the id, username and content, or an empty string if id does not exist.
     */
    CommentInfoType retrieveCommentInfo(int id);

    /**
     * @brief retrieveAllComments
     * Return a vector of tuple containing information about the comme
     * @param blogID
     * The ID of the blog
     * @return
     */
    std::vector<CommentInfoType> retrieveAllCommentInfo(int blogID);

    /**
     * @brief commentExists
     * Check if comment exists given the id.
     *
     * @param id the input id.
     * @return true if yes, false if no
     */
    bool commentExists(int id) const;

    /**
     * @brief removeAllComments
     * Remove all comments in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllComments();


private:
};


#endif // COMMENTDB_H
