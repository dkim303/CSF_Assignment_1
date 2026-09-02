/*
 * Header file containing prototypes for the Money class and its methods
 * CSF Assignment 1
 * Darius Kim
 * dkim262@jhu.edu
 */

#ifndef MONEY_H
#define MONEY_H

#include <vector>
#include <string>
#include <cstdint>

class Money {
private:
  // Added fields for amount (in hundreds) and is negative bool
  uint64_t amount;
  bool negative;

public:
  //! Construct from a numeric amount and sign flag.
  //!
  //! @param amount the number of "cents" (one-hundredths of a
  //!               whole) in the currency value
  //! @param negative true if the value is negative, false
  //!                 otherwise
  Money( uint64_t amount = 0, bool negative = false );

  //! Copy constructor.
  //!
  //! @param other a Money object to make this object identical to
  Money( const Money &other );

  //! Destructor.
  ~Money();

  //! Assignment operator.
  //!
  //! @param rhs another Money object to make the left-hand object
  //!            (*this) identical to
  //! @return a reference to the left-hand object (*this)
  Money &operator=( const Money &rhs );

  //! Get the number of whole units in the currency value.
  //! E.g., if the value represents 2.43, return 2.
  //!
  //! @return the number of whole units
  uint64_t get_whole() const;

  //! Get the number of fractional (one-hundredths) in th
  //! currency value. E.g., if the value represents 2.43,
  //! return 43.
  //!
  //! @return the number of fractional (one-hundredths)
  //!         in the currency value
  uint64_t get_frac() const;

  //! Check whether this Money value is negative.
  //!
  //! @return true if the Money value is negative,
  //!         false otherwise
  bool is_negative() const;

  //! Addition operator.
  //!
  //! @param rhs the right-hand Money object to add
  //!            (*this is the left-hand Money object)
  //! @return a Money object representing the sum
  //! @throw std::overflow_error if the magnitude of the
  //!        sum exceeds the range of uint64_t
  Money operator+( const Money &rhs ) const;

  //! Subtraction operator.
  //!
  //! @param rhs the right-hand Money object to subtract
  //!            (*this is the left-hand Money object)
  //! @return a Money object representing the difference
  //!         (the value of subtracting the right-hand object
  //!         from the left-hand object)
  //! @throw std::overflow_error if the magnitude of the
  //!        difference exceeds the range of uint64_t
  Money operator-( const Money &rhs ) const;

  //! Multiplication operator. Compute the product of
  //! the left-hand Money object (*this) and the given
  //! unsigned integer value.
  //!
  //! @param x the unsigned integer value to multiply the
  //!        left-hand Money object by
  //! @return the Money object representing the product
  //!         of the left-hand object and the unsigned integer
  //!         value
  //! @throw std::overflow_error if the magnitude of the
  //!        product exceeds the range of uint64_t
  Money operator*( uint64_t x ) const;

  //! Division operator. Divides the value of the left-hand
  //! Money object (*this) in the specified number of
  //! parts, splitting the total value of the left-hand object
  //! as evenly as possible such that the sum of the
  //! returned parts exactly equals the value of the left-hand
  //! object. Returns a vector containing the parts, with
  //! sorted in descending order of amount. For example,
  //! For example, if the left-hand object represents the value
  //! 4.45, and we are dividing by 3, the returned vector
  //! will contain 3 Money objects, with values
  //! 1.49, 1.48, and 1.48, in that order.
  //!
  //! @param x the unsigned integer value to divide the
  //!          left-hand Money object by
  //! @return vector of Money objects splitting the left-hand
  //!         value as evenly as possible, sorted in descending
  //!         order of amount
  //! @throw std::invalid_argument if the specified integer
  //!        divisor is 0
  std::vector< Money > operator/( unsigned x ) const;

  //! Unary minus operator.
  //!
  //! @return the negation of the Money value the operator is
  //!         applied to
  Money operator-() const;

  //! Less-than comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              less than the right-hand object,
  //!              false otherwise
  bool operator<( const Money &rhs ) const;

  //! Less-than or equal comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              less than or equal to the right-hand object,
  //!              false otherwise
  bool operator<=( const Money &rhs ) const;

  //! Greater-than comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              greater than the right-hand object,
  //!              false otherwise
  bool operator>( const Money &rhs ) const;

  //! Greater-than or equal comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              greater than or equal to the right-hand object,
  //!              false otherwise
  bool operator>=( const Money &rhs ) const;

  //! Equality comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              equal to the right-hand object,
  //!              false otherwise
  bool operator==( const Money &rhs ) const;

  //! Inequality comparison.
  //!
  //! @return true if the left-hand object (*this) is numerically
  //!              not equal to the right-hand object,
  //!              false otherwise
  bool operator!=( const Money &rhs ) const;

  //! Return a formatted string representing the currency value
  //! of the Money object. The string must have the form
  //! MSX.Y, where
  //!
  //! * "M" is a minus sign ("-") if the Money value is negative,
  //!   or nothing if the Money value is non-negative
  //! * "S" is the characters of the curr_sym parameter,
  //! * "X" is the whole currency amount, and
  //! * "Y" is the fractional (cents) currency amount formatted
  //!   as exactly two digits
  //!
  //! For example, if the whole value of the Money object is
  //! 3, the fractional value of the Money object is 8,
  //! the value of curr_sym is "$", and the Money value is
  //! negative, the string returned should be "-$3.08".
  //!
  //! @return formatted string representing the currency amount
  std::string to_str( const std::string &curr_sym ) const;

  //! Parse the characters of the given string and return a
  //! Money object representing the currency amount.
  //! The string must be in one of the following forms:
  //! MSX.Y, MSX, or MS.Y
  //!
  //! * M is an optional minus sign ("-")
  //! * S is some sequence of non-digit characters representing
  //!   the currency symbol
  //! * X is the number of whole currency units (consisting of one or
  //!   more decimal digits)
  //! * Y is the fractional (cents) currency value formatted as
  //!   exactly two digits
  //!
  //! @param s the string to convert
  //! @return the converted Money value
  //! @throw std::invalid_argument if the string is not a valid
  //!        currency value (as described above)
  //! @throw std::overflow_error if the currency value represented
  //!        by the string is too large to fit in a uint64_t value
  static Money from_str( const std::string &s );

private:
  // TODO: add private member functions
};

#endif // MONEY_H
