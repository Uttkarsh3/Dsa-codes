#include<stdlib.h>
#include<stdio.h>
void merge(a[],b[],c[],m,n)
{
    int i,j,k;
    i=j=k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<m)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n)
    {
        c[k]=b[j];
        k++;
        j++;
    }
}

int main()
{
    int a[]
    merge(int a[], int b[], int c[], int m, int n);
    return 0;
}