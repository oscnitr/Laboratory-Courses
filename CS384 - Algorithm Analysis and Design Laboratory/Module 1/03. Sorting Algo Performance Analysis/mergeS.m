function [ count ] = mergeS( a,n )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
 
count = 0;
l = 1;
u = n;
[a,count]=mergeSort(a,l,u,count);
 
end
 
function [a,count] = mergeSort(a,l,u,count)
m = floor((l+u)/2);
if(l<u)
    [a,count] = mergeSort(a,l,m,count);
    [a,count] = mergeSort(a,m+1,u,count);
    [a,count] = pivot(a,l,m,u,count);
end
end
 
function [a,d] = pivot(a,l,m,u,d)
    s1 = m-l+1;
    s2 = u-m;
    b = zeros(1,s1);
    c = zeros(1,s2);
    for i = 1:s1
        b(i) = a(l+i-1);
    end
    for i = 1:s2
        c(i) = a(m+i);
    end
    i = 1; j = 1; k = l;
    while i <= s1 && j <= s2
        d = d+1;
        if b(i) <= c(j)
            a(k) = b(i);
            i = i+1;
        else
            a(k) = c(j);
            j = j+1;
        end
        k = k+1;
    end
    while i <= s1
        a(k) = b(i);
        i = i+1;
        k = k+1;
    end
    while j <= s2
        a(k) = c(j);
        j = j+1;
        k = k+1;
    end
end
