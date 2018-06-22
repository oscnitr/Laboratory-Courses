x = zeros(1,10);
a = zeros(1,10);
b = zeros(1,10);
c = zeros(1,10);
d = zeros(1,10);
e = zeros(1,10);



ip = 1;

for n = 10:10:100
    A =  round(rand(1,n) * 100 );
    B = A;
    C = A;
    D = A;
    E = A;
    x(ip) = n;
    a(ip) = bubbles(A,n);
    b(ip) = quick(B,n);
    c(ip) = Insertion_sort(C,n);
    d(ip) = Selection_sort(D,n);
    e(ip) = mergeS(E,n);
    ip = ip + 1;
end
plot(x,a,x,b,x,c,x,d,x,e);
title('Randomly Generated Array');
xlabel('Number of elements');
ylabel('Number of comparisions');
disp('Analysis of different sorting methods');
legend('Bubble Sort','Quick Sort','Insertion Sort','Selection Sort','Merge Sort');
grid on;
