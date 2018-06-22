p = [12,21,65,18,24,93,121,16,41,31,47,5,47,29,76,18,72,15];

%count1 = MatrixChainOrder_Memorised(p,2,18);
count2 = MatrixChainOrder_DP(p,17);
%display(count1);
fprintf('No. of operations required are : %d\n',count2);
%display(count2);