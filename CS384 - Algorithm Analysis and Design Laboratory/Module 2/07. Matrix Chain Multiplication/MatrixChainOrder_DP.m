function [ c ] = MatrixChainOrder_DP( p,n )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
   m = zeros(n,n);
   for L = 2:n
       for i = 1:n-L+1
           j = i+L-1;
           m(i,j) = intmax();
           for k = i:j-1
               q = m(i,k) + m(k+1,j) + p(i)*p(k+1)*p(j+1);
               if q < m(i,j)
                   m(i,j) = q;
               end
           end
       end
   end
   c = m(1,n);
   display(m);

end

