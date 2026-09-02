/*
 * Unit testing file for the Money class and its methods
 * CSF Assignment 1
 * Darius Kim
 * dkim262@jhu.edu
 */

#include <iostream>
#include "money.h"
#include "tctest.h"

// Test fixture data type
struct TestObjs {
  // TODO: add additional test fixture objects
  Money zero_00, one_00, one_23;

  // TODO: initialize additional test fixture objects
  TestObjs()
    : zero_00( 0UL )
    , one_00( 100UL )
    , one_23( 123UL ) {
  }
};

// Create and destroy the test fixture
// (these are called automatically for each test
// function invocation)
TestObjs *setup();
void cleanup( TestObjs *objs );

// Prototypes of test functions
void test_get_whole( TestObjs *objs );
void test_get_frac( TestObjs *objs );
void test_is_negative( TestObjs *objs );
void test_add( TestObjs *objs );
void test_div( TestObjs *objs );
// TODO: add prototypes for additional test functions

int main( int argc, char **argv ) {
  // Allow the a test function to be explicitly named
  // on the command line
  if ( argc > 1 )
    tctest_testname_to_execute = argv[1];

  TEST_INIT();

  // Run the test functions
  TEST( test_get_whole );
  TEST( test_get_frac );
  TEST( test_is_negative );
  TEST( test_add );
  TEST( test_div );
  // TODO: run your additional test functions

  TEST_FINI();
}

TestObjs *setup() {
  return new TestObjs();
}

void cleanup( TestObjs *objs ) {
  delete objs;
}

void test_get_whole( TestObjs *objs ) {
  ASSERT( 0UL == objs->zero_00.get_whole() );
  ASSERT( 1UL == objs->one_00.get_whole() );
  ASSERT( 1UL == objs->one_23.get_whole() );
}

void test_get_frac( TestObjs *objs ) {
  ASSERT( 0UL == objs->zero_00.get_frac() );
  ASSERT( 0UL == objs->one_00.get_frac() );
  ASSERT( 23UL == objs->one_23.get_frac() );
}

void test_is_negative( TestObjs *objs ) {
  ASSERT( !objs->zero_00.is_negative() );
  ASSERT( !objs->one_00.is_negative() );
  ASSERT( !objs->one_23.is_negative() );
}

void test_add( TestObjs *objs ) {
  Money sum1( objs->zero_00 + objs->zero_00 );
  ASSERT( 0UL == sum1.get_whole() );
  ASSERT( 0UL == sum1.get_frac() );
  ASSERT( !sum1.is_negative() );

  Money sum2( objs->one_23 + objs->one_23 );
  ASSERT( 2UL == sum2.get_whole() );
  ASSERT( 46UL == sum2.get_frac() );
  ASSERT( !sum2.is_negative() );
}

void test_div( TestObjs *objs ) {
  std::vector d1( objs->one_23 / 2 );
  ASSERT( 2U == d1.size() );
  ASSERT( 0UL == d1[0].get_whole() );
  ASSERT( 62UL == d1[0].get_frac() );
  ASSERT( !d1[0].is_negative() );
  ASSERT( 0UL == d1[1].get_whole() );
  ASSERT( 61UL == d1[1].get_frac() );
  ASSERT( !d1[1].is_negative() );
}
// TODO: Implement additional test functions

// Ideas:
// integer overflow must throw std::overflow in addition
// integer overflow in the negative direciton from subtraction
// multiplication overflow must throw std::overflow
// division by 0 must throw an exception
// multiplication between +/- must give right sign at end
// Ensure operator== evalues +0==-0 as true
// Ensure normalize() function turns -0 into +0
// Ensure if X == Y is true then X>=Y and X<=Y are both also true
// Check multipication by 0 is 0

