#include "blogdb.h"

BlogDB::BlogDB()
{
    connectionName.append("blogs");

    QSqlDatabase blogDB;
    if (!QSqlDatabase::contains(connectionName)) {
        blogDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        blogDB = QSqlDatabase::database(connectionName);
    }


    blogDB.setDatabaseName("rocketDB.sqlite");

    if (!blogDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

BlogDB::BlogDB(const QString &path) : PostDB::PostDB()
{
    connectionName.append("blogs");

    QSqlDatabase blogDB;
    if (!QSqlDatabase::contains(connectionName)) {
        blogDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        blogDB = QSqlDatabase::database(connectionName);
    }

    blogDB.setDatabaseName(path);

    if (!blogDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

BlogDB::~BlogDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}


bool BlogDB::addBlog(int blogID,
                     int accountID,
                     int scrapbookID,
                     const QString &blogTitle,
                     const QString &blogContent,
                     int privacy)
{
    bool success = false;

    //qDebug() << "blog id is: " <<  blogID;
    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Blogs (BlogID, AccountID, ScrapbookID, BlogTitle, BlogContent, Privacy) VALUES (:BlogID, :AccountID, :ScrapbookID, :BlogTitle, :BlogContent, :Privacy)");
    queryAdd.bindValue(":BlogID", blogID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);
    queryAdd.bindValue(":BlogTitle", blogTitle);
    queryAdd.bindValue(":BlogContent", blogContent);
    queryAdd.bindValue(":Privacy", privacy);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "add blog failed: " << queryAdd.lastError();
    }

    return success;
}

bool BlogDB::removeBlog(int id)
{
    bool success = false;

    if (blogExists(id))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Blogs WHERE BlogID = (:BlogID)");
        queryDelete.bindValue(":BlogID", id);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove blog failed: " << queryDelete.lastError();
        }
    }
    else
    {
        //qDebug() << "remove blog failed: blog doesnt exist";
    }

    return success;
}

BlogInfoType BlogDB::retrieveBlogInfo(int blogID)
{
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Blogs WHERE BlogID = :BlogID");
    queryRetrieve.bindValue(":BlogID", blogID);

    int blogIDIndex = /*query.record().indexOf("BlogID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 1;
    int scrapbookIDIndex = /*query.record().indexOf("ScrapbookID");*/ 2;
    int titleIndex = 3;
    int contentIndex = /*query.record().indexOf("BlogContent");*/ 4;
    int privacyIndex = 5;

    int id = -1;
    int accountID = -1;
    int scrapbookID = -1;
    QString blogTitle = "";
    QString blogContent = "";
    int privacy = -1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            id = queryRetrieve.value(blogIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            scrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            blogTitle = queryRetrieve.value(titleIndex).toString();
            blogContent = queryRetrieve.value(contentIndex).toString();
            privacy = queryRetrieve.value(privacyIndex).toInt();
        }
    }
    else
    {
        //qDebug() << "blog retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(id, accountID, scrapbookID, blogTitle, blogContent, privacy);
}

std::vector<BlogInfoType> BlogDB::retrieveAllBlogInfo(int scrapbookID)
{
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Blogs WHERE ScrapbookID = :ScrapbookID");
    queryRetrieve.bindValue(":ScrapbookID", scrapbookID);

    int blogIDIndex = /*query.record().indexOf("BlogID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 1;
    int scrapbookIDIndex = /*query.record().indexOf("ScrapbookID");*/ 2;
    int titleIndex = 3;
    int contentIndex = /*query.record().indexOf("BlogContent");*/ 4;
    int privacyIndex = 5;

    int id = -1;
    int accountID = -1;
    int newScrapbookID = -1;
    QString blogTitle = "";
    QString blogContent = "";
    int privacy = -1;
    std::vector<BlogInfoType> blogInfo;

    if (queryRetrieve.exec())
    {
        while (queryRetrieve.next())
        {
            //retrieve each unit info
            id = queryRetrieve.value(blogIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            newScrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            blogTitle = queryRetrieve.value(titleIndex).toString();
            blogContent = queryRetrieve.value(contentIndex).toString();
            privacy = queryRetrieve.value(privacyIndex).toInt();

            //add a row into the vector
            blogInfo.push_back(std::make_tuple(id, accountID, newScrapbookID, blogTitle, blogContent, privacy));
        }
    }
    else
    {
        //qDebug() << "blog retrieval fails:" <<queryRetrieve.lastError();
    }

    return blogInfo;
}

bool BlogDB::blogExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT * FROM Blogs WHERE BlogID = (:BlogID)");
    checkQuery.bindValue(":BlogID", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        //qDebug() << "blog exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool BlogDB::removeAllBlogs()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Blogs");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "remove all blogs failed: " << removeQuery.lastError();
    }

    return success;
}
