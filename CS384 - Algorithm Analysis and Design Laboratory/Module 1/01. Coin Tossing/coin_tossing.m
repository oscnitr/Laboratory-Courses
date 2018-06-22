%clear all;
prob_1 = zeros(1,10000);
c = zeros(1,10000);
for n = 1:10000
    A = round(rand(1,n));
    count_1 = 0;
    c(n) = n;
    for i = 1:n
        if A(i) == 1    % HEAD is denoted by 1. 
            count_1 = count_1 + 1;
        end
    end    
    prob_1(n) = count_1 / n;
end
plot(c,prob_1);
title('Coin Tossing');
xlabel('Number of toss');
ylabel('Probability');
disp('Analysis of coin tossing');
legend('Prob. of HEAD');
grid on;