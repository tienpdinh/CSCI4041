def swap(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp

def permute(lst, i):
    if i < len(lst):
        j = i
        while j < len(lst):
            swap(lst, i, j)
            permute(lst, i + 1)
            swap(lst, i, j)
            j += 1
    else:
        print(lst)

if __name__ == '__main__':
    lst = [1,2,3]
    permute(range(6), 0)
            
