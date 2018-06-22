function [ count ] = quick( a,n )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
count = 0;
l = 1;
u = n;
[a,count] = quickSort(a,l,u,count);
 
end
function [a,count] = quickSort(a,l,u,count)
    p=0;
    if(l<u)
        [a,p,count] = part(a,l,u,count);
        [a,count] = quickSort(a,l,p-1,count);
        [a,count] = quickSort(a,p+1,u,count);
    end
end
 
function [a,p,k] = part(a,l,u,k)
    pivot = u;
    i = l;
    j = l;
    while i<u
        k = k+1;
        if a(i) <= a(pivot)
            temp = a(i);
            a(i) = a(j);
            a(j) = temp;
            j = j+1;
        end
        i = i+1;
    end
    temp = a(j);
    a(j) = a(i);
    a(i) = temp;
    p = j;
end
