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
  // TODO: implement
  return Money();
}

std::vector< Money > Money::operator/( unsigned x ) const {
  // TODO: implement
  return std::vector< Money >();
}

Money Money::operator-() const {
  // TODO: implement
  return Money();
}

bool Money::operator<( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator<=( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator>( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator>=( const Money &rhs ) const {
  // TODO: implement
  return false;
}

bool Money::operator==( const Money &rhs ) const {
  // TODO: implement
  return false;
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