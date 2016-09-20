function [data] = ABCDTosParam(ABCD)
    Z0 = 50;
    
    data = zeros(numel(ABCD)/5, 5);
    
    for i = 1:(numel(data)/5)
        A = ABCD(i,2);
        B = ABCD(i,3);
        C = ABCD(i,4);
        D = ABCD(i,5);
        
        data(i,1) = ABCD(i,1);
        data(i,2) = (A+(B/Z0)-C*Z0-D)/(A+(B/Z0)+C*Z0+D);
        data(i,3) = (2*(A*D-B*C))/(A+(B/Z0)+C*Z0+D);
        data(i,4) = (2)/(A+(B/Z0)+C*Z0+D);
        data(i,5) = (-A+(B/Z0)-C*Z0+D)/(A+(B/Z0)+C*Z0+D);
    end