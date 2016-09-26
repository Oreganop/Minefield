# BUG LOG

Segfaults on test:

TEST(FieldTest, placeLimitMAX_MAX)
{
	Field minefield;
	minefield.placeMine(10,10);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(10,10) );
}
