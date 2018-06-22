function [ ct ] = multiply( a,b,n )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
ct=0;
c=zeros(n,n);
for i=1:n
    for j=1:n
       for k=1:n
          c(i,j)=c(i,j)+a(i,k)*b(k,j);
          ct=ct+1;
      end
    end
end
%disp(ct);
end

