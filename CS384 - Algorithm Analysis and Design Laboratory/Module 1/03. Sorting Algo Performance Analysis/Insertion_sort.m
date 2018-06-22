function [ count ] = Insertion_sort( a,n )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    count = 0;
    for j = 2:n
        k = a(j);
        i = j-1;
        while i>=1 && a(i) > k 
            count = count + 1;
            a(i+1) = a(i);
            i = i - 1;
        end
        if j~=0
            count = count + 1;
        end
        a(i+1) = k;
    end
end