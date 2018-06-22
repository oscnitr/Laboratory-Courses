function [ arr, index, n ] = partition_quickSelect( arr, left, right, n)
    
    pivot = arr(1);
    i = left;
    j = right;
   
    while(i < j)
        while(pivot >= arr(i) && i < right)
            i = i + 1;
            n = n + 1;
        end
        
        while(pivot < arr(j) && j > left )
            j = j - 1;
            n = n + 1;
        end
        
        if(i < j)
            temp = arr(i);
            arr(i) = arr(j);
            arr(j) = temp;
        end
    end
    
        arr(1) = arr(j);
        arr(j) = pivot;
        index = j;
end

