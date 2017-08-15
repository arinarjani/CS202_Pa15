/// @author Arin Arjani
/// @note pa15
/// @file pa15.cpp
/// @version 2017-04-14
/// @brief  This program is all about recursive functions.  Theere are 
///         functions that print start patterned triangles, star 
///         patterened fractal trees, print arrays, print file 
///         levels ( file_name.1.1.1.. ), and a jelly bean counting
///         game that outputs true for 42 jelly beans.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>



/// -----------------------------------------------------------------------
/// Prints a triangle pattern from 1 to n.  So n = 5.  The pattern would be:
///
/// *
/// **
/// ***
/// ****
/// *****
///
/// @param n A non-negative number that controls the stopping point
///          for the triangle pattern printing.
///
/// -----------------------------------------------------------------------
void pattern(unsigned n);

/// -----------------------------------------------------------------------
/// Prints a triangle pattern from m to n.  So m = 2, n = 4.  The pattern
/// would look like:
///
/// **
/// ***
/// ****
/// ****
/// ***
/// **
///
/// @param m A non-negative number that controls the starting/ending
///          point for the pattern.
///
/// @param n A non-negative number that controls the largest point of 
///          the pattern.
///
/// -----------------------------------------------------------------------
void triangle(unsigned m, unsigned n);

/// -----------------------------------------------------------------------
/// Prints a fractal tree image
///
/// @param n A non-negative number that controls the number of *'s printed
///
/// @param i A non-negative number that controls the spaces printed
///
/// -----------------------------------------------------------------------
void fractal_pattern(unsigned n, unsigned i);

/// -----------------------------------------------------------------------
/// Calculates the sum of an array. Say the array = {1,2,3}, the sum
/// would be 6; 1+2+3 = 6.
///
/// @param arr[] The array to be used to compute the sum of its elements
///
/// @param size The size of the arr[] array
///
/// @param start The starting point in the array.  Defaults to 0
///
/// @return The sum of all the elements in the array added together
/// -----------------------------------------------------------------------
template<class Type>
Type sum_array( const Type arr[], const Type size, Type start = 0 );

/// -----------------------------------------------------------------------
/// Prints the arr in element order.  An array of {1,2,3} would print 1 2 3.
///
/// @param arr[] The array to be used to compute the sum of its elements
///
/// @param size The size of the arr[] array
///
/// @param start The starting point in the array.  Defaults to 0
///
/// -----------------------------------------------------------------------
template<class Type>
void print_array( const Type arr[], const Type size, Type start = 0 );

/// -----------------------------------------------------------------------
/// Reverses the element order of an array.  Say the array = {1,2,3}, the 
/// reverse would be {3,2,1}.
///
/// @param arr[] The array to be used to compute the sum of its elements
///
/// @param start The starting point in the array.  Defaults to 0
///
/// @param end The ending point of the array. Defailts to 0
///
/// -----------------------------------------------------------------------
template<class Type>
void reverse_array( Type arr[], Type start = 0, Type end = 0 );

/// -----------------------------------------------------------------------
/// Prints a string with levels on it.  Ex. levels = 2, prefix = "CS202-".
/// The output would be CS202-1.1-9. through CS202-9.1-9.  The 
/// levels stop at 9.  More specifically CS202-1.1., CS202-1.2. .. 
/// CS202-9.1., CS202-9.9.
///
/// @param prefix The string to start adding levels to.  Ex. CS202-
///
/// @param levels How many numbers to use for levels.  
///
/// -----------------------------------------------------------------------
void section_numbers(const std::string& prefix, int levels);

/// -----------------------------------------------------------------------
/// Prints a bool value ( 0 or 1; false or true respectively ) if the player
/// reaches 42 jelly beans.  
/// Rules:
/// • If n is even, then you may give back exactly n/2 jelly beans. 
/// • If n is divisible by 3 or 4, then you may multiply the last two digits 
///   of n and give back this many jelly beans. (By the way, the last digit 
///   of n is n % 10, and the next-to-last digit is (n % 100) / 10.) 
/// • If n is divisible by 5, then you may give back exactly 42 jelly beans.
/// Ex.
/// • Start with 250 jelly beans 
/// • Since 250 is divisible by 5, you may return 42 of the jelly beans, 
///   leaving you with 208. 
/// • Since 208 is even, you may return half the jelly beans, leaving you 
///   with 104. 
/// • Since 104 is even, you may return half the jelly beans, leaving you 
///   with 52.
/// • Since 52 is divisible by 4, you may multiply the last two digits 
///   (resulting in 10) and return those 10 jelly beans. This leaves you 
///   with 42. 
/// • You have reached the goal!  
///
/// @param prefix The string to start adding levels to.  Ex. CS202-
///
/// @param levels How many numbers to use for levels.  
///
/// -----------------------------------------------------------------------
bool jelly_beans( int beans );
 
