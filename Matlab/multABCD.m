function [abcdres] = multABCD(abcd1, abcd2)
    length = numel(abcd1)/5;

    abcdres = zeros(length, 5);

    if(numel(abcd1/5) ~= numel(abcd2/5))
        disp('ERROR: ABCD matrix size mismatch');
        return;
    end
    
    for i = 1:length
        if(abcd1(i,1) ~= abcd2(i,1))
            disp('ERROR: frequency mismatch in ABCD matrix multiplication');
        end
        
        abcdres(i,1) = abcd1(i,1);
        
        %setup empty abcd matrix, then fillup with data
        tmpABCD1 = zeros(2,2);
        tmpABCD2 = zeros(2,2);
        
        tmpABCD1(1,1) = abcd1(i,2);
        tmpABCD1(1,2) = abcd1(i,3);
        tmpABCD1(2,1) = abcd1(i,4);
        tmpABCD1(2,2) = abcd1(i,5);
        
        tmpABCD2(1,1) = abcd2(i,2);
        tmpABCD2(1,2) = abcd2(i,3);
        tmpABCD2(2,1) = abcd2(i,4);
        tmpABCD2(2,2) = abcd2(i,5);
        
        %perform multiplation
        tmp = tmpABCD1 * tmpABCD2;
        abcdres(i,2) = tmp(1,1);
        abcdres(i,3) = tmp(1,2);
        abcdres(i,4) = tmp(2,1);
        abcdres(i,5) = tmp(2,2);        
    end