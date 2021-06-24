# Bubblesort in python3
def bubblesort(arr,n):
    #loop through each element in array
    for i in range(n):
        swap=False  #keeping the track of swapping
        #loop for compare elements
        for j in range(n-i-1):
            #compare adjacent elements
            if(arr[j]>arr[j+1]):
                temp=arr[j]
                arr[j]=arr[j+1]
                arr[j+1]=temp
                #if swapping occurs set swap to true
                swap=True
        #no swap means array is sorted
        if not swap:
            break
n=int(input("Enter the size of the array to be sorted:"))
print("Enter the elements of the array:")
arr=[]
for i in range(n):
    ele=int(input())
    arr.append(ele)
bubblesort(arr,n)
print("Sorted array in Ascending order using Bubble Sort:")
print(arr)


