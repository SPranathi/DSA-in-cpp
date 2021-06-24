def mergesort(arr):
    if len(arr)>1:
        mid=len(arr)//2 
        L=arr[:mid]
        R=arr[mid:]
        mergesort(L)
        mergesort(R)
        i=j=k=0
        while i<len(L) and j<len(R):
            if(L[i]<R[j]):
                arr[k]=L[i]
                i+=1
            else:
                arr[k]=R[j]
                j+=1
            k+=1
        while i<len(L):
            arr[k]=L[i]
            i+=1
            k+=1
        while j<len(R):
            arr[k]=R[j]
            j+=1
            k+=1
def printarray(arr):
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()
n=int(input("Enter the size of the array:"))
print("Enter the elements of the array:")
arr=[]
for i in range(n):
    ele=int(input())
    arr.append(ele)
mergesort(arr)
print("Sorted array:")
printarray(arr)
