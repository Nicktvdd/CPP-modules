#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    // Constructor
    return;
}

PmergeMe::~PmergeMe(void) {
    // Destructor
    return;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Copy constructor
    *this = other;
    return;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // Assignment operator
    if (this != &other) {
        // Clear the current vector
        this->vec.clear();
        // Copy elements from the other vector to this vector
        for (unsigned long i = 0; i < other.vec.size(); i++) {
            this->vec.push_back(other.vec[i]);
        }
        // Clear the current deque
        this->deq.clear();
        // Copy elements from the other deque to this deque
        this->deq = other.deq;
    }
    return (*this);
}

void PmergeMe::fillVec(char** input) {
    std::string token;
    int number;
    int i = 1;
    while (input[i]) {
        token = input[i];
        // Check if the token contains only digits
        for (unsigned long i = 0; i < token.length(); i++) {
            if (!std::isdigit(token[i]))
                throw PmergeMe::DigitException();
        }
        // Convert the token to an integer
        if (std::istringstream(token) >> number) {
            vec.push_back(number);
        } else
            throw PmergeMe::ConversionException();
        i++;
    }
    return;
}

void PmergeMe::fillDeq(char** input) {
    std::string token;
    int number;
    int i = 1;
    while (input[i]) {
        token = input[i];
        // Check if the token contains only digits
        for (unsigned long i = 0; i < token.length(); i++) {
            if (!std::isdigit(token[i]))
                throw PmergeMe::DigitException();
        }
        // Convert the token to an integer
        if (std::istringstream(token) >> number) {
            deq.push_back(number);
        } else
            throw PmergeMe::ConversionException();
        i++;
    }
    return;
}

void PmergeMe::printVector(int flag) {
    if (flag == 1)
        std::cout << "Before (vec): ";
    else if (flag == 2)
        std::cout << "After (vec):  ";
    else if (flag == 3)
        std::cout << "Before:       ";
    for (unsigned long i = 0; i < vec.size(); i++) {
        std::cout << " " << vec[i];
    }
    std::cout << std::endl;
    return;
}

void PmergeMe::printDeque(int flag) {
    if (flag == 1)
        std::cout << "Before (deq): ";
    else
        std::cout << "After (deq):  ";
    std::deque<int>::iterator it;
    for (it = deq.begin(); it != deq.end(); it++) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
    return;
}

void PmergeMe::mergeVec(std::vector<int>& myVec, std::vector<int>& left, std::vector<int>& right) {
    int l = 0, r = 0, v = 0;
    int leftSize = left.size();
    int rightSize = right.size();
    // Merge elements of left and right vectors into myVec
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            myVec[v] = left[l]; // Copy the smaller element from left
            l++;
        } else {
            myVec[v] = right[r]; // Copy the smaller element from right
            r++;
        }
        v++;
    }
    // If there are any remaining elements in left, copy them to myVec
    while (l < leftSize) {
        myVec[v] = left[l];
        l++;
        v++;
    }
    // If there are any remaining elements in right, copy them to myVec
    while (r < rightSize) {
        myVec[v] = right[r];
        r++;
        v++;
    }
    return;
}

void PmergeMe::insertionSortVec(std::vector<int>& myVec, int vecsize) {
    for (int i = 1; i < vecsize; i++) {
        int key = myVec[i]; // Current element to be inserted
        int comp = i - 1; // Start comparison from the previous element

        // Move elements that are greater than key to one position ahead of their current position
        while (comp >= 0 && myVec[comp] > key) {
            myVec[comp + 1] = myVec[comp];
            comp--;
        }

        // Insert key to the correct position
        myVec[comp + 1] = key;
    }
    return;
}

