function [ min ] = MatrixChainOrder_Memorised( p, i, j )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    if i==j
        min = 0;
    else
        min = Inf;
        cnt = 0;
        for k = i:j-1
            cnt = MatrixChainOrder_Memorised(p,i,k) + MatrixChainOrder_Memorised(p,k+1,j) + p(i-1)*p(k)*p(j);
            if cnt<min
                min = cnt;
            end
        end
    end
end

