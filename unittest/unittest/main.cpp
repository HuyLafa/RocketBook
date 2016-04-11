#include <iostream>
#include <random>
#include <string>

#include "../gtest/gtest.h"
#include "../../database/accountdb.h"
#include "../../database/profiledb.h"
#include "../../database/frienddb.h"
#include "../../database/commentdb.h"
#include "../../database/tweetdb.h"
#include "../../database/multimediadb.h"


//#include "../../model/blog.h"
//#include "../../model/comment.h"

using namespace std;


TEST(AccntDatabase, testAddAccnt)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");


    newDB.removeAllAccounts();

    bool added = false;
    int id1 = rand();
    int id2 = rand();
    added = newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);

    ASSERT_TRUE(added);


    bool allRemoved;

    allRemoved = newDB.removeAllAccounts();

    ASSERT_TRUE(allRemoved);



}

TEST(AccntDatabase, testAccntExists)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);

    ASSERT_TRUE(newDB.accountExists(un));
    ASSERT_TRUE(newDB.accountExists(un2));
    ASSERT_FALSE(newDB.accountExists(un3));

    newDB.removeAllAccounts();


}

TEST(AccntDatabase, testRmvAccnt)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");
    const QString un3("username3");
    const QString pw3("password3");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);
    bool removed;
    removed = newDB.removeAccount(un);
    ASSERT_TRUE(removed);
    ASSERT_FALSE(newDB.accountExists(un));

    newDB.removeAllAccounts();



}

TEST(AccntDatabase, testRmvAll)
{
    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    newDB.addAccount(id1, un, pw, 54322);
    newDB.addAccount(id2, un2, pw2, 54321);
    bool removed;
    removed = newDB.removeAllAccounts();
    ASSERT_TRUE(removed);
    ASSERT_FALSE(newDB.accountExists(un));



}

TEST(AccntDatabase, testRetrieveAccntID)
{

    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    int pid1 = rand();
    int pid2 = rand();



    newDB.addAccount(id1, un, pw, pid1);
    newDB.addAccount(id2, un2, pw2, pid2);

    int actualID1 = newDB.retrieveAccountId(un);

    ASSERT_EQ(actualID1, id1);

    int actualID2 = newDB.retrieveAccountId(un2);

    ASSERT_EQ(actualID2, id2);


}

TEST(AccntDatabase, testRetrieveInfo)
{

    const QString path("../unittest/testdirec/testAccntDB");
    AccountDB newDB(path);
    const QString un("username");
    const QString pw("password");
    const QString un2("username2");
    const QString pw2("password2");

    newDB.removeAllAccounts();

    int id1 = rand();
    int id2 = rand();

    int pid1 = rand();
    int pid2 = rand();



    newDB.addAccount(id1, un, pw, pid1);
    newDB.addAccount(id2, un2, pw2, pid2);

    string info1 = "";
    info1 = info1 + to_string(id1) + " ";
    info1 = info1 + un.toStdString() + " ";
    info1 = info1 + pw.toStdString() + " ";
    info1 = info1 + to_string(pid1);

    std::tuple<int,QString,QString,int> actualInfo1 =
            newDB.retrieveAccountInfo(un, pw);

    ASSERT_EQ (std::get<0>(actualInfo1), id1);
    ASSERT_EQ (std::get<1>(actualInfo1), un);
    ASSERT_EQ (std::get<2>(actualInfo1), pw);
    ASSERT_EQ (std::get<3>(actualInfo1), pid1);



    std::tuple<int,QString,QString,int> actualInfo2 =
            newDB.retrieveAccountInfo(un2, pw2);

    ASSERT_EQ (std::get<0>(actualInfo2), id2);
    ASSERT_EQ (std::get<1>(actualInfo2), un2);
    ASSERT_EQ (std::get<2>(actualInfo2), pw2);
    ASSERT_EQ (std::get<3>(actualInfo2), pid2);

    newDB.removeAllAccounts();


}

// PROFILE DATABASE TESTS /////////////////////////////////////////////////////////



