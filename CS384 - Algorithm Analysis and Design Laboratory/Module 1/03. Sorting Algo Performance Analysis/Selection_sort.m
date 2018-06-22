function [ count ] = Selection_sort( a , n )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
     count = 0;
     for i = 1:n
        small = a(i);
        pos = i;
        for j = i+1:n
            count = count + 1;
            if a(j)<small
                count = count + 1;
                small = a(j);
                pos = j;
            end
            temp = a(i);
            a(i) = a(pos);
            a(pos) = temp;
        end
     end
end