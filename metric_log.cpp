/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 6 - Class Templates
 * Description: Generic metric log practice and ADT contract
 * Due date: [Date]
 */

#include <iostream>
using namespace std;

/*
 * MetricLog ADT
 *
 * Data:
 * [Complete in Part E: describe the values managed by this log.]
 *  Stores a capacity of four values of a generic type.
 * 
 * Operations:
 * [Complete in Part E: describe add(value).]
 * adds a new value to the log when there is remaining capacity.
 * 
 * [Complete in Part E: describe get(index) and its precondition.]
 * it returns the value stored at the given index.
 * 
 * [Complete in Part E: describe contains(target).]
 * returns true when an equal stored value exists; otherwise returns false.
 * 
 * [Complete in Part E: describe size() and isEmpty().]
 * size returns the number of values currently stored in the log.
 * isEmpty returns true when the log stores no values; otherwise returns false.
 * 
 */

template <typename T>
class MetricLog
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Add a constant for a fixed capacity of four values.
    static const int CAPACITY = 4;
    // TODO (Part C): Add an array that stores values of the generic type.
    T values[CAPACITY];
    // TODO (Part C): Add an int that tracks how many values are stored.
    int count;

public:
    // TODO (Part C): Write a constructor that creates an empty log.
    MetricLog()
    {
        count = 0;
    }

    // TODO (Part C): Write add. It receives one generic value by const reference.
    // Return false when the log has no remaining capacity.
    bool add(const T& value)
    {
        if (count == CAPACITY)
        {
            return false;
        }

        values[count] = value;
        count++;
        return true;
    }

    // TODO (Part C): Write get. It receives a valid index and returns its stored value.
    T get(int index) const
    {
        // Precondition: index is between 0 and count - 1.
        return values[index];
    }

    // TODO (Part C): Write size as a const member function.
    int size() const
    {
        return count;
    }  
    // TODO (Part C): Write isEmpty as a const member function.
    bool isEmpty() const
    {
        return count == 0;
    }

    bool contains(const T& target) const;
};

// ===== Do not resolve these TODOs yet (Part D) =====
// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.
template <typename T>
bool MetricLog<T>::contains(const T& target) const
{
    for (int i = 0; i < count; i++)
    {
        if (values[i] == target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    MetricLog<int> waitlistCounts;

    waitlistCounts.add(6);
    waitlistCounts.add(11);

    cout << "First waitlist count: "
         << waitlistCounts.get(0) << endl;
    cout << "Stored waitlist counts: "
         << waitlistCounts.size() << endl;

    // ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    MetricLog<double> sessionDurations;
    // TODO (Part E): Add two dummy duration values to that log.
    sessionDurations.add(10.5);
    sessionDurations.add(15.2);
    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    cout << "Contains 10.5: "
         << sessionDurations.contains(10.5) << endl;
    cout << "Contains 20.0: "
         << sessionDurations.contains(20.0) << endl;
    // TODO (Part E): Print descriptive English labels for all results.


    return 0;
}