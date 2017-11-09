#include "hash_table.hpp"
#include "gtest/gtest.h"

TEST(Hash_table, create_and_destroy)
{
    HashTable<int> hash_table;
}

TEST(Hash_table, insert_and_retrive_single)
{
    HashTable<int> hash_table;
    hash_table.add("John", -123);

    EXPECT_EQ(hash_table.get("John"), -123);
}

TEST(Hash_table, insert_and_retrive_many)
{
    HashTable<int> hash_table;

    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Magus", 0);
    hash_table.add("Tyrannosaurus", 999999999);

    EXPECT_EQ(hash_table.get("John"), -123);
    EXPECT_EQ(hash_table.get("Jane"), -1);
    EXPECT_EQ(hash_table.get("Magus"), 0);
    EXPECT_EQ(hash_table.get("Tyrannosaurus"), 999999999);
}

TEST(Hash_table, attempt_addition_on_full_table)
{
    HashTable<int> hash_table(2);
    hash_table.add("John", -123);
    hash_table.add("Jane", -1);

    EXPECT_THROW(hash_table.add("Jacob", -1), std::runtime_error);
}

TEST(Hash_table, non_existant_key_dereference_attempt_full_table)
{
    HashTable<int> hash_table(2);
    hash_table.add("John", -123);
    hash_table.add("Jane", -1);

    EXPECT_THROW(hash_table.get("Jacob"), std::runtime_error);
}

TEST(Hash_table, non_existant_key_dereference_attempt_not_full_table)
{
    HashTable<int> hash_table(2);
    hash_table.add("John", -123);

    EXPECT_THROW(hash_table.get("Jacob"), std::runtime_error);
}

TEST(Hash_table, overwrite)
{
    HashTable<int> hash_table;
    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Magus", 0);
    hash_table.add("Tyrannosaurus", 999999999);

    hash_table.add("Tyrannosaurus", -8);

    EXPECT_EQ(hash_table.get("John"), -123);
    EXPECT_EQ(hash_table.get("Jane"), -1);
    EXPECT_EQ(hash_table.get("Magus"), 0);
    EXPECT_EQ(hash_table.get("Tyrannosaurus"), -8);
}


// todo: test addition in different order
// todo: test for collisions

// TEST(Hash_table, insert_and_retrive)
// {
//     HashTable<int> hash_table;

//     // todo: generate collision and redo the asserts

//     // collisions
//     hash_table.add("John", -123);
//     hash_table.add("Jane", -1);
//     hash_table.add("Magus", 0);
//     hash_table.add("Tyrannosaurus", 999999999);
//     // HashTable_add(hash_table, "Johnd", 512);
//     // assert(HashTable_get(hash_table, "John") == -123);
//     // assert(HashTable_get(hash_table, "Jane") == -1);
//     // assert(HashTable_get(hash_table, "Magues") == 0);
//     // assert(HashTable_get(hash_table, "Tyrannosaurus rix") == -8);
//     // assert(HashTable_get(hash_table, "Johnd") == 512);
// }

// TEST(Hash_table, TEST_CASE_NAME)
// {
//     HashTable<int> hash_table;
//     // Do the setup

//     // Do the assertions
// }
