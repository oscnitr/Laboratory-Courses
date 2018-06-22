r = [1:1:5]; 
s = zeros(length(r), 1);
n = zeros(length(r), 1);
for i = 1:length(r)
    x(i)=2^r(i);
        a = randi(100, x(i));
        b = randi(100, x(i));
        [dummy,s(i)] = strassen(a,b, 0);
        n(i) = multiply(a,b,x(i));
        %r(i) = x(i);
end
plot(r, s,r, n);
grid on;
title('Comparison of strassen and normal multiplication');
legend('Strassen', 'Normal');
