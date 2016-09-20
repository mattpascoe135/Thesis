%{
DATA available

Data/Infineon-sp4t-state01-c-rx1.s2p
Data/Infineon-sp4t-state01-c-rx2.s2p
Data/Infineon-sp4t-state01-c-rx3.s2p
Data/Infineon-sp4t-state01-c-rx4.s2p
Data/Infineon-sp4t-state01-c-rx5.s2p
Data/Infineon-sp4t-state10-c-rx1.s2p
Data/Infineon-sp4t-state10-c-rx2.s2p

### NOTE: these have been measured with a larger step size,
        therefore they are 201x5 arrays :NOTE ###
Data/Infineon-sp2t-state0-c-rx1.s2p
Data/Infineon-sp2t-state0-c-rx2.s2p
Data/Infineon-sp2t-state0-rx1-rx2.s2p
Data/Infineon-sp2t-state1-c-rx1.s2p
Data/Infineon-sp2t-state1-c-rx1.s2p
Data/Infineon-sp2t-state1-rx1-rx2.s2p

Data/PSEMI-sp4t-state00-c-p1.s2p
Data/PSEMI-sp4t-state00-c-p2.s2p 
Data/PSEMI-sp4t-state00-c-p3.s2p 
Data/PSEMI-sp4t-state00-c-p4.s2p 
Data/PSEMI-sp4t-state01-c-p1.s2p 
Data/PSEMI-sp4t-state01-c-p4.s2p
Data/PSEMI-sp4t-state01-p4-p2.s2p
%}


test = 1;

switch test
    case 0 
        %{
            4x
            2x
            2x
        %}
        %Insertion LOSS calculation
        
        data1 = getSparam('Data/PSEMI-sp4t-state00-c-p1.s2p');
        tmp = sParamToABCD(data1);
        abcd1 = downscale(tmp, 4);
        data2 = getSparam('Data/Infineon-sp2t-state0-c-rx1.s2p');
        abcd2 = sParamToABCD(data2);
        %Convert each switch abcd to single abcd, then to sParam
        abcdtmp = multABCD(abcd1, abcd2);
        abcd = multABCD(abcdtmp, abcd2);
        data = ABCDTosParam(abcd);
        %Plot the data
        plotData(data);
        
        %Isolation LOSS calculation
        data3 = getSparam('Data/PSEMI-sp4t-state00-c-p2.s2p');
        tmp = sParamToABCD(data3);
        abcd3 = downscale(tmp, 4);
        data4 = getSparam('Data/Infineon-sp2t-state0-c-rx2.s2p');
        abcd4 = sParamToABCD(data4);
        
        %Convert each switch abcd to single abcd, then to sParam
        abcdtmp = multABCD(abcd3, abcd4);
        abcd_2 = multABCD(abcdtmp, abcd4);
        data_2 = ABCDTosParam(abcd_2);
        %Plot the data
        plotData(data_2);
        
        
        
        
    case 1
        %{
            4x
            4x
        %}
        %Insertion LOSS calculation
        data1 = getSparam('Data/PSEMI-sp4t-state00-c-p1.s2p');
        abcd1 = sParamToABCD(data1);
        %Convert each switch abcd to single abcd, then to sParam
        abcd = multABCD(abcd1, abcd1);
        data = ABCDTosParam(abcd);
        %Plot the data
        plotData(data);
        
        %Isolation LOSS calculation
        data2 = getSparam('Data/PSEMI-sp4t-state00-c-p2.s2p');
        abcd2 = sParamToABCD(data2);
        %Convert each switch abcd to single abcd, then to sParam
        abcd_2 = multABCD(abcd2, abcd2);
        data_2 = ABCDTosParam(abcd_2);
        %Plot the data
        plotData(data_2);
        
    otherwise
        %do nothing
end