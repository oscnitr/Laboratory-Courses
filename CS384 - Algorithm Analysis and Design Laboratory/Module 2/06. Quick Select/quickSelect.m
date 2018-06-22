function [ m, n ] = quickSelect(a, k, n)
    
    l = 1;
    s = length(a);
    [a, pivot, n] = partition_quickSelect(a, l, s, n);
    if(pivot == k)
        m = a(pivot);
    elseif (pivot > k)
        s = pivot-1;
        a = a(l:s);
        [m, n] = quickSelect(a, k, n);
    else
        l = pivot + 1;
        k = k - pivot;
        a = a(l:s);
        [m, n] =  quickSelect(a, k, n);
    end
end