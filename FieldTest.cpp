/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}
TEST(FieldTest, placeLimit0_0)
{
	Field minefield;
	minefield.placeMine(0,0);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(0,0) );
}
TEST(FieldTest, placeLimit0_10)
{
	Field minefield;
	minefield.placeMine(0,10);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(0,10) );
}
TEST(FieldTest, placeLimit10_0)
{
	Field minefield;
	minefield.placeMine(10,0);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(10,0) );
}
TEST(FieldTest, placeLimit10_10)
{
	Field minefield;
	minefield.placeMine(10,10);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(10,10) );
}


/*  void function lol
TEST(FieldTest, placeMineOutBounds)
{
    Field minefield;

    ASSERT_ANY_THROW(minefield.placeMine(-1,-1));
}
*/

TEST(FieldTest, getOutBounds)
{
    Field minefield;
    ASSERT_ANY_THROW(minefield.get(-1,-1));
    ASSERT_ANY_THROW(minefield.get(-1,11));
    ASSERT_ANY_THROW(minefield.get(11,11));
    ASSERT_ANY_THROW(minefield.get(11,-1));
}

TEST(FieldTest, getUnplaced)
{
    Field mf;
    ASSERT_EQ(EMPTY_HIDDEN, mf.get(5,5));
}

TEST(FIELDTEST, safeOutBounds)
{
    Field mf;
    ASSERT_FALSE(mf.isSafe(-1, 5));
    ASSERT_FALSE(mf.isSafe(-1, 11));
    ASSERT_FALSE(mf.isSafe(11,5));
    ASSERT_FALSE(mf.isSafe(11,-1));
}

