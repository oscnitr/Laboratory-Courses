function [ count ] = bubbles( a,n )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
count = 0;
for i = 1:n
    for j = 1:n-i
        count = count+1;
        if a(j) > a(j+1)
            count = count + 1;
            temp = a(j);
            a(j) = a(j+1);
            a(j+1) = temp;
        end
    end
end

end

