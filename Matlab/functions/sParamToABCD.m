function [ABCD] = sParamToABCD(data)
    Z0 = 50;
    
    ABCD = zeros(numel(data, 5));
    
%     for i = 1:(numel(data)/5)
%         ABCD(i,1) = data(i,1);
%         ABCD(i,2) = ((1+data(i, 2))*(1-data(i,5))+data(i,3)*data(i,4))/(2*data(i,4));
%         ABCD(i,3) = Z0 * ((1+data(i, 2))*(1+data(i,5))-data(i,3)*data(i,4))/(2*data(i,4));
%         ABCD(i,4) = ((1+data(i, 2))*(1+data(i,5))-data(i,3)*data(i,4))/(Z0*2*data(i,4));
%         ABCD(i,5) = ((1-data(i, 2))*(1+data(i,5))+data(i,3)*data(i,4))/(2*data(i,4));
%     end