void PmergeMe::mergeInsertionSortVec(std::vector<int>& myVec) {
    int vecsize = myVec.size();
    if (vecsize <= 1)
        return;
    if (vecsize <= 10) // Threshold value for insertion sort
        insertionSortVec(myVec, vecsize);
    else {
        int mid = vecsize / 2; // Divide the vector into two
        std::vector<int> left(myVec.begin(), myVec.begin() + mid); // Elements from begin to mid
        std::vector<int> right(myVec.begin() + mid, myVec.end()); // Elements from mid to end

        // Recursively sort the divided vectors
        mergeInsertionSortVec(left);
        mergeInsertionSortVec(right);

        // Merge the sorted halves back together
        mergeVec(myVec, left, right);
    }
    return;
}

void PmergeMe::mergeDeq(std::deque<int>& myDeq, std::deque<int>& left, std::deque<int>& right) {
    int l = 0, r = 0, d = 0;
    int leftSize = left.size();
    int rightSize = right.size();
    // Merge elements of left and right deques into myDeq
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            myDeq[d] = left[l]; // Copy the smaller element from left
            l++;
        } else {
            myDeq[d] = right[r]; // Copy the smaller element from right
            r++;
        }
        d++;
    }
    // If there are any remaining elements in left, copy them to myDeq
    while (l < leftSize) {
        myDeq[d] = left[l];
        l++;
        d++;
    }
    // If there are any remaining elements in right, copy them to myDeq
    while (r < rightSize) {
        myDeq[d] = right[r];
        r++;
        d++;
    }
    return;
}

void PmergeMe::insertionSortDeq(std::deque<int>& myDeq, int deqsize) {
    for (int i = 1; i < deqsize; i++) {
        int key = myDeq[i]; // Current element to be inserted
        int comp = i - 1; // Start comparison from the previous element

        // Move elements that are greater than key to one position ahead of their current position
        while (comp >= 0 && myDeq[comp] > key) {
            myDeq[comp + 1] = myDeq[comp];
            comp--;
        }

        // Insert key to the correct position
        myDeq[comp + 1] = key;
    }
    return;
}
// Merge and sort a deque using insertion sort
void PmergeMe::mergeInsertionSortDeq(std::deque<int>& myDeq) {
    int deqsize = myDeq.size();
    if (deqsize <= 1)
        return;
    
    // If the deque size is small, use insertion sort
    if (deqsize <= 10)
        insertionSortDeq(myDeq, deqsize);
    else {
        int mid = deqsize / 2;
        std::deque<int> left, right;
        
        // Divide the deque into two halves
        for (int i = 0; i < mid; i++) {
            left.push_back(myDeq[i]);
        }
        for (int i = mid; i < deqsize; i++) {
            right.push_back(myDeq[i]);
        }
        
        // Recursively sort the divided deques
        mergeInsertionSortDeq(left);
        mergeInsertionSortDeq(right);

        // Merge the sorted halves back together
        mergeDeq(myDeq, left, right);
    }
    return;
}

// Process the input vector
void PmergeMe::processVec(char** input) {
    vecStart = clock();
    fillVec(input);
    mergeInsertionSortVec(this->vec);
    vecEnd = clock();
    ticks = static_cast<double>(vecEnd - vecStart);
    vecTime = ticks / CLOCKS_PER_SEC * 1000000;
    return;
}

// Process the input deque
void PmergeMe::processDeq(char** input) {
    deqStart = clock();
    fillDeq(input);
    mergeInsertionSortDeq(this->deq);
    deqEnd = clock();
    ticks = static_cast<double>(deqEnd - deqStart);
    deqTime = ticks / CLOCKS_PER_SEC * 1000000;
    return;
}

// Print the processing times
void PmergeMe::printTimes(void) {
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
}

// Exception class for invalid integer input
const char* PmergeMe::IntegerException::what() const throw() {
    return ("Input not valid: supported value range 0 -> MAX_INT\0");
}

// Exception class for non-digit input
const char* PmergeMe::DigitException::what() const throw() {
    return ("Input not valid: Just digits please.\0");
}

// Exception class for failed conversion to integer
const char* PmergeMe::ConversionException::what() const throw() {
    return ("Failed converting token to int.\0");
}