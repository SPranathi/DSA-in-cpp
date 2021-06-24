def insertionsort(arr,n):
    for i in range(n):
        for j in range(i-1,-1,-1):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
            else:
                break 
n=int(input("Enter the size of the array:"))
arr=[]
print("Enter elements of the array:")
for i in range(n):
    l=int(input())
    arr.append(l)
insertionsort(arr,n)
print("Sorted array in Ascending order by using Insertion Sort:")
print(arr)
