#Time complexity of Quick sort is O(n^2)

def partition(arr,si,ei):
    pivot=arr[ei]
    pindex=si
    for i in range(si,ei):
        if(arr[i]<=pivot):
            arr[i],arr[pindex]=arr[pindex],arr[i]
            pindex+=1
    arr[pindex],arr[ei]=arr[ei],arr[pindex]
    return pindex
def quicksort(arr,si,ei):
    if(si>=ei):
        return 
    pi=partition(arr,si,ei)
    quicksort(arr,si,pi-1)
    quicksort(arr,pi+1,ei)
n=int(input("Enter the size of the array:"))
print("Enter the elements of the array: ")
arr=[]
for i in range(n):
    ele=int(input())
    arr.append(ele)
quicksort(arr,0,n-1)
for i in range(n):
    print(arr[i],end=" ")