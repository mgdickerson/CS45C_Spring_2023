#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <sstream>
#include <utility>

#include "coins.h"

using namespace std;
using testing::HasSubstr;
using testing::ContainsRegex;
using testing::MatchesRegex;

TEST(Coins, SingleCoinTotalValue) {
  const Coins one_quarter(1, 0, 0, 0);
  const Coins one_dime(0, 1, 0, 0);
  const Coins one_nickel(0, 0, 1, 0);
  const Coins one_penny(0, 0, 0, 1);

  EXPECT_EQ(CENTS_PER_QUARTER, one_quarter.total_value_in_cents());
  EXPECT_EQ(CENTS_PER_DIME, one_dime.total_value_in_cents());
  EXPECT_EQ(CENTS_PER_NICKEL, one_nickel.total_value_in_cents());
  EXPECT_EQ(1, one_penny.total_value_in_cents());
}

TEST(Coins, Deposit) {
  Coins bank(0, 0, 0, 0);
  Coins deposit1(1, 2, 3, 4);
  Coins deposit2(5, 2, 3, 1);

  bank.deposit_coins(deposit1);
  EXPECT_EQ(Coins(1, 2, 3, 4), bank);

  bank.deposit_coins(deposit2);
  EXPECT_EQ(Coins(6, 4, 6, 5), bank);
}

TEST(Coins, InsertionOperator) {
  const auto print_coins = [](const Coins& c) {
    stringstream output;
    output << c;
    return output.str();
  };

  EXPECT_STREQ(print_coins(Coins(1, 2, 3, 4)).c_str(), "1 quarters, 2 dimes, 3 nickels, 4 pennies");
  EXPECT_STREQ(print_coins(Coins(5, 0, 1, 1)).c_str(), "5 quarters, 0 dimes, 1 nickels, 1 pennies");
  EXPECT_STREQ(print_coins(Coins(0, 0, 9, 9)).c_str(), "0 quarters, 0 dimes, 9 nickels, 9 pennies");
}

TEST(Coins, PrintCents) {
  const auto print_cents_str = [](const int i) {
    stringstream output;
    print_cents(i, output);
    return output.str();
  };

  EXPECT_STREQ(print_cents_str(0).c_str(), "$0.00");
  EXPECT_STREQ(print_cents_str(5).c_str(), "$0.05");
  EXPECT_STREQ(print_cents_str(10).c_str(), "$0.10");
  EXPECT_STREQ(print_cents_str(92).c_str(), "$0.92");
  EXPECT_STREQ(print_cents_str(100).c_str(), "$1.00");
  EXPECT_STREQ(print_cents_str(205).c_str(), "$2.05");
}

TEST(Coins, AskForCoins) {
  const auto ask_for_coins_str = [](const char* str) {
    stringstream input(str);
    stringstream output;
    const Coins result = ask_for_coins(input, output);
    return pair{result, output.str()};
  };

  {
    const auto [coins, output] = ask_for_coins_str("1\n2\n3\n4\n");
    EXPECT_EQ(coins, Coins(1, 2, 3, 4));
    EXPECT_THAT(output, MatchesRegex("Quarters\\?\\s*Dimes\\?\\s*Nickels\\?\\s*Pennies\\?\\s*"));
  }

  {
    const auto [coins, output] = ask_for_coins_str("5\n0\n0\n7\n");
    EXPECT_EQ(coins, Coins(5, 0, 0, 7));
    EXPECT_THAT(output, MatchesRegex("Quarters\\?\\s*Dimes\\?\\s*Nickels\\?\\s*Pennies\\?\\s*"));
  }

  {
    const auto [coins, output] = ask_for_coins_str("2\n1\n3\n5\n");
    EXPECT_EQ(coins, Coins(2, 1, 3, 5));
    EXPECT_THAT(output, MatchesRegex("Quarters\\?\\s*Dimes\\?\\s*Nickels\\?\\s*Pennies\\?\\s*"));
  }
}

TEST(Coins, Menu) {
  const auto run_menu = [](const char* str) {
    stringstream input(str);
    stringstream output;
    coins_menu(input, output);
    return output.str();
  };

  EXPECT_THAT(run_menu("4\n"),
              MatchesRegex("Coins Menu\\s*1. Deposit Change\\s*2. Extract Change\\s*"
                           "3. Print Balance\\s*4. Exit\\s*User Input:\\s*"));

  EXPECT_THAT(run_menu("1\n10\n20\n30\n40\n4\n"),
              ContainsRegex("Quarters\\?\\s*Dimes\\?\\s*Nickels\\?\\s*Pennies\\?\\s*Thank you!"));

  EXPECT_THAT(run_menu("1\n5\n0\n3\n7\n3\n4\n"), HasSubstr("$1.47"));
}