int main()
{
    int test_arr[] = {1,2,3,4,5};

    std::cout << "Question 1:" << std::endl;
    pattern(5);

    std::cout << "Question 2:" << std::endl;
    triangle(3,7);

    std::cout << "Question 3:" << std::endl;
    fractal_pattern(8,0);

    std::cout << "Question 4:" << std::endl;
    std::cout << "Sum Array f(x): " << sum_array(test_arr, 5) << std::endl;

    std::cout << "Question 5:" << std::endl;
    print_array(test_arr, 5);

    std::cout << "Question 6:" << std::endl;
    std::cout << "Before: "; 
    print_array(test_arr, 5);
    reverse_array(test_arr, 0, 5);
    std::cout << "After: "; 
    print_array(test_arr, 5);

    std::cout << "Question 7:" << std::endl;
    section_numbers("cs202-", 2);

    std::cout << "Question 8:" << std::endl;
    //std::cout << jelly_beans(250) << std::endl;



}

// 1)
void pattern(unsigned n) {
    // it returns at 0, then it still needs to hit the loop at 1..5, so it 
    // "skips" the return
    if ( n == 0 ) {
      return;
    }
    pattern(n - 1);
    for (size_t i = 0; i < n;std::cout << "*", ++i){}
    std::cout << std::endl;
}

// 2)
void triangle(unsigned m, unsigned n) {
    // base case to stop
    if ( m == 8 ) {
      return;
    }
    // case to start incrementing
    if ( m <= n ) {
        // start going up
        // m = 3,4,5,6,7
        for (size_t i = 0; i < m;std::cout << "*", ++i){}
        std::cout << std::endl;
        triangle(m + 1, n);
        // start going down
        // m = 7,6,5,4,3
        for (unsigned i = 0; i < m;std::cout << "*", ++i){}
        std::cout << std::endl;
    }
}

// 3)
void fractal_pattern(unsigned n, unsigned i) {
    // make sure n is a power of 2
    // if ( n == 2 || sqrt(n) % 2 == 0 ) {

    // }
    // pattern 1,2,1,2,1,8..repeat
    if ( n > 0 ) {
        fractal_pattern( n / 2, i );
    }
    for (unsigned k = 0; k < i; ++k) {
        std::cout << " ";
    }
    // print astrisks 
    for (unsigned k = 0; k < n; ++k) {
        std::cout << "* ";
    }
    std::cout << std::endl;
    if ( n > 0 ) {
        fractal_pattern( n / 2, i + n );
    }
}

// 4)
template<class Type>
Type sum_array( const Type arr[], const Type size, Type start ) {
    if ( size == 0 || start == size ) {
        return 0;
    } 
    // think about how you do factorial by return n + function( n - 1 )
    return arr[start] + sum_array(arr, size, start + 1);
}
template<class Type>
void print_array( const Type arr[], const Type size, Type start ) {
    if ( size == 0 || start == size ) {
        std::cout << std::endl; 
        return;
    } 
    std::cout << arr[start] << " ";
    print_array(arr, size, start + 1);
}
template<class Type>
void reverse_array( Type arr[], Type start, Type end ) {
    if ( start > end  ) {
        return;
    }
    std::swap( arr[start], arr[end - 1] );
    reverse_array( arr, start + 1, end - 1 );
}

void section_numbers(const std::string& prefix, int levels) {
    if ( levels == 0 ) {
        std::cout << "inside levels == 0; prefix: " << prefix << std::endl;
        return;
    }

    std::string s; // the string to take in prefix and levels

    for (char c = '1';c <= '9'; ++c)
    {
        s = prefix + c + '.';
        std::cout << "s: " << s << std::endl;
        section_numbers( s, levels - 1 );
    }
}

// for the jelly bean, do recursive calls for if num/2,/3,etc.  
// if those do not work, then the whole thing is false  think
// of it like a maze where your left, right, forward calls are 
// your number divisibilities

bool jelly_beans( int beans ) {
    if ( beans == 42 /*|| beans % 42 == 0*/ ) {
        return true;
    }

    if ( beans % 2 == 0 ) {
        std::cout << "Inside beans % 2; beans = " << beans - beans / 2 << std::endl;
        return jelly_beans(beans  - beans / 2);
    }

    if ( beans % 3 == 0 || beans % 4 == 0 ) {
        int last = beans % 10;
        int second_last = beans % 100 / 10;

        std::cout << "Inside beans % 3,4; beans = " << beans - last * second_last << std::endl;
        return jelly_beans( beans - last * second_last );
    }

    if ( beans % 5 == 0 ) {
        std::cout << "Inside beans % 5; beans = " << beans - 42 << std::endl;
        return jelly_beans( beans - 42 );
        return false;
    }
}