TEST(ProfDatabase, testAddProf)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");


    newPDB.removeAllProfiles();

    bool added = false;
    bool added2 = false;

    added = newPDB.addProfile(pid1, fn, ph, dscr);
    added2 = newPDB.addProfile(pid2, fn2, ph2, dscr2);


    ASSERT_TRUE(added);
    ASSERT_TRUE(added2);



    bool allRemoved;

    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testProfExists)
{

    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = 1231;
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = 1232;
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");


    newPDB.removeAllProfiles();


    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);


    ASSERT_TRUE(newPDB.profileExists(pid1));
    ASSERT_TRUE(newPDB.profileExists(pid2));

    int pid3 = 1233;
    ASSERT_FALSE(newPDB.profileExists(pid3));

    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testRmvProf)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    int pid3 = rand();
    const QString fn3("fullName3");
    const QString ph3("photo3");
    const QString dscr3("description3");


    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    bool removed1 = false;
    removed1 = newPDB.removeProfile(pid1);
    ASSERT_TRUE(removed1);
    ASSERT_FALSE(newPDB.profileExists(pid1));
    bool removed2 = false;
    removed2 = newPDB.removeProfile(pid2);
    ASSERT_TRUE(removed2);
    ASSERT_FALSE(newPDB.profileExists(pid2));

    newPDB.removeAllProfiles();
}

TEST(ProfDatabase, testRmvAllProf)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    int pid3 = rand();
    const QString fn3("fullName3");
    const QString ph3("photo3");
    const QString dscr3("description3");


    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    ASSERT_TRUE(newPDB.profileExists(pid1));
    ASSERT_TRUE(newPDB.profileExists(pid2));

    bool allRmv = false;
    allRmv = newPDB.removeAllProfiles();
    ASSERT_TRUE(allRmv);
    ASSERT_FALSE(newPDB.profileExists(pid1));
    ASSERT_FALSE(newPDB.profileExists(pid2));


}

TEST(ProfDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    ProfileInfoType info = newPDB.retrieveProfileInfo(pid1);
    ASSERT_EQ (std::get<0>(info), pid1);
    ASSERT_EQ (std::get<1>(info), fn);
    ASSERT_EQ (std::get<2>(info), ph);
    ASSERT_EQ (std::get<3>(info), dscr);


    ProfileInfoType info2 = newPDB.retrieveProfileInfo(pid2);
    ASSERT_EQ (std::get<0>(info2), pid2);
    ASSERT_EQ (std::get<1>(info2), fn2);
    ASSERT_EQ (std::get<2>(info2), ph2);
    ASSERT_EQ (std::get<3>(info2), dscr2);

}

TEST(ProfDatabase, testRetrieveFullName)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    string actualFN1 = newPDB.retrieveFullname(pid1).toStdString();
    string expectedFN1 = fn.toStdString();
    ASSERT_EQ(expectedFN1, actualFN1);

}

TEST(ProfDatabase, testRetrievePhoto)
{
    const QString path("../unittest/testdirec/profiles");
    ProfileDB newPDB(path);
    int pid1 = rand();
    const QString fn("fullName");
    const QString ph("photo");
    const QString dscr("description");

    int pid2 = rand();
    const QString fn2("fullName2");
    const QString ph2("photo2");
    const QString dscr2("description2");

    newPDB.removeAllProfiles();

    newPDB.addProfile(pid1, fn, ph, dscr);
    newPDB.addProfile(pid2, fn2, ph2, dscr2);

    string actualPh1 = newPDB.retrievePhoto(pid1).toStdString();
    string expectedPh1 = ph.toStdString();
    ASSERT_EQ(expectedPh1, actualPh1);

    string actualPh2 = newPDB.retrievePhoto(pid2).toStdString();
    string expectedPh2 = ph2.toStdString();
    ASSERT_EQ(expectedPh2, actualPh2);

}

//Comment DB Tests:

TEST(CommentDatabase, testAddComments)
{
    const QString path("../unittest/testdirec/comments");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testCommentExists)
{
    const QString path("../unittest/testdirec/comments");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");
    newCDB.removeAllComments();

    ASSERT_FALSE(newCDB.commentExists(cid1));
    ASSERT_FALSE(newCDB.commentExists(cid2));
    newCDB.removeAllComments();
    newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(newCDB.commentExists(cid1));
    newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(newCDB.commentExists(cid2));



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testRmvComments)
{
    const QString path("../unittest/testdirec/comments");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);
    newCDB.removeComment(cid1);
    ASSERT_FALSE(newCDB.commentExists(cid1));



    newCDB.removeAllComments();



}

