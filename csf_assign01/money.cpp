#include <stdexcept>
#include <cassert>
#include <cctype>
#include "money.h"

Money::Money( uint64_t amount, bool negative )
  /* TODO: initialize member variables */ {
}

Money::Money( const Money &other )
  /* TODO: initialize member variables */ {
}

Money::~Money() {
}

Money &Money::operator=( const Money &rhs ) {
  // TODO: implement
  return *this;
}

uint64_t Money::get_whole() const {
  // TODO: implement
  return 0;
}

uint64_t Money::get_frac() const {
  // TODO: implement
  return 0;
}

bool Money::is_negative() const {
  // TODO: implement
  return false;
}

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

// TODO: implement private member functions
