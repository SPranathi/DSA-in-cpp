#selection sort in python3
def selectionsort(arr,n):
    for i in range(n):
        min=i   
        for j in range(i+1,n):
            if(arr[j]<arr[min]):
                min=j
        arr[i],arr[min]=arr[min],arr[i] #swaping the minimum element and element at beginning
n=int(input("Enter the size of the array:"))
arr=[]
print("Enter the elements of the array:")
for i in range(n):
    ele=int(input())
    arr.append(ele)
selectionsort(arr,n)
print("Sorted array in Ascending order by using Selection Sort:")
print(arr)
