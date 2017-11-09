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

TEST(Hash_table, collisions)
{
    HashTable<int> hash_table(5);

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

TEST(Hash_table, Equality)
{
    HashTable<int> hash_table;
    HashTable<int> reference_hash_table;

    hash_table.add("Magus", 0);
    hash_table.add("Random", 512);
    hash_table.add("Jane", -1);
    hash_table.add("John", -123);
    hash_table.add("Tyrannosaurus", 999999999);
    hash_table.remove("Random");

    reference_hash_table.add("Tyrannosaurus", 999999999);
    reference_hash_table.add("John", -123);
    reference_hash_table.add("Jane", -1);
    reference_hash_table.add("Magus", 0);

    EXPECT_TRUE(hash_table == reference_hash_table);
}

TEST(Hash_table, Inequality)
{
    HashTable<int> hash_table;
    HashTable<int> reference_hash_table_different_capacity(15);

    EXPECT_TRUE(hash_table != reference_hash_table_different_capacity);

    HashTable<int> reference_hash_table_different_size;

    hash_table.add("John", -123);
    hash_table.add("Jane", -1);
    hash_table.add("Magus", 0);
    hash_table.add("Tyrannosaurus", 999999999);

    reference_hash_table_different_size.add("John", -123);
    reference_hash_table_different_size.add("Jane", -1);
    reference_hash_table_different_size.add("Magus", 0);
    reference_hash_table_different_size.add("Tyrannosaurus", 999999999);
    reference_hash_table_different_size.add("Random", 512);

    EXPECT_TRUE(hash_table != reference_hash_table_different_size);

    HashTable<int> reference_hash_table_different_keys;

    reference_hash_table_different_keys.add("Magus", 0);
    reference_hash_table_different_keys.add("Keton", -123);
    reference_hash_table_different_keys.add("Tyrannosaurus", 999999999);
    reference_hash_table_different_keys.add("Beton", -1);

    EXPECT_TRUE(hash_table != reference_hash_table_different_keys);

    HashTable<int> reference_hash_table_different_values;

    hash_table.add("John", 784);
    hash_table.add("Jane", 513);
    hash_table.add("Magus", 2);
    hash_table.add("Tyrannosaurus", 999919999);

    EXPECT_TRUE(hash_table != reference_hash_table_different_keys);

}


// TEST(Hash_table, TEST_CASE_NAME)
// {
//     HashTable<int> hash_table;
//     // Do the setup

//     // Do the assertions
// }
