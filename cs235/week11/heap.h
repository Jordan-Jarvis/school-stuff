/***********************************************************************
* Program:
*    Week 11, Sorting
*    Brother Ercanbrack, CS 235
*
* Author:
*   Jordan Jarvis
************************************************************************/
#include <vector>

using namespace std;
template <class T>
void heapSort(vector<T> &data);
template <class T>
void heapify(vector<T> &data);
template <class T>
void percDown(vector<T> &data, int n, int parent);

/*************************************************************************
* This function sorts a vector using a heap sort.
* Input:  data -  Vector to be sorted.
* Output: data -  Vector sorted
**************************************************************************/
template <class T>
void heapSort(vector<T> &data)
{
    heapify(data);

    for (int i = data.size() - 1; i >= 2; --i)
    {
        T temp = data[1];
        data[1] = data[i];
        data[i] = temp;

        percDown(data, i - 1, 1);
    }
}
/*************************************************************************
* FUNCTION: percDown
* DESCRIPTION: This function percalate down a vector
**************************************************************************/
template <class T>
void percDown(vector<T> &data, int n, int parent)
{
    int child = 2 * parent;

    while (parent <= n)
    {
        if (child < n && data[child] < data[child + 1])
        {
            child++;
        }

        if (child > n)
        {
            return;
        }

        if (data[parent] < data[child])
        {
            T temp = data[child];
            data[child] = data[parent];
            data[parent] = temp;

            parent = child;
            child = 2 * child;
        }
        else
        {
            parent++;
            child = 2 * parent;
        }
    }
}

/*************************************************************************
* FUNCTION: heapify
* DESCRIPTION: This function turns a vector into a heap
**************************************************************************/
template <class T>
void heapify(vector<T> &data)
{
    for (int i = (data.size() - 1) / 2; i >= 1; --i)
    {
        percDown(data, data.size(), i);
    }
}

