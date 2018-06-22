n = 5;
Wts = [1, 2, 5, 6, 7]
V = [1, 6, 18, 22, 28]
Capacity = 11; 
[max, Seq] = knapsack_algo(Wts, V, Capacity);
fprintf ('Max values is %d\n',max);
items = find(Seq);
fprintf('Items are \n');
disp(items);