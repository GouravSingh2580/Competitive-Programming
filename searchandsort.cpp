#include<iostream>
#include<stdlib.h>
using namespace std;

int AB[50];

void input(int a)
{
 for(int i=0;i<a;i++)
        cin>>AB[i];
 cout<<"entered elements are  ::";
 for(int i=0;i<a;i++)
        cout<<AB[i]<<"\t";
        cout<<"\n";
}
void printArray( int s)
{
    int i;
    for (i = 0; i < s; i++)
        cout << AB[i] << " ";
    cout << endl;
}
void linearSearch(int a)
{
    int i;
    int x;
    cout<<"enter the element to be searched  ";
    cin>>x;
    cout<<endl;
    int found=0;
    for (i = 0; i < a; i++)
    {
        if (AB[i] == x)
        {
		   found=1;
           break;
        }
    }
    if(found==1)
       cout<<"Elemnet found at "<<i+1<<" position"<<endl;
    else
	   cout<<"Not found" ;
}
int binarySearch( int l, int r,int y)   // only position of 1st and last element is passed as argument as  the array is global
{
   
    if (r >= l) {
        int mid = (l + r )/ 2;

        // If the element is present at the middle
        if (AB[mid] ==y)
            return mid;

        // If element is smaller than mid, then it can only be present in left
        if (AB[mid] > y)
            return binarySearch( l, mid - 1,y);

        // Else the element can only be present in right s
        return binarySearch( mid + 1, r,y);
        
    }
	else
	    return -1;
    // We reach here when element is not
    // present in array
    return -1;
}
void swapped(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort( int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (AB[j] > AB[j+1])
            swapped(&AB[j], &AB[j+1]);
   printArray(n);
}

void selectionSort( int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (AB[j] < AB[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swapped(&AB[min_idx], &AB[i]);
    }
    printArray(n);
}
void insertionSort( int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = AB[i];
        j = i - 1;

        /* Move elements of AB[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && AB[j] > key)
        {
            AB[j + 1] = AB[j];
            j = j - 1;
        }
        AB[j + 1] = key;
    }
   
}
int part ( int low, int high)
{
    int pivot = AB[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (AB[j] < pivot)
        {
            i++; // increment index of smaller element
            swapped(&AB[i], &AB[j]);
        }
    }
    swapped(&AB[i + 1], &AB[high]);
    return (i + 1);
}
void quickSort( int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, AB[p] is nownat right place
        int pi = part( low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort( low, pi - 1);
        quickSort( pi + 1, high);
    }
    
}
void merger(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = AB[l + i];
    for (j = 0; j < n2; j++)
        R[j] = AB[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            AB[k] = L[i];
            i++;
        }
        else {
            AB[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        AB[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        AB[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort( int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort( l, m);
        mergeSort( m + 1, r);

        merger( l, m, r);
    }
}
int main()
{  int a;
    cout<<"enter the number of elements you want to enter ";
   cin>>a;
   cout<<"\n enter array";
   input(a);
   char y='y';
   int x;
   int f,e;

   do
    { //system("cls");
    cout<<"enter choice:: ";

    cout<<"\n 1 for linear search ";
    cout<<"\n 2 for binary search ";
    cout<<"\n 3 for Bubble sort ";
    cout<<"\n 4 for Selection sort ";
    cout<<"\n 5 for insertion sort";
    cout<<"\n 6 for quick sort ";
    cout<<"\n 7 for merge sort"<<endl;
    cin>>x;
	cout<<endl;
    switch(x)
    {
        case 1: linearSearch(a);
                break;
        case 2: cout<<"Enter the number to be searched ";
        		cin>>e;
        		f=binarySearch(0,a-1,e);
        		if(f!=-1)
        		    cout<<"Element found at "<<f+1<<endl;
        		else
					cout<<"Elemnet not found"<<endl;    
                break;
        case 3: bubbleSort(a);
                break;
        case 4: selectionSort(a);
                break;
        case 5: insertionSort(a);
        		printArray(a);
                break;
        case 6: quickSort(0,a-1);
        		printArray(a);
                break;
        case 7: mergeSort(0,a-1);
        		printArray(a);
                break;
        default:
            cout<<"enter valid choice";
            break;
    }
    cout<<"enter y to do continue ";
    cin>>y;
    }while(y=='y');
 return 0;
}
