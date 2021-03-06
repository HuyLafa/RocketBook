#include "tweetdb.h"

TweetDB::TweetDB(): PostDB::PostDB()
{
    connectionName.append("tweets");
    QSqlDatabase tweetDB;
    if (!QSqlDatabase::contains(connectionName)) {
        tweetDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        tweetDB = QSqlDatabase::database(connectionName);
    }
    tweetDB.setDatabaseName("TweetDB.sqlite");

    if (!tweetDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

TweetDB::TweetDB(const QString &path): PostDB::PostDB()
{
    connectionName.append("tweets");
    QSqlDatabase tweetDB;
    if (!QSqlDatabase::contains(connectionName)) {
        tweetDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        tweetDB = QSqlDatabase::database(connectionName);
    }
    tweetDB.setDatabaseName(path);

    if (!tweetDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

TweetDB::~TweetDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}


bool TweetDB::addTweet(int tweetID, int accountID, int scrapbookID, const QString &tweetContent, int privacy)
{
    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Tweets (TweetID, AccountID, ScrapbookID, TweetContent, Privacy) VALUES (:TweetID, :AccountID, :ScrapbookID, :TweetContent, :Privacy)");
    queryAdd.bindValue(":TweetID", tweetID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);
    queryAdd.bindValue(":TweetContent", tweetContent);
    queryAdd.bindValue(":Privacy", privacy);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "add tweet failed: " << queryAdd.lastError();
    }

    return success;
}




bool TweetDB::removeTweet(int id)
{
    bool success = false;

    if (tweetExists(id))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Tweets WHERE TweetID = (:TweetID)");
        queryDelete.bindValue(":TweetID", id);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove tweet failed: " << queryDelete.lastError();
        }
    }
    else
    {
        //qDebug() << "remove tweet failed: tweet doesnt exist";
    }

    return success;
}

TweetInfoType TweetDB::retrieveTweetInfo(int tweetID)
{

    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM tweets WHERE tweetID = :tweetID");
    queryRetrieve.bindValue(":tweetID", tweetID);

    int tweetIDIndex = /*query.record().indexOf("tweetID");*/ 0;
    int accountIDIndex = 1;
    int scrapbookIDIndex = /*query.record().indexOf("Username");*/ 2;
    int contentIndex = /*query.record().indexOf("Password");*/ 3;
    int privacyIndex = 4;

    int id = -1;
    int accountID = -1;
    int scrapbookID = -1;
    QString tweetContent = "";
    int privacy = -1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            id = queryRetrieve.value(tweetIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            scrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            tweetContent = queryRetrieve.value(contentIndex).toString();
            privacy = queryRetrieve.value(privacyIndex).toInt();
        }
    }
    else
    {
        //qDebug() << "tweet retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(id, accountID, scrapbookID, tweetContent, privacy);

}

std::vector<TweetInfoType> TweetDB::retrieveAllTweetInfo(int scrapbookID)
{
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Tweets WHERE ScrapbookID = :ScrapbookID");
    queryRetrieve.bindValue(":ScrapbookID", scrapbookID);

    int tweetIDIndex = /*query.record().indexOf("TweetID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 1;
    int scrapbookIDIndex = /*query.record().indexOf("ScrapbookID");*/ 2;
    int contentIndex = /*query.record().indexOf("TweetContent");*/ 3;
    int privacyIndex = 4;

    int id = -1;
    int accountID = -1;
    int newScrapbookID = -1;
    QString tweetContent = "";
    int privacy = -1;
    std::vector<TweetInfoType> tweetInfo;

    if (queryRetrieve.exec())
    {
        while (queryRetrieve.next())
        {
            //retrieve each unit info
            id = queryRetrieve.value(tweetIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            newScrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            tweetContent = queryRetrieve.value(contentIndex).toString();
            privacy = queryRetrieve.value(privacyIndex).toInt();

            //add a row into the vector
            tweetInfo.push_back(std::make_tuple(id, accountID, newScrapbookID, tweetContent, privacy));
        }
    }
    else
    {
        //qDebug() << "tweet retrieval fails:" <<queryRetrieve.lastError();
    }

    return tweetInfo;
}

bool TweetDB::tweetExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT * FROM Tweets WHERE TweetID = (:TweetID)");
    checkQuery.bindValue(":TweetID", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        //qDebug() << "tweet exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool TweetDB::removeAllTweets()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Tweets");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "remove all tweets failed: " << removeQuery.lastError();
    }

    return success;
}
