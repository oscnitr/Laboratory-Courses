clc;

arr=zeros(1,1000);
a=zeros(1,1000);

for	i=1:1000 arr=round(rand(1,i)*100);


crr=arr;

d(i)=quicks(crr,1,i);

curve(i)=i;
end

plot(curve, d);
title('Performance analysis');
xlabel('no of element' );
ylabel('no of comp');
legend('quick sort comparision');
grid on;
disp ('Analyzing the performance');
