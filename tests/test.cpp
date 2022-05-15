//Copyright by PanasyukMaria

#include <gtest/gtest.h>
#include "Stack.hpp"
#include "StackSecond.hpp"

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}
TEST(StackOne, True) {
  Stack<int> MySteck;
  int t=2;
  MySteck.push(1);
  MySteck.push(t);
  EXPECT_EQ(MySteck.head(), 2);
  EXPECT_EQ(MySteck.pop(), 2);
  EXPECT_EQ(MySteck.head(), 1);
  EXPECT_EQ(MySteck.pop(), 1);
  std::string err = "Stack is empty!";
  try {
    MySteck.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}

class Myclass {
 public:
  Myclass(Myclass&) = delete;
  Myclass& operator = (Myclass&) = delete;
  Myclass(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
  }
  Myclass& operator=(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
    return *this;
  }
  Myclass(){
    t0 = 0;
    t1 = 0.1;
    t2 = "0";
  }
  Myclass(int a, double b, std::string c): t0(a), t1(b), t2(c){}
  int t0;
  double t1;
  std::string t2;
};
TEST(Stacktwo, True) {
  SecondStack<Myclass> MyStack;
  int t0 = 5;
  double t1 = 5.5;
  std::string t2 = "5";
  MyStack.push_emplace(Myclass(1, 1.1, "12"));
  MyStack.push_emplace(t0, t1, t2);
  MyStack.push(Myclass());
  EXPECT_EQ(MyStack.pop().t2, "0");
  EXPECT_EQ(MyStack.head().t0, 5);
  EXPECT_EQ(MyStack.pop().t1, 5.5);
  EXPECT_EQ(MyStack.head().t0, 1);
  EXPECT_EQ(MyStack.pop().t2, "12");
  std::string err = "Stack is empty";
  try {
    MyStack.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}