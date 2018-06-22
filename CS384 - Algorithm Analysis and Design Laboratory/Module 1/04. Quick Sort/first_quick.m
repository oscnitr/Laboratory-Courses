function [ count ] = first_quick( a,n )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
 
count = 0;
l = 1;
u = n;
[a,count] = s_quickSort(a,l,u,count);
 
end
 
function [a,count] = s_quickSort(a,l,u,count)
    p = 0;
    if l<u
        [a,p,count] = s_partition(a,l,u,count);
        [a,count] = s_quickSort(a,l,p-1,count);
        [a,count] = s_quickSort(a,p+1,u,count);
    end
end
 
function [a,p,count] = s_partition(a,l,u,count)
    pivot = l;
    i = u;
    j = u;
    while i>l
        count = count+1;
        if a(i) >= a(pivot)
            temp = a(i);
            a(i) = a(j);
            a(j) = temp;
            j = j-1;
        end
        i = i-1;
    end
    temp = a(j);
    a(j) = a(i);
    a(i) = temp;
    p = j;
end
