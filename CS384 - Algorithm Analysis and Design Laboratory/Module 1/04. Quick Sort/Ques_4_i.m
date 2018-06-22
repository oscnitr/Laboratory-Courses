x = zeros(1,10);
A = zeros(1,10);
B = zeros(1,10);
C = zeros(1,10); 
ip = 1;
 
for n = 10:10:100
    arr = round(rand(1,n)*100);
    P = arr;
    Q = arr;
    
    %fprintf('\nArray : %d',P);
    
    x(ip) = n;
    A(ip) = quick(arr,n);
    B(ip) = first_quick(P,n);
    C(ip) = rand_quick(Q,n);
    
    ip = ip + 1;
end
plot(x,A,x,B,x,C);
title('Types of quick Sort');
xlabel('Number of elements');
ylabel('Number of comparisions');
disp('Analysis of sortings');
legend('Pivot present at Last','Pivot present At First','Random Pivot');
grid on;
