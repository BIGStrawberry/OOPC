#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iostream"

/**
 * @file
 * @brief
 * 2D integer vector ADT
 * @details
 * This is a 2D vector ADT that stores its two components as signed integers.
 * The x and y are public.
*/
class Vector {
public:
    int x, y;
    
    /**
     * @brief
     * Basic Constructor
     * @details
     * This constructor doesn't initializes the x and y attributes, so they're set to 0.
    */
    Vector();

    /**
     * @brief
     * Basic Constructor
     * @details
     * This constructor does initialize the x and y attributes.
    */
    Vector(int x, int y);
    
    /**
     * @brief
     * Compares two vectors
     * @details
     * This operator tests for equality. 
     * It returns true if - and only if - the x and y values of both vectors are equal.
     */
    bool operator==(const Vector& rhs) const;

    /**
     * @brief
     * Unary plus operator
     * @details
     * Returns a copy of the given Vector 
     */
    Vector operator+() const;
    
    /**
     * @brief
     * Add a Vector to another Vector
     * @details
     * This operator adds a Vector to another Vector. 
     */
    Vector operator+(const Vector& rhs) const;
    
    /**
     * @brief
     * Add a Vector to another Vector
     * @details
     * This operator adds a Vector to another Vector. 
     */
    Vector& operator+=(const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by an integer
     * @details
     * This operator multiplies a Vector by an integer value.
     */
    Vector operator*(const int& rhs) const;
    /**
     * @brief
     * Multiply a Vector by an integer
     * @details
     * This operator multiplies a Vector by an integer value.
     */
    friend Vector operator*(const int& lhs, const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by another Vector
     * @details
     * This operator multiplies a Vector by another Vector.
     */
    Vector& operator*=(const Vector& rhs);
    
    /**
     * @brief
     * Multiply a Vector by an integer
     * @details
     * This operator multiplies a Vector by an integer value.
     */
    Vector& operator*=(const int& rhs);
    
    friend std::ostream& operator<<(std::ostream& lhs, const Vector& rhs);
};



#endif // VECTOR_HPP
