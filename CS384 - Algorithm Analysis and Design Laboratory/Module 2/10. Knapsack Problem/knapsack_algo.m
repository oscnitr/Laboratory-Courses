function [Max ,Seq] = knapsack_algo(Wts, V, Capacity)
    A = zeros(length(Wts)+1,Capacity+1);
    for j = 1:length(Wts)
        for X = 1:Capacity
            if Wts(j) > X
                A(j+1,X+1) = A(j,X+1);
            else
                A(j+1,X+1) = max( A(j,X+1), V(j) + A(j,X-Wts(j)+1));
            end
        end
    end
   Max = A(end,end);
   
   %Finding the optimal sequence
   Seq = zeros(length(Wts),1);
   a = Max;
   j = length(Wts); 
   X = Capacity;
   while a > 0
       while A(j+1,X+1) == a
           j = j - 1;
       end
       j = j + 1; 
       Seq(j) = 1;
       X = X - Wts(j);
       j = j - 1;
       a = A(j+1,X+1);
   end
end