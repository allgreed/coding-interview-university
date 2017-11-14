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

TEST(Hash_table, collisions)
{
    HashTable<int> hash_table;

    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Magus", 0);
    // Tyrannosaurus should collide with John
    hash_table.add("Tyrannosaurus", 999999999);

    EXPECT_EQ(hash_table.get("John"), -123);
    EXPECT_EQ(hash_table.get("Jane"), -1);
    EXPECT_EQ(hash_table.get("Magus"), 0);
    EXPECT_EQ(hash_table.get("Tyrannosaurus"), 999999999);
}

TEST(Hash_table, insert_and_retrive_many_different_order)
{
    HashTable<int> hash_table;

    hash_table.add("Tyrannosaurus", 999999999);
    hash_table.add("Jane", -1);
    hash_table.add("John", -123);
    hash_table.add("Magus", 0);

    EXPECT_EQ(hash_table.get("John"), -123);
    EXPECT_EQ(hash_table.get("Jane"), -1);
    EXPECT_EQ(hash_table.get("Magus"), 0);
    EXPECT_EQ(hash_table.get("Tyrannosaurus"), 999999999);
}

TEST(Hash_table, existance)
{
    HashTable<int> hash_table;
    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Johnd", 512);

    EXPECT_TRUE(hash_table.exists("John"));
    EXPECT_TRUE(hash_table.exists("Jane"));
    EXPECT_TRUE(hash_table.exists("Johnd"));
    EXPECT_FALSE(hash_table.exists("Kane"));
    EXPECT_FALSE(hash_table.exists("Main"));
}

TEST(Hash_table, deletion)
{
    HashTable<int> hash_table;

    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Johnd", 512);

    hash_table.remove("Jane");
    hash_table.remove("John");

    EXPECT_FALSE(hash_table.exists("Jane"));
    EXPECT_FALSE(hash_table.exists("John"));
    EXPECT_TRUE(hash_table.exists("Johnd"));
}

TEST(Hash_table, write_after_delete_same)
{
    HashTable<int> hash_table;

    hash_table.add("John", -123);
    hash_table.remove("John");
    hash_table.add("Johnd", 512);

    EXPECT_FALSE(hash_table.exists("John"));
    EXPECT_TRUE(hash_table.exists("Johnd"));
    EXPECT_EQ(hash_table.get("Johnd"), 512);
}
