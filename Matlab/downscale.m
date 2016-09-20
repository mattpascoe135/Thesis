function [ABCDnew] = downscale(ABCD, num)
    ABCDnew = zeros(1+(((numel(ABCD)/5)-1)/num), 5);
 
    %setup count and write in first sparameter data
    count = 0;
    ABCDnew(1,1)=ABCD(1,1);
    ABCDnew(1,2)=ABCD(1,2);
    ABCDnew(1,3)=ABCD(1,3);
    ABCDnew(1,4)=ABCD(1,4);
    ABCDnew(1,5)=ABCD(1,5);
    
    %iterate through the rest of the array
    for i=2:(numel(ABCD)/5)
        count = count +1;
        if(count >= num)
            count = 0;
            
            %transfer data into new smaller array
            ABCDnew((((i-1)/num)+1), 1) = ABCD(i,1);
            ABCDnew((((i-1)/num)+1), 2) = ABCD(i,2);
            ABCDnew((((i-1)/num)+1), 3) = ABCD(i,3);
            ABCDnew((((i-1)/num)+1), 4) = ABCD(i,4);
            ABCDnew((((i-1)/num)+1), 5) = ABCD(i,5);
            
        end
        
        
    end