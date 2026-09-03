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
  TEST( test_pos_overflow );
  TEST( test_neg_overflow );
  TEST( test_mul_overflow );
  TEST( test_zero_division );
  TEST( test_mul_signs );
  TEST( test_normalized_zeros );
  TEST( test_equality_logic );
  TEST( test_zero_mult );
  TEST( test_private_members );

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

/*
 * Ensure integer overflow in positive direction throws std::overflow.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_pos_overflow( TestObjs *objs ) {

}

/*
 * Ensure integer overflow in negative direction throws std::overflow.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_neg_overflow( TestObjs *objs ) {

}

/*
 * Ensure multiplication causing overflow must throw std::overflow.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_mul_overflow( TestObjs *objs ) {

}

/*
 * Ensure attempted division by 0 throws an std::invalid_argument.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_zero_division( TestObjs *objs ) {
  Money money(100, false);
  money/0;
}

/*
 * Various tests to ensure correct sign logic with multiplication.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_mul_signs( TestObjs *objs ) {

}

/*
 * Ensure +0 is the same thing as -0.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_normalized_zeros( TestObjs *objs ) {

}

/*
 * Ensure if X == Y is true that X >= Y and X <= Y must also be true.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_equality_logic( TestObjs *objs ) {

}

/*
 * Ensure multiplication by 0 always returns 0.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_zero_mult( TestObjs *objs ) {

}

/*
 * Ensure private member functions of Money are not accessible from the outside.
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_private_members( TestObjs *objs ) {

}

/*
 * Ensure basic functionality of to_str method
 *
 * Parameters:
 *   TestObjs *objs
 *
 * Returns:
 *  None
 */
void test_to_str_basic( TestObjs *objs ) {
  Money euro(10025, false);
  Money usd(25, true);

  std::string euro_str = euro.to_str("€");
  std::string usd_str = usd.to_str("$");

  ASSERT( euro_str == "€100.25" );
  ASSERT( usd_str == "-$0.25" );
}
