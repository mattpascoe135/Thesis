function [ sData ] = divData( data1 , data2 )
    Z0 = 50;    %50 ohms
    sData = zeros(length(data1), numel(data1)/length(data1));
    sData(:,1) = data1(:,1);        %set input data to be equal to output data for row 1 (this is freq.)

    for idx=1:length(data1)
        %Convert to ABCD matrix
        sparam1 = zeros(2);
        sparam1(1,1) = data1(idx,2); sparam1(1,2) = data1(idx,3);
        sparam1(2,1) = data1(idx,4); sparam1(2,2) = data1(idx,5);
        abcd_param1 = s2abcd(sparam1, Z0);
        
        sparam2 = zeros(2);
        sparam2(1,1) = data2(idx,2); sparam2(1,2) = data2(idx,3);
        sparam2(2,1) = data2(idx,4); sparam2(2,2) = data2(idx,5);
        abcd_param2 = s2abcd(sparam2, Z0);
        
        %Do division
        abcd_param = abcd_param1 * abcd_param2;
        
        %Convert back to S-parameters
        s_param = abcd2s(abcd_param);
        sData(idx,2) = s_param(1,1); sData(idx,3) = s_param(1,2);
        sData(idx,4) = s_param(2,1); sData(idx,5) = s_param(2,2);
    end
end

