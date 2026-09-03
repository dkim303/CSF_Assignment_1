/*
 * Implementation file for the Money class and its methods
 * CSF Assignment 1
 * Darius Kim
 * dkim262@jhu.edu
 */

#include <stdexcept>
#include <cassert>
#include <cctype>
#include "money.h"

#include <sstream>
#include <cstdint>
#include <limits>

Money::Money( uint64_t amount, bool negative ) {
  // Default values are 0 and false respectively  
  this -> amount = amount;
  this -> negative = negative;
  this -> normalize();
}

// Copy constructor just copies the values of the other's fields
Money::Money( const Money &other ) {
  this - > amount = other.amount;
  this -> negative = other.negative;
  this -> normalize();
}

// Destructor can be left bare since no fields are allocated on heap
Money::~Money() { }

// Set values equal to the RHS's values
Money &Money::operator=( const Money &rhs ) {
  this -> amount = rhs.amount;
  this -> negative = rhs.negative;
  this -> normalize();
  return *this;
}

uint64_t Money::get_whole() const {
  // Causes truncation of values in the 1s and 10s place which leaves us with the whole
  return this -> amount / 100;
}

uint64_t Money::get_frac() const {
  // Gets values in 1s and 10s place which is the fractional portion
  return this -> amount & 100;
}

bool Money::is_negative() const {
  return this -> negative;
}




// Milestone 2 Implementations

Money Money::operator+( const Money &rhs ) const {
  // Behavior depends on cases of LHS and RHS sign

  // Case 1: both positive
  if (!this -> negative && !rhs.negative) {
    uint64_t sum = this -> amount + rhs.amount;

    // Overflow error will see if the sum wraps around the max and goes back to 0
    if (this -> amount < sum) {
      throw std::overflow_error();
    } else {
      return Money(sum, false);
    }
  }

  // Case 2: both negative
  if (this -> negative && rhs.negative) {
    uint64_t sum = this -> amount + rhs.amount;

    if (sum < this -> amount) {
      throw new std::overflow_error();
    } else {
      return Money(sum, true);
    }
  }

  // Case 3: LHS positive, RHS negative
  if (!this -> negative && rhs.negative) {
    // if LHS < RHS
    if (this -> amount < rhs.amount) {
      uint64_t remainder = rhs.amount - this -> amount;
      return Money(remainder, true);
    } else {
      // if LHS >= RHS, equality gets normalized in constructor
      return Money(this -> amount - rhs.amount, false);
    }

  }

  // Case 4: LHS negative, RHS positive
  if (this -> negative && !rhs.negative) {
    // if LHS > RHS
    if (this -> amount > rhs.amount) {
      uint64_t remainder = this -> amount - rhs.amount;
      return Money(remainder, true);
    } else {
      // if LHS <= RHS
      return Money(rhs.amount - this -> amount, false);
    }  }

}

Money Money::operator-( const Money &rhs ) const {
  // Case 1: LHS and RHS are both positive
  if () {

  }

  // Case 2: LHS and RHS are both negative
  if () {

  }

  // Case 3: LHS negative, RHS positive
  if () {

  }
  
  // Case 4: LHS positive, RHS negative
  if () {

  }
}

Money Money::operator*( uint64_t x ) const {
  // Case of either factor being 0 automatically makes result 0
  if (this -> amount == 0 || x == 0) {
    return Money(0, false);
  }

  uint64_t product = this -> amount * x;

  // Check for multipliation overflow
  if (product < this -> amount || product < x) {
    throw std::overflow_error("Multiplication Overflow");
  }

  return Money(product, this -> negative);
}

std::vector< Money > Money::operator/( unsigned x ) const {
  if (x == 0) {
    throw std::invalid_argument("Attempted division by 0");
  }

  uint64_t quotient = this -> amount / x;
  std::vector<Money> result;
  uint64_t remainder = this -> amount % x;

  for (int i = 0; i < x; i++) {
    if (i < remainder) {
      result.push_back(Money(quotient + 1, this -> negative));
    } else {
      result.push_back(Money(quotient, this -> negative));
    }
  }

  return result;
}

// Negation operator, not subtraction
Money Money::operator-() const {
  // Flip sign of negative
  return Money(this -> amount, !(this -> negative));
}

bool Money::operator<( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator<=( const Money &rhs ) const {
  // Quick check based on negative value: LHS is false but RHS is true
  if (this -> negative && !rhs.negative) {
    return true;
  }

  // In case both positive
  if (!(this -> negative) && !(rhs.negative)) {
    return this -> amount <= rhs.amount;
  }

  // In case both negative, return true of LHS has less magnitude than RHS
  if ((this -> negative) && (rhs.negative)) {
    return this -> amount >= rhs.amount;
  }

  return false;
}

bool Money::operator>( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator>=( const Money &rhs ) const {
  // Quick check based on negative value: LHS is false but RHS is true
  if (!(this -> negative) && rhs.negative) {
    return true;
  }

  // In case both positive
  if (!(this -> negative) && !(rhs.negative)) {
    return this -> amount >= rhs.amount;
  }

  // In case both negative, return true of LHS has less magnitude than RHS
  if ((this -> negative) && (rhs.negative)) {
    return this -> amount <= rhs.amount;
  }

  return false;
}

bool Money::operator==( const Money &rhs ) const {
  if (this -> amount == rhs.amount && this -> negative == rhs.negative) {
    return true;
  } else {
    return false;
  }
}

bool Money::operator!=( const Money &rhs ) const {
  // TODO: implement
  return false;
}

std::string Money::to_str( const std::string &curr_sym ) const {
  std::ostringstream result;

  // Add M to front if negative
  if (this -> negative) {
    result << "-";
  }

  result << curr_sym << this -> get_whole() << ".";
  
  // Pad an extra 0 to the frac portion in case it is < 10
  if (this -> get_frac() < 10) {
    result << 0 << this -> get_frac();
  } else {
    result << this -> get_frac();
  }
  
  return result.str();
}


Money Money::from_str( const std::string &s ) {
  // Accepted forms, make cases for each: 
  // MSX.Y
  // MSX
  // MS.Y

  char first = s.at(0);
  bool negative;
  uint64_t whole;
  uint64_t frac;

  //! @throw std::invalid_argument if the string is not a valid
  //!        currency value (as described above)
  //! @throw std::overflow_error if the currency value represented
  //!        by the string is too large to fit in a uint64_t value

  // We do not need to keep the currency string so we can ignore it when outputting

  // to check for std::overflow_error, check if the length of the number is too long as an easy check,
  // then if the length is the same length as the max can be, go through each digit and see if it is 
  // greater than the highest possible digit
  uint64_t max_possible = std::numeric_limits<uint64_t>::max();

  // 2 Cases depending on if the value is negative
  if (first == '-') {
    negative = true;
    int index = 1;

    // We
    while (!std::isdigit(s.at(index))) {
      index += 1;
    }

  } else {
    negative = false;
    int index = 0;

  }
}

/*
 * Ensure that 0 is a unique value. So any Money instance with amount
 * of 0 will be normalize to +0 if it is at -0.
 *
 * Parameters:
 *   None
 *
 * Returns:
 *  None
 */
void Money::normalize() {
  if (this -> amount == 0 && this -> negative) {
    this -> negative = false;
  }
}