TEST(CommentDatabase, testRmvAllComments)
{
    const QString path("../unittest/testdirec/comments");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    bool added = false;
    added = newCDB.addComment(cid1, aid1, bid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newCDB.addComment(cid2, aid2, bid2, content2);
    ASSERT_TRUE(added2);
    newCDB.removeAllComments();
    ASSERT_FALSE(newCDB.commentExists(cid1));
    ASSERT_FALSE(newCDB.commentExists(cid2));

    newCDB.removeAllComments();

}

TEST(CommentDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/comments");
    CommentDB newCDB(path);
    int cid1 = 4;
    int aid1 = 5;
    int bid1 = 7;
    const QString content("content");
    int cid2 = 14;
    int aid2 = 15;
    int bid2 = 17;
    const QString content2("content2");

    newCDB.removeAllComments();
    newCDB.addComment(cid1, aid1, bid1, content);
    newCDB.addComment(cid2, aid2, bid2, content2);


    std::tuple<int,int,int,QString> actualInfo1 =
            newCDB.retrieveCommentInfo(cid1);

    ASSERT_EQ (std::get<0>(actualInfo1), cid1);
    //ASSERT_EQ (std::get<1>(actualInfo1), aid1);
    //ASSERT_EQ (std::get<2>(actualInfo1), bid1);
    ASSERT_EQ (std::get<3>(actualInfo1), content);

}


//FRIEND DB TESTS//

TEST(FriendDatabase, testAddFriends)
{


    const QString path("../unittest/testdirec/friends");
    FriendDB newFDB(path);
    int accntid = 1;
    int friendid = 2;

    bool added = false;
    added = newFDB.addFriend(accntid, friendid);
    ASSERT_TRUE(added);



}

//TWEED DB TESTS

TEST(TweetDatabase, testAddTweet)
{
    const QString path("../unittest/testdirec/tweets");
    TweetDB newTDB(path);
    int tid1 = 4;
    int sid1 = 5;
    const QString content("content");
    int tid2 = 14;
    int sid2 = 15;
    const QString content2("content2");

    newTDB.removeAllTweets();
    bool added = false;
    added = newTDB.addTweet(tid1, sid1, content);
    ASSERT_TRUE(added);
    bool added2 = false;
    added2 = newTDB.addTweet(tid2, sid2, content2);
    ASSERT_TRUE(added2);



    newTDB.removeAllTweets();



}

TEST(TweetDatabase, testTweetExists)
{
    const QString path("../unittest/testdirec/tweets");
    TweetDB newTDB(path);
    int tid1 = 4;
    int sid1 = 5;
    const QString content("content");
    int tid2 = 14;
    int sid2 = 15;
    const QString content2("content2");


    newTDB.removeAllTweets();
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));
    newTDB.addTweet(tid1, sid1, content);
    ASSERT_TRUE(newTDB.tweetExists(tid1));
    newTDB.addTweet(tid2, sid2, content2);
    ASSERT_TRUE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRmvTweet)
{
    const QString path("../unittest/testdirec/tweets");
    TweetDB newTDB(path);
    int tid1 = 4;
    int sid1 = 5;
    const QString content("content");
    int tid2 = 14;
    int sid2 = 15;
    const QString content2("content2");


    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, sid1, content);
    newTDB.addTweet(tid2, sid2, content2);
    newTDB.removeTweet(tid1);
    newTDB.removeTweet(tid2);
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRmvAllTweets)
{
    const QString path("../unittest/testdirec/tweets");
    TweetDB newTDB(path);
    int tid1 = 4;
    int sid1 = 5;
    const QString content("content");
    int tid2 = 14;
    int sid2 = 15;
    const QString content2("content2");


    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, sid1, content);
    newTDB.addTweet(tid2, sid2, content2);
    newTDB.removeAllTweets();
    ASSERT_FALSE(newTDB.tweetExists(tid1));
    ASSERT_FALSE(newTDB.tweetExists(tid2));

    newTDB.removeAllTweets();

}

TEST(TweetDatabase, testRetrieveTweetInfo)
{
    const QString path("../unittest/testdirec/tweets");
    TweetDB newTDB(path);
    int tid1 = 4;
    int sid1 = 5;
    const QString content("content");
    int tid2 = 14;
    int sid2 = 15;
    const QString content2("content2");


    newTDB.removeAllTweets();
    newTDB.addTweet(tid1, sid1, content);
    newTDB.addTweet(tid2, sid2, content2);

    TweetInfoType info = newTDB.retrieveTweetInfo(tid1);
    ASSERT_EQ (std::get<0>(info), tid1);
    ASSERT_EQ (std::get<1>(info), sid1);
    ASSERT_EQ (std::get<2>(info), content);
    TweetInfoType info2 = newTDB.retrieveTweetInfo(tid2);
    ASSERT_EQ (std::get<0>(info2), tid2);
    ASSERT_EQ (std::get<1>(info2), sid2);
    ASSERT_EQ (std::get<2>(info2), content2);

}

