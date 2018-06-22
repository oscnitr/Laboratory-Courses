function [ ans ] = Binomial( n,k )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
    c=zeros(n,k+1);
    for i=1:n
        for j=1:min(i+1,k+1)
            %co=co+1;
            if j==1 || j==i+1
                c(i,j)=1;
            else
                c(i,j)=c(i-1,j-1)+c(i-1,j);
            end
        end
    end
    ans=c(n,k+1);
    disp(c);
end

