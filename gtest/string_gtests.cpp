#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

#include "alloc.hpp"
#include "gtest/gtest.h"
#include "string.hpp"
#include "string.hpp"  // intentional, lets catch some include guard errors :)

using namespace std;
using testing::HasSubstr;

class StringClass : public testing::Test {
protected:
    AllocationTracker tracker;

    virtual void TearDown() override {
        if (!testing::Test::HasFailure()) {
            // Only check this when there are no failures because failures themselves produce
            // allocations in gtest.
            EXPECT_EQ(tracker.get_allocations().size(), 0) << "You have a memory leak!";
            EXPECT_EQ(tracker.get_mismatching_deletes(), 0)
                << "You have mismatching delete[]/new or delete/new[]!";
            EXPECT_EQ(tracker.get_double_deletes(), 0) << "You tried to delete a pointer twice!";
        }
    }
};

// No longer relevant, just testing to make sure students don't rely on this.
constexpr int MAXLEN = 1024;

TEST_F(StringClass, Constructors) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);

    String t(s);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(s.size(), 5);
}

TEST_F(StringClass, Print) {
    String s("foo");
    stringstream out;
    s.print(out);
    EXPECT_STREQ(out.str().c_str(), "foo");

    stringstream out2;
    String().print(out2);
    EXPECT_STREQ(out2.str().c_str(), "");

    stringstream out3;
    out3 << s << s << String("bar");
    EXPECT_STREQ(out3.str().c_str(), "foofoobar");
}

TEST_F(StringClass, Comparisons) {
    EXPECT_LT(String("aaaa"), String("aaab"));
    EXPECT_LE(String("aaaa"), String("aaab"));
    EXPECT_EQ(String("foo"), String("foo"));
    EXPECT_NE(String("foo"), String("fooo"));
    EXPECT_LT(String("asdf"), String("asdf!"));
    EXPECT_LT(String(""), String("a"));
    EXPECT_GT(String("haha"), String("hah"));
    EXPECT_GE(String("haha"), String("hah"));
    EXPECT_GT(String("z"), String("a"));
    EXPECT_GE(String("a"), String("a"));
}

TEST_F(StringClass, EmptyConstructors) {
    String s, t;

    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s, t);

    String x("");
    EXPECT_EQ(s, x);
    EXPECT_EQ(x.size(), 0);
}

TEST_F(StringClass, Assignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    String empty;
    s = empty;
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}

TEST_F(StringClass, Swap) {
    String s("test"), t("foo");

    std::size_t allocations = tracker.get_num_allocations();
    s.swap(t);
    EXPECT_EQ(tracker.get_num_allocations(), allocations);
    EXPECT_EQ(s, String("foo"));
    EXPECT_EQ(t, String("test"));
}

TEST_F(StringClass, MoveConstructor) {
    String s("foo"), t("bar");

    std::size_t allocations = tracker.get_num_allocations();
    String test{std::move(s)};
    EXPECT_EQ(tracker.get_num_allocations(), allocations);
    EXPECT_EQ(test, String("foo"));

    s = t;
    EXPECT_EQ(s, t);
}

TEST_F(StringClass, MoveAssignment) {
    String s("test"), t("foo");

    std::size_t allocations = tracker.get_num_allocations();
    s = std::move(t);
    EXPECT_EQ(tracker.get_num_allocations(), allocations);

    EXPECT_EQ(s, String("foo"));
    t = String("bar");
    EXPECT_EQ(t, String("bar"));

    t = std::move(t);
    t = String("bar");
    EXPECT_EQ(t, String("bar"));
}

TEST_F(StringClass, IndexOfChar) {
    String haystack("abcdefghkl");
    EXPECT_EQ(haystack.indexOf('a'), 0);
}

TEST_F(StringClass, IndexOfString) {
    String haystack("foofooofoooofooooo");
    EXPECT_EQ(haystack.indexOf(String("fooooooo")), -1);
}

TEST_F(StringClass, Plus) {
    String s("test");
    String t("ing");
    s += t;
    EXPECT_EQ(s, String("testing"));
    EXPECT_EQ(s += s, String("testingtesting"));

    EXPECT_EQ(String("foo") + String("bar"), String("foobar"));
    EXPECT_EQ(String("foo") + String(""), String("foo"));
    EXPECT_EQ(String("") + String("foo"), String("foo"));
}

TEST_F(StringClass, Read) {
    stringstream in("foo bar hello world");
    String foo, bar, hello, world;
    foo.read(in);
    bar.read(in);
    in >> hello >> world;

    EXPECT_EQ(foo, String("foo"));
    EXPECT_EQ(bar, String("bar"));
    EXPECT_EQ(hello, String("hello"));
    EXPECT_EQ(world, String("world"));
}
