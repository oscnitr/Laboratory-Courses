function [ count ] = m_bubbles( B,n )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
count = 0;
for i = 1:n
    flag = 0;
    for j = 1:n-i
        count = count+1;
        if B(j) > B(j+1)
            count = count + 1;
            flag = 1;
            temp = B(j);
            B(j) = B(j+1);
            B(j+1) = temp;
        end
    end
    if flag == 0
      break;
    end
end

end

