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
  // TODO: implement
  return Money();
}

Money Money::operator-( const Money &rhs ) const {
  // TODO: implement
  return Money();
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
  // use not to flip sign of negative
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
  // TODO: implement
  return "";
}

Money Money::from_str( const std::string &s ) {
  // TODO: implement
  return Money();
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