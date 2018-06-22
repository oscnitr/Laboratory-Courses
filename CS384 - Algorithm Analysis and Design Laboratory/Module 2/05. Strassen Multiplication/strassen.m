function [ C ct] = strassen( A, B, ct )
    n = size(A, 1);
%disp(n);
    if (n == 1)
        C = A * B;
        ct = ct + 1;
     
    else
        A11 = A(1: n/2 , 1: n/2);
        A12 = A(1: n/2 , n/2+1: n);
        A21 = A(n/2+1: n , 1: n/2);
        A22 = A(n/2+1: n , n/2+1: n);
        B11 = B(1: n/2 , 1: n/2);
        B12 = B(1: n/2 , n/2+1: n);
        B21 = B(n/2+1: n , 1: n/2);
        B22 = B(n/2+1: n , n/2+1: n);
        
        [M1 ct] = strassen(A11 + A22, B11 + B22, ct);
        [M2 ct] = strassen(A21 + A22, B11, ct);
        [M3 ct] = strassen(A11, B12 - B22, ct);
        [M4 ct] = strassen(A22 , B21 - B11, ct);
        [M5 ct] = strassen(A11 + A12, B22, ct);
        [M6 ct] = strassen(A21 - A11, B11 + B12, ct);
        [M7 ct] = strassen(A12 - A22, B21 + B22, ct);
        
        C(1: n/2 , 1: n/2) = M1 + M4 - M5 + M7;
        C(1: n/2 , n/2+1: n) = M3 + M5;
        C(n/2+1: n , 1: n/2) = M2 + M4;
        C(n/2+1: n , n/2+1: n) = M1 + M3 - M2 + M6;
        
        
    end
end

