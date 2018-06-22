x =  [50:25:500];
y = zeros(1,length(x));
fprintf('\nSize of array\t3rd largest element\n');
for i = 1:length(x)
        a = round(rand(x(i))*1000);
        %disp(a);
        [m, y(i)] = quickSelect(a, 3, 0);
        fprintf('\t%d\t\t\t\t%d\n',x(i),m);        
end
plot(x,y);
xlabel('No of elements');
ylabel('No of comparisons');
legend('Quickselect performance');
grid on;