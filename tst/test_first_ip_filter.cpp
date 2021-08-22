#include "gtest/gtest.h"
#include "ip_filter.h"

std::vector<std::vector<int>> vec{
        {2, 3, 4, 15},
        {1, 2, 3, 4},
        {2, 4, 8, 16},
        {1, 6, 8, 9},
        {2, 3, 8, 9}
};

TEST(Unit, should_return_only_addresses_with_certain_first_byte) {
    const std::vector<std::vector<int>> expected_addresses{vec[1], vec[3]};
    const auto actual_addresses = filter(vec, 1);
    EXPECT_EQ(expected_addresses, actual_addresses);
}

TEST(Unit, should_return_addresses_with_the_certain_two_first_bytes) {
    std::vector<std::vector<int>> expected_addresses{vec[0], vec[4]};
    const auto actual_addresses = filter(vec, 2, 3);
    EXPECT_EQ(expected_addresses, actual_addresses);
}

TEST(Unit, should_return_addresses_with_certain_byte_value) {
    std::vector<std::vector<int>> expected_addresses{vec[0], vec[1], vec[2], vec[4]};
    const auto actual_addresses = filter_any(vec, 2);
    EXPECT_EQ(expected_addresses, actual_addresses);
}