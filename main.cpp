//Author: Ryan Phadnis
//Course: CSC 112
//Project 2: Merge Sort
//9/19/2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// function declarations

// Divide the function down
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);

//Merge it back up
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Type in the seed and length: " << endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge

    vector<int> test = {47, 23, 71, 6};
    vector<int> testTwo(4);

    mergeSort(test, testTwo, 0, 3);

    //testing the test array
    for(int i = 1; i < test.size() - 1; i++) {
        assert(test.at(i-1) <= test.at(i));
    }

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v, t, 0, v.size() - 1);

    // check output, make sure it's sorted

    // print ending output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right)
{
    //base case: return if size is 1
    if(right <= left)
    {
        return;
    }
    int midpoint = (right + left) / 2;
    //split into pieces (left)
    mergeSort(a, tmp, left, midpoint);
    //split into pieces (right)
    mergeSort(a, tmp, midpoint + 1, right); //may need a + 1 in here
    //call the merge function
    mergeSortedLists(a, tmp, left, midpoint, right);
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right)
{
    int tleft = left; // left indexes
    int mid = (middle + 1); // right indexes
    int tright = left; // temp indexes
    while (tleft < (middle + 1) && mid < (right + 1))
    {
        if (a.at(tleft) < a.at(mid))
        {
            tmp.at(tright) = a.at(tleft);
            tleft++;
            tright++;
        }
        else
        {
            tmp.at(tright) = a.at(mid);
            mid++;
            tright++;
        }
    }
    if (tleft >= (middle + 1)) //if left list is finished
        {
        while (mid <= right)
        {
            tmp.at(tright) = a.at(mid);
            mid++;
            tright++;
        }
    }
    else if (mid >= right) //if right list is finished
        {
        while (tleft < (middle + 1))
        {
            tmp.at(tright) = a.at(tleft);
            tleft++;
            tright++;
        }
    }

    for(int i = left; i <= right; i++)
    {
        a.at(i) = tmp.at(i);
    }
}