//Multimedia Tests:

TEST(MultimediaDatabase, testAddMM)
{
    const QString path("../unittest/testdirec/Multimedias");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int sid1 = 6;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");

    newMDB.removeAllMultimedias();
    bool added = false;
    added = newMDB.addMultimedia(mid1, sid1, mmTitle1, mmDescription1, mmContent1);
    ASSERT_TRUE(added);
    ASSERT_TRUE(newMDB.multimediaExists(mid1));


    newMDB.removeAllMultimedias();
}

TEST(MultimediaDatabase, testRmvMultimedia)
{

    const QString path("../unittest/testdirec/Multimedias");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int sid1 = 6;
    int mid2 = 15;
    int sid2 = 16;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");

    newMDB.removeAllMultimedias();
    newMDB.addMultimedia(mid1, sid1, mmTitle1, mmDescription1, mmContent1);
    newMDB.addMultimedia(mid2, sid2, mmTitle2, mmDescription2, mmContent2);

    bool rmv1 = false;
    rmv1 = newMDB.removeMultimedia(mid1);
    ASSERT_TRUE(rmv1);
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    bool rmv2 = false;
    rmv2 = newMDB.removeMultimedia(mid2);
    ASSERT_TRUE(rmv2);
    ASSERT_FALSE(newMDB.multimediaExists(mid2));



}

TEST(MultimediaDatabase, testRmvAllMultimedia)
{

    const QString path("../unittest/testdirec/Multimedias");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int sid1 = 6;
    int mid2 = 15;
    int sid2 = 16;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");

    newMDB.removeAllMultimedias();
    newMDB.addMultimedia(mid1, sid1, mmTitle1, mmDescription1, mmContent1);
    newMDB.addMultimedia(mid2, sid2, mmTitle2, mmDescription2, mmContent2);

    ASSERT_TRUE(newMDB.multimediaExists(mid1));
    ASSERT_TRUE(newMDB.multimediaExists(mid2));

    bool allRmv = false;
    allRmv = newMDB.removeAllMultimedias();
    ASSERT_TRUE(allRmv);
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    ASSERT_FALSE(newMDB.multimediaExists(mid2));





}

TEST(MultimediaDatabase, testMultimediaExists)
{

    const QString path("../unittest/testdirec/Multimedias");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int sid1 = 6;
    int mid2 = 15;
    int sid2 = 16;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");

    newMDB.removeAllMultimedias();
    ASSERT_FALSE(newMDB.multimediaExists(mid1));
    ASSERT_FALSE(newMDB.multimediaExists(mid2));
    newMDB.addMultimedia(mid1, sid1, mmTitle1, mmDescription1, mmContent1);
    newMDB.addMultimedia(mid2, sid2, mmTitle2, mmDescription2, mmContent2);
    ASSERT_TRUE(newMDB.multimediaExists(mid1));
    ASSERT_TRUE(newMDB.multimediaExists(mid2));

}

TEST(MultimediaDatabase, testRetrieveInfo)
{
    const QString path("../unittest/testdirec/Multimedias");
    MultimediaDB newMDB(path);
    int mid1 = 5;
    int sid1 = 6;
    int mid2 = 15;
    int sid2 = 16;
    const QString mmTitle1("Title 1");
    const QString mmDescription1("Description 1");
    const QString mmContent1("Content 1");
    const QString mmTitle2("Title 2");
    const QString mmDescription2("Description 2");
    const QString mmContent2("Content 2");

    MultimediaInfoType info1 = newMDB.retrieveMultimediaInfo(mid1);
    ASSERT_EQ (std::get<0>(info1), mid1);
    ASSERT_EQ (std::get<1>(info1), sid1);
    ASSERT_EQ (std::get<2>(info1), mmTitle1);
    ASSERT_EQ (std::get<3>(info1), mmDescription1);
    ASSERT_EQ (std::get<4>(info1), mmContent1);

    MultimediaInfoType info2 = newMDB.retrieveMultimediaInfo(mid2);
    ASSERT_EQ (std::get<0>(info2), mid2);
    ASSERT_EQ (std::get<1>(info2), sid2);
    ASSERT_EQ (std::get<2>(info2), mmTitle2);
    ASSERT_EQ (std::get<3>(info2), mmDescription2);
    ASSERT_EQ (std::get<4>(info2), mmContent2);
}




int main(int argc, char **argv)
{

    ::testing::InitGoogleTest(&argc, argv);

     return RUN_ALL_TESTS();

}
