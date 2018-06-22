x = zeros(1,10);
A = zeros(1,10);
B = zeros(1,10);
 
ip = 1;
 
for n = 10:10:100
    arr = round(rand(1,n)*100);
    P = arr;
    
    %fprintf('\nArray : %d',P);
    
    x(ip) = n;
    A(ip) = quick(arr,n);
    B(ip) = m_quick(P,n);
    
    ip = ip + 1;
end
plot(x,A,x,B);
title('Sorting comparison when insertion sort is introduced in quick sort');
xlabel('Number of elements');
ylabel('Number of comparisions');
disp('Analysis of sortings');
legend('quick sort','quick sort followed by insertion sort');
grid on;
