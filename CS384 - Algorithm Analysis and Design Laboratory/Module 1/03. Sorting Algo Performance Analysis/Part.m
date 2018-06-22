function [ i ] = Part( A , p , r, count )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
    
    x = A(r);
    i = p-1;
    for j = p:r-1
        count = count + 1;
        if A(j) <= x
            count = count + 1;
            i = i+1;
            temp = A(i);
            A(i) = A(j);
            A(j) = temp;
        end
    end
    temp1 = A(i+1);
    A(i+1) =  A(r);
    A(r) = temp1;
    i = i+1;
